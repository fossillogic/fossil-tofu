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
 * This function allocates and initializes a new fossil_array_t structure,
 * setting its type field to the provided string. The array is initially empty,
 * and its capacity is set according to implementation defaults.
 *
 * @param type The expected type of elements in the array (as a string).
 * @return     Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_container(char* type);

/**
 * Creates a new array with default values.
 *
 * This function allocates and initializes a new fossil_array_t structure
 * with default type and capacity. The array is initially empty.
 *
 * @return Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_default(void);

/**
 * Creates a new array by copying the contents of an existing array.
 *
 * This function allocates a new fossil_array_t structure and copies all
 * elements, size, capacity, and type from the provided array. The new array
 * is independent of the original.
 *
 * @param other Pointer to the array to copy.
 * @return      Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_copy(const fossil_array_t* other);

/**
 * Creates a new array by moving the contents from an existing array.
 * The source array will be invalidated after the move.
 *
 * This function transfers ownership of the data from the source array to
 * the new array, leaving the source array in an invalid state (typically NULL).
 *
 * @param other Pointer to the array to move.
 * @return      Pointer to the newly created fossil_array_t structure, or NULL on failure.
 */
fossil_array_t* fossil_array_create_move(fossil_array_t* other);

/**
 * Destroys the array and frees all allocated memory.
 *
 * This function releases all resources associated with the array, including
 * its data buffer and type string. After calling this, the array pointer
 * should not be used.
 *
 * @param array Pointer to the array to destroy.
 */
void fossil_array_destroy(fossil_array_t* array);

/**
 * Adds an element to the end of the array.
 *
 * This function appends the provided element string to the end of the array,
 * resizing the array if necessary to accommodate the new element.
 *
 * @param array   Pointer to the array.
 * @param element The element to add (as a string).
 */
void fossil_array_push_back(fossil_array_t* array, char *element);

/**
 * Adds an element to the front of the array.
 *
 * This function inserts the provided element string at the beginning of the array,
 * shifting existing elements as needed and resizing if necessary.
 *
 * @param array   Pointer to the array.
 * @param element The element to add (as a string).
 */
void fossil_array_push_front(fossil_array_t* array, char *element);

/**
 * Inserts an element at the specified index in the array.
 *
 * This function inserts the provided element string at the given index,
 * shifting subsequent elements and resizing the array if required.
 *
 * @param array   Pointer to the array.
 * @param index   The index at which to insert the element.
 * @param element The element to add (as a string).
 */
void fossil_array_push_at(fossil_array_t* array, size_t index, char *element);

/**
 * Removes the last element from the array.
 *
 * This function deletes the element at the end of the array, reducing its size by one.
 * If the array is empty, no action is taken.
 *
 * @param array Pointer to the array.
 */
void fossil_array_pop_back(fossil_array_t* array);

/**
 * Removes the first element from the array.
 *
 * This function deletes the element at the beginning of the array, shifting remaining
 * elements forward and reducing the size by one. No action if the array is empty.
 *
 * @param array Pointer to the array.
 */
void fossil_array_pop_front(fossil_array_t* array);

/**
 * Removes the element at the specified index in the array.
 *
 * This function deletes the element at the given index, shifting subsequent elements
 * backward and reducing the size by one. No action if index is out of bounds.
 *
 * @param array Pointer to the array.
 * @param index The index of the element to remove.
 */
void fossil_array_pop_at(fossil_array_t* array, size_t index);

/**
 * Removes all elements from the array, leaving it empty.
 *
 * This function clears the array, freeing all element strings and resetting its size to zero.
 * The array remains valid for further use.
 *
 * @param array Pointer to the array.
 */
void fossil_array_erase(fossil_array_t* array);

/**
 * Checks if the array pointer is NULL.
 *
 * This function returns true if the provided array pointer is NULL, indicating
 * an invalid or uninitialized array.
 *
 * @param array Pointer to the array.
 * @return      true if the array is NULL, false otherwise.
 */
