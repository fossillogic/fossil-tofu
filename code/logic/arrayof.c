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

fossil_array_t fossil_array_create_container(char *type) {
    fossil_array_t arrayof;
    arrayof.array = (fossil_tofu_t *)fossil_tofu_alloc(10 * sizeof(fossil_tofu_t));
    if (arrayof.array == NULL) {
        fprintf(stderr, "Memory allocation failed for arrayof\n");
        exit(EXIT_FAILURE);
    }
    arrayof.size = 0;
    arrayof.capacity = 10;
    return arrayof;
}

fossil_array_t fossil_array_create_with(char *type, size_t size, ...) {
    fossil_array_t arrayof;
    arrayof.array = (fossil_tofu_t *)fossil_tofu_alloc(size * sizeof(fossil_tofu_t));
    if (arrayof.array == NULL) {
        fprintf(stderr, "Memory allocation failed for arrayof\n");
        exit(EXIT_FAILURE);
    }
    arrayof.size = 0;
    arrayof.capacity = size;
    va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; ++i) {
        arrayof.array[i] = va_arg(args, fossil_tofu_t);
        ++arrayof.size;
    }
    va_end(args);
    return arrayof;
}

// Function to destroy arrayof and free allocated memory
void fossil_array_destroy(fossil_array_t *arrayof) {
    for (size_t i = 0; i < arrayof->size; ++i) {
        fossil_tofu_destroy(&(arrayof->array[i]));
    }
    fossil_tofu_free(arrayof->array);
    arrayof->size = 0;
    arrayof->capacity = 0;
}

// Function to add a fossil_tofu_t element to the end of the arrayof
void fossil_array_add(fossil_array_t *arrayof, fossil_tofu_t tofu) {
    if (arrayof == NULL || arrayof->array == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return;
    }
    if (arrayof->size >= arrayof->capacity) {
        arrayof->capacity *= 2;
        fossil_tofu_t *new_array = (fossil_tofu_t *)fossil_tofu_realloc(arrayof->array, arrayof->capacity * sizeof(fossil_tofu_t));
        if (new_array == NULL) {
            fprintf(stderr, "Memory allocation failed while expanding arrayof\n");
            exit(EXIT_FAILURE);
        }
        arrayof->array = new_array;
    }
    arrayof->array[arrayof->size++] = tofu;
}

void fossil_array_add_at(fossil_array_t *arrayof, size_t index, fossil_tofu_t tofu) {
    if (arrayof == NULL || arrayof->array == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return;
    }
    if (index > arrayof->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    if (arrayof->size >= arrayof->capacity) {
        arrayof->capacity *= 2;
        fossil_tofu_t *new_array = (fossil_tofu_t *)fossil_tofu_realloc(arrayof->array, arrayof->capacity * sizeof(fossil_tofu_t));
        if (new_array == NULL) {
            fprintf(stderr, "Memory allocation failed while expanding arrayof\n");
            exit(EXIT_FAILURE);
        }
        arrayof->array = new_array;
    }
    for (size_t i = arrayof->size; i > index; --i) {
        arrayof->array[i] = arrayof->array[i - 1];
    }
    arrayof->array[index] = tofu;
    ++arrayof->size;
}

void fossil_array_remove(fossil_array_t *arrayof, size_t index) {
    if (arrayof == NULL || arrayof->array == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return;
    }
    if (index >= arrayof->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }
    fossil_tofu_destroy(&(arrayof->array[index]));
    for (size_t i = index; i < arrayof->size - 1; ++i) {
        arrayof->array[i] = arrayof->array[i + 1];
    }
    --arrayof->size;
}

fossil_tofu_t fossil_array_get(const fossil_array_t *arrayof, size_t index) {
    if (arrayof == NULL || arrayof->array == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        exit(EXIT_FAILURE);
    }
    if (index >= arrayof->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return arrayof->array[index];
}

size_t fossil_array_capacity(const fossil_array_t *arrayof) {
    if (arrayof == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return 0;
    }
    return arrayof->capacity;
}

size_t fossil_array_size(const fossil_array_t *arrayof) {
    if (arrayof == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return 0;
    }
    return arrayof->size;
}

bool fossil_array_is_empty(const fossil_array_t *arrayof) {
    if (arrayof == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return true;
    }
    return arrayof->size == 0;
}

void fossil_array_clear(fossil_array_t *arrayof) {
    if (arrayof == NULL || arrayof->array == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return;
    }
    for (size_t i = 0; i < arrayof->size; ++i) {
        fossil_tofu_destroy(&(arrayof->array[i]));
    }
    arrayof->size = 0;
}

void fossil_array_print(const fossil_array_t *arrayof) {
    if (arrayof == NULL || arrayof->array == NULL) {
        fprintf(stderr, "Invalid arrayof\n");
        return;
    }
    for (size_t i = 0; i < arrayof->size; ++i) {
        fossil_tofu_print(arrayof->array[i]);
    }
}
