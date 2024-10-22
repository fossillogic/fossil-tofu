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

fossil_pqueue_t* fossil_pqueue_create(char* type) {
    if (!type) {
        fprintf(stderr, "Error: type cannot be NULL\n");
        return NULL;
    }

    fossil_pqueue_t* pqueue = (fossil_pqueue_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_t));
    if (!pqueue) {
        fprintf(stderr, "Error: Memory allocation failed for pqueue\n");
        return NULL;
    }

    pqueue->front = NULL;
    pqueue->type = type;  // Assuming type is a static string or managed separately
    return pqueue;
}

void fossil_pqueue_destroy(fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        fprintf(stderr, "Error: pqueue cannot be NULL\n");
        return;
    }

    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        fossil_pqueue_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    pqueue->front = NULL;
    fossil_tofu_free(pqueue);
}

int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    if (!pqueue) {
        fprintf(stderr, "Error: pqueue cannot be NULL\n");
        return FOSSIL_TOFU_FAILURE;
    }

    fossil_pqueue_node_t* new_node = (fossil_pqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_node_t));
    if (!new_node) {
        fprintf(stderr, "Error: Memory allocation failed for new_node\n");
        return FOSSIL_TOFU_FAILURE;  // Allocation failed
    }

    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (!pqueue->front || pqueue->front->priority > priority) {
        new_node->next = pqueue->front;
        pqueue->front = new_node;
    } else {
        fossil_pqueue_node_t* current = pqueue->front;
        while (current->next && current->next->priority <= priority) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, fossil_tofu_t* data, int32_t priority) {
    if (!pqueue) {
        fprintf(stderr, "Error: pqueue cannot be NULL\n");
        return FOSSIL_TOFU_FAILURE;
    }

    if (!data) {
        fprintf(stderr, "Error: data cannot be NULL\n");
        return FOSSIL_TOFU_FAILURE;
    }

    if (fossil_pqueue_is_empty(pqueue)) {
        return FOSSIL_TOFU_FAILURE;  // Empty queue
    }

    fossil_pqueue_node_t* current = pqueue->front;
    fossil_pqueue_node_t* prev = NULL;

    while (current && current->priority != priority) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        return FOSSIL_TOFU_FAILURE;  // Not found
    }

    if (prev) {
        prev->next = current->next;
    } else {
        pqueue->front = current->next;
    }

    *data = current->data;
    fossil_tofu_free(current);

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_pqueue_search(const fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority) {
    if (!pqueue) {
        fprintf(stderr, "Error: pqueue cannot be NULL\n");
        return FOSSIL_TOFU_FAILURE;
    }

    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        if (current->priority == priority && fossil_tofu_equals(current->data, data)) {
            return FOSSIL_TOFU_SUCCESS;  // Found
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;  // Not found
}

size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        fprintf(stderr, "Error: pqueue cannot be NULL\n");
        return 0;
    }

    size_t count = 0;
    fossil_pqueue_node_t* current = pqueue->front;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        fprintf(stderr, "Error: pqueue cannot be NULL\n");
        return false;
    }
    return pqueue->front != NULL;
}

bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue != NULL;
}

bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue) {
    if (!pqueue) {
        fprintf(stderr, "Error: pqueue cannot be NULL\n");
        return true;
    }
    return pqueue->front == NULL;
}

bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue == NULL;
}
