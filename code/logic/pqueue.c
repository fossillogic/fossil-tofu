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

fossil_pqueue_t* fossil_pqueue_create_container(char* type) {
    fossil_pqueue_t* pqueue = (fossil_pqueue_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_t));
    if (!pqueue) {
        return NULL;
    }
    pqueue->front = NULL;
    pqueue->type = fossil_tofu_strdup(type);
    return pqueue;
}

void fossil_pqueue_destroy(fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        return;
    }

    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        fossil_pqueue_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(pqueue->type);
    fossil_tofu_free(pqueue);
}

int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, char *data, int32_t priority) {
    if (!pqueue) {
        return -1;
    }

    if (!pqueue->front) {
        pqueue->front = (fossil_pqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_node_t));
        if (!pqueue->front) {
            return -1;
        }
        pqueue->front->data = fossil_tofu_create(pqueue->type, data);
        pqueue->front->priority = priority;
        pqueue->front->next = NULL;
        return 0;
    }

    fossil_pqueue_node_t* current = pqueue->front;
    fossil_pqueue_node_t* previous = NULL;
    while (current && current->priority < priority) {
        previous = current;
        current = current->next;
    }

    fossil_pqueue_node_t* node = (fossil_pqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_node_t));
    if (!node) {
        return -1;
    }
    node->data = fossil_tofu_create(pqueue->type, data);
    node->priority = priority;
    node->next = current;

    if (previous) {
        previous->next = node;
    } else {
        pqueue->front = node;
    }

    return 0;
}

int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, int32_t priority) {
    if (!pqueue) {
        return -1;
    }

    fossil_pqueue_node_t* current = pqueue->front;
    fossil_pqueue_node_t* previous = NULL;
    while (current && current->priority != priority) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        return -1;
    }

    if (previous) {
        previous->next = current->next;
    } else {
        pqueue->front = current->next;
    }

    fossil_tofu_destroy(&current->data);
    fossil_tofu_free(current);
    return 0;
}

size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        return 0;
    }

    size_t size = 0;
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}

bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        return false;
    }
    return pqueue->front != NULL;
}

bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue != NULL;
}

bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        return false;
    }
    return pqueue->front == NULL;
}

bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue == NULL;
}
