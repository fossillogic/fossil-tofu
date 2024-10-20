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
#include "fossil/tofu/arrayof.h"
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

// Function to create an arrayof with an initial set of elements
fossil_tofu_arrayof_t fossil_tofu_arrayof_create(char *type, size_t size, ...) {
    fossil_tofu_arrayof_t arrayof;
    arrayof.size = size;
    arrayof.capacity = size > 0 ? size : 1; // Ensure at least capacity of 1
    arrayof.array = (fossil_tofu_t *)fossil_tofu_alloc(arrayof.capacity * sizeof(fossil_tofu_t));
    if (arrayof.array == NULL) {
        fprintf(stderr, "Memory allocation failed for arrayof\n");
        exit(EXIT_FAILURE);
    }

    va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; ++i) {
        fossil_tofu_t element = fossil_tofu_create(type, va_arg(args, char*));
        arrayof.array[i] = element;
    }
    va_end(args);

    return arrayof;
}

// Function to destroy arrayof and free allocated memory
void fossil_tofu_arrayof_destroy(fossil_tofu_arrayof_t *arrayof) {
    for (size_t i = 0; i < arrayof->size; ++i) {
        fossil_tofu_destroy(&(arrayof->array[i]));
    }
    fossil_tofu_free(arrayof->array);
    arrayof->size = 0;
    arrayof->capacity = 0;
}

// Function to add a fossil_tofu_t element to the end of the arrayof
void fossil_tofu_arrayof_add(fossil_tofu_arrayof_t *arrayof, fossil_tofu_t tofu) {
    if (arrayof->size >= arrayof->capacity) {
        arrayof->capacity *= 2;
        arrayof->array = (fossil_tofu_t *)fossil_tofu_realloc(arrayof->array, arrayof->capacity * sizeof(fossil_tofu_t));
        if (arrayof->array == NULL) {
            fprintf(stderr, "Memory allocation failed while expanding arrayof\n");
            exit(EXIT_FAILURE);
        }
    }
    arrayof->array[arrayof->size++] = tofu;
}

// Function to retrieve the fossil_tofu_t element at a specified index
fossil_tofu_t fossil_tofu_arrayof_get(const fossil_tofu_arrayof_t *arrayof, size_t index) {
    if (index >= arrayof->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return arrayof->array[index];
}

// Function to return the current size of the arrayof
size_t fossil_tofu_arrayof_size(const fossil_tofu_arrayof_t *arrayof) {
    return arrayof->size;
}

// Function to check if the arrayof is empty
bool fossil_tofu_arrayof_is_empty(const fossil_tofu_arrayof_t *arrayof) {
    return arrayof->size == 0;
}

// Function to clear all elements from the arrayof
void fossil_tofu_arrayof_clear(fossil_tofu_arrayof_t *arrayof) {
    for (size_t i = 0; i < arrayof->size; ++i) {
        fossil_tofu_destroy(&(arrayof->array[i]));
    }
    arrayof->size = 0;
}

// Function to print all elements of the arrayof
void fossil_tofu_arrayof_print(const fossil_tofu_arrayof_t *arrayof) {
    for (size_t i = 0; i < arrayof->size; ++i) {
        fossil_tofu_print(arrayof->array[i]);
    }
}
