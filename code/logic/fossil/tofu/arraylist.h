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
typedef struct fossil_arraylist_node_t {
    fossil_tofu_t data;
} fossil_arraylist_node_t;

// Array list structure
typedef struct fossil_arraylist_t {
    fossil_arraylist_node_t* items;
    size_t capacity;
    size_t size;
    char* type;
} fossil_arraylist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new array list with the specified data type and initial capacity.
 *
 * @param type     The type of data the array list will store.
 * @param capacity The initial capacity of the array list.
 * @return         The created array list.
 * @complexity     O(1)
 */
fossil_arraylist_t* fossil_arraylist_create_container(char* type, size_t capacity);

/**
 * Create a new array list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created array list.
 */
fossil_arraylist_t* fossil_arraylist_create_default(void);

/**
 * Create a new array list by copying an existing array list.
 * 
 * Time complexity: O(n)
 *
 * @param other The array list to copy.
 * @return      The created array list.
 */
fossil_arraylist_t* fossil_arraylist_create_copy(const fossil_arraylist_t* other);

/**
 * Create a new array list by moving an existing array list.
 * 
 * Time complexity: O(1)
 *
 * @param other The array list to move.
 * @return      The created array list.
 */
fossil_arraylist_t* fossil_arraylist_create_move(fossil_arraylist_t* other);

/**
 * Erase the contents of the array list and free allocated memory.
 *
 * @param alist The array list to erase.
 * @complexity  O(1)
 */
