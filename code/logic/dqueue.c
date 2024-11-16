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

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_dqueue_t* fossil_dqueue_create_container(char* type) {
    fossil_dqueue_t* dqueue = (fossil_dqueue_t*)fossil_tofu_alloc(sizeof(fossil_dqueue_t));
    if (dqueue == NULL) {
        return NULL;
    }
    dqueue->front = NULL;
    dqueue->rear = NULL;
    dqueue->type = fossil_tofu_strdup(type);
    return dqueue;
}

void fossil_dqueue_destroy(fossil_dqueue_t* dqueue) {
    fossil_dqueue_node_t* current = dqueue->front;
    while (current != NULL) {
        fossil_dqueue_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(dqueue->type);
    fossil_tofu_free(dqueue);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_dqueue_insert(fossil_dqueue_t* dqueue, char *data) {
    if (data == NULL || dqueue == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }

    fossil_dqueue_node_t* node = (fossil_dqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_dqueue_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(dqueue->type, data);
    node->next = NULL;
    if (dqueue->front == NULL) {
        dqueue->front = node;
        dqueue->rear = node;
        node->prev = NULL;
    } else {
        dqueue->rear->next = node;
        node->prev = dqueue->rear;
        dqueue->rear = node;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_dqueue_remove(fossil_dqueue_t* dqueue) {
    if (dqueue->front == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_dqueue_node_t* node = dqueue->front;
    dqueue->front = node->next;
    if (dqueue->front == NULL) {
        dqueue->rear = NULL;
    } else {
        dqueue->front->prev = NULL;
    }
    fossil_tofu_destroy(&node->data);
    fossil_tofu_free(node);
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_dqueue_size(const fossil_dqueue_t* dqueue) {
    size_t size = 0;
    fossil_dqueue_node_t* current = dqueue->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_dqueue_not_empty(const fossil_dqueue_t* dqueue) {
    return dqueue->front != NULL;
}

bool fossil_dqueue_not_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue != NULL;
}

bool fossil_dqueue_is_empty(const fossil_dqueue_t* dqueue) {
    return dqueue->front == NULL;
}

bool fossil_dqueue_is_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue == NULL;
}
