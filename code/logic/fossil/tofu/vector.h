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
#ifndef FOSSIL_TOFU_VECTOR_H
#define FOSSIL_TOFU_VECTOR_H

#include "tofu.h"

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

typedef struct {
    fossil_tofu_t* data;
    size_t size;
    size_t capacity;
    char* type;
} fossil_vector_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new vector with the specified expected type.
 * 
 * Time complexity: O(1)
 *
 * @param expected_type The expected type of elements in the vector.
 * @return              The created vector.
 */
fossil_vector_t* fossil_vector_create_container(char* type);

/**
 * Erase the contents of the vector and fossil_tofu_free allocated memory.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to erase.
 */
void fossil_vector_destroy(fossil_vector_t* vector);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Add an element to the end of the vector.
 * 
 * Amortized time complexity: O(1)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_back(fossil_vector_t* vector, char *element);

/**
 * Add an element to the front of the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_front(fossil_vector_t* vector, char *element);

/**
 * Add an element at the specified index in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param index   The index at which to add the element.
 * @param element The element to add.
 */
void fossil_vector_push_at(fossil_vector_t* vector, size_t index, char *element);

/**
 * Remove the last element from the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to remove the last element.
 */
void fossil_vector_pop_back(fossil_vector_t* vector);

/**
 * Remove the first element from the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector from which to remove the first element.
 */
void fossil_vector_pop_front(fossil_vector_t* vector);

/**
 * Remove the element at the specified index in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector from which to remove the element.
 * @param index  The index at which to remove the element.
 */
void fossil_vector_pop_at(fossil_vector_t* vector, size_t index);

/**
 * Remove the specified element from the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector from which to remove the element.
 * @return        0 if the element was removed, -1 otherwise.
 */
int32_t fossil_vector_remove(fossil_vector_t* vector);

/**
 * Remove all elements from the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to remove all elements.
 */
void fossil_vector_erase(fossil_vector_t* vector);

/**
 * Check if the vector is a null pointer.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is a null pointer, false otherwise.
 */
bool fossil_vector_is_cnullptr(const fossil_vector_t* vector);

/**
 * Check if the vector is not a null pointer.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is not a null pointer, false otherwise.
 */
bool fossil_vector_not_cnullptr(const fossil_vector_t* vector);

/**
 * Check if the vector is empty.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is empty, false otherwise.
 */
bool fossil_vector_is_empty(const fossil_vector_t* vector);

/**
 * Check if the vector is not empty.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is not empty, false otherwise.
 */
bool fossil_vector_not_empty(const fossil_vector_t* vector);

/**
 * Get the size of the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector for which to get the size.
 * @return       The size of the vector.
 */
size_t fossil_vector_size(const fossil_vector_t* vector);

/**
 * Get the capacity of the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector for which to get the capacity.
 * @return       The capacity of the vector.
 */
size_t fossil_vector_capacity(const fossil_vector_t* vector);

/**
 * Get the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the element.
 * @param index  The index of the element to get.
 * @return       The element at the specified index.
 */
char *fossil_vector_get(const fossil_vector_t* vector, size_t index);

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

/**
 * Search for an element in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector in which to search for the element.
 * @param element The element to search for.
 * @return        0 if the element was found, -1 otherwise.
 */
int fossil_vector_algorithm_search(const fossil_vector_t* vector, char *element);

/**
 * Sort the elements in the vector.
 * 
 * Time complexity: O(n log n)
 *
 * @param vector The vector to sort.
 * @return       0 if the vector was sorted, -1 otherwise.
 */
int fossil_vector_algorithm_sort(fossil_vector_t* vector);

/**
 * Reverse the elements in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to reverse.
 * @return       0 if the vector was reversed, -1 otherwise.
 */
int fossil_vector_algorithm_reverse(fossil_vector_t* vector);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

/**
 * Create a new vector with the specified expected type.
 * 
 * Time complexity: O(1)
 *
 * @param expected_type The expected type of elements in the vector.
 * @return              The created vector.
 */
inline fossil_vector_t* vector_create_container(const std::string& type) {
    return fossil_vector_create_container(const_cast<char*>(type.c_str()));
}

/**
 * Erase the contents of the vector and fossil_tofu_free allocated memory.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to erase.
 */
