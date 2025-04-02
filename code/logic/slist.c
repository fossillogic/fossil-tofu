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

#define FOSSIL_SLIST_MAX_LEVEL 16
#define FOSSIL_SLIST_PROBABILITY 0.5f

static int random_level(void) {
    int level = 1;
    while ((rand() / (RAND_MAX + 1.0)) < FOSSIL_SLIST_PROBABILITY && level < FOSSIL_SLIST_MAX_LEVEL) {
        level++;
    }
    return level;
}

fossil_slist_t* fossil_slist_create_container(char* type) {
    fossil_slist_t* slist = (fossil_slist_t*)malloc(sizeof(fossil_slist_t));
    if (!slist) return NULL;
    slist->max_level = FOSSIL_SLIST_MAX_LEVEL;
    slist->probability = FOSSIL_SLIST_PROBABILITY;
    slist->head = (fossil_slist_node_t*)malloc(sizeof(fossil_slist_node_t));
    slist->head->forward = (fossil_slist_node_t**)calloc(FOSSIL_SLIST_MAX_LEVEL, sizeof(fossil_slist_node_t*));
    slist->type = fossil_tofu_strdup(type);
    return slist;
}

fossil_slist_t* fossil_slist_create_default(void) {
    return fossil_slist_create_container("any");
}

fossil_slist_t* fossil_slist_create_copy(const fossil_slist_t* other) {
    if (!other) return NULL;
    fossil_slist_t* copy = fossil_slist_create_container(other->type);
    if (!copy) return NULL;
    fossil_slist_node_t* node = other->head->forward[0];
    while (node) {
        fossil_slist_insert(copy, node->data.value.data);
        node = node->forward[0];
    }
    return copy;
}

fossil_slist_t* fossil_slist_create_move(fossil_slist_t* other) {
    if (!other) return NULL;
    fossil_slist_t* moved = other;
    other = NULL;
    return moved;
}

void fossil_slist_destroy(fossil_slist_t* slist) {
    if (!slist) return;
    fossil_slist_node_t* node = slist->head;
    while (node) {
        fossil_slist_node_t* next = node->forward[0];
        free(node->forward);
        free(node);
        node = next;
    }
    free(slist->type);
    free(slist);
}

int32_t fossil_slist_insert(fossil_slist_t* slist, char *data) {
    if (!slist || !data) return -1;
    fossil_slist_node_t* update[FOSSIL_SLIST_MAX_LEVEL];
    fossil_slist_node_t* node = slist->head;
    for (int i = slist->max_level - 1; i >= 0; i--) {
        while (node->forward[i] && strcmp(node->forward[i]->data.value.data, data) < 0) {
            node = node->forward[i];
        }
        update[i] = node;
    }
    node = node->forward[0];
    if (node && strcmp(node->data.value.data, data) == 0) {
        return -1; // Duplicate value
    }
    size_t level = random_level();
    if (level > slist->max_level) {
        level = slist->max_level;
    }
    fossil_slist_node_t* new_node = (fossil_slist_node_t*)malloc(sizeof(fossil_slist_node_t));
    new_node->data.value.data = fossil_tofu_strdup(data);
    new_node->forward = (fossil_slist_node_t**)calloc(level, sizeof(fossil_slist_node_t*));
    for (int i = 0; i < level; i++) {
        new_node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = new_node;
    }
    return 0;
}

int32_t fossil_slist_remove(fossil_slist_t* slist, char *data) {
    if (!slist || !data) return -1;
    fossil_slist_node_t* update[FOSSIL_SLIST_MAX_LEVEL];
    fossil_slist_node_t* node = slist->head;
    for (int i = slist->max_level - 1; i >= 0; i--) {
        while (node->forward[i] && strcmp(node->forward[i]->data.value.data, data) < 0) {
            node = node->forward[i];
        }
        update[i] = node;
    }
    node = node->forward[0];
    if (node && strcmp(node->data.value.data, data) == 0) {
        for (size_t i = 0; i < slist->max_level; i++) {
            if (update[i]->forward[i] != node) break;
            update[i]->forward[i] = node->forward[i];
        }
        free(node->data.value.data);
        free(node->forward);
        free(node);
        return 0;
    }
    return -1;
}

size_t fossil_slist_size(const fossil_slist_t* slist) {
    if (!slist) return 0;
    size_t count = 0;
    fossil_slist_node_t* node = slist->head->forward[0];
    while (node) {
        count++;
        node = node->forward[0];
    }
    return count;
}

bool fossil_slist_not_empty(const fossil_slist_t* slist) {
    return slist && slist->head->forward[0];
}

bool fossil_slist_not_cnullptr(const fossil_slist_t* slist) {
    return slist != NULL;
}

bool fossil_slist_is_empty(const fossil_slist_t* slist) {
    return !fossil_slist_not_empty(slist);
}

bool fossil_slist_is_cnullptr(const fossil_slist_t* slist) {
    return slist == NULL;
}

char *fossil_slist_search(const fossil_slist_t* slist, char *key) {
    if (!slist || !key) return NULL;
    fossil_slist_node_t* node = slist->head;
    for (int i = slist->max_level - 1; i >= 0; i--) {
        while (node->forward[i] && strcmp(node->forward[i]->data.value.data, key) < 0) {
            node = node->forward[i];
        }
    }
    node = node->forward[0];
    return (node && strcmp(node->data.value.data, key) == 0) ? node->data.value.data : NULL;
}

char *fossil_slist_get_front(const fossil_slist_t* slist) {
    return (slist && slist->head->forward[0]) ? slist->head->forward[0]->data.value.data : NULL;
}

char *fossil_slist_get_back(const fossil_slist_t* slist) {
    if (!slist || !slist->head->forward[0]) return NULL;
    fossil_slist_node_t* node = slist->head->forward[0];
    while (node->forward[0]) {
        node = node->forward[0];
    }
    return node->data.value.data;
}
