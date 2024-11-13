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

extern char* fossil_tofu_type_to_string(fossil_tofu_type_t type);

fossil_vector_t* fossil_vector_create_container(char* type) {
    fossil_vector_t* vector = (fossil_vector_t*)fossil_tofu_alloc(sizeof(fossil_vector_t));
    if (!vector) return NULL;
    vector->data = (fossil_tofu_t*)fossil_tofu_alloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    if (!vector->data) {
        fossil_tofu_free(vector);
        return NULL;
    }
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;
    vector->type = fossil_tofu_strdup(type);
    return vector;
}

void fossil_vector_destroy(fossil_vector_t* vector) {
    if (!vector) return;
    for (size_t i = 0; i < vector->size; i++) {
        fossil_tofu_destroy(&vector->data[i]);
    }
    fossil_tofu_free(vector->data);
    fossil_tofu_free(vector->type);
    fossil_tofu_free(vector);
}

void fossil_vector_push_back(fossil_vector_t* vector, char *element) {
    if (!vector) return;
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(vector->data, 2 * vector->capacity * sizeof(fossil_tofu_t));
        if (!new_data) return;
        vector->data = new_data;
        vector->capacity *= 2;
    }
    vector->data[vector->size++] = fossil_tofu_create(fossil_tofu_type_to_string(vector->type), element);
}

void fossil_vector_push_front(fossil_vector_t* vector, char *element) {
    if (!vector) return;
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(vector->data, 2 * vector->capacity * sizeof(fossil_tofu_t));
        if (!new_data) return;
        vector->data = new_data;
        vector->capacity *= 2;
    }
    for (size_t i = vector->size; i > 0; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[0] = fossil_tofu_create(fossil_tofu_type_to_string(vector->type), element);
    vector->size++;
}

void fossil_vector_push_at(fossil_vector_t* vector, size_t index, char *element) {
    if (!vector || index > vector->size) return;
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(vector->data, 2 * vector->capacity * sizeof(fossil_tofu_t));
        if (!new_data) return;
        vector->data = new_data;
        vector->capacity *= 2;
    }
    for (size_t i = vector->size; i > index; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index] = fossil_tofu_create(fossil_tofu_type_to_string(vector->type), element);
    vector->size++;
}

void fossil_vector_pop_back(fossil_vector_t* vector) {
    if (!vector || vector->size == 0) return;
    fossil_tofu_destroy(&vector->data[--vector->size]);
}

void fossil_vector_pop_front(fossil_vector_t* vector) {
    if (!vector || vector->size == 0) return;
    fossil_tofu_destroy(&vector->data[0]);
    for (size_t i = 0; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

void fossil_vector_pop_at(fossil_vector_t* vector, size_t index) {
    if (!vector || index >= vector->size) return;
    fossil_tofu_destroy(&vector->data[index]);
    for (size_t i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

void fossil_vector_erase(fossil_vector_t* vector) {
    if (!vector) return;
    for (size_t i = 0; i < vector->size; i++) {
        fossil_tofu_destroy(&vector->data[i]);
    }
    vector->size = 0;
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
    if (!vector) return;
    for (size_t i = 0; i < vector->size; i++) {
        fossil_tofu_print(vector->data[i]);
    }
}
