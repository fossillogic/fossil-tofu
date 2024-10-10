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

// Node structure for the set
typedef struct fossil_set_node_t {
    fossil_tofu_t data;
    struct fossil_set_node_t* next;
} fossil_set_node_t;

// Set structure
typedef struct fossil_set_t {
    fossil_set_node_t* head;
    char* type;
} fossil_set_t;

/**
 * Create a new set with the specified data type.
 *
 * @param list_type The type of data the set will store.
 * @return          The created set.
 */
fossil_set_t* fossil_set_create(char* type);

/**
 * Erase the contents of the set and free allocated memory.
 *
 * @param set The set to erase.
 */
void fossil_set_erase(fossil_set_t* set);

/**
 * Insert data into the set.
 *
 * @param set  The set to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_insert(fossil_set_t* set, fossil_tofu_t data);

/**
 * Remove data from the set.
 *
 * @param set  The set to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_remove(fossil_set_t* set, fossil_tofu_t data);

/**
 * Search for data in the set.
 *
 * @param set  The set to search.
 * @param data The data to search for.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_search(const fossil_set_t* set, fossil_tofu_t data);

/**
 * Get the size of the set.
 *
 * @param set The set for which to get the size.
 * @return    The size of the set.
 */
size_t fossil_set_size(const fossil_set_t* set);

/**
 * Get the data from the set matching the specified data.
 *
 * @param set  The set from which to get the data.
 * @param data The data to search for.
 * @return     A pointer to the matching data, or NULL if not found.
 */
fossil_tofu_t* fossil_set_getter(fossil_set_t* set, fossil_tofu_t data);

/**
 * Set data in the set.
 *
 * @param set  The set in which to set the data.
 * @param data The data to set.
 * @return     The error code indicating the success or failure of the operation.
 */
int32_t fossil_set_setter(fossil_set_t* set, fossil_tofu_t data);

/**
 * Check if the set is not empty.
 *
 * @param set The set to check.
 * @return    True if the set is not empty, false otherwise.
 */
bool fossil_set_not_empty(const fossil_set_t* set);

/**
 * Check if the set is not a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is not a null pointer, false otherwise.
 */
bool fossil_set_not_cnullptr(const fossil_set_t* set);

/**
 * Check if the set is empty.
 *
 * @param set The set to check.
 * @return    True if the set is empty, false otherwise.
 */
bool fossil_set_is_empty(const fossil_set_t* set);

/**
 * Check if the set is a null pointer.
 *
 * @param set The set to check.
 * @return    True if the set is a null pointer, false otherwise.
 */
bool fossil_set_is_cnullptr(const fossil_set_t* set);

/**
 * Check if the set contains a specific element.
 *
 * @param set  The set to check.
 * @param data The data to search for.
 * @return     True if the set contains the element, false otherwise.
 */
int32_t fossil_set_contains(const fossil_set_t* set, fossil_tofu_t data);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace fossil {
    class Set {
    public:
        Set(char* type) : set_(fossil_set_create(type)) {}

        ~Set() {
            fossil_set_erase(set_);
        }

        void insert(fossil_tofu_t data) {
            fossil_set_insert(set_, data);
        }

        void remove(fossil_tofu_t data) {
            fossil_set_remove(set_, data);
        }

        int search(fossil_tofu_t data) {
            return fossil_set_search(set_, data);
        }

        size_t size() {
            return fossil_set_size(set_);
        }

        fossil_tofu_t* getter(fossil_tofu_t data) {
            return fossil_set_getter(set_, data);
        }

        void setter(fossil_tofu_t data) {
            fossil_set_setter(set_, data);
        }

        bool not_empty() {
            return fossil_set_not_empty(set_);
        }

        bool not_cnullptr() {
            return fossil_set_not_cnullptr(set_);
        }

        bool is_empty() {
            return fossil_set_is_empty(set_);
        }

        bool is_cnullptr() {
            return fossil_set_is_cnullptr(set_);
        }

        bool contains(fossil_tofu_t data) {
            return fossil_set_contains(set_, data);
        }

    private:
        fossil_set_t* set_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
