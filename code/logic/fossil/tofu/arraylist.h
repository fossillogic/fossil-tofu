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
#ifndef FOSSIL_TOFU_ARRAYLIST_H
#define FOSSIL_TOFU_ARRAYLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the array list
typedef struct fossil_tofu_arraylist_node_t {
    fossil_tofu_t data;
} fossil_tofu_arraylist_node_t;

// Array list structure
typedef struct fossil_tofu_arraylist_t {
    fossil_tofu_arraylist_node_t* items;
    size_t capacity;
    size_t size;
    char* type;
} fossil_tofu_arraylist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * @brief Create a new array list with the specified data type and initial capacity.
 *
 * This function allocates and initializes a new array list container that can store
 * elements of the specified type. The initial capacity determines how many elements
 * the array list can hold before needing to resize.
 *
 * @param type     The type of data the array list will store (as a string).
 * @param capacity The initial capacity of the array list.
 * @return         Pointer to the created array list, or NULL on failure.
 * @complexity     O(1)
 */
fossil_tofu_arraylist_t* fossil_tofu_arraylist_create_container(char* type, size_t capacity);

/**
 * @brief Create a new array list with default values.
 *
 * This function creates an array list with default type and capacity settings.
 * It is useful for cases where the user does not need to specify custom parameters.
 *
 * @return Pointer to the created array list, or NULL on failure.
 * @complexity O(1)
 */
fossil_tofu_arraylist_t* fossil_tofu_arraylist_create_default(void);

/**
 * @brief Create a new array list by copying an existing array list.
 *
 * This function performs a deep copy of the provided array list, duplicating all
 * elements and internal state. The new array list is independent of the original.
 *
 * @param other Pointer to the array list to copy.
 * @return      Pointer to the newly created copy, or NULL on failure.
 * @complexity  O(n)
 */
fossil_tofu_arraylist_t* fossil_tofu_arraylist_create_copy(const fossil_tofu_arraylist_t* other);

/**
 * @brief Create a new array list by moving an existing array list.
 *
 * This function transfers ownership of the internal data from the source array list
 * to the new array list, leaving the source in an invalid or empty state.
 *
 * @param other Pointer to the array list to move.
 * @return      Pointer to the newly created array list, or NULL on failure.
 * @complexity  O(1)
 */
fossil_tofu_arraylist_t* fossil_tofu_arraylist_create_move(fossil_tofu_arraylist_t* other);

/**
 * @brief Erase the contents of the array list and free allocated memory.
 *
 * This function releases all resources associated with the array list, including
 * its elements and internal buffers. After calling this, the array list pointer
 * should not be used.
 *
 * @param alist Pointer to the array list to destroy.
 * @complexity  O(1)
 */
