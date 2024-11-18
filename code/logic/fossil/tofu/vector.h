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
 * Create a new vector with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created vector.
 */
fossil_vector_t* fossil_vector_create_default(void);

/**
 * Create a new vector by copying an existing vector.
 * 
 * Time complexity: O(n)
 *
 * @param other The vector to copy.
 * @return      The created vector.
 */
fossil_vector_t* fossil_vector_create_copy(const fossil_vector_t* other);

/**
 * Create a new vector by moving an existing vector.
 * 
 * Time complexity: O(1)
 *
 * @param other The vector to move.
 * @return      The created vector.
 */
fossil_vector_t* fossil_vector_create_move(fossil_vector_t* other);

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

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

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

/**
 * Get the first element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the first element.
 * @return       The first element in the vector.
 */
char *fossil_vector_get_front(const fossil_vector_t* vector);

/**
 * Get the last element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the last element.
 * @return       The last element in the vector.
 */
char *fossil_vector_get_back(const fossil_vector_t* vector);

/**
 * Get the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the element.
 * @param index  The index of the element to get.
 * @return       The element at the specified index.
 */
char *fossil_vector_get_at(const fossil_vector_t* vector, size_t index);

/**
 * Set the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_vector_set(fossil_vector_t* vector, size_t index, char *element);

/**
 * Set the first element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the first element.
 * @param element The element to set.
 */
void fossil_vector_set_front(fossil_vector_t* vector, char *element);

/**
 * Set the last element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the last element.
 * @param element The element to set.
 */
void fossil_vector_set_back(fossil_vector_t* vector, char *element);

/**
 * Set the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_vector_set_at(fossil_vector_t* vector, size_t index, char *element);

#ifdef __cplusplus
}
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
 * Create a new vector with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created vector.
 */
inline fossil_vector_t* vector_create_default() {
    return fossil_vector_create_default();
}

/**
 * Create a new vector by copying an existing vector.
 * 
 * Time complexity: O(n)
 *
 * @param other The vector to copy.
 * @return      The created vector.
 */
inline fossil_vector_t* vector_create_copy(const fossil_vector_t* other) {
    return fossil_vector_create_copy(other);
}

/**
 * Create a new vector by moving an existing vector.
 * 
 * Time complexity: O(1)
 *
 * @param other The vector to move.
 * @return      The created vector.
 */
inline fossil_vector_t* vector_create_move(fossil_vector_t* other) {
    return fossil_vector_create_move(other);
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
 * Get the first element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the first element.
 * @return       The first element in the vector.
 */
inline std::string vector_get_front(const fossil_vector_t* vector) {
    return std::string(fossil_vector_get_front(vector));
}

/**
 * Get the last element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the last element.
 * @return       The last element in the vector.
 */
inline std::string vector_get_back(const fossil_vector_t* vector) {
    return std::string(fossil_vector_get_back(vector));
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
inline std::string vector_get_at(const fossil_vector_t* vector, size_t index) {
    return std::string(fossil_vector_get_at(vector, index));
}

/**
 * Set the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
inline void vector_set(fossil_vector_t* vector, size_t index, const std::string& element) {
    fossil_vector_set(vector, index, const_cast<char*>(element.c_str()));
}

/**
 * Set the first element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the first element.
 * @param element The element to set.
 */
inline void vector_set_front(fossil_vector_t* vector, const std::string& element) {
    fossil_vector_set_front(vector, const_cast<char*>(element.c_str()));
}

/**
 * Set the last element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the last element.
 * @param element The element to set.
 */
inline void vector_set_back(fossil_vector_t* vector, const std::string& element) {
    fossil_vector_set_back(vector, const_cast<char*>(element.c_str()));
}

/**
 * Set the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
inline void vector_set_at(fossil_vector_t* vector, size_t index, const std::string& element) {
    fossil_vector_set_at(vector, index, const_cast<char*>(element.c_str()));
}

}

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
