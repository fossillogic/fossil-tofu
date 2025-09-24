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
#ifndef FOSSIL_TOFU_BLOOM_H
#define FOSSIL_TOFU_BLOOM_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions for fossil_bloom
// *****************************************************************************

/**
 * @brief Error codes for the fossil_bloom data structure.
 */
typedef enum {
    FOSSIL_BLOOM_SUCCESS = 0,              // Operation successful
    FOSSIL_BLOOM_ERROR_INVALID_ARGUMENT,   // Invalid argument provided
    FOSSIL_BLOOM_ERROR_MEMORY_ALLOCATION,  // Memory allocation failed
    FOSSIL_BLOOM_ERROR_NOT_FOUND           // Element not found (for debugging)
} fossil_bloom_error_t;

/**
 * @brief Bloom filter container.
 */
typedef struct fossil_bloom_t {
    uint8_t* bit_array;     // Underlying bit array
    size_t bit_count;       // Total number of bits
    size_t hash_count;      // Number of hash functions
    size_t item_count;      // Number of inserted elements
} fossil_bloom_t;


// *****************************************************************************
// Function prototypes for fossil_bloom
// *****************************************************************************

/**
 * @brief Create a new Bloom filter.
 *
 * @param capacity Expected number of elements to store.
 * @param false_positive_rate Desired false-positive probability (e.g., 0.01).
 * @return Pointer to a newly allocated Bloom filter or NULL on failure.
 * @note O(1)
 */
fossil_bloom_t* fossil_bloom_create(size_t capacity, double false_positive_rate);

/**
 * @brief Create a deep copy of a Bloom filter.
 *
 * @param other Bloom filter to copy.
 * @return Pointer to the copied Bloom filter.
 * @note O(n) where n = number of bits in the filter.
 */
fossil_bloom_t* fossil_bloom_create_copy(const fossil_bloom_t* other);

/**
 * @brief Move an existing Bloom filter into a new one, leaving the source empty.
 *
 * @param other Bloom filter to move.
 * @return Pointer to the moved Bloom filter.
 * @note O(1)
 */
fossil_bloom_t* fossil_bloom_create_move(fossil_bloom_t* other);

/**
 * @brief Destroy a Bloom filter and free all memory.
 *
 * @param bloom Bloom filter to destroy.
 * @note O(1)
 */
void fossil_bloom_destroy(fossil_bloom_t* bloom);

/**
 * @brief Insert a key into the Bloom filter.
 *
 * @param bloom Bloom filter container.
 * @param key Key to insert.
 * @param key_len Length of key in bytes.
 * @return 0 on success, non-zero on failure.
 * @note O(k) where k = number of hash functions.
 */
int32_t fossil_bloom_insert(fossil_bloom_t* bloom, const void* key, size_t key_len);

/**
 * @brief Check if a key is *probably* in the Bloom filter.
 *
 * @param bloom Bloom filter container.
 * @param key Key to check.
 * @param key_len Length of key in bytes.
 * @return true if key is probably present, false if definitely not present.
 * @note O(k)
 */
bool fossil_bloom_contains(const fossil_bloom_t* bloom, const void* key, size_t key_len);

/**
 * @brief Get the number of items inserted into the filter.
 *
 * @param bloom Bloom filter container.
 * @return Number of inserted items.
 * @note O(1)
 */
size_t fossil_bloom_count(const fossil_bloom_t* bloom);

/**
 * @brief Clear all bits in the Bloom filter (empties it).
 *
 * @param bloom Bloom filter container.
 * @note O(n) where n = number of bits.
 */
void fossil_bloom_clear(fossil_bloom_t* bloom);

/**
 * @brief Dump Bloom filter internal state for debugging.
 *
 * @param bloom Bloom filter container.
 */
void fossil_bloom_dump(const fossil_bloom_t* bloom);

#ifdef __cplusplus
}

#include <vector>
#include <string>
#include <stdexcept>

namespace fossil {

namespace tofu {

    /**
     * @brief A C++ wrapper class for the fossil_bloom_t structure.
     *
     * This class provides a modern C++ interface to the underlying C Bloom filter implementation,
     * allowing for safe and convenient management of Bloom filter containers and their contents.
     * All resource management is handled automatically, and exceptions are thrown on errors.
     */
    class Bloom {
    public:
        /**
         * @brief Construct a new Bloom filter object.
         *
         * Creates a new Bloom filter container with the specified capacity and false positive rate.
         *
         * @param capacity Expected number of elements to store.
         * @param false_positive_rate Desired false-positive probability (e.g., 0.01).
         * @throws std::runtime_error if the Bloom filter cannot be created.
         */
        Bloom(size_t capacity, double false_positive_rate) {
            bloom = fossil_bloom_create(capacity, false_positive_rate);
            if (!bloom) throw std::runtime_error("Failed to create Bloom filter");
        }

        /**
         * @brief Copy constructor.
         *
         * Creates a deep copy of another Bloom filter object.
         *
         * @param other The Bloom filter to copy.
         * @throws std::runtime_error if the copy operation fails.
         */
        Bloom(const Bloom& other) {
            bloom = fossil_bloom_create_copy(other.bloom);
            if (!bloom) throw std::runtime_error("Failed to copy Bloom filter");
        }

        /**
         * @brief Move constructor.
         *
         * Transfers ownership of the underlying Bloom filter from another Bloom object.
         *
         * @param other The Bloom filter to move from.
         */
        Bloom(Bloom&& other) noexcept {
            bloom = fossil_bloom_create_move(other.bloom);
            other.bloom = nullptr;
            if (!bloom) throw std::runtime_error("Failed to move Bloom filter");
        }

        /**
         * @brief Destructor.
         *
         * Frees all resources associated with the Bloom filter container.
         */
        ~Bloom() {
            fossil_bloom_destroy(bloom);
        }

        /**
         * @brief Insert a key into the Bloom filter.
         *
         * Adds the specified key to the Bloom filter.
         *
         * @param key The key to insert.
         * @return 0 on success, non-zero on failure.
         */
        int32_t insert(const std::string& key) {
            return fossil_bloom_insert(bloom, key.data(), key.size());
        }

        /**
         * @brief Check if a key is probably in the Bloom filter.
         *
         * Determines whether the specified key is probably present in the Bloom filter.
         *
         * @param key The key to check.
         * @return True if the key is probably present, false if definitely not present.
         */
        bool contains(const std::string& key) const {
            return fossil_bloom_contains(bloom, key.data(), key.size());
        }

        /**
         * @brief Get the number of items inserted into the filter.
         *
         * @return Number of inserted items.
         */
        size_t count() const {
            return fossil_bloom_count(bloom);
        }

        /**
         * @brief Clear all bits in the Bloom filter (empties it).
         */
        void clear() {
            fossil_bloom_clear(bloom);
        }

        /**
         * @brief Dump Bloom filter internal state for debugging.
         */
        void dump() const {
            fossil_bloom_dump(bloom);
        }

    private:
        fossil_bloom_t* bloom; ///< Pointer to the underlying C Bloom filter container.
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
