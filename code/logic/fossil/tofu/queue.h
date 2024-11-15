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
// Algorithm functions
// *****************************************************************************

/**
 * Search for an element in the queue.
 *
 * @param queue   The queue to search in.
 * @param element The element to search for.
 * @return        The index of the element if found, or -1 if not found.
 * @note          Time complexity: O(n)
 */
int fossil_queue_algorithm_search(fossil_queue_t* queue, char *element);

/**
 * Sort the queue in ascending order.
 *
 * @param queue The queue to sort.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n^2)
 */
int fossil_queue_algorithm_sort(fossil_queue_t* queue);

/**
 * Reverse the order of the elements in the queue.
 *
 * @param queue The queue to reverse.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n)
 */
int fossil_queue_algorithm_reverse(fossil_queue_t* queue);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <string>

namespace fossil {

/**
 * Create a new queue with the specified data type.
 *
 * @param type The type of data the queue will store.
 * @return     The created queue.
 * @note       Time complexity: O(1)
 */
fossil_queue_t *queue_create_container(const std::string &type) {
    return fossil_queue_create_container(const_cast<char *>(type.c_str()));
}

/**
 * Erase the contents of the queue and free allocated memory.
 *
 * @param queue The queue to erase.
 * @note        Time complexity: O(n)
 */
void queue_destroy(fossil_queue_t *queue) {
    fossil_queue_destroy(queue);
}

/**
 * Insert data into the queue.
 *
 * @param queue The queue to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t queue_insert(fossil_queue_t *queue, const std::string &data) {
    return fossil_queue_insert(queue, const_cast<char *>(data.c_str()));
}

/**
 * Remove data from the queue.
 *
 * @param queue The queue to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t queue_remove(fossil_queue_t *queue) {
    return fossil_queue_remove(queue);
}

/**
 * Get the size of the queue.
 *
 * @param queue The queue for which to get the size.
 * @return      The size of the queue.
 * @note        Time complexity: O(n)
 */
size_t queue_size(const fossil_queue_t *queue) {
    return fossil_queue_size(queue);
}

/**
 * Check if the queue is not empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool queue_not_empty(const fossil_queue_t *queue) {
    return fossil_queue_not_empty(queue);
}

/**
 * Check if the queue is not a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool queue_not_cnullptr(const fossil_queue_t *queue) {
    return fossil_queue_not_cnullptr(queue);
}

/**
 * Check if the queue is empty.
 *
 * @param queue The queue to check.
 * @return      True if the queue is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool queue_is_empty(const fossil_queue_t *queue) {
    return fossil_queue_is_empty(queue);
}

/**
 * Check if the queue is a null pointer.
 *
 * @param queue The queue to check.
 * @return      True if the queue is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool queue_is_cnullptr(const fossil_queue_t *queue) {
    return fossil_queue_is_cnullptr(queue);
}

/**
 * Search for an element in the queue.
 *
 * @param queue   The queue to search in.
 * @param element The element to search for.
 * @return        The index of the element if found, or -1 if not found.
 * @note          Time complexity: O(n)
 */
int queue_algorithm_search(fossil_queue_t *queue, const std::string &element) {
    return fossil_queue_algorithm_search(queue, const_cast<char *>(element.c_str()));
}

/**
 * Sort the queue in ascending order.
 *
 * @param queue The queue to sort.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n^2)
 */
int queue_algorithm_sort(fossil_queue_t *queue) {
    return fossil_queue_algorithm_sort(queue);
}

/**
 * Reverse the order of the elements in the queue.
 *
 * @param queue The queue to reverse.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(n)
 */
int queue_algorithm_reverse(fossil_queue_t *queue) {
    return fossil_queue_algorithm_reverse(queue);
}

}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
