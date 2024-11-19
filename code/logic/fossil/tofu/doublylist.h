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
#ifndef FOSSIL_TOFU_DOUBLYLIST_H
#define FOSSIL_TOFU_DOUBLYLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the doubly linked list
typedef struct fossil_dlist_node_t {
    fossil_tofu_t data;
    struct fossil_dlist_node_t* prev;
    struct fossil_dlist_node_t* next;
} fossil_dlist_node_t;

// Doubly linked list structure
typedef struct fossil_dlist_t {
    fossil_dlist_node_t* head;
    fossil_dlist_node_t* tail;
    char* type;
} fossil_dlist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new doubly linked list with the specified data type.
 *
 * @param list_type The type of data the doubly linked list will store.
 * @return          The created doubly linked list.
 * @note            Time complexity: O(1)
 */
fossil_dlist_t* fossil_dlist_create_container(char* type);

/**
 * Create a new doubly linked list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created doubly linked list.
 */
fossil_dlist_t* fossil_dlist_create_default(void);

/**
 * Create a new doubly linked list by copying an existing list.
 * 
 * Time complexity: O(n)
 *
 * @param other The doubly linked list to copy.
 * @return      The created doubly linked list.
 */
fossil_dlist_t* fossil_dlist_create_copy(const fossil_dlist_t* other);

/**
 * Create a new doubly linked list by moving an existing list.
 * 
 * Time complexity: O(1)
 *
 * @param other The doubly linked list to move.
 * @return      The created doubly linked list.
 */
fossil_dlist_t* fossil_dlist_create_move(fossil_dlist_t* other);

/**
 * Erase the contents of the doubly linked list and fossil_tofu_free allocated memory.
 *
 * @param dlist The doubly linked list to erase.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_destroy(fossil_dlist_t* dlist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the doubly linked list.
 *
 * @param dlist The doubly linked list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_dlist_insert(fossil_dlist_t* dlist, char *data);

/**
 * Remove data from the doubly linked list.
 *
 * @param dlist The doubly linked list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_dlist_remove(fossil_dlist_t* dlist);

/**
 * Reverse the doubly linked list in the forward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_reverse_forward(fossil_dlist_t* dlist);

/**
 * Reverse the doubly linked list in the backward direction.
 *
 * @param dlist The doubly linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_dlist_reverse_backward(fossil_dlist_t* dlist);

/**
 * Get the size of the doubly linked list.
 *
 * @param dlist The doubly linked list for which to get the size.
 * @return      The size of the doubly linked list.
 * @note        Time complexity: O(n)
 */
size_t fossil_dlist_size(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is not empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_not_empty(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is not a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is empty.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_is_empty(const fossil_dlist_t* dlist);

/**
 * Check if the doubly linked list is a null pointer.
 *
 * @param dlist The doubly linked list to check.
 * @return      True if the doubly linked list is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the doubly linked list.
 * 
 * Time complexity: O(n)
 *
 * @param dlist The doubly linked list from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_dlist_get(const fossil_dlist_t* dlist, size_t index);

/**
 * Get the first element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist The doubly linked list from which to get the first element.
 * @return      The first element in the doubly linked list.
 */
char *fossil_dlist_get_front(const fossil_dlist_t* dlist);

/**
 * Get the last element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist The doubly linked list from which to get the last element.
 * @return      The last element in the doubly linked list.
 */
char *fossil_dlist_get_back(const fossil_dlist_t* dlist);

/**
 * Set the element at the specified index in the doubly linked list.
 * 
 * Time complexity: O(n)
 *
 * @param dlist   The doubly linked list in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_dlist_set(fossil_dlist_t* dlist, size_t index, char *element);

/**
 * Set the first element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist   The doubly linked list in which to set the first element.
 * @param element The element to set.
 */
void fossil_dlist_set_front(fossil_dlist_t* dlist, char *element);

/**
 * Set the last element in the doubly linked list.
 * 
 * Time complexity: O(1)
 *
 * @param dlist   The doubly linked list in which to set the last element.
 * @param element The element to set.
 */
void fossil_dlist_set_back(fossil_dlist_t* dlist, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

/**
 * @brief A doubly linked list.
 * 
 * @tparam T The type of data the doubly linked list will store.
 */
template <typename T>
class DList {
public:
    /**
     * @brief Default constructor.
     */
    DList() : head(nullptr), tail(nullptr) {}

    /**
     * @brief Destructor.
     */
    ~DList() {
        clear();
    }

    /**
     * @brief Insert data into the doubly linked list.
     * 
     * @param data The data to insert.
     * @note Time complexity: O(1)
     */
    void insert(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /**
     * @brief Remove data from the doubly linked list.
     * @note Time complexity: O(1)
     */
    void remove() {
        if (!tail) {
            throw std::underflow_error("List is empty");
        }
        Node* toDelete = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete toDelete;
    }

    /**
     * @brief Reverse the doubly linked list in the forward direction.
     * @note Time complexity: O(n)
     */
    T get(size_t index) const {
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            if (!current) {
                throw std::out_of_range("Index out of range");
            }
            current = current->next;
        }
        if (!current) {
            throw std::out_of_range("Index out of range");
        }
        return current->data;
    }

    /**
     * @brief Get the first element in the doubly linked list.
     * @note Time complexity: O(1)
     */
    T get_front() const {
        if (!head) {
            throw std::underflow_error("List is empty");
        }
        return head->data;
    }

    /**
     * @brief Get the last element in the doubly linked list.
     * @note Time complexity: O(1)
     */
    T get_back() const {
        if (!tail) {
            throw std::underflow_error("List is empty");
        }
        return tail->data;
    }

    /**
     * @brief Set the element at the specified index in the doubly linked list.
     * @note Time complexity: O(n)
     */
    void clear() {
        while (head) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        tail = nullptr;
    }

    /**
     * @brief Get the size of the doubly linked list.
     * @note Time complexity: O(n)
     */
    size_t size() const {
        size_t count = 0;
        Node* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    /**
     * @brief Check if the doubly linked list is not empty.
     * @note Time complexity: O(1)
     */
    bool is_empty() const {
        return head == nullptr;
    }

private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
};

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
