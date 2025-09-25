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
#ifndef FOSSIL_TOFU_CIRCALIRLIST_H
#define FOSSIL_TOFU_CIRCALIRLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the circular doubly linked list
typedef struct fossil_clist_node_t {
    fossil_tofu_t data;
    struct fossil_clist_node_t* prev;
    struct fossil_clist_node_t* next;
} fossil_clist_node_t;

// Circular doubly linked list structure
typedef struct fossil_clist_t {
    fossil_clist_node_t* head;  // Head node
    char* type;                 // Data type string
} fossil_clist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new circular linked list container with the specified data type.
 * 
 * @param type A string representing the data type for the list elements.
 * @return Pointer to the newly created circular linked list container, or NULL on failure.
 */
fossil_clist_t* fossil_clist_create_container(char* type);

/**
 * Create a new circular linked list container with default settings.
 * 
 * @return Pointer to the newly created default circular linked list container, or NULL on failure.
 */
fossil_clist_t* fossil_clist_create_default(void);

/**
 * Create a deep copy of an existing circular linked list container.
 * 
 * @param other Pointer to the source circular linked list to copy.
 * @return Pointer to the newly created copy, or NULL on failure.
 */
fossil_clist_t* fossil_clist_create_copy(const fossil_clist_t* other);

/**
 * Move the contents of an existing circular linked list container to a new container.
 * The source container is left in an empty or invalid state.
 * 
 * @param other Pointer to the source circular linked list to move.
 * @return Pointer to the newly created container with moved contents, or NULL on failure.
 */
fossil_clist_t* fossil_clist_create_move(fossil_clist_t* other);

/**
 * Destroy a circular linked list container and free all associated memory.
 * 
 * @param clist Pointer to the circular linked list container to destroy.
 */
