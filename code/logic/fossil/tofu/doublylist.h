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
#ifndef FOSSIL_TOFU_DOUBLYLIST_H
#define FOSSIL_TOFU_DOUBLYLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the doubly linked list
typedef struct fossil_dlist_node_t {
    fossil_tofu_t data;
    struct fossil_dlist_node_t* prev;
    struct fossil_dlist_node_t* next;
} fossil_dlist_node_t;

// Doubly linked list structure
typedef struct fossil_dlist_t {
    fossil_dlist_node_t* head;
    fossil_dlist_node_t* tail;
    char* type;
} fossil_dlist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new doubly linked list with the specified data type.
 *
 * @param list_type The type of data the doubly linked list will store.
 * @return          The created doubly linked list.
 * @note            Time complexity: O(1)
 */
fossil_dlist_t* fossil_dlist_create_container(char* type);

/**
 * Erase the contents of the doubly linked list and fossil_tofu_free allocated memory.
 *
 * @param dlist The doubly linked list to erase.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_destroy(fossil_dlist_t* dlist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the doubly linked list.
 *
 * @param dlist The doubly linked list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_dlist_insert(fossil_dlist_t* dlist, char *data);

/**
 * Remove data from the doubly linked list.
 *
 * @param dlist The doubly linked list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_dlist_remove(fossil_dlist_t* dlist);

/**
 * Reverse the doubly linked list in the forward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_reverse_forward(fossil_dlist_t* dlist);

/**
 * Reverse the doubly linked list in the backward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_reverse_backward(fossil_dlist_t* dlist);

/**
 * Get the size of the doubly linked list.
 *
 * @param dlist The doubly linked list for which to get the size.
 * @return      The size of the doubly linked list.
 * @note        Time complexity: O(n)
 */
size_t fossil_dlist_size(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is not empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_not_empty(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is not a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_is_empty(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

/**
 * Create a new doubly linked list with the specified data type.
 *
 * @param type The type of data the doubly linked list will store.
 * @return     The created doubly linked list.
 * @note       Time complexity: O(1)
 */
fossil_dlist_t *dlist_create_container(char *type) {
    return fossil_dlist_create_container(type);
}

/**
 * Erase the contents of the doubly linked list and fossil_tofu_free allocated memory.
 *
 * @param dlist The doubly linked list to erase.
 * @note        Time complexity: O(n)
 */
void dlist_destroy(fossil_dlist_t* dlist) {
    fossil_dlist_destroy(dlist);
}

/**
 * Insert data into the doubly linked list.
 *
 * @param dlist The doubly linked list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t dlist_insert(fossil_dlist_t* dlist, char *data) {
    return fossil_dlist_insert(dlist, data);
}

/**
 * Remove data from the doubly linked list.
 *
 * @param dlist The doubly linked list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t dlist_remove(fossil_dlist_t* dlist) {
    return fossil_dlist_remove(dlist);
}

/**
 * Reverse the doubly linked list in the forward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void dlist_reverse_forward(fossil_dlist_t* dlist) {
    fossil_dlist_reverse_forward(dlist);
}

/**
 * Reverse the doubly linked list in the backward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void dlist_reverse_backward(fossil_dlist_t* dlist) {
    fossil_dlist_reverse_backward(dlist);
}

/**
 * Get the size of the doubly linked list.
 *
 * @param dlist The doubly linked list for which to get the size.
 * @return      The size of the doubly linked list.
 * @note        Time complexity: O(n)
 */
size_t dlist_size(const fossil_dlist_t* dlist) {
    return fossil_dlist_size(dlist);
}

/**
 * Check if the doubly linked list is not empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool dlist_not_empty(const fossil_dlist_t* dlist) {
    return fossil_dlist_not_empty(dlist);
}

/**
 * Check if the doubly linked list is not a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool dlist_not_cnullptr(const fossil_dlist_t* dlist) {
    return fossil_dlist_not_cnullptr(dlist);
}

/**
 * Check if the doubly linked list is empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool dlist_is_empty(const fossil_dlist_t* dlist) {
    return fossil_dlist_is_empty(dlist);
}

/**
 * Check if the doubly linked list is a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool dlist_is_cnullptr(const fossil_dlist_t* dlist) {
    return fossil_dlist_is_cnullptr(dlist);
}

}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
