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
#include "fossil/tofu/dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_dlist_t* fossil_dlist_create_container(char* type) {
    fossil_dlist_t* dlist = (fossil_dlist_t*)fossil_tofu_alloc(sizeof(fossil_dlist_t));
    if (dlist == NULL) {
        return NULL;
    }
    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->type = fossil_tofu_strdup(type);
    return dlist;
}

fossil_dlist_t* fossil_dlist_create_default(void) {
    return fossil_dlist_create_container("any");
}

fossil_dlist_t* fossil_dlist_create_copy(const fossil_dlist_t* other) {
    fossil_dlist_t* dlist = (fossil_dlist_t*)fossil_tofu_alloc(sizeof(fossil_dlist_t));
    if (dlist == NULL) {
        return NULL;
    }
    dlist->type = fossil_tofu_strdup(other->type);
    dlist->head = NULL;
    dlist->tail = NULL;
    fossil_dlist_node_t* current = other->head;
    while (current != NULL) {
        fossil_dlist_insert(dlist, fossil_tofu_get_value(&current->data));
        current = current->next;
    }
    return dlist;
}

fossil_dlist_t* fossil_dlist_create_move(fossil_dlist_t* other) {
    fossil_dlist_t* dlist = (fossil_dlist_t*)fossil_tofu_alloc(sizeof(fossil_dlist_t));
    if (dlist == NULL) {
        return NULL;
    }
    dlist->type = other->type;
    dlist->head = other->head;
    dlist->tail = other->tail;
    other->type = NULL;
    other->head = NULL;
    other->tail = NULL;
    return dlist;
}

void fossil_dlist_destroy(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->head;
    while (current != NULL) {
        fossil_dlist_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(dlist->type);
    fossil_tofu_free(dlist);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_dlist_insert(fossil_dlist_t* dlist, char *data) {
    fossil_dlist_node_t* node = (fossil_dlist_node_t*)fossil_tofu_alloc(sizeof(fossil_dlist_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(dlist->type, data);
    node->prev = NULL;
    node->next = NULL;

    if (dlist->head == NULL) {
        // List is empty, node becomes both head and tail
        dlist->head = node;
        dlist->tail = node;
    } else {
        // Insert at the end (tail)
        node->prev = dlist->tail;
        dlist->tail->next = node;
        dlist->tail = node;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_dlist_remove(fossil_dlist_t* dlist) {
    if (dlist->head == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_dlist_node_t* node = dlist->head;
    dlist->head = node->next;
    if (dlist->head != NULL) {
        dlist->head->prev = NULL;
    }
    fossil_tofu_destroy(&node->data);
    fossil_tofu_free(node);
    return FOSSIL_TOFU_SUCCESS;
}

void fossil_dlist_reverse_forward(fossil_dlist_t* dlist) {
    if (dlist == NULL || dlist->head == NULL) {
        return;
    }
    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = NULL;
    while (current != NULL) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

void fossil_dlist_reverse_backward(fossil_dlist_t* dlist) {
    if (dlist == NULL || dlist->tail == NULL) {
        return;
    }
    fossil_dlist_node_t* current = dlist->tail;
    fossil_dlist_node_t* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = temp;
    }
    temp = dlist->tail;
    dlist->tail = dlist->head;
    dlist->head = temp;
}

size_t fossil_dlist_size(const fossil_dlist_t* dlist) {
    if (dlist == NULL) {
        return 0;
    }
    size_t size = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    // Each node is counted exactly once, no duplicates.
    return size;
}

bool fossil_dlist_not_empty(const fossil_dlist_t* dlist) {
    return dlist->head != NULL;
}

bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist) {
    return dlist != NULL;
}

bool fossil_dlist_is_empty(const fossil_dlist_t* dlist) {
    return dlist->head == NULL;
}

bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist) {
    return dlist == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_dlist_get(const fossil_dlist_t* dlist, size_t index) {
    size_t i = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current != NULL) {
        if (i == index) {
            return fossil_tofu_get_value(&current->data);
        }
        i++;
        current = current->next;
    }
    return NULL;
}

char *fossil_dlist_get_front(const fossil_dlist_t* dlist) {
    return fossil_tofu_get_value(&dlist->head->data);
}

char *fossil_dlist_get_back(const fossil_dlist_t* dlist) {
    return fossil_tofu_get_value(&dlist->tail->data);
}

void fossil_dlist_set(fossil_dlist_t* dlist, size_t index, char *element) {
    size_t i = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current != NULL) {
        if (i == index) {
            fossil_tofu_set_value(&current->data, element);
            return;
        }
        i++;
        current = current->next;
    }
}

void fossil_dlist_set_front(fossil_dlist_t* dlist, char *element) {
    fossil_tofu_set_value(&dlist->head->data, element);
}

void fossil_dlist_set_back(fossil_dlist_t* dlist, char *element) {
    fossil_tofu_set_value(&dlist->tail->data, element);
}
