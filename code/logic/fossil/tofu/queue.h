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
#ifndef FOSSIL_TOFU_QUEUE_H
#define FOSSIL_TOFU_QUEUE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the queue
typedef struct fossil_queue_node_t {
    fossil_tofu_t data;
    struct fossil_queue_node_t* next;
} fossil_queue_node_t;

// Queue structure
typedef struct fossil_queue_t {
    fossil_queue_node_t* front;
    fossil_queue_node_t* rear;
    char* type;
} fossil_queue_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new queue with the specified data type.
 *
 * @param list_type The type of data the queue will store.
 * @return          The created queue.
 * @note            Time complexity: O(1)
 */
fossil_queue_t* fossil_queue_create_container(char* type);

/**
 * Erase the contents of the queue and free allocated memory.
 *
 * @param queue The queue to erase.
 * @note        Time complexity: O(n)
 */
void fossil_queue_destroy(fossil_queue_t* queue);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the queue.
 *
 * @param queue The queue to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_queue_insert(fossil_queue_t* queue, char *data);

/**
 * Remove data from the queue.
 *
 * @param queue The queue to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_queue_remove(fossil_queue_t* queue);

/**
 * Get the size of the queue.
 *
 * @param queue The queue for which to get the size.
 * @return      The size of the queue.
 * @note        Time complexity: O(n)
 */
size_t fossil_queue_size(const fossil_queue_t* queue);

/**
 * Check if the queue is not empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_queue_not_empty(const fossil_queue_t* queue);

/**
 * Check if the queue is not a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_queue_not_cnullptr(const fossil_queue_t* queue);

/**
 * Check if the queue is empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_queue_is_empty(const fossil_queue_t* queue);

/**
 * Check if the queue is a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_queue_is_cnullptr(const fossil_queue_t* queue);

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
