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

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

/**
 * Create a new forward list with the specified data type.
 *
 * @param type The type of data the forward list will store.
 * @return     The created forward list.
 */
fossil_flist_t *flist_create_container(const std::string &type) {
    return fossil_flist_create_container(const_cast<char *>(type.c_str()));
}

/**
 * Erase the contents of the forward list and free allocated memory.
 *
 * @param flist The forward list to erase.
 */
void flist_destroy(fossil_flist_t *flist) {
    fossil_flist_destroy(flist);
}

/**
 * Insert data into the forward list.
 *
 * @param flist The forward list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 */
int32_t flist_insert(fossil_flist_t *flist, const std::string &data) {
    return fossil_flist_insert(flist, const_cast<char *>(data.c_str()));
}

/**
 * Remove data from the forward list.
 *
 * @param flist The forward list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 */
int32_t flist_remove(fossil_flist_t *flist) {
    return fossil_flist_remove(flist);
}

/**
 * Reverse the forward list in the forward direction.
 *
 * @param flist The forward list to reverse.
 */
void flist_reverse_forward(fossil_flist_t *flist) {
    fossil_flist_reverse_forward(flist);
}

/**
 * Reverse the forward list in the backward direction.
 *
 * @param flist The forward list to reverse.
 */
void flist_reverse_backward(fossil_flist_t *flist) {
    fossil_flist_reverse_backward(flist);
}

/**
 * Get the size of the forward list.
 *
 * @param flist The forward list for which to get the size.
 * @return      The size of the forward list.
 */
size_t flist_size(const fossil_flist_t *flist) {
    return fossil_flist_size(flist);
}

/**
 * Check if the forward list is not empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not empty, false otherwise.
 */
bool flist_not_empty(const fossil_flist_t *flist) {
    return fossil_flist_not_empty(flist);
}

/**
 * Check if the forward list is not a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not a null pointer, false otherwise.
 */
bool flist_not_cnullptr(const fossil_flist_t *flist) {
    return fossil_flist_not_cnullptr(flist);
}

/**
 * Check if the forward list is empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is empty, false otherwise.
 */
bool flist_is_empty(const fossil_flist_t *flist) {
    return fossil_flist_is_empty(flist);
}

/**
 * Check if the forward list is a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is a null pointer, false otherwise.
 */
bool flist_is_cnullptr(const fossil_flist_t *flist) {
    return fossil_flist_is_cnullptr(flist);
}

}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
