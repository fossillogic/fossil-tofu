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
#ifndef FOSSIL_TOFU_SETOF_H
#define FOSSIL_TOFU_SETOF_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the set
typedef struct fossil_set_node_t {
    fossil_tofu_t data;
    struct fossil_set_node_t* next;
} fossil_set_node_t;

// Set structure
typedef struct fossil_set_t {
    fossil_set_node_t* head;
    char* type;
} fossil_set_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new set with the specified data type.
 *
 * @param list_type The type of data the set will store.
 * @return          The created set.
 * @note            O(1) - Constant time complexity.
 */
fossil_set_t* fossil_set_create_container(char* type);

/**
 * Create a new set with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created set.
 */
fossil_set_t* fossil_set_create_default(void);

/**
 * Create a new set by copying an existing set.
 * 
 * Time complexity: O(n)
 *
 * @param other The set to copy.
 * @return      The created set.
 */
fossil_set_t* fossil_set_create_copy(const fossil_set_t* other);

/**
 * Create a new set by moving an existing set.
 * 
 * Time complexity: O(1)
 *
 * @param other The set to move.
 * @return      The created set.
 */
fossil_set_t* fossil_set_create_move(fossil_set_t* other);

/**
 * Erase the contents of the set and fossil_tofu_free allocated memory.
 *
 * @param set The set to erase.
 * @note      O(n) - Linear time complexity, where n is the number of elements in the set.
 */
void fossil_set_destroy(fossil_set_t* set);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the set.
 *
 * @param set  The set to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 * @note       O(1) - Constant time complexity.
 */
int32_t fossil_set_insert(fossil_set_t* set, char *data);

/**
 * Remove data from the set.
 *
 * @param set  The set to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 * @note       O(n) - Linear time complexity, where n is the number of elements in the set.
 */
void fossil_set_erase(fossil_set_t *set);

/**
 * Get the size of the set.
 *
 * @param set The set for which to get the size.
 * @return    The size of the set.
 * @note      O(n) - Linear time complexity, where n is the number of elements in the set.
 */
size_t fossil_set_size(const fossil_set_t* set);

/**
 * Check if the set is not empty.
 *
 * @param set The set to check.
 * @return    True if the set is not empty, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_not_empty(const fossil_set_t* set);

/**
 * Check if the set is not a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is not a null pointer, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_not_cnullptr(const fossil_set_t* set);

/**
 * Check if the set is empty.
 *
 * @param set The set to check.
 * @return    True if the set is empty, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_is_empty(const fossil_set_t* set);

/**
 * Check if the set is a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is a null pointer, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_is_cnullptr(const fossil_set_t* set);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set   The set from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_set_get(const fossil_set_t* set, size_t index);

/**
 * Get the first element in the set.
 * 
 * Time complexity: O(1)
 *
 * @param set The set from which to get the first element.
 * @return    The first element in the set.
 */
char *fossil_set_get_front(const fossil_set_t* set);

/**
 * Get the last element in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set The set from which to get the last element.
 * @return    The last element in the set.
 */
char *fossil_set_get_back(const fossil_set_t* set);

/**
 * Set the element at the specified index in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set     The set in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_set_set(fossil_set_t* set, size_t index, char *element);

/**
 * Set the first element in the set.
 * 
 * Time complexity: O(1)
 *
 * @param set     The set in which to set the first element.
 * @param element The element to set.
 */
void fossil_set_set_front(fossil_set_t* set, char *element);

/**
 * Set the last element in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set     The set in which to set the last element.
 * @param element The element to set.
 */
void fossil_set_set_back(fossil_set_t* set, char *element);

#ifdef __cplusplus
}

