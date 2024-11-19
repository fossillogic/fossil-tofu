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
 * Create a new queue with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created queue.
 */
fossil_queue_t* fossil_queue_create_default(void);

/**
 * Create a new queue by copying an existing queue.
 * 
 * Time complexity: O(n)
 *
 * @param other The queue to copy.
 * @return      The created queue.
 */
fossil_queue_t* fossil_queue_create_copy(const fossil_queue_t* other);

/**
 * Create a new queue by moving an existing queue.
 * 
 * Time complexity: O(1)
 *
 * @param other The queue to move.
 * @return      The created queue.
 */
fossil_queue_t* fossil_queue_create_move(fossil_queue_t* other);

/**
 * Erase the contents of the queue and fossil_tofu_free allocated memory.
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
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the front of the queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue The queue from which to get the front element.
 * @return      The element at the front of the queue.
 */
char *fossil_queue_get_front(const fossil_queue_t* queue);

/**
 * Get the element at the rear of the queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue The queue from which to get the rear element.
 * @return      The element at the rear of the queue.
 */
char *fossil_queue_get_rear(const fossil_queue_t* queue);

/**
 * Set the element at the front of the queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue   The queue in which to set the front element.
 * @param element The element to set at the front.
 */
void fossil_queue_set_front(fossil_queue_t* queue, char *element);

/**
 * Set the element at the rear of the queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue   The queue in which to set the rear element.
 * @param element The element to set at the rear.
 */
void fossil_queue_set_rear(fossil_queue_t* queue, char *element);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
