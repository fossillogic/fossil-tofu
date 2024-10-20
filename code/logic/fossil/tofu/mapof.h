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

// Struct for map
typedef struct {
    fossil_tofu_t *keys;
    fossil_tofu_t *values;
    size_t size;
    size_t capacity;
} fossil_tofu_mapof_t;

/**
 * @brief Creates a new map with a given type.
 *
 * @param type The type of the map.
 * @return The created map.
 * @note Time complexity: O(1)
 */
fossil_tofu_mapof_t fossil_tofu_mapof_create(const char *type);

/**
 * @brief Adds a key-value pair to the map.
 *
 * @param map The map to add the key-value pair to.
 * @param key The key to add.
 * @param value The value to add.
 * @note Time complexity: O(1) on average, O(n) in the worst case due to resizing.
 */
void fossil_tofu_mapof_add(fossil_tofu_mapof_t *map, fossil_tofu_t key, fossil_tofu_t value);

/**
 * @brief Gets the value associated with the specified key from the map.
 *
 * @param map The map to get the value from.
 * @param key The key to get the value for.
 * @return The value associated with the key, or NULL if the key is not found.
 * @note Time complexity: O(1) on average, O(n) in the worst case.
 */
fossil_tofu_t fossil_tofu_mapof_get(fossil_tofu_mapof_t *map, fossil_tofu_t key);

/**
 * @brief Checks if the specified key exists in the map.
 *
 * @param map The map to check.
 * @param key The key to check for.
 * @return true if the key exists in the map, false otherwise.
 * @note Time complexity: O(1) on average, O(n) in the worst case.
 */
bool fossil_tofu_mapof_contains(fossil_tofu_mapof_t *map, fossil_tofu_t key);

/**
 * @brief Removes the key-value pair with the specified key from the map.
 *
 * @param map The map to remove the key-value pair from.
 * @param key The key to remove.
 * @note Time complexity: O(1) on average, O(n) in the worst case.
 */
void fossil_tofu_mapof_remove(fossil_tofu_mapof_t *map, fossil_tofu_t key);

/**
 * @brief Gets the number of key-value pairs in the map.
 *
 * @param map The map to get the size of.
 * @return The number of key-value pairs in the map.
 * @note Time complexity: O(1)
 */
size_t fossil_tofu_mapof_size(fossil_tofu_mapof_t *map);

/**
 * @brief Checks if the map is empty.
 *
 * @param map The map to check.
 * @return true if the map is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_tofu_mapof_is_empty(fossil_tofu_mapof_t *map);

/**
 * @brief Clears all key-value pairs from the map.
 *
 * @param map The map to clear.
 * @note Time complexity: O(n)
 */
void fossil_tofu_mapof_clear(fossil_tofu_mapof_t *map);

/**
 * @brief Destroys the map and frees the allocated memory.
 *
 * @param map The map to destroy.
 * @note Time complexity: O(n)
 */
void fossil_tofu_mapof_destroy(fossil_tofu_mapof_t *map);

/**
 * @brief Prints the contents of the map.
 *
 * @param map The map to print.
 * @note Time complexity: O(n)
 */
void fossil_tofu_mapof_print(fossil_tofu_mapof_t *map);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace fossil {
    class Map {
    public:
        Map(const std::string &type) : map_(fossil_tofu_mapof_create(type.c_str())) {}

        ~Map() {
            fossil_tofu_mapof_destroy(&map_);
        }

        void add(fossil_tofu_t key, fossil_tofu_t value) {
            fossil_tofu_mapof_add(&map_, key, value);
        }

        fossil_tofu_t get(fossil_tofu_t key) {
            return fossil_tofu_mapof_get(&map_, key);
        }

        bool contains(fossil_tofu_t key) {
            return fossil_tofu_mapof_contains(&map_, key);
        }

        void remove(fossil_tofu_t key) {
            fossil_tofu_mapof_remove(&map_, key);
        }

        size_t size() {
            return fossil_tofu_mapof_size(&map_);
        }

        bool is_empty() {
            return fossil_tofu_mapof_is_empty(&map_);
        }

        void clear() {
            fossil_tofu_mapof_clear(&map_);
        }

        void print() {
            fossil_tofu_mapof_print(&map_);
        }

    private:
        fossil_tofu_mapof_t map_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
