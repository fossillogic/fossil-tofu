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
#include "fossil/tofu/pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

fossil_pqueue_t* fossil_pqueue_create(char* type) {
    fossil_pqueue_t* pqueue = (fossil_pqueue_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_t));
    if (!pqueue) return NULL;
    pqueue->front = NULL;
    pqueue->type = fossil_tofu_strdup(type);  // Duplicate type string
    return pqueue;
}

fossil_pqueue_t* fossil_pqueue_create_blocks(char* type, size_t size, ...) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create(type);
    if (!pqueue) return NULL;

    va_list args;
    va_start(args, size);

    for (size_t i = 0; i < size; ++i) {
        fossil_tofu_t data = va_arg(args, fossil_tofu_t);
        int32_t priority = va_arg(args, int32_t);
        fossil_pqueue_insert(pqueue, data, priority);
    }

    va_end(args);
    return pqueue;
}

void fossil_pqueue_destroy(fossil_pqueue_t* pqueue) {
    if (!pqueue) return;

    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        fossil_pqueue_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(pqueue->type);
    fossil_tofu_free(pqueue);
}

int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    if (!pqueue) return -1;

    fossil_pqueue_node_t* node = (fossil_pqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_node_t));
    if (!node) return -1;

    node->data = data;
    node->priority = priority;
    node->next = NULL;

    if (!pqueue->front || pqueue->front->priority > priority) {
        node->next = pqueue->front;
        pqueue->front = node;
    } else {
        fossil_pqueue_node_t* current = pqueue->front;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }

    return 0;
}

int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, fossil_tofu_t* data, int32_t priority) {
    if (!pqueue || !pqueue->front) return -1;

    fossil_pqueue_node_t* temp = pqueue->front;
    *data = temp->data;
    pqueue->front = pqueue->front->next;

    fossil_tofu_free(temp);
    return 0;
}

int32_t fossil_pqueue_search(const fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        if (current->priority == priority && memcmp(&current->data, &data, sizeof(fossil_tofu_t)) == 0)
            return 0;
        current = current->next;
    }
    return -1;
}

size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue) {
    size_t count = 0;
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue) {
    return pqueue && pqueue->front != NULL;
}

bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue != NULL;
}

bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue) {
    return pqueue && pqueue->front == NULL;
}

bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue == NULL;
}
