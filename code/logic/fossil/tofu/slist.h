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
    size_t level;
} fossil_slist_node_t;

// Skip list structure
typedef struct fossil_slist_t {
    fossil_slist_node_t* head;
    size_t max_level;
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
 * @return          The created skip list.
 * @note            Time complexity: O(1)
 */
fossil_slist_t* fossil_slist_create_container(char* type);

/**
 * Create a new skip list with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created skip list.
 */
fossil_slist_t* fossil_slist_create_default(void);

/**
 * Create a new skip list by copying an existing list.
 * 
 * Time complexity: O(n log n)
 *
 * @param other The skip list to copy.
 * @return      The created skip list.
 */
fossil_slist_t* fossil_slist_create_copy(const fossil_slist_t* other);

/**
 * Create a new skip list by moving an existing list.
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
 * @note        Time complexity: O(n)
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
 * @note        Time complexity: O(log n)
 */
int32_t fossil_slist_insert(fossil_slist_t* slist, char *data);

/**
 * Remove data from the skip list.
 *
 * @param slist The skip list to remove data from.
 * @param data  The data to remove.
 * @return      The error code indicating the success or failure of the operation.
 * @note        Time complexity: O(log n)
 */
int32_t fossil_slist_remove(fossil_slist_t* slist, char *data);

/**
 * Get the size of the skip list.
 *
 * @param slist The skip list for which to get the size.
 * @return      The size of the skip list.
 * @note        Time complexity: O(n)
 */
size_t fossil_slist_size(const fossil_slist_t* slist);

/**
 * Check if the skip list is not empty.
 *
 * @param slist The skip list to check.
 * @return      True if the skip list is not empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_slist_not_empty(const fossil_slist_t* slist);

/**
 * Check if the skip list is not a null pointer.
 *
 * @param slist The skip list to check.
 * @return      True if the skip list is not a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_slist_not_cnullptr(const fossil_slist_t* slist);

/**
 * Check if the skip list is empty.
 *
 * @param slist The skip list to check.
 * @return      True if the skip list is empty, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_slist_is_empty(const fossil_slist_t* slist);

/**
 * Check if the skip list is a null pointer.
 *
 * @param slist The skip list to check.
 * @return      True if the skip list is a null pointer, false otherwise.
 * @note        Time complexity: O(1)
 */
bool fossil_slist_is_cnullptr(const fossil_slist_t* slist);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Search for an element in the skip list.
 * 
 * Time complexity: O(log n)
 *
 * @param slist The skip list to search in.
 * @param key   The key to search for.
 * @return      The element found or NULL if not found.
 */
char *fossil_slist_search(const fossil_slist_t* slist, char *key);

/**
 * Get the first element in the skip list.
 * 
 * Time complexity: O(1)
 *
 * @param slist The skip list from which to get the first element.
 * @return      The first element in the skip list.
 */
char *fossil_slist_get_front(const fossil_slist_t* slist);

/**
 * Get the last element in the skip list.
 * 
 * Time complexity: O(1)
 *
 * @param slist The skip list from which to get the last element.
 * @return      The last element in the skip list.
 */
char *fossil_slist_get_back(const fossil_slist_t* slist);

#ifdef __cplusplus
}
#include <stdexcept>

namespace fossil {

namespace tofu {

    class SList {
    public:
        /**
         * Constructor to create a skip list with a specified type.
         *
         * @param type The type of data the skip list will store.
         * @throws std::runtime_error If the list creation fails.
         */
        SList(char* type) : slist(fossil_slist_create_container(type)) {
            if (slist == nullptr) {
                throw std::runtime_error("Failed to create skip list.");
            }
        }

        /**
         * Default constructor to create a skip list with default values.
         *
         * @throws std::runtime_error If the list creation fails.
         */
        SList() : slist(fossil_slist_create_default()) {
            if (slist == nullptr) {
                throw std::runtime_error("Failed to create skip list.");
            }
        }

        // Destructor to clean up the skip list
        ~SList() {
            fossil_slist_destroy(slist);
        }

        // Other member functions can be added here
        // to manipulate the skip list, such as insert, remove, etc.
        int32_t insert(char *data) {
            return fossil_slist_insert(slist, data);
        }

        int32_t remove(char *data) {
            return fossil_slist_remove(slist, data);
        }

        size_t size() const {
            return fossil_slist_size(slist);
        }

        bool not_empty() const {
            return fossil_slist_not_empty(slist);
        }

        bool not_cnullptr() const {
            return fossil_slist_not_cnullptr(slist);
        }

        bool is_empty() const {
            return fossil_slist_is_empty(slist);
        }

        bool is_cnullptr() const {
            return fossil_slist_is_cnullptr(slist);
        }

        char *search(char *key) const {
            return fossil_slist_search(slist, key);
        }

        char *get_front() const {
            return fossil_slist_get_front(slist);
        }

        char *get_back() const {
            return fossil_slist_get_back(slist);
        }

    private:
        fossil_slist_t* slist; // Pointer to the skip list

    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
