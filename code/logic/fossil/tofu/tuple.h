/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
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
} fossil_tofu_tuple_t;

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
fossil_tofu_tuple_t *fossil_tofu_tuple_create(char *type);

/**
 * @brief Creates a new tuple with default values.
 *
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tofu_tuple_t* fossil_tofu_tuple_create_default(void);

/**
 * @brief Creates a new tuple by copying an existing tuple.
 *
 * @param other The tuple to copy.
 * @return The created tuple.
 * @note Time complexity: O(n)
 */
fossil_tofu_tuple_t* fossil_tofu_tuple_create_copy(const fossil_tofu_tuple_t* other);

/**
 * @brief Creates a new tuple by moving an existing tuple.
 *
 * @param other The tuple to move.
 * @return The created tuple.
 * @note Time complexity: O(1)
 */
fossil_tofu_tuple_t* fossil_tofu_tuple_create_move(fossil_tofu_tuple_t* other);

/**
 * @brief Destroys the tuple and fossil_tofu_frees the allocated memory.
 *
 * @param tuple The tuple to destroy.
 * @note Time complexity: O(n)
 */
void fossil_tofu_tuple_destroy(fossil_tofu_tuple_t *tuple);

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
void fossil_tofu_tuple_add(fossil_tofu_tuple_t *tuple, char *element);

/**
 * @brief Removes the element at the specified index from the tuple.
 *
 * @param tuple The tuple to remove the element from.
 * @param index The index to remove the element at.
 * @note Time complexity: O(n)
 */
void fossil_tofu_tuple_remove(fossil_tofu_tuple_t *tuple, size_t index);

/**
 * @brief Gets the number of elements in the tuple.
 *
 * @param tuple The tuple to get the size of.
 * @return The number of elements in the tuple.
 * @note Time complexity: O(1)
 */
size_t fossil_tofu_tuple_size(fossil_tofu_tuple_t *tuple);

/**
 * @brief Gets the capacity of the tuple.
 *
 * @param tuple The tuple to get the capacity of.
 * @return The capacity of the tuple.
 * @note Time complexity: O(1)
 */
size_t fossil_tofu_tuple_capacity(fossil_tofu_tuple_t *tuple);

/**
 * @brief Checks if the tuple is empty.
 *
 * @param tuple The tuple to check.
 * @return true if the tuple is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_tofu_tuple_is_empty(fossil_tofu_tuple_t *tuple);

/**
 * @brief Clears all elements from the tuple.
 *
 * @param tuple The tuple to clear.
 * @note Time complexity: O(n)
 */
void fossil_tofu_tuple_clear(fossil_tofu_tuple_t *tuple);

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
char *fossil_tofu_tuple_get(fossil_tofu_tuple_t* tuple, size_t index);

/**
 * @brief Gets the first element in the tuple.
 * 
 * @param tuple The tuple from which to get the first element.
 * @return The first element in the tuple.
 * @note Time complexity: O(1)
 */
char *fossil_tofu_tuple_get_front(const fossil_tofu_tuple_t* tuple);

/**
 * @brief Gets the last element in the tuple.
 * 
 * @param tuple The tuple from which to get the last element.
 * @return The last element in the tuple.
 * @note Time complexity: O(1)
 */
char *fossil_tofu_tuple_get_back(const fossil_tofu_tuple_t* tuple);

