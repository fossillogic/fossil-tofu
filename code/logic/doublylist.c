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
    fossil_dlist_t* dlist = (fossil_dlist_t*)fossil_tofu_alloc(sizeof(fossil_dlist_t));
    if (dlist) {
        dlist->head = NULL;
        dlist->tail = NULL;
        dlist->type = type;  // Assuming type is a static string or managed separately
    }
    return dlist;
}

void fossil_dlist_erase(fossil_dlist_t* dlist) {
    if (!dlist) return;

    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        fossil_dlist_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    dlist->head = NULL;
    dlist->tail = NULL;
    fossil_tofu_free(dlist);
}

int32_t fossil_dlist_insert(fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* new_node = (fossil_dlist_node_t*)fossil_tofu_alloc(sizeof(fossil_dlist_node_t));
    if (!new_node) {
        return -1;  // Allocation failed
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (dlist->head == NULL) {
        // Empty list case
        dlist->head = new_node;
        dlist->tail = new_node;
    } else {
        // Non-empty list case
        new_node->prev = dlist->tail;
        dlist->tail->next = new_node;
        dlist->tail = new_node;
    }

    return 0;  // Success
}

int32_t fossil_dlist_remove(fossil_dlist_t* dlist, fossil_tofu_t* data) {
    if (fossil_dlist_is_empty(dlist)) {
        return -1;  // Empty list
    }

    fossil_dlist_node_t* node_to_remove = dlist->tail;

    if (node_to_remove == dlist->head) {
        // Only one node in the list
        dlist->head = NULL;
        dlist->tail = NULL;
    } else {
        dlist->tail = node_to_remove->prev;
        dlist->tail->next = NULL;
    }

    *data = node_to_remove->data;
    fossil_tofu_free(node_to_remove);

    return 0;  // Success
}

int32_t fossil_dlist_search(const fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return 0;  // Found
        }
        current = current->next;
    }
    return -1;  // Not found
}

void fossil_dlist_reverse_forward(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = NULL;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node
    }

    // Swap head and tail
    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

void fossil_dlist_reverse_backward(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->tail;
    fossil_dlist_node_t* temp = NULL;

    while (current) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->next; // Move to the previous node
    }

    // Swap head and tail
    temp = dlist->head;
    dlist->head = dlist->tail;
    dlist->tail = temp;
}

size_t fossil_dlist_size(const fossil_dlist_t* dlist) {
    size_t count = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_dlist_getter(fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data);  // Return pointer to found data
        }
        current = current->next;
    }
    return NULL;  // Not found
}

int32_t fossil_dlist_setter(fossil_dlist_t* dlist, fossil_tofu_t data) {
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data;  // Update data
            return 0;  // Success
        }
        current = current->next;
    }
    return -1;  // Not found
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
