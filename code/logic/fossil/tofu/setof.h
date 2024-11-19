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
#ifndef FOSSIL_TOFU_SETOF_H
#define FOSSIL_TOFU_SETOF_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the set
typedef struct fossil_set_node_t {
    fossil_tofu_t data;
    struct fossil_set_node_t* next;
} fossil_set_node_t;

// Set structure
typedef struct fossil_set_t {
    fossil_set_node_t* head;
    char* type;
} fossil_set_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new set with the specified data type.
 *
 * @param list_type The type of data the set will store.
 * @return          The created set.
 * @note            O(1) - Constant time complexity.
 */
fossil_set_t* fossil_set_create_container(char* type);

/**
 * Create a new set with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created set.
 */
fossil_set_t* fossil_set_create_default(void);

/**
 * Create a new set by copying an existing set.
 * 
 * Time complexity: O(n)
 *
 * @param other The set to copy.
 * @return      The created set.
 */
fossil_set_t* fossil_set_create_copy(const fossil_set_t* other);

/**
 * Create a new set by moving an existing set.
 * 
 * Time complexity: O(1)
 *
 * @param other The set to move.
 * @return      The created set.
 */
fossil_set_t* fossil_set_create_move(fossil_set_t* other);

/**
 * Erase the contents of the set and fossil_tofu_free allocated memory.
 *
 * @param set The set to erase.
 * @note      O(n) - Linear time complexity, where n is the number of elements in the set.
 */
void fossil_set_destroy(fossil_set_t* set);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the set.
 *
 * @param set  The set to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 * @note       O(1) - Constant time complexity.
 */
int32_t fossil_set_insert(fossil_set_t* set, char *data);

/**
 * Remove data from the set.
 *
 * @param set  The set to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 * @note       O(n) - Linear time complexity, where n is the number of elements in the set.
 */
void fossil_set_erase(fossil_set_t *set);

/**
 * Get the size of the set.
 *
 * @param set The set for which to get the size.
 * @return    The size of the set.
 * @note      O(n) - Linear time complexity, where n is the number of elements in the set.
 */
size_t fossil_set_size(const fossil_set_t* set);

/**
 * Check if the set is not empty.
 *
 * @param set The set to check.
 * @return    True if the set is not empty, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_not_empty(const fossil_set_t* set);

/**
 * Check if the set is not a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is not a null pointer, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_not_cnullptr(const fossil_set_t* set);

/**
 * Check if the set is empty.
 *
 * @param set The set to check.
 * @return    True if the set is empty, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_is_empty(const fossil_set_t* set);

/**
 * Check if the set is a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is a null pointer, false otherwise.
 * @note      O(1) - Constant time complexity.
 */
bool fossil_set_is_cnullptr(const fossil_set_t* set);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set   The set from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
char *fossil_set_get(const fossil_set_t* set, size_t index);

/**
 * Get the first element in the set.
 * 
 * Time complexity: O(1)
 *
 * @param set The set from which to get the first element.
 * @return    The first element in the set.
 */
char *fossil_set_get_front(const fossil_set_t* set);

/**
 * Get the last element in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set The set from which to get the last element.
 * @return    The last element in the set.
 */
char *fossil_set_get_back(const fossil_set_t* set);

/**
 * Set the element at the specified index in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set     The set in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_set_set(fossil_set_t* set, size_t index, char *element);

/**
 * Set the first element in the set.
 * 
 * Time complexity: O(1)
 *
 * @param set     The set in which to set the first element.
 * @param element The element to set.
 */
void fossil_set_set_front(fossil_set_t* set, char *element);

/**
 * Set the last element in the set.
 * 
 * Time complexity: O(n)
 *
 * @param set     The set in which to set the last element.
 * @param element The element to set.
 */
void fossil_set_set_back(fossil_set_t* set, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

//
template <typename T>
class Set {
public:
    // Node structure for the set
    struct Node {
        T data;
        Node* next;
    };

    // Constructor
    Set() : head(nullptr) {}

    // Destructor
    ~Set() {
        clear();
    }

    // Insert data into the set
    void insert(const T& data) {
        Node* newNode = new Node{data, head};
        head = newNode;
    }

    // Remove data from the set
    void erase(const T& data) {
        Node** current = &head;
        while (*current) {
            if ((*current)->data == data) {
                Node* temp = *current;
                *current = (*current)->next;
                delete temp;
                return;
            }
            current = &((*current)->next);
        }
    }

    // Get the size of the set
    size_t size() const {
        size_t count = 0;
        Node* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // Check if the set is not empty
    bool not_empty() const {
        return head != nullptr;
    }

    // Check if the set is empty
    bool is_empty() const {
        return head == nullptr;
    }

    // Get the element at the specified index in the set
    T get(size_t index) const {
        Node* current = head;
        while (current && index > 0) {
            current = current->next;
            --index;
        }
        if (current) {
            return current->data;
        }
        throw std::out_of_range("Index out of range");
    }

    // Get the first element in the set
    T get_front() const {
        if (head) {
            return head->data;
        }
        throw std::out_of_range("Set is empty");
    }

    // Get the last element in the set
    T get_back() const {
        if (!head) {
            throw std::out_of_range("Set is empty");
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        return current->data;
    }

    // Set the element at the specified index in the set
    void set(size_t index, const T& element) {
        Node* current = head;
        while (current && index > 0) {
            current = current->next;
            --index;
        }
        if (current) {
            current->data = element;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Set the first element in the set
    void set_front(const T& element) {
        if (head) {
            head->data = element;
        } else {
            throw std::out_of_range("Set is empty");
        }
    }

    // Set the last element in the set
    void set_back(const T& element) {
        if (!head) {
            throw std::out_of_range("Set is empty");
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->data = element;
    }

    // Clear the set
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
};

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
