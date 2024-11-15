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

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tuple_t *fossil_tuple_create(char *type) {
    fossil_tuple_t *tuple = (fossil_tuple_t*)fossil_tofu_alloc(sizeof(fossil_tuple_t));
    if (tuple == NULL) {
        return NULL;
    }
    tuple->elements = (fossil_tofu_t*)fossil_tofu_alloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    if (tuple->elements == NULL) {
        fossil_tofu_free(tuple);
        return NULL;
    }
    tuple->element_count = 0;
    tuple->capacity = INITIAL_CAPACITY;
    tuple->type = type;
    return tuple;
}

void fossil_tuple_destroy(fossil_tuple_t *tuple) {
    if (tuple == NULL) {
        return;
    }
    for (size_t i = 0; i < tuple->element_count; i++) {
        fossil_tofu_destroy(&tuple->elements[i]);
    }
    fossil_tofu_free(tuple->elements);
    tuple->element_count = 0;
    tuple->capacity = 0;
    tuple->type = NULL;
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

void fossil_tuple_add(fossil_tuple_t *tuple, char *element) {
    if (tuple == NULL) {
        return;
    }
    if (tuple->element_count == tuple->capacity) {
        fossil_tofu_t* new_elements = (fossil_tofu_t*)fossil_tofu_alloc(2 * tuple->capacity * sizeof(fossil_tofu_t));
        if (new_elements == NULL) {
            return;
        }
        for (size_t i = 0; i < tuple->element_count; i++) {
            new_elements[i] = tuple->elements[i];
        }
        fossil_tofu_free(tuple->elements);
        tuple->elements = new_elements;
        tuple->capacity *= 2;
    }
    tuple->elements[tuple->element_count++] = fossil_tofu_create(tuple->type, element);
}

fossil_tofu_t *fossil_tuple_get(fossil_tuple_t *tuple, size_t index) {
    if (tuple == NULL || index >= tuple->element_count) {
        return NULL;
    }
    return &tuple->elements[index];
}

void fossil_tuple_remove(fossil_tuple_t *tuple, size_t index) {
    if (tuple == NULL || index >= tuple->element_count) {
        return;
    }
    fossil_tofu_destroy(&tuple->elements[index]);
    for (size_t i = index; i < tuple->element_count - 1; i++) {
        tuple->elements[i] = tuple->elements[i + 1];
    }
    tuple->element_count--;
}

size_t fossil_tuple_size(fossil_tuple_t *tuple) {
    return tuple == NULL ? 0 : tuple->element_count;
}

size_t fossil_tuple_capacity(fossil_tuple_t *tuple) {
    return tuple == NULL ? 0 : tuple->capacity;
}

bool fossil_tuple_is_empty(fossil_tuple_t *tuple) {
    return tuple == NULL || tuple->element_count == 0;
}

void fossil_tuple_clear(fossil_tuple_t *tuple) {
    if (tuple == NULL) {
        return;
    }
    for (size_t i = 0; i < tuple->element_count; i++) {
        fossil_tofu_destroy(&tuple->elements[i]);
    }
    tuple->element_count = 0;
}

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

int fossil_tuple_algorithm_search(fossil_tuple_t* tuple, char *element) {
    if (tuple == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    for (size_t i = 0; i < tuple->element_count; i++) {
        if (fossil_tofu_compare(&tuple->elements[i], element) == 0) {
            return i;
        }
    }
    return FOSSIL_TOFU_FAILURE;
}

int fossil_tuple_algorithm_sort(fossil_tuple_t* tuple) {
    if (tuple == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    return fossil_tofu_algorithm_sort(tuple->elements, tuple->element_count, true);
}

int fossil_tuple_algorithm_reverse(fossil_tuple_t* tuple) {
    if (tuple == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    return fossil_tofu_algorithm_reverse(tuple->elements, tuple->element_count);
}
