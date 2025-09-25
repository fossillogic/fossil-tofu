/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
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
 * @param type     The type of data the queue will store as a string.
 * @param capacity The maximum number of elements the queue can hold.
 * @return         Pointer to the created circular queue structure, or NULL on failure.
 * @note           Time complexity: O(1)
 * @details        Allocates memory for a circular queue and initializes its members.
 *                 The queue will be able to store up to 'capacity' elements of the specified type.
 */
fossil_cqueue_t* fossil_cqueue_create_container(char* type, size_t capacity);

/**
 * Create a new circular queue with default values.
 *
 * @return Pointer to the created circular queue structure, or NULL on failure.
 * @note   Time complexity: O(1)
 * @details        Allocates memory for a circular queue and initializes it with default settings.
 *                 The default type and capacity are implementation-defined.
 */
fossil_cqueue_t* fossil_cqueue_create_default(void);

/**
 * Create a new circular queue by copying an existing queue.
 *
 * @param other Pointer to the circular queue to copy.
 * @return      Pointer to the newly created circular queue, or NULL on failure.
 * @note        Time complexity: O(n)
 * @details     Performs a deep copy of the source queue, duplicating all elements and metadata.
 */
fossil_cqueue_t* fossil_cqueue_create_copy(const fossil_cqueue_t* other);

/**
 * Create a new circular queue by moving an existing queue.
 *
 * @param other Pointer to the circular queue to move.
 * @return      Pointer to the newly created circular queue, or NULL on failure.
 * @note        Time complexity: O(1)
 * @details     Transfers ownership of the queue from 'other' to the new queue.
 *              The original queue pointer is invalidated after the move.
 */
fossil_cqueue_t* fossil_cqueue_create_move(fossil_cqueue_t* other);

/**
 * Erase the contents of the circular queue and free allocated memory.
 *
 * @param queue Pointer to the circular queue to erase.
 * @note        Time complexity: O(n)
 * @details     Frees all memory associated with the queue, including all nodes and metadata.
 *              After calling this function, the queue pointer should not be used.
 */
void fossil_cqueue_destroy(fossil_cqueue_t* queue);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the circular queue.
 *
 * @param queue Pointer to the circular queue to insert data into.
 * @param data  Pointer to the data to insert as a string.
 * @return      Error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 * @details     Adds the specified data to the rear of the queue.
 *              Returns 0 on success, or a negative error code on failure (e.g., if the queue is full).
 */
int32_t fossil_cqueue_insert(fossil_cqueue_t* queue, char *data);

/**
 * Remove data from the circular queue.
 *
 * @param queue Pointer to the circular queue to remove data from.
 * @return      Error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 * @details     Removes the front element from the queue.
 *              Returns 0 on success, or a negative error code on failure (e.g., if the queue is empty).
 */
int32_t fossil_cqueue_remove(fossil_cqueue_t* queue);

/**
 * Get the size of the circular queue.
 *
 * @param queue Pointer to the circular queue for which to get the size.
 * @return      The number of elements currently stored in the queue.
 * @note        Time complexity: O(1)
 * @details     Returns the current number of elements in the queue.
 */
