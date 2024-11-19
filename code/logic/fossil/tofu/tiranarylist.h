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
#ifndef FOSSIL_TOFU_TIRANARYLIST_H
#define FOSSIL_TOFU_TIRANARYLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the tiranary linked list
typedef struct fossil_tlist_node_t {
    fossil_tofu_t data;
    struct fossil_tlist_node_t* prev;
    struct fossil_tlist_node_t* next;
    struct fossil_tlist_node_t* third;
} fossil_tlist_node_t;

// Tiranary linked list structure
typedef struct fossil_tlist_t {
    fossil_tlist_node_t* head;
    fossil_tlist_node_t* tail;
    char* type;
} fossil_tlist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new tiranary linked list with the specified data type.
 *
 * @param list_type The type of data the tiranary linked list will store.
 * @return          The created tiranary linked list.
 * @note            Time complexity: O(1)
 */
fossil_tlist_t* fossil_tlist_create_container(char* type);

/**
 * Create a new tiranary linked list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created tiranary linked list.
 */
fossil_tlist_t* fossil_tlist_create_default(void);

/**
 * Create a new tiranary linked list by copying an existing list.
 * 
 * Time complexity: O(n)
 *
 * @param other The tiranary linked list to copy.
 * @return      The created tiranary linked list.
 */
fossil_tlist_t* fossil_tlist_create_copy(const fossil_tlist_t* other);

/**
 * Create a new tiranary linked list by moving an existing list.
 * 
 * Time complexity: O(1)
 *
 * @param other The tiranary linked list to move.
 * @return      The created tiranary linked list.
 */
fossil_tlist_t* fossil_tlist_create_move(fossil_tlist_t* other);

/**
 * Erase the contents of the tiranary linked list and fossil_tofu_free allocated memory.
 *
 * @param tlist The tiranary linked list to erase.
 * @note        Time complexity: O(n)
 */
void fossil_tlist_destroy(fossil_tlist_t* tlist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the tiranary linked list.
 *
 * @param tlist The tiranary linked list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_tlist_insert(fossil_tlist_t* tlist, char *data);

/**
 * Remove data from the tiranary linked list.
 *
 * @param tlist The tiranary linked list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_tlist_remove(fossil_tlist_t* tlist);

/**
 * Reverse the tiranary linked list in the forward direction.
 *
 * @param tlist The tiranary linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_tlist_reverse_forward(fossil_tlist_t* tlist);

/**
 * Reverse the tiranary linked list in the backward direction.
 *
 * @param tlist The tiranary linked list to reverse.
 * @note        Time complexity: O(n)
 */
void fossil_tlist_reverse_backward(fossil_tlist_t* tlist);

/**
 * Get the size of the tiranary linked list.
 *
 * @param tlist The tiranary linked list for which to get the size.
 * @return      The size of the tiranary linked list.
 * @note        Time complexity: O(n)
 */
size_t fossil_tlist_size(const fossil_tlist_t* tlist);

/**
 * Check if the tiranary linked list is not empty.
 *
 * @param tlist The tiranary linked list to check.
 * @return      True if the tiranary linked list is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_tlist_not_empty(const fossil_tlist_t* tlist);

/**
 * Check if the tiranary linked list is not a null pointer.
 *
 * @param tlist The tiranary linked list to check.
 * @return      True if the tiranary linked list is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_tlist_not_cnullptr(const fossil_tlist_t* tlist);

/**
 * Check if the tiranary linked list is empty.
 *
 * @param tlist The tiranary linked list to check.
 * @return      True if the tiranary linked list is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_tlist_is_empty(const fossil_tlist_t* tlist);

/**
 * Check if the tiranary linked list is a null pointer.
 *
 * @param tlist The tiranary linked list to check.
 * @return      True if the tiranary linked list is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_tlist_is_cnullptr(const fossil_tlist_t* tlist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the tiranary linked list.
 * 
 * Time complexity: O(n)
 *
 * @param tlist The tiranary linked list from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_tlist_get(const fossil_tlist_t* tlist, size_t index);

/**
 * Get the first element in the tiranary linked list.
 * 
 * Time complexity: O(1)
 *
 * @param tlist The tiranary linked list from which to get the first element.
 * @return      The first element in the tiranary linked list.
 */
char *fossil_tlist_get_front(const fossil_tlist_t* tlist);

/**
 * Get the last element in the tiranary linked list.
 * 
 * Time complexity: O(1)
 *
 * @param tlist The tiranary linked list from which to get the last element.
 * @return      The last element in the tiranary linked list.
 */
char *fossil_tlist_get_back(const fossil_tlist_t* tlist);

/**
 * Set the element at the specified index in the tiranary linked list.
 * 
 * Time complexity: O(n)
 *
 * @param tlist   The tiranary linked list in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_tlist_set(fossil_tlist_t* tlist, size_t index, char *element);

/**
 * Set the first element in the tiranary linked list.
 * 
 * Time complexity: O(1)
 *
 * @param tlist   The tiranary linked list in which to set the first element.
 * @param element The element to set.
 */
void fossil_tlist_set_front(fossil_tlist_t* tlist, char *element);

/**
 * Set the last element in the tiranary linked list.
 * 
 * Time complexity: O(1)
 *
 * @param tlist   The tiranary linked list in which to set the last element.
 * @param element The element to set.
 */
void fossil_tlist_set_back(fossil_tlist_t* tlist, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

/**
 * @brief A tiranary linked list.
 * 
 * @tparam T The type of data the tiranary linked list will store.
 */
template <typename T>
class TList {
public:
    /**
     * @brief Default constructor.
     */
    TList() : head(nullptr), tail(nullptr) {}

    /**
     * @brief Destructor.
     */
    ~TList() {
        clear();
    }

    /**
     * @brief Insert data into the tiranary linked list.
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
     * @brief Remove data from the tiranary linked list.
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
     * @brief Get the element at the specified index in the tiranary linked list.
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
     * @brief Get the first element in the tiranary linked list.
     * @note Time complexity: O(1)
     */
    T get_front() const {
        if (!head) {
            throw std::underflow_error("List is empty");
        }
        return head->data;
    }

    /**
     * @brief Get the last element in the tiranary linked list.
     * @note Time complexity: O(1)
     */
    T get_back() const {
        if (!tail) {
            throw std::underflow_error("List is empty");
        }
        return tail->data;
    }

    /**
     * @brief Clear the tiranary linked list.
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
     * @brief Get the size of the tiranary linked list.
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
     * @brief Check if the tiranary linked list is not empty.
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
        Node* third;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr), third(nullptr) {}
    };

    Node* head;
    Node* tail;
};

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
