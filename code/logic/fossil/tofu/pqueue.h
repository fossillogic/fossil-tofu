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

typedef struct fossil_pqueue_node_t {
    fossil_tofu_t data;
    int32_t priority;
    struct fossil_pqueue_node_t* next;
} fossil_pqueue_node_t;

typedef struct fossil_pqueue_t {
    fossil_pqueue_node_t* front;
    char* type;
} fossil_pqueue_t;

/**
 * Create a new priority queue with the specified data type.
 *
 * @param queue_type The type of data the priority queue will store.
 * @return           The created priority queue.
 * @note             Time complexity: O(1)
 */
fossil_pqueue_t* fossil_pqueue_create(char* type);

/**
 * Erase the contents of the priority queue and free allocated memory.
 *
 * @param pqueue The priority queue to erase.
 * @note         Time complexity: O(n)
 */
void fossil_pqueue_erase(fossil_pqueue_t* pqueue);

/**
 * Insert data into the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue to insert data into.
 * @param data     The data to insert.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(n)
 */
int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority);

/**
 * Remove data from the priority queue.
 *
 * @param pqueue   The priority queue to remove data from.
 * @param data     The data to remove.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(1)
 */
int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, fossil_tofu_t* data, int32_t priority);

/**
 * Search for data in the priority queue.
 *
 * @param pqueue   The priority queue to search.
 * @param data     The data to search for.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(n)
 */
int32_t fossil_pqueue_search(const fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority);

/**
 * Get the size of the priority queue.
 *
 * @param pqueue The priority queue for which to get the size.
 * @return       The size of the priority queue.
 * @note         Time complexity: O(1)
 */
size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue);

/**
 * Get the data from the priority queue matching the specified data and priority.
 *
 * @param pqueue   The priority queue from which to get the data.
 * @param data     The data to search for.
 * @param priority The priority of the data.
 * @return         A pointer to the matching data, or NULL if not found.
 * @note           Time complexity: O(n)
 */
fossil_tofu_t* fossil_pqueue_getter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority);

/**
 * Set data in the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue in which to set the data.
 * @param data     The data to set.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(n)
 */
int32_t fossil_pqueue_setter(fossil_pqueue_t* pqueue, fossil_tofu_t data, int32_t priority);

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

#ifdef __cplusplus

#include <string>

namespace fossil {
    class PQueue {
    public:
        PQueue(const std::string& type) : pqueue_(fossil_pqueue_create(const_cast<char*>(type.c_str()))) {}

        ~PQueue() {
            fossil_pqueue_erase(pqueue_);
        }

        void insert(fossil_tofu_t data, int32_t priority) {
            fossil_pqueue_insert(pqueue_, data, priority);
        }

        fossil_tofu_t remove() {
            fossil_tofu_t data;
            fossil_pqueue_remove(pqueue_, &data, 0);
            return data;
        }

        bool search(fossil_tofu_t data, int32_t priority) {
            return fossil_pqueue_search(pqueue_, data, priority) == 0;
        }

        size_t size() {
            return fossil_pqueue_size(pqueue_);
        }

        fossil_tofu_t* getter(fossil_tofu_t data, int32_t priority) {
            return fossil_pqueue_getter(pqueue_, data, priority);
        }

        void setter(fossil_tofu_t data, int32_t priority) {
            fossil_pqueue_setter(pqueue_, data, priority);
        }

        bool not_empty() {
            return fossil_pqueue_not_empty(pqueue_);
        }

        bool not_cnullptr() {
            return fossil_pqueue_not_cnullptr(pqueue_);
        }

        bool is_empty() {
            return fossil_pqueue_is_empty(pqueue_);
        }

        bool is_cnullptr() {
            return fossil_pqueue_is_cnullptr(pqueue_);
        }

    private:
        fossil_pqueue_t* pqueue_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
