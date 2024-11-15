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
// Algorithm functions
// *****************************************************************************

/**
 * Search for an element in the stack.
 *
 * @param stack     The stack to search.
 * @param element   The element to search for.
 * @return          The index of the element in the stack, or -1 if the element is not found.
 * @note            Time complexity: O(n)
 */
int fossil_stack_algorithm_search(fossil_stack_t* stack, char *element);

/**
 * Sort the stack.
 *
 * @param stack The stack to sort.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n^2)
 */
int fossil_stack_algorithm_sort(fossil_stack_t* stack);

/**
 * Reverse the stack.
 *
 * @param stack The stack to reverse.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n)
 */
int fossil_stack_algorithm_reverse(fossil_stack_t* stack);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

/**
 * Create a new stack with the specified data type.
 *
 * @param type The type of data the stack will store.
 * @return     The created stack.
 * @note       Time complexity: O(1)
 */
fossil_stack_t *stack_create_container(const std::string& type) {
    return fossil_stack_create_container(const_cast<char*>(type.c_str()));
}

/**
 * Erase the contents of the stack and fossil_tofu_free allocated memory.
 *
 * @param stack The stack to erase.
 * @note        Time complexity: O(n)
 */
void stack_destroy(fossil_stack_t* stack) {
    fossil_stack_destroy(stack);
}

/**
 * Insert data into the stack.
 *
 * @param stack The stack to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t stack_insert(fossil_stack_t* stack, const std::string& data) {
    return fossil_stack_insert(stack, const_cast<char*>(data.c_str()));
}

/**
 * Remove data from the stack.
 *
 * @param stack The stack to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t stack_remove(fossil_stack_t* stack) {
    return fossil_stack_remove(stack);
}

/**
 * Get the size of the stack.
 *
 * @param stack The stack for which to get the size.
 * @return      The size of the stack.
 * @note        Time complexity: O(n)
 */
size_t stack_size(const fossil_stack_t* stack) {
    return fossil_stack_size(stack);
}

/**
 * Check if the stack is not empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool stack_not_empty(const fossil_stack_t* stack) {
    return fossil_stack_not_empty(stack);
}

/**
 * Check if the stack is not a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool stack_not_cnullptr(const fossil_stack_t* stack) {
    return fossil_stack_not_cnullptr(stack);
}

/**
 * Check if the stack is empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool stack_is_empty(const fossil_stack_t* stack) {
    return fossil_stack_is_empty(stack);
}

/**
 * Check if the stack is a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool stack_is_cnullptr(const fossil_stack_t* stack) {
    return fossil_stack_is_cnullptr(stack);
}

/**
 * Get the top element of the stack.
 *
 * @param stack         The stack to get the top element from.
 * @return              The top element of the stack or the default value if the stack is empty.
 * @note                Time complexity: O(1)
 */
fossil_tofu_t stack_top(fossil_stack_t* stack) {
    return fossil_stack_top(stack);
}

/**
 * Search for an element in the stack.
 *
 * @param stack     The stack to search.
 * @param element   The element to search for.
 * @return          The index of the element in the stack, or -1 if the element is not found.
 * @note            Time complexity: O(n)
 */
int stack_algorithm_search(fossil_stack_t* stack, const std::string& element) {
    return fossil_stack_algorithm_search(stack, const_cast<char*>(element.c_str()));
}

/**
 * Sort the stack.
 *
 * @param stack The stack to sort.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n^2)
 */
int stack_algorithm_sort(fossil_stack_t* stack) {
    return fossil_stack_algorithm_sort(stack);
}

/**
 * Reverse the stack.
 *
 * @param stack The stack to reverse.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n)
 */
int stack_algorithm_reverse(fossil_stack_t* stack) {
    return fossil_stack_algorithm_reverse(stack);
}

}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
