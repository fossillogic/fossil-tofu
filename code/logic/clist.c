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
#include "fossil/tofu/clist.h"

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tofu_clist_t* fossil_tofu_clist_create_container(char* type) {
    fossil_tofu_clist_t* clist = (fossil_tofu_clist_t*)fossil_tofu_alloc(sizeof(fossil_tofu_clist_t));
    if (clist == NULL) {
        return NULL;
    }
    clist->head = NULL;
    clist->type = fossil_tofu_strdup(type);
    return clist;
}

fossil_tofu_clist_t* fossil_tofu_clist_create_default(void) {
    return fossil_tofu_clist_create_container("any");
}

fossil_tofu_clist_t* fossil_tofu_clist_create_copy(const fossil_tofu_clist_t* other) {
    fossil_tofu_clist_t* clist = (fossil_tofu_clist_t*)fossil_tofu_alloc(sizeof(fossil_tofu_clist_t));
    if (clist == NULL) {
        return NULL;
    }
    clist->type = fossil_tofu_strdup(other->type);
    clist->head = NULL;
    fossil_tofu_clist_node_t* current = other->head;
    if (current != NULL) {
        do {
            fossil_tofu_clist_insert(clist, fossil_tofu_get_value(&current->data));
            current = current->next;
        } while (current != other->head);  // Continue until we reach the head node again
    }
    return clist;
}

fossil_tofu_clist_t* fossil_tofu_clist_create_move(fossil_tofu_clist_t* other) {
    fossil_tofu_clist_t* clist = (fossil_tofu_clist_t*)fossil_tofu_alloc(sizeof(fossil_tofu_clist_t));
    if (clist == NULL) {
        return NULL;
    }
    clist->type = other->type;
    clist->head = other->head;
    other->type = NULL; // Prevent double free of type
    other->head = NULL;
    return clist;
}

void fossil_tofu_clist_destroy(fossil_tofu_clist_t* clist) {
    if (clist == NULL || clist->head == NULL) return;
    fossil_tofu_clist_node_t* current = clist->head;
    do {
        fossil_tofu_clist_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    } while (current != clist->head);
    fossil_tofu_free(clist->type);
    fossil_tofu_free(clist);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_tofu_clist_insert(fossil_tofu_clist_t* clist, char* data) {
    fossil_tofu_clist_node_t* node = (fossil_tofu_clist_node_t*)fossil_tofu_alloc(sizeof(fossil_tofu_clist_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(clist->type, data);
    if (clist->head == NULL) {
        clist->head = node;
        node->next = node;
        node->prev = node;  // Circular link
    } else {
        node->next = clist->head;
        node->prev = clist->head->prev;
        clist->head->prev->next = node;
        clist->head->prev = node;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_tofu_clist_remove(fossil_tofu_clist_t* clist) {
    if (clist->head == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tofu_clist_node_t* node = clist->head;
    if (clist->head == clist->head->next) {  // Only one node in the list
        clist->head = NULL;
    } else {
        clist->head->prev->next = clist->head->next;
        clist->head->next->prev = clist->head->prev;
        clist->head = clist->head->next;
    }
    fossil_tofu_destroy(&node->data);
    fossil_tofu_free(node);
    return FOSSIL_TOFU_SUCCESS;
}

void fossil_tofu_clist_reverse(fossil_tofu_clist_t* clist) {
    if (clist == NULL || clist->head == NULL) {
        return;
    }
    fossil_tofu_clist_node_t* current = clist->head;
    fossil_tofu_clist_node_t* temp = NULL;
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != clist->head);
    clist->head = clist->head->prev;  // Move head to the new start
}

size_t fossil_tofu_clist_size(const fossil_tofu_clist_t* clist) {
    size_t size = 0;
    if (clist->head != NULL) {
        fossil_tofu_clist_node_t* current = clist->head;
        do {
            size++;
            current = current->next;
        } while (current != clist->head);
    }
    return size;
}

bool fossil_tofu_clist_not_empty(const fossil_tofu_clist_t* clist) {
    return (clist != NULL) && (clist->head != NULL);
}

bool fossil_tofu_clist_not_cnullptr(const fossil_tofu_clist_t* clist) {
    return clist != NULL;
}

bool fossil_tofu_clist_is_empty(const fossil_tofu_clist_t* clist) {
    return (clist == NULL) || (clist->head == NULL);
}

bool fossil_tofu_clist_is_cnullptr(const fossil_tofu_clist_t* clist) {
    return clist == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char* fossil_tofu_clist_get(const fossil_tofu_clist_t* clist, size_t index) {
    size_t i = 0;
    if (clist->head != NULL) {
        fossil_tofu_clist_node_t* current = clist->head;
        do {
            if (i == index) {
                return fossil_tofu_get_value(&current->data);
            }
            i++;
            current = current->next;
        } while (current != clist->head);
    }
    return NULL;
}

char* fossil_tofu_clist_get_front(const fossil_tofu_clist_t* clist) {
    if (clist->head != NULL) {
        return fossil_tofu_get_value(&clist->head->data);
    }
    return NULL;
}

char* fossil_tofu_clist_get_back(const fossil_tofu_clist_t* clist) {
    if (clist->head != NULL) {
        return fossil_tofu_get_value(&clist->head->prev->data);
    }
    return NULL;
}

void fossil_tofu_clist_set(fossil_tofu_clist_t* clist, size_t index, char* element) {
    size_t i = 0;
    if (clist->head != NULL) {
        fossil_tofu_clist_node_t* current = clist->head;
        do {
            if (i == index) {
                fossil_tofu_set_value(&current->data, element);
                return;
            }
            i++;
            current = current->next;
        } while (current != clist->head);
    }
}

void fossil_tofu_clist_set_front(fossil_tofu_clist_t* clist, char* element) {
    if (clist->head != NULL) {
        fossil_tofu_set_value(&clist->head->data, element);
    }
}

void fossil_tofu_clist_set_back(fossil_tofu_clist_t* clist, char* element) {
    if (clist->head != NULL) {
        fossil_tofu_set_value(&clist->head->prev->data, element);
    }
}
