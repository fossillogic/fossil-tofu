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
#ifndef FOSSIL_TOFU_SKIPLIST_H
#define FOSSIL_TOFU_SKIPLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Node structure for the skip list
typedef struct fossil_slist_node_t {
    fossil_tofu_t data;
    struct fossil_slist_node_t** forward;
    int level;
} fossil_slist_node_t;

// Skip list structure
typedef struct fossil_slist_t {
    fossil_slist_node_t* header;
    int max_level;
    float probability;
    char* type;
} fossil_slist_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new skip list with the specified data type.
 *
 * @param list_type The type of data the skip list will store.
 * @param max_level The maximum level of the skip list.
 * @param probability The probability factor for level generation.
 * @return          The created skip list.
 * @complexity      O(1)
 */
fossil_slist_t* fossil_slist_create_container(char* type, int max_level, float probability);

/**
 * Create a new skip list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created skip list.
 */
fossil_slist_t* fossil_slist_create_default(void);

/**
 * Create a new skip list by copying an existing skip list.
 * 
 * Time complexity: O(n)
 *
 * @param other The skip list to copy.
 * @return      The created skip list.
 */
fossil_slist_t* fossil_slist_create_copy(const fossil_slist_t* other);

/**
 * Create a new skip list by moving an existing skip list.
 * 
 * Time complexity: O(1)
 *
 * @param other The skip list to move.
 * @return      The created skip list.
 */
fossil_slist_t* fossil_slist_create_move(fossil_slist_t* other);

/**
 * Erase the contents of the skip list and free allocated memory.
 *
 * @param slist The skip list to erase.
 * @complexity  O(n)
 */
void fossil_slist_destroy(fossil_slist_t* slist);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the skip list.
 *
 * @param slist The skip list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(log n)
 */
int32_t fossil_slist_insert(fossil_slist_t* slist, char *data);

/**
 * Remove data from the skip list.
 *
 * @param slist The skip list to remove data from.
 * @param data  The data to remove.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(log n)
 */
int32_t fossil_slist_remove(fossil_slist_t* slist, char *data);

/**
 * Get the size of the skip list.
 *
 * @param slist The skip list for which to get the size.
 * @return      The size of the skip list.
 * @complexity  O(n)
 */
size_t fossil_slist_size(const fossil_slist_t* slist);

/**
 * Check if the skip list is not empty.
 *
 * @param slist The skip list to check.
 * @return      True if the skip list is not empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_slist_not_empty(const fossil_slist_t* slist);

/**
 * Check if the skip list is empty.
 *
 * @param slist The skip list to check.
 * @return      True if the skip list is empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_slist_is_empty(const fossil_slist_t* slist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Find an element in the skip list.
 * 
 * Time complexity: O(log n)
 *
 * @param slist The skip list in which to search for the element.
 * @param data  The data to search for.
 * @return      True if the element is found, false otherwise.
 */
bool fossil_slist_find(const fossil_slist_t* slist, char *data);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

namespace tofu {

    class SList {
    public:
        /**
         * Constructor to create a skip list with a specified data type.
         *
         * @param type The type of data the skip list will store.
         * @param max_level The maximum level of the skip list.
         * @param probability The probability factor for level generation.
         */
        SList(char* type, int max_level, float probability) {
            slist = fossil_slist_create_container(type, max_level, probability);
        }

        /**
         * Default constructor to create a skip list with default values.
         */
        SList() {
            slist = fossil_slist_create_default();
        }

        /**
         * Copy constructor to create a skip list by copying another skip list.
         *
         * @param other The skip list to copy.
         */
        SList(const SList& other) {
            slist = fossil_slist_create_copy(other.slist);
        }

        /**
         * Move constructor to create a skip list by moving another skip list.
         *
         * @param other The skip list to move.
         */
        SList(SList&& other) noexcept {
            slist = fossil_slist_create_move(other.slist);
            other.slist = nullptr;
        }

        /**
         * Destructor to destroy the skip list and free allocated memory.
         */
        ~SList() {
            fossil_slist_destroy(slist);
        }

        /**
         * Insert data into the skip list.
         *
         * @param data The data to insert.
         */
        void insert(char* data) {
            fossil_slist_insert(slist, data);
        }

        /**
         * Remove data from the skip list.
         *
         * @param data The data to remove.
         */
        void remove(char* data) {
            fossil_slist_remove(slist, data);
        }

        /**
         * Get the size of the skip list.
         *
         * @return The size of the skip list.
         */
        size_t size() const {
            return fossil_slist_size(slist);
        }

        /**
         * Check if the skip list is not empty.
         *
         * @return True if the skip list is not empty, false otherwise.
         */
        bool not_empty() const {
            return fossil_slist_not_empty(slist);
        }

        /**
         * Check if the skip list is empty.
         *
         * @return True if the skip list is empty, false otherwise.
         */
        bool is_empty() const {
            return fossil_slist_is_empty(slist);
        }

        /**
         * Find an element in the skip list.
         *
         * @param data The data to search for.
         * @return True if the element is found, false otherwise.
         */
        bool find(char* data) const {
            return fossil_slist_find(slist, data);
        }

    private:
        /**
         * Pointer to the underlying fossil_slist_t structure.
         */
        fossil_slist_t* slist;
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
