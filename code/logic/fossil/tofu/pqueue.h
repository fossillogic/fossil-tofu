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
#ifndef FOSSIL_TOFU_PQUEUE_H
#define FOSSIL_TOFU_PQUEUE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

typedef struct fossil_pqueue_node_t {
    fossil_tofu_t data;
    int32_t priority;
    struct fossil_pqueue_node_t* next;
} fossil_pqueue_node_t;

typedef struct fossil_pqueue_t {
    fossil_pqueue_node_t* front;
    char* type;
} fossil_pqueue_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new priority queue with the specified data type.
 *
 * @param queue_type The type of data the priority queue will store.
 * @return           The created priority queue.
 * @note             Time complexity: O(1)
 */
fossil_pqueue_t* fossil_pqueue_create_container(char* type);

/**
 * Create a new priority queue with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created priority queue.
 */
fossil_pqueue_t* fossil_pqueue_create_default(void);

/**
 * Create a new priority queue by copying an existing priority queue.
 * 
 * Time complexity: O(n)
 *
 * @param other The priority queue to copy.
 * @return      The created priority queue.
 */
fossil_pqueue_t* fossil_pqueue_create_copy(const fossil_pqueue_t* other);

/**
 * Create a new priority queue by moving an existing priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param other The priority queue to move.
 * @return      The created priority queue.
 */
fossil_pqueue_t* fossil_pqueue_create_move(fossil_pqueue_t* other);

/**
 * Erase the contents of the priority queue and fossil_tofu_free allocated memory.
 *
 * @param pqueue The priority queue to erase.
 * @note         Time complexity: O(n)
 */
void fossil_pqueue_destroy(fossil_pqueue_t* pqueue);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue to insert data into.
 * @param data     The data to insert.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(n)
 */
int32_t fossil_pqueue_insert(fossil_pqueue_t* pqueue, char *data, int32_t priority);

/**
 * Remove data from the priority queue.
 *
 * @param pqueue   The priority queue to remove data from.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(1)
 */
int32_t fossil_pqueue_remove(fossil_pqueue_t* pqueue, int32_t priority);

/**
 * Get the size of the priority queue.
 *
 * @param pqueue The priority queue for which to get the size.
 * @return       The size of the priority queue.
 * @note         Time complexity: O(1)
 */
