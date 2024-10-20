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
#include "fossil/tofu/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_queue_t* fossil_queue_create(char* type) {
    fossil_queue_t* queue = (fossil_queue_t*)fossil_tofu_alloc(sizeof(fossil_queue_t));
    if (queue) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->type = type;  // Assuming type is a static string or managed separately
    }
    return queue;
}

void fossil_queue_erase(fossil_queue_t* queue) {
    if (!queue) return;

    fossil_queue_node_t* current = queue->front;
    while (current) {
        fossil_queue_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    queue->front = NULL;
    queue->rear = NULL;
    fossil_tofu_free(queue);
}

int32_t fossil_queue_insert(fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* new_node = (fossil_queue_node_t*)fossil_tofu_alloc(sizeof(fossil_queue_node_t));
    if (!new_node) {
        return FOSSIL_TOFU_FAILURE;  // Allocation failed
    }

    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node; // Empty queue case
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node; // Non-empty queue case
        queue->rear = new_node;
    }

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_queue_remove(fossil_queue_t* queue, fossil_tofu_t* data) {
    if (fossil_queue_is_empty(queue)) {
        return FOSSIL_TOFU_FAILURE;  // Empty queue
    }

    fossil_queue_node_t* node_to_remove = queue->front;
    *data = node_to_remove->data;
    queue->front = node_to_remove->next;
    fossil_tofu_free(node_to_remove);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_queue_search(const fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* current = queue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return FOSSIL_TOFU_SUCCESS;  // Found
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;  // Not found
}

size_t fossil_queue_size(const fossil_queue_t* queue) {
    size_t count = 0;
    fossil_queue_node_t* current = queue->front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_queue_getter(fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* current = queue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return NULL;  // Not found
}

int32_t fossil_queue_setter(fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* current = queue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return FOSSIL_TOFU_SUCCESS;  // Success
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;  // Not found
}


bool fossil_queue_not_empty(const fossil_queue_t* queue) {
    return queue->front != NULL;
}

bool fossil_queue_not_cnullptr(const fossil_queue_t* queue) {
    return queue != NULL;
}

bool fossil_queue_is_empty(const fossil_queue_t* queue) {
    return queue->front == NULL;
}

bool fossil_queue_is_cnullptr(const fossil_queue_t* queue) {
    return queue == NULL;
}
