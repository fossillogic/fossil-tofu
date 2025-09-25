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
#ifndef FOSSIL_TOFU_STACK_H
#define FOSSIL_TOFU_STACK_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Stack structure
typedef struct fossil_stack_node_t {
    fossil_tofu_t data; // Data stored in the stack node
    struct fossil_stack_node_t* next; // Pointer to the next node
} fossil_stack_node_t;

typedef struct fossil_stack_t {
    char* type; // Type of the stack
    fossil_stack_node_t* top; // Pointer to the top node of the stack
} fossil_stack_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new stack with the specified data type.
 *
 * @param list_type The type of data the stack will store.
 * @return          The created stack.
 * @note            Time complexity: O(1)
 */
fossil_stack_t* fossil_stack_create_container(char* type);

/**
 * Create a new stack with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created stack.
 */
fossil_stack_t* fossil_stack_create_default(void);

/**
 * Create a new stack by copying an existing stack.
 * 
 * Time complexity: O(n)
 *
 * @param other The stack to copy.
 * @return      The created stack.
 */
fossil_stack_t* fossil_stack_create_copy(const fossil_stack_t* other);

/**
 * Create a new stack by moving an existing stack.
 * 
 * Time complexity: O(1)
 *
 * @param other The stack to move.
 * @return      The created stack.
 */
fossil_stack_t* fossil_stack_create_move(fossil_stack_t* other);

/**
 * Erase the contents of the stack and fossil_tofu_free allocated memory.
 *
 * @param stack The stack to erase.
 * @note        Time complexity: O(n)
 */
void fossil_stack_destroy(fossil_stack_t* stack);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the stack.
 *
 * @param stack The stack to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_stack_insert(fossil_stack_t* stack, char *data);

/**
 * Remove data from the stack.
 *
 * @param stack       The stack to remove data from.
 * @return            The error code indicating the success or failure of the operation.
 * @note              Time complexity: O(1)
 */
int32_t fossil_stack_remove(fossil_stack_t* stack);

/**
 * Get the size of the stack.
 *
 * @param stack The stack for which to get the size.
 * @return      The size of the stack.
 * @note        Time complexity: O(n)
 */
size_t fossil_stack_size(const fossil_stack_t* stack);

/**
 * Check if the stack is not empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_not_empty(const fossil_stack_t* stack);

/**
 * Check if the stack is not a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_not_cnullptr(const fossil_stack_t* stack);

/**
 * Check if the stack is empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_is_empty(const fossil_stack_t* stack);

/**
 * Check if the stack is a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_is_cnullptr(const fossil_stack_t* stack);

/**
 * Get the top element of the stack.
 *
 * @param stack         The stack to get the top element from.
 * @return              The top element of the stack or the default value if the stack is empty.
 * @note                Time complexity: O(1)
 */
fossil_tofu_t fossil_stack_top(fossil_stack_t* stack);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the stack.
 * 
 * Time complexity: O(n)
 *
 * @param stack The stack from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
fossil_tofu_t fossil_stack_get(const fossil_stack_t* stack, size_t index);

/**
 * Set the element at the specified index in the stack.
 * 
 * Time complexity: O(n)
 *
 * @param stack   The stack in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_stack_set(fossil_stack_t* stack, size_t index, fossil_tofu_t element);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {

    namespace tofu {

        /**
         * A C++ wrapper class for the fossil_stack_t structure, providing a more
         * user-friendly interface for stack operations.
         */
        class Stack {
            public:
                /**
                 * Constructor to create a stack with a specified type.
                 *
                 * @param type The type of data the stack will store.
                 * @throws std::runtime_error If the stack creation fails.
                 */
                Stack(const std::string& type) {
                    stack_ = fossil_stack_create_container(const_cast<char*>(type.c_str()));
                    if (!stack_) {
                        throw std::runtime_error("Failed to create stack.");
                    }
                }

                /**
                 * Default constructor to create a stack with default values.
                 *
                 * @throws std::runtime_error If the stack creation fails.
                 */
                Stack() {
                    stack_ = fossil_stack_create_default();
                    if (!stack_) {
                        throw std::runtime_error("Failed to create stack.");
                    }
                }

                /**
                 * Copy constructor to create a stack by copying another stack.
                 *
                 * @param other The stack to copy.
                 * @throws std::runtime_error If the stack creation fails.
                 */
                Stack(const Stack& other) {
                    stack_ = fossil_stack_create_copy(other.stack_);
                    if (!stack_) {
                        throw std::runtime_error("Failed to create stack.");
                    }
                }

                /**
                 * Destructor to destroy the stack and free allocated memory.
                 */
                ~Stack() {
                    fossil_stack_destroy(stack_);
                }

                /**
                 * Insert data into the stack.
                 *
                 * @param data The data to insert.
                 * @return     The error code indicating the success or failure of the operation.
                 */
                int32_t insert(const std::string& data) {
                    return fossil_stack_insert(stack_, const_cast<char*>(data.c_str()));
                }

                /**
                 * Remove data from the stack.
                 *
                 * @return The error code indicating the success or failure of the operation.
                 */
                int32_t remove() {
                    return fossil_stack_remove(stack_);
                }

                /**
                 * Get the size of the stack.
                 *
                 * @return The size of the stack.
                 */
                size_t size() const {
                    return fossil_stack_size(stack_);
                }

                /**
                 * Check if the stack is not empty.
                 *
                 * @return True if the stack is not empty, false otherwise.
                 */
                bool not_empty() const {
                    return fossil_stack_not_empty(stack_);
                }

                /**
                 * Check if the stack is not a null pointer.
                 *
                 * @return True if the stack is not a null pointer, false otherwise.
                 */
                bool not_cnullptr() const {
                    return fossil_stack_not_cnullptr(stack_);
                }

                /**
                 * Check if the stack is empty.
                 *
                 * @return True if the stack is empty, false otherwise.
                 */
                bool is_empty() const {
                    return fossil_stack_is_empty(stack_);
                }

                /**
                 * Check if the stack is a null pointer.
                 *
                 * @return True if the stack is a null pointer, false otherwise.
                 */
                bool is_cnullptr() const {
                    return fossil_stack_is_cnullptr(stack_);
                }

                /**
                 * Get the top element of the stack.
                 *
                 * @return The top element of the stack or the default value if the stack is empty.
                 */
                fossil_tofu_t top() {
                    return fossil_stack_top(stack_);
                }

                /**
                 * Get the element at the specified index in the stack.
                 *
                 * @param index The index of the element to get.
                 * @return      The element at the specified index.
                 */
                fossil_tofu_t get(size_t index) const {
                    return fossil_stack_get(stack_, index);
                }

                /**
                 * Set the element at the specified index in the stack.
                 *
                 * @param index   The index at which to set the element.
                 * @param element The element to set.
                 */
                void set(size_t index, fossil_tofu_t element) {
                    fossil_stack_set(stack_, index, element);
                }

            private:
                /**
                 * Pointer to the underlying fossil_stack_t structure.
                 */
                fossil_stack_t* stack_;
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
