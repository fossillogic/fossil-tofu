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

// Define a tuple to hold multiple ToFu elements
typedef struct {
    fossil_tofu_t* elements;  // Dynamic array of ToFu elements in the tuple
    size_t element_count;     // Number of elements in the tuple
    size_t capacity;          // Capacity of the tuple
    char* type;               // Expected type of elements in the tuple
} fossil_tuple_t;

/**
 * @brief Creates a new tuple with a given initial capacity.
 *
 * @param size The initial capacity of the tuple.
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tuple_t fossil_tuple_create(char *type);

/**
 * @brief Destroys the tuple and frees the allocated memory.
 *
 * @param tuple The tuple to destroy.
 * @note Time complexity: O(n)
 */
void fossil_tuple_destroy(fossil_tuple_t *tuple);

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
fossil_tofu_t fossil_tuple_get(fossil_tuple_t *tuple, size_t index);

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

/**
 * @brief Prints the contents of the tuple.
 *
 * @param tuple The tuple to print.
 * @note Time complexity: O(n)
 */
void fossil_tuple_print(fossil_tuple_t *tuple);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */