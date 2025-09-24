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
#ifndef FOSSIL_TOFU_ARRAY_H
#define FOSSIL_TOFU_ARRAY_H

#include "tofu.h"

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// API for array structure
// *****************************************************************************

typedef struct {
    fossil_tofu_t* data;
    size_t size;
    size_t capacity;
    char* type;
} fossil_array_t;

/**
 * Creates a new array container with the specified expected type.
 *
 * @param type The expected type of elements in the array (as a string).
 * @return     Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_container(char* type);

/**
 * Creates a new array with default values.
 *
 * @return Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_default(void);

/**
 * Creates a new array by copying the contents of an existing array.
 *
 * @param other Pointer to the array to copy.
 * @return      Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_copy(const fossil_array_t* other);

/**
 * Creates a new array by moving the contents from an existing array.
 * The source array will be invalidated after the move.
 *
 * @param other Pointer to the array to move.
 * @return      Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_move(fossil_array_t* other);

/**
 * Destroys the array and frees all allocated memory.
 *
 * @param array Pointer to the array to destroy.
 */
void fossil_array_destroy(fossil_array_t* array);

/**
 * Adds an element to the end of the array.
 *
 * @param array   Pointer to the array.
 * @param element The element to add (as a string).
 */
void fossil_array_push_back(fossil_array_t* array, char *element);

/**
 * Adds an element to the front of the array.
 *
 * @param array   Pointer to the array.
 * @param element The element to add (as a string).
 */
void fossil_array_push_front(fossil_array_t* array, char *element);

/**
 * Inserts an element at the specified index in the array.
 *
 * @param array   Pointer to the array.
 * @param index   The index at which to insert the element.
 * @param element The element to add (as a string).
 */
void fossil_array_push_at(fossil_array_t* array, size_t index, char *element);

/**
 * Removes the last element from the array.
 *
 * @param array Pointer to the array.
 */
void fossil_array_pop_back(fossil_array_t* array);

/**
 * Removes the first element from the array.
 *
 * @param array Pointer to the array.
 */
void fossil_array_pop_front(fossil_array_t* array);

/**
 * Removes the element at the specified index in the array.
 *
 * @param array Pointer to the array.
 * @param index The index of the element to remove.
 */
void fossil_array_pop_at(fossil_array_t* array, size_t index);

/**
 * Removes all elements from the array, leaving it empty.
 *
 * @param array Pointer to the array.
 */
void fossil_array_erase(fossil_array_t* array);

/**
 * Checks if the array pointer is NULL.
 *
 * @param array Pointer to the array.
 * @return      true if the array is NULL, false otherwise.
 */
bool fossil_array_is_cnullptr(const fossil_array_t* array);

/**
 * Checks if the array pointer is not NULL.
 *
 * @param array Pointer to the array.
 * @return      true if the array is not NULL, false otherwise.
 */
bool fossil_array_not_cnullptr(const fossil_array_t* array);

/**
 * Checks if the array is empty (contains no elements).
 *
 * @param array Pointer to the array.
 * @return      true if the array is empty, false otherwise.
 */
bool fossil_array_is_empty(const fossil_array_t* array);

/**
 * Checks if the array is not empty (contains at least one element).
 *
 * @param array Pointer to the array.
 * @return      true if the array is not empty, false otherwise.
 */
bool fossil_array_not_empty(const fossil_array_t* array);

/**
 * Gets the number of elements currently stored in the array.
 *
 * @param array Pointer to the array.
 * @return      The size of the array.
 */
size_t fossil_array_size(const fossil_array_t* array);

/**
 * Gets the current capacity of the array (maximum number of elements before resizing).
 *
 * @param array Pointer to the array.
 * @return      The capacity of the array.
 */
size_t fossil_array_capacity(const fossil_array_t* array);

/**
 * Retrieves the element at the specified index in the array.
 *
 * @param array Pointer to the array.
 * @param index The index of the element to retrieve.
 * @return      Pointer to the element string, or NULL if out of bounds.
 */
char *fossil_array_get(const fossil_array_t* array, size_t index);

/**
 * Retrieves the first element in the array.
 *
 * @param array Pointer to the array.
 * @return      Pointer to the first element string, or NULL if the array is empty.
 */
char *fossil_array_get_front(const fossil_array_t* array);

/**
 * Retrieves the last element in the array.
 *
 * @param array Pointer to the array.
 * @return      Pointer to the last element string, or NULL if the array is empty.
 */
char *fossil_array_get_back(const fossil_array_t* array);

/**
 * Retrieves the element at the specified index in the array.
 *
 * @param array Pointer to the array.
 * @param index The index of the element to retrieve.
 * @return      Pointer to the element string, or NULL if out of bounds.
 */
char *fossil_array_get_at(const fossil_array_t* array, size_t index);

/**
 * Sets the element at the specified index in the array.
 *
 * @param array   Pointer to the array.
 * @param index   The index at which to set the element.
 * @param element The new element value (as a string).
 */
void fossil_array_set(fossil_array_t* array, size_t index, char *element);

/**
 * Sets the first element in the array.
 *
 * @param array   Pointer to the array.
 * @param element The new element value (as a string).
 */
void fossil_array_set_front(fossil_array_t* array, char *element);

/**
 * Sets the last element in the array.
 *
 * @param array   Pointer to the array.
 * @param element The new element value (as a string).
 */
void fossil_array_set_back(fossil_array_t* array, char *element);

