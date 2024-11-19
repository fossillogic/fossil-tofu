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
#ifndef FOSSIL_TOFU_STACK_H
#define FOSSIL_TOFU_STACK_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Stack structure
typedef struct fossil_stack_node_t {
    fossil_tofu_t data; // Data stored in the stack node
    struct fossil_stack_node_t* next; // Pointer to the next node
} fossil_stack_node_t;

typedef struct fossil_stack_t {
    char* type; // Type of the stack
    fossil_stack_node_t* top; // Pointer to the top node of the stack
} fossil_stack_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new stack with the specified data type.
 *
 * @param list_type The type of data the stack will store.
 * @return          The created stack.
 * @note            Time complexity: O(1)
 */
fossil_stack_t* fossil_stack_create_container(char* type);

/**
 * Create a new stack with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created stack.
 */
fossil_stack_t* fossil_stack_create_default(void);

/**
 * Create a new stack by copying an existing stack.
 * 
 * Time complexity: O(n)
 *
 * @param other The stack to copy.
 * @return      The created stack.
 */
fossil_stack_t* fossil_stack_create_copy(const fossil_stack_t* other);

/**
 * Create a new stack by moving an existing stack.
 * 
 * Time complexity: O(1)
 *
 * @param other The stack to move.
 * @return      The created stack.
 */
fossil_stack_t* fossil_stack_create_move(fossil_stack_t* other);

/**
 * Erase the contents of the stack and fossil_tofu_free allocated memory.
 *
 * @param stack The stack to erase.
 * @note        Time complexity: O(n)
 */
void fossil_stack_destroy(fossil_stack_t* stack);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the stack.
 *
 * @param stack The stack to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(1)
 */
int32_t fossil_stack_insert(fossil_stack_t* stack, char *data);

/**
 * Remove data from the stack.
 *
 * @param stack       The stack to remove data from.
 * @return            The error code indicating the success or failure of the operation.
 * @note              Time complexity: O(1)
 */
int32_t fossil_stack_remove(fossil_stack_t* stack);

/**
 * Get the size of the stack.
 *
 * @param stack The stack for which to get the size.
 * @return      The size of the stack.
 * @note        Time complexity: O(n)
 */
size_t fossil_stack_size(const fossil_stack_t* stack);

/**
 * Check if the stack is not empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_not_empty(const fossil_stack_t* stack);

/**
 * Check if the stack is not a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_not_cnullptr(const fossil_stack_t* stack);

/**
 * Check if the stack is empty.
 *
 * @param stack The stack to check.
 * @return      True if the stack is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_is_empty(const fossil_stack_t* stack);

/**
 * Check if the stack is a null pointer.
 *
 * @param stack The stack to check.
 * @return      True if the stack is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_stack_is_cnullptr(const fossil_stack_t* stack);

/**
 * Get the top element of the stack.
 *
 * @param stack         The stack to get the top element from.
 * @return              The top element of the stack or the default value if the stack is empty.
 * @note                Time complexity: O(1)
 */
fossil_tofu_t fossil_stack_top(fossil_stack_t* stack);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the stack.
 * 
 * Time complexity: O(n)
 *
 * @param stack The stack from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
fossil_tofu_t fossil_stack_get(const fossil_stack_t* stack, size_t index);

/**
 * Set the element at the specified index in the stack.
 * 
 * Time complexity: O(n)
 *
 * @param stack   The stack in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_stack_set(fossil_stack_t* stack, size_t index, fossil_tofu_t element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

/**
 * Stack data structure.
 *
 * @tparam T The type of data stored in the stack.
 */
template <typename T>
class Stack {
public:
    /**
     * Default constructor.
     */
    Stack() : top(nullptr), stack_size(0) {}

    /**
     * Destructor.
     */
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    /**
     * Push data onto the stack.
     *
     * @param data The data to push onto the stack.
     */
    void push(const T& data) {
        Node* newNode = new Node{data, top};
        top = newNode;
        ++stack_size;
    }

    /**
     * Pop data from the stack.
     */
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        --stack_size;
    }

    /**
     * Get the top element of the stack.
     *
     * @return The top element of the stack.
     */
    T& peek() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return top->data;
    }

    /**
     * Get the top element of the stack.
     *
     * @return The top element of the stack.
     */
    const T& peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return top->data;
    }

    /**
     * Check if the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty() const {
        return top == nullptr;
    }

    /**
     * Get the size of the stack.
     *
     * @return The size of the stack.
     */
    size_t size() const {
        return stack_size;
    }

private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;
    size_t stack_size;
};

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
