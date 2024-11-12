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
#include <stdarg.h>

fossil_vector_t* fossil_vector_create_container(char* type) {
    fossil_vector_t* vector = (fossil_vector_t*)fossil_tofu_alloc(sizeof(fossil_vector_t));
    vector->data = (fossil_tofu_t*)fossil_tofu_alloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;
    vector->type = fossil_tofu_strdup(type);
    return vector;
}

fossil_vector_t* fossil_vector_create_with(char* type, size_t size, ...) {
    fossil_vector_t* vector = fossil_vector_create_container(type);
    va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; ++i) {
        fossil_tofu_t element = va_arg(args, fossil_tofu_t);
        fossil_vector_push_back(vector, element);
    }
    va_end(args);
    return vector;
}

void fossil_vector_destroy(fossil_vector_t* vector) {
    if (vector) {
        for (size_t i = 0; i < vector->size; ++i) {
            fossil_tofu_destroy(&vector->data[i]);
        }
        fossil_tofu_free(vector->data);
        fossil_tofu_free(vector->type);
        fossil_tofu_free(vector);
    }
}

void fossil_vector_push_back(fossil_vector_t* vector, fossil_tofu_t element) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = fossil_tofu_realloc(vector->data, vector->capacity * sizeof(fossil_tofu_t));
    }
    vector->data[vector->size++] = fossil_tofu_copy(element);
}

void fossil_vector_push_front(fossil_vector_t* vector, fossil_tofu_t element) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = fossil_tofu_realloc(vector->data, vector->capacity * sizeof(fossil_tofu_t));
    }
    memmove(&vector->data[1], &vector->data[0], vector->size * sizeof(fossil_tofu_t));
    vector->data[0] = fossil_tofu_copy(element);
    vector->size++;
}

void fossil_vector_push_at(fossil_vector_t* vector, size_t index, fossil_tofu_t element) {
    if (index > vector->size) return;
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = fossil_tofu_realloc(vector->data, vector->capacity * sizeof(fossil_tofu_t));
    }
    memmove(&vector->data[index + 1], &vector->data[index], (vector->size - index) * sizeof(fossil_tofu_t));
    vector->data[index] = fossil_tofu_copy(element);
    vector->size++;
}

void fossil_vector_pop_back(fossil_vector_t* vector) {
    if (vector->size > 0) {
        fossil_tofu_destroy(&vector->data[--vector->size]);
    }
}

void fossil_vector_pop_front(fossil_vector_t* vector) {
    if (vector->size > 0) {
        fossil_tofu_destroy(&vector->data[0]);
        memmove(&vector->data[0], &vector->data[1], (vector->size - 1) * sizeof(fossil_tofu_t));
        vector->size--;
    }
}

void fossil_vector_pop_at(fossil_vector_t* vector, size_t index) {
    if (index < vector->size) {
        fossil_tofu_destroy(&vector->data[index]);
        memmove(&vector->data[index], &vector->data[index + 1], (vector->size - index - 1) * sizeof(fossil_tofu_t));
        vector->size--;
    }
}

void fossil_vector_erase(fossil_vector_t* vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        fossil_tofu_destroy(&vector->data[i]);
    }
    vector->size = 0;
}

void fossil_vector_erase_if(fossil_vector_t* vector, fossil_tofu_t target) {
    size_t j = 0;
    for (size_t i = 0; i < vector->size; ++i) {
        if (!fossil_tofu_equals(vector->data[i], target)) {
            vector->data[j++] = vector->data[i];
        } else {
            fossil_tofu_destroy(&vector->data[i]);
        }
    }
    vector->size = j;
}

int fossil_vector_search(const fossil_vector_t* vector, fossil_tofu_t target) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (fossil_tofu_equals(vector->data[i], target)) {
            return (int)i;
        }
    }
    return -1;
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

size_t fossil_vector_size(const fossil_vector_t* vector) {
    return vector->size;
}

size_t fossil_vector_capacity(const fossil_vector_t* vector) {
    return vector->capacity;
}

void fossil_vector_peek(const fossil_vector_t* vector) {
    for (size_t i = 0; i < vector->size; ++i) {
        fossil_tofu_print(vector->data[i]);
    }
}
