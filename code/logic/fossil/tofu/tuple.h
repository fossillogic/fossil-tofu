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
#ifndef FOSSIL_TOFU_TUPLE_H
#define FOSSIL_TOFU_TUPLE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Define a tuple to hold multiple ToFu elements
typedef struct {
    fossil_tofu_t* elements;  // Dynamic array of ToFu elements in the tuple
    size_t element_count;     // Number of elements in the tuple
    size_t capacity;          // Capacity of the tuple
    char* type;               // Expected type of elements in the tuple
} fossil_tuple_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * @brief Creates a new tuple with a given initial capacity.
 *
 * @param size The initial capacity of the tuple.
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tuple_t *fossil_tuple_create(char *type);

/**
 * @brief Destroys the tuple and fossil_tofu_frees the allocated memory.
 *
 * @param tuple The tuple to destroy.
 * @note Time complexity: O(n)
 */
void fossil_tuple_destroy(fossil_tuple_t *tuple);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * @brief Adds an element to the tuple.
 *
 * @param tuple The tuple to add the element to.
 * @param element The element to add.
 * @note Time complexity: O(1) on average, O(n) in the worst case due to resizing.
 */
void fossil_tuple_add(fossil_tuple_t *tuple, char *element);

/**
 * @brief Gets the element at the specified index from the tuple.
 *
 * @param tuple The tuple to get the element from.
 * @param index The index to get the element at.
 * @return The element at the specified index, or NULL if the index is out of bounds.
 * @note Time complexity: O(1)
 */
char *fossil_tuple_get(fossil_tuple_t *tuple, size_t index);

/**
 * @brief Removes the element at the specified index from the tuple.
 *
 * @param tuple The tuple to remove the element from.
 * @param index The index to remove the element at.
 * @note Time complexity: O(n)
 */
void fossil_tuple_remove(fossil_tuple_t *tuple, size_t index);

/**
 * @brief Gets the number of elements in the tuple.
 *
 * @param tuple The tuple to get the size of.
 * @return The number of elements in the tuple.
 * @note Time complexity: O(1)
 */
size_t fossil_tuple_size(fossil_tuple_t *tuple);

/**
 * @brief Gets the capacity of the tuple.
 *
 * @param tuple The tuple to get the capacity of.
 * @return The capacity of the tuple.
 * @note Time complexity: O(1)
 */
size_t fossil_tuple_capacity(fossil_tuple_t *tuple);

/**
 * @brief Checks if the tuple is empty.
 *
 * @param tuple The tuple to check.
 * @return true if the tuple is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_tuple_is_empty(fossil_tuple_t *tuple);

/**
 * @brief Clears all elements from the tuple.
 *
 * @param tuple The tuple to clear.
 * @note Time complexity: O(n)
 */
void fossil_tuple_clear(fossil_tuple_t *tuple);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

/**
 * @brief Creates a new tuple with a given initial capacity.
 *
 * @param type The type of elements in the tuple.
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tuple_t *tuple_create(const std::string& type) {
    return fossil_tuple_create(const_cast<char*>(type.c_str()));
}

/**
 * @brief Destroys the tuple and frees the allocated memory.
 *
 * @param tuple The tuple to destroy.
 * @note Time complexity: O(n)
 */
void tuple_destroy(fossil_tuple_t *tuple) {
    fossil_tuple_destroy(tuple);
}

/**
 * @brief Adds an element to the tuple.
 *
 * @param tuple The tuple to add the element to.
 * @param element The element to add.
 * @note Time complexity: O(1) on average, O(n) in the worst case due to resizing.
 */
void tuple_add(fossil_tuple_t *tuple, const std::string& element) {
    fossil_tuple_add(tuple, const_cast<char*>(element.c_str()));
}

/**
 * @brief Gets the element at the specified index from the tuple.
 *
 * @param tuple The tuple to get the element from.
 * @param index The index to get the element at.
 * @return The element at the specified index, or NULL if the index is out of bounds.
 * @note Time complexity: O(1)
 */
std::string tuple_get(fossil_tuple_t *tuple, size_t index) {
    return std::string(fossil_tuple_get(tuple, index));
}

/**
 * @brief Removes the element at the specified index from the tuple.
 *
 * @param tuple The tuple to remove the element from.
 * @param index The index to remove the element at.
 * @note Time complexity: O(n)
 */
void tuple_remove(fossil_tuple_t *tuple, size_t index) {
    fossil_tuple_remove(tuple, index);
}

/**
 * @brief Gets the number of elements in the tuple.
 *
 * @param tuple The tuple to get the size of.
 * @return The number of elements in the tuple.
 * @note Time complexity: O(1)
 */
size_t tuple_size(fossil_tuple_t *tuple) {
    return fossil_tuple_size(tuple);
}

/**
 * @brief Gets the capacity of the tuple.
 *
 * @param tuple The tuple to get the capacity of.
 * @return The capacity of the tuple.
 * @note Time complexity: O(1)
 */
size_t tuple_capacity(fossil_tuple_t *tuple) {
    return fossil_tuple_capacity(tuple);
}

/**
 * @brief Checks if the tuple is empty.
 *
 * @param tuple The tuple to check.
 * @return true if the tuple is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool tuple_is_empty(fossil_tuple_t *tuple) {
    return fossil_tuple_is_empty(tuple);
}

/**
 * @brief Clears all elements from the tuple.
 *
 * @param tuple The tuple to clear.
 * @note Time complexity: O(n)
 */
void tuple_clear(fossil_tuple_t *tuple) {
    fossil_tuple_clear(tuple);
}

}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
