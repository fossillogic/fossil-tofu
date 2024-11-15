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
#ifndef FOSSIL_TOFU_DQUEUE_H
#define FOSSIL_TOFU_DQUEUE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the double-ended queue
typedef struct fossil_dqueue_node_t {
    fossil_tofu_t data;
    struct fossil_dqueue_node_t* prev;
    struct fossil_dqueue_node_t* next;
} fossil_dqueue_node_t;

// Double-ended queue structure
typedef struct fossil_dqueue_t {
    fossil_dqueue_node_t* front;
    fossil_dqueue_node_t* rear;
    char *type;
} fossil_dqueue_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new dynamic queue with the specified data type.
 *
 * @param list_type The type of data the dynamic queue will store.
 * @return          The created dynamic queue.
 * @note            Time complexity: O(1)
 */
fossil_dqueue_t* fossil_dqueue_create_container(char* type);

/**
 * Erase the contents of the dynamic queue and fossil_tofu_free allocated memory.
 *
 * @param dqueue The dynamic queue to erase.
 * @note         Time complexity: O(n)
 */
void fossil_dqueue_destroy(fossil_dqueue_t* dqueue);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the dynamic queue.
 *
 * @param dqueue The dynamic queue to insert data into.
 * @param data   The data to insert.
 * @return       The error code indicating the success or failure of the operation.
 * @note         Time complexity: O(1)
 */
int32_t fossil_dqueue_insert(fossil_dqueue_t* dqueue, char *data);

/**
 * Remove data from the dynamic queue.
 *
 * @param dqueue The dynamic queue to remove data from.
 * @return       The error code indicating the success or failure of the operation.
 * @note         Time complexity: O(1)
 */
int32_t fossil_dqueue_remove(fossil_dqueue_t* dqueue);

/**
 * Get the size of the dynamic queue.
 *
 * @param dqueue The dynamic queue for which to get the size.
 * @return       The size of the dynamic queue.
 * @note         Time complexity: O(1)
 */
size_t fossil_dqueue_size(const fossil_dqueue_t* dqueue);

/**
 * Check if the dynamic queue is not empty.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is not empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_dqueue_not_empty(const fossil_dqueue_t* dqueue);

/**
 * Check if the dynamic queue is not a null pointer.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is not a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_dqueue_not_cnullptr(const fossil_dqueue_t* dqueue);

/**
 * Check if the dynamic queue is empty.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_dqueue_is_empty(const fossil_dqueue_t* dqueue);

/**
 * Check if the dynamic queue is a null pointer.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_dqueue_is_cnullptr(const fossil_dqueue_t* dqueue);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

/**
 * Create a new dynamic queue with the specified data type.
 *
 * @param list_type The type of data the dynamic queue will store.
 * @return          The created dynamic queue.
 * @note            Time complexity: O(1)
 */
fossil_dqueue_t *dqueue_create_container(char *type) {
    return fossil_dqueue_create_container(type);
}

/**
 * Erase the contents of the dynamic queue and fossil_tofu_free allocated memory.
 *
 * @param dqueue The dynamic queue to erase.
 * @note         Time complexity: O(n)
 */
void dqueue_destroy(fossil_dqueue_t *dqueue) {
    fossil_dqueue_destroy(dqueue);
}

/**
 * Insert data into the dynamic queue.
 *
 * @param dqueue The dynamic queue to insert data into.
 * @param data   The data to insert.
 * @return       The error code indicating the success or failure of the operation.
 * @note         Time complexity: O(1)
 */
int32_t dqueue_insert(fossil_dqueue_t *dqueue, char *data) {
    return fossil_dqueue_insert(dqueue, data);
}

/**
 * Remove data from the dynamic queue.
 *
 * @param dqueue The dynamic queue to remove data from.
 * @return       The error code indicating the success or failure of the operation.
 * @note         Time complexity: O(1)
 */
int32_t dqueue_remove(fossil_dqueue_t *dqueue) {
    return fossil_dqueue_remove(dqueue);
}

/**
 * Get the size of the dynamic queue.
 *
 * @param dqueue The dynamic queue for which to get the size.
 * @return       The size of the dynamic queue.
 * @note         Time complexity: O(1)
 */
size_t dqueue_size(const fossil_dqueue_t *dqueue) {
    return fossil_dqueue_size(dqueue);
}

/**
 * Check if the dynamic queue is not empty.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is not empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool dqueue_not_empty(const fossil_dqueue_t *dqueue) {
    return fossil_dqueue_not_empty(dqueue);
}

/**
 * Check if the dynamic queue is not a null pointer.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is not a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool dqueue_not_cnullptr(const fossil_dqueue_t *dqueue) {
    return fossil_dqueue_not_cnullptr(dqueue);
}

/**
 * Check if the dynamic queue is empty.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool dqueue_is_empty(const fossil_dqueue_t *dqueue) {
    return fossil_dqueue_is_empty(dqueue);
}

/**
 * Check if the dynamic queue is a null pointer.
 *
 * @param dqueue The dynamic queue to check.
 * @return       True if the dynamic queue is a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool dqueue_is_cnullptr(const fossil_dqueue_t *dqueue) {
    return fossil_dqueue_is_cnullptr(dqueue);
}

}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
