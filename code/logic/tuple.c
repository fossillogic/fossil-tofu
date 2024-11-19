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
#include "fossil/tofu/tuple.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tuple_t *fossil_tuple_create(char *type) {
    fossil_tuple_t *tuple = (fossil_tuple_t*)fossil_tofu_alloc(sizeof(fossil_tuple_t));
    if (tuple == NULL) {
        return NULL;
    }
    tuple->elements = (fossil_tofu_t*)fossil_tofu_alloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    if (tuple->elements == NULL) {
        fossil_tofu_free(tuple);
        return NULL;
    }
    tuple->element_count = 0;
    tuple->capacity = INITIAL_CAPACITY;
    tuple->type = type;
    return tuple;
}

fossil_tuple_t* fossil_tuple_create_default(void) {
    return fossil_tuple_create("any");
}

fossil_tuple_t* fossil_tuple_create_copy(const fossil_tuple_t* other) {
    fossil_tuple_t* tuple = (fossil_tuple_t*)fossil_tofu_alloc(sizeof(fossil_tuple_t));
    if (tuple == NULL) {
        return NULL;
    }
    tuple->elements = (fossil_tofu_t*)fossil_tofu_alloc(other->capacity * sizeof(fossil_tofu_t));
    if (tuple->elements == NULL) {
        fossil_tofu_free(tuple);
        return NULL;
    }
    for (size_t i = 0; i < other->element_count; i++) {
        tuple->elements[i] = fossil_tofu_create(other->type, other->elements[i].value.data);
    }
    tuple->element_count = other->element_count;
    tuple->capacity = other->capacity;
    tuple->type = other->type;
    return tuple;
}

fossil_tuple_t* fossil_tuple_create_move(fossil_tuple_t* other) {
    fossil_tuple_t* tuple = (fossil_tuple_t*)fossil_tofu_alloc(sizeof(fossil_tuple_t));
    if (tuple == NULL) {
        return NULL;
    }
    tuple->elements = other->elements;
    tuple->element_count = other->element_count;
    tuple->capacity = other->capacity;
    tuple->type = other->type;
    other->elements = NULL;
    other->element_count = 0;
    other->capacity = 0;
    other->type = NULL;
    return tuple;
}

void fossil_tuple_destroy(fossil_tuple_t *tuple) {
    if (tuple == NULL) {
        return;
    }
    for (size_t i = 0; i < tuple->element_count; i++) {
        fossil_tofu_destroy(&tuple->elements[i]);
    }
    fossil_tofu_free(tuple->elements);
    tuple->element_count = 0;
    tuple->capacity = 0;
    tuple->type = NULL;
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

void fossil_tuple_add(fossil_tuple_t *tuple, char *element) {
    if (tuple == NULL) {
        return;
    }
    if (tuple->element_count == tuple->capacity) {
        fossil_tofu_t* new_elements = (fossil_tofu_t*)fossil_tofu_alloc(2 * tuple->capacity * sizeof(fossil_tofu_t));
        if (new_elements == NULL) {
            return;
        }
        for (size_t i = 0; i < tuple->element_count; i++) {
            new_elements[i] = tuple->elements[i];
        }
        fossil_tofu_free(tuple->elements);
        tuple->elements = new_elements;
        tuple->capacity *= 2;
    }
    tuple->elements[tuple->element_count++] = fossil_tofu_create(tuple->type, element);
}

void fossil_tuple_remove(fossil_tuple_t *tuple, size_t index) {
    if (tuple == NULL || index >= tuple->element_count) {
        return;
    }
    fossil_tofu_destroy(&tuple->elements[index]);
    for (size_t i = index; i < tuple->element_count - 1; i++) {
        tuple->elements[i] = tuple->elements[i + 1];
    }
    tuple->element_count--;
}

size_t fossil_tuple_size(fossil_tuple_t *tuple) {
    return tuple == NULL ? 0 : tuple->element_count;
}

size_t fossil_tuple_capacity(fossil_tuple_t *tuple) {
    return tuple == NULL ? 0 : tuple->capacity;
}

bool fossil_tuple_is_empty(fossil_tuple_t *tuple) {
    return tuple == NULL || tuple->element_count == 0;
}

void fossil_tuple_clear(fossil_tuple_t *tuple) {
    if (tuple == NULL) {
        return;
    }
    for (size_t i = 0; i < tuple->element_count; i++) {
        fossil_tofu_destroy(&tuple->elements[i]);
    }
    tuple->element_count = 0;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_tuple_get(fossil_tuple_t *tuple, size_t index) {
    if (tuple == NULL || index >= tuple->element_count) {
        return NULL;
    }
    return tuple->elements[index].value.data;
}

/**
 * @brief Gets the first element in the tuple.
 * 
 * @param tuple The tuple from which to get the first element.
 * @return The first element in the tuple.
 * @note Time complexity: O(1)
 */
char *fossil_tuple_get_front(const fossil_tuple_t* tuple) {
    return tuple == NULL || tuple->element_count == 0 ? NULL : tuple->elements[0].value.data;
}

/**
 * @brief Gets the last element in the tuple.
 * 
 * @param tuple The tuple from which to get the last element.
 * @return The last element in the tuple.
 * @note Time complexity: O(1)
 */
char *fossil_tuple_get_back(const fossil_tuple_t* tuple) {
    return tuple == NULL || tuple->element_count == 0 ? NULL : tuple->elements[tuple->element_count - 1].value.data;
}

/**
 * @brief Sets the element at the specified index in the tuple.
 * 
 * @param tuple The tuple in which to set the element.
 * @param index The index at which to set the element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tuple_set(fossil_tuple_t* tuple, size_t index, char *element) {
    if (tuple == NULL || index >= tuple->element_count) {
        return;
    }
    fossil_tofu_set_value(&tuple->elements[index], element);
}

/**
 * @brief Sets the first element in the tuple.
 * 
 * @param tuple The tuple in which to set the first element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tuple_set_front(fossil_tuple_t* tuple, char *element) {
    if (tuple == NULL || tuple->element_count == 0) {
        return;
    }
    fossil_tofu_set_value(&tuple->elements[0], element);
}

/**
 * @brief Sets the last element in the tuple.
 * 
 * @param tuple The tuple in which to set the last element.
 * @param element The element to set.
 * @note Time complexity: O(1)
 */
void fossil_tuple_set_back(fossil_tuple_t* tuple, char *element) {
    if (tuple == NULL || tuple->element_count == 0) {
        return;
    }
    fossil_tofu_set_value(&tuple->elements[tuple->element_count - 1], element);
}
