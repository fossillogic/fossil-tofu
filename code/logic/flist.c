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
#include "fossil/tofu/flist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_flist_t* fossil_flist_create_container(char* type) {
    fossil_flist_t* flist = (fossil_flist_t*)fossil_tofu_alloc(sizeof(fossil_flist_t));
    if (!flist) {
        return NULL;
    }
    flist->head = NULL;
    flist->type = fossil_tofu_strdup(type);
    return flist;
}

fossil_flist_t* fossil_flist_create_default(void) {
    return fossil_flist_create_container("any");
}

fossil_flist_t* fossil_flist_create_copy(const fossil_flist_t* other) {
    if (!other) {
        return NULL;
    }
    fossil_flist_t* copy = fossil_flist_create_container(other->type);
    if (!copy) {
        return NULL;
    }
    
    // Copy the elements from the other list
    fossil_flist_node_t* current = other->head;
    while (current) {
        fossil_flist_insert(copy, current->data.value.data);
        current = current->next;
    }
    
    return copy;
}

fossil_flist_t* fossil_flist_create_move(fossil_flist_t* other) {
    if (!other) {
        return NULL;
    }
    fossil_flist_t* new_list = fossil_flist_create_container(other->type);
    if (!new_list) {
        return NULL;
    }
    new_list->head = other->head;
    other->head = NULL;
    return new_list;
}

void fossil_flist_destroy(fossil_flist_t* flist) {
    if (!flist) {
        return;
    }
    fossil_flist_node_t* current = flist->head;
    while (current) {
        fossil_flist_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(flist->type);
    fossil_tofu_free(flist);
}

int32_t fossil_flist_insert(fossil_flist_t* flist, char *data) {
    if (!flist || !data) {
        return -1;  // Error
    }
    fossil_flist_node_t* new_node = (fossil_flist_node_t*)fossil_tofu_alloc(sizeof(fossil_flist_node_t));
    if (!new_node) {
        return -1;  // Error
    }
    new_node->data.value.data = fossil_tofu_strdup(data);
    new_node->next = NULL;

    if (!flist->head) {
        // List is empty, new node becomes head
        flist->head = new_node;
    } else {
        // Traverse to the end and append
        fossil_flist_node_t* current = flist->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    return 0;  // Success
}

int32_t fossil_flist_remove(fossil_flist_t* flist) {
    if (!flist || !flist->head) {
        return -1;  // Error
    }
    fossil_flist_node_t* to_remove = flist->head;
    flist->head = to_remove->next;
    fossil_tofu_free(to_remove->data.value.data);
    fossil_tofu_free(to_remove);
    return 0;  // Success
}

void fossil_flist_reverse_forward(fossil_flist_t* flist) {
    if (!flist) {
        return;
    }
    fossil_flist_node_t* prev = NULL;
    fossil_flist_node_t* current = flist->head;
    while (current) {
        fossil_flist_node_t* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    flist->head = prev;
}

void fossil_flist_reverse_backward(fossil_flist_t* flist) {
    if (!flist) {
        return;
    }
    fossil_flist_node_t* prev = NULL;
    fossil_flist_node_t* current = flist->head;
    while (current) {
        fossil_flist_node_t* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    flist->head = prev;
}

size_t fossil_flist_size(const fossil_flist_t* flist) {
    if (!flist) {
        return 0;
    }
    size_t size = 0;
    fossil_flist_node_t* current = flist->head;
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_flist_not_empty(const fossil_flist_t* flist) {
    return flist && flist->head != NULL;
}

bool fossil_flist_not_cnullptr(const fossil_flist_t* flist) {
    return flist != NULL;
}

bool fossil_flist_is_empty(const fossil_flist_t* flist) {
    return !fossil_flist_not_empty(flist);
}

bool fossil_flist_is_cnullptr(const fossil_flist_t* flist) {
    return flist == NULL;
}

char *fossil_flist_get(const fossil_flist_t* flist, size_t index) {
    if (!flist) {
        return NULL;  // Error
    }
    fossil_flist_node_t* current = flist->head;
    size_t count = 0;
    while (current) {
        if (count == index) {
            return current->data.value.data;  // Found the element
        }
        count++;
        current = current->next;
    }
    return NULL;  // Index out of bounds
}

char *fossil_flist_get_front(const fossil_flist_t* flist) {
    if (!flist || !flist->head) {
        return NULL;  // Error
    }
    return flist->head->data.value.data;
}

char *fossil_flist_get_back(const fossil_flist_t* flist) {
    if (!flist || !flist->head) {
        return NULL;  // Error
    }
    fossil_flist_node_t* current = flist->head;
    while (current->next) {
        current = current->next;
    }
    return current->data.value.data;
}

void fossil_flist_set(fossil_flist_t* flist, size_t index, char *element) {
    if (!flist) {
        return;  // Error
    }
    fossil_flist_node_t* current = flist->head;
    size_t count = 0;
    while (current) {
        if (count == index) {
            fossil_tofu_free(current->data.value.data);  // Free old data
            current->data.value.data = fossil_tofu_strdup(element);  // Set new data
            return;  // Element set successfully
        }
        count++;
        current = current->next;
    }
}

void fossil_flist_set_front(fossil_flist_t* flist, char *element) {
    if (!flist || !flist->head) {
        return;  // Error
    }
    fossil_tofu_free(flist->head->data.value.data);  // Free old data
    flist->head->data.value.data = fossil_tofu_strdup(element);  // Set new data
}

void fossil_flist_set_back(fossil_flist_t* flist, char *element) {
    if (!flist || !flist->head) {
        return;  // Error
    }
    fossil_flist_node_t* current = flist->head;
    while (current->next) {
        current = current->next;
    }
    fossil_tofu_free(current->data.value.data);  // Free old data
    current->data.value.data = fossil_tofu_strdup(element);  // Set new data
}
