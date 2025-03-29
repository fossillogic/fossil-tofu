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
#include "fossil/tofu/algorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function definitions
// *****************************************************************************

fossil_mapof_t* fossil_mapof_create_container(char* key_type, char* value_type) {
    fossil_mapof_t* map = (fossil_mapof_t*)fossil_tofu_alloc(sizeof(fossil_mapof_t));
    if (!map) return NULL;
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
    if (!other) return NULL;

    fossil_mapof_t* map = fossil_mapof_create_container(other->key_type, other->value_type);
    if (!map) return NULL;

    fossil_mapof_node_t* current = other->head;
    while (current) {
        fossil_mapof_insert(map, fossil_tofu_get_value(&current->key), fossil_tofu_get_value(&current->value));
        current = current->next;
    }
    return map;
}

fossil_mapof_t* fossil_mapof_create_move(fossil_mapof_t* other) {
    if (!other) return NULL;

    fossil_mapof_t* map = fossil_mapof_create_container(other->key_type, other->value_type);
    if (!map) return NULL;

    map->head = other->head;
    map->size = other->size;
    other->head = NULL;
    other->size = 0;

    return map;
}

void fossil_mapof_destroy(fossil_mapof_t* map) {
    if (!map) return;

    while (map->head) {
        fossil_mapof_node_t* temp = map->head;
        map->head = map->head->next;
        fossil_tofu_destroy(&temp->key);
        fossil_tofu_destroy(&temp->value);
        fossil_tofu_free(temp);
    }

    fossil_tofu_free(map);
}

int32_t fossil_mapof_insert(fossil_mapof_t* map, char *key, char *value) {
    if (!map || !key || !value) return FOSSIL_TOFU_FAILURE;

    fossil_mapof_node_t* node = (fossil_mapof_node_t*)fossil_tofu_alloc(sizeof(fossil_mapof_node_t));
    if (!node) return FOSSIL_TOFU_FAILURE;

    node->key = fossil_tofu_create(map->key_type, key);
    node->value = fossil_tofu_create(map->value_type, value);
    node->next = map->head;
    map->head = node;
    map->size++;

    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_mapof_remove(fossil_mapof_t* map, char *key) {
    if (!map || !key) return FOSSIL_TOFU_FAILURE;

    fossil_tofu_t temp_data = fossil_tofu_create(map->key_type, key);

    fossil_mapof_node_t** current = &map->head;
    while (*current) {
        if (fossil_algorithm_compare(&(*current)->key, &temp_data) == 0) {
            fossil_mapof_node_t* temp = *current;
            *current = (*current)->next;
            fossil_tofu_destroy(&temp->key);
            fossil_tofu_destroy(&temp->value);
            fossil_tofu_free(temp);
            map->size--;
            return FOSSIL_TOFU_SUCCESS;
        }
        current = &(*current)->next;
    }
    return FOSSIL_TOFU_FAILURE;
}

bool fossil_mapof_contains(const fossil_mapof_t* map, char *key) {
    if (!map || !key) return false;

    fossil_tofu_t temp_data = fossil_tofu_create(map->key_type, key);

    fossil_mapof_node_t* current = map->head;
    while (current) {
        if (fossil_algorithm_compare(&current->key, &temp_data) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

fossil_tofu_t fossil_mapof_get(const fossil_mapof_t* map, char *key) {
    if (!map || !key) return fossil_tofu_create(map->value_type, NULL);

    fossil_tofu_t temp_data = fossil_tofu_create(map->key_type, key);

    fossil_mapof_node_t* current = map->head;
    while (current) {
        if (fossil_algorithm_compare(&current->key, &temp_data) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return fossil_tofu_create(map->value_type, NULL);
}

int32_t fossil_mapof_set(fossil_mapof_t* map, char *key, char *value) {
    if (!map || !key || !value) return FOSSIL_TOFU_FAILURE;

    fossil_tofu_t temp_data = fossil_tofu_create(map->key_type, key);

    fossil_mapof_node_t* current = map->head;
    while (current) {
        if (fossil_algorithm_compare(&current->key, &temp_data) == 0) {
            fossil_tofu_destroy(&current->value);
            current->value = fossil_tofu_create(map->value_type, value);
            return FOSSIL_TOFU_SUCCESS;
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;
}

size_t fossil_mapof_size(const fossil_mapof_t* map) {
    return map ? map->size : 0;
}

bool fossil_mapof_not_empty(const fossil_mapof_t* map) {
    return map && map->head != NULL;
}

bool fossil_mapof_is_empty(const fossil_mapof_t* map) {
    return !map || map->head == NULL;
}