bool fossil_array_is_cnullptr(const fossil_array_t* array);

/**
 * Checks if the array pointer is not NULL.
 *
 * This function returns true if the provided array pointer is not NULL,
 * indicating a valid array structure.
 *
 * @param array Pointer to the array.
 * @return      true if the array is not NULL, false otherwise.
 */
bool fossil_array_not_cnullptr(const fossil_array_t* array);

/**
 * Checks if the array is empty (contains no elements).
 *
 * This function returns true if the array's size is zero.
 *
 * @param array Pointer to the array.
 * @return      true if the array is empty, false otherwise.
 */
bool fossil_array_is_empty(const fossil_array_t* array);

/**
 * Checks if the array is not empty (contains at least one element).
 *
 * This function returns true if the array's size is greater than zero.
 *
 * @param array Pointer to the array.
 * @return      true if the array is not empty, false otherwise.
 */
bool fossil_array_not_empty(const fossil_array_t* array);

/**
 * Gets the number of elements currently stored in the array.
 *
 * This function returns the current size (number of elements) of the array.
 *
 * @param array Pointer to the array.
 * @return      The size of the array.
 */
size_t fossil_array_size(const fossil_array_t* array);

/**
 * Gets the current capacity of the array (maximum number of elements before resizing).
 *
 * This function returns the total capacity of the array, which may be greater than its size.
 *
 * @param array Pointer to the array.
 * @return      The capacity of the array.
 */
size_t fossil_array_capacity(const fossil_array_t* array);

/**
 * Retrieves the element at the specified index in the array.
 *
 * This function returns a pointer to the element string at the given index,
 * or NULL if the index is out of bounds.
 *
 * @param array Pointer to the array.
 * @param index The index of the element to retrieve.
 * @return      Pointer to the element string, or NULL if out of bounds.
 */
char *fossil_array_get(const fossil_array_t* array, size_t index);

/**
 * Retrieves the first element in the array.
 *
 * This function returns a pointer to the first element string, or NULL if the array is empty.
 *
 * @param array Pointer to the array.
 * @return      Pointer to the first element string, or NULL if the array is empty.
 */
char *fossil_array_get_front(const fossil_array_t* array);

/**
 * Retrieves the last element in the array.
 *
 * This function returns a pointer to the last element string, or NULL if the array is empty.
 *
 * @param array Pointer to the array.
 * @return      Pointer to the last element string, or NULL if the array is empty.
 */
char *fossil_array_get_back(const fossil_array_t* array);

/**
 * Retrieves the element at the specified index in the array.
 *
 * This function returns a pointer to the element string at the given index,
 * or NULL if the index is out of bounds.
 *
 * @param array Pointer to the array.
 * @param index The index of the element to retrieve.
 * @return      Pointer to the element string, or NULL if out of bounds.
 */
char *fossil_array_get_at(const fossil_array_t* array, size_t index);

/**
 * Sets the element at the specified index in the array.
 *
 * This function replaces the element at the given index with the provided string.
 * If the index is out of bounds, no action is taken.
 *
 * @param array   Pointer to the array.
 * @param index   The index at which to set the element.
 * @param element The new element value (as a string).
 */
void fossil_array_set(fossil_array_t* array, size_t index, char *element);

/**
 * Sets the first element in the array.
 *
 * This function replaces the first element in the array with the provided string.
 * If the array is empty, no action is taken.
 *
 * @param array   Pointer to the array.
 * @param element The new element value (as a string).
 */
void fossil_array_set_front(fossil_array_t* array, char *element);

/**
 * Sets the last element in the array.
 *
 * This function replaces the last element in the array with the provided string.
 * If the array is empty, no action is taken.
 *
 * @param array   Pointer to the array.
 * @param element The new element value (as a string).
 */
void fossil_array_set_back(fossil_array_t* array, char *element);