size_t fossil_pqueue_size(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is not empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_not_empty(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is not a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_not_cnullptr(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is empty, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_is_empty(const fossil_pqueue_t* pqueue);

/**
 * Check if the priority queue is a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
bool fossil_pqueue_is_cnullptr(const fossil_pqueue_t* pqueue);

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element with the highest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue The priority queue from which to get the element.
 * @return       The element with the highest priority.
 */
char *fossil_pqueue_get_front(const fossil_pqueue_t* pqueue);

/**
 * Get the element with the lowest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue The priority queue from which to get the element.
 * @return       The element with the lowest priority.
 */
char *fossil_pqueue_get_back(const fossil_pqueue_t* pqueue);

/**
 * Get the element at the specified priority in the priority queue.
 * 
 * Time complexity: O(n)
 *
 * @param pqueue   The priority queue from which to get the element.
 * @param priority The priority of the element to get.
 * @return         The element at the specified priority.
 */
char *fossil_pqueue_get_at(const fossil_pqueue_t* pqueue, int32_t priority);

/**
 * Set the element with the highest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue  The priority queue in which to set the element.
 * @param element The element to set.
 */
void fossil_pqueue_set_front(fossil_pqueue_t* pqueue, char *element);

/**
 * Set the element with the lowest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue  The priority queue in which to set the element.
 * @param element The element to set.
 */
void fossil_pqueue_set_back(fossil_pqueue_t* pqueue, char *element);

/**
 * Set the element at the specified priority in the priority queue.
 * 
 * Time complexity: O(n)
 *
 * @param pqueue   The priority queue in which to set the element.
 * @param priority The priority at which to set the element.
 * @param element  The element to set.
 */
void fossil_pqueue_set_at(fossil_pqueue_t* pqueue, int32_t priority, char *element);

#ifdef __cplusplus
}

namespace fossil {

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Create a new priority queue with the specified data type.
 *
 * @param queue_type The type of data the priority queue will store.
 * @return           The created priority queue.
 * @note             Time complexity: O(1)
 */
inline fossil_pqueue_t* pqueue_create_container(const std::string& type) {
    return fossil_pqueue_create_container(const_cast<char*>(type.c_str()));
}

/**
 * Create a new priority queue with default values.
 * 
 * Time complexity: O(1)
 *
 * @return The created priority queue.
 */
inline fossil_pqueue_t* pqueue_create_default(void) {
    return fossil_pqueue_create_default();
}

/**
 * Create a new priority queue by copying an existing priority queue.
 * 
 * Time complexity: O(n)
 *
 * @param other The priority queue to copy.
 * @return      The created priority queue.
 */
inline fossil_pqueue_t* pqueue_create_copy(const fossil_pqueue_t* other) {
    return fossil_pqueue_create_copy(other);
}

/**
 * Create a new priority queue by moving an existing priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param other The priority queue to move.
 * @return      The created priority queue.
 */
inline fossil_pqueue_t* pqueue_create_move(fossil_pqueue_t* other) {
    return fossil_pqueue_create_move(other);
}

/**
 * Erase the contents of the priority queue and fossil_tofu_free allocated memory.
 *
 * @param pqueue The priority queue to erase.
 * @note         Time complexity: O(n)
 */
inline void pqueue_destroy(fossil_pqueue_t* pqueue) {
    fossil_pqueue_destroy(pqueue);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Insert data into the priority queue with the specified priority.
 *
 * @param pqueue   The priority queue to insert data into.
 * @param data     The data to insert.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(n)
 */
inline int32_t pqueue_insert(fossil_pqueue_t* pqueue, const std::string& data, int32_t priority) {
    return fossil_pqueue_insert(pqueue, const_cast<char*>(data.c_str()), priority);
}

/**
 * Remove data from the priority queue.
 *
 * @param pqueue   The priority queue to remove data from.
 * @param priority The priority of the data.
 * @return         The error code indicating the success or failure of the operation.
 * @note           Time complexity: O(1)
 */
inline int32_t pqueue_remove(fossil_pqueue_t* pqueue, int32_t priority) {
    return fossil_pqueue_remove(pqueue, priority);
}

/**
 * Get the size of the priority queue.
 *
 * @param pqueue The priority queue for which to get the size.
 * @return       The size of the priority queue.
 * @note         Time complexity: O(1)
 */
inline size_t pqueue_size(const fossil_pqueue_t* pqueue) {
    return fossil_pqueue_size(pqueue);
}

/**
 * Check if the priority queue is not empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not empty, false otherwise.
 * @note         Time complexity: O(1)
 */
inline bool pqueue_not_empty(const fossil_pqueue_t* pqueue) {
    return fossil_pqueue_not_empty(pqueue);
}

/**
 * Check if the priority queue is not a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is not a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
inline bool pqueue_not_cnullptr(const fossil_pqueue_t* pqueue) {
    return fossil_pqueue_not_cnullptr(pqueue);
}

/**
 * Check if the priority queue is empty.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is empty, false otherwise.
 * @note         Time complexity: O(1)
 */
inline bool pqueue_is_empty(const fossil_pqueue_t* pqueue) {
    return fossil_pqueue_is_empty(pqueue);
}

/**
 * Check if the priority queue is a null pointer.
 *
 * @param pqueue The priority queue to check.
 * @return       True if the priority queue is a null pointer, false otherwise.
 * @note         Time complexity: O(1)
 */
inline bool pqueue_is_cnullptr(const fossil_pqueue_t* pqueue) {
    return fossil_pqueue_is_cnullptr(pqueue);
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element with the highest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue The priority queue from which to get the element.
 * @return       The element with the highest priority.
 */
inline std::string pqueue_get_front(const fossil_pqueue_t* pqueue) {
    return std::string(fossil_pqueue_get_front(pqueue));
}

/**
 * Get the element with the lowest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue The priority queue from which to get the element.
 * @return       The element with the lowest priority.
 */
inline std::string pqueue_get_back(const fossil_pqueue_t* pqueue) {
    return std::string(fossil_pqueue_get_back(pqueue));
}

/**
 * Get the element at the specified priority in the priority queue.
 * 
 * Time complexity: O(n)
 *
 * @param pqueue   The priority queue from which to get the element.
 * @param priority The priority of the element to get.
 * @return         The element at the specified priority.
 */
inline std::string pqueue_get_at(const fossil_pqueue_t* pqueue, int32_t priority) {
    return std::string(fossil_pqueue_get_at(pqueue, priority));
}

/**
 * Set the element with the highest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue  The priority queue in which to set the element.
 * @param element The element to set.
 */
inline void pqueue_set_front(fossil_pqueue_t* pqueue, const std::string& element) {
    fossil_pqueue_set_front(pqueue, const_cast<char*>(element.c_str()));
}

/**
 * Set the element with the lowest priority in the priority queue.
 * 
 * Time complexity: O(1)
 *
 * @param pqueue  The priority queue in which to set the element.
 * @param element The element to set.
 */
inline void pqueue_set_back(fossil_pqueue_t* pqueue, const std::string& element) {
    fossil_pqueue_set_back(pqueue, const_cast<char*>(element.c_str()));
}

/**
 * Set the element at the specified priority in the priority queue.
 * 
 * Time complexity: O(n)
 *
 * @param pqueue   The priority queue in which to set the element.
 * @param priority The priority at which to set the element.
 * @param element  The element to set.
 */
inline void pqueue_set_at(fossil_pqueue_t* pqueue, int32_t priority, const std::string& element) {
    fossil_pqueue_set_at(pqueue, priority, const_cast<char*>(element.c_str()));
}

}

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
