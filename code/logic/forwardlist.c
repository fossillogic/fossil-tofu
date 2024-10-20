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
#include "fossil/tofu/forwardlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_flist_t* fossil_flist_create(char* type) {
    fossil_flist_t* flist = (fossil_flist_t*)fossil_tofu_alloc(sizeof(fossil_flist_t));
    if (flist) {
        flist->head = NULL;
        flist->type = type;  // Assuming type is a static string or managed separately
    }
    return flist;
}

void fossil_flist_destroy(fossil_flist_t* flist) {
    if (!flist) return;

    fossil_flist_node_t* current = flist->head;
    while (current) {
        fossil_flist_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    flist->head = NULL;
    fossil_tofu_free(flist);
}

int32_t fossil_flist_insert(fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* new_node = (fossil_flist_node_t*)fossil_tofu_alloc(sizeof(fossil_flist_node_t));
    if (!new_node) {
        return FOSSIL_TOFU_FAILURE;  // Allocation failed
    }

    new_node->data = data;
    new_node->next = flist->head;
    flist->head = new_node;

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_flist_remove(fossil_flist_t* flist, fossil_tofu_t* data) {
    if (fossil_flist_is_cnullptr(flist)) {
        return FOSSIL_TOFU_FAILURE;  // Empty list
    }

    fossil_flist_node_t* node_to_remove = flist->head;
    *data = node_to_remove->data;
    flist->head = node_to_remove->next;
    fossil_tofu_free(node_to_remove);

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_flist_search(const fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* current = flist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return FOSSIL_TOFU_SUCCESS;  // Found
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;  // Not found
}

void fossil_flist_reverse_forward(fossil_flist_t* flist) {
    fossil_flist_node_t* prev = NULL;
    fossil_flist_node_t* current = flist->head;
    fossil_flist_node_t* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    flist->head = prev;
}

void fossil_flist_reverse_backward(fossil_flist_t* flist) {
    fossil_flist_reverse_forward(flist);
}

size_t fossil_flist_size(const fossil_flist_t* flist) {
    size_t count = 0;
    fossil_flist_node_t* current = flist->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_flist_getter(fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* current = flist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return NULL;  // Not found
}

int32_t fossil_flist_setter(fossil_flist_t* flist, fossil_tofu_t data) {
    fossil_flist_node_t* current = flist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return FOSSIL_TOFU_SUCCESS;  // Success
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;  // Not found
}

bool fossil_flist_not_empty(const fossil_flist_t* flist) {
    return flist->head != NULL;
}

bool fossil_flist_not_cnullptr(const fossil_flist_t* flist) {
    return flist != NULL;
}

bool fossil_flist_is_empty(const fossil_flist_t* flist) {
    return flist->head == NULL;
}

bool fossil_flist_is_cnullptr(const fossil_flist_t* flist) {
    return flist == NULL;
}
