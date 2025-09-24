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
#include "fossil/tofu/arraylist.h"

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_arraylist_t* fossil_arraylist_create_container(char* type, size_t capacity) {
    fossil_arraylist_t* alist = (fossil_arraylist_t*)fossil_tofu_alloc(sizeof(fossil_arraylist_t));
    if (alist == NULL) {
        return NULL;
    }
    alist->type = fossil_tofu_strdup(type);
    alist->size = 0;
    alist->capacity = capacity;
    alist->items = (fossil_arraylist_node_t*)fossil_tofu_alloc(sizeof(fossil_arraylist_node_t) * capacity);
    if (alist->items == NULL) {
        fossil_tofu_free(alist->type);
        fossil_tofu_free(alist);
        return NULL;
    }
    return alist;
}

fossil_arraylist_t* fossil_arraylist_create_default(void) {
    return fossil_arraylist_create_container("any", 8);
}

fossil_arraylist_t* fossil_arraylist_create_copy(const fossil_arraylist_t* other) {
    if (other == NULL) return NULL;
    fossil_arraylist_t* alist = fossil_arraylist_create_container(other->type, other->capacity);
    if (alist == NULL) return NULL;
    alist->size = other->size;
    for (size_t i = 0; i < other->size; ++i) {
        alist->items[i].data = fossil_tofu_create(other->type, fossil_tofu_get_value(&other->items[i].data));
    }
    return alist;
}

fossil_arraylist_t* fossil_arraylist_create_move(fossil_arraylist_t* other) {
    if (other == NULL) return NULL;
    fossil_arraylist_t* alist = (fossil_arraylist_t*)fossil_tofu_alloc(sizeof(fossil_arraylist_t));
    if (alist == NULL) return NULL;
    alist->type = other->type;
    alist->size = other->size;
    alist->capacity = other->capacity;
    alist->items = other->items;
    other->type = NULL;
    other->items = NULL;
    other->size = 0;
    other->capacity = 0;
    return alist;
}

void fossil_arraylist_destroy(fossil_arraylist_t* alist) {
    if (alist == NULL) return;
    for (size_t i = 0; i < alist->size; ++i) {
        fossil_tofu_destroy(&alist->items[i].data);
    }
    fossil_tofu_free(alist->items);
    fossil_tofu_free(alist->type);
    fossil_tofu_free(alist);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_arraylist_insert(fossil_arraylist_t* alist, char *data) {
    if (alist == NULL) return FOSSIL_TOFU_FAILURE;
    if (alist->size >= alist->capacity) {
        size_t new_capacity = alist->capacity * 2;
        fossil_arraylist_node_t* new_items = (fossil_arraylist_node_t*)fossil_tofu_alloc(sizeof(fossil_arraylist_node_t) * new_capacity);
        if (new_items == NULL) return FOSSIL_TOFU_FAILURE;
        for (size_t i = 0; i < alist->size; ++i) {
            new_items[i] = alist->items[i];
        }
        fossil_tofu_free(alist->items);
        alist->items = new_items;
        alist->capacity = new_capacity;
    }
    alist->items[alist->size].data = fossil_tofu_create(alist->type, data);
    alist->size++;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_arraylist_remove(fossil_arraylist_t* alist, size_t index) {
    if (alist == NULL || index >= alist->size) return FOSSIL_TOFU_FAILURE;
    fossil_tofu_destroy(&alist->items[index].data);
    for (size_t i = index; i < alist->size - 1; ++i) {
        alist->items[i] = alist->items[i + 1];
    }
    alist->size--;
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_arraylist_size(const fossil_arraylist_t* alist) {
    return (alist != NULL) ? alist->size : 0;
}

size_t fossil_arraylist_capacity(const fossil_arraylist_t* alist) {
    return (alist != NULL) ? alist->capacity : 0;
}

bool fossil_arraylist_not_empty(const fossil_arraylist_t* alist) {
    return (alist != NULL) && (alist->size > 0);
}

bool fossil_arraylist_not_cnullptr(const fossil_arraylist_t* alist) {
    return alist != NULL;
}

bool fossil_arraylist_is_empty(const fossil_arraylist_t* alist) {
    return (alist == NULL) || (alist->size == 0);
}

bool fossil_arraylist_is_cnullptr(const fossil_arraylist_t* alist) {
    return alist == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_arraylist_get(const fossil_arraylist_t* alist, size_t index) {
    if (alist == NULL || index >= alist->size) return NULL;
    return fossil_tofu_get_value(&alist->items[index].data);
}

char *fossil_arraylist_get_front(const fossil_arraylist_t* alist) {
    if (alist == NULL || alist->size == 0) return NULL;
    return fossil_tofu_get_value(&alist->items[0].data);
}

char *fossil_arraylist_get_back(const fossil_arraylist_t* alist) {
    if (alist == NULL || alist->size == 0) return NULL;
    return fossil_tofu_get_value(&alist->items[alist->size - 1].data);
}

void fossil_arraylist_set(fossil_arraylist_t* alist, size_t index, char *element) {
    if (alist == NULL || index >= alist->size) return;
    fossil_tofu_set_value(&alist->items[index].data, element);
}

void fossil_arraylist_set_front(fossil_arraylist_t* alist, char *element) {
    if (alist == NULL || alist->size == 0) return;
    fossil_tofu_set_value(&alist->items[0].data, element);
}

void fossil_arraylist_set_back(fossil_arraylist_t* alist, char *element) {
    if (alist == NULL || alist->size == 0) return;
    fossil_tofu_set_value(&alist->items[alist->size - 1].data, element);
}
