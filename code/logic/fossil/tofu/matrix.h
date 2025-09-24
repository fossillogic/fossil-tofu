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

    /**
     * A C++ RAII wrapper class for the fossil_matrix_t structure.
     * Provides type-safe management of dynamic arrays of fossil_tofu_t elements.
     */
    class Matrix {
    public:
        /**
         * Default constructor. Creates a new matrix with default (generic) element type.
         * Throws std::runtime_error on failure.
         */
        Matrix() : matrix(fossil_matrix_create_default()) {
            if (!matrix) {
                throw std::runtime_error("Failed to create matrix");
            }
        }

        /**
         * Constructor that creates a new matrix with a specified expected type.
         * Throws std::runtime_error on failure.
         *
         * @param type Expected type of elements in the matrix (e.g. "string", "i32").
         */
        explicit Matrix(const std::string& type)
            : matrix(fossil_matrix_create(type.c_str())) {
            if (!matrix) {
                throw std::runtime_error("Failed to create matrix");
            }
        }

        /**
         * Copy constructor. Deep-clones the underlying matrix and all tofu elements.
         * Throws std::runtime_error on failure.
         */
        Matrix(const Matrix& other)
            : matrix(fossil_matrix_clone(other.matrix)) {
            if (!matrix) {
                throw std::runtime_error("Failed to clone matrix");
            }
        }

        /**
         * Move constructor. Transfers ownership from another Matrix instance.
         * Noexcept for strong exception guarantee.
         */
        Matrix(Matrix&& other) noexcept : matrix(other.matrix) {
            other.matrix = nullptr;
        }

        /**
         * Destructor. Destroys the matrix and frees all elements.
         */
        ~Matrix() {
            if (matrix) {
                fossil_matrix_destroy(matrix);
            }
        }

        /**
         * Copy assignment (deep copy).
         */
        Matrix& operator=(const Matrix& other) {
            if (this != &other) {
                fossil_matrix_t* new_matrix = fossil_matrix_clone(other.matrix);
                if (!new_matrix) {
                    throw std::runtime_error("Failed to copy matrix");
                }
                fossil_matrix_destroy(matrix);
                matrix = new_matrix;
            }
            return *this;
        }

        /**
         * Move assignment (transfer ownership).
         */
        Matrix& operator=(Matrix&& other) noexcept {
            if (this != &other) {
                fossil_matrix_destroy(matrix);
                matrix = other.matrix;
                other.matrix = nullptr;
            }
            return *this;
        }

        // ---------------------------------------------------------------------
        // Element management
        // ---------------------------------------------------------------------

        void push_back(const fossil_tofu_t* element) {
            fossil_matrix_push_back(matrix, element);
        }

        void push_front(const fossil_tofu_t* element) {
            fossil_matrix_push_front(matrix, element);
        }

        void insert_at(size_t index, const fossil_tofu_t* element) {
            fossil_matrix_insert_at(matrix, index, element);
        }

        void pop_back() {
            fossil_matrix_pop_back(matrix);
        }

        void pop_front() {
            fossil_matrix_pop_front(matrix);
        }

        void remove_at(size_t index) {
            fossil_matrix_remove_at(matrix, index);
        }

        void clear() {
            fossil_matrix_clear(matrix);
        }

        bool is_empty() const {
            return fossil_matrix_is_empty(matrix);
        }

        size_t size() const {
            return fossil_matrix_size(matrix);
        }

        size_t capacity() const {
            return fossil_matrix_capacity(matrix);
        }

        const fossil_tofu_t* get(size_t index) const {
            return fossil_matrix_get(matrix, index);
        }

        const fossil_tofu_t* get_front() const {
            return fossil_matrix_get_front(matrix);
        }

        const fossil_tofu_t* get_back() const {
            return fossil_matrix_get_back(matrix);
        }

        void set(size_t index, const fossil_tofu_t* element) {
            fossil_matrix_set(matrix, index, element);
        }

        // ---------------------------------------------------------------------
        // Serialization
        // ---------------------------------------------------------------------

        std::string serialize() const {
            char* serialized = fossil_matrix_serialize(matrix);
            if (!serialized) {
                throw std::runtime_error("Failed to serialize matrix");
            }
            std::string result(serialized);
            free(serialized);
            return result;
        }

        static Matrix parse(const std::string& serialized) {
            fossil_matrix_t* parsed = fossil_matrix_parse(serialized.c_str());
            if (!parsed) {
                throw std::runtime_error("Failed to parse matrix");
            }
            return Matrix(parsed);
        }

    private:
        /**
         * Private constructor for use by parse() and move semantics.
         */
        explicit Matrix(fossil_matrix_t* existing) : matrix(existing) {}

        fossil_matrix_t* matrix;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
