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
 * Create a new circular linked list with the specified data type.
 */
fossil_clist_t* fossil_clist_create_container(char* type);

/**
 * Create a new circular linked list with default values.
 */
fossil_clist_t* fossil_clist_create_default(void);

/**
 * Create a copy of an existing circular linked list.
 */
fossil_clist_t* fossil_clist_create_copy(const fossil_clist_t* other);

/**
 * Move an existing circular linked list.
 */
fossil_clist_t* fossil_clist_create_move(fossil_clist_t* other);

/**
 * Destroy a circular linked list and free allocated memory.
 */
void fossil_clist_destroy(fossil_clist_t* clist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert a new element into the circular linked list.
 * The new element is inserted at the tail and links back to the head.
 */
int32_t fossil_clist_insert(fossil_clist_t* clist, char *data);

/**
 * Remove an element from the circular linked list.
 */
int32_t fossil_clist_remove(fossil_clist_t* clist);

/**
 * Reverse the circular linked list by swapping next and prev pointers.
 */
void fossil_clist_reverse(fossil_clist_t* clist);

/**
 * Get the size of the circular linked list.
 */
size_t fossil_clist_size(const fossil_clist_t* clist);

/**
 * Check if the circular linked list is not empty.
 */
bool fossil_clist_not_empty(const fossil_clist_t* clist);

/**
 * Check if the circular linked list is not a null pointer.
 */
bool fossil_clist_not_cnullptr(const fossil_clist_t* clist);

/**
 * Check if the circular linked list is empty.
 */
bool fossil_clist_is_empty(const fossil_clist_t* clist);

/**
 * Check if the circular linked list is a null pointer.
 */
bool fossil_clist_is_cnullptr(const fossil_clist_t* clist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the circular linked list.
 */
char *fossil_clist_get(const fossil_clist_t* clist, size_t index);

/**
 * Get the first element in the circular linked list.
 */
char *fossil_clist_get_front(const fossil_clist_t* clist);

/**
 * Get the last element in the circular linked list.
 */
char *fossil_clist_get_back(const fossil_clist_t* clist);

/**
 * Set the element at the specified index in the circular linked list.
 */
void fossil_clist_set(fossil_clist_t* clist, size_t index, char *element);

/**
 * Set the first element in the circular linked list.
 */
void fossil_clist_set_front(fossil_clist_t* clist, char *element);

/**
 * Set the last element in the circular linked list.
 */
void fossil_clist_set_back(fossil_clist_t* clist, char *element);

#ifdef __cplusplus
}

#include <string>
#include <cstddef>  // For size_t
#include <stdexcept>  // For exceptions

namespace fossil {
namespace tofu {

class CList {
private:
    fossil_clist_t* clist_;  // Pointer to the circular linked list container (C API)

public:
    // Constructor to create a circular linked list with a specific data type.
    // Throws an exception if creation fails.
    explicit CList(const std::string& type) {
        // Create the list container with the given type.
        clist_ = fossil_clist_create_container(const_cast<char*>(type.c_str()));
        if (!clist_) {
            // If creation failed, throw an exception.
            throw std::runtime_error("Failed to create circular linked list");
        }
    }

    // Default constructor for creating an empty circular linked list.
    // Throws an exception if creation fails.
    CList() {
        // Create the default list container.
        clist_ = fossil_clist_create_default();
        if (!clist_) {
            // If creation failed, throw an exception.
            throw std::runtime_error("Failed to create circular linked list");
        }
    }

    // Copy constructor: Creates a new list as a copy of another list.
    // Throws an exception if copy creation fails.
    CList(const CList& other) {
        // Create a copy of the other list.
        clist_ = fossil_clist_create_copy(other.clist_);
        if (!clist_) {
            // If copy creation failed, throw an exception.
            throw std::runtime_error("Failed to copy circular linked list");
        }
    }

    // Move constructor: Transfers ownership of resources from another list to this one.
    // The other list is left in a valid but empty state.
    CList(CList&& other) noexcept {
        // Steal the list container from the other list.
        clist_ = fossil_clist_create_move(other.clist_);
        // Set the other list's pointer to null, so it no longer owns the list.
        other.clist_ = nullptr;
    }

    // Destructor: Destroys the circular linked list and frees its memory.
    ~CList() {
        if (clist_) {
            // If the list is not null, destroy it and release resources.
            fossil_clist_destroy(clist_);
        }
    }

    // Insert a new element into the circular linked list.
    // Returns an integer status code (0 for success, non-zero for failure).
    int insert(const std::string& data) {
        // Insert the element into the list. Returns 0 if successful.
        return fossil_clist_insert(clist_, const_cast<char*>(data.c_str()));
    }

    // Remove an element from the circular linked list.
    // Returns an integer status code (0 for success, non-zero for failure).
    int remove() {
        // Remove an element from the list. Returns 0 if successful.
        return fossil_clist_remove(clist_);
    }

    // Reverse the order of elements in the circular linked list.
    void reverse() {
        // Call the C API function to reverse the list.
        fossil_clist_reverse(clist_);
    }

    // Return the number of elements in the circular linked list.
    size_t size() const {
        // Call the C API function to get the size.
        return fossil_clist_size(clist_);
    }

    // Check if the circular linked list is not empty.
    // Returns true if the list is not empty, false if it is empty.
    bool not_empty() const {
        // Check if the list has elements.
        return fossil_clist_not_empty(clist_);
    }

    // Check if the circular linked list is not a null pointer.
    // Returns true if the list is valid, false if it is null.
    bool not_cnullptr() const {
        // Check if the list is not a nullptr.
        return fossil_clist_not_cnullptr(clist_);
    }

    // Check if the circular linked list is empty.
    // Returns true if the list is empty, false if it has elements.
    bool is_empty() const {
        // Check if the list is empty.
        return fossil_clist_is_empty(clist_);
    }

    // Check if the circular linked list is a null pointer.
    // Returns true if the list is null, false if it is valid.
    bool is_cnullptr() const {
        // Check if the list is a nullptr.
        return fossil_clist_is_cnullptr(clist_);
    }

    // Get the element at the specified index in the circular linked list.
    // Throws an exception if the index is out of range.
    std::string get(size_t index) const {
        // Retrieve the element at the specified index.
        char* result = fossil_clist_get(clist_, index);
        if (result) {
            // Return the element as a string.
            return std::string(result);
        }
        // If the element does not exist (invalid index), throw an exception.
        throw std::out_of_range("Index out of range");
    }

    // Get the first element in the circular linked list.
    // Throws an exception if the list is empty or retrieval fails.
    std::string get_front() const {
        // Retrieve the front element of the list.
        char* result = fossil_clist_get_front(clist_);
        if (result) {
            // Return the front element as a string.
            return std::string(result);
        }
        // If the front element does not exist, throw an exception.
        throw std::runtime_error("Failed to get front element");
    }

    // Get the last element in the circular linked list.
    // Throws an exception if the list is empty or retrieval fails.
    std::string get_back() const {
        // Retrieve the back element of the list.
        char* result = fossil_clist_get_back(clist_);
        if (result) {
            // Return the back element as a string.
            return std::string(result);
        }
        // If the back element does not exist, throw an exception.
        throw std::runtime_error("Failed to get back element");
    }

    // Set the element at the specified index in the circular linked list.
    void set(size_t index, const std::string& element) {
        // Set the element at the specified index in the list.
        fossil_clist_set(clist_, index, const_cast<char*>(element.c_str()));
    }

    // Set the first element in the circular linked list.
    void set_front(const std::string& element) {
        // Set the front element of the list.
        fossil_clist_set_front(clist_, const_cast<char*>(element.c_str()));
    }

    // Set the last element in the circular linked list.
    void set_back(const std::string& element) {
        // Set the back element of the list.
        fossil_clist_set_back(clist_, const_cast<char*>(element.c_str()));
    }
};

}  // namespace tofu
}  // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
