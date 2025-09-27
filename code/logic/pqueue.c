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
#include "fossil/tofu/pqueue.h"

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tofu_pqueue_t* fossil_tofu_pqueue_create_container(char* type) {
    fossil_tofu_type_t t = fossil_tofu_validate_type(type);
    if (t == FOSSIL_TOFU_TYPE_CNULL) {
        return NULL;
    }
    fossil_tofu_pqueue_t* pqueue = (fossil_tofu_pqueue_t*)fossil_tofu_alloc(sizeof(fossil_tofu_pqueue_t));
    if (pqueue == NULL) {
        return NULL;
    }
    pqueue->type = type;
    pqueue->front = NULL;
    return pqueue;
}

fossil_tofu_pqueue_t* fossil_tofu_pqueue_create_default(void) {
    return fossil_tofu_pqueue_create_container("any");
}

fossil_tofu_pqueue_t* fossil_tofu_pqueue_create_copy(const fossil_tofu_pqueue_t* other) {
    if (other == NULL) {
        return NULL;
    }
    fossil_tofu_pqueue_t* pqueue = (fossil_tofu_pqueue_t*)fossil_tofu_alloc(sizeof(fossil_tofu_pqueue_t));
    if (pqueue == NULL) {
        return NULL;
    }
    pqueue->type = other->type;
    pqueue->front = NULL;
    fossil_tofu_type_t t1 = fossil_tofu_validate_type(pqueue->type);
    fossil_tofu_type_t t2 = fossil_tofu_validate_type(other->type);
    if (t1 != t2) {
        fossil_tofu_free(pqueue);
        return NULL;
    }
    fossil_tofu_pqueue_node_t* current = other->front;
    while (current != NULL) {
        fossil_tofu_type_t node_type = fossil_tofu_get_type(&current->data);
        if (node_type != t1 && t1 != FOSSIL_TOFU_TYPE_CNULL) {
            fossil_tofu_pqueue_destroy(pqueue);
            return NULL;
        }
        fossil_tofu_pqueue_insert(pqueue, current->data.value.data, current->priority);
        current = current->next;
    }
    return pqueue;
}

fossil_tofu_pqueue_t* fossil_tofu_pqueue_create_move(fossil_tofu_pqueue_t* other) {
    if (other == NULL) {
        return NULL;
    }
    fossil_tofu_type_t t = fossil_tofu_validate_type(other->type);
    if (t == FOSSIL_TOFU_TYPE_CNULL) {
        return NULL;
    }
    fossil_tofu_pqueue_t* pqueue = (fossil_tofu_pqueue_t*)fossil_tofu_alloc(sizeof(fossil_tofu_pqueue_t));
    if (pqueue == NULL) {
        return NULL;
    }
    pqueue->type = other->type;
    pqueue->front = other->front;
    other->front = NULL;
    return pqueue;
}

void fossil_tofu_pqueue_destroy(fossil_tofu_pqueue_t* pqueue) {
    if (pqueue == NULL) {
        return;
    }
    while (pqueue->front != NULL) {
        fossil_tofu_pqueue_node_t* temp = pqueue->front;
        pqueue->front = pqueue->front->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(pqueue);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_tofu_pqueue_insert(fossil_tofu_pqueue_t* pqueue, char *data, int32_t priority) {
    if (pqueue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tofu_pqueue_node_t* node = (fossil_tofu_pqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_tofu_pqueue_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(pqueue->type, data);
    node->priority = priority;
    node->next = NULL;
    if (pqueue->front == NULL) {
        pqueue->front = node;
    } else {
        fossil_tofu_pqueue_node_t* current = pqueue->front;
        fossil_tofu_pqueue_node_t* prev = NULL;
        while (current != NULL && current->priority < priority) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            node->next = pqueue->front;
            pqueue->front = node;
        } else {
            prev->next = node;
            node->next = current;
        }
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_tofu_pqueue_remove(fossil_tofu_pqueue_t* pqueue, int32_t priority) {
    if (pqueue == NULL || pqueue->front == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tofu_pqueue_node_t* current = pqueue->front;
    fossil_tofu_pqueue_node_t* prev = NULL;
    while (current != NULL && current->priority != priority) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return FOSSIL_TOFU_FAILURE; // Node with the given priority not found
    }
    if (prev == NULL) {
        pqueue->front = current->next;
    } else {
        prev->next = current->next;
    }
    fossil_tofu_destroy(&current->data);
    fossil_tofu_free(current);
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_tofu_pqueue_size(const fossil_tofu_pqueue_t* pqueue) {
    size_t size = 0;
    fossil_tofu_pqueue_node_t* current = pqueue->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_tofu_pqueue_not_empty(const fossil_tofu_pqueue_t* pqueue) {
    return pqueue != NULL && pqueue->front != NULL;
}

bool fossil_tofu_pqueue_not_cnullptr(const fossil_tofu_pqueue_t* pqueue) {
    return pqueue != NULL;
}

bool fossil_tofu_pqueue_is_empty(const fossil_tofu_pqueue_t* pqueue) {
    return pqueue == NULL || pqueue->front == NULL;
}

bool fossil_tofu_pqueue_is_cnullptr(const fossil_tofu_pqueue_t* pqueue) {
    return pqueue == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_tofu_pqueue_get_front(const fossil_tofu_pqueue_t* pqueue) {
    return pqueue == NULL || pqueue->front == NULL ? NULL : pqueue->front->data.value.data;
}

char *fossil_tofu_pqueue_get_back(const fossil_tofu_pqueue_t* pqueue) {
    if (pqueue == NULL || pqueue->front == NULL) {
        return NULL;
    }
    fossil_tofu_pqueue_node_t* current = pqueue->front;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->data.value.data;
}

char *fossil_tofu_pqueue_get_at(const fossil_tofu_pqueue_t* pqueue, int32_t priority) {
    if (pqueue == NULL || pqueue->front == NULL) {
        return NULL;
    }
    fossil_tofu_pqueue_node_t* current = pqueue->front;
    while (current != NULL && current->priority != priority) {
        current = current->next;
    }
    return current == NULL ? NULL : current->data.value.data;
}

void fossil_tofu_pqueue_set_front(fossil_tofu_pqueue_t* pqueue, char *element) {
    if (pqueue == NULL || pqueue->front == NULL) {
        return;
    }
    fossil_tofu_set_value(&pqueue->front->data, element);
}

void fossil_tofu_pqueue_set_back(fossil_tofu_pqueue_t* pqueue, char *element) {
    if (pqueue == NULL || pqueue->front == NULL) {
        return;
    }
    fossil_tofu_pqueue_node_t* current = pqueue->front;
    while (current->next != NULL) {
        current = current->next;
    }
    fossil_tofu_set_value(&current->data, element);
}

void fossil_tofu_pqueue_set_at(fossil_tofu_pqueue_t* pqueue, int32_t priority, char *element) {
    if (pqueue == NULL || pqueue->front == NULL) {
        return;
    }
    fossil_tofu_pqueue_node_t* current = pqueue->front;
    while (current != NULL && current->priority != priority) {
        current = current->next;
    }
    if (current != NULL) {
        fossil_tofu_set_value(&current->data, element);
    }
}
