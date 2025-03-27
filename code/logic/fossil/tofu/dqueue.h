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
extern "C" {
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
 * Create a new double-ended queue with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created double-ended queue.
 */
fossil_dqueue_t* fossil_dqueue_create_default(void);

/**
 * Create a new double-ended queue by copying an existing queue.
 * 
 * Time complexity: O(n)
 *
 * @param other The queue to copy.
 * @return      The created double-ended queue.
 */
fossil_dqueue_t* fossil_dqueue_create_copy(const fossil_dqueue_t* other);

/**
 * Create a new double-ended queue by moving an existing queue.
 * 
 * Time complexity: O(1)
 *
 * @param other The queue to move.
 * @return      The created double-ended queue.
 */
fossil_dqueue_t* fossil_dqueue_create_move(fossil_dqueue_t* other);

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

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the double-ended queue.
 * 
 * Time complexity: O(n)
 *
 * @param dqueue The double-ended queue from which to get the element.
 * @param index  The index of the element to get.
 * @return       The element at the specified index.
 */
char *fossil_dqueue_get(const fossil_dqueue_t* dqueue, size_t index);

/**
 * Get the first element in the double-ended queue.
 * 
 * Time complexity: O(1)
 *
 * @param dqueue The double-ended queue from which to get the first element.
 * @return       The first element in the double-ended queue.
 */
char *fossil_dqueue_get_front(const fossil_dqueue_t* dqueue);

/**
 * Get the last element in the double-ended queue.
 * 
 * Time complexity: O(1)
 *
 * @param dqueue The double-ended queue from which to get the last element.
 * @return       The last element in the double-ended queue.
 */
char *fossil_dqueue_get_back(const fossil_dqueue_t* dqueue);

/**
 * Set the element at the specified index in the double-ended queue.
 * 
 * Time complexity: O(n)
 *
 * @param dqueue  The double-ended queue in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_dqueue_set(fossil_dqueue_t* dqueue, size_t index, char *element);

/**
 * Set the first element in the double-ended queue.
 * 
 * Time complexity: O(1)
 *
 * @param dqueue  The double-ended queue in which to set the first element.
 * @param element The element to set.
 */
void fossil_dqueue_set_front(fossil_dqueue_t* dqueue, char *element);

/**
 * Set the last element in the double-ended queue.
 * 
 * Time complexity: O(1)
 *
 * @param dqueue  The double-ended queue in which to set the last element.
 * @param element The element to set.
 */
void fossil_dqueue_set_back(fossil_dqueue_t* dqueue, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

namespace tofu {

    /**
     * A C++ wrapper class for the C-style double-ended queue (fossil_dqueue_t).
     * Provides a more user-friendly interface for managing the queue.
     */
    class DQueue {
    public:
        /**
         * Default constructor.
         * Creates a new double-ended queue with default values.
         * 
         * @throws std::runtime_error if the queue creation fails.
         */
        DQueue() : dqueue(fossil_dqueue_create_default()) {
            if (dqueue == nullptr) {
                throw std::runtime_error("Failed to create a new double-ended queue.");
            }
        }

        /**
         * Copy constructor.
         * Creates a new double-ended queue by copying an existing queue.
         * 
         * @param other The queue to copy.
         * @throws std::runtime_error if the queue copy operation fails.
         */
        DQueue(const DQueue& other) : dqueue(fossil_dqueue_create_copy(other.dqueue)) {
            if (dqueue == nullptr) {
                throw std::runtime_error("Failed to create a new double-ended queue by copying an existing queue.");
            }
        }

        /**
         * Move constructor.
         * Creates a new double-ended queue by moving an existing queue.
         * 
         * @param other The queue to move.
         */
        DQueue(DQueue&& other) noexcept : dqueue(fossil_dqueue_create_move(other.dqueue)) {
            other.dqueue = nullptr;
        }

        /**
         * Destructor.
         * Destroys the double-ended queue and frees allocated memory.
         */
        ~DQueue() {
            fossil_dqueue_destroy(dqueue);
        }

        /**
         * Copy assignment operator.
         * Copies the contents of another queue into this queue.
         * 
         * @param other The queue to copy.
         * @return A reference to this queue.
         * @throws std::runtime_error if the queue copy operation fails.
         */
        DQueue& operator=(const DQueue& other) {
            if (this != &other) {
                fossil_dqueue_destroy(dqueue);
                dqueue = fossil_dqueue_create_copy(other.dqueue);
                if (dqueue == nullptr) {
                    throw std::runtime_error("Failed to create a new double-ended queue by copying an existing queue.");
                }
            }
            return *this;
        }

        /**
         * Move assignment operator.
         * Moves the contents of another queue into this queue.
         * 
         * @param other The queue to move.
         * @return A reference to this queue.
         */
        DQueue& operator=(DQueue&& other) noexcept {
            if (this != &other) {
                fossil_dqueue_destroy(dqueue);
                dqueue = fossil_dqueue_create_move(other.dqueue);
                other.dqueue = nullptr;
            }
            return *this;
        }

        /**
         * Inserts data into the queue.
         * 
         * @param data The data to insert.
         * @throws std::runtime_error if the insertion fails.
         */
        void insert(char *data) {
            if (fossil_dqueue_insert(dqueue, data) != 0) {
                throw std::runtime_error("Failed to insert data into the double-ended queue.");
            }
        }

        /**
         * Removes data from the queue.
         * 
         * @throws std::runtime_error if the removal fails.
         */
        void remove() {
            if (fossil_dqueue_remove(dqueue) != 0) {
                throw std::runtime_error("Failed to remove data from the double-ended queue.");
            }
        }

        /**
         * Gets the size of the queue.
         * 
         * @return The size of the queue.
         */
        size_t size() const {
            return fossil_dqueue_size(dqueue);
        }

        /**
         * Checks if the queue is not empty.
         * 
         * @return True if the queue is not empty, false otherwise.
         */
        bool not_empty() const {
            return fossil_dqueue_not_empty(dqueue);
        }

        /**
         * Checks if the queue is not a null pointer.
         * 
         * @return True if the queue is not a null pointer, false otherwise.
         */
        bool not_cnullptr() const {
            return fossil_dqueue_not_cnullptr(dqueue);
        }

        /**
         * Checks if the queue is empty.
         * 
         * @return True if the queue is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_dqueue_is_empty(dqueue);
        }

        /**
         * Checks if the queue is a null pointer.
         * 
         * @return True if the queue is a null pointer, false otherwise.
         */
        bool is_cnullptr() const {
            return fossil_dqueue_is_cnullptr(dqueue);
        }

        /**
         * Gets the element at the specified index in the queue.
         * 
         * @param index The index of the element to get.
         * @return The element at the specified index.
         */
        char *get(size_t index) const {
            return fossil_dqueue_get(dqueue, index);
        }

        /**
         * Gets the first element in the queue.
         * 
         * @return The first element in the queue.
         */
        char *get_front() const {
            return fossil_dqueue_get_front(dqueue);
        }

        /**
         * Gets the last element in the queue.
         * 
         * @return The last element in the queue.
         */
        char *get_back() const {
            return fossil_dqueue_get_back(dqueue);
        }

        /**
         * Sets the element at the specified index in the queue.
         * 
         * @param index   The index at which to set the element.
         * @param element The element to set.
         */
        void set(size_t index, char *element) {
            fossil_dqueue_set(dqueue, index, element);
        }

        /**
         * Sets the first element in the queue.
         * 
         * @param element The element to set.
         */
        void set_front(char *element) {
            fossil_dqueue_set_front(dqueue, element);
        }

        /**
         * Sets the last element in the queue.
         * 
         * @param element The element to set.
         */
        void set_back(char *element) {
            fossil_dqueue_set_back(dqueue, element);
        }

    private:
        fossil_dqueue_t* dqueue; /**< Pointer to the underlying C-style double-ended queue. */
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
