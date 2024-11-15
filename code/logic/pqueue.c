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

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_pqueue_t* fossil_pqueue_create_container(char* type) {
    fossil_pqueue_t* pqueue = (fossil_pqueue_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_t));
    if (pqueue == NULL) {
        return NULL;
    }
    pqueue->type = type;
    pqueue->front = NULL;
    return pqueue;
}

void fossil_pqueue_destroy(fossil_pqueue_t* pqueue) {
    if (pqueue == NULL) {
        return;
    }
    while (pqueue->front != NULL) {
        fossil_pqueue_node_t* temp = pqueue->front;
        pqueue->front = pqueue->front->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(pqueue);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, char *data, int32_t priority) {
    if (pqueue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_pqueue_node_t* node = (fossil_pqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_pqueue_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(pqueue->type, data);
    node->priority = priority;
    node->next = NULL;
    if (pqueue->front == NULL) {
        pqueue->front = node;
    } else {
        fossil_pqueue_node_t* current = pqueue->front;
        fossil_pqueue_node_t* prev = NULL;
        while (current != NULL && current->priority < priority) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            node->next = pqueue->front;
            pqueue->front = node;
        } else {
            prev->next = node;
            node->next = current;
        }
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, int32_t priority) {
    if (pqueue == NULL || pqueue->front == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_pqueue_node_t* temp = pqueue->front;
    pqueue->front = pqueue->front->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue) {
    size_t size = 0;
    fossil_pqueue_node_t* current = pqueue->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue) {
    return pqueue != NULL && pqueue->front != NULL;
}

bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue != NULL;
}

bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue) {
    return pqueue == NULL || pqueue->front == NULL;
}

bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue) {
    return pqueue == NULL;
}

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

int fossil_pqueue_algorithm_search(fossil_pqueue_t* pqueue, char *element) {
    if (pqueue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    size_t index = 0;
    fossil_pqueue_node_t* current = pqueue->front;
    while (current != NULL) {
        if (fossil_tofu_compare(&current->data, element) == 0) {
            return index;
        }
        index++;
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;
}

int fossil_pqueue_algorithm_sort(fossil_pqueue_t* pqueue) {
    if (pqueue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_pqueue_node_t* current = pqueue->front;
    while (current != NULL) {
        fossil_pqueue_node_t* temp = current->next;
        while (temp != NULL) {
            if (fossil_tofu_compare(&current->data, &temp->data) > 0) {
                fossil_tofu_t swap = current->data;
                current->data = temp->data;
                temp->data = swap;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int fossil_pqueue_algorithm_reverse(fossil_pqueue_t* pqueue) {
    if (pqueue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_pqueue_node_t* current = pqueue->front;
    fossil_pqueue_node_t* prev = NULL;
    fossil_pqueue_node_t* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    pqueue->front = prev;
    return FOSSIL_TOFU_SUCCESS;
}
