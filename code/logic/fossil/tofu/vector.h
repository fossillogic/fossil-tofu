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
 * @param expected_type The expected type of elements in the vector.
 * @return              The created vector.
 */
fossil_vector_t* fossil_vector_create(char* type);

/**
 * Erase the contents of the vector and free allocated memory.
 *
 * @param vector The vector to erase.
 */
void fossil_vector_erase(fossil_vector_t* vector);

/**
 * Add an element to the end of the vector.
 *
 * @param vector  The vector to which the element will be added.
 * @param element The element to add.
 */
void fossil_vector_push_back(fossil_vector_t* vector, fossil_tofu_t element);

/**
 * Search for a target element in the vector.
 *
 * @param vector The vector to search.
 * @param target The element to search for.
 * @return       The index of the target element, or -1 if not found.
 */
int fossil_vector_search(const fossil_vector_t* vector, fossil_tofu_t target);

/**
 * Reverse the order of elements in the vector.
 *
 * @param vector The vector to reverse.
 */
void fossil_vector_reverse(fossil_vector_t* vector);

/**
 * Check if the vector is a null pointer.
 *
 * @param vector The vector to check.
 * @return       True if the vector is a null pointer, false otherwise.
 */
bool fossil_vector_is_cnullptr(const fossil_vector_t* vector);

/**
 * Check if the vector is not a null pointer.
 *
 * @param vector The vector to check.
 * @return       True if the vector is not a null pointer, false otherwise.
 */
bool fossil_vector_not_cnullptr(const fossil_vector_t* vector);

/**
 * Check if the vector is empty.
 *
 * @param vector The vector to check.
 * @return       True if the vector is empty, false otherwise.
 */
bool fossil_vector_is_empty(const fossil_vector_t* vector);

/**
 * Check if the vector is not empty.
 *
 * @param vector The vector to check.
 * @return       True if the vector is not empty, false otherwise.
 */
bool fossil_vector_not_empty(const fossil_vector_t* vector);

/**
 * Set the element at the specified index in the vector.
 *
 * @param vector The vector in which to set the element.
 * @param index  The index at which to set the element.
 * @param element The element to set.
 */
void fossil_vector_setter(fossil_vector_t* vector, size_t index, fossil_tofu_t element);

/**
 * Get the element at the specified index in the vector.
 *
 * @param vector The vector from which to get the element.
 * @param index  The index from which to get the element.
 * @return       The element at the specified index.
 */
fossil_tofu_t* fossil_vector_getter(const fossil_vector_t* vector, size_t index);

/**
 * Get the size of the vector.
 *
 * @param vector The vector for which to get the size.
 * @return       The size of the vector.
 */
size_t fossil_vector_size(const fossil_vector_t* vector);

/**
 * Display the contents of the vector.
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
            fossil_vector_erase(vector_);
        }

        void push_back(fossil_tofu_t element) {
            fossil_vector_push_back(vector_, element);
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

        void setter(size_t index, fossil_tofu_t element) {
            fossil_vector_setter(vector_, index, element);
        }

        fossil_tofu_t* getter(size_t index) {
            return fossil_vector_getter(vector_, index);
        }

        size_t size() {
            return fossil_vector_size(vector_);
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
