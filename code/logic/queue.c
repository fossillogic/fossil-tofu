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
#include <stdarg.h>

fossil_queue_t* fossil_queue_create(char* type) {
    fossil_queue_t* queue = (fossil_queue_t*)fossil_tofu_alloc(sizeof(fossil_queue_t));
    if (!queue) return NULL;
    queue->front = NULL;
    queue->rear = NULL;
    queue->type = fossil_tofu_strdup(type);  // Duplicate the type string for ownership
    return queue;
}

fossil_queue_t* fossil_queue_create_blocks(char* type, size_t size, ...) {
    fossil_queue_t* queue = fossil_queue_create(type);
    if (!queue) return NULL;

    va_list args;
    va_start(args, size);

    for (size_t i = 0; i < size; ++i) {
        fossil_tofu_t data = va_arg(args, fossil_tofu_t);
        fossil_queue_insert(queue, data);
    }

    va_end(args);
    return queue;
}

void fossil_queue_destroy(fossil_queue_t* queue) {
    if (!queue) return;

    fossil_queue_node_t* current = queue->front;
    while (current) {
        fossil_queue_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(queue->type);
    fossil_tofu_free(queue);
}

int32_t fossil_queue_insert(fossil_queue_t* queue, fossil_tofu_t data) {
    if (!queue) return -1;

    fossil_queue_node_t* node = (fossil_queue_node_t*)malloc(sizeof(fossil_queue_node_t));
    if (!node) return -1;

    node->data = data;
    node->next = NULL;

    if (!queue->rear) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }

    return 0;
}

int32_t fossil_queue_remove(fossil_queue_t* queue, fossil_tofu_t* data) {
    if (!queue || !queue->front) return -1;

    fossil_queue_node_t* temp = queue->front;
    *data = temp->data;
    queue->front = queue->front->next;

    if (!queue->front) queue->rear = NULL;

    fossil_tofu_free(temp);
    return 0;
}

int32_t fossil_queue_search(const fossil_queue_t* queue, fossil_tofu_t data) {
    fossil_queue_node_t* current = queue->front;
    while (current) {
        if (memcmp(&current->data, &data, sizeof(fossil_tofu_t)) == 0) return 0;
        current = current->next;
    }
    return -1;
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

bool fossil_queue_not_empty(const fossil_queue_t* queue) {
    return queue && queue->front != NULL;
}

bool fossil_queue_not_cnullptr(const fossil_queue_t* queue) {
    return queue != NULL;
}

bool fossil_queue_is_empty(const fossil_queue_t* queue) {
    return queue && queue->front == NULL;
}

bool fossil_queue_is_cnullptr(const fossil_queue_t* queue) {
    return queue == NULL;
}
