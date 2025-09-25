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
#ifndef FOSSIL_TOFU_MAPOF_H
#define FOSSIL_TOFU_MAPOF_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

typedef struct fossil_tofu_mapof_node_t {
    fossil_tofu_t key;
    fossil_tofu_t value;
    struct fossil_tofu_mapof_node_t* next;
} fossil_tofu_mapof_node_t;

typedef struct fossil_tofu_mapof_t {
    char* key_type;
    char* value_type;
    fossil_tofu_mapof_node_t* head;
    size_t size;
} fossil_tofu_mapof_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * @brief Create a new map container with specified key and value types.
 *
 * @param key_type The type of the keys.
 * @param value_type The type of the values.
 * @return A pointer to the newly created map container.
 */
fossil_tofu_mapof_t* fossil_tofu_mapof_create_container(char* key_type, char* value_type);

/**
 * @brief Create a new map container with default key and value types.
 *
 * @return A pointer to the newly created map container.
 */
fossil_tofu_mapof_t* fossil_tofu_mapof_create_default(void);

/**
 * @brief Create a copy of an existing map container.
 *
 * @param other The map container to copy.
 * @return A pointer to the newly created copy of the map container.
 */
fossil_tofu_mapof_t* fossil_tofu_mapof_create_copy(const fossil_tofu_mapof_t* other);

/**
 * @brief Move an existing map container to a new map container.
 *
 * @param other The map container to move.
 * @return A pointer to the newly created map container.
 */
fossil_tofu_mapof_t* fossil_tofu_mapof_create_move(fossil_tofu_mapof_t* other);

/**
 * @brief Destroy a map container and free its memory.
 *
 * @param map The map container to destroy.
 */
void fossil_tofu_mapof_destroy(fossil_tofu_mapof_t* map);

/**
 * @brief Insert a key-value pair into the map.
 *
 * @param map The map container.
 * @param key The key to insert.
 * @param value The value to insert.
 * @return 0 on success, non-zero on failure.
 * @note Time complexity: O(n)
 */
int32_t fossil_tofu_mapof_insert(fossil_tofu_mapof_t* map, char *key, char *value);

/**
 * @brief Remove a key-value pair from the map.
 *
 * @param map The map container.
 * @param key The key to remove.
 * @return 0 on success, non-zero on failure.
 * @note Time complexity: O(n)
 */
int32_t fossil_tofu_mapof_remove(fossil_tofu_mapof_t* map, char *key);

/**
 * @brief Check if the map contains a key.
 *
 * @param map The map container.
 * @param key The key to check.
 * @return True if the key is found, false otherwise.
 * @note Time complexity: O(n)
 */
bool fossil_tofu_mapof_contains(const fossil_tofu_mapof_t* map, char *key);

/**
 * @brief Get the value associated with a key in the map.
 *
 * @param map The map container.
 * @param key The key to look up.
 * @return The value associated with the key.
 * @note Time complexity: O(n)
 */
fossil_tofu_t fossil_tofu_mapof_get(const fossil_tofu_mapof_t* map, char *key);

/**
 * @brief Set the value associated with a key in the map.
 *
 * @param map The map container.
 * @param key The key to set.
 * @param value The value to set.
 * @return 0 on success, non-zero on failure.
 * @note Time complexity: O(n)
 */
int32_t fossil_tofu_mapof_set(fossil_tofu_mapof_t* map, char *key, char *value);

/**
 * @brief Get the number of elements in the map.
 *
 * @param map The map container.
 * @return The number of elements in the map.
 * @note Time complexity: O(1)
 */
size_t fossil_tofu_mapof_size(const fossil_tofu_mapof_t* map);

