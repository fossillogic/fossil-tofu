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
#ifndef FOSSIL_TOFU_MATRIX_H
#define FOSSIL_TOFU_MATRIX_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// API for Matrix (Array of Tofu)
// *****************************************************************************

typedef struct {
    fossil_tofu_t* data;    // Array of tofu objects
    size_t size;            // Number of elements in use
    size_t capacity;        // Allocated capacity
    char* expected_type;    // Type string all elements must conform to (e.g. "string", "i32")
} fossil_matrix_t;

/**
 * Creates a new matrix container with a given expected element type.
 *
 * @param expected_type Expected type string (e.g. "string", "int").
 * @return Pointer to a newly allocated matrix, or NULL on failure.
 */
fossil_matrix_t* fossil_matrix_create(const char* expected_type);

/**
 * Creates an empty matrix with default element type (generic).
 */
fossil_matrix_t* fossil_matrix_create_default(void);

/**
 * Creates a deep copy of a matrix, including cloning each tofu element.
 */
fossil_matrix_t* fossil_matrix_clone(const fossil_matrix_t* other);

/**
 * Moves the contents from another matrix into a new one.
 * The source is invalidated after the move.
 */
fossil_matrix_t* fossil_matrix_move(fossil_matrix_t* other);

/**
 * Destroys the matrix and frees all elements (deep free).
 */
void fossil_matrix_destroy(fossil_matrix_t* matrix);

/**
 * Adds an element to the end of the matrix.
 * The element is cloned before insertion.
 */
int fossil_matrix_push_back(fossil_matrix_t* matrix, const fossil_tofu_t* element);

/**
 * Adds an element to the front of the matrix.
 */
int fossil_matrix_push_front(fossil_matrix_t* matrix, const fossil_tofu_t* element);

/**
 * Inserts an element at a given index.
 */
int fossil_matrix_insert_at(fossil_matrix_t* matrix, size_t index, const fossil_tofu_t* element);

/**
 * Removes the last element from the matrix.
 */
void fossil_matrix_pop_back(fossil_matrix_t* matrix);

/**
 * Removes the first element from the matrix.
 */
void fossil_matrix_pop_front(fossil_matrix_t* matrix);

/**
 * Removes the element at the specified index.
 */
void fossil_matrix_remove_at(fossil_matrix_t* matrix, size_t index);

/**
 * Clears the matrix (deep destroy of all tofu elements).
 */
void fossil_matrix_clear(fossil_matrix_t* matrix);

/**
 * Gets the number of elements.
 */
size_t fossil_matrix_size(const fossil_matrix_t* matrix);

/**
 * Gets the current capacity.
 */
size_t fossil_matrix_capacity(const fossil_matrix_t* matrix);

/**
 * Returns a pointer to the tofu element at a given index.
 * The returned pointer is owned by the matrix (do not free).
 */
const fossil_tofu_t* fossil_matrix_get(const fossil_matrix_t* matrix, size_t index);

/**
 * Returns a pointer to the first element.
 */
const fossil_tofu_t* fossil_matrix_get_front(const fossil_matrix_t* matrix);

/**
 * Returns a pointer to the last element.
 */
const fossil_tofu_t* fossil_matrix_get_back(const fossil_matrix_t* matrix);

/**
 * Replaces an element at a given index.
 * The new element is cloned before assignment.
 */
int fossil_matrix_set(fossil_matrix_t* matrix, size_t index, const fossil_tofu_t* element);

/**
 * Checks if the matrix is empty.
 */
bool fossil_matrix_is_empty(const fossil_matrix_t* matrix);

/**
 * Serializes the entire matrix into a JSON-like string.
 */
char* fossil_matrix_serialize(const fossil_matrix_t* matrix);

/**
 * Parses a serialized matrix back into a matrix object.
 */
fossil_matrix_t* fossil_matrix_parse(const char* serialized);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {
    
namespace tofu {

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
