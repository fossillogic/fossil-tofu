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

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_vector_t* fossil_vector_create_container(char* type) {
    fossil_vector_t* vector = (fossil_vector_t*)fossil_tofu_alloc(sizeof(fossil_vector_t));
    if (vector == NULL) {
        return NULL;
    }
    vector->data = (fossil_tofu_t*)fossil_tofu_alloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    if (vector->data == NULL) {
        fossil_tofu_fossil_tofu_free(vector);
        return NULL;
    }
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;
    vector->type = type;
    return vector;
}

void fossil_vector_destroy(fossil_vector_t* vector) {
    if (vector == NULL) {
        return;
    }
    for (size_t i = 0; i < vector->size; i++) {
        fossil_tofu_destroy(&vector->data[i]);
    }
    fossil_tofu_fossil_tofu_free(vector->data);
    fossil_tofu_fossil_tofu_free(vector);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

void fossil_vector_push_back(fossil_vector_t* vector, char *element) {
    if (vector == NULL) {
        return;
    }
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * vector->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < vector->size; i++) {
            new_data[i] = vector->data[i];
        }
        fossil_tofu_fossil_tofu_free(vector->data);
        vector->data = new_data;
        vector->capacity *= 2;
    }
    vector->data[vector->size++] = fossil_tofu_create(vector->type, element);
}

void fossil_vector_push_front(fossil_vector_t* vector, char *element) {
    if (vector == NULL) {
        return;
    }
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * vector->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < vector->size; i++) {
            new_data[i + 1] = vector->data[i];
        }
        fossil_tofu_fossil_tofu_free(vector->data);
        vector->data = new_data;
        vector->capacity *= 2;
    } else {
        for (size_t i = vector->size; i > 0; i--) {
            vector->data[i] = vector->data[i - 1];
        }
    }
    vector->data[0] = fossil_tofu_create(vector->type, element);
    vector->size++;
}

void fossil_vector_push_at(fossil_vector_t* vector, size_t index, char *element) {
    if (vector == NULL || index > vector->size) {
        return;
    }
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * vector->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < index; i++) {
            new_data[i] = vector->data[i];
        }
        for (size_t i = index; i < vector->size; i++) {
            new_data[i + 1] = vector->data[i];
        }
        fossil_tofu_fossil_tofu_free(vector->data);
        vector->data = new_data;
        vector->capacity *= 2;
    } else {
        for (size_t i = vector->size; i > index; i--) {
            vector->data[i] = vector->data[i - 1];
        }
    }
    vector->data[index] = fossil_tofu_create(vector->type, element);
    vector->size++;
}

void fossil_vector_pop_back(fossil_vector_t* vector) {
    if (vector == NULL || vector->size == 0) {
        return;
    }
    fossil_tofu_destroy(&vector->data[--vector->size]);
}

void fossil_vector_pop_front(fossil_vector_t* vector) {
    if (vector == NULL || vector->size == 0) {
        return;
    }
    fossil_tofu_destroy(&vector->data[0]);
    for (size_t i = 0; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

void fossil_vector_pop_at(fossil_vector_t* vector, size_t index) {
    if (vector == NULL || index >= vector->size) {
        return;
    }
    fossil_tofu_destroy(&vector->data[index]);
    for (size_t i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

int32_t fossil_vector_remove(fossil_vector_t* vector) {
    if (vector == NULL || vector->size == 0) {
        return FOSSIL_TOFU_FAILURE;
    }
    for (size_t i = 0; i < vector->size; i++) {
        if (fossil_tofu_compare(&vector->data[i], vector->type) == 0) {
            fossil_vector_pop_at(vector, i);
            return FOSSIL_TOFU_SUCCESS;
        }
    }
    return FOSSIL_TOFU_FAILURE;
}

void fossil_vector_erase(fossil_vector_t* vector) {
    if (vector == NULL) {
        return;
    }
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
    return vector == NULL || vector->size == 0;
}

bool fossil_vector_not_empty(const fossil_vector_t* vector) {
    return vector != NULL && vector->size > 0;
}

size_t fossil_vector_size(const fossil_vector_t* vector) {
    return vector == NULL ? 0 : vector->size;
}

size_t fossil_vector_capacity(const fossil_vector_t* vector) {
    return vector == NULL ? 0 : vector->capacity;
}

char *fossil_vector_get(const fossil_vector_t* vector, size_t index) {
    return vector == NULL || index >= vector->size ? NULL : vector->data[index].value.data;
}

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

int fossil_vector_algorithm_search(const fossil_vector_t* vector, char *element) {
    if (vector == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    for (size_t i = 0; i < vector->size; i++) {
        if (fossil_tofu_compare(&vector->data[i], element) == 0) {
            return i;
        }
    }
    return FOSSIL_TOFU_FAILURE;
}

int fossil_vector_algorithm_sort(fossil_vector_t* vector) {
    if (vector == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tofu_t* temp = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (temp == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    for (size_t i = 0; i < vector->size; i++) {
        for (size_t j = i + 1; j < vector->size; j++) {
            if (fossil_tofu_compare(&vector->data[i], &vector->data[j]) > 0) {
                *temp = vector->data[i];
                vector->data[i] = vector->data[j];
                vector->data[j] = *temp;
            }
        }
    }
    fossil_tofu_free(temp);
    return FOSSIL_TOFU_SUCCESS;
}

int fossil_vector_algorithm_reverse(fossil_vector_t* vector) {
    if (vector == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tofu_t* temp = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (temp == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    for (size_t i = 0; i < vector->size / 2; i++) {
        *temp = vector->data[i];
        vector->data[i] = vector->data[vector->size - i - 1];
        vector->data[vector->size - i - 1] = *temp;
    }
    fossil_tofu_free(temp);
    return FOSSIL_TOFU_SUCCESS;
}
