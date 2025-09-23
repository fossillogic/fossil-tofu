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
#include "fossil/tofu/queue.h"

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_queue_t* fossil_queue_create_container(char* type) {
    fossil_queue_t* queue = (fossil_queue_t*)fossil_tofu_alloc(sizeof(fossil_queue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->type = type;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

fossil_queue_t* fossil_queue_create_default(void) {
    return fossil_queue_create_container("any");
}

fossil_queue_t* fossil_queue_create_copy(const fossil_queue_t* other) {
    fossil_queue_t* queue = (fossil_queue_t*)fossil_tofu_alloc(sizeof(fossil_queue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->type = other->type;
    queue->front = NULL;
    queue->rear = NULL;
    fossil_queue_node_t* current = other->front;
    while (current != NULL) {
        fossil_queue_insert(queue, current->data.value.data);
        current = current->next;
    }
    return queue;
}

fossil_queue_t* fossil_queue_create_move(fossil_queue_t* other) {
    fossil_queue_t* queue = (fossil_queue_t*)fossil_tofu_alloc(sizeof(fossil_queue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->type = other->type;
    queue->front = other->front;
    queue->rear = other->rear;
    other->front = NULL;
    other->rear = NULL;
    return queue;
}

void fossil_queue_destroy(fossil_queue_t* queue) {
    if (queue == NULL) {
        return;
    }
    while (queue->front != NULL) {
        fossil_queue_node_t* temp = queue->front;
        queue->front = queue->front->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(queue);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_queue_insert(fossil_queue_t* queue, char *data) {
    if (queue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_queue_node_t* node = (fossil_queue_node_t*)fossil_tofu_alloc(sizeof(fossil_queue_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(queue->type, data);
    node->next = NULL;
    if (queue->front == NULL) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_queue_remove(fossil_queue_t* queue) {
    if (queue == NULL || queue->front == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_queue_node_t* temp = queue->front;
    queue->front = queue->front->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_queue_size(const fossil_queue_t* queue) {
    size_t size = 0;
    fossil_queue_node_t* current = queue->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_queue_not_empty(const fossil_queue_t* queue) {
    return queue != NULL && queue->front != NULL;
}

bool fossil_queue_not_cnullptr(const fossil_queue_t* queue) {
    return queue != NULL;
}

bool fossil_queue_is_empty(const fossil_queue_t* queue) {
    return queue == NULL || queue->front == NULL;
}

bool fossil_queue_is_cnullptr(const fossil_queue_t* queue) {
    return queue == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_queue_get_front(const fossil_queue_t* queue) {
    return queue == NULL || queue->front == NULL ? NULL : queue->front->data.value.data;
}

char *fossil_queue_get_rear(const fossil_queue_t* queue) {
    return queue == NULL || queue->rear == NULL ? NULL : queue->rear->data.value.data;
}

void fossil_queue_set_front(fossil_queue_t* queue, char *element) {
    if (queue == NULL || queue->front == NULL) {
        return;
    }
    fossil_tofu_set_value(&queue->front->data, element);
}

void fossil_queue_set_rear(fossil_queue_t* queue, char *element) {
    if (queue == NULL || queue->rear == NULL) {
        return;
    }
    fossil_tofu_set_value(&queue->rear->data, element);
}