/**
 * @brief Sets the element at the specified index in the tuple.
 * 
 * @param tuple The tuple in which to set the element.
 * @param index The index at which to set the element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tofu_tuple_set(fossil_tofu_tuple_t* tuple, size_t index, char *element);

/**
 * @brief Sets the first element in the tuple.
 * 
 * @param tuple The tuple in which to set the first element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tofu_tuple_set_front(fossil_tofu_tuple_t* tuple, char *element);

/**
 * @brief Sets the last element in the tuple.
 * 
 * @param tuple The tuple in which to set the last element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tofu_tuple_set_back(fossil_tofu_tuple_t* tuple, char *element);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

    namespace tofu {

        /**
         * @class Tuple
         * @brief A C++ wrapper for the fossil_tofu_tuple_t structure, providing a more
         *        user-friendly interface for managing tuples of ToFu elements.
         */
        class Tuple {
            public:
                /**
                 * @brief Constructs a Tuple with a specified type.
                 * 
                 * @param type The expected type of elements in the tuple.
                 * @throws std::runtime_error If the tuple creation fails.
                 */
                Tuple(const std::string& type) {
                    tuple_ = fossil_tofu_tuple_create(const_cast<char*>(type.c_str()));
                    if (!tuple_) {
                        throw std::runtime_error("Failed to create tuple.");
                    }
                }

                /**
                 * @brief Constructs a Tuple with default values.
                 * 
                 * @throws std::runtime_error If the tuple creation fails.
                 */
                Tuple() {
                    tuple_ = fossil_tofu_tuple_create_default();
                    if (!tuple_) {
                        throw std::runtime_error("Failed to create tuple.");
                    }
                }

                /**
                 * @brief Constructs a Tuple by copying another Tuple.
                 * 
                 * @param other The Tuple to copy.
                 * @throws std::runtime_error If the tuple creation fails.
                 */
                Tuple(const Tuple& other) {
                    tuple_ = fossil_tofu_tuple_create_copy(other.tuple_);
                    if (!tuple_) {
                        throw std::runtime_error("Failed to create tuple.");
                    }
                }

                /**
                 * @brief Constructs a Tuple by moving another Tuple.
                 * 
                 * @param other The Tuple to move.
                 * @throws std::runtime_error If the tuple creation fails.
                 */
                Tuple(Tuple&& other) {
                    tuple_ = fossil_tofu_tuple_create_move(other.tuple_);
                    if (!tuple_) {
                        throw std::runtime_error("Failed to create tuple.");
                    }
                }

                /**
                 * @brief Destroys the Tuple and releases its resources.
                 */
                ~Tuple() {
                    fossil_tofu_tuple_destroy(tuple_);
                }

                /**
                 * @brief Adds an element to the Tuple.
                 * 
                 * @param element The element to add.
                 */
                void add(const std::string& element) {
                    fossil_tofu_tuple_add(tuple_, const_cast<char*>(element.c_str()));
                }

                /**
                 * @brief Removes the element at the specified index from the Tuple.
                 * 
                 * @param index The index of the element to remove.
                 */
                void remove(size_t index) {
                    fossil_tofu_tuple_remove(tuple_, index);
                }

                /**
                 * @brief Gets the number of elements in the Tuple.
                 * 
                 * @return The number of elements in the Tuple.
                 */
                size_t size() const {
                    return fossil_tofu_tuple_size(tuple_);
                }

                /**
                 * @brief Gets the capacity of the Tuple.
                 * 
                 * @return The capacity of the Tuple.
                 */
                size_t capacity() const {
                    return fossil_tofu_tuple_capacity(tuple_);
                }

                /**
                 * @brief Checks if the Tuple is empty.
                 * 
                 * @return true if the Tuple is empty, false otherwise.
                 */
                bool is_empty() const {
                    return fossil_tofu_tuple_is_empty(tuple_);
                }

                /**
                 * @brief Clears all elements from the Tuple.
                 */
                void clear() {
                    fossil_tofu_tuple_clear(tuple_);
                }

                /**
                 * @brief Gets the element at the specified index in the Tuple.
                 * 
                 * @param index The index of the element to get.
                 * @return The element at the specified index.
                 */
                std::string get(size_t index) const {
                    char* result = fossil_tofu_tuple_get(tuple_, index);
                    return result ? std::string(result) : std::string();
                }

                /**
                 * @brief Gets the first element in the Tuple.
                 * 
                 * @return The first element in the Tuple.
                 */
                std::string get_front() const {
                    char* result = fossil_tofu_tuple_get_front(tuple_);
                    return result ? std::string(result) : std::string();
                }

                /**
                 * @brief Gets the last element in the Tuple.
                 * 
                 * @return The last element in the Tuple.
                 */
                std::string get_back() const {
                    char* result = fossil_tofu_tuple_get_back(tuple_);
                    return result ? std::string(result) : std::string();
                }

                /**
                 * @brief Sets the element at the specified index in the Tuple.
                 * 
                 * @param index The index at which to set the element.
                 * @param element The element to set.
                 */
                void set(size_t index, const std::string& element) {
                    fossil_tofu_tuple_set(tuple_, index, const_cast<char*>(element.c_str()));
                }

                /**
                 * @brief Sets the first element in the Tuple.
                 * 
                 * @param element The element to set.
                 */
                void set_front(const std::string& element) {
                    fossil_tofu_tuple_set_front(tuple_, const_cast<char*>(element.c_str()));
                }

                /**
                 * @brief Sets the last element in the Tuple.
                 * 
                 * @param element The element to set.
                 */
                void set_back(const std::string& element) {
                    fossil_tofu_tuple_set_back(tuple_, const_cast<char*>(element.c_str()));
                }

            private:
                fossil_tofu_tuple_t* tuple_; /**< Pointer to the underlying fossil_tofu_tuple_t structure. */
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
