/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#ifndef FOSSIL_TOFU_STACK_H
#define FOSSIL_TOFU_STACK_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Stack structure
typedef struct fossil_stack_node_t {
    fossil_tofu_t data; // Data stored in the stack node
    struct fossil_stack_node_t* next; // Pointer to the next node
} fossil_stack_node_t;

typedef struct fossil_stack_t {
    char* type; // Type of the stack
    fossil_stack_node_t* top; // Pointer to the top node of the stack
} fossil_stack_t;

/**
 * Create a new stack with the specified data type.
 *
 * @param list_type The type of data the stack will store.
 * @return          The created stack.
 * @note            Time complexity: O(1)
 */
fossil_stack_t* fossil_stack_create(char* type);

/**
 * Erase the contents of the stack and free allocated memory.
 *
 * @param stack The stack to erase.
 * @note        Time complexity: O(n)
 */
void fossil_stack_destroy(fossil_stack_t* stack);

/**
 * Insert data into the stack.
 *
 * @param stack The stack to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_stack_insert(fossil_stack_t* stack, fossil_tofu_t data);

/**
 * Remove data from the stack.
 *
 * @param stack       The stack to remove data from.
 * @param[out] data   A pointer to store the removed data.
 * @return            The error code indicating the success or failure of the operation.
 * @note              Time complexity: O(1)
 */
int32_t fossil_stack_remove(fossil_stack_t* stack, fossil_tofu_t* data);

/**
 * Search for data in the stack.
 *
 * @param stack The stack to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n)
 */
int32_t fossil_stack_search(const fossil_stack_t* stack, fossil_tofu_t data);

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
 * @param default_value The default value to return if the stack is empty.
 * @return              The top element of the stack or the default value if the stack is empty.
 * @note                Time complexity: O(1)
 */
fossil_tofu_t fossil_stack_top(fossil_stack_t* stack, fossil_tofu_t default_value);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace fossil {
    class Stack {
    public:
        Stack(const std::string& type) : stack_(fossil_stack_create(const_cast<char*>(type.c_str()))) {}

        ~Stack() {
            fossil_stack_destroy(stack_);
        }

        void insert(fossil_tofu_t data) {
            fossil_stack_insert(stack_, data);
        }

        fossil_tofu_t remove() {
            fossil_tofu_t data;
            fossil_stack_remove(stack_, &data);
            return data;
        }

        bool search(fossil_tofu_t data) {
            return fossil_stack_search(stack_, data) == 0;
        }

        size_t size() {
            return fossil_stack_size(stack_);
        }

        bool not_empty() {
            return fossil_stack_not_empty(stack_);
        }

        bool not_cnullptr() {
            return fossil_stack_not_cnullptr(stack_);
        }

        bool is_empty() {
            return fossil_stack_is_empty(stack_);
        }

        bool is_cnullptr() {
            return fossil_stack_is_cnullptr(stack_);
        }

        fossil_tofu_t top(fossil_tofu_t default_value) {
            return fossil_stack_top(stack_, default_value);
        }

    private:
        fossil_stack_t* stack_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
