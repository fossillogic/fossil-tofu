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
#ifndef FOSSIL_TOFU_TRIE_H
#define FOSSIL_TOFU_TRIE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions for fossil_trie
// *****************************************************************************

typedef struct fossil_trie_node_t {
    char ch;                               // Character for this node
    bool is_terminal;                      // Whether this node marks the end of a key
    fossil_tofu_t value;                   // Optional stored value
    struct fossil_trie_node_t** children;  // Dynamic array of child nodes
    size_t child_count;                    // Number of children
} fossil_trie_node_t;

typedef struct fossil_trie_t {
    fossil_trie_node_t* root;              // Root node of the trie
    char* value_type;                      // Optional type information for stored values
    size_t size;                           // Number of keys currently stored
} fossil_trie_t;

// *****************************************************************************
// Function prototypes for fossil_trie
// *****************************************************************************

/**
 * @brief Create a new trie container with optional value type.
 *
 * @param value_type The type of values to store (may be NULL for key-only trie).
 * @return A pointer to the newly created trie.
 * @note O(1) - Constant time complexity.
 */
fossil_trie_t* fossil_trie_create(const char* value_type);

/**
 * @brief Create a default empty trie.
 *
 * @return A pointer to the newly created default trie.
 * @note O(1)
 */
fossil_trie_t* fossil_trie_create_default(void);

/**
 * @brief Create a deep copy of an existing trie.
 *
 * @param other The trie to copy.
 * @return A pointer to the newly created copy.
 * @note O(n) - Proportional to number of keys stored.
 */
fossil_trie_t* fossil_trie_create_copy(const fossil_trie_t* other);

/**
 * @brief Move an existing trie into a new one, leaving the source empty.
 *
 * @param other The trie to move.
 * @return A pointer to the new trie.
 * @note O(1)
 */
fossil_trie_t* fossil_trie_create_move(fossil_trie_t* other);

/**
 * @brief Destroy a trie and free all memory.
 *
 * @param trie The trie to destroy.
 * @note O(n) - Frees all nodes recursively.
 */
void fossil_trie_destroy(fossil_trie_t* trie);

/**
 * @brief Insert a key-value pair into the trie.
 *
 * @param trie The trie container.
 * @param key The string key to insert.
 * @param value The value string to associate with the key.
 * @return 0 on success, non-zero on failure.
 * @note O(k) where k = length of key.
 */
int32_t fossil_trie_insert(fossil_trie_t* trie, const char* key, const char* value);

/**
 * @brief Get the value associated with a key.
 *
 * @param trie The trie container.
 * @param key The string key to look up.
 * @return The associated value as `fossil_tofu_t`. Returns an empty tofu if key not found.
 * @note O(k) where k = length of key.
 */
fossil_tofu_t fossil_trie_get(const fossil_trie_t* trie, const char* key);

/**
 * @brief Remove a key from the trie.
 *
 * @param trie The trie container.
 * @param key The key to remove.
 * @return 0 on success, non-zero if key not found.
 * @note O(k)
 */
int32_t fossil_trie_remove(fossil_trie_t* trie, const char* key);

/**
 * @brief Check if the trie contains a key.
 *
 * @param trie The trie container.
 * @param key The key to search for.
 * @return True if the key exists, false otherwise.
 * @note O(k)
 */
bool fossil_trie_contains(const fossil_trie_t* trie, const char* key);

/**
 * @brief Get the number of keys stored in the trie.
 *
 * @param trie The trie container.
 * @return The number of keys.
 * @note O(1)
 */
size_t fossil_trie_size(const fossil_trie_t* trie);

/**
 * @brief Check if the trie is empty.
 *
 * @param trie The trie container.
 * @return True if empty, false otherwise.
 * @note O(1)
 */
bool fossil_trie_is_empty(const fossil_trie_t* trie);

/**
 * @brief Retrieve all keys with a given prefix.
 *
 * @param trie The trie container.
 * @param prefix The prefix to match.
 * @param out_keys A pointer to an array of strings (allocated by function).
 * @param out_count A pointer to store number of returned keys.
 * @return 0 on success, non-zero on failure.
 * @note O(p + m) where p = length of prefix, m = number of matches.
 */
int32_t fossil_trie_get_keys_with_prefix(const fossil_trie_t* trie, const char* prefix,
                                         char*** out_keys, size_t* out_count);

/**
 * @brief Clear all keys and values from the trie.
 *
 * @param trie The trie container.
 * @note O(n)
 */
void fossil_trie_clear(fossil_trie_t* trie);

/**
 * @brief Dump internal trie state for debugging.
 *
 * @param trie The trie container.
 */
void fossil_trie_dump(const fossil_trie_t* trie);

#ifdef __cplusplus
}

#include <vector>
#include <string>
#include <stdexcept>

namespace fossil {

namespace tofu {

