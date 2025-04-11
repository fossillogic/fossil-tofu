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
#include <stdexcept>
#include <string>

namespace fossil {

namespace tofu {

    class Queue {
    public:
        /**
         * Create a new queue with the specified data type.
         *
         * @param type The type of data the queue will store.
         */
        Queue(const std::string& type) {
            queue = fossil_queue_create_container(const_cast<char*>(type.c_str()));
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create queue.");
            }
        }

        /**
         * Create a new queue with default values.
         */
        Queue() {
            queue = fossil_queue_create_default();
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create queue.");
            }
        }

        /**
         * Create a new queue by copying an existing queue.
         *
         * @param other The queue to copy.
         */
        Queue(const Queue& other) {
            queue = fossil_queue_create_copy(other.queue);
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create queue.");
            }
        }

        /**
         * Create a new queue by moving an existing queue.
         *
         * @param other The queue to move.
         */
        Queue(Queue&& other) noexcept {
            queue = fossil_queue_create_move(other.queue);
            other.queue = nullptr;
        }

        /**
         * Destroy the queue and fossil_tofu_free allocated memory.
         */
        ~Queue() {
            fossil_queue_destroy(queue);
        }

        /**
         * Insert data into the queue.
         *
         * @param data The data to insert.
         * @return     The error code indicating the success or failure of the operation.
         */
        int32_t insert(const std::string& data) {
            return fossil_queue_insert(queue, const_cast<char*>(data.c_str()));
        }

        /**
         * Remove data from the queue.
         *
         * @return The error code indicating the success or failure of the operation.
         */
        int32_t remove() {
            return fossil_queue_remove(queue);
        }

        /**
         * Get the size of the queue.
         *
         * @return The size of the queue.
         */
        size_t size() const {
            return fossil_queue_size(queue);
        }

        /**
         * Check if the queue is not empty.
         *
         * @return True if the queue is not empty, false otherwise.
         */
        bool not_empty() const {
            return fossil_queue_not_empty(queue);
        }

        /**
         * Check if the queue is not a null pointer.
         *
         * @return True if the queue is not a null pointer, false otherwise.
         */
        bool not_cnullptr() const {
            return fossil_queue_not_cnullptr(queue);
        }

        /**
         * Check if the queue is empty.
         *
         * @return True if the queue is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_queue_is_empty(queue);
        }

        /**
         * Check if the queue is a null pointer.
         *
         * @return True if the queue is a null pointer, false otherwise.
         */
        bool is_cnullptr() const {
            return fossil_queue_is_cnullptr(queue);
        }

        /**
         * Get the element at the front of the queue.
         *
         * @return The element at the front of the queue.
         */
        std::string get_front() const {
            char* front = fossil_queue_get_front(queue);
            return front ? std::string(front) : std::string();
        }

        /**
         * Get the element at the rear of the queue.
         *
         * @return The element at the rear of the queue.
         */
        std::string get_rear() const {
            char* rear = fossil_queue_get_rear(queue);
            return rear ? std::string(rear) : std::string();
        }

        /**
         * Set the element at the front of the queue.
         *
         * @param element The element to set at the front.
         */
        void set_front(const std::string& element) {
            fossil_queue_set_front(queue, const_cast<char*>(element.c_str()));
        }

        /**
         * Set the element at the rear of the queue.
         *
         * @param element The element to set at the rear.
         */
        void set_rear(const std::string& element) {
            fossil_queue_set_rear(queue, const_cast<char*>(element.c_str()));
        }

    private:
        fossil_queue_t* queue;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
