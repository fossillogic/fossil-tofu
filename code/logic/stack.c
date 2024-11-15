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
// Type definitions
// *****************************************************************************

// Stack structure
typedef struct fossil_stack_node_t {
    fossil_tofu_t data; // Data stored in the stack node
    struct fossil_stack_node_t* next; // Pointer to the next node
} fossil_stack_node_t;

typedef struct fossil_stack_t {
    char* type; // Type of the stack
    fossil_stack_node_t* top; // Pointer to the top node of the stack
} fossil_stack_t;

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
    if (stack == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_stack_node_t* node = (fossil_stack_node_t*)fossil_tofu_alloc(sizeof(fossil_stack_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(stack->type, data);
    node->next = stack->top;
    stack->top = node;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_stack_remove(fossil_stack_t* stack) {
    if (stack == NULL || stack->top == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_stack_node_t* temp = stack->top;
    stack->top = stack->top->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return FOSSIL_TOFU_SUCCESS;
}

size_t fossil_stack_size(const fossil_stack_t* stack) {
    if (stack == NULL) {
        return FOSSIL_TOFU_SUCCESS;
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
// Algorithm functions
// *****************************************************************************

int fossil_stack_algorithm_search(fossil_stack_t* stack, char *element) {
    if (stack == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    size_t index = 0;
    fossil_stack_node_t* current = stack->top;
    while (current != NULL) {
        if (fossil_tofu_compare(&current->data, element) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }
    return FOSSIL_TOFU_FAILURE;
}

int fossil_stack_algorithm_sort(fossil_stack_t* stack) {
    if (stack == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_stack_node_t* current = stack->top;
    while (current != NULL) {
        fossil_stack_node_t* temp = current->next;
        while (temp != NULL) {
            if (fossil_tofu_compare(&current->data, &temp->data) > 0) {
                fossil_tofu_t temp_data = current->data;
                current->data = temp->data;
                temp->data = temp_data;
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int fossil_stack_algorithm_reverse(fossil_stack_t* stack) {
    if (stack == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_stack_node_t* current = stack->top;
    fossil_stack_node_t* prev = NULL;
    while (current != NULL) {
        fossil_stack_node_t* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    stack->top = prev;
    return FOSSIL_TOFU_SUCCESS;
}
