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
#ifndef FOSSIL_TOFU_SETOF_H
#define FOSSIL_TOFU_SETOF_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Set structure
typedef struct fossil_setof_node_t {
    fossil_tofu_t data; // Data stored in the set node
    struct fossil_setof_node_t* next; // Pointer to the next node
} fossil_setof_node_t;

typedef struct fossil_setof_t {
    char* type; // Type of the set
    fossil_setof_node_t* head; // Pointer to the head node of the set
    size_t size; // Number of elements in the set
} fossil_setof_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * @brief Creates a new container for a set of the specified type.
 *
 * @param type The type of elements that the set will contain.
 * @return A pointer to the newly created set container.
 */
fossil_setof_t* fossil_setof_create_container(char* type);

/**
 * @brief Creates a new set with default settings.
 *
 * @return A pointer to the newly created default set.
 */
fossil_setof_t* fossil_setof_create_default(void);

/**
 * @brief Creates a copy of the given set.
 *
 * @param other The set to copy.
 * @return A pointer to the newly created copy of the set.
 */
fossil_setof_t* fossil_setof_create_copy(const fossil_setof_t* other);

/**
 * @brief Moves the given set to a new set container.
 *
 * @param other The set to move.
 * @return A pointer to the newly created set container with the moved set.
 */
fossil_setof_t* fossil_setof_create_move(fossil_setof_t* other);

/**
 * @brief Destroys the given set and frees its resources.
 *
 * @param set The set to destroy.
 */
void fossil_setof_destroy(fossil_setof_t* set);

/**
 * @brief Inserts data into the set.
 *
 * @param set The set to insert data into.
 * @param data The data to insert.
 * @return An integer indicating success (0) or failure (non-zero).
 */
int32_t fossil_setof_insert(fossil_setof_t* set, char *data);

/**
 * @brief Removes data from the set.
 *
 * @param set The set to remove data from.
 * @param data The data to remove.
 * @return An integer indicating success (0) or failure (non-zero).
 */
int32_t fossil_setof_remove(fossil_setof_t* set, char *data);

/**
 * @brief Checks if the set contains the specified data.
 *
 * @param set The set to check.
 * @param data The data to check for.
 * @return True if the set contains the data, false otherwise.
 */
bool fossil_setof_contains(const fossil_setof_t* set, char *data);

/**
 * @brief Gets the number of elements in the set.
 *
 * @param set The set to get the size of.
 * @return The number of elements in the set.
 */
size_t fossil_setof_size(const fossil_setof_t* set);

/**
 * @brief Checks if the set is not empty.
 *
 * @param set The set to check.
 * @return True if the set is not empty, false otherwise.
 */
bool fossil_setof_not_empty(const fossil_setof_t* set);

/**
 * @brief Checks if the set is empty.
 *
 * @param set The set to check.
 * @return True if the set is empty, false otherwise.
 */
bool fossil_setof_is_empty(const fossil_setof_t* set);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

namespace tofu {

    class SetOf {
    public:
        /**
         * @brief Constructs a new SetOf object with the specified type.
         *
         * @param type The type of elements that the set will contain.
         */
        SetOf(char* type) {
            set = fossil_setof_create_container(type);
            if (set == nullptr) {
                throw std::runtime_error("Failed to create set container");
            }
        }

        /**
         * @brief Constructs a new SetOf object with default settings.
         */
        SetOf() {
            set = fossil_setof_create_default();
            if (set == nullptr) {
                throw std::runtime_error("Failed to create set container");
            }
        }

        /**
         * @brief Constructs a new SetOf object by copying another SetOf object.
         *
         * @param other The SetOf object to copy.
         */
        SetOf(const SetOf& other) {
            set = fossil_setof_create_copy(other.set);
            if (set == nullptr) {
                throw std::runtime_error("Failed to create set container");
            }
        }

        /**
         * @brief Constructs a new SetOf object by moving another SetOf object.
         *
         * @param other The SetOf object to move.
         */
        SetOf(SetOf&& other) {
            set = fossil_setof_create_move(other.set);
            if (set == nullptr) {
                throw std::runtime_error("Failed to create set container");
            }
        }

        /**
         * @brief Destroys the SetOf object and frees its resources.
         */
        ~SetOf() {
            fossil_setof_destroy(set);
        }

        /**
         * @brief Inserts data into the set.
         *
         * @param data The data to insert.
         * @return An integer indicating success (0) or failure (non-zero).
         */
        int32_t insert(char *data) {
            return fossil_setof_insert(set, data);
        }

        /**
         * @brief Removes data from the set.
         *
         * @param data The data to remove.
         * @return An integer indicating success (0) or failure (non-zero).
         */
        int32_t remove(char *data) {
            return fossil_setof_remove(set, data);
        }

        /**
         * @brief Checks if the set contains the specified data.
         *
         * @param data The data to check for.
         * @return True if the set contains the data, false otherwise.
         */
        bool contains(char *data) {
            return fossil_setof_contains(set, data);
        }

        /**
         * @brief Gets the number of elements in the set.
         *
         * @return The number of elements in the set.
         */
        size_t size() {
            return fossil_setof_size(set);
        }

        /**
         * @brief Checks if the set is not empty.
         *
         * @return True if the set is not empty, false otherwise.
         */
        bool not_empty() {
            return fossil_setof_not_empty(set);
        }

        /**
         * @brief Checks if the set is empty.
         *
         * @return True if the set is empty, false otherwise.
         */
        bool is_empty() {
            return fossil_setof_is_empty(set);
        }

    private:
        fossil_setof_t* set; ///< Pointer to the underlying set structure.
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
