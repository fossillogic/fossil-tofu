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
#include "fossil/tofu/doublylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_dlist_t* fossil_dlist_create(char* type) {
    if (!type) return NULL;  // Error checking for null type

    fossil_dlist_t* dlist = (fossil_dlist_t*)fossil_tofu_alloc(sizeof(fossil_dlist_t));
    if (dlist) {
        dlist->head = NULL;
        dlist->tail = NULL;
        dlist->type = type;  // Ensure type is managed appropriately
    }
    return dlist;
}

void fossil_dlist_destroy(fossil_dlist_t* dlist) {
    if (!dlist) return;

    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        fossil_dlist_node_t* next = current->next;
        fossil_tofu_free(current); // Ensure deep free of node's data if necessary
        current = next;
    }
    fossil_tofu_free(dlist);
}

int32_t fossil_dlist_insert(fossil_dlist_t* dlist, fossil_tofu_t data) {
    if (!dlist) return FOSSIL_TOFU_FAILURE;

    fossil_dlist_node_t* new_node = (fossil_dlist_node_t*)fossil_tofu_alloc(sizeof(fossil_dlist_node_t));
    if (!new_node) {
        return FOSSIL_TOFU_FAILURE;  // Allocation failed
    }

    new_node->data = data;  // Consider deep copying data if necessary
    new_node->prev = NULL;
    new_node->next = NULL;

    if (dlist->tail == NULL) {
        dlist->head = new_node;
        dlist->tail = new_node;
    } else {
        new_node->prev = dlist->tail;
        dlist->tail->next = new_node;
        dlist->tail = new_node;
    }

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_dlist_remove(fossil_dlist_t* dlist, fossil_tofu_t* data) {
    if (!dlist || !data) return FOSSIL_TOFU_FAILURE;  // Error checking for null pointers

    if (fossil_dlist_is_empty(dlist)) {
        return FOSSIL_TOFU_FAILURE;  // Empty list
    }

    fossil_dlist_node_t* node_to_remove = dlist->tail;
    if (!node_to_remove) return FOSSIL_TOFU_FAILURE;

    if (node_to_remove == dlist->head) {
        dlist->head = NULL;
        dlist->tail = NULL;
    } else {
        dlist->tail = node_to_remove->prev;
        dlist->tail->next = NULL;
    }

    *data = node_to_remove->data;  // Consider deep copy if necessary
    fossil_tofu_free(node_to_remove);

    return FOSSIL_TOFU_SUCCESS;  // Success
}

int32_t fossil_dlist_search(const fossil_dlist_t* dlist, fossil_tofu_t data) {
    if (!dlist) return FOSSIL_TOFU_FAILURE;  // Error checking for null list

    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return FOSSIL_TOFU_SUCCESS;  // Found
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;  // Not found
}

void fossil_dlist_reverse_forward(fossil_dlist_t* dlist) {
    if (!dlist) return;

    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = NULL;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to the next node (which is actually previous in the original order)
    }

    // Swap head and tail
    if (temp) {
        dlist->head = temp->prev;
    }
    dlist->tail = dlist->head;
    while (dlist->tail && dlist->tail->next) {
        dlist->tail = dlist->tail->next;
    }
}

void fossil_dlist_reverse_backward(fossil_dlist_t* dlist) {
    if (!dlist) return;

    fossil_dlist_node_t* current = dlist->tail;
    fossil_dlist_node_t* temp = NULL;

    while (current) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->next;  // Move to the next node (which is actually previous in the original order)
    }

    // Swap head and tail
    if (temp) {
        dlist->tail = temp->next;
    }
    dlist->head = dlist->tail;
    while (dlist->head && dlist->head->prev) {
        dlist->head = dlist->head->prev;
    }
}

size_t fossil_dlist_size(const fossil_dlist_t* dlist) {
    if (!dlist) return 0;  // Error checking for null list

    size_t count = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool fossil_dlist_not_empty(const fossil_dlist_t* dlist) {
    return (dlist != NULL && dlist->head != NULL);
}

bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist) {
    return (dlist != NULL);
}

bool fossil_dlist_is_empty(const fossil_dlist_t* dlist) {
    return (dlist == NULL || dlist->head == NULL);
}

bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist) {
    return (dlist == NULL);
}
