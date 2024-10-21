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

fossil_stack_t* fossil_stack_create(char* type) {
    if (!type) {
        return NULL; // Error: type is NULL
    }

    fossil_stack_t* stack = (fossil_stack_t*)fossil_tofu_alloc(sizeof(fossil_stack_t));
    if (stack) {
        stack->type = type; // Assuming type is a static string or managed separately
        stack->top = NULL;
    }
    return stack;
}

void fossil_stack_destroy(fossil_stack_t* stack) {
    if (!stack) return;

    fossil_stack_node_t* current = stack->top;
    while (current) {
        fossil_stack_node_t* next = current->next;
        fossil_tofu_free(current);
        current = next;
    }
    stack->top = NULL;
    fossil_tofu_free(stack);
}

int32_t fossil_stack_insert(fossil_stack_t* stack, fossil_tofu_t data) {
    if (!stack) {
        return FOSSIL_TOFU_FAILURE; // Error: stack is NULL
    }

    fossil_stack_node_t* new_node = (fossil_stack_node_t*)fossil_tofu_alloc(sizeof(fossil_stack_node_t));
    if (!new_node) {
        return FOSSIL_TOFU_FAILURE; // Allocation failed
    }

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;

    return FOSSIL_TOFU_SUCCESS; // Success
}

int32_t fossil_stack_remove(fossil_stack_t* stack, fossil_tofu_t* data) {
    if (!stack || !data) {
        return FOSSIL_TOFU_FAILURE; // Error: stack or data is NULL
    }

    if (!stack->top) {
        return FOSSIL_TOFU_FAILURE; // Stack is empty
    }

    fossil_stack_node_t* top_node = stack->top;
    *data = top_node->data;
    stack->top = top_node->next;
    fossil_tofu_free(top_node);

    return FOSSIL_TOFU_SUCCESS; // Success
}

int32_t fossil_stack_search(const fossil_stack_t* stack, fossil_tofu_t data) {
    if (!stack) {
        return FOSSIL_TOFU_FAILURE; // Error: stack is NULL
    }

    fossil_stack_node_t* current = stack->top;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return FOSSIL_TOFU_SUCCESS; // Found
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE; // Not found
}

size_t fossil_stack_size(const fossil_stack_t* stack) {
    if (!stack) {
        return 0; // Error: stack is NULL
    }

    size_t count = 0;
    fossil_stack_node_t* current = stack->top;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

fossil_tofu_t* fossil_stack_getter(fossil_stack_t* stack, fossil_tofu_t data) {
    if (!stack) {
        return NULL; // Error: stack is NULL
    }

    fossil_stack_node_t* current = stack->top;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return &(current->data); // Return pointer to found data
        }
        current = current->next;
    }
    return NULL; // Not found
}

int32_t fossil_stack_setter(fossil_stack_t* stack, fossil_tofu_t data) {
    if (!stack) {
        return FOSSIL_TOFU_FAILURE; // Error: stack is NULL
    }

    fossil_stack_node_t* current = stack->top;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            current->data = data; // Update data
            return FOSSIL_TOFU_SUCCESS; // Success
        }
        current = current->next;
    }
    return FOSSIL_TOFU_FAILURE; // Not found
}

bool fossil_stack_not_empty(const fossil_stack_t* stack) {
    if (!stack) {
        return false; // Error: stack is NULL
    }
    return stack->top != NULL;
}

bool fossil_stack_not_cnullptr(const fossil_stack_t* stack) {
    return stack != NULL;
}

bool fossil_stack_is_empty(const fossil_stack_t* stack) {
    if (!stack) {
        return true; // Error: stack is NULL
    }
    return stack->top == NULL;
}

bool fossil_stack_is_cnullptr(const fossil_stack_t* stack) {
    return stack == NULL;
}

fossil_tofu_t fossil_stack_top(fossil_stack_t* stack, fossil_tofu_t default_value) {
    if (!stack) {
        return default_value; // Error: stack is NULL
    }

    if (!stack->top) {
        return default_value; // Stack is empty
    }
    return stack->top->data;
}
