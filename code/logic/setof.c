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
#include "fossil/tofu/setof.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_set_t* fossil_set_create_container(char* type) {
    fossil_set_t* set = (fossil_set_t*)fossil_tofu_alloc(sizeof(fossil_set_t));
    if (set == NULL) {
        return NULL;
    }
    set->type = type;
    set->head = NULL;
    return set;
}

void fossil_set_destroy(fossil_set_t* set) {
    if (set == NULL) {
        return;
    }
    while (set->head != NULL) {
        fossil_set_node_t* temp = set->head;
        set->head = set->head->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(set);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_set_insert(fossil_set_t* set, char *data) {
    if (set == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_set_node_t* node = (fossil_set_node_t*)fossil_tofu_alloc(sizeof(fossil_set_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(set->type, data);
    node->next = set->head;
    set->head = node;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_set_remove(fossil_set_t* set) {
    if (set == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_set_node_t* current = set->head;
    fossil_set_node_t* prev = NULL;
    while (current != NULL) {
        if (current == set->head) {
            if (prev == NULL) {
                set->head = current->next;
            } else {
                prev->next = current->next;
            }
            fossil_tofu_destroy(&current->data);
            fossil_tofu_free(current);
            return FOSSIL_TOFU_SUCCESS;
        }
        prev = current;
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE;
}

size_t fossil_set_size(const fossil_set_t* set) {
    size_t size = 0;
    fossil_set_node_t* current = set->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_set_not_empty(const fossil_set_t* set) {
    return set != NULL && set->head != NULL;
}

bool fossil_set_not_cnullptr(const fossil_set_t* set) {
    return set != NULL;
}

bool fossil_set_is_empty(const fossil_set_t* set) {
    return set == NULL || set->head == NULL;
}

bool fossil_set_is_cnullptr(const fossil_set_t* set) {
    return set == NULL;
}
