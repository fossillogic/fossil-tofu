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
#ifndef FOSSIL_TOFU_DOUBLYLIST_H
#define FOSSIL_TOFU_DOUBLYLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the doubly linked list
typedef struct fossil_dlist_node_t {
    fossil_tofu_t data;
    struct fossil_dlist_node_t* prev;
    struct fossil_dlist_node_t* next;
} fossil_dlist_node_t;

// Doubly linked list structure
typedef struct fossil_dlist_t {
    fossil_dlist_node_t* head;
    fossil_dlist_node_t* tail;
    char* type;
} fossil_dlist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new doubly linked list with the specified data type.
 *
 * @param list_type The type of data the doubly linked list will store.
 * @return          The created doubly linked list.
 * @note            Time complexity: O(1)
 */
fossil_dlist_t* fossil_dlist_create_container(char* type);

/**
 * Create a new doubly linked list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created doubly linked list.
 */
fossil_dlist_t* fossil_dlist_create_default(void);

/**
 * Create a new doubly linked list by copying an existing list.
 * 
 * Time complexity: O(n)
 *
 * @param other The doubly linked list to copy.
 * @return      The created doubly linked list.
 */
fossil_dlist_t* fossil_dlist_create_copy(const fossil_dlist_t* other);

/**
 * Create a new doubly linked list by moving an existing list.
 * 
 * Time complexity: O(1)
 *
 * @param other The doubly linked list to move.
 * @return      The created doubly linked list.
 */
fossil_dlist_t* fossil_dlist_create_move(fossil_dlist_t* other);

/**
 * Erase the contents of the doubly linked list and fossil_tofu_free allocated memory.
 *
 * @param dlist The doubly linked list to erase.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_destroy(fossil_dlist_t* dlist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the doubly linked list.
 *
 * @param dlist The doubly linked list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_dlist_insert(fossil_dlist_t* dlist, char *data);

/**
 * Remove data from the doubly linked list.
 *
 * @param dlist The doubly linked list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_dlist_remove(fossil_dlist_t* dlist);

/**
 * Reverse the doubly linked list in the forward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_reverse_forward(fossil_dlist_t* dlist);

/**
 * Reverse the doubly linked list in the backward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_reverse_backward(fossil_dlist_t* dlist);

/**
 * Get the size of the doubly linked list.
 *
 * @param dlist The doubly linked list for which to get the size.
 * @return      The size of the doubly linked list.
 * @note        Time complexity: O(n)
 */
