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
#ifndef FOSSIL_TOFU_FORWARDLIST_H
#define FOSSIL_TOFU_FORWARDLIST_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Node structure for the linked list
typedef struct fossil_flist_node_t {
    fossil_tofu_t data;
    struct fossil_flist_node_t* next;
} fossil_flist_node_t;

// Linked list structure
typedef struct fossil_flist_t {
    fossil_flist_node_t* head;
    char* type;
} fossil_flist_t;

/**
 * Create a new forward list with the specified data type.
 *
 * @param list_type The type of data the forward list will store.
 * @return          The created forward list.
 * @complexity      O(1)
 */
fossil_flist_t* fossil_flist_create(char* type);

/**
 * Erase the contents of the forward list and free allocated memory.
 *
 * @param flist The forward list to erase.
 * @complexity  O(n)
 */
void fossil_flist_erase(fossil_flist_t* flist);

/**
 * Insert data into the forward list.
 *
 * @param flist The forward list to insert data into.
 * @param data  The data to insert.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(1)
 */
int32_t fossil_flist_insert(fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Remove data from the forward list.
 *
 * @param flist The forward list to remove data from.
 * @param data  A pointer to store the removed data.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(1)
 */
int32_t fossil_flist_remove(fossil_flist_t* flist, fossil_tofu_t* data);

/**
 * Search for data in the forward list.
 *
 * @param flist The forward list to search.
 * @param data  The data to search for.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(n)
 */
int32_t fossil_flist_search(const fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Reverse the forward list in the forward direction.
 *
 * @param flist The forward list to reverse.
 * @complexity  O(n)
 */
void fossil_flist_reverse_forward(fossil_flist_t* flist);

/**
 * Reverse the forward list in the backward direction.
 *
 * @param flist The forward list to reverse.
 * @complexity  O(n)
 */
void fossil_flist_reverse_backward(fossil_flist_t* flist);

/**
 * Get the size of the forward list.
 *
 * @param flist The forward list for which to get the size.
 * @return      The size of the forward list.
 * @complexity  O(n)
 */
size_t fossil_flist_size(const fossil_flist_t* flist);

/**
 * Get the data from the forward list matching the specified data.
 *
 * @param flist The forward list from which to get the data.
 * @param data  The data to search for.
 * @return      A pointer to the matching data.
 * @complexity  O(n)
 */
fossil_tofu_t* fossil_flist_getter(fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Set data in the forward list.
 *
 * @param flist The forward list in which to set the data.
 * @param data  The data to set.
 * @return      The error code indicating the success or failure of the operation.
 * @complexity  O(n)
 */
int32_t fossil_flist_setter(fossil_flist_t* flist, fossil_tofu_t data);

/**
 * Check if the forward list is not empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_not_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is not a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is not a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_not_cnullptr(const fossil_flist_t* flist);

/**
 * Check if the forward list is empty.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is empty, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_is_empty(const fossil_flist_t* flist);

/**
 * Check if the forward list is a null pointer.
 *
 * @param flist The forward list to check.
 * @return      True if the forward list is a null pointer, false otherwise.
 * @complexity  O(1)
 */
bool fossil_flist_is_cnullptr(const fossil_flist_t* flist);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace fossil {
    class ForwardList {
    public:
        ForwardList(const std::string& type) : flist_(fossil_flist_create(const_cast<char*>(type.c_str()))) {}

        ~ForwardList() {
            fossil_flist_erase(flist_);
        }

        void insert(fossil_tofu_t data) {
            fossil_flist_insert(flist_, data);
        }

        fossil_tofu_t remove() {
            fossil_tofu_t data;
            fossil_flist_remove(flist_, &data);
            return data;
        }

        bool search(fossil_tofu_t data) {
            return fossil_flist_search(flist_, data) == 0;
        }

        size_t size() {
            return fossil_flist_size(flist_);
        }

        fossil_tofu_t* getter(fossil_tofu_t data) {
            return fossil_flist_getter(flist_, data);
        }

        void setter(fossil_tofu_t data) {
            fossil_flist_setter(flist_, data);
        }

        void reverse_forward() {
            fossil_flist_reverse_forward(flist_);
        }

        void reverse_backward() {
            fossil_flist_reverse_backward(flist_);
        }

        bool not_empty() {
            return fossil_flist_not_empty(flist_);
        }

        bool not_cnullptr() {
            return fossil_flist_not_cnullptr(flist_);
        }

        bool is_empty() {
            return fossil_flist_is_empty(flist_);
        }

        bool is_cnullptr() {
            return fossil_flist_is_cnullptr(flist_);
        }

    private:
        fossil_flist_t* flist_;
    };
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