inline void vector_destroy(fossil_vector_t* vector) {
    fossil_vector_destroy(vector);
}

/**
 * Add an element to the end of the vector.
 * 
 * Amortized time complexity: O(1)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
inline void vector_push_back(fossil_vector_t* vector, const std::string& element) {
    fossil_vector_push_back(vector, const_cast<char*>(element.c_str()));
}

/**
 * Add an element to the front of the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
inline void vector_push_front(fossil_vector_t* vector, const std::string& element) {
    fossil_vector_push_front(vector, const_cast<char*>(element.c_str()));
}

/**
 * Add an element at the specified index in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param index   The index at which to add the element.
 * @param element The element to add.
 */
inline void vector_push_at(fossil_vector_t* vector, size_t index, const std::string& element) {
    fossil_vector_push_at(vector, index, const_cast<char*>(element.c_str()));
}

/**
 * Remove the last element from the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to remove the last element.
 */
inline void vector_pop_back(fossil_vector_t* vector) {
    fossil_vector_pop_back(vector);
}

/**
 * Remove the first element from the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector from which to remove the first element.
 */
inline void vector_pop_front(fossil_vector_t* vector) {
    fossil_vector_pop_front(vector);
}

/**
 * Remove the element at the specified index in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector from which to remove the element.
 * @param index  The index at which to remove the element.
 */
inline void vector_pop_at(fossil_vector_t* vector, size_t index) {
    fossil_vector_pop_at(vector, index);
}

/**
 * Remove the specified element from the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector from which to remove the element.
 * @return        0 if the element was removed, -1 otherwise.
 */
inline int32_t vector_remove(fossil_vector_t* vector) {
    return fossil_vector_remove(vector);
}

/**
 * Remove all elements from the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to remove all elements.
 */
inline void vector_erase(fossil_vector_t* vector) {
    fossil_vector_erase(vector);
}

/**
 * Check if the vector is a null pointer.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is a null pointer, false otherwise.
 */
inline bool vector_is_cnullptr(const fossil_vector_t* vector) {
    return fossil_vector_is_cnullptr(vector);
}

/**
 * Check if the vector is not a null pointer.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is not a null pointer, false otherwise.
 */
inline bool vector_not_cnullptr(const fossil_vector_t* vector) {
    return fossil_vector_not_cnullptr(vector);
}

/**
 * Check if the vector is empty.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is empty, false otherwise.
 */
inline bool vector_is_empty(const fossil_vector_t* vector) {
    return fossil_vector_is_empty(vector);
}

/**
 * Check if the vector is not empty.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is not empty, false otherwise.
 */
inline bool vector_not_empty(const fossil_vector_t* vector) {
    return fossil_vector_not_empty(vector);
}

/**
 * Get the size of the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector for which to get the size.
 * @return       The size of the vector.
 */
inline size_t vector_size(const fossil_vector_t* vector) {
    return fossil_vector_size(vector);
}

/**
 * Get the capacity of the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector for which to get the capacity.
 * @return       The capacity of the vector.
 */
inline size_t vector_capacity(const fossil_vector_t* vector) {
    return fossil_vector_capacity(vector);
}

/**
 * Get the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the element.
 * @param index  The index of the element to get.
 * @return       The element at the specified index.
 */
inline std::string vector_get(const fossil_vector_t* vector, size_t index) {
    return std::string(fossil_vector_get(vector, index));
}

/**
 * Search for an element in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector in which to search for the element.
 * @param element The element to search for.
 * @return        0 if the element was found, -1 otherwise.
 */
inline int vector_algorithm_search(const fossil_vector_t* vector, const std::string& element) {
    return fossil_vector_algorithm_search(vector, const_cast<char*>(element.c_str()));
}

/**
 * Sort the elements in the vector.
 * 
 * Time complexity: O(n log n)
 *
 * @param vector The vector to sort.
 * @return       0 if the vector was sorted, -1 otherwise.
 */
inline int vector_algorithm_sort(fossil_vector_t* vector) {
    return fossil_vector_algorithm_sort(vector);
}

/**
 * Reverse the elements in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to reverse.
 * @return       0 if the vector was reversed, -1 otherwise.
 */
inline int vector_algorithm_reverse(fossil_vector_t* vector) {
    return fossil_vector_algorithm_reverse(vector);
}


}

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