/**
 * @brief Check if the map is not empty.
 *
 * @param map The map container.
 * @return True if the map is not empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_tofu_mapof_not_empty(const fossil_tofu_mapof_t* map);

/**
 * @brief Check if the map is empty.
 *
 * @param map The map container.
 * @return True if the map is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_tofu_mapof_is_empty(const fossil_tofu_mapof_t* map);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

    namespace tofu {

        /**
         * @brief A C++ wrapper class for the fossil_tofu_mapof_t structure.
         */
        class MapOf {
        public:
            /**
             * @brief Construct a new MapOf object with specified key and value types.
             *
             * @param key_type The type of the keys.
             * @param value_type The type of the values.
             */
            MapOf(const std::string& key_type, const std::string& value_type) {
                map = fossil_tofu_mapof_create_container(const_cast<char*>(key_type.c_str()), const_cast<char*>(value_type.c_str()));
                if (map == nullptr) {
                throw std::runtime_error("Failed to create map container");
                }
            }

            /**
             * @brief Construct a new MapOf object with default key and value types.
             */
            MapOf() {
                map = fossil_tofu_mapof_create_default();
                if (map == nullptr) {
                    throw std::runtime_error("Failed to create map container");
                }
            }

            /**
             * @brief Construct a new MapOf object by copying an existing MapOf object.
             *
             * @param other The MapOf object to copy.
             */
            MapOf(const MapOf& other) {
                map = fossil_tofu_mapof_create_copy(other.map);
                if (map == nullptr) {
                    throw std::runtime_error("Failed to create map container");
                }
            }

            /**
             * @brief Construct a new MapOf object by moving an existing MapOf object.
             *
             * @param other The MapOf object to move.
             */
            MapOf(MapOf&& other) {
                map = fossil_tofu_mapof_create_move(other.map);
                if (map == nullptr) {
                    throw std::runtime_error("Failed to create map container");
                }
            }

            /**
             * @brief Destroy the MapOf object and free its memory.
             */
            ~MapOf() {
                fossil_tofu_mapof_destroy(map);
            }

            /**
             * @brief Insert a key-value pair into the map.
             *
             * @param key The key to insert.
             * @param value The value to insert.
             * @return 0 on success, non-zero on failure.
             */
            int32_t insert(const std::string& key, const std::string& value) {
                return fossil_tofu_mapof_insert(map, const_cast<char*>(key.c_str()), const_cast<char*>(value.c_str()));
            }

            /**
             * @brief Remove a key-value pair from the map.
             *
             * @param key The key to remove.
             * @return 0 on success, non-zero on failure.
             */
            int32_t remove(const std::string& key) {
                return fossil_tofu_mapof_remove(map, const_cast<char*>(key.c_str()));
            }

            /**
             * @brief Check if the map contains a key.
             *
             * @param key The key to check.
             * @return True if the key is found, false otherwise.
             */
            bool contains(const std::string& key) {
                return fossil_tofu_mapof_contains(map, const_cast<char*>(key.c_str()));
            }

            /**
             * @brief Get the value associated with a key in the map.
             *
             * @param key The key to look up.
             * @return The value associated with the key.
             */
            fossil_tofu_t get(const std::string& key) {
                return fossil_tofu_mapof_get(map, const_cast<char*>(key.c_str()));
            }

            /**
             * @brief Set the value associated with a key in the map.
             *
             * @param key The key to set.
             * @param value The value to set.
             * @return 0 on success, non-zero on failure.
             */
            int32_t set(const std::string& key, const std::string& value) {
                return fossil_tofu_mapof_set(map, const_cast<char*>(key.c_str()), const_cast<char*>(value.c_str()));
            }

            /**
             * @brief Get the number of elements in the map.
             *
             * @return The number of elements in the map.
             */
            size_t size() {
                return fossil_tofu_mapof_size(map);
            }

            /**
             * @brief Check if the map is not empty.
             *
             * @return True if the map is not empty, false otherwise.
             */
            bool not_empty() {
                return fossil_tofu_mapof_not_empty(map);
            }

            /**
             * @brief Check if the map is empty.
             *
             * @return True if the map is empty, false otherwise.
             */
            bool is_empty() {
                return fossil_tofu_mapof_is_empty(map);
            }

        private:
            fossil_tofu_mapof_t* map; ///< Pointer to the underlying C map structure.
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
