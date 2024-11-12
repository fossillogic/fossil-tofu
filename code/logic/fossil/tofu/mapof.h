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
    char *type;
} fossil_map_t;

/**
 * @brief Creates a new map with a given type.
 *
 * @param type The type of the map.
 * @return The created map.
 * @note Time complexity: O(1)
 */
fossil_map_t fossil_map_create_container(const char *type);

/**
 * @brief Creates a new map with a given type and initial capacity.
 *
 * @param type The type of the map.
 * @param size The initial capacity of the map.
 * @return The created map.
 * @note Time complexity: O(1)
 */
fossil_map_t fossil_map_create_with(const char *type, size_t size, ...);

/**
 * @brief Destroys the map and frees the allocated memory.
 *
 * @param map The map to destroy.
 * @note Time complexity: O(n)
 */
void fossil_map_destroy(fossil_map_t *map);

/**
 * @brief Adds a key-value pair to the map.
 *
 * @param map The map to add the key-value pair to.
 * @param key The key to add.
 * @param value The value to add.
 * @note Time complexity: O(1) on average, O(n) in the worst case due to resizing.
 */
void fossil_map_add(fossil_map_t *map, fossil_tofu_t key, fossil_tofu_t value);

/**
 * @brief Gets the value associated with the specified key from the map.
 *
 * @param map The map to get the value from.
 * @param key The key to get the value for.
 * @return The value associated with the key, or NULL if the key is not found.
 * @note Time complexity: O(1) on average, O(n) in the worst case.
 */
fossil_tofu_t fossil_map_get(fossil_map_t *map, fossil_tofu_t key);

/**
 * @brief Checks if the specified key exists in the map.
 *
 * @param map The map to check.
 * @param key The key to check for.
 * @return true if the key exists in the map, false otherwise.
 * @note Time complexity: O(1) on average, O(n) in the worst case.
 */
bool fossil_map_contains(fossil_map_t *map, fossil_tofu_t key);

/**
 * @brief Removes the key-value pair with the specified key from the map.
 *
 * @param map The map to remove the key-value pair from.
 * @param key The key to remove.
 * @note Time complexity: O(1) on average, O(n) in the worst case.
 */
void fossil_map_remove(fossil_map_t *map, fossil_tofu_t key);

/**
 * @brief Gets the number of key-value pairs in the map.
 *
 * @param map The map to get the size of.
 * @return The number of key-value pairs in the map.
 * @note Time complexity: O(1)
 */
size_t fossil_map_size(fossil_map_t *map);

/**
 * @brief Gets the capacity of the map.
 *
 * @param map The map to get the capacity of.
 * @return The capacity of the map.
 * @note Time complexity: O(1)
 */
size_t fossil_map_capacity(fossil_map_t *map);

/**
 * @brief Checks if the map is empty.
 *
 * @param map The map to check.
 * @return true if the map is empty, false otherwise.
 * @note Time complexity: O(1)
 */
bool fossil_map_is_empty(fossil_map_t *map);

/**
 * @brief Clears all key-value pairs from the map.
 *
 * @param map The map to clear.
 * @note Time complexity: O(n)
 */
void fossil_map_clear(fossil_map_t *map);

/**
 * @brief Prints the contents of the map.
 *
 * @param map The map to print.
 * @note Time complexity: O(n)
 */
void fossil_map_print(fossil_map_t *map);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