size_t fossil_cqueue_size(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is not empty.
 *
 * @param queue Pointer to the circular queue to check.
 * @return      True if the circular queue contains at least one element, false otherwise.
 * @note        Time complexity: O(1)
 * @details     Returns true if the queue has elements, false if it is empty or invalid.
 */
bool fossil_cqueue_not_empty(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is not a null pointer.
 *
 * @param queue Pointer to the circular queue to check.
 * @return      True if the queue pointer is valid, false otherwise.
 * @note        Time complexity: O(1)
 * @details     Returns true if the queue pointer is not NULL.
 */
bool fossil_cqueue_not_cnullptr(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is empty.
 *
 * @param queue Pointer to the circular queue to check.
 * @return      True if the circular queue contains no elements, false otherwise.
 * @note        Time complexity: O(1)
 * @details     Returns true if the queue has no elements.
 */
bool fossil_cqueue_is_empty(const fossil_cqueue_t* queue);

/**
 * Check if the circular queue is a null pointer.
 *
 * @param queue Pointer to the circular queue to check.
 * @return      True if the queue pointer is NULL, false otherwise.
 * @note        Time complexity: O(1)
 * @details     Returns true if the queue pointer is NULL.
 */
bool fossil_cqueue_is_cnullptr(const fossil_cqueue_t* queue);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the front of the circular queue.
 *
 * @param queue Pointer to the circular queue from which to get the front element.
 * @return      Pointer to the element at the front of the queue as a string, or NULL if empty.
 * @note        Time complexity: O(1)
 * @details     Returns the front element of the queue without removing it.
 */
char *fossil_cqueue_get_front(const fossil_cqueue_t* queue);

/**
 * Get the element at the rear of the circular queue.
 *
 * @param queue Pointer to the circular queue from which to get the rear element.
 * @return      Pointer to the element at the rear of the queue as a string, or NULL if empty.
 * @note        Time complexity: O(1)
 * @details     Returns the rear element of the queue without removing it.
 */
char *fossil_cqueue_get_rear(const fossil_cqueue_t* queue);

/**
 * Set the element at the front of the circular queue.
 *
 * @param queue   Pointer to the circular queue in which to set the front element.
 * @param element Pointer to the element to set at the front as a string.
 * @note         Time complexity: O(1)
 * @details      Overwrites the front element of the queue with the specified value.
 */
void fossil_cqueue_set_front(fossil_cqueue_t* queue, char *element);

/**
 * Set the element at the rear of the circular queue.
 *
 * @param queue   Pointer to the circular queue in which to set the rear element.
 * @param element Pointer to the element to set at the rear as a string.
 * @note         Time complexity: O(1)
 * @details      Overwrites the rear element of the queue with the specified value.
 */
void fossil_cqueue_set_rear(fossil_cqueue_t* queue, char *element);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {

    namespace tofu {

        /**
         * @class CQueue
         * @brief C++ wrapper for the Fossil circular queue (cqueue).
         *
         * Provides a convenient and type-safe interface for managing a circular queue
         * using the underlying C implementation. Supports construction, destruction,
         * copy/move semantics, and queue operations such as insert, remove, and accessors.
         */
        class CQueue {
        public:
            /**
             * @brief Create a new circular queue with the specified data type and capacity.
             *
             * @param type     The type of data the queue will store as a string.
             * @param capacity The maximum number of elements the queue can hold.
             * @throws std::runtime_error If the queue creation fails.
             *
             * Allocates and initializes a circular queue for the given type and capacity.
             */
            CQueue(const std::string& type, size_t capacity) {
            queue = fossil_cqueue_create_container(const_cast<char*>(type.c_str()), capacity);
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create circular queue.");
            }
            }

            /**
             * @brief Create a new circular queue with default values.
             *
             * @throws std::runtime_error If the queue creation fails.
             *
             * Allocates and initializes a circular queue with implementation-defined defaults.
             */
            CQueue() {
            queue = fossil_cqueue_create_default();
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create circular queue.");
            }
            }

            /**
             * @brief Copy constructor. Creates a new circular queue by copying an existing queue.
             *
             * @param other The queue to copy.
             * @throws std::runtime_error If the queue copy fails.
             *
             * Performs a deep copy of the source queue, duplicating all elements and metadata.
             */
            CQueue(const CQueue& other) {
            queue = fossil_cqueue_create_copy(other.queue);
            if (queue == nullptr) {
                throw std::runtime_error("Failed to create circular queue.");
            }
            }

            /**
             * @brief Move constructor. Creates a new circular queue by moving an existing queue.
             *
             * @param other The queue to move.
             *
             * Transfers ownership of the queue from 'other' to the new queue.
             * The original queue pointer in 'other' is invalidated.
             */
            CQueue(CQueue&& other) noexcept {
            queue = fossil_cqueue_create_move(other.queue);
            }

            /**
             * @brief Destructor. Destroys the circular queue and frees allocated memory.
             *
             * Frees all memory associated with the queue, including all nodes and metadata.
             */
            ~CQueue() {
            fossil_cqueue_destroy(queue);
            }

            /**
             * @brief Insert data into the circular queue.
             *
             * @param data The data to insert as a std::string.
             * @return     Error code indicating the success or failure of the operation.
             *
             * Adds the specified data to the rear of the queue.
             * Returns 0 on success, or a negative error code on failure (e.g., if the queue is full).
             */
            int32_t insert(const std::string& data) {
            return fossil_cqueue_insert(queue, const_cast<char*>(data.c_str()));
            }

            /**
             * @brief Remove data from the circular queue.
             *
             * @return Error code indicating the success or failure of the operation.
             *
             * Removes the front element from the queue.
             * Returns 0 on success, or a negative error code on failure (e.g., if the queue is empty).
             */
            int32_t remove() {
            return fossil_cqueue_remove(queue);
            }

            /**
             * @brief Get the size of the circular queue.
             *
             * @return The number of elements currently stored in the queue.
             *
             * Returns the current number of elements in the queue.
             */
            size_t size() const {
            return fossil_cqueue_size(queue);
            }

            /**
             * @brief Check if the circular queue is not empty.
             *
             * @return True if the circular queue contains at least one element, false otherwise.
             *
             * Returns true if the queue has elements, false if it is empty or invalid.
             */
            bool not_empty() const {
            return fossil_cqueue_not_empty(queue);
            }

            /**
             * @brief Check if the circular queue is not a null pointer.
             *
             * @return True if the queue pointer is valid, false otherwise.
             *
             * Returns true if the queue pointer is not NULL.
             */
            bool not_cnullptr() const {
            return fossil_cqueue_not_cnullptr(queue);
            }

            /**
             * @brief Check if the circular queue is empty.
             *
             * @return True if the circular queue contains no elements, false otherwise.
             *
             * Returns true if the queue has no elements.
             */
            bool is_empty() const {
            return fossil_cqueue_is_empty(queue);
            }

            /**
             * @brief Check if the circular queue is a null pointer.
             *
             * @return True if the queue pointer is NULL, false otherwise.
             *
             * Returns true if the queue pointer is NULL.
             */
            bool is_cnullptr() const {
            return fossil_cqueue_is_cnullptr(queue);
            }

            /**
             * @brief Get the element at the front of the circular queue.
             *
             * @return The element at the front of the queue as std::string, or empty if none.
             *
             * Returns the front element of the queue without removing it.
             */
            std::string get_front() const {
            char* result = fossil_cqueue_get_front(queue);
            return result ? std::string(result) : std::string();
            }

            /**
             * @brief Get the element at the rear of the circular queue.
             *
             * @return The element at the rear of the queue as std::string, or empty if none.
             *
             * Returns the rear element of the queue without removing it.
             */
            std::string get_rear() const {
            char* result = fossil_cqueue_get_rear(queue);
            return result ? std::string(result) : std::string();
            }

            /**
             * @brief Set the element at the front of the circular queue.
             *
             * @param element The element to set at the front as std::string.
             *
             * Overwrites the front element of the queue with the specified value.
             */
            void set_front(const std::string& element) {
            fossil_cqueue_set_front(queue, const_cast<char*>(element.c_str()));
            }

            /**
             * @brief Set the element at the rear of the circular queue.
             *
             * @param element The element to set at the rear as std::string.
             *
             * Overwrites the rear element of the queue with the specified value.
             */
            void set_rear(const std::string& element) {
            fossil_cqueue_set_rear(queue, const_cast<char*>(element.c_str()));
            }

            /**
             * @brief Get the type of data the circular queue stores.
             *
             * @return The type as std::string, or empty if not set.
             *
             * Returns the type string associated with the queue.
             */
            std::string type() const {
            return queue && queue->type ? std::string(queue->type) : std::string();
            }

            /**
             * @brief Get the capacity of the circular queue.
             *
             * @return The maximum number of elements the queue can hold.
             *
             * Returns the capacity value of the queue.
             */
            size_t capacity() const {
            return queue ? queue->capacity : 0;
            }

        private:
            /**
             * @brief Pointer to the underlying C circular queue structure.
             */
            fossil_cqueue_t* queue;
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
