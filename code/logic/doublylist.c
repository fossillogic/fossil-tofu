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

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_dlist_t* fossil_dlist_create_container(char* type) {
    fossil_dlist_t* dlist = (fossil_dlist_t*)fossil_tofu_alloc(sizeof(fossil_dlist_t));
    if (dlist == NULL) {
        return NULL;
    }
    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->type = fossil_tofu_strdup(type);
    return dlist;
}

void fossil_dlist_destroy(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->head;
    while (current != NULL) {
        fossil_dlist_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(dlist->type);
    fossil_tofu_free(dlist);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_dlist_insert(fossil_dlist_t* dlist, char *data) {
    fossil_dlist_node_t* node = (fossil_dlist_node_t*)fossil_tofu_alloc(sizeof(fossil_dlist_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(dlist->type, data);
    node->prev = NULL;
    node->next = dlist->head;
    if (dlist->head == NULL) {
        dlist->head = node;
        dlist->tail = node;
    } else {
        dlist->head->prev = node;
        dlist->head = node;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_dlist_remove(fossil_dlist_t* dlist) {
    if (dlist->head == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_dlist_node_t* node = dlist->head;
    dlist->head = node->next;
    if (dlist->head == NULL) {
        dlist->tail = NULL;
    } else {
        dlist->head->prev = NULL;
    }
    fossil_tofu_destroy(&node->data);
    fossil_tofu_free(node);
    return FOSSIL_TOFU_SUCCESS;
}

void fossil_dlist_reverse_forward(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* prev = NULL;
    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    dlist->head = prev;
}

void fossil_dlist_reverse_backward(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
}

size_t fossil_dlist_size(const fossil_dlist_t* dlist) {
    size_t size = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_dlist_not_empty(const fossil_dlist_t* dlist) {
    return dlist->head != NULL;
}

bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist) {
    return dlist != NULL;
}

bool fossil_dlist_is_empty(const fossil_dlist_t* dlist) {
    return dlist->head == NULL;
}

bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist) {
    return dlist == NULL;
}

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

int fossil_dlist_algorithm_search(fossil_dlist_t* dlist, char *element) {
    fossil_dlist_node_t* current = dlist->head;
    int index = 0;
    while (current != NULL) {
        if (fossil_tofu_equals(&current->data, element)) {
            return index;
        }
        current = current->next;
        index++;
    }
    return FOSSIL_TOFU_FAILURE;
}

int fossil_dlist_algorithm_sort(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->head;
    while (current != NULL) {
        fossil_dlist_node_t* next = current->next;
        while (next != NULL) {
            if (fossil_tofu_algorithm_compare(&current->data, &next->data) > 0) {
                fossil_tofu_t temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int fossil_dlist_algorithm_reverse(fossil_dlist_t* dlist) {
    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        dlist->head = temp->prev;
    }
    return FOSSIL_TOFU_SUCCESS;
}
