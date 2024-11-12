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
#include "fossil/tofu/dqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

fossil_dqueue_t* fossil_dqueue_create_container(char* type) {
    if (!type) {
        fprintf(stderr, "Error: type cannot be NULL\n");
        return NULL;
    }

    fossil_dqueue_t* dqueue = (fossil_dqueue_t*)fossil_tofu_alloc(sizeof(fossil_dqueue_t));
    if (!dqueue) {
        fprintf(stderr, "Error: Memory allocation failed for dqueue\n");
        return NULL;
    }

    dqueue->front = NULL;
    dqueue->rear = NULL;
    dqueue->type = fossil_tofu_strdup(type);  // Duplicate the type string to manage its memory
    if (!dqueue->type) {
        fprintf(stderr, "Error: Memory allocation failed for type string\n");
        fossil_tofu_free(dqueue);
        return NULL;
    }

    return dqueue;
}

fossil_dqueue_t* fossil_dqueue_create_with(char* type, size_t size, ...) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container(type);
    if (!dqueue) {
        return NULL;
    }

    va_list args;
    va_start(args, size);

    for (size_t i = 0; i < size; ++i) {
        fossil_tofu_t data = va_arg(args, fossil_tofu_t);
        fossil_dqueue_insert(dqueue, data);
    }

    va_end(args);
    return dqueue;
}

void fossil_dqueue_destroy(fossil_dqueue_t* dqueue) {
    if (!dqueue) return;

    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        fossil_dqueue_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    dqueue->front = NULL;
    dqueue->rear = NULL;
    fossil_tofu_free(dqueue->type);  // Free the duplicated type string
    fossil_tofu_free(dqueue);
}

int32_t fossil_dqueue_insert(fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    if (!dqueue) {
        fprintf(stderr, "Error: dqueue cannot be NULL\n");
        return FOSSIL_TOFU_FAILURE;
    }

    fossil_dqueue_node_t* new_node = (fossil_dqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_dqueue_node_t));
    if (!new_node) {
        fprintf(stderr, "Error: Memory allocation failed for new node\n");
        return FOSSIL_TOFU_FAILURE;  // Allocation failed
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (dqueue->rear == NULL) {
        // Empty queue case
        dqueue->front = new_node;
        dqueue->rear = new_node;
    } else {
        // Non-empty queue case
        new_node->prev = dqueue->rear;
        dqueue->rear->next = new_node;
        dqueue->rear = new_node;
    }

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_dqueue_remove(fossil_dqueue_t* dqueue, fossil_tofu_t* data) {
    if (!dqueue || !data) {
        fprintf(stderr, "Error: dqueue and data cannot be NULL\n");
        return FOSSIL_TOFU_FAILURE;
    }

    if (fossil_dqueue_is_empty(dqueue)) {
        return FOSSIL_TOFU_FAILURE;  // Empty queue
    }

    fossil_dqueue_node_t* node_to_remove = dqueue->front;

    if (node_to_remove == dqueue->rear) {
        dqueue->front = NULL;
        dqueue->rear = NULL;
    } else {
        dqueue->front = node_to_remove->next;
        dqueue->front->prev = NULL;
    }

    *data = node_to_remove->data;
    fossil_tofu_free(node_to_remove);

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_dqueue_search(const fossil_dqueue_t* dqueue, fossil_tofu_t data) {
    if (!dqueue) {
        fprintf(stderr, "Error: dqueue cannot be NULL\n");
        return FOSSIL_TOFU_FAILURE;
    }

    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return FOSSIL_TOFU_SUCCESS;  // Found
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;  // Not found
}

size_t fossil_dqueue_size(const fossil_dqueue_t* dqueue) {
    if (!dqueue) {
        fprintf(stderr, "Error: dqueue cannot be NULL\n");
        return 0;
    }

    size_t count = 0;
    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool fossil_dqueue_not_empty(const fossil_dqueue_t* dqueue) {
    if (!dqueue) {
        fprintf(stderr, "Error: dqueue cannot be NULL\n");
        return false;
    }
    return dqueue->front != NULL;
}

bool fossil_dqueue_not_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue != NULL;
}

bool fossil_dqueue_is_empty(const fossil_dqueue_t* dqueue) {
    if (!dqueue) {
        fprintf(stderr, "Error: dqueue cannot be NULL\n");
        return true;
    }
    return dqueue->front == NULL;
}

bool fossil_dqueue_is_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue == NULL;
}