namespace fossil {

/**
 * Create a new set with the specified data type.
 *
 * @param list_type The type of data the set will store.
 * @return          The created set.
 * @note            O(1) - Constant time complexity.
 */
inline fossil_set_t* set_create_container(const std::string& type) {
    return fossil_set_create_container(const_cast<char*>(type.c_str()));
}

/**
 * Create a new set with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created set.
 */
inline fossil_set_t* set_create_default() {
    return fossil_set_create_default();
}

/**
 * Create a new set by copying an existing set.
 * 
 * Time complexity: O(n)
 *
 * @param other The set to copy.
 * @return      The created set.
 */
inline fossil_set_t* set_create_copy(const fossil_set_t* other) {
    return fossil_set_create_copy(other);
}

/**
 * Create a new set by moving an existing set.
 * 
 * Time complexity: O(1)
 *
 * @param other The set to move.
 * @return      The created set.
 */
inline fossil_set_t* set_create_move(fossil_set_t* other) {
    return fossil_set_create_move(other);
}

/**
 * Erase the contents of the set and fossil_tofu_free allocated memory.
 *
 * @param set The set to erase.
 * @note      O(n) - Linear time complexity, where n is the number of elements in the set.
 */
inline void set_destroy(fossil_set_t* set) {
    fossil_set_destroy(set);
}

/**
 * Insert data into the set.
 *
 * @param set  The set to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 * @note       O(1) - Constant time complexity.
 */
inline int32_t set_insert(fossil_set_t* set, const std::string& data) {
    return fossil_set_insert(set, const_cast<char*>(data.c_str()));
}

/**
 * Remove data from the set.
 *
 * @param set  The set to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 * @note       O(n) - Linear time complexity, where n is the number of elements in the set.
 */
inline void set_erase(fossil_set_t *set) {
    fossil_set_erase(set);
}

/**
 * Get the size of the set.
 *
 * @param set The set for which to get the size.
 * @return    The size of the set.
 * @note      O(n) - Linear time complexity, where n is the number of elements in the set.
 */
inline size_t set_size(const fossil_set_t* set) {
    return fossil_set_size(set);
}

/**
 * Check if the set is not empty.
 *
 * @param set The set to check.
 * @return    True if the set is not empty, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
inline bool set_not_empty(const fossil_set_t* set) {
    return fossil_set_not_empty(set);
}

/**
 * Check if the set is not a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is not a null pointer, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
inline bool set_not_cnullptr(const fossil_set_t* set) {
    return fossil_set_not_cnullptr(set);
}

/**
 * Check if the set is empty.
 *
 * @param set The set to check.
 * @return    True if the set is empty, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
inline bool set_is_empty(const fossil_set_t* set) {
    return fossil_set_is_empty(set);
}

/**
 * Check if the set is a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is a null pointer, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
inline bool set_is_cnullptr(const fossil_set_t* set) {
    return fossil_set_is_cnullptr(set);
}

/**
 * Get the element at the specified index in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set   The set from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
inline std::string set_get(const fossil_set_t* set, size_t index) {
    return std::string(fossil_set_get(set, index));
}

/**
 * Get the first element in the set.
 * 
 * Time complexity: O(1)
 *
 * @param set The set from which to get the first element.
 * @return    The first element in the set.
 */
inline std::string set_get_front(const fossil_set_t* set) {
    return std::string(fossil_set_get_front(set));
}

/**
 * Get the last element in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set The set from which to get the last element.
 * @return    The last element in the set.
 */
inline std::string set_get_back(const fossil_set_t* set) {
    return std::string(fossil_set_get_back(set));
}

/**
 * Set the element at the specified index in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set     The set in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
inline void set_set(fossil_set_t* set, size_t index, const std::string& element) {
    fossil_set_set(set, index, const_cast<char*>(element.c_str()));
}

/**
 * Set the first element in the set.
 * 
 * Time complexity: O(1)
 *
 * @param set     The set in which to set the first element.
 * @param element The element to set.
 */
inline void set_set_front(fossil_set_t* set, const std::string& element) {
    fossil_set_set_front(set, const_cast<char*>(element.c_str()));
}

/**
 * Set the last element in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set     The set in which to set the last element.
 * @param element The element to set.
 */
inline void set_set_back(fossil_set_t* set, const std::string& element) {
    fossil_set_set_back(set, const_cast<char*>(element.c_str()));
}

}

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