    /**
     * @brief A C++ wrapper class for the fossil_trie_t structure.
     *
     * This class provides a modern C++ interface to the underlying C trie implementation,
     * allowing for safe and convenient management of trie containers and their contents.
     * All resource management is handled automatically, and exceptions are thrown on errors.
     */
    class Trie {
    public:
        /**
         * @brief Construct a new Trie object with optional value type.
         *
         * Creates a new trie container, optionally specifying the type of values to store.
         * If value_type is empty, the trie will store only keys.
         *
         * @param value_type The type of values to store (may be empty for key-only trie).
         * @throws std::runtime_error if the trie cannot be created.
         */
        Trie(const std::string& value_type) {
            trie = fossil_trie_create(value_type.empty() ? nullptr : value_type.c_str());
            if (!trie) throw std::runtime_error("Failed to create trie container");
        }

        /**
         * @brief Construct a new default Trie object.
         *
         * Creates a new empty trie container with default settings (key-only).
         *
         * @throws std::runtime_error if the trie cannot be created.
         */
        Trie() {
            trie = fossil_trie_create_default();
            if (!trie) throw std::runtime_error("Failed to create trie container");
        }

        /**
         * @brief Copy constructor.
         *
         * Creates a deep copy of another Trie object, duplicating all keys and values.
         *
         * @param other The Trie to copy.
         * @throws std::runtime_error if the copy operation fails.
         */
        Trie(const Trie& other) {
            trie = fossil_trie_create_copy(other.trie);
            if (!trie) throw std::runtime_error("Failed to copy trie container");
        }

        /**
         * @brief Move constructor.
         *
         * Transfers ownership of the underlying trie from another Trie object,
         * leaving the source empty and avoiding deep copy overhead.
         *
         * @param other The Trie to move from.
         * @throws std::runtime_error if the move operation fails.
         */
        Trie(Trie&& other) noexcept {
            trie = fossil_trie_create_move(other.trie);
            other.trie = nullptr;
            if (!trie) throw std::runtime_error("Failed to move trie container");
        }

        /**
         * @brief Destructor.
         *
         * Frees all resources associated with the trie container.
         */
        ~Trie() {
            fossil_trie_destroy(trie);
        }

        /**
         * @brief Insert a key-value pair into the trie.
         *
         * Adds the specified key and value to the trie. If the key already exists,
         * its value will be updated.
         *
         * @param key The key string to insert.
         * @param value The value string to associate with the key.
         * @return 0 on success, non-zero on failure.
         */
        int32_t insert(const std::string& key, const std::string& value) {
            return fossil_trie_insert(trie, key.c_str(), value.c_str());
        }

        /**
         * @brief Get the value associated with a key.
         *
         * Retrieves the value associated with the specified key. If the key does not exist,
         * returns an empty fossil_tofu_t value.
         *
         * @param key The key string to look up.
         * @return The associated value as fossil_tofu_t.
         */
        fossil_tofu_t get(const std::string& key) const {
            return fossil_trie_get(trie, key.c_str());
        }

        /**
         * @brief Remove a key from the trie.
         *
         * Deletes the specified key and its associated value from the trie.
         *
         * @param key The key string to remove.
         * @return 0 on success, non-zero if key not found.
         */
        int32_t remove(const std::string& key) {
            return fossil_trie_remove(trie, key.c_str());
        }

        /**
         * @brief Check if the trie contains a key.
         *
         * Determines whether the specified key exists in the trie.
         *
         * @param key The key string to search for.
         * @return True if the key exists, false otherwise.
         */
        bool contains(const std::string& key) const {
            return fossil_trie_contains(trie, key.c_str());
        }

        /**
         * @brief Get the number of keys stored in the trie.
         *
         * Returns the total number of keys currently stored in the trie.
         *
         * @return The number of keys.
         */
        size_t size() const {
            return fossil_trie_size(trie);
        }

        /**
         * @brief Check if the trie is empty.
         *
         * Determines whether the trie contains any keys.
         *
         * @return True if empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_trie_is_empty(trie);
        }

        /**
         * @brief Retrieve all keys with a given prefix.
         *
         * Finds and returns all keys in the trie that start with the specified prefix.
         *
         * @param prefix The prefix string to match.
         * @return A vector of matching key strings.
         */
        std::vector<std::string> get_keys_with_prefix(const std::string& prefix) const {
            char** keys = nullptr;
            size_t count = 0;
            int32_t res = fossil_trie_get_keys_with_prefix(trie, prefix.c_str(), &keys, &count);
            std::vector<std::string> result;
            if (res == 0 && keys) {
                for (size_t i = 0; i < count; ++i) {
                    result.emplace_back(keys[i]);
                    free(keys[i]);
                }
                free(keys);
            }
            return result;
        }

        /**
         * @brief Clear all keys and values from the trie.
         *
         * Removes all keys and values, leaving the trie empty.
         */
        void clear() {
            fossil_trie_clear(trie);
        }

        /**
         * @brief Dump internal trie state for debugging.
         *
         * Outputs the internal state of the trie to standard output for diagnostic purposes.
         */
        void dump() const {
            fossil_trie_dump(trie);
        }

    private:
        fossil_trie_t* trie; ///< Pointer to the underlying C trie container.
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
