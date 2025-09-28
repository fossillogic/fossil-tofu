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
#include "fossil/tofu/dqueue.h"

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tofu_dqueue_t* fossil_tofu_dqueue_create_container(char* type) {
    if (type == NULL || fossil_tofu_validate_type(type) == FOSSIL_TOFU_TYPE_CNULL) {
        return NULL;
    }
    fossil_tofu_dqueue_t* dqueue = (fossil_tofu_dqueue_t*)fossil_tofu_alloc(sizeof(fossil_tofu_dqueue_t));
    if (dqueue == NULL) {
        return NULL;
    }
    dqueue->front = NULL;
    dqueue->rear = NULL;
    dqueue->type = fossil_tofu_strdup(type);
    return dqueue;
}

fossil_tofu_dqueue_t* fossil_tofu_dqueue_create_default(void) {
    return fossil_tofu_dqueue_create_container("any");
}

fossil_tofu_dqueue_t* fossil_tofu_dqueue_create_copy(const fossil_tofu_dqueue_t* other) {
    if (other == NULL || other->type == NULL) {
        return NULL;
    }
    fossil_tofu_dqueue_t* dqueue = (fossil_tofu_dqueue_t*)fossil_tofu_alloc(sizeof(fossil_tofu_dqueue_t));
    if (dqueue == NULL) {
        return NULL;
    }
    dqueue->type = fossil_tofu_strdup(other->type);
    dqueue->front = NULL;
    dqueue->rear = NULL;
    fossil_tofu_dqueue_node_t* current = other->front;
    while (current != NULL) {
        // Check type match before insert
        fossil_tofu_type_t dqueue_type = fossil_tofu_validate_type(dqueue->type);
        fossil_tofu_type_t node_type = fossil_tofu_get_type(&current->data);
        if (dqueue_type != FOSSIL_TOFU_TYPE_ANY && dqueue_type != node_type) {
            fossil_tofu_dqueue_destroy(dqueue);
            return NULL;
        }
        fossil_tofu_dqueue_insert(dqueue, fossil_tofu_get_value(&current->data));
        current = current->next;
    }
    return dqueue;
}

fossil_tofu_dqueue_t* fossil_tofu_dqueue_create_move(fossil_tofu_dqueue_t* other) {
    if (other == NULL || other->type == NULL) {
        return NULL;
    }
    fossil_tofu_dqueue_t* dqueue = (fossil_tofu_dqueue_t*)fossil_tofu_alloc(sizeof(fossil_tofu_dqueue_t));
    if (dqueue == NULL) {
        return NULL;
    }
    dqueue->type = other->type;
    dqueue->front = other->front;
    dqueue->rear = other->rear;

    other->type = NULL;
    other->front = NULL;
    other->rear = NULL;

    return dqueue;
}

void fossil_tofu_dqueue_destroy(fossil_tofu_dqueue_t* dqueue) {
    fossil_tofu_dqueue_node_t* current = dqueue->front;
    while (current != NULL) {
        fossil_tofu_dqueue_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(dqueue->type);
    fossil_tofu_free(dqueue);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_tofu_dqueue_insert(fossil_tofu_dqueue_t* dqueue, char *data) {
    if (data == NULL || dqueue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }

    fossil_tofu_dqueue_node_t* node = (fossil_tofu_dqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_tofu_dqueue_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(dqueue->type, data);
    node->next = NULL;
    if (dqueue->front == NULL) {
        dqueue->front = node;
        dqueue->rear = node;
        node->prev = NULL;
    } else {
        dqueue->rear->next = node;
        node->prev = dqueue->rear;
        dqueue->rear = node;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_tofu_dqueue_remove(fossil_tofu_dqueue_t* dqueue) {
    if (dqueue->front == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tofu_dqueue_node_t* node = dqueue->front;
    dqueue->front = node->next;
    if (dqueue->front == NULL) {
        dqueue->rear = NULL;
    } else {
        dqueue->front->prev = NULL;
    }
    fossil_tofu_destroy(&node->data);
    fossil_tofu_free(node);
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_tofu_dqueue_size(const fossil_tofu_dqueue_t* dqueue) {
    size_t size = 0;
    fossil_tofu_dqueue_node_t* current = dqueue->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_tofu_dqueue_not_empty(const fossil_tofu_dqueue_t* dqueue) {
    return dqueue != NULL && dqueue->front != NULL;
}

bool fossil_tofu_dqueue_not_cnullptr(const fossil_tofu_dqueue_t* dqueue) {
    return dqueue != NULL;
}

bool fossil_tofu_dqueue_is_empty(const fossil_tofu_dqueue_t* dqueue) {
    return dqueue == NULL || dqueue->front == NULL;
}

bool fossil_tofu_dqueue_is_cnullptr(const fossil_tofu_dqueue_t* dqueue) {
    return dqueue == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_tofu_dqueue_get(const fossil_tofu_dqueue_t* dqueue, size_t index) {
    size_t i = 0;
    fossil_tofu_dqueue_node_t* current = dqueue->front;
    while (current != NULL) {
        if (i == index) {
            return fossil_tofu_get_value(&current->data);
        }
        i++;
        current = current->next;
    }
    return NULL;
}

char *fossil_tofu_dqueue_get_front(const fossil_tofu_dqueue_t* dqueue) {
    return fossil_tofu_get_value(&dqueue->front->data);
}

char *fossil_tofu_dqueue_get_back(const fossil_tofu_dqueue_t* dqueue) {
    return fossil_tofu_get_value(&dqueue->rear->data);
}

void fossil_tofu_dqueue_set(fossil_tofu_dqueue_t* dqueue, size_t index, char *element) {
    size_t i = 0;
    fossil_tofu_dqueue_node_t* current = dqueue->front;
    while (current != NULL) {
        if (i == index) {
            fossil_tofu_set_value(&current->data, element);
            return;
        }
        i++;
        current = current->next;
    }
}

void fossil_tofu_dqueue_set_front(fossil_tofu_dqueue_t* dqueue, char *element) {
    fossil_tofu_set_value(&dqueue->front->data, element);
}

void fossil_tofu_dqueue_set_back(fossil_tofu_dqueue_t* dqueue, char *element) {
    fossil_tofu_set_value(&dqueue->rear->data, element);
}
