/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/tofu/matrix.h"

#define FOSSIL_MATRIX_INITIAL_CAPACITY 8

// -----------------------------------------------------------------------------
// Internal Helpers
// -----------------------------------------------------------------------------

static bool fossil_matrix_grow(fossil_matrix_t* matrix, size_t new_capacity) {
    if (!matrix) return false;

    fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(
        matrix->data, new_capacity * sizeof(fossil_tofu_t));
    if (!new_data) return false;

    matrix->data = new_data;
    matrix->capacity = new_capacity;
    return true;
}

static bool fossil_matrix_type_matches(const fossil_matrix_t* matrix,
                                       const fossil_tofu_t* element) {
    if (!matrix->expected_type) return true; // generic matrix accepts any type
    const char* elem_type_name = fossil_tofu_type_name(fossil_tofu_get_type(element));
    return elem_type_name && strcmp(elem_type_name, matrix->expected_type) == 0;
}

// -----------------------------------------------------------------------------
// Public API Implementation
// -----------------------------------------------------------------------------

fossil_matrix_t* fossil_matrix_create(const char* expected_type) {
    fossil_matrix_t* matrix = (fossil_matrix_t*)fossil_tofu_alloc(sizeof(fossil_matrix_t));
    if (!matrix) return NULL;

    matrix->size = 0;
    matrix->capacity = FOSSIL_MATRIX_INITIAL_CAPACITY;
    matrix->data = (fossil_tofu_t*)fossil_tofu_alloc(
        matrix->capacity * sizeof(fossil_tofu_t));
    if (!matrix->data) {
        fossil_tofu_free(matrix);
        return NULL;
    }

    matrix->expected_type = expected_type ? fossil_tofu_strdup(expected_type) : NULL;
    return matrix;
}

fossil_matrix_t* fossil_matrix_create_default(void) {
    return fossil_matrix_create(NULL);
}

fossil_matrix_t* fossil_matrix_clone(const fossil_matrix_t* other) {
    if (!other) return NULL;

    fossil_matrix_t* clone = fossil_matrix_create(other->expected_type);
    if (!clone) return NULL;

    for (size_t i = 0; i < other->size; ++i) {
        fossil_matrix_push_back(clone, &other->data[i]);
    }

    return clone;
}

fossil_matrix_t* fossil_matrix_move(fossil_matrix_t* other) {
    if (!other) return NULL;

    fossil_matrix_t* new_matrix = (fossil_matrix_t*)fossil_tofu_alloc(sizeof(fossil_matrix_t));
    if (!new_matrix) return NULL;

    *new_matrix = *other; // Shallow move
    other->data = NULL;
    other->size = 0;
    other->capacity = 0;
    other->expected_type = NULL;

    return new_matrix;
}

void fossil_matrix_destroy(fossil_matrix_t* matrix) {
    if (!matrix) return;

    fossil_matrix_clear(matrix);
    fossil_tofu_free(matrix->data);
    fossil_tofu_free(matrix->expected_type);
    fossil_tofu_free(matrix);
}

int fossil_matrix_push_back(fossil_matrix_t* matrix, const fossil_tofu_t* element) {
    if (!matrix || !element) return -1;
    if (!fossil_matrix_type_matches(matrix, element)) return -1;

    if (matrix->size >= matrix->capacity) {
        if (!fossil_matrix_grow(matrix, matrix->capacity * 2)) return -1;
    }

    fossil_tofu_copy(&matrix->data[matrix->size++], element);
    return 0;
}

int fossil_matrix_push_front(fossil_matrix_t* matrix, const fossil_tofu_t* element) {
    if (!matrix || !element) return -1;
    if (!fossil_matrix_type_matches(matrix, element)) return -1;

    if (matrix->size >= matrix->capacity) {
        if (!fossil_matrix_grow(matrix, matrix->capacity * 2)) return -1;
    }

    memmove(&matrix->data[1], &matrix->data[0], matrix->size * sizeof(fossil_tofu_t));
    fossil_tofu_copy(&matrix->data[0], element);
    matrix->size++;
    return 0;
}

int fossil_matrix_insert_at(fossil_matrix_t* matrix, size_t index, const fossil_tofu_t* element) {
    if (!matrix || !element || index > matrix->size) return -1;
    if (!fossil_matrix_type_matches(matrix, element)) return -1;

    if (matrix->size >= matrix->capacity) {
        if (!fossil_matrix_grow(matrix, matrix->capacity * 2)) return -1;
    }

    memmove(&matrix->data[index + 1], &matrix->data[index],
            (matrix->size - index) * sizeof(fossil_tofu_t));
    fossil_tofu_copy(&matrix->data[index], element);
    matrix->size++;
    return 0;
}

