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
#ifndef FOSSIL_TOFU_FORWARDLIST_H
#define FOSSIL_TOFU_FORWARDLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the linked list
typedef struct fossil_flist_node_t {
    fossil_tofu_t data;
    struct fossil_flist_node_t* next;
} fossil_flist_node_t;

// Linked list structure
typedef struct fossil_flist_t {
    fossil_flist_node_t* head;
    char* type;
} fossil_flist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new forward list with the specified data type.
 *
 * @param list_type The type of data the forward list will store.
 * @return          The created forward list.
 * @complexity      O(1)
 */
fossil_flist_t* fossil_flist_create_container(char* type);

/**
 * Create a new forward list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created forward list.
 */
fossil_flist_t* fossil_flist_create_default(void);

/**
 * Create a new forward list by copying an existing forward list.
 * 
 * Time complexity: O(n)
 *
 * @param other The forward list to copy.
 * @return      The created forward list.
 */
fossil_flist_t* fossil_flist_create_copy(const fossil_flist_t* other);

/**
 * Create a new forward list by moving an existing forward list.
 * 
 * Time complexity: O(1)
 *
 * @param other The forward list to move.
 * @return      The created forward list.
 */
fossil_flist_t* fossil_flist_create_move(fossil_flist_t* other);

/**
 * Erase the contents of the forward list and fossil_tofu_free allocated memory.
 *
 * @param flist The forward list to erase.
 * @complexity  O(n)
 */
void fossil_flist_destroy(fossil_flist_t* flist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the forward list.
 *
 * @param flist The forward list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(1)
 */
int32_t fossil_flist_insert(fossil_flist_t* flist, char *data);

/**
 * Remove data from the forward list.
 *
 * @param flist The forward list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(1)
 */
int32_t fossil_flist_remove(fossil_flist_t* flist);

/**
 * Reverse the forward list in the forward direction.
 *
 * @param flist The forward list to reverse.
 * @complexity  O(n)
 */
void fossil_flist_reverse_forward(fossil_flist_t* flist);

/**
 * Reverse the forward list in the backward direction.
 *
 * @param flist The forward list to reverse.
 * @complexity  O(n)
 */
void fossil_flist_reverse_backward(fossil_flist_t* flist);

/**
 * Get the size of the forward list.
 *
 * @param flist The forward list for which to get the size.
 * @return      The size of the forward list.
 * @complexity  O(n)
 */
size_t fossil_flist_size(const fossil_flist_t* flist);

/**
 * Check if the forward list is not empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_not_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is not a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_not_cnullptr(const fossil_flist_t* flist);

/**
 * Check if the forward list is empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_is_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_is_cnullptr(const fossil_flist_t* flist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist The forward list from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_flist_get(const fossil_flist_t* flist, size_t index);

/**
 * Get the first element in the forward list.
 * 
 * Time complexity: O(1)
 *
 * @param flist The forward list from which to get the first element.
 * @return      The first element in the forward list.
 */
char *fossil_flist_get_front(const fossil_flist_t* flist);

/**
 * Get the last element in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist The forward list from which to get the last element.
 * @return      The last element in the forward list.
 */
char *fossil_flist_get_back(const fossil_flist_t* flist);

/**
 * Set the element at the specified index in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist   The forward list in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_flist_set(fossil_flist_t* flist, size_t index, char *element);

/**
 * Set the first element in the forward list.
 * 
 * Time complexity: O(1)
 *
 * @param flist   The forward list in which to set the first element.
 * @param element The element to set.
 */
void fossil_flist_set_front(fossil_flist_t* flist, char *element);

/**
 * Set the last element in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist   The forward list in which to set the last element.
 * @param element The element to set.
 */
void fossil_flist_set_back(fossil_flist_t* flist, char *element);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