size_t fossil_dlist_size(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is not empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_not_empty(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is not a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_is_empty(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the doubly linked list.
 * 
 * Time complexity: O(n)
 *
 * @param dlist The doubly linked list from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_dlist_get(const fossil_dlist_t* dlist, size_t index);

/**
 * Get the first element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist The doubly linked list from which to get the first element.
 * @return      The first element in the doubly linked list.
 */
char *fossil_dlist_get_front(const fossil_dlist_t* dlist);

/**
 * Get the last element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist The doubly linked list from which to get the last element.
 * @return      The last element in the doubly linked list.
 */
char *fossil_dlist_get_back(const fossil_dlist_t* dlist);

/**
 * Set the element at the specified index in the doubly linked list.
 * 
 * Time complexity: O(n)
 *
 * @param dlist   The doubly linked list in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_dlist_set(fossil_dlist_t* dlist, size_t index, char *element);

/**
 * Set the first element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist   The doubly linked list in which to set the first element.
 * @param element The element to set.
 */
void fossil_dlist_set_front(fossil_dlist_t* dlist, char *element);

/**
 * Set the last element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist   The doubly linked list in which to set the last element.
 * @param element The element to set.
 */
void fossil_dlist_set_back(fossil_dlist_t* dlist, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

namespace tofu {

    class DList {
    public:
        /**
         * Constructor to create a doubly linked list with a specified type.
         *
         * @param type The type of data the doubly linked list will store.
         * @throws std::runtime_error If the list creation fails.
         */
        DList(std::string type) : dlist(fossil_dlist_create_container(const_cast<char*>(type.c_str()))) {
            if (dlist == nullptr) {
                throw std::runtime_error("Failed to create doubly linked list.");
            }
        }

        /**
         * Default constructor to create a doubly linked list with default values.
         *
         * @throws std::runtime_error If the list creation fails.
         */
        DList() : dlist(fossil_dlist_create_default()) {
            if (dlist == nullptr) {
                throw std::runtime_error("Failed to create doubly linked list.");
            }
        }

        /**
         * Copy constructor to create a new doubly linked list by copying another list.
         *
         * @param other The doubly linked list to copy.
         * @throws std::runtime_error If the list creation fails.
         */
        DList(const DList& other) : dlist(fossil_dlist_create_copy(other.dlist)) {
            if (dlist == nullptr) {
                throw std::runtime_error("Failed to create doubly linked list.");
            }
        }

        /**
         * Move constructor to create a new doubly linked list by moving another list.
         *
         * @param other The doubly linked list to move.
         * @throws std::runtime_error If the list creation fails.
         */
        DList(DList&& other) : dlist(fossil_dlist_create_move(other.dlist)) {
            if (dlist == nullptr) {
            throw std::runtime_error("Failed to create doubly linked list.");
            }
        }

        /**
         * Destructor to destroy the doubly linked list and free allocated memory.
         */
        ~DList() {
            fossil_dlist_destroy(dlist);
        }

        /**
         * Insert data into the doubly linked list.
         *
         * @param data The data to insert.
         * @return     The error code indicating the success or failure of the operation.
         */
        int32_t insert(const std::string& data) {
            return fossil_dlist_insert(dlist, const_cast<char*>(data.c_str()));
        }

        /**
         * Remove data from the doubly linked list.
         *
         * @return The error code indicating the success or failure of the operation.
         */
        int32_t remove() {
            return fossil_dlist_remove(dlist);
        }

        /**
         * Reverse the doubly linked list in the forward direction.
         */
        void reverse_forward() {
            fossil_dlist_reverse_forward(dlist);
        }

        /**
         * Reverse the doubly linked list in the backward direction.
         */
        void reverse_backward() {
            fossil_dlist_reverse_backward(dlist);
        }

        /**
         * Get the size of the doubly linked list.
         *
         * @return The size of the doubly linked list.
         */
        size_t size() const {
            return fossil_dlist_size(dlist);
        }

        /**
         * Check if the doubly linked list is not empty.
         *
         * @return True if the doubly linked list is not empty, false otherwise.
         */
        bool not_empty() const {
            return fossil_dlist_not_empty(dlist);
        }

        /**
         * Check if the doubly linked list is not a null pointer.
         *
         * @return True if the doubly linked list is not a null pointer, false otherwise.
         */
        bool not_cnullptr() const {
            return fossil_dlist_not_cnullptr(dlist);
        }

        /**
         * Check if the doubly linked list is empty.
         *
         * @return True if the doubly linked list is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_dlist_is_empty(dlist);
        }

        /**
         * Check if the doubly linked list is a null pointer.
         *
         * @return True if the doubly linked list is a null pointer, false otherwise.
         */
        bool is_cnullptr() const {
            return fossil_dlist_is_cnullptr(dlist);
        }

        /**
         * Get the element at the specified index in the doubly linked list.
         *
         * @param index The index of the element to get.
         * @return      The element at the specified index as std::string.
         */
        std::string get(size_t index) const {
            char* result = fossil_dlist_get(dlist, index);
            return result ? std::string(result) : std::string();
        }

        /**
         * Get the first element in the doubly linked list.
         *
         * @return The first element in the doubly linked list as std::string.
         */
        std::string get_front() const {
            char* result = fossil_dlist_get_front(dlist);
            return result ? std::string(result) : std::string();
        }

        /**
         * Get the last element in the doubly linked list.
         *
         * @return The last element in the doubly linked list as std::string.
         */
        std::string get_back() const {
            char* result = fossil_dlist_get_back(dlist);
            return result ? std::string(result) : std::string();
        }

        /**
         * Set the element at the specified index in the doubly linked list.
         *
         * @param index   The index at which to set the element.
         * @param element The element to set as std::string.
         */
        void set(size_t index, const std::string& element) {
            fossil_dlist_set(dlist, index, const_cast<char*>(element.c_str()));
        }

        /**
         * Set the first element in the doubly linked list.
         *
         * @param element The element to set as std::string.
         */
        void set_front(const std::string& element) {
            fossil_dlist_set_front(dlist, const_cast<char*>(element.c_str()));
        }

        /**
         * Set the last element in the doubly linked list.
         *
         * @param element The element to set as std::string.
         */
        void set_back(const std::string& element) {
            fossil_dlist_set_back(dlist, const_cast<char*>(element.c_str()));
        }

    private:
        fossil_dlist_t* dlist;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
