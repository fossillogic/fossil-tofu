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

fossil_stack_t* fossil_stack_create_container(char* type) {
    fossil_stack_t* stack = (fossil_stack_t*)malloc(sizeof(fossil_stack_t));
    if (!stack) {
        return NULL; // Memory allocation failed
    }
    stack->type = fossil_tofu_strdup(type); // Duplicate the type string
    if (!stack->type) {
        fossil_tofu_free(stack);
        return NULL; // Memory allocation failed
    }
    stack->top = NULL; // Initialize the top pointer to NULL
    return stack;
}

fossil_stack_t* fossil_stack_create_default(void) {
    return fossil_stack_create_container("any");
}

fossil_stack_t* fossil_stack_create_copy(const fossil_stack_t* other) {
    if (!other) {
        return NULL; // Cannot copy a null stack
    }
    
    fossil_stack_t* new_stack = fossil_stack_create_container(other->type);
    if (!new_stack) {
        return NULL; // Memory allocation failed
    }

    // Copy the elements from the other stack
    fossil_stack_node_t* current = other->top;
    while (current) {
        int32_t rc = fossil_stack_insert(new_stack, fossil_tofu_get_value(&current->data));
        if (rc != FOSSIL_TOFU_SUCCESS) {
            fossil_stack_destroy(new_stack);
            return NULL; // Insertion failed
        }
        current = current->next;
    }
    
    return new_stack;
}

fossil_stack_t* fossil_stack_create_move(fossil_stack_t* other) {
    if (!other) {
        return NULL; // Cannot move a null stack
    }

    fossil_stack_t* new_stack = (fossil_stack_t*)fossil_tofu_alloc(sizeof(fossil_stack_t));
    if (!new_stack) {
        return NULL; // Memory allocation failed
    }

    new_stack->type = other->type;
    new_stack->top = other->top;

    // Invalidate the original stack
    other->type = NULL;
    other->top = NULL;

    return new_stack;
}

void fossil_stack_destroy(fossil_stack_t* stack) {
    if (!stack) {
        return;
    }

    // Free the type string
    fossil_tofu_free(stack->type);

    // Free the stack nodes
    fossil_stack_node_t* current = stack->top;
    while (current) {
        fossil_stack_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }

    // Free the stack structure
    fossil_tofu_free(stack);
}

int32_t fossil_stack_insert(fossil_stack_t* stack, char* data) {
    if (!stack || !data) {
        return FOSSIL_TOFU_FAILURE; // Invalid stack or data
    }

    // Create a new stack node
    fossil_stack_node_t* new_node = (fossil_stack_node_t*)malloc(sizeof(fossil_stack_node_t));
    if (!new_node) {
        return FOSSIL_TOFU_FAILURE; // Memory allocation failed
    }

    // Use the stack's type to create the tofu object
    new_node->data = fossil_tofu_create(stack->type, data);
    new_node->next = stack->top;
    stack->top = new_node;

    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_stack_remove(fossil_stack_t* stack) {
    if (!stack || !stack->top) {
        return FOSSIL_TOFU_FAILURE; // Invalid stack or empty stack
    }

    // Remove the top node
    fossil_stack_node_t* temp = stack->top;
    stack->top = stack->top->next;
    fossil_tofu_free(temp);

    return FOSSIL_TOFU_SUCCESS; // Removal successful
}

size_t fossil_stack_size(const fossil_stack_t* stack) {
    if (!stack) {
        return 0; // Invalid stack
    }

    size_t size = 0;
    fossil_stack_node_t* current = stack->top;
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_stack_not_empty(const fossil_stack_t* stack) {
    return fossil_stack_size(stack) > 0;
}

bool fossil_stack_not_cnullptr(const fossil_stack_t* stack) {
    return stack != NULL;
}

bool fossil_stack_is_empty(const fossil_stack_t* stack) {
    return fossil_stack_size(stack) == 0;
}

bool fossil_stack_is_cnullptr(const fossil_stack_t* stack) {
    return stack == NULL;
}

fossil_tofu_t fossil_stack_top(fossil_stack_t* stack) {
    if (!stack || !stack->top) {
        return fossil_tofu_create("any", ""); // Return default value if empty
    }
    return stack->top->data;
}

fossil_tofu_t fossil_stack_get(const fossil_stack_t* stack, size_t index) {
    if (!stack) {
        return fossil_tofu_create("any", ""); // Return default value if stack is null
    }

    fossil_stack_node_t* current = stack->top;
    size_t current_index = 0;
    while (current) {
        if (current_index == index) {
            return current->data;
        }
        current = current->next;
        current_index++;
    }
    return fossil_tofu_create("any", ""); // Return default value if index is out of bounds
}

void fossil_stack_set(fossil_stack_t* stack, size_t index, fossil_tofu_t element) {
    if (!stack || index >= fossil_stack_size(stack)) {
        return; // Invalid stack or index out of bounds
    }

    fossil_stack_node_t* current = stack->top;
    size_t current_index = 0;
    while (current) {
        if (current_index == index) {
            current->data = element; // Set the element at the specified index
            return;
        }
        current = current->next;
        current_index++;
    }
}
