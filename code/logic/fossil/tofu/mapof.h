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

typedef struct fossil_mapof_node_t {
    fossil_tofu_t key;
    fossil_tofu_t value;
    struct fossil_mapof_node_t* next;
} fossil_mapof_node_t;

typedef struct fossil_mapof_t {
    char* key_type;
    char* value_type;
    fossil_mapof_node_t* head;
    size_t size;
} fossil_mapof_t;

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
fossil_mapof_t* fossil_mapof_create_container(char* key_type, char* value_type);

/**
 * @brief Create a new map container with default key and value types.
 *
 * @return A pointer to the newly created map container.
 */
fossil_mapof_t* fossil_mapof_create_default(void);

/**
 * @brief Create a copy of an existing map container.
 *
 * @param other The map container to copy.
 * @return A pointer to the newly created copy of the map container.
 */
fossil_mapof_t* fossil_mapof_create_copy(const fossil_mapof_t* other);

/**
 * @brief Move an existing map container to a new map container.
 *
 * @param other The map container to move.
 * @return A pointer to the newly created map container.
 */
fossil_mapof_t* fossil_mapof_create_move(fossil_mapof_t* other);

/**
 * @brief Destroy a map container and free its memory.
 *
 * @param map The map container to destroy.
 */
void fossil_mapof_destroy(fossil_mapof_t* map);

/**
 * @brief Insert a key-value pair into the map.
 *
 * @param map The map container.
 * @param key The key to insert.
 * @param value The value to insert.
 * @return 0 on success, non-zero on failure.
 * @note Time complexity: O(n)
 */
int32_t fossil_mapof_insert(fossil_mapof_t* map, char *key, char *value);

/**
 * @brief Remove a key-value pair from the map.
 *
 * @param map The map container.
 * @param key The key to remove.
 * @return 0 on success, non-zero on failure.
 * @note Time complexity: O(n)
 */
int32_t fossil_mapof_remove(fossil_mapof_t* map, char *key);

/**
 * @brief Check if the map contains a key.
 *
 * @param map The map container.
 * @param key The key to check.
 * @return True if the key is found, false otherwise.
 * @note Time complexity: O(n)
 */
bool fossil_mapof_contains(const fossil_mapof_t* map, char *key);

/**
 * @brief Get the value associated with a key in the map.
 *
 * @param map The map container.
 * @param key The key to look up.
 * @return The value associated with the key.
 * @note Time complexity: O(n)
 */
fossil_tofu_t fossil_mapof_get(const fossil_mapof_t* map, char *key);

/**
 * @brief Set the value associated with a key in the map.
 *
 * @param map The map container.
 * @param key The key to set.
 * @param value The value to set.
 * @return 0 on success, non-zero on failure.
 * @note Time complexity: O(n)
 */
int32_t fossil_mapof_set(fossil_mapof_t* map, char *key, char *value);

/**
 * @brief Get the number of elements in the map.
 *
 * @param map The map container.
 * @return The number of elements in the map.
 * @note Time complexity: O(1)
 */
size_t fossil_mapof_size(const fossil_mapof_t* map);

/**
 * @brief Check if the map is not empty.
 *
 * @param map The map container.
 * @return True if the map is not empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_mapof_not_empty(const fossil_mapof_t* map);

/**
 * @brief Check if the map is empty.
 *
 * @param map The map container.
 * @return True if the map is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_mapof_is_empty(const fossil_mapof_t* map);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

namespace tofu {

    /**
     * @brief A C++ wrapper class for the fossil_mapof_t structure.
     */
    class MapOf {
    public:
        /**
         * @brief Construct a new MapOf object with specified key and value types.
         *
         * @param key_type The type of the keys.
         * @param value_type The type of the values.
         */
        MapOf(char* key_type, char* value_type) {
            map = fossil_mapof_create_container(key_type, value_type);
            if (map == nullptr) {
                throw std::runtime_error("Failed to create map container");
            }
        }

        /**
         * @brief Construct a new MapOf object with default key and value types.
         */
        MapOf() {
            map = fossil_mapof_create_default();
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
            map = fossil_mapof_create_copy(other.map);
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
            map = fossil_mapof_create_move(other.map);
            if (map == nullptr) {
                throw std::runtime_error("Failed to create map container");
            }
        }

        /**
         * @brief Destroy the MapOf object and free its memory.
         */
        ~MapOf() {
            fossil_mapof_destroy(map);
        }

        /**
         * @brief Insert a key-value pair into the map.
         *
         * @param key The key to insert.
         * @param value The value to insert.
         * @return 0 on success, non-zero on failure.
         */
        int32_t insert(char *key, char *value) {
            return fossil_mapof_insert(map, key, value);
        }

        /**
         * @brief Remove a key-value pair from the map.
         *
         * @param key The key to remove.
         * @return 0 on success, non-zero on failure.
         */
        int32_t remove(char *key) {
            return fossil_mapof_remove(map, key);
        }

        /**
         * @brief Check if the map contains a key.
         *
         * @param key The key to check.
         * @return True if the key is found, false otherwise.
         */
        bool contains(char *key) {
            return fossil_mapof_contains(map, key);
        }

        /**
         * @brief Get the value associated with a key in the map.
         *
         * @param key The key to look up.
         * @return The value associated with the key.
         */
        fossil_tofu_t get(char *key) {
            return fossil_mapof_get(map, key);
        }

        /**
         * @brief Set the value associated with a key in the map.
         *
         * @param key The key to set.
         * @param value The value to set.
         * @return 0 on success, non-zero on failure.
         */
        int32_t set(char *key, char *value) {
            return fossil_mapof_set(map, key, value);
        }

        /**
         * @brief Get the number of elements in the map.
         *
         * @return The number of elements in the map.
         */
        size_t size() {
            return fossil_mapof_size(map);
        }

        /**
         * @brief Check if the map is not empty.
         *
         * @return True if the map is not empty, false otherwise.
         */
        bool not_empty() {
            return fossil_mapof_not_empty(map);
        }

        /**
         * @brief Check if the map is empty.
         *
         * @return True if the map is empty, false otherwise.
         */
        bool is_empty() {
            return fossil_mapof_is_empty(map);
        }

    private:
        fossil_mapof_t* map; ///< Pointer to the underlying C map structure.
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
