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
#include "fossil/tofu/cqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_cqueue_t* fossil_cqueue_create_container(char* type, size_t capacity) {
    fossil_cqueue_t* queue = (fossil_cqueue_t*)fossil_tofu_alloc(sizeof(fossil_cqueue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->type = fossil_tofu_strdup(type);
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

fossil_cqueue_t* fossil_cqueue_create_default(void) {
    return fossil_cqueue_create_container("any", 0);
}

fossil_cqueue_t* fossil_cqueue_create_copy(const fossil_cqueue_t* other) {
    if (other == NULL) {
        return NULL;  // Cannot copy a null queue
    }
    fossil_cqueue_t* queue = (fossil_cqueue_t*)fossil_tofu_alloc(sizeof(fossil_cqueue_t));
    if (queue == NULL) {
        return NULL;  // Memory allocation failed
    }
    queue->type = fossil_tofu_strdup(other->type);
    queue->capacity = other->capacity;
    queue->size = other->size;
    queue->front = NULL;
    queue->rear = NULL;

    // Copy nodes
    if (other->front != NULL) {
        fossil_cqueue_node_t* current = other->front;
        do {
            fossil_cqueue_node_t* node = (fossil_cqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_cqueue_node_t));
            if (node == NULL) {
                fossil_cqueue_destroy(queue);
                return NULL;  // Memory allocation failed
            }
            node->data = fossil_tofu_create(queue->type, fossil_tofu_get_value(&current->data));
            node->next = NULL;

            if (queue->front == NULL) {
                queue->front = node;
                queue->rear = node;
                node->next = node;  // Circular link
            } else {
                queue->rear->next = node;
                queue->rear = node;
                node->next = queue->front;  // Circular link
            }
            current = current->next;
        } while (current != other->front);
    }
    return queue;
}

fossil_cqueue_t* fossil_cqueue_create_move(fossil_cqueue_t* other) {
    if (other == NULL) {
        return NULL;
    }
    fossil_cqueue_t* queue = (fossil_cqueue_t*)fossil_tofu_alloc(sizeof(fossil_cqueue_t));
    if (queue == NULL) {
        return NULL;
    }
    queue->type = other->type;
    queue->capacity = other->capacity;
    queue->size = other->size;
    queue->front = other->front;
    queue->rear = other->rear;

    // Empty the old queue
    other->type = NULL;
    other->capacity = 0;
    other->size = 0;
    other->front = NULL;
    other->rear = NULL;

    return queue;
}

void fossil_cqueue_destroy(fossil_cqueue_t* queue) {
    if (queue == NULL) {
        return;
    }
    if (queue->front != NULL) {
        queue->rear->next = NULL;  // Break the circular link
    }
    fossil_cqueue_node_t* current = queue->front;
    while (current != NULL) {
        fossil_cqueue_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(queue->type);
    fossil_tofu_free(queue);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_cqueue_insert(fossil_cqueue_t* queue, char *data) {
    if (queue->size >= queue->capacity) {
        return FOSSIL_TOFU_FAILURE;  // Queue is full
    }
    fossil_cqueue_node_t* node = (fossil_cqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_cqueue_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;  // Memory allocation failed
    }
    node->data = fossil_tofu_create(queue->type, data);
    node->next = NULL;
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
        node->next = node;  // Circular link
    } else {
        queue->rear->next = node;
        queue->rear = node;
        node->next = queue->front;  // Circular link
    }
    queue->size++;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_cqueue_remove(fossil_cqueue_t* queue) {
    if (queue->front == NULL) {
        return FOSSIL_TOFU_FAILURE;  // Queue is empty
    }
    fossil_cqueue_node_t* node = queue->front;
    if (queue->front == queue->rear) {  // Only one node in the queue
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;  // Maintain circular link
    }
    fossil_tofu_destroy(&node->data);
    fossil_tofu_free(node);
    queue->size--;
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_cqueue_size(const fossil_cqueue_t* queue) {
    return queue->size;
}

bool fossil_cqueue_not_empty(const fossil_cqueue_t* queue) {
    return (queue != NULL) && (queue->size > 0);
}

bool fossil_cqueue_not_cnullptr(const fossil_cqueue_t* queue) {
    return queue != NULL;
}

bool fossil_cqueue_is_empty(const fossil_cqueue_t* queue) {
    return (queue == NULL) || (queue->size == 0);
}

bool fossil_cqueue_is_cnullptr(const fossil_cqueue_t* queue) {
    return queue == NULL;
}

char *fossil_cqueue_get_front(const fossil_cqueue_t* queue) {
    if (queue->front == NULL) {
        return NULL;  // Queue is empty
    }
    return fossil_tofu_get_value(&queue->front->data);
}

char *fossil_cqueue_get_rear(const fossil_cqueue_t* queue) {
    if (queue->rear == NULL) {
        return NULL;  // Queue is empty
    }
    return fossil_tofu_get_value(&queue->rear->data);
}

void fossil_cqueue_set_front(fossil_cqueue_t* queue, char *element) {
    if (queue->front == NULL) {
        return;  // Queue is empty
    }
    fossil_tofu_set_value(&queue->front->data, element);
}

void fossil_cqueue_set_rear(fossil_cqueue_t* queue, char *element) {
    if (queue->rear == NULL) {
        return;  // Queue is empty
    }
    fossil_tofu_set_value(&queue->rear->data, element);
}
