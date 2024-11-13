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

fossil_dqueue_t* fossil_dqueue_create_container(char* type) {
    fossil_dqueue_t* dqueue = (fossil_dqueue_t*)fossil_tofu_alloc(sizeof(fossil_dqueue_t));
    if (!dqueue) {
        return NULL;
    }
    dqueue->front = NULL;
    dqueue->rear = NULL;
    dqueue->type = fossil_tofu_strdup(type);
    return dqueue;
}

void fossil_dqueue_destroy(fossil_dqueue_t* dqueue) {
    if (!dqueue) {
        return;
    }

    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        fossil_dqueue_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(dqueue->type);
    fossil_tofu_free(dqueue);
}

int32_t fossil_dqueue_insert(fossil_dqueue_t* dqueue, char *data) {
    if (!dqueue) {
        return -1;
    }

    if (!dqueue->front) {
        dqueue->front = (fossil_dqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_dqueue_node_t));
        if (!dqueue->front) {
            return -1;
        }
        dqueue->front->data = fossil_tofu_create(dqueue->type, data);
        dqueue->front->prev = NULL;
        dqueue->front->next = NULL;
        dqueue->rear = dqueue->front;
        return 0;
    }

    dqueue->rear->next = (fossil_dqueue_node_t*)fossil_tofu_alloc(sizeof(fossil_dqueue_node_t));
    if (!dqueue->rear->next) {
        return -1;
    }
    dqueue->rear->next->data = fossil_tofu_create(dqueue->type, data);
    dqueue->rear->next->prev = dqueue->rear;
    dqueue->rear->next->next = NULL;
    dqueue->rear = dqueue->rear->next;
    return 0;
}

int32_t fossil_dqueue_remove(fossil_dqueue_t* dqueue) {
    if (!dqueue || !dqueue->front) {
        return -1;
    }

    fossil_dqueue_node_t* temp = dqueue->front;
    dqueue->front = dqueue->front->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return 0;
}

size_t fossil_dqueue_size(const fossil_dqueue_t* dqueue) {
    if (!dqueue) {
        return 0;
    }

    size_t size = 0;
    fossil_dqueue_node_t* current = dqueue->front;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}

bool fossil_dqueue_not_empty(const fossil_dqueue_t* dqueue) {
    return fossil_dqueue_size(dqueue) > 0;
}

bool fossil_dqueue_not_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue != NULL;
}

bool fossil_dqueue_is_empty(const fossil_dqueue_t* dqueue) {
    return fossil_dqueue_size(dqueue) == 0;
}

bool fossil_dqueue_is_cnullptr(const fossil_dqueue_t* dqueue) {
    return dqueue == NULL;
}
