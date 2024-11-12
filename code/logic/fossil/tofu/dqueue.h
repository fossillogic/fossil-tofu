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

/**
 * Create a new dynamic queue with the specified data type.
 *
 * @param list_type The type of data the dynamic queue will store.
 * @return          The created dynamic queue.
 * @note            Time complexity: O(1)
 */
fossil_dqueue_t* fossil_dqueue_create_container(char* type);

/**
 * Create a new dynamic queue with the specified data type and initial capacity.
 *
 * @param list_type The type of data the dynamic queue will store.
 * @param size      The initial capacity of the dynamic queue.
 * @return          The created dynamic queue.
 * @note            Time complexity: O(1)
 */
fossil_dqueue_t* fossil_dqueue_create_with(char* type, size_t size, ...);

/**
 * Erase the contents of the dynamic queue and free allocated memory.
 *
 * @param dqueue The dynamic queue to erase.
 * @note         Time complexity: O(n)
 */
void fossil_dqueue_destroy(fossil_dqueue_t* dqueue);

/**
 * Insert data into the dynamic queue.
 *
 * @param dqueue The dynamic queue to insert data into.
 * @param data   The data to insert.
 * @return       The error code indicating the success or failure of the operation.
 * @note         Time complexity: O(1)
 */
int32_t fossil_dqueue_insert(fossil_dqueue_t* dqueue, fossil_tofu_t data);

/**
 * Remove data from the dynamic queue.
 *
 * @param dqueue The dynamic queue to remove data from.
 * @param data   A pointer to store the removed data.
 * @return       The error code indicating the success or failure of the operation.
 * @note         Time complexity: O(1)
 */
int32_t fossil_dqueue_remove(fossil_dqueue_t* dqueue, fossil_tofu_t* data);

/**
 * Search for data in the dynamic queue.
 *
 * @param dqueue The dynamic queue to search.
 * @param data   The data to search for.
 * @return       The error code indicating the success or failure of the operation.
 * @note         Time complexity: O(n)
 */
int32_t fossil_dqueue_search(const fossil_dqueue_t* dqueue, fossil_tofu_t data);

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
    class DQueue {
    public:
        DQueue(const std::string& type) : dqueue_(fossil_dqueue_create_container(const_cast<char*>(type.c_str()))) {}

        ~DQueue() {
            fossil_dqueue_destroy(dqueue_);
        }

        void insert(fossil_tofu_t data) {
            fossil_dqueue_insert(dqueue_, data);
        }

        fossil_tofu_t remove() {
            fossil_tofu_t data;
            fossil_dqueue_remove(dqueue_, &data);
            return data;
        }

        int search(fossil_tofu_t data) {
            return fossil_dqueue_search(dqueue_, data);
        }

        size_t size() {
            return fossil_dqueue_size(dqueue_);
        }

        bool not_empty() {
            return fossil_dqueue_not_empty(dqueue_);
        }

        bool not_cnullptr() {
            return fossil_dqueue_not_cnullptr(dqueue_);
        }

        bool is_empty() {
            return fossil_dqueue_is_empty(dqueue_);
        }

        bool is_cnullptr() {
            return fossil_dqueue_is_cnullptr(dqueue_);
        }

    private:
        fossil_dqueue_t* dqueue_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