/**
 * Sets the element at the specified index in the array.
 *
 * This function replaces the element at the given index with the provided string.
 * If the index is out of bounds, no action is taken.
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
         *
         * This class encapsulates the C array structure and exposes methods for
         * manipulating the array using C++ idioms. It handles resource management,
         * including allocation and deallocation, and provides exception safety.
         */
        class Array {
        public:
            /**
             * Default constructor.
             *
             * Creates a new array with default values by calling the underlying
             * fossil_array_create_default function. If the array creation fails,
             * a std::runtime_error is thrown to indicate the error.
             */
            Array() : array(fossil_array_create_default()) {
                if (fossil_array_is_cnullptr(array)) {
                    throw std::runtime_error("Failed to create array");
                }
            }

            /**
             * Constructor with type specification.
             *
             * Creates a new array with the specified type by calling
             * fossil_array_create_container. The type parameter is passed as a string.
             * Throws std::runtime_error if the array creation fails.
             *
             * @param type The expected type of elements in the array.
             */
            Array(const std::string& type) : array(fossil_array_create_container(const_cast<char*>(type.c_str()))) {
                if (fossil_array_is_cnullptr(array)) {
                    throw std::runtime_error("Failed to create array");
                }
            }

            /**
             * Copy constructor.
             *
             * Creates a new array by copying the contents of another Array instance.
             * Calls fossil_array_create_copy to perform a deep copy. Throws
             * std::runtime_error if the copy fails.
             *
             * @param other The Array instance to copy.
             */
            Array(const Array& other) : array(fossil_array_create_copy(other.array)) {
                if (fossil_array_is_cnullptr(array)) {
                    throw std::runtime_error("Failed to create array");
                }
            }

            /**
             * Move constructor.
             *
             * Transfers ownership of the array from another Array instance by calling
             * fossil_array_create_move. The source array pointer is set to nullptr
             * to prevent double-free. This constructor does not throw exceptions.
             *
             * @param other The Array instance to move from.
             */
            Array(Array&& other) noexcept : array(fossil_array_create_move(other.array)) {
                other.array = nullptr;
            }

            /**
             * Destructor.
             *
             * Destroys the array and frees all allocated memory by calling
             * fossil_array_destroy. Ensures proper resource cleanup.
             */
            ~Array() {
                if (array) {
                    fossil_array_destroy(array);
                }
            }

            /**
             * Adds an element to the end of the array.
             *
             * Appends the provided string element to the array by calling
             * fossil_array_push_back. The element is converted to a C string.
             *
             * @param element The element to add.
             */
            void push_back(const std::string& element) {
                fossil_array_push_back(array, const_cast<char*>(element.c_str()));
            }

            /**
             * Adds an element to the front of the array.
             *
             * Inserts the provided string element at the beginning of the array by
             * calling fossil_array_push_front.
             *
             * @param element The element to add.
             */
            void push_front(const std::string& element) {
                fossil_array_push_front(array, const_cast<char*>(element.c_str()));
            }

            /**
             * Adds an element at the specified index in the array.
             *
             * Inserts the provided string element at the given index by calling
             * fossil_array_push_at.
             *
             * @param index   The index at which to add the element.
             * @param element The element to add.
             */
            void push_at(size_t index, const std::string& element) {
                fossil_array_push_at(array, index, const_cast<char*>(element.c_str()));
            }

            /**
             * Removes the last element from the array.
             *
             * Calls fossil_array_pop_back to delete the element at the end of the array.
             */
            void pop_back() {
                fossil_array_pop_back(array);
            }

            /**
             * Removes the first element from the array.
             *
             * Calls fossil_array_pop_front to delete the element at the beginning of the array.
             */
            void pop_front() {
                fossil_array_pop_front(array);
            }

            /**
             * Removes the element at the specified index in the array.
             *
             * Calls fossil_array_pop_at to delete the element at the given index.
             *
             * @param index The index at which to remove the element.
             */
            void pop_at(size_t index) {
                fossil_array_pop_at(array, index);
            }

            /**
             * Removes all elements from the array.
             *
             * Calls fossil_array_erase to clear the array and reset its size to zero.
             */
            void erase() {
                fossil_array_erase(array);
            }

            /**
             * Checks if the array is empty.
             *
             * Returns true if the array contains no elements by calling
             * fossil_array_is_empty.
             *
             * @return True if the array is empty, false otherwise.
             */
            bool is_empty() const {
                return fossil_array_is_empty(array);
            }

            /**
             * Gets the size of the array.
             *
             * Returns the number of elements currently stored in the array by calling
             * fossil_array_size.
             *
             * @return The size of the array.
             */
            size_t size() const {
                return fossil_array_size(array);
            }

            /**
             * Gets the capacity of the array.
             *
             * Returns the maximum number of elements the array can hold before resizing
             * by calling fossil_array_capacity.
             *
             * @return The capacity of the array.
             */
            size_t capacity() const {
                return fossil_array_capacity(array);
            }

            /**
             * Gets the element at the specified index in the array.
             *
             * Returns the element string at the given index by calling fossil_array_get.
             * If the index is out of bounds, returns an empty string.
             *
             * @param index The index of the element to get.
             * @return      The element at the specified index.
             */
            std::string get(size_t index) const {
                char* result = fossil_array_get(array, index);
                return result ? std::string(result) : std::string();
            }

            /**
             * Gets the first element in the array.
             *
             * Returns the first element string by calling fossil_array_get_front.
             * If the array is empty, returns an empty string.
             *
             * @return The first element in the array.
             */
            std::string get_front() const {
                char* result = fossil_array_get_front(array);
                return result ? std::string(result) : std::string();
            }

            /**
             * Gets the last element in the array.
             *
             * Returns the last element string by calling fossil_array_get_back.
             * If the array is empty, returns an empty string.
             *
             * @return The last element in the array.
             */
            std::string get_back() const {
                char* result = fossil_array_get_back(array);
                return result ? std::string(result) : std::string();
            }

            /**
             * Gets the element at the specified index in the array.
             *
             * Returns the element string at the given index by calling fossil_array_get_at.
             * If the index is out of bounds, returns an empty string.
             *
             * @param index The index of the element to get.
             * @return      The element at the specified index.
             */
            std::string get_at(size_t index) const {
                char* result = fossil_array_get_at(array, index);
                return result ? std::string(result) : std::string();
            }

            /**
             * Sets the element at the specified index in the array.
             *
             * Replaces the element at the given index with the provided string by
             * calling fossil_array_set. No action if the index is out of bounds.
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
             * Replaces the first element with the provided string by calling
             * fossil_array_set_front. No action if the array is empty.
             *
             * @param element The element to set.
             */
            void set_front(const std::string& element) {
                fossil_array_set_front(array, const_cast<char*>(element.c_str()));
            }

            /**
             * Sets the last element in the array.
             *
             * Replaces the last element with the provided string by calling
             * fossil_array_set_back. No action if the array is empty.
             *
             * @param element The element to set.
             */
            void set_back(const std::string& element) {
                fossil_array_set_back(array, const_cast<char*>(element.c_str()));
            }

            /**
             * Sets the element at the specified index in the array.
             *
             * Replaces the element at the given index with the provided string by
             * calling fossil_array_set_at. No action if the index is out of bounds.
             *
             * @param index   The index at which to set the element.
             * @param element The element to set.
             */
            void set_at(size_t index, const std::string& element) {
                fossil_array_set_at(array, index, const_cast<char*>(element.c_str()));
            }

        private:
            /**
             * Pointer to the underlying fossil_array_t structure.
             *
             * This member holds the C array structure managed by the class.
             * All operations are delegated to the corresponding C functions.
             */
            fossil_array_t* array;
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
