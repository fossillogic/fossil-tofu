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

namespace tofu {

    /**
     * A wrapper class for the fossil_vector_t structure, providing a C++ interface
     * for managing dynamic arrays of elements.
     */
    class Vector {
    public:
        /**
         * Default constructor. Creates a new vector with default values.
         * Throws a runtime_error if the vector creation fails.
         */
        Vector() : vector(fossil_vector_create_default()) {
            if (fossil_vector_is_cnullptr(vector)) {
                throw std::runtime_error("Failed to create vector");
            }
        }

        /**
         * Constructor that creates a new vector with the specified type.
         * Throws a runtime_error if the vector creation fails.
         *
         * @param type The expected type of elements in the vector.
         */
        Vector(char* type) : vector(fossil_vector_create_container(type)) {
            if (fossil_vector_is_cnullptr(vector)) {
                throw std::runtime_error("Failed to create vector");
            }
        }

        /**
         * Copy constructor. Creates a new vector by copying an existing vector.
         * Throws a runtime_error if the vector creation fails.
         *
         * @param other The vector to copy.
         */
        Vector(const Vector& other) : vector(fossil_vector_create_copy(other.vector)) {
            if (fossil_vector_is_cnullptr(vector)) {
                throw std::runtime_error("Failed to create vector");
            }
        }

        /**
         * Move constructor. Creates a new vector by moving an existing vector.
         * Does not throw exceptions.
         *
         * @param other The vector to move.
         */
        Vector(Vector&& other) noexcept : vector(fossil_vector_create_move(other.vector)) {
            if (fossil_vector_is_cnullptr(vector)) {
                throw std::runtime_error("Failed to create vector");
            }
        }

        /**
         * Destructor. Destroys the vector and frees allocated memory.
         */
        ~Vector() {
            fossil_vector_destroy(vector);
        }

        /**
         * Adds an element to the end of the vector.
         *
         * @param element The element to add.
         */
        void push_back(char *element) {
            fossil_vector_push_back(vector, element);
        }

        /**
         * Adds an element to the front of the vector.
         *
         * @param element The element to add.
         */
        void push_front(char *element) {
            fossil_vector_push_front(vector, element);
        }

        /**
         * Adds an element at the specified index in the vector.
         *
         * @param index   The index at which to add the element.
         * @param element The element to add.
         */
        void push_at(size_t index, char *element) {
            fossil_vector_push_at(vector, index, element);
        }

        /**
         * Removes the last element from the vector.
         */
        void pop_back() {
            fossil_vector_pop_back(vector);
        }

        /**
         * Removes the first element from the vector.
         */
        void pop_front() {
            fossil_vector_pop_front(vector);
        }

        /**
         * Removes the element at the specified index in the vector.
         *
         * @param index The index at which to remove the element.
         */
        void pop_at(size_t index) {
            fossil_vector_pop_at(vector, index);
        }

        /**
         * Removes all elements from the vector.
         */
        void erase() {
            fossil_vector_erase(vector);
        }

        /**
         * Checks if the vector is empty.
         *
         * @return True if the vector is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_vector_is_empty(vector);
        }

        /**
         * Gets the size of the vector.
         *
         * @return The size of the vector.
         */
        size_t size() const {
            return fossil_vector_size(vector);
        }

        /**
         * Gets the element at the specified index in the vector.
         *
         * @param index The index of the element to get.
         * @return      The element at the specified index.
         */
        char *get(size_t index) const {
            return fossil_vector_get(vector, index);
        }

        /**
         * Gets the first element in the vector.
         *
         * @return The first element in the vector.
         */
        char *get_front() const {
            return fossil_vector_get_front(vector);
        }

        /**
         * Gets the last element in the vector.
         *
         * @return The last element in the vector.
         */
        char *get_back() const {
            return fossil_vector_get_back(vector);
        }

        /**
         * Gets the element at the specified index in the vector.
         *
         * @param index The index of the element to get.
         * @return      The element at the specified index.
         */
        char *get_at(size_t index) const {
            return fossil_vector_get_at(vector, index);
        }

        /**
         * Sets the element at the specified index in the vector.
         *
         * @param index   The index at which to set the element.
         * @param element The element to set.
         */
        void set(size_t index, char *element) {
            fossil_vector_set(vector, index, element);
        }

        /**
         * Sets the first element in the vector.
         *
         * @param element The element to set.
         */
        void set_front(char *element) {
            fossil_vector_set_front(vector, element);
        }

        /**
         * Sets the last element in the vector.
         *
         * @param element The element to set.
         */
        void set_back(char *element) {
            fossil_vector_set_back(vector, element);
        }

        /**
         * Sets the element at the specified index in the vector.
         *
         * @param index   The index at which to set the element.
         * @param element The element to set.
         */
        void set_at(size_t index, char *element) {
            fossil_vector_set_at(vector, index, element);
        }

    private:
        /**
         * A pointer to the underlying fossil_vector_t structure.
         */
        fossil_vector_t* vector;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
