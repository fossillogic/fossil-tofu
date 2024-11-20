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
#ifndef FOSSIL_TOFU_VECTOR_H
#define FOSSIL_TOFU_VECTOR_H

#include "tofu.h"

#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

typedef struct {
    fossil_tofu_t* data;
    size_t size;
    size_t capacity;
    char* type;
} fossil_vector_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new vector with the specified expected type.
 * 
 * Time complexity: O(1)
 *
 * @param expected_type The expected type of elements in the vector.
 * @return              The created vector.
 */
fossil_vector_t* fossil_vector_create_container(char* type);

/**
 * Create a new vector with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created vector.
 */
fossil_vector_t* fossil_vector_create_default(void);

/**
 * Create a new vector by copying an existing vector.
 * 
 * Time complexity: O(n)
 *
 * @param other The vector to copy.
 * @return      The created vector.
 */
fossil_vector_t* fossil_vector_create_copy(const fossil_vector_t* other);

/**
 * Create a new vector by moving an existing vector.
 * 
 * Time complexity: O(1)
 *
 * @param other The vector to move.
 * @return      The created vector.
 */
fossil_vector_t* fossil_vector_create_move(fossil_vector_t* other);

/**
 * Erase the contents of the vector and fossil_tofu_free allocated memory.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to erase.
 */
void fossil_vector_destroy(fossil_vector_t* vector);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Add an element to the end of the vector.
 * 
 * Amortized time complexity: O(1)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_back(fossil_vector_t* vector, char *element);

/**
 * Add an element to the front of the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_front(fossil_vector_t* vector, char *element);

/**
 * Add an element at the specified index in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param index   The index at which to add the element.
 * @param element The element to add.
 */
void fossil_vector_push_at(fossil_vector_t* vector, size_t index, char *element);

/**
 * Remove the last element from the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to remove the last element.
 */
void fossil_vector_pop_back(fossil_vector_t* vector);

/**
 * Remove the first element from the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector from which to remove the first element.
 */
void fossil_vector_pop_front(fossil_vector_t* vector);

/**
 * Remove the element at the specified index in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector from which to remove the element.
 * @param index  The index at which to remove the element.
 */
void fossil_vector_pop_at(fossil_vector_t* vector, size_t index);

/**
 * Remove all elements from the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to remove all elements.
 */
void fossil_vector_erase(fossil_vector_t* vector);

/**
 * Check if the vector is a null pointer.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is a null pointer, false otherwise.
 */
bool fossil_vector_is_cnullptr(const fossil_vector_t* vector);

/**
 * Check if the vector is not a null pointer.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is not a null pointer, false otherwise.
 */
bool fossil_vector_not_cnullptr(const fossil_vector_t* vector);

/**
 * Check if the vector is empty.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is empty, false otherwise.
 */
bool fossil_vector_is_empty(const fossil_vector_t* vector);

/**
 * Check if the vector is not empty.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector to check.
 * @return       True if the vector is not empty, false otherwise.
 */
bool fossil_vector_not_empty(const fossil_vector_t* vector);

/**
 * Get the size of the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector for which to get the size.
 * @return       The size of the vector.
 */
size_t fossil_vector_size(const fossil_vector_t* vector);

/**
 * Get the capacity of the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector for which to get the capacity.
 * @return       The capacity of the vector.
 */
size_t fossil_vector_capacity(const fossil_vector_t* vector);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the element.
 * @param index  The index of the element to get.
 * @return       The element at the specified index.
 */
char *fossil_vector_get(const fossil_vector_t* vector, size_t index);

/**
 * Get the first element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the first element.
 * @return       The first element in the vector.
 */
char *fossil_vector_get_front(const fossil_vector_t* vector);

/**
 * Get the last element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the last element.
 * @return       The last element in the vector.
 */
char *fossil_vector_get_back(const fossil_vector_t* vector);

/**
 * Get the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector The vector from which to get the element.
 * @param index  The index of the element to get.
 * @return       The element at the specified index.
 */
char *fossil_vector_get_at(const fossil_vector_t* vector, size_t index);

/**
 * Set the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_vector_set(fossil_vector_t* vector, size_t index, char *element);

/**
 * Set the first element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the first element.
 * @param element The element to set.
 */
