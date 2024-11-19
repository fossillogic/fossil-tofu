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
#ifndef FOSSIL_TOFU_TUPLE_H
#define FOSSIL_TOFU_TUPLE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Define a tuple to hold multiple ToFu elements
typedef struct {
    fossil_tofu_t* elements;  // Dynamic array of ToFu elements in the tuple
    size_t element_count;     // Number of elements in the tuple
    size_t capacity;          // Capacity of the tuple
    char* type;               // Expected type of elements in the tuple
} fossil_tuple_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * @brief Creates a new tuple with a given initial capacity.
 *
 * @param size The initial capacity of the tuple.
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tuple_t *fossil_tuple_create(char *type);

/**
 * @brief Creates a new tuple with default values.
 *
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tuple_t* fossil_tuple_create_default(void);

/**
 * @brief Creates a new tuple by copying an existing tuple.
 *
 * @param other The tuple to copy.
 * @return The created tuple.
 * @note Time complexity: O(n)
 */
fossil_tuple_t* fossil_tuple_create_copy(const fossil_tuple_t* other);

/**
 * @brief Creates a new tuple by moving an existing tuple.
 *
 * @param other The tuple to move.
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tuple_t* fossil_tuple_create_move(fossil_tuple_t* other);

/**
 * @brief Destroys the tuple and fossil_tofu_frees the allocated memory.
 *
 * @param tuple The tuple to destroy.
 * @note Time complexity: O(n)
 */
void fossil_tuple_destroy(fossil_tuple_t *tuple);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * @brief Adds an element to the tuple.
 *
 * @param tuple The tuple to add the element to.
 * @param element The element to add.
 * @note Time complexity: O(1) on average, O(n) in the worst case due to resizing.
 */
void fossil_tuple_add(fossil_tuple_t *tuple, char *element);

/**
 * @brief Removes the element at the specified index from the tuple.
 *
 * @param tuple The tuple to remove the element from.
 * @param index The index to remove the element at.
 * @note Time complexity: O(n)
 */
void fossil_tuple_remove(fossil_tuple_t *tuple, size_t index);

/**
 * @brief Gets the number of elements in the tuple.
 *
 * @param tuple The tuple to get the size of.
 * @return The number of elements in the tuple.
 * @note Time complexity: O(1)
 */
size_t fossil_tuple_size(fossil_tuple_t *tuple);

/**
 * @brief Gets the capacity of the tuple.
 *
 * @param tuple The tuple to get the capacity of.
 * @return The capacity of the tuple.
 * @note Time complexity: O(1)
 */
size_t fossil_tuple_capacity(fossil_tuple_t *tuple);

/**
 * @brief Checks if the tuple is empty.
 *
 * @param tuple The tuple to check.
 * @return true if the tuple is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_tuple_is_empty(fossil_tuple_t *tuple);

/**
 * @brief Clears all elements from the tuple.
 *
 * @param tuple The tuple to clear.
 * @note Time complexity: O(n)
 */
void fossil_tuple_clear(fossil_tuple_t *tuple);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * @brief Gets the element at the specified index in the tuple.
 * 
 * @param tuple The tuple from which to get the element.
 * @param index The index of the element to get.
 * @return The element at the specified index.
 * @note Time complexity: O(1)
 */
char *fossil_tuple_get(fossil_tuple_t* tuple, size_t index);

/**
 * @brief Gets the first element in the tuple.
 * 
 * @param tuple The tuple from which to get the first element.
 * @return The first element in the tuple.
 * @note Time complexity: O(1)
 */
char *fossil_tuple_get_front(const fossil_tuple_t* tuple);

/**
 * @brief Gets the last element in the tuple.
 * 
 * @param tuple The tuple from which to get the last element.
 * @return The last element in the tuple.
 * @note Time complexity: O(1)
 */
char *fossil_tuple_get_back(const fossil_tuple_t* tuple);

/**
 * @brief Sets the element at the specified index in the tuple.
 * 
 * @param tuple The tuple in which to set the element.
 * @param index The index at which to set the element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tuple_set(fossil_tuple_t* tuple, size_t index, char *element);

/**
 * @brief Sets the first element in the tuple.
 * 
 * @param tuple The tuple in which to set the first element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tuple_set_front(fossil_tuple_t* tuple, char *element);

/**
 * @brief Sets the last element in the tuple.
 * 
 * @param tuple The tuple in which to set the last element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tuple_set_back(fossil_tuple_t* tuple, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

template <typename T>
class Tuple {
public:
    Tuple(size_t initial_capacity = 10)
        : elements(new T[initial_capacity]), element_count(0), capacity(initial_capacity) {}

    Tuple(const Tuple& other)
        : elements(new T[other.capacity]), element_count(other.element_count), capacity(other.capacity) {
        std::copy(other.elements, other.elements + other.element_count, elements);
    }

    Tuple(Tuple&& other) noexcept
        : elements(other.elements), element_count(other.element_count), capacity(other.capacity) {
        other.elements = nullptr;
        other.element_count = 0;
        other.capacity = 0;
    }

    ~Tuple() {
        delete[] elements;
    }

    void add(const T& element) {
        if (element_count == capacity) {
            resize(capacity * 2);
        }
        elements[element_count++] = element;
    }

    void remove(size_t index) {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        std::move(elements + index + 1, elements + element_count, elements + index);
        --element_count;
    }

    size_t size() const {
        return element_count;
    }

    size_t get_capacity() const {
        return capacity;
    }

    bool is_empty() const {
        return element_count == 0;
    }

    void clear() {
        element_count = 0;
    }

    T& get(size_t index) {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const T& get(size_t index) const {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    T& front() {
        if (is_empty()) {
            throw std::out_of_range("Tuple is empty");
        }
        return elements[0];
    }

    const T& front() const {
        if (is_empty()) {
            throw std::out_of_range("Tuple is empty");
        }
        return elements[0];
    }

    T& back() {
        if (is_empty()) {
            throw std::out_of_range("Tuple is empty");
        }
        return elements[element_count - 1];
    }

    const T& back() const {
        if (is_empty()) {
            throw std::out_of_range("Tuple is empty");
        }
        return elements[element_count - 1];
    }

    void set(size_t index, const T& element) {
        if (index >= element_count) {
            throw std::out_of_range("Index out of range");
        }
        elements[index] = element;
    }

    void set_front(const T& element) {
        if (is_empty()) {
            throw std::out_of_range("Tuple is empty");
        }
        elements[0] = element;
    }

    void set_back(const T& element) {
        if (is_empty()) {
            throw std::out_of_range("Tuple is empty");
        }
        elements[element_count - 1] = element;
    }

private:
    void resize(size_t new_capacity) {
        T* new_elements = new T[new_capacity];
        std::move(elements, elements + element_count, new_elements);
        delete[] elements;
        elements = new_elements;
        capacity = new_capacity;
    }

    T* elements;
    size_t element_count;
    size_t capacity;
};

}

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
