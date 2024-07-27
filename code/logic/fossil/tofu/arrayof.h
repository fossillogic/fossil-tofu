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
#ifndef FOSSIL_TOFU_ARRAYOF_H
#define FOSSIL_TOFU_ARRAYOF_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Struct for arrayof
typedef struct {
    fossil_tofu_t *array; // Array of fossil_tofu_t elements
    size_t size;          // Current size of the array
    size_t capacity;      // Capacity of the array
} fossil_tofu_arrayof_t;

/**
 * @brief Creates an arrayof with an initial set of elements.
 * 
 * @param type The type of the elements.
 * @param size The number of initial elements.
 * @param ... The initial values for the elements.
 * @return A newly created fossil_tofu_arrayof_t.
 */
fossil_tofu_arrayof_t fossil_tofu_arrayof_create(char *type, size_t size, ...);

/**
 * @brief Destroys the arrayof and frees allocated memory.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t to be destroyed.
 */
void fossil_tofu_arrayof_erase(fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Adds a fossil_tofu_t element to the end of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @param tofu The fossil_tofu_t element to add.
 */
void fossil_tofu_arrayof_add(fossil_tofu_arrayof_t *arrayof, fossil_tofu_t tofu);

/**
 * @brief Retrieves the fossil_tofu_t element at a specified index.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @param index The index of the element to retrieve.
 * @return The fossil_tofu_t element at the specified index.
 */
fossil_tofu_t fossil_tofu_arrayof_get(const fossil_tofu_arrayof_t *arrayof, size_t index);

/**
 * @brief Returns the current size of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @return The current number of elements in the arrayof.
 */
size_t fossil_tofu_arrayof_size(const fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Checks if the arrayof is empty.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @return True if the arrayof is empty, false otherwise.
 */
bool fossil_tofu_arrayof_is_empty(const fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Clears all elements from the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 */
void fossil_tofu_arrayof_clear(fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Prints all elements of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 */
void fossil_tofu_arrayof_print(const fossil_tofu_arrayof_t *arrayof);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
