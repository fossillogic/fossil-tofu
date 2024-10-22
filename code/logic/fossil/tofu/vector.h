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
extern "C"
{
#endif

#define INITIAL_CAPACITY 10

typedef struct {
    fossil_tofu_t* data;
    size_t size;
    size_t capacity;
    char* type;
} fossil_vector_t;

/**
 * Create a new vector with the specified expected type.
 * 
 * Time complexity: O(1)
 *
 * @param expected_type The expected type of elements in the vector.
 * @return              The created vector.
 */
fossil_vector_t* fossil_vector_create(char* type);

/**
 * Erase the contents of the vector and free allocated memory.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to erase.
 */
void fossil_vector_destroy(fossil_vector_t* vector);

/**
 * Add an element to the end of the vector.
 * 
 * Amortized time complexity: O(1)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_back(fossil_vector_t* vector, fossil_tofu_t element);

/**
 * Add an element to the front of the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_front(fossil_vector_t* vector, fossil_tofu_t element);

/**
 * Add an element at the specified index in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector  The vector to which the element will be added.
 * @param index   The index at which to add the element.
 * @param element The element to add.
 */
void fossil_vector_push_at(fossil_vector_t* vector, size_t index, fossil_tofu_t element);

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
void fossil_vector_erase(fossil_vector_t* vector, size_t index);

/**
 * Remove all elements from the vector that match the target element.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector from which to remove elements.
 * @param target The element to remove.
 */
void fossil_vector_erase_if(fossil_vector_t* vector, fossil_tofu_t target);


/**
 * Search for a target element in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to search.
 * @param target The element to search for.
 * @return       The index of the target element, or -1 if not found.
 */
int fossil_vector_search(const fossil_vector_t* vector, fossil_tofu_t target);

/**
 * Reverse the order of elements in the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to reverse.
 */
void fossil_vector_reverse(fossil_vector_t* vector);

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

/**
 * Display the contents of the vector.
 * 
 * Time complexity: O(n)
 *
 * @param vector The vector to peek into.
 */
void fossil_vector_peek(const fossil_vector_t* vector);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace fossil {
    class Vector {
    public:
        Vector(const std::string& type) : vector_(fossil_vector_create(const_cast<char*>(type.c_str()))) {}

        ~Vector() {
            fossil_vector_destroy(vector_);
        }

        void push_back(fossil_tofu_t element) {
            fossil_vector_push_back(vector_, element);
        }

        void push_front(fossil_tofu_t element) {
            fossil_vector_push_front(vector_, element);
        }

        void push_at(size_t index, fossil_tofu_t element) {
            fossil_vector_push_at(vector_, index, element);
        }

        void pop_back() {
            fossil_vector_pop_back(vector_);
        }

        void pop_front() {
            fossil_vector_pop_front(vector_);
        }

        void pop_at(size_t index) {
            fossil_vector_pop_at(vector_, index);
        }

        int search(fossil_tofu_t target) {
            return fossil_vector_search(vector_, target);
        }

        void reverse() {
            fossil_vector_reverse(vector_);
        }

        bool is_cnullptr() {
            return fossil_vector_is_cnullptr(vector_);
        }

        bool not_cnullptr() {
            return fossil_vector_not_cnullptr(vector_);
        }

        bool is_empty() {
            return fossil_vector_is_empty(vector_);
        }

        bool not_empty() {
            return fossil_vector_not_empty(vector_);
        }

        size_t size() {
            return fossil_vector_size(vector_);
        }

        size_t capacity() {
            return fossil_vector_capacity(vector_);
        }

        void peek() {
            fossil_vector_peek(vector_);
        }

    private:
        fossil_vector_t* vector_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