void fossil_arraylist_destroy(fossil_arraylist_t* alist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the array list.
 *
 * @param alist The array list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  Amortized O(1)
 */
int32_t fossil_arraylist_insert(fossil_arraylist_t* alist, char *data);

/**
 * Remove data from the array list at the specified index.
 *
 * @param alist The array list to remove data from.
 * @param index The index of the element to remove.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(n)
 */
int32_t fossil_arraylist_remove(fossil_arraylist_t* alist, size_t index);

/**
 * Get the size of the array list.
 *
 * @param alist The array list for which to get the size.
 * @return      The size of the array list.
 * @complexity  O(1)
 */
size_t fossil_arraylist_size(const fossil_arraylist_t* alist);

/**
 * Get the capacity of the array list.
 *
 * @param alist The array list for which to get the capacity.
 * @return      The capacity of the array list.
 * @complexity  O(1)
 */
size_t fossil_arraylist_capacity(const fossil_arraylist_t* alist);

/**
 * Check if the array list is not empty.
 *
 * @param alist The array list to check.
 * @return      True if the array list is not empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_arraylist_not_empty(const fossil_arraylist_t* alist);

/**
 * Check if the array list is not a null pointer.
 *
 * @param alist The array list to check.
 * @return      True if the array list is not a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_arraylist_not_cnullptr(const fossil_arraylist_t* alist);

/**
 * Check if the array list is empty.
 *
 * @param alist The array list to check.
 * @return      True if the array list is empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_arraylist_is_empty(const fossil_arraylist_t* alist);

/**
 * Check if the array list is a null pointer.
 *
 * @param alist The array list to check.
 * @return      True if the array list is a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_arraylist_is_cnullptr(const fossil_arraylist_t* alist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the array list.
 * 
 * Time complexity: O(1)
 *
 * @param alist The array list from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_arraylist_get(const fossil_arraylist_t* alist, size_t index);

/**
 * Get the first element in the array list.
 * 
 * Time complexity: O(1)
 *
 * @param alist The array list from which to get the first element.
 * @return      The first element in the array list.
 */
char *fossil_arraylist_get_front(const fossil_arraylist_t* alist);

/**
 * Get the last element in the array list.
 * 
 * Time complexity: O(1)
 *
 * @param alist The array list from which to get the last element.
 * @return      The last element in the array list.
 */
char *fossil_arraylist_get_back(const fossil_arraylist_t* alist);

/**
 * Set the element at the specified index in the array list.
 * 
 * Time complexity: O(1)
 *
 * @param alist   The array list in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_arraylist_set(fossil_arraylist_t* alist, size_t index, char *element);

/**
 * Set the first element in the array list.
 * 
 * Time complexity: O(1)
 *
 * @param alist   The array list in which to set the first element.
 * @param element The element to set.
 */
void fossil_arraylist_set_front(fossil_arraylist_t* alist, char *element);

/**
 * Set the last element in the array list.
 * 
 * Time complexity: O(1)
 *
 * @param alist   The array list in which to set the last element.
 * @param element The element to set.
 */
void fossil_arraylist_set_back(fossil_arraylist_t* alist, char *element);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {

namespace tofu {

    /**
     * @class ArrayList
     * @brief A C++ wrapper for the fossil_arraylist_t array list using std::string.
     */
    class ArrayList {
    public:
        /**
         * Constructor to create an array list with a specified data type and capacity.
         *
         * @param type     The type of data the array list will store.
         * @param capacity The initial capacity of the array list.
         */
        ArrayList(const std::string& type, size_t capacity) {
            alist = fossil_arraylist_create_container(const_cast<char*>(type.c_str()), capacity);
        }

        /**
         * Default constructor to create an array list with default values.
         */
        ArrayList() {
            alist = fossil_arraylist_create_default();
        }

        /**
         * Copy constructor to create an array list by copying another array list.
         *
         * @param other The array list to copy.
         */
        ArrayList(const ArrayList& other) {
            alist = fossil_arraylist_create_copy(other.alist);
        }

        /**
         * Move constructor to create an array list by moving another array list.
         *
         * @param other The array list to move.
         */
        ArrayList(ArrayList&& other) noexcept {
            alist = fossil_arraylist_create_move(other.alist);
            other.alist = nullptr;
        }

        /**
         * Destructor to destroy the array list and free allocated memory.
         */
        ~ArrayList() {
            fossil_arraylist_destroy(alist);
        }

        /**
         * Insert data into the array list.
         *
         * @param data The data to insert.
         */
        void insert(const std::string& data) {
            fossil_arraylist_insert(alist, const_cast<char*>(data.c_str()));
        }

        /**
         * Remove data from the array list at the specified index.
         *
         * @param index The index of the element to remove.
         */
        void remove(size_t index) {
            fossil_arraylist_remove(alist, index);
        }

        /**
         * Get the size of the array list.
         *
         * @return The size of the array list.
         */
        size_t size() const {
            return fossil_arraylist_size(alist);
        }

        /**
         * Get the capacity of the array list.
         *
         * @return The capacity of the array list.
         */
        size_t capacity() const {
            return fossil_arraylist_capacity(alist);
        }

        /**
         * Check if the array list is not empty.
         *
         * @return True if the array list is not empty, false otherwise.
         */
        bool not_empty() const {
            return fossil_arraylist_not_empty(alist);
        }

        /**
         * Check if the array list is not a null pointer.
         *
         * @return True if the array list is not a null pointer, false otherwise.
         */
        bool not_cnullptr() const {
            return fossil_arraylist_not_cnullptr(alist);
        }

        /**
         * Check if the array list is empty.
         *
         * @return True if the array list is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_arraylist_is_empty(alist);
        }

        /**
         * Check if the array list is a null pointer.
         *
         * @return True if the array list is a null pointer, false otherwise.
         */
        bool is_cnullptr() const {
            return fossil_arraylist_is_cnullptr(alist);
        }

        /**
         * Get the element at the specified index in the array list.
         *
         * @param index The index of the element to get.
         * @return      The element at the specified index as a string.
         */
        std::string get(size_t index) const {
            const char* elem = fossil_arraylist_get(alist, index);
            return elem ? std::string(elem) : "";
        }

        /**
         * Get the first element in the array list.
         *
         * @return The first element in the array list as a string.
         */
        std::string front() const {
            const char* elem = fossil_arraylist_get_front(alist);
            return elem ? std::string(elem) : "";
        }

        /**
         * Get the last element in the array list.
         *
         * @return The last element in the array list as a string.
         */
        std::string back() const {
            const char* elem = fossil_arraylist_get_back(alist);
            return elem ? std::string(elem) : "";
        }

        /**
         * Set the element at the specified index in the array list.
         *
         * @param index The index at which to set the element.
         * @param value The element to set.
         */
        void set(size_t index, const std::string& value) {
            fossil_arraylist_set(alist, index, const_cast<char*>(value.c_str()));
        }

        /**
         * Set the first element in the array list.
         *
         * @param value The element to set.
         */
        void set_front(const std::string& value) {
            fossil_arraylist_set_front(alist, const_cast<char*>(value.c_str()));
        }

        /**
         * Set the last element in the array list.
         *
         * @param value The element to set.
         */
        void set_back(const std::string& value) {
            fossil_arraylist_set_back(alist, const_cast<char*>(value.c_str()));
        }

        /**
         * Copy assignment operator.
         */
        ArrayList& operator=(const ArrayList& other) {
            if (this != &other) {
                fossil_arraylist_destroy(alist);
                alist = fossil_arraylist_create_copy(other.alist);
            }
            return *this;
        }

        /**
         * Move assignment operator.
         */
        ArrayList& operator=(ArrayList&& other) noexcept {
            if (this != &other) {
                fossil_arraylist_destroy(alist);
                alist = other.alist;
                other.alist = nullptr;
            }
            return *this;
        }

        /**
         * Get raw pointer to underlying fossil_arraylist_t.
         */
        fossil_arraylist_t* raw() { return alist; }

        /**
         * Get const raw pointer to underlying fossil_arraylist_t.
         */
        const fossil_arraylist_t* raw() const { return alist; }

    private:
        fossil_arraylist_t* alist = nullptr;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
