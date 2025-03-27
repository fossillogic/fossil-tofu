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
#include "fossil/tofu/mapof.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_mapof_t* fossil_mapof_create_container(char* key_type, char* value_type) {
    fossil_mapof_t* map = (fossil_mapof_t*)fossil_tofu_alloc(sizeof(fossil_mapof_t));
    if (map == NULL) {
        return NULL;
    }
    map->key_type = key_type;
    map->value_type = value_type;
    map->head = NULL;
    map->size = 0;
    return map;
}

fossil_mapof_t* fossil_mapof_create_default(void) {
    return fossil_mapof_create_container("any", "any");
}

fossil_mapof_t* fossil_mapof_create_copy(const fossil_mapof_t* other) {
    fossil_mapof_t* map = (fossil_mapof_t*)fossil_tofu_alloc(sizeof(fossil_mapof_t));
    if (map == NULL) {
        return NULL;
    }
    map->key_type = other->key_type;
    map->value_type = other->value_type;
    map->head = NULL;
    map->size = 0;
    fossil_mapof_node_t* current = other->head;
    while (current != NULL) {
        fossil_mapof_insert(map, current->key, fossil_tofu_get_value(&current->value));
        current = current->next;
    }
    return map;
}

fossil_mapof_t* fossil_mapof_create_move(fossil_mapof_t* other) {
    fossil_mapof_t* map = (fossil_mapof_t*)fossil_tofu_alloc(sizeof(fossil_mapof_t));
    if (map == NULL) {
        return NULL;
    }
    map->key_type = other->key_type;
    map->value_type = other->value_type;
    map->head = other->head;
    other->head = NULL;
    map->size = other->size;
    other->size = 0;
    return map;
}

void fossil_mapof_destroy(fossil_mapof_t* map) {
    if (map == NULL) {
        return;
    }
    while (map->head != NULL) {
        fossil_mapof_node_t* temp = map->head;
        map->head = map->head->next;
        fossil_tofu_destroy(&temp->value);
        fossil_tofu_free(temp->key);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(map);
}

int32_t fossil_mapof_insert(fossil_mapof_t* map, char *key, char *value) {
    if (map == NULL || key == NULL || value == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_mapof_node_t* node = (fossil_mapof_node_t*)fossil_tofu_alloc(sizeof(fossil_mapof_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->key = key;
    if (node->key == NULL) {
        fossil_tofu_free(node);
        return FOSSIL_TOFU_FAILURE;
    }
    node->value = fossil_tofu_create(map->value_type, value);
    node->next = map->head;
    map->head = node;
    map->size++;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_mapof_remove(fossil_mapof_t* map, char *key) {
    if (map == NULL || key == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_mapof_node_t** current = &map->head;
    while (*current) {
        if (strcmp((*current)->key, key) == 0) {
            fossil_mapof_node_t* temp = *current;
            *current = (*current)->next;
            fossil_tofu_destroy(&temp->value);
            fossil_tofu_free(temp->key);
            fossil_tofu_free(temp);
            map->size--;
            return FOSSIL_TOFU_SUCCESS;
        }
        current = &((*current)->next);
    }
    return FOSSIL_TOFU_FAILURE;
}

bool fossil_mapof_contains(const fossil_mapof_t* map, char *key) {
    if (map == NULL || key == NULL) {
        return false;
    }
    fossil_mapof_node_t* current = map->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

fossil_tofu_t fossil_mapof_get(const fossil_mapof_t* map, char *key) {
    if (map == NULL || key == NULL) {
        return fossil_tofu_create(map->value_type, NULL);
    }
    fossil_mapof_node_t* current = map->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return fossil_tofu_create(map->value_type, NULL);
}

int32_t fossil_mapof_set(fossil_mapof_t* map, char *key, char *value) {
    if (map == NULL || key == NULL || value == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_mapof_node_t* current = map->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            fossil_tofu_destroy(&current->value);
            current->value = fossil_tofu_create(map->value_type, value);
            return FOSSIL_TOFU_SUCCESS;
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;
}

size_t fossil_mapof_size(const fossil_mapof_t* map) {
    return map == NULL ? 0 : map->size;
}

bool fossil_mapof_not_empty(const fossil_mapof_t* map) {
    return map != NULL && map->head != NULL;
}

bool fossil_mapof_is_empty(const fossil_mapof_t* map) {
    return map == NULL || map->head == NULL;
}
