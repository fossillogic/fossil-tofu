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
#ifndef FOSSIL_TOFU_CQUEUE_H
#define FOSSIL_TOFU_CQUEUE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the circular queue
typedef struct fossil_cqueue_node_t {
    fossil_tofu_t data;
    struct fossil_cqueue_node_t* next;
} fossil_cqueue_node_t;

// Circular queue structure
typedef struct fossil_cqueue_t {
    fossil_cqueue_node_t* front;
    fossil_cqueue_node_t* rear;
    char* type;
    size_t capacity;
    size_t size;
} fossil_cqueue_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new circular queue with the specified data type and capacity.
 *
 * @param type     The type of data the queue will store.
 * @param capacity The maximum number of elements the queue can hold.
 * @return         The created circular queue.
 * @note           Time complexity: O(1)
 */
fossil_cqueue_t* fossil_cqueue_create_container(char* type, size_t capacity);

/**
 * Create a new circular queue with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created circular queue.
 */
fossil_cqueue_t* fossil_cqueue_create_default(void);

/**
 * Create a new circular queue by copying an existing queue.
 * 
 * Time complexity: O(n)
 *
 * @param other The circular queue to copy.
 * @return      The created circular queue.
 */
fossil_cqueue_t* fossil_cqueue_create_copy(const fossil_cqueue_t* other);

/**
 * Create a new circular queue by moving an existing queue.
 * 
 * Time complexity: O(1)
 *
 * @param other The circular queue to move.
 * @return      The created circular queue.
 */
fossil_cqueue_t* fossil_cqueue_create_move(fossil_cqueue_t* other);

/**
 * Erase the contents of the circular queue and free allocated memory.
 *
 * @param queue The circular queue to erase.
 * @note        Time complexity: O(n)
 */
void fossil_cqueue_destroy(fossil_cqueue_t* queue);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the circular queue.
 *
 * @param queue The circular queue to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_cqueue_insert(fossil_cqueue_t* queue, char *data);

/**
 * Remove data from the circular queue.
 *
 * @param queue The circular queue to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_cqueue_remove(fossil_cqueue_t* queue);

/**
 * Get the size of the circular queue.
 *
 * @param queue The circular queue for which to get the size.
 * @return      The size of the circular queue.
 * @note        Time complexity: O(1)
 */