void fossil_clist_destroy(fossil_clist_t* clist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert a new element into the circular linked list.
 * The new element is added at the tail and linked back to the head.
 * 
 * @param clist Pointer to the circular linked list container.
 * @param data String data to insert as a new element.
 * @return 0 on success, non-zero on failure.
 */
int32_t fossil_clist_insert(fossil_clist_t* clist, char *data);

/**
 * Remove an element from the circular linked list.
 * Typically removes the tail or a designated element.
 * 
 * @param clist Pointer to the circular linked list container.
 * @return 0 on success, non-zero on failure.
 */
int32_t fossil_clist_remove(fossil_clist_t* clist);

/**
 * Reverse the order of elements in the circular linked list by swapping next and prev pointers.
 * 
 * @param clist Pointer to the circular linked list container.
 */
void fossil_clist_reverse(fossil_clist_t* clist);

/**
 * Get the number of elements currently stored in the circular linked list.
 * 
 * @param clist Pointer to the circular linked list container.
 * @return The number of elements in the list.
 */
size_t fossil_clist_size(const fossil_clist_t* clist);

/**
 * Check if the circular linked list contains any elements.
 * 
 * @param clist Pointer to the circular linked list container.
 * @return true if the list is not empty, false if it is empty.
 */
bool fossil_clist_not_empty(const fossil_clist_t* clist);

/**
 * Check if the circular linked list pointer is not a null pointer.
 * 
 * @param clist Pointer to the circular linked list container.
 * @return true if the pointer is valid, false if it is NULL.
 */
bool fossil_clist_not_cnullptr(const fossil_clist_t* clist);

/**
 * Check if the circular linked list is empty (contains no elements).
 * 
 * @param clist Pointer to the circular linked list container.
 * @return true if the list is empty, false otherwise.
 */
bool fossil_clist_is_empty(const fossil_clist_t* clist);

/**
 * Check if the circular linked list pointer is a null pointer.
 * 
 * @param clist Pointer to the circular linked list container.
 * @return true if the pointer is NULL, false otherwise.
 */
bool fossil_clist_is_cnullptr(const fossil_clist_t* clist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the circular linked list.
 * 
 * @param clist Pointer to the circular linked list container.
 * @param index Zero-based index of the element to retrieve.
 * @return Pointer to the string data at the specified index, or NULL if out of range.
 */
char *fossil_clist_get(const fossil_clist_t* clist, size_t index);

/**
 * Get the first (head) element in the circular linked list.
 * 
 * @param clist Pointer to the circular linked list container.
 * @return Pointer to the string data of the first element, or NULL if the list is empty.
 */
char *fossil_clist_get_front(const fossil_clist_t* clist);

/**
 * Get the last (tail) element in the circular linked list.
 * 
 * @param clist Pointer to the circular linked list container.
 * @return Pointer to the string data of the last element, or NULL if the list is empty.
 */
char *fossil_clist_get_back(const fossil_clist_t* clist);

/**
 * Set the element at the specified index in the circular linked list.
 * Overwrites the data at the given index.
 * 
 * @param clist Pointer to the circular linked list container.
 * @param index Zero-based index of the element to set.
 * @param element String data to set at the specified index.
 */
void fossil_clist_set(fossil_clist_t* clist, size_t index, char *element);

/**
 * Set the first (head) element in the circular linked list.
 * Overwrites the data of the first element.
 * 
 * @param clist Pointer to the circular linked list container.
 * @param element String data to set as the first element.
 */
void fossil_clist_set_front(fossil_clist_t* clist, char *element);

/**
 * Set the last (tail) element in the circular linked list.
 * Overwrites the data of the last element.
 * 
 * @param clist Pointer to the circular linked list container.
 * @param element String data to set as the last element.
 */
void fossil_clist_set_back(fossil_clist_t* clist, char *element);

#ifdef __cplusplus
}

#include <string>
#include <cstddef>  // For size_t
#include <stdexcept>  // For exceptions

namespace fossil {

    namespace tofu {

        /**
         * @class CList
         * @brief C++ RAII wrapper for the C circular linked list API.
         *
         * This class provides safe, type-checked, and exception-aware access to the
         * underlying C circular doubly linked list implementation. It manages memory
         * automatically and exposes familiar C++ methods for list operations.
         */
        class CList {
        private:
            fossil_clist_t* clist_;  /**< Pointer to the circular linked list container (C API) */

        public:
            /**
             * @brief Constructor: Creates a circular linked list with a specific data type.
             * @param type String representing the data type for the list elements.
             * @throws std::runtime_error If creation fails.
             */
            explicit CList(const std::string& type) {
                clist_ = fossil_clist_create_container(const_cast<char*>(type.c_str()));
                if (!clist_) {
                    throw std::runtime_error("Failed to create circular linked list");
                }
            }

            /**
             * @brief Default constructor: Creates an empty circular linked list.
             * @throws std::runtime_error If creation fails.
             */
            CList() {
                clist_ = fossil_clist_create_default();
                if (!clist_) {
                    throw std::runtime_error("Failed to create circular linked list");
                }
            }

            /**
             * @brief Copy constructor: Creates a deep copy of another CList.
             * @param other Reference to the CList to copy.
             * @throws std::runtime_error If copy creation fails.
             */
            CList(const CList& other) {
                clist_ = fossil_clist_create_copy(other.clist_);
                if (!clist_) {
                    throw std::runtime_error("Failed to copy circular linked list");
                }
            }

            /**
             * @brief Move constructor: Transfers ownership from another CList.
             *        The source CList is left in a valid but empty state.
             * @param other Rvalue reference to the CList to move.
             */
            CList(CList&& other) noexcept {
                clist_ = fossil_clist_create_move(other.clist_);
                other.clist_ = nullptr;
            }

            /**
             * @brief Destructor: Destroys the circular linked list and frees all resources.
             */
            ~CList() {
                if (clist_) {
                    fossil_clist_destroy(clist_);
                }
            }

            /**
             * @brief Insert a new element into the circular linked list.
             * @param data String data to insert as a new element.
             * @return 0 on success, non-zero on failure.
             */
            int insert(const std::string& data) {
                return fossil_clist_insert(clist_, const_cast<char*>(data.c_str()));
            }

            /**
             * @brief Remove an element from the circular linked list.
             * @return 0 on success, non-zero on failure.
             */
            int remove() {
                return fossil_clist_remove(clist_);
            }

            /**
             * @brief Reverse the order of elements in the circular linked list.
             */
            void reverse() {
                fossil_clist_reverse(clist_);
            }

            /**
             * @brief Get the number of elements in the circular linked list.
             * @return Number of elements in the list.
             */
            size_t size() const {
                return fossil_clist_size(clist_);
            }

            /**
             * @brief Check if the circular linked list contains any elements.
             * @return true if not empty, false otherwise.
             */
            bool not_empty() const {
                return fossil_clist_not_empty(clist_);
            }

            /**
             * @brief Check if the circular linked list pointer is valid (not nullptr).
             * @return true if valid, false otherwise.
             */
            bool not_cnullptr() const {
                return fossil_clist_not_cnullptr(clist_);
            }

            /**
             * @brief Check if the circular linked list is empty.
             * @return true if empty, false otherwise.
             */
            bool is_empty() const {
                return fossil_clist_is_empty(clist_);
            }

            /**
             * @brief Check if the circular linked list pointer is nullptr.
             * @return true if nullptr, false otherwise.
             */
            bool is_cnullptr() const {
                return fossil_clist_is_cnullptr(clist_);
            }

            /**
             * @brief Get the element at the specified index.
             * @param index Zero-based index of the element to retrieve.
             * @return std::string containing the element data.
             * @throws std::out_of_range If index is invalid.
             */
            std::string get(size_t index) const {
                char* result = fossil_clist_get(clist_, index);
                if (result) {
                    return std::string(result);
                }
                throw std::out_of_range("Index out of range");
            }

            /**
             * @brief Get the first (head) element in the list.
             * @return std::string containing the front element data.
             * @throws std::runtime_error If retrieval fails.
             */
            std::string get_front() const {
                char* result = fossil_clist_get_front(clist_);
                if (result) {
                    return std::string(result);
                }
                throw std::runtime_error("Failed to get front element");
            }

            /**
             * @brief Get the last (tail) element in the list.
             * @return std::string containing the back element data.
             * @throws std::runtime_error If retrieval fails.
             */
            std::string get_back() const {
                char* result = fossil_clist_get_back(clist_);
                if (result) {
                    return std::string(result);
                }
                throw std::runtime_error("Failed to get back element");
            }

            /**
             * @brief Set the element at the specified index.
             * @param index Zero-based index of the element to set.
             * @param element String data to set at the specified index.
             */
            void set(size_t index, const std::string& element) {
                fossil_clist_set(clist_, index, const_cast<char*>(element.c_str()));
            }

            /**
             * @brief Set the first (head) element in the list.
             * @param element String data to set as the first element.
             */
            void set_front(const std::string& element) {
                fossil_clist_set_front(clist_, const_cast<char*>(element.c_str()));
            }

            /**
             * @brief Set the last (tail) element in the list.
             * @param element String data to set as the last element.
             */
            void set_back(const std::string& element) {
                fossil_clist_set_back(clist_, const_cast<char*>(element.c_str()));
            }
        };

    }  // namespace tofu

}  // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
