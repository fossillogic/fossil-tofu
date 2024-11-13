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

fossil_queue_t* fossil_queue_create_container(char* type) {
    fossil_queue_t* queue = (fossil_queue_t*)fossil_tofu_alloc(sizeof(fossil_queue_t));
    if (!queue) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->type = fossil_tofu_strdup(type);
    return queue;
}

void fossil_queue_destroy(fossil_queue_t* queue) {
    if (!queue) {
        return;
    }

    fossil_queue_node_t* current = queue->front;
    while (current) {
        fossil_queue_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(queue->type);
    fossil_tofu_free(queue);
}

int32_t fossil_queue_insert(fossil_queue_t* queue, char *data) {
    if (!queue) {
        return -1;
    }

    if (!queue->front) {
        queue->front = (fossil_queue_node_t*)fossil_tofu_alloc(sizeof(fossil_queue_node_t));
        if (!queue->front) {
            return -1;
        }
        queue->front->data = fossil_tofu_create(fossil_tofu_type_to_string(queue->type), data);
        queue->front->next = NULL;
        queue->rear = queue->front;
        return 0;
    }

    queue->rear->next = (fossil_queue_node_t*)fossil_tofu_alloc(sizeof(fossil_queue_node_t));
    if (!queue->rear->next) {
        return -1;
    }
    queue->rear->next->data = fossil_tofu_create(fossil_tofu_type_to_string(queue->type), data);
    queue->rear->next->next = NULL;
    queue->rear = queue->rear->next;
    return 0;
}

int32_t fossil_queue_remove(fossil_queue_t* queue, char *data) {
    if (!queue || !queue->front) {
        return -1;
    }

    fossil_queue_node_t* current = queue->front;
    fossil_queue_node_t* previous = NULL;
    while (current) {
        if (fossil_tofu_equal_value(current->data, fossil_tofu_create(fossil_tofu_type_to_string(queue->type), data))) {
            if (current == queue->front) {
                queue->front = current->next;
            } else {
                previous->next = current->next;
            }
            fossil_tofu_destroy(&current->data);
            fossil_tofu_free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }

    return -1;
}

size_t fossil_queue_size(const fossil_queue_t* queue) {
    if (!queue) {
        return 0;
    }

    size_t size = 0;
    fossil_queue_node_t* current = queue->front;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}

bool fossil_queue_not_empty(const fossil_queue_t* queue) {
    if (!queue) {
        return false;
    }
    return queue->front != NULL;
}

bool fossil_queue_not_cnullptr(const fossil_queue_t* queue) {
    return queue != NULL;
}

bool fossil_queue_is_empty(const fossil_queue_t* queue) {
    if (!queue) {
        return false;
    }
    return queue->front == NULL;
}

bool fossil_queue_is_cnullptr(const fossil_queue_t* queue) {
    return queue == NULL;
}