size_t fossil_cqueue_size(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is not empty.
 *
 * @param queue The circular queue to check.
 * @return      True if the circular queue is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_cqueue_not_empty(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is not a null pointer.
 *
 * @param queue The circular queue to check.
 * @return      True if the circular queue is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_cqueue_not_cnullptr(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is empty.
 *
 * @param queue The circular queue to check.
 * @return      True if the circular queue is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_cqueue_is_empty(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is a null pointer.
 *
 * @param queue The circular queue to check.
 * @return      True if the circular queue is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_cqueue_is_cnullptr(const fossil_cqueue_t* queue);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the front of the circular queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue The circular queue from which to get the front element.
 * @return      The element at the front of the circular queue.
 */
char *fossil_cqueue_get_front(const fossil_cqueue_t* queue);

/**
 * Get the element at the rear of the circular queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue The circular queue from which to get the rear element.
 * @return      The element at the rear of the circular queue.
 */
char *fossil_cqueue_get_rear(const fossil_cqueue_t* queue);

/**
 * Set the element at the front of the circular queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue   The circular queue in which to set the front element.
 * @param element The element to set at the front.
 */
void fossil_cqueue_set_front(fossil_cqueue_t* queue, char *element);

/**
 * Set the element at the rear of the circular queue.
 * 
 * Time complexity: O(1)
 *
 * @param queue   The circular queue in which to set the rear element.
 * @param element The element to set at the rear.
 */
void fossil_cqueue_set_rear(fossil_cqueue_t* queue, char *element);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {

namespace tofu {

    class CQueue {
    public:
        /**
         * Create a new circular queue with the specified data type.
         *
         * @param type The type of data the queue will store.
         * @param capacity The maximum number of elements the queue can hold.
         */
        CQueue(const std::string& type, size_t capacity) {
            queue = fossil_cqueue_create_container(const_cast<char*>(type.c_str()), capacity);
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create circular queue.");
            }
        }

        /**
         * Create a new circular queue with default values.
         */
        CQueue() {
            queue = fossil_cqueue_create_default();
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create circular queue.");
            }
        }

        /**
         * Create a new circular queue by copying an existing queue.
         *
         * @param other The queue to copy.
         */
        CQueue(const CQueue& other) {
            queue = fossil_cqueue_create_copy(other.queue);
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create circular queue.");
            }
        }

        /**
         * Create a new circular queue by moving an existing queue.
         *
         * @param other The queue to move.
         */
        CQueue(CQueue&& other) noexcept {
            queue = fossil_cqueue_create_move(other.queue);
        }

        /**
         * Destroy the circular queue and free allocated memory.
         */
        ~CQueue() {
            fossil_cqueue_destroy(queue);
        }

        /**
         * Insert data into the circular queue.
         *
         * @param data The data to insert.
         * @return     The error code indicating the success or failure of the operation.
         */
        int32_t insert(const std::string& data) {
            return fossil_cqueue_insert(queue, const_cast<char*>(data.c_str()));
        }

        /**
         * Remove data from the circular queue.
         *
         * @return The error code indicating the success or failure of the operation.
         */
        int32_t remove() {
            return fossil_cqueue_remove(queue);
        }

        /**
         * Get the size of the circular queue.
         *
         * @return The size of the circular queue.
         */
        size_t size() const {
            return fossil_cqueue_size(queue);
        }

        /**
         * Check if the circular queue is not empty.
         *
         * @return True if the circular queue is not empty, false otherwise.
         */
        bool not_empty() const {
            return fossil_cqueue_not_empty(queue);
        }

        /**
         * Check if the circular queue is not a null pointer.
         *
         * @return True if the circular queue is not a null pointer, false otherwise.
         */
        bool not_cnullptr() const {
            return fossil_cqueue_not_cnullptr(queue);
        }

        /**
         * Check if the circular queue is empty.
         *
         * @return True if the circular queue is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_cqueue_is_empty(queue);
        }

        /**
         * Check if the circular queue is a null pointer.
         *
         * @return True if the circular queue is a null pointer, false otherwise.
         */
        bool is_cnullptr() const {
            return fossil_cqueue_is_cnullptr(queue);
        }

        /**
         * Get the element at the front of the circular queue.
         *
         * @return The element at the front of the circular queue as std::string.
         */
        std::string get_front() const {
            char* result = fossil_cqueue_get_front(queue);
            return result ? std::string(result) : std::string();
        }

        /**
         * Get the element at the rear of the circular queue.
         *
         * @return The element at the rear of the circular queue as std::string.
         */
        std::string get_rear() const {
            char* result = fossil_cqueue_get_rear(queue);
            return result ? std::string(result) : std::string();
        }

        /**
         * Set the element at the front of the circular queue.
         *
         * @param element The element to set at the front as std::string.
         */
        void set_front(const std::string& element) {
            fossil_cqueue_set_front(queue, const_cast<char*>(element.c_str()));
        }

        /**
         * Set the element at the rear of the circular queue.
         *
         * @param element The element to set at the rear as std::string.
         */
        void set_rear(const std::string& element) {
            fossil_cqueue_set_rear(queue, const_cast<char*>(element.c_str()));
        }

        /**
         * Get the type of data the circular queue stores.
         *
         * @return The type as std::string.
         */
        std::string type() const {
            return queue && queue->type ? std::string(queue->type) : std::string();
        }

        /**
         * Get the capacity of the circular queue.
         *
         * @return The capacity.
         */
        size_t capacity() const {
            return queue ? queue->capacity : 0;
        }

    private:
        fossil_cqueue_t* queue;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
