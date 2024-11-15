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
#ifndef FOSSIL_TOFU_PQUEUE_H
#define FOSSIL_TOFU_PQUEUE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

typedef struct fossil_pqueue_node_t {
    fossil_tofu_t data;
    int32_t priority;
    struct fossil_pqueue_node_t* next;
} fossil_pqueue_node_t;

typedef struct fossil_pqueue_t {
    fossil_pqueue_node_t* front;
    char* type;
} fossil_pqueue_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new priority queue with the specified data type.
 *
 * @param queue_type The type of data the priority queue will store.
 * @return           The created priority queue.
 * @note             Time complexity: O(1)
 */
fossil_pqueue_t* fossil_pqueue_create_container(char* type);

/**
 * Erase the contents of the priority queue and fossil_tofu_free allocated memory.
 *
 * @param pqueue The priority queue to erase.
 * @note         Time complexity: O(n)
 */
void fossil_pqueue_destroy(fossil_pqueue_t* pqueue);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue to insert data into.
 * @param data     The data to insert.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(n)
 */
int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, char *data, int32_t priority);

/**
 * Remove data from the priority queue.
 *
 * @param pqueue   The priority queue to remove data from.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(1)
 */
int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, int32_t priority);

/**
 * Get the size of the priority queue.
 *
 * @param pqueue The priority queue for which to get the size.
 * @return       The size of the priority queue.
 * @note         Time complexity: O(1)
 */
size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is not empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is not a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
