/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/tofu/slist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_slist_t* fossil_slist_create_container(char* type, int max_level, float probability) {
    fossil_slist_t* slist = (fossil_slist_t*)fossil_tofu_alloc(sizeof(fossil_slist_t));
    if (slist == NULL) {
        return NULL;
    }
    slist->header = (fossil_slist_node_t*)fossil_tofu_alloc(sizeof(fossil_slist_node_t));
    if (slist->header == NULL) {
        fossil_tofu_free(slist);
        return NULL;
    }
    slist->header->forward = (fossil_slist_node_t**)fossil_tofu_alloc(max_level * sizeof(fossil_slist_node_t*));
    if (slist->header->forward == NULL) {
        fossil_tofu_free(slist->header);
        fossil_tofu_free(slist);
        return NULL;
    }
    slist->max_level = max_level;
    slist->probability = probability;
    slist->type = fossil_tofu_strdup(type);
    return slist;
}

fossil_slist_t* fossil_slist_create_default(void) {
    return fossil_slist_create_container("any", 16, 0.5f);
}

fossil_slist_t* fossil_slist_create_copy(const fossil_slist_t* other) {
    fossil_slist_t* slist = (fossil_slist_t*)fossil_tofu_alloc(sizeof(fossil_slist_t));
    if (slist == NULL) {
        return NULL;
    }
    slist->header = (fossil_slist_node_t*)fossil_tofu_alloc(sizeof(fossil_slist_node_t));
    if (slist->header == NULL) {
        fossil_tofu_free(slist);
        return NULL;
    }
    slist->header->forward = (fossil_slist_node_t**)fossil_tofu_alloc(other->max_level * sizeof(fossil_slist_node_t*));
    if (slist->header->forward == NULL) {
        fossil_tofu_free(slist->header);
        fossil_tofu_free(slist);
        return NULL;
    }
    slist->max_level = other->max_level;
    slist->probability = other->probability;
    slist->type = fossil_tofu_strdup(other->type);
    memcpy(slist->header->forward, other->header->forward, other->max_level * sizeof(fossil_slist_node_t*));
    return slist;
}

fossil_slist_t* fossil_slist_create_move(fossil_slist_t* other) {
    fossil_slist_t* slist = (fossil_slist_t*)fossil_tofu_alloc(sizeof(fossil_slist_t));
    if (slist == NULL) {
        return NULL;
    }
    slist->header = other->header;
    slist->max_level = other->max_level;
    slist->probability = other->probability;
    slist->type = other->type;
    other->header = NULL;
    return slist;
}

void fossil_slist_destroy(fossil_slist_t* slist) {
    if (slist == NULL) {
        return;
    }
    fossil_slist_node_t* current = slist->header;
    while (current != NULL) {
        fossil_slist_node_t* next = current->forward[0];
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current->forward);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(slist->type);
    fossil_tofu_free(slist);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_slist_insert(fossil_slist_t* slist, char *data) {
    if (slist == NULL || data == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    int level = 0;
    while ((float)rand() / RAND_MAX < slist->probability && level < slist->max_level) {
        level++;
    }
    fossil_slist_node_t* new_node = (fossil_slist_node_t*)fossil_tofu_alloc(sizeof(fossil_slist_node_t));
    if (new_node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    new_node->data = fossil_tofu_create(slist->type, data);
    new_node->level = level;
    new_node->forward = (fossil_slist_node_t**)fossil_tofu_alloc((level + 1) * sizeof(fossil_slist_node_t*));
    if (new_node->forward == NULL) {
        fossil_tofu_free(new_node);
        return FOSSIL_TOFU_FAILURE;
    }
    for (int i = 0; i <= level; i++) {
        new_node->forward[i] = NULL;
    }
    
    // Insert the new node into the skip list
    fossil_slist_node_t* current = slist->header;
    for (int i = slist->max_level - 1; i >= 0; i--) {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->data.value.data, data) < 0) {
            current = current->forward[i];
        }
        if (i <= level) {
            new_node->forward[i] = current->forward[i];
            current->forward[i] = new_node;
        }
    }
    
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_slist_remove(fossil_slist_t* slist, char *data) {
    if (slist == NULL || data == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_slist_node_t* current = slist->header;
    fossil_slist_node_t* update[slist->max_level + 1];
    for (int i = slist->max_level; i >= 0; i--) {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->data.value.data, data) < 0) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    
    if (current != NULL && strcmp(current->data.value.data, data) == 0) {
        for (int i = 0; i <= slist->max_level; i++) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current->forward);
        fossil_tofu_free(current);
        return FOSSIL_TOFU_SUCCESS;
    }
    
    return FOSSIL_TOFU_FAILURE;
}

size_t fossil_slist_size(const fossil_slist_t* slist) {
    if (slist == NULL) {
        return 0;
    }
    size_t size = 0;
    fossil_slist_node_t* current = slist->header->forward[0];
    while (current != NULL) {
        size++;
        current = current->forward[0];
    }
    return size;
}

bool fossil_slist_not_empty(const fossil_slist_t* slist) {
    return slist != NULL && slist->header->forward[0] != NULL;
}

bool fossil_slist_is_empty(const fossil_slist_t* slist) {
    return slist == NULL || slist->header->forward[0] == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

bool fossil_slist_find(const fossil_slist_t* slist, char *data) {
    if (slist == NULL || data == NULL) {
        return false;
    }
    fossil_slist_node_t* current = slist->header;
    for (int i = slist->max_level; i >= 0; i--) {
        while (current->forward[i] != NULL && strcmp(current->forward[i]->data.value.data, data) < 0) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    
    return current != NULL && strcmp(current->data.value.data, data) == 0;
}