/**
 * Sets the element at the specified index in the array.
 *
 * @param array   Pointer to the array.
 * @param index   The index at which to set the element.
 * @param element The new element value (as a string).
 */
void fossil_array_set_at(fossil_array_t* array, size_t index, char *element);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {

namespace tofu {

    /**
     * A wrapper class for the fossil_array_t structure, providing a C++ interface
     * for managing dynamic arrays of elements.
     */
    class Array {
    public:
        /**
         * Default constructor. Creates a new array with default values.
         * Throws a runtime_error if the array creation fails.
         */
        Array() : array(fossil_array_create_default()) {
            if (fossil_array_is_cnullptr(array)) {
                throw std::runtime_error("Failed to create array");
            }
        }

        /**
         * Constructor that creates a new array with the specified type.
         * Throws a runtime_error if the array creation fails.
         *
         * @param type The expected type of elements in the array.
         */
        Array(const std::string& type) : array(fossil_array_create_container(const_cast<char*>(type.c_str()))) {
            if (fossil_array_is_cnullptr(array)) {
                throw std::runtime_error("Failed to create array");
            }
        }

        /**
         * Copy constructor. Creates a new array by copying an existing array.
         * Throws a runtime_error if the array creation fails.
         *
         * @param other The array to copy.
         */
        Array(const Array& other) : array(fossil_array_create_copy(other.array)) {
            if (fossil_array_is_cnullptr(array)) {
                throw std::runtime_error("Failed to create array");
            }
        }

        /**
         * Move constructor. Creates a new array by moving an existing array.
         * Does not throw exceptions.
         *
         * @param other The array to move.
         */
        Array(Array&& other) noexcept : array(fossil_array_create_move(other.array)) {
            other.array = nullptr;
        }

        /**
         * Destructor. Destroys the array and frees allocated memory.
         */
        ~Array() {
            if (array) {
                fossil_array_destroy(array);
            }
        }

        /**
         * Adds an element to the end of the array.
         *
         * @param element The element to add.
         */
        void push_back(const std::string& element) {
            fossil_array_push_back(array, const_cast<char*>(element.c_str()));
        }

        /**
         * Adds an element to the front of the array.
         *
         * @param element The element to add.
         */
        void push_front(const std::string& element) {
            fossil_array_push_front(array, const_cast<char*>(element.c_str()));
        }

        /**
         * Adds an element at the specified index in the array.
         *
         * @param index   The index at which to add the element.
         * @param element The element to add.
         */
        void push_at(size_t index, const std::string& element) {
            fossil_array_push_at(array, index, const_cast<char*>(element.c_str()));
        }

        /**
         * Removes the last element from the array.
         */
        void pop_back() {
            fossil_array_pop_back(array);
        }

        /**
         * Removes the first element from the array.
         */
        void pop_front() {
            fossil_array_pop_front(array);
        }

        /**
         * Removes the element at the specified index in the array.
         *
         * @param index The index at which to remove the element.
         */
        void pop_at(size_t index) {
            fossil_array_pop_at(array, index);
        }

        /**
         * Removes all elements from the array.
         */
        void erase() {
            fossil_array_erase(array);
        }

        /**
         * Checks if the array is empty.
         *
         * @return True if the array is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_array_is_empty(array);
        }

        /**
         * Gets the size of the array.
         *
         * @return The size of the array.
         */
        size_t size() const {
            return fossil_array_size(array);
        }

        /**
         * Gets the capacity of the array.
         *
         * @return The capacity of the array.
         */
        size_t capacity() const {
            return fossil_array_capacity(array);
        }

        /**
         * Gets the element at the specified index in the array.
         *
         * @param index The index of the element to get.
         * @return      The element at the specified index.
         */
        std::string get(size_t index) const {
            return std::string(fossil_array_get(array, index));
        }

        /**
         * Gets the first element in the array.
         *
         * @return The first element in the array.
         */
        std::string get_front() const {
            return std::string(fossil_array_get_front(array));
        }

        /**
         * Gets the last element in the array.
         *
         * @return The last element in the array.
         */
        std::string get_back() const {
            return std::string(fossil_array_get_back(array));
        }

        /**
         * Gets the element at the specified index in the array.
         *
         * @param index The index of the element to get.
         * @return      The element at the specified index.
         */
        std::string get_at(size_t index) const {
            return std::string(fossil_array_get_at(array, index));
        }

        /**
         * Sets the element at the specified index in the array.
         *
         * @param index   The index at which to set the element.
         * @param element The element to set.
         */
        void set(size_t index, const std::string& element) {
            fossil_array_set(array, index, const_cast<char*>(element.c_str()));
        }

        /**
         * Sets the first element in the array.
         *
         * @param element The element to set.
         */
        void set_front(const std::string& element) {
            fossil_array_set_front(array, const_cast<char*>(element.c_str()));
        }

        /**
         * Sets the last element in the array.
         *
         * @param element The element to set.
         */
        void set_back(const std::string& element) {
            fossil_array_set_back(array, const_cast<char*>(element.c_str()));
        }

        /**
         * Sets the element at the specified index in the array.
         *
         * @param index   The index at which to set the element.
         * @param element The element to set.
         */
        void set_at(size_t index, const std::string& element) {
            fossil_array_set_at(array, index, const_cast<char*>(element.c_str()));
        }

    private:
        /**
         * A pointer to the underlying fossil_array_t structure.
         */
        fossil_array_t* array;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