void fossil_vector_set_front(fossil_vector_t* vector, char *element);

/**
 * Set the last element in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the last element.
 * @param element The element to set.
 */
void fossil_vector_set_back(fossil_vector_t* vector, char *element);

/**
 * Set the element at the specified index in the vector.
 * 
 * Time complexity: O(1)
 *
 * @param vector  The vector in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_vector_set_at(fossil_vector_t* vector, size_t index, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

/**
 * A dynamic array that can grow and shrink as needed.
 * 
 * @tparam T The type of elements in the vector.
 */
template <typename T>
class Vector {
public:
    /**
     * Create a new vector with the specified initial capacity.
     * 
     * Time complexity: O(1)
     *
     * @param initial_capacity The initial capacity of the vector.
     */
    Vector() : data(nullptr), size(0), capacity(0) {}

    /**
     * Create a new vector with the specified initial capacity.
     * 
     * Time complexity: O(1)
     *
     * @param initial_capacity The initial capacity of the vector.
     */
    explicit Vector(size_t initial_capacity) : data(new T[initial_capacity]), size(0), capacity(initial_capacity) {}

    /**
     * Destroy the vector and fossil_tofu_free allocated memory.
     * 
     * Time complexity: O(1)
     */
    ~Vector() { delete[] data; }

    /**
     * Add an element to the end of the vector.
     * 
     * Amortized time complexity: O(1)
     *
     * @param element The element to add.
     */
    void push_back(const T& element) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = element;
    }

    /**
     * Add an element to the front of the vector.
     * 
     * Time complexity: O(n)
     *
     * @param element The element to add.
     */
    void push_front(const T& element) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = element;
        ++size;
    }

    /**
     * Add an element at the specified index in the vector.
     * 
     * Time complexity: O(n)
     *
     * @param index   The index at which to add the element.
     * @param element The element to add.
     */
    void push_at(size_t index, const T& element) {
        if (index > size) throw std::out_of_range("Index out of range");
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = element;
        ++size;
    }

    /**
     * Remove the last element from the vector.
     * 
     * Time complexity: O(1)
     */
    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    /**
     * Remove the first element from the vector.
     * 
     * Time complexity: O(n)
     */
    void pop_front() {
        if (size > 0) {
            for (size_t i = 0; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            --size;
        }
    }

    /**
     * Remove the element at the specified index in the vector.
     * 
     * Time complexity: O(n)
     *
     * @param index The index at which to remove the element.
     */
    void pop_at(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    /**
     * Remove all elements from the vector.
     * 
     * Time complexity: O(1)
     */
    void erase() {
        size = 0;
    }

    /**
     * Check if the vector is empty.
     * 
     * Time complexity: O(1)
     *
     * @return True if the vector is empty, false otherwise.
     */
    bool is_empty() const {
        return size == 0;
    }

    /**
     * Get the size of the vector.
     * 
     * Time complexity: O(1)
     *
     * @return The size of the vector.
     */
    size_t get_size() const {
        return size;
    }

    /**
     * Get the capacity of the vector.
     * 
     * Time complexity: O(1)
     *
     * @return The capacity of the vector.
     */
    size_t get_capacity() const {
        return capacity;
    }

    /**
     * Get the element at the specified index in the vector.
     * 
     * Time complexity: O(1)
     *
     * @param index The index of the element to get.
     * @return      The element at the specified index.
     */
    T& get(size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    /**
     * Get the element at the specified index in the vector.
     * 
     * Time complexity: O(1)
     *
     * @param index The index of the element to get.
     * @return      The element at the specified index.
     */
    const T& get(size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    /**
     * Get the first element in the vector.
     * 
     * Time complexity: O(1)
     *
     * @return The first element in the vector.
     */
    void set(size_t index, const T& element) {
        if (index >= size) throw std::out_of_range("Index out of range");
        data[index] = element;
    }

private:
    /**
     * Resize the vector to the specified new capacity.
     * 
     * Time complexity: O(n)
     *
     * @param new_capacity The new capacity of the vector.
     */
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    T* data;
    size_t size;
    size_t capacity;
};

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
