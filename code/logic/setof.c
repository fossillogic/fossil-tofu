/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/tofu/setof.h"

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tofu_setof_t* fossil_tofu_setof_create_container(char* type) {
    fossil_tofu_setof_t* set = (fossil_tofu_setof_t*)fossil_tofu_alloc(sizeof(fossil_tofu_setof_t));
    if (set == NULL) {
        return NULL;
    }
    set->type = type;
    set->head = NULL;
    set->size = 0;
    return set;
}

fossil_tofu_setof_t* fossil_tofu_setof_create_default(void) {
    return fossil_tofu_setof_create_container("any");
}

fossil_tofu_setof_t* fossil_tofu_setof_create_copy(const fossil_tofu_setof_t* other) {
    fossil_tofu_setof_t* set = fossil_tofu_setof_create_container(other->type);
    if (set == NULL) {
        return NULL;
    }
    fossil_tofu_setof_node_t* current = other->head;
    while (current != NULL) {
        fossil_tofu_setof_insert(set, fossil_tofu_get_value(&current->data));
        current = current->next;
    }
    return set;
}

fossil_tofu_setof_t* fossil_tofu_setof_create_move(fossil_tofu_setof_t* other) {
    fossil_tofu_setof_t* set = fossil_tofu_setof_create_container(other->type);
    if (set == NULL) {
        return NULL;
    }
    set->head = other->head;
    other->head = NULL;
    set->size = other->size;
    other->size = 0;
    return set;
}

void fossil_tofu_setof_destroy(fossil_tofu_setof_t* set) {
    if (set == NULL) {
        return;
    }
    while (set->head != NULL) {
        fossil_tofu_setof_node_t* temp = set->head;
        set->head = set->head->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(set);
}

int32_t fossil_tofu_setof_insert(fossil_tofu_setof_t* set, char *data) {
    if (set == NULL || data == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tofu_setof_node_t* node = (fossil_tofu_setof_node_t*)fossil_tofu_alloc(sizeof(fossil_tofu_setof_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(set->type, data);
    node->next = set->head;
    set->head = node;
    set->size++;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_tofu_setof_remove(fossil_tofu_setof_t* set, char *data) {
    if (set == NULL || data == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }

    fossil_tofu_t temp_data = fossil_tofu_create(set->type, data);
    fossil_tofu_setof_node_t** current = &set->head;

    while (*current) {
        if (fossil_tofu_compare(&(*current)->data, &temp_data) == 0) {
            fossil_tofu_setof_node_t* temp = *current;
            *current = (*current)->next;
            fossil_tofu_destroy(&temp->data);
            fossil_tofu_free(temp);
            set->size--;
            fossil_tofu_destroy(&temp_data);
            return FOSSIL_TOFU_SUCCESS;
        }
        current = &((*current)->next);
    }

    fossil_tofu_destroy(&temp_data);
    return FOSSIL_TOFU_FAILURE;
}

bool fossil_tofu_setof_contains(const fossil_tofu_setof_t* set, char *data) {
    if (set == NULL || data == NULL) {
        return false;
    }

    fossil_tofu_t temp_data = fossil_tofu_create(set->type, data);
    fossil_tofu_setof_node_t* current = set->head;

    while (current) {
        if (fossil_tofu_compare(&current->data, &temp_data) == 0) {
            fossil_tofu_destroy(&temp_data);
            return true;
        }
        current = current->next;
    }

    fossil_tofu_destroy(&temp_data);
    return false;
}

size_t fossil_tofu_setof_size(const fossil_tofu_setof_t* set) {
    return set == NULL ? 0 : set->size;
}

bool fossil_tofu_setof_not_empty(const fossil_tofu_setof_t* set) {
    return set != NULL && set->size > 0;
}

bool fossil_tofu_setof_is_empty(const fossil_tofu_setof_t* set) {
    return set == NULL || set->size == 0;
}
