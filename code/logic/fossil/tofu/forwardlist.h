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
#ifndef FOSSIL_TOFU_FORWARDLIST_H
#define FOSSIL_TOFU_FORWARDLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the linked list
typedef struct fossil_flist_node_t {
    fossil_tofu_t data;
    struct fossil_flist_node_t* next;
} fossil_flist_node_t;

// Linked list structure
typedef struct fossil_flist_t {
    fossil_flist_node_t* head;
    char* type;
} fossil_flist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new forward list with the specified data type.
 *
 * @param list_type The type of data the forward list will store.
 * @return          The created forward list.
 * @complexity      O(1)
 */
fossil_flist_t* fossil_flist_create_container(char* type);

/**
 * Create a new forward list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created forward list.
 */
fossil_flist_t* fossil_flist_create_default(void);

/**
 * Create a new forward list by copying an existing forward list.
 * 
 * Time complexity: O(n)
 *
 * @param other The forward list to copy.
 * @return      The created forward list.
 */
fossil_flist_t* fossil_flist_create_copy(const fossil_flist_t* other);

/**
 * Create a new forward list by moving an existing forward list.
 * 
 * Time complexity: O(1)
 *
 * @param other The forward list to move.
 * @return      The created forward list.
 */
fossil_flist_t* fossil_flist_create_move(fossil_flist_t* other);

/**
 * Erase the contents of the forward list and fossil_tofu_free allocated memory.
 *
 * @param flist The forward list to erase.
 * @complexity  O(n)
 */
void fossil_flist_destroy(fossil_flist_t* flist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the forward list.
 *
 * @param flist The forward list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(1)
 */
int32_t fossil_flist_insert(fossil_flist_t* flist, char *data);

/**
 * Remove data from the forward list.
 *
 * @param flist The forward list to remove data from.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(1)
 */
int32_t fossil_flist_remove(fossil_flist_t* flist);

/**
 * Reverse the forward list in the forward direction.
 *
 * @param flist The forward list to reverse.
 * @complexity  O(n)
 */
void fossil_flist_reverse_forward(fossil_flist_t* flist);

/**
 * Reverse the forward list in the backward direction.
 *
 * @param flist The forward list to reverse.
 * @complexity  O(n)
 */
void fossil_flist_reverse_backward(fossil_flist_t* flist);

/**
 * Get the size of the forward list.
 *
 * @param flist The forward list for which to get the size.
 * @return      The size of the forward list.
 * @complexity  O(n)
 */
size_t fossil_flist_size(const fossil_flist_t* flist);

/**
 * Check if the forward list is not empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_not_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is not a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_not_cnullptr(const fossil_flist_t* flist);

/**
 * Check if the forward list is empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_is_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_is_cnullptr(const fossil_flist_t* flist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist The forward list from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_flist_get(const fossil_flist_t* flist, size_t index);

/**
 * Get the first element in the forward list.
 * 
 * Time complexity: O(1)
 *
 * @param flist The forward list from which to get the first element.
 * @return      The first element in the forward list.
 */
char *fossil_flist_get_front(const fossil_flist_t* flist);

/**
 * Get the last element in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist The forward list from which to get the last element.
 * @return      The last element in the forward list.
 */
char *fossil_flist_get_back(const fossil_flist_t* flist);

/**
 * Set the element at the specified index in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist   The forward list in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_flist_set(fossil_flist_t* flist, size_t index, char *element);

/**
 * Set the first element in the forward list.
 * 
 * Time complexity: O(1)
 *
 * @param flist   The forward list in which to set the first element.
 * @param element The element to set.
 */
void fossil_flist_set_front(fossil_flist_t* flist, char *element);

/**
 * Set the last element in the forward list.
 * 
 * Time complexity: O(n)
 *
 * @param flist   The forward list in which to set the last element.
 * @param element The element to set.
 */
void fossil_flist_set_back(fossil_flist_t* flist, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

/**
 * @brief A forward list data structure.
 * 
 * A forward list is a data structure that stores elements in a linear sequence.
 * Elements can be inserted and removed from the front of the list, but not from
 * the back. The forward list does not support random access to elements.
 * 
 * @tparam T The type of data to store in the forward list.
 */
template <typename T>
class ForwardList {
public:
    // Node structure for the linked list
    struct Node {
        T data;
        Node* next;
    };

    /**
     * Default constructor.
     */
    ForwardList() : head(nullptr), type(typeid(T).name()) {}

    /**
     * Destructor.
     */
    ~ForwardList() {
        clear();
    }

    /**
     * Copy constructor.
     */
    ForwardList(const ForwardList& other) : head(nullptr), type(other.type) {
        Node* current = other.head;
        while (current) {
            insert(current->data);
            current = current->next;
        }
    }

    /**
     * Move constructor.
     */
    ForwardList(ForwardList&& other) noexcept : head(other.head), type(other.type) {
        other.head = nullptr;
    }

    /**
     * Copy assignment operator.
     */
    ForwardList& operator=(const ForwardList& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                insert(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    /**
     * Move assignment operator.
     */
    ForwardList& operator=(ForwardList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            type = other.type;
            other.head = nullptr;
        }
        return *this;
    }

    /**
     * Insert data into the forward list.
     *
     * @param data The data to insert.
     */
    void insert(const T& data) {
        Node* newNode = new Node{data, head};
        head = newNode;
    }

    /**
     * Remove data from the forward list.
     */
    void remove() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            throw std::underflow_error("List is empty");
        }
    }

    /**
     * Reverse the forward list in the forward direction.
     */
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    /**
     * Get the size of the forward list.
     * 
     * Time complexity: O(n)
     *
     * @return The size of the forward list.
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
     * Check if the forward list is not empty.
     * 
     * Time complexity: O(1)
     *
     * @return True if the forward list is not empty, false otherwise.
     */
    bool isEmpty() const {
        return head == nullptr;
    }

    /**
     * Get the element at the specified index in the forward list.
     * 
     * Time complexity: O(n)
     *
     * @param index The index of the element to get.
     * @return      The element at the specified index.
     */
    T& get(size_t index) {
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
     * Get the first element in the forward list.
     * 
     * Time complexity: O(1)
     *
     * @return The first element in the forward list.
     */
    T& front() {
        if (!head) {
            throw std::underflow_error("List is empty");
        }
        return head->data;
    }

    /**
     * Get the last element in the forward list.
     * 
     * Time complexity: O(n)
     *
     * @return The last element in the forward list.
     */
    T& back() {
        if (!head) {
            throw std::underflow_error("List is empty");
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        return current->data;
    }

    /**
     * Set the element at the specified index in the forward list.
     * 
     * Time complexity: O(n)
     *
     * @param index   The index at which to set the element.
     * @param element The element to set.
     */
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
    std::string type;
};

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
