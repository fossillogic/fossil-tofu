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
#include "fossil/tofu/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_vector_t* fossil_vector_create(char* type) {
    fossil_vector_t* vector = (fossil_vector_t*)fossil_tofu_alloc(sizeof(fossil_vector_t));
    if (vector) {
        vector->data = NULL;
        vector->size = 0;
        vector->capacity = 0;
        vector->type = type; // Assuming type is a static string or managed separately
    }
    return vector;
}

void fossil_vector_destroy(fossil_vector_t* vector) {
    if (!vector) return;

    fossil_tofu_free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    fossil_tofu_free(vector);
}

void fossil_vector_push_back(fossil_vector_t* vector, fossil_tofu_t element) {
    if (vector->size >= vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(vector->data, new_capacity * sizeof(fossil_tofu_t));
        if (!new_data) {
            // Handle allocation failure
            return;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    vector->data[vector->size++] = element;
}

void fossil_vector_pop_back(fossil_vector_t* vector) {
    if (!vector) {
        // Handle null vector
        fprintf(stderr, "Error: Attempt to pop from a null vector.\n");
        return;
    }

    if (vector->size > 0) {
        --vector->size;
    } else {
        // Handle empty vector
        fprintf(stderr, "Error: Attempt to pop from an empty vector.\n");
    }
}

int fossil_vector_search(const fossil_vector_t* vector, fossil_tofu_t target) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (fossil_tofu_equals(vector->data[i], target)) {
            return (int)i; // Found
        }
    }
    return FOSSIL_TOFU_FAILURE; // Not found
}

void fossil_vector_reverse(fossil_vector_t* vector) {
    for (size_t i = 0; i < vector->size / 2; ++i) {
        fossil_tofu_t temp = vector->data[i];
        vector->data[i] = vector->data[vector->size - i - 1];
        vector->data[vector->size - i - 1] = temp;
    }
}

bool fossil_vector_is_cnullptr(const fossil_vector_t* vector) {
    return vector == NULL;
}

bool fossil_vector_not_cnullptr(const fossil_vector_t* vector) {
    return vector != NULL;
}

bool fossil_vector_is_empty(const fossil_vector_t* vector) {
    return vector->size == 0;
}

bool fossil_vector_not_empty(const fossil_vector_t* vector) {
    return vector->size != 0;
}

void fossil_vector_setter(fossil_vector_t* vector, size_t index, fossil_tofu_t element) {
    if (index < vector->size) {
        vector->data[index] = element;
    }
}

fossil_tofu_t* fossil_vector_getter(const fossil_vector_t* vector, size_t index) {
    if (index < vector->size) {
        return &(vector->data[index]);
    }
    return NULL; // Handle out-of-bounds access
}

size_t fossil_vector_size(const fossil_vector_t* vector) {
    return vector->size;
}

void fossil_vector_peek(const fossil_vector_t* vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        fossil_tofu_print(vector->data[i]);
    }
}
