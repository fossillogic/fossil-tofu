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
 * @note Time complexity: O(n), where n is the number of initial elements.
 */
fossil_tofu_arrayof_t fossil_tofu_arrayof_create(char *type, size_t size, ...);

/**
 * @brief Destroys the arrayof and frees allocated memory.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t to be destroyed.
 * @note Time complexity: O(1).
 */
void fossil_tofu_arrayof_destroy(fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Adds a fossil_tofu_t element to the end of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @param tofu The fossil_tofu_t element to add.
 * @note Time complexity: O(1) on average, O(n) in the worst case when resizing.
 */
void fossil_tofu_arrayof_add(fossil_tofu_arrayof_t *arrayof, fossil_tofu_t tofu);

/**
 * @brief Retrieves the fossil_tofu_t element at a specified index.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @param index The index of the element to retrieve.
 * @return The fossil_tofu_t element at the specified index.
 * @note Time complexity: O(1).
 */
fossil_tofu_t fossil_tofu_arrayof_get(const fossil_tofu_arrayof_t *arrayof, size_t index);

/**
 * @brief Returns the current size of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @return The current number of elements in the arrayof.
 * @note Time complexity: O(1).
 */
size_t fossil_tofu_arrayof_size(const fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Checks if the arrayof is empty.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @return True if the arrayof is empty, false otherwise.
 * @note Time complexity: O(1).
 */
bool fossil_tofu_arrayof_is_empty(const fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Clears all elements from the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @note Time complexity: O(n), where n is the number of elements in the array.
 */
void fossil_tofu_arrayof_clear(fossil_tofu_arrayof_t *arrayof);

/**
 * @brief Prints all elements of the arrayof.
 * 
 * @param arrayof A pointer to the fossil_tofu_arrayof_t.
 * @note Time complexity: O(n), where n is the number of elements in the array.
 */
void fossil_tofu_arrayof_print(const fossil_tofu_arrayof_t *arrayof);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace fossil {
    class ArrayOf {
    public:
        ArrayOf(const std::string& type, size_t size, ...) : arrayof_(fossil_tofu_arrayof_create(const_cast<char*>(type.c_str()), size)) {}

        ~ArrayOf() {
            fossil_tofu_arrayof_destroy(arrayof_);
        }

        void add(fossil_tofu_t element) {
            fossil_tofu_arrayof_add(arrayof_, element);
        }

        fossil_tofu_t get(size_t index) {
            return fossil_tofu_arrayof_get(arrayof_, index);
        }

        size_t size() {
            return fossil_tofu_arrayof_size(arrayof_);
        }

        bool is_empty() {
            return fossil_tofu_arrayof_is_empty(arrayof_);
        }

        void clear() {
            fossil_tofu_arrayof_clear(arrayof_);
        }

        void print() {
            fossil_tofu_arrayof_print(arrayof_);
        }

    private:
        fossil_tofu_arrayof_t* arrayof_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
