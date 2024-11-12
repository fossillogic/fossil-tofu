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
#include <stdarg.h>

fossil_stack_t* fossil_stack_create_container(char* type) {
    fossil_stack_t* stack = (fossil_stack_t*)fossil_tofu_alloc(sizeof(fossil_stack_t));
    if (!stack) return NULL;
    stack->type = fossil_tofu_strdup(type);
    stack->top = NULL;
    return stack;
}

void fossil_stack_destroy(fossil_stack_t* stack) {
    while (stack->top) {
        fossil_stack_node_t* temp = stack->top;
        stack->top = stack->top->next;
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(stack->type);
    fossil_tofu_free(stack);
}

int32_t fossil_stack_insert(fossil_stack_t* stack, char *data) {
    fossil_stack_node_t* new_node = (fossil_stack_node_t*)fossil_tofu_alloc(sizeof(fossil_stack_node_t));
    if (!new_node) return -1;
    new_node->data = fossil_tofu_create(stack->type, data);
    new_node->next = stack->top;
    stack->top = new_node;
    return 0;
}

int32_t fossil_stack_remove(fossil_stack_t* stack, fossil_tofu_t *data) {
    if (!stack->top) return -1;
    fossil_stack_node_t* temp = stack->top;
    *data = temp->data;
    stack->top = stack->top->next;
    fossil_tofu_free(temp);
    return 0;
}

int32_t fossil_stack_search(const fossil_stack_t* stack, fossil_tofu_t data) {
    fossil_stack_node_t* current = stack->top;
    size_t index = 0;
    while (current) {
        if (fossil_tofu_equals(current->data, data)) {
            return (int32_t)index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

size_t fossil_stack_size(const fossil_stack_t* stack) {
    size_t count = 0;
    fossil_stack_node_t* current = stack->top;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

bool fossil_stack_not_empty(const fossil_stack_t* stack) {
    return stack->top != NULL;
}

bool fossil_stack_not_cnullptr(const fossil_stack_t* stack) {
    return stack != NULL;
}

bool fossil_stack_is_empty(const fossil_stack_t* stack) {
    return stack->top == NULL;
}

bool fossil_stack_is_cnullptr(const fossil_stack_t* stack) {
    return stack == NULL;
}

fossil_tofu_t fossil_stack_top(fossil_stack_t* stack, fossil_tofu_t default_value) {
    if (stack->top) {
        return stack->top->data;
    }
    return default_value;
}
