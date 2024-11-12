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
#include "fossil/tofu/tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

fossil_tuple_t fossil_tuple_create(size_t size) {
    fossil_tuple_t tuple;
    tuple.elements = (fossil_tofu_t*)malloc(size * sizeof(fossil_tofu_t));
    tuple.element_count = 0;
    tuple.capacity = size;
    tuple.type = NULL;  // Set a type if needed
    return tuple;
}

void fossil_tuple_destroy(fossil_tuple_t *tuple) {
    if (tuple->elements) {
        free(tuple->elements);
    }
    if (tuple->type) {
        free(tuple->type);
    }
    tuple->elements = NULL;
    tuple->element_count = 0;
    tuple->capacity = 0;
}

void fossil_tuple_add(fossil_tuple_t *tuple, fossil_tofu_t element) {
    if (tuple->element_count == tuple->capacity) {
        tuple->capacity *= 2;
        tuple->elements = (fossil_tofu_t*)realloc(tuple->elements, tuple->capacity * sizeof(fossil_tofu_t));
    }
    tuple->elements[tuple->element_count++] = element;
}

fossil_tofu_t* fossil_tuple_get(fossil_tuple_t *tuple, size_t index) {
    if (index >= tuple->element_count) {
        return NULL;
    }
    return &tuple->elements[index];
}

void fossil_tuple_remove(fossil_tuple_t *tuple, size_t index) {
    if (index < tuple->element_count) {
        for (size_t i = index; i < tuple->element_count - 1; i++) {
            tuple->elements[i] = tuple->elements[i + 1];
        }
        tuple->element_count--;
    }
}

size_t fossil_tuple_size(fossil_tuple_t *tuple) {
    return tuple->element_count;
}

size_t fossil_tuple_capacity(fossil_tuple_t *tuple) {
    return tuple->capacity;
}

bool fossil_tuple_is_empty(fossil_tuple_t *tuple) {
    return tuple->element_count == 0;
}

void fossil_tuple_clear(fossil_tuple_t *tuple) {
    tuple->element_count = 0;
}

void fossil_tuple_print(fossil_tuple_t *tuple) {
    printf("Tuple contains %zu elements:\n", tuple->element_count);
    for (size_t i = 0; i < tuple->element_count; i++) {
        // Assuming a function fossil_tofu_print() exists to print a fossil_tofu_t element
        fossil_tofu_print(tuple->elements[i]);
    }
    printf("\n");
}
