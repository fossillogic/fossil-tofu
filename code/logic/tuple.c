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

fossil_tuple_t fossil_tuple_create(char *type) {
    fossil_tuple_t tuple;
    tuple.elements = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (!tuple.elements) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return tuple;
    }
    tuple.element_count = 0;
    tuple.capacity = 1;
    tuple.type = fossil_tofu_strdup(type);
    return tuple;
}

void fossil_tuple_destroy(fossil_tuple_t *tuple) {
    if (!tuple) return;
    for (size_t i = 0; i < tuple->element_count; i++) {
        fossil_tofu_destroy(&tuple->elements[i]);
    }
    fossil_tofu_free(tuple->elements);
    fossil_tofu_free(tuple->type);
}

void fossil_tuple_add(fossil_tuple_t *tuple, char *element) {
    if (!tuple) return;
    if (tuple->element_count == tuple->capacity) {
        fossil_tofu_t* new_elements = (fossil_tofu_t*)fossil_tofu_realloc(tuple->elements, 2 * tuple->capacity * sizeof(fossil_tofu_t));
        if (!new_elements) return;
        tuple->elements = new_elements;
        tuple->capacity *= 2;
    }
    tuple->elements[tuple->element_count++] = fossil_tofu_create(tuple->type, element);
}

fossil_tofu_t fossil_tuple_get(fossil_tuple_t *tuple, size_t index) {
    if (!tuple || index >= tuple->element_count) {
        fprintf(stderr, "Error: Invalid tuple or index out of bounds\n");
        return fossil_tofu_create("ghost", ""); // Return a ghost tofu if tuple is invalid or index is out of bounds
    }
    return tuple->elements[index];
}

void fossil_tuple_remove(fossil_tuple_t *tuple, size_t index) {
    if (!tuple || index >= tuple->element_count) return;
    fossil_tofu_destroy(&tuple->elements[index]);
    for (size_t i = index; i < tuple->element_count - 1; i++) {
        tuple->elements[i] = tuple->elements[i + 1];
    }
    tuple->element_count--;
}

size_t fossil_tuple_size(fossil_tuple_t *tuple) {
    return tuple ? tuple->element_count : 0;
}

size_t fossil_tuple_capacity(fossil_tuple_t *tuple) {
    return tuple ? tuple->capacity : 0;
}

bool fossil_tuple_is_empty(fossil_tuple_t *tuple) {
    return tuple ? tuple->element_count == 0 : true;
}

void fossil_tuple_clear(fossil_tuple_t *tuple) {
    if (!tuple) return;
    for (size_t i = 0; i < tuple->element_count; i++) {
        fossil_tofu_destroy(&tuple->elements[i]);
    }
    tuple->element_count = 0;
}

void fossil_tuple_print(fossil_tuple_t *tuple) {
    if (!tuple) {
        fprintf(stderr, "Error: Invalid tuple\n");
        return;
    }
    printf("Tuple (%s) [", tuple->type);
    for (size_t i = 0; i < tuple->element_count; i++) {
        fossil_tofu_print(tuple->elements[i]);
        if (i < tuple->element_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
