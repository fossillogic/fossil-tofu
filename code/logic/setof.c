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
#include <stdarg.h>

bool fossil_set_node_equals(const fossil_set_node_t* node, fossil_tofu_t data) {
    return fossil_tofu_equals(node->data, data);
}

fossil_set_t* fossil_set_create(char* type) {
    fossil_set_t* set = (fossil_set_t*)fossil_tofu_alloc(sizeof(fossil_set_t));
    if (set) {
        set->head = NULL;
        set->type = fossil_tofu_strdup(type);
    }
    return set;
}

fossil_set_t* fossil_set_create_blocks(char* type, size_t size, ...) {
    fossil_set_t* set = fossil_set_create(type);
    if (!set) return NULL;
    
    va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; i++) {
        fossil_tofu_t data = va_arg(args, fossil_tofu_t);
        fossil_set_insert(set, data);
    }
    va_end(args);
    return set;
}

void fossil_set_destroy(fossil_set_t* set) {
    if (!set) return;
    fossil_set_node_t* current = set->head;
    while (current) {
        fossil_set_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(set->type);
    fossil_tofu_free(set);
}

int32_t fossil_set_insert(fossil_set_t* set, fossil_tofu_t data) {
    if (!set) return -1;
    if (fossil_set_contains(set, data) == 0) return 0;

    fossil_set_node_t* new_node = (fossil_set_node_t*)fossil_tofu_alloc(sizeof(fossil_set_node_t));
    if (!new_node) return -1;
    
    new_node->data = data;
    new_node->next = set->head;
    set->head = new_node;
    return 0;
}

int32_t fossil_set_remove(fossil_set_t* set, fossil_tofu_t data) {
    if (!set) return -1;

    fossil_set_node_t* current = set->head;
    fossil_set_node_t* previous = NULL;
    while (current) {
        if (fossil_set_node_equals(current, data)) { // Assuming int_val is a member of the union
            if (previous) {
                previous->next = current->next;
            } else {
                set->head = current->next;
            }
            fossil_tofu_free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}

int32_t fossil_set_search(const fossil_set_t* set, fossil_tofu_t data) {
    return fossil_set_contains(set, data);
}

size_t fossil_set_size(const fossil_set_t* set) {
    size_t count = 0;
    fossil_set_node_t* current = set->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool fossil_set_not_empty(const fossil_set_t* set) {
    return set && set->head != NULL;
}

bool fossil_set_not_cnullptr(const fossil_set_t* set) {
    return set != NULL;
}

bool fossil_set_is_empty(const fossil_set_t* set) {
    return !fossil_set_not_empty(set);
}

bool fossil_set_is_cnullptr(const fossil_set_t* set) {
    return set == NULL;
}

int32_t fossil_set_contains(const fossil_set_t* set, fossil_tofu_t data) {
    if (!set) return -1;
    
    fossil_set_node_t* current = set->head;
    while (current) {
        if (fossil_set_node_equals(current, data)) {
            return 0; // Data found
        }
        current = current->next;
    }
    return -1; // Data not found
}
