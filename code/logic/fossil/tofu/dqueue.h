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

/**
 * @brief A double-ended queue (deque) data structure.
 * 
 * A double-ended queue is a data structure that allows elements to be inserted
 * and removed from both the front and back of the queue. This implementation
 * uses a doubly linked list to store the elements.
 * 
 * @tparam T The type of elements stored in the queue.
 */
template <typename T>
class DQueue {
public:
    /**
     * @brief Default constructor.
     * 
     * @note Time complexity: O(1)
     */
    DQueue() : front(nullptr), rear(nullptr), size(0) {}

    /**
     * @brief Destructor.
     * 
     * @note Time complexity: O(n)
     */
    ~DQueue() {
        while (!isEmpty()) {
            remove();
        }
    }

    /**
     * @brief Insert an element at the back of the queue.
     * 
     * Time complexity: O(1)
     *
     * @param data The element to insert.
     */
    void insert(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        ++size;
    }

    /**
     * @brief Remove the element at the front of the queue.
     * 
     * Time complexity: O(1)
     */
    void remove() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        Node* temp = front;
        front = front->next;
        if (front) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }
        delete temp;
        --size;
    }

    /**
     * @brief Get the size of the queue.
     * 
     * Time complexity: O(1)
     *
     * @return The size of the queue.
     */
    T get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = front;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    /**
     * @brief Get the first element in the queue.
     * 
     * Time complexity: O(1)
     *
     * @return The first element in the queue.
     */
    T getFront() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return front->data;
    }

    /**
     * @brief Get the last element in the queue.
     * 
     * Time complexity: O(1)
     *
     * @return The last element in the queue.
     */
    T getBack() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return rear->data;
    }

    /**
     * @brief Set the element at the specified index in the queue.
     * 
     * Time complexity: O(n)
     *
     * @param index The index at which to set the element.
     * @param data  The element to set.
     */
    void set(size_t index, const T& data) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = front;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        current->data = data;
    }

    /**
     * @brief Set the first element in the queue.
     * 
     * Time complexity: O(1)
     *
     * @param data The element to set.
     */
    void setFront(const T& data) {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        front->data = data;
    }

    /**
     * @brief Set the last element in the queue.
     * 
     * Time complexity: O(1)
     *
     * @param data The element to set.
     */
    void setBack(const T& data) {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        rear->data = data;
    }

    /**
     * @brief Clear all elements from the queue.
     * 
     * Time complexity: O(n)
     */
    size_t getSize() const {
        return size;
    }

    /**
     * @brief Check if the queue is empty.
     * 
     * Time complexity: O(1)
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const {
        return size == 0;
    }

private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    size_t size;
};

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