void fossil_matrix_pop_back(fossil_matrix_t* matrix) {
    if (!matrix || matrix->size == 0) return;
    fossil_tofu_destroy(&matrix->data[--matrix->size]);
}

void fossil_matrix_pop_front(fossil_matrix_t* matrix) {
    if (!matrix || matrix->size == 0) return;
    fossil_tofu_destroy(&matrix->data[0]);
    memmove(&matrix->data[0], &matrix->data[1], (matrix->size - 1) * sizeof(fossil_tofu_t));
    matrix->size--;
}

void fossil_matrix_remove_at(fossil_matrix_t* matrix, size_t index) {
    if (!matrix || index >= matrix->size) return;
    fossil_tofu_destroy(&matrix->data[index]);
    memmove(&matrix->data[index], &matrix->data[index + 1],
            (matrix->size - index - 1) * sizeof(fossil_tofu_t));
    matrix->size--;
}

void fossil_matrix_clear(fossil_matrix_t* matrix) {
    if (!matrix) return;
    for (size_t i = 0; i < matrix->size; ++i) {
        fossil_tofu_destroy(&matrix->data[i]);
    }
    matrix->size = 0;
}

size_t fossil_matrix_size(const fossil_matrix_t* matrix) {
    return matrix ? matrix->size : 0;
}

size_t fossil_matrix_capacity(const fossil_matrix_t* matrix) {
    return matrix ? matrix->capacity : 0;
}

const fossil_tofu_t* fossil_matrix_get(const fossil_matrix_t* matrix, size_t index) {
    if (!matrix || index >= matrix->size) return NULL;
    return &matrix->data[index];
}

const fossil_tofu_t* fossil_matrix_get_front(const fossil_matrix_t* matrix) {
    if (!matrix || matrix->size == 0) return NULL;
    return &matrix->data[0];
}

const fossil_tofu_t* fossil_matrix_get_back(const fossil_matrix_t* matrix) {
    if (!matrix || matrix->size == 0) return NULL;
    return &matrix->data[matrix->size - 1];
}

int fossil_matrix_set(fossil_matrix_t* matrix, size_t index, const fossil_tofu_t* element) {
    if (!matrix || !element || index >= matrix->size) return -1;
    if (!fossil_matrix_type_matches(matrix, element)) return -1;

    fossil_tofu_destroy(&matrix->data[index]);
    fossil_tofu_copy(&matrix->data[index], element);
    return 0;
}

bool fossil_matrix_is_empty(const fossil_matrix_t* matrix) {
    return !matrix || matrix->size == 0;
}

// NOTE: Simple serialization as JSON array of tofu values
char* fossil_matrix_serialize(const fossil_matrix_t* matrix) {
    if (!matrix) return fossil_tofu_strdup("[]");

    size_t total_len = 2; // for '[' and ']'
    char** serialized_items = (char**)fossil_tofu_alloc(matrix->size * sizeof(char*));

    for (size_t i = 0; i < matrix->size; ++i) {
        serialized_items[i] = fossil_tofu_serialize(&matrix->data[i]);
        total_len += strlen(serialized_items[i]) + 2;
    }

    char* result = (char*)fossil_tofu_alloc(total_len + 1);
    char* ptr = result;
    *ptr++ = '[';
    for (size_t i = 0; i < matrix->size; ++i) {
        size_t len = strlen(serialized_items[i]);
        memcpy(ptr, serialized_items[i], len);
        ptr += len;
        if (i < matrix->size - 1) *ptr++ = ',';
        fossil_tofu_free(serialized_items[i]);
    }
    *ptr++ = ']';
    *ptr = '\0';

    fossil_tofu_free(serialized_items);
    return result;
}

// NOTE: Basic parser — assumes well-formed serialized data.
fossil_matrix_t* fossil_matrix_parse(const char* serialized) {
    if (!serialized) return NULL;
    fossil_matrix_t* matrix = fossil_matrix_create_default();

    const char* ptr = serialized;
    while (*ptr) {
        if (*ptr == '{') { // naive tofu parse
            const char* start = ptr;
            while (*ptr && *ptr != '}') ptr++;
            if (*ptr == '}') {
                size_t len = (ptr - start) + 1;
                char* tofu_str = (char*)fossil_tofu_alloc(len + 1);
                memcpy(tofu_str, start, len);
                tofu_str[len] = '\0';

                fossil_tofu_t* tofu = fossil_tofu_parse(tofu_str);
                if (tofu) fossil_matrix_push_back(matrix, tofu);
                fossil_tofu_destroy(tofu);
                fossil_tofu_free(tofu_str);
            }
        }
        ptr++;
    }

    return matrix;
}
