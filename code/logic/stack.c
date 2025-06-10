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
#include "fossil/tofu/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_stack_t* fossil_stack_create_container(char* type) {
    fossil_stack_t* stack = (fossil_stack_t*)fossil_tofu_alloc(sizeof(fossil_stack_t));
    if (stack == NULL) {
        return NULL;
    }
    stack->type = type;
    stack->top = NULL;
    return stack;
}

fossil_stack_t* fossil_stack_create_default(void) {
    return fossil_stack_create_container("any");
}

fossil_stack_t* fossil_stack_create_copy(const fossil_stack_t* other) {
    if (other == NULL) {
        return NULL;
    }
    fossil_stack_t* stack = (fossil_stack_t*)fossil_tofu_alloc(sizeof(fossil_stack_t));
    if (stack == NULL) {
        return NULL;
    }
    stack->type = other->type;
    stack->top = NULL;

    // To preserve order, first collect data in an array
    size_t count = 0;
    fossil_stack_node_t* current = other->top;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    if (count == 0) {
        return stack;
    }

    char** data_array = (char**)fossil_tofu_alloc(sizeof(char*) * count);
    if (data_array == NULL) {
        fossil_tofu_free(stack);
        return NULL;
    }

    current = other->top;
    for (size_t i = 0; i < count; ++i) {
        // Deep copy the string data
        data_array[i] = fossil_tofu_strdup(current->data.value.data);
        current = current->next;
    }

    // Insert in reverse order to preserve stack order
    for (int i = count - 1; i >= 0; --i) {
        fossil_stack_insert(stack, data_array[i]);
        fossil_tofu_free(data_array[i]);
    }
    fossil_tofu_free(data_array);

    return stack;
}

fossil_stack_t* fossil_stack_create_move(fossil_stack_t* other) {
    fossil_stack_t* stack = (fossil_stack_t*)fossil_tofu_alloc(sizeof(fossil_stack_t));
    if (stack == NULL) {
        return NULL;
    }
    stack->type = other->type;
    stack->top = other->top;
    other->type = NULL;
    other->top = NULL;
    return stack;
}

void fossil_stack_destroy(fossil_stack_t* stack) {
    if (stack == NULL) {
        return;
    }
    while (stack->top != NULL) {
        fossil_stack_node_t* temp = stack->top;
        stack->top = stack->top->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(stack);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_stack_insert(fossil_stack_t* stack, char *data) {
    if (stack == NULL || data == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    // Ensure no duplicate data is inserted (compare string values)
    fossil_stack_node_t* current = stack->top;
    while (current != NULL) {
        if (strcmp(current->data.value.data, data) == 0) {
            // Duplicate found, do not insert
            return FOSSIL_TOFU_FAILURE;
        }
        current = current->next;
    }
    fossil_stack_node_t* new_node = (fossil_stack_node_t*)fossil_tofu_alloc(sizeof(fossil_stack_node_t));
    if (new_node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    new_node->data = fossil_tofu_create(stack->type, data);
    new_node->next = stack->top;
    stack->top = new_node;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_stack_remove(fossil_stack_t* stack) {
    if (stack == NULL || stack->top == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    // If only one node is left, remove it
    if (stack->top->next == NULL) {
        fossil_stack_node_t* temp = stack->top;
        stack->top = NULL;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
        return FOSSIL_TOFU_SUCCESS;
    }
    // Remove only the top node
    fossil_stack_node_t* temp = stack->top;
    stack->top = stack->top->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_stack_size(const fossil_stack_t* stack) {
    if (stack == NULL) {
        return 0;
    }
    size_t size = 0;
    fossil_stack_node_t* current = stack->top;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_stack_not_empty(const fossil_stack_t* stack) {
    return stack != NULL && stack->top != NULL;
}

bool fossil_stack_not_cnullptr(const fossil_stack_t* stack) {
    return stack != NULL;
}

bool fossil_stack_is_empty(const fossil_stack_t* stack) {
    return stack == NULL || stack->top == NULL;
}

bool fossil_stack_is_cnullptr(const fossil_stack_t* stack) {
    return stack == NULL;
}

fossil_tofu_t fossil_stack_top(fossil_stack_t* stack) {
    if (stack == NULL || stack->top == NULL) {
        return fossil_tofu_create(stack->type, "");
    }
    return stack->top->data;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

/**
 * Get the element at the specified index in the stack.
 * 
 * Time complexity: O(n)
 *
 * @param stack The stack from which to get the element.
 * @param index The index of the element to get.
 * @return      The element at the specified index.
 */
fossil_tofu_t fossil_stack_get(const fossil_stack_t* stack, size_t index) {
    size_t i = 0;
    fossil_stack_node_t* current = stack->top;
    while (current != NULL) {
        if (i == index) {
            return current->data;
        }
        i++;
        current = current->next;
    }
    return fossil_tofu_create(stack->type, "");
}

/**
 * Set the element at the specified index in the stack.
 * 
 * Time complexity: O(n)
 *
 * @param stack   The stack in which to set the element.
 * @param index   The index at which to set the element.
 * @param element The element to set.
 */
void fossil_stack_set(fossil_stack_t* stack, size_t index, fossil_tofu_t element) {
    size_t i = 0;
    fossil_stack_node_t* current = stack->top;
    while (current != NULL) {
        if (i == index) {
            current->data = element;
            return;
        }
        i++;
        current = current->next;
    }
}