void fossil_tofu_arraylist_destroy(fossil_tofu_arraylist_t* alist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * @brief Insert data into the array list.
 *
 * Adds a new element to the end of the array list. If the array list is full,
 * it will automatically resize to accommodate the new element.
 *
 * @param alist Pointer to the array list to insert data into.
 * @param data  Pointer to the data to insert (as a string).
 * @return      Error code indicating success (0) or failure (non-zero).
 * @complexity  Amortized O(1)
 */
int32_t fossil_tofu_arraylist_insert(fossil_tofu_arraylist_t* alist, char *data);

/**
 * @brief Remove data from the array list at the specified index.
 *
 * Deletes the element at the given index, shifting subsequent elements to fill
 * the gap. The array list size is reduced by one.
 *
 * @param alist Pointer to the array list to remove data from.
 * @param index Index of the element to remove (0-based).
 * @return      Error code indicating success (0) or failure (non-zero).
 * @complexity  O(n)
 */
int32_t fossil_tofu_arraylist_remove(fossil_tofu_arraylist_t* alist, size_t index);

/**
 * @brief Get the size of the array list.
 *
 * Returns the current number of elements stored in the array list.
 *
 * @param alist Pointer to the array list.
 * @return      Number of elements in the array list.
 * @complexity  O(1)
 */
size_t fossil_tofu_arraylist_size(const fossil_tofu_arraylist_t* alist);

/**
 * @brief Get the capacity of the array list.
 *
 * Returns the total number of elements the array list can hold before resizing.
 *
 * @param alist Pointer to the array list.
 * @return      Capacity of the array list.
 * @complexity  O(1)
 */
size_t fossil_tofu_arraylist_capacity(const fossil_tofu_arraylist_t* alist);

/**
 * @brief Check if the array list is not empty.
 *
 * Returns true if the array list contains at least one element.
 *
 * @param alist Pointer to the array list.
 * @return      True if not empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_tofu_arraylist_not_empty(const fossil_tofu_arraylist_t* alist);

/**
 * @brief Check if the array list is not a null pointer.
 *
 * Returns true if the array list pointer is valid (not NULL).
 *
 * @param alist Pointer to the array list.
 * @return      True if not NULL, false otherwise.
 * @complexity  O(1)
 */
bool fossil_tofu_arraylist_not_cnullptr(const fossil_tofu_arraylist_t* alist);

/**
 * @brief Check if the array list is empty.
 *
 * Returns true if the array list contains no elements.
 *
 * @param alist Pointer to the array list.
 * @return      True if empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_tofu_arraylist_is_empty(const fossil_tofu_arraylist_t* alist);

/**
 * @brief Check if the array list is a null pointer.
 *
 * Returns true if the array list pointer is NULL.
 *
 * @param alist Pointer to the array list.
 * @return      True if NULL, false otherwise.
 * @complexity  O(1)
 */
bool fossil_tofu_arraylist_is_cnullptr(const fossil_tofu_arraylist_t* alist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * @brief Get the element at the specified index in the array list.
 *
 * Retrieves the element stored at the given index. The returned pointer is valid
 * as long as the array list is not modified.
 *
 * @param alist Pointer to the array list.
 * @param index Index of the element to retrieve (0-based).
 * @return      Pointer to the element, or NULL if index is out of bounds.
 * @complexity  O(1)
 */
char *fossil_tofu_arraylist_get(const fossil_tofu_arraylist_t* alist, size_t index);

/**
 * @brief Get the first element in the array list.
 *
 * Returns a pointer to the first element in the array list.
 *
 * @param alist Pointer to the array list.
 * @return      Pointer to the first element, or NULL if the list is empty.
 * @complexity  O(1)
 */
char *fossil_tofu_arraylist_get_front(const fossil_tofu_arraylist_t* alist);

/**
 * @brief Get the last element in the array list.
 *
 * Returns a pointer to the last element in the array list.
 *
 * @param alist Pointer to the array list.
 * @return      Pointer to the last element, or NULL if the list is empty.
 * @complexity  O(1)
 */
char *fossil_tofu_arraylist_get_back(const fossil_tofu_arraylist_t* alist);

/**
 * @brief Set the element at the specified index in the array list.
 *
 * Updates the element at the given index with the provided value.
 *
 * @param alist   Pointer to the array list.
 * @param index   Index at which to set the element (0-based).
 * @param element Pointer to the new element value.
 * @complexity    O(1)
 */
void fossil_tofu_arraylist_set(fossil_tofu_arraylist_t* alist, size_t index, char *element);

/**
 * @brief Set the first element in the array list.
 *
 * Updates the first element in the array list with the provided value.
 *
 * @param alist   Pointer to the array list.
 * @param element Pointer to the new value for the first element.
 * @complexity    O(1)
 */
void fossil_tofu_arraylist_set_front(fossil_tofu_arraylist_t* alist, char *element);

/**
 * @brief Set the last element in the array list.
 *
 * Updates the last element in the array list with the provided value.
 *
 * @param alist   Pointer to the array list.
 * @param element Pointer to the new value for the last element.
 * @complexity    O(1)
 */
void fossil_tofu_arraylist_set_back(fossil_tofu_arraylist_t* alist, char *element);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {

    namespace tofu {

        /**
         * @class ArrayList
         * @brief A C++ wrapper for the fossil_tofu_arraylist_t array list using std::string.
         *
         * This class provides a convenient C++ interface for managing a dynamic array list
         * of strings, backed by the C fossil_tofu_arraylist_t implementation. It supports
         * construction, destruction, copy/move semantics, and common container operations.
         */
        class ArrayList {
        public:
            /**
             * @brief Constructor to create an array list with a specified data type and capacity.
             *
             * Allocates and initializes a new array list container with the given type and
             * initial capacity. The type is passed as a string and capacity determines the
             * initial number of elements the list can hold before resizing.
             *
             * @param type     The type of data the array list will store.
             * @param capacity The initial capacity of the array list.
             */
            ArrayList(const std::string& type, size_t capacity) {
                alist = fossil_tofu_arraylist_create_container(const_cast<char*>(type.c_str()), capacity);
            }

            /**
             * @brief Default constructor to create an array list with default values.
             *
             * Initializes the array list with default type and capacity settings.
             */
            ArrayList() {
                alist = fossil_tofu_arraylist_create_default();
            }

            /**
             * @brief Copy constructor to create an array list by copying another array list.
             *
             * Performs a deep copy of the provided array list, duplicating all elements and
             * internal state. The new array list is independent of the original.
             *
             * @param other The array list to copy.
             */
            ArrayList(const ArrayList& other) {
                alist = fossil_tofu_arraylist_create_copy(other.alist);
            }

            /**
             * @brief Move constructor to create an array list by moving another array list.
             *
             * Transfers ownership of the internal data from the source array list to this
             * instance, leaving the source in an invalid or empty state.
             *
             * @param other The array list to move.
             */
            ArrayList(ArrayList&& other) noexcept {
                alist = fossil_tofu_arraylist_create_move(other.alist);
                other.alist = nullptr;
            }

            /**
             * @brief Destructor to destroy the array list and free allocated memory.
             *
             * Releases all resources associated with the array list, including its elements
             * and internal buffers.
             */
            ~ArrayList() {
                fossil_tofu_arraylist_destroy(alist);
            }

            /**
             * @brief Insert data into the array list.
             *
             * Adds a new element to the end of the array list. If the array list is full,
             * it will automatically resize to accommodate the new element.
             *
             * @param data The data to insert.
             */
            void insert(const std::string& data) {
                fossil_tofu_arraylist_insert(alist, const_cast<char*>(data.c_str()));
            }

            /**
             * @brief Remove data from the array list at the specified index.
             *
             * Deletes the element at the given index, shifting subsequent elements to fill
             * the gap. The array list size is reduced by one.
             *
             * @param index The index of the element to remove.
             */
            void remove(size_t index) {
                fossil_tofu_arraylist_remove(alist, index);
            }

            /**
             * @brief Get the size of the array list.
             *
             * Returns the current number of elements stored in the array list.
             *
             * @return The size of the array list.
             */
            size_t size() const {
                return fossil_tofu_arraylist_size(alist);
            }

            /**
             * @brief Get the capacity of the array list.
             *
             * Returns the total number of elements the array list can hold before resizing.
             *
             * @return The capacity of the array list.
             */
            size_t capacity() const {
                return fossil_tofu_arraylist_capacity(alist);
            }

            /**
             * @brief Check if the array list is not empty.
             *
             * Returns true if the array list contains at least one element.
             *
             * @return True if the array list is not empty, false otherwise.
             */
            bool not_empty() const {
                return fossil_tofu_arraylist_not_empty(alist);
            }

            /**
             * @brief Check if the array list is not a null pointer.
             *
             * Returns true if the array list pointer is valid (not NULL).
             *
             * @return True if the array list is not a null pointer, false otherwise.
             */
            bool not_cnullptr() const {
                return fossil_tofu_arraylist_not_cnullptr(alist);
            }

            /**
             * @brief Check if the array list is empty.
             *
             * Returns true if the array list contains no elements.
             *
             * @return True if the array list is empty, false otherwise.
             */
            bool is_empty() const {
                return fossil_tofu_arraylist_is_empty(alist);
            }

            /**
             * @brief Check if the array list is a null pointer.
             *
             * Returns true if the array list pointer is NULL.
             *
             * @return True if the array list is a null pointer, false otherwise.
             */
            bool is_cnullptr() const {
                return fossil_tofu_arraylist_is_cnullptr(alist);
            }

            /**
             * @brief Get the element at the specified index in the array list.
             *
             * Retrieves the element stored at the given index. The returned string is empty
             * if the index is out of bounds or the element is NULL.
             *
             * @param index The index of the element to get.
             * @return      The element at the specified index as a string.
             */
            std::string get(size_t index) const {
                const char* elem = fossil_tofu_arraylist_get(alist, index);
                return elem ? std::string(elem) : "";
            }

            /**
             * @brief Get the first element in the array list.
             *
             * Returns a string containing the first element in the array list, or an empty
             * string if the list is empty.
             *
             * @return The first element in the array list as a string.
             */
            std::string front() const {
                const char* elem = fossil_tofu_arraylist_get_front(alist);
                return elem ? std::string(elem) : "";
            }

            /**
             * @brief Get the last element in the array list.
             *
             * Returns a string containing the last element in the array list, or an empty
             * string if the list is empty.
             *
             * @return The last element in the array list as a string.
             */
            std::string back() const {
                const char* elem = fossil_tofu_arraylist_get_back(alist);
                return elem ? std::string(elem) : "";
            }

            /**
             * @brief Set the element at the specified index in the array list.
             *
             * Updates the element at the given index with the provided value.
             *
             * @param index The index at which to set the element.
             * @param value The element to set.
             */
            void set(size_t index, const std::string& value) {
                fossil_tofu_arraylist_set(alist, index, const_cast<char*>(value.c_str()));
            }

            /**
             * @brief Set the first element in the array list.
             *
             * Updates the first element in the array list with the provided value.
             *
             * @param value The element to set.
             */
            void set_front(const std::string& value) {
                fossil_tofu_arraylist_set_front(alist, const_cast<char*>(value.c_str()));
            }

            /**
             * @brief Set the last element in the array list.
             *
             * Updates the last element in the array list with the provided value.
             *
             * @param value The element to set.
             */
            void set_back(const std::string& value) {
                fossil_tofu_arraylist_set_back(alist, const_cast<char*>(value.c_str()));
            }

            /**
             * @brief Copy assignment operator.
             *
             * Destroys the current array list and replaces it with a deep copy of the
             * provided array list.
             *
             * @param other The array list to copy.
             * @return Reference to this array list.
             */
            ArrayList& operator=(const ArrayList& other) {
                if (this != &other) {
                    fossil_tofu_arraylist_destroy(alist);
                    alist = fossil_tofu_arraylist_create_copy(other.alist);
                }
                return *this;
            }

            /**
             * @brief Move assignment operator.
             *
             * Destroys the current array list and replaces it by taking ownership of the
             * internal data from the provided array list, leaving the source empty.
             *
             * @param other The array list to move.
             * @return Reference to this array list.
             */
            ArrayList& operator=(ArrayList&& other) noexcept {
                if (this != &other) {
                    fossil_tofu_arraylist_destroy(alist);
                    alist = other.alist;
                    other.alist = nullptr;
                }
                return *this;
            }

            /**
             * @brief Get raw pointer to underlying fossil_tofu_arraylist_t.
             *
             * Returns a non-const pointer to the underlying C array list structure.
             *
             * @return fossil_tofu_arraylist_t* pointer.
             */
            fossil_tofu_arraylist_t* raw() { return alist; }

            /**
             * @brief Get const raw pointer to underlying fossil_tofu_arraylist_t.
             *
             * Returns a const pointer to the underlying C array list structure.
             *
             * @return const fossil_tofu_arraylist_t* pointer.
             */
            const fossil_tofu_arraylist_t* raw() const { return alist; }

        private:
            /**
             * @brief Pointer to the underlying fossil_tofu_arraylist_t structure.
             *
             * This member holds the actual C array list instance managed by this wrapper.
             */
            fossil_tofu_arraylist_t* alist = nullptr;
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
