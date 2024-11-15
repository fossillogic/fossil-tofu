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
