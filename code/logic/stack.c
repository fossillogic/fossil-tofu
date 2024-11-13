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

extern char* fossil_tofu_type_to_string(fossil_tofu_type_t type);

fossil_stack_t* fossil_stack_create_container(char* type) {
    fossil_stack_t* stack = (fossil_stack_t*)fossil_tofu_alloc(sizeof(fossil_stack_t));
    if (!stack) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    stack->type = fossil_tofu_strdup(type);
    stack->top = NULL;
    return stack;
}

void fossil_stack_destroy(fossil_stack_t* stack) {
    if (!stack) return;
    while (stack->top) {
        fossil_stack_node_t* temp = stack->top;
        stack->top = stack->top->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(stack->type);
    fossil_tofu_free(stack);
}

int32_t fossil_stack_insert(fossil_stack_t* stack, char *data) {
    if (!stack || !data) {
        fprintf(stderr, "Error: Invalid stack or data\n");
        return -1;
    }
    fossil_stack_node_t* node = (fossil_stack_node_t*)fossil_tofu_alloc(sizeof(fossil_stack_node_t));
    if (!node) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return -1;
    }
    node->data = fossil_tofu_create(fossil_tofu_type_to_string(stack->type), data);
    node->next = stack->top;
    stack->top = node;
    return 0;
}

int32_t fossil_stack_remove(fossil_stack_t* stack, char *data) {
    if (!stack || !data) {
        fprintf(stderr, "Error: Invalid stack or data\n");
        return -1;
    }
    if (!stack->top) {
        fprintf(stderr, "Error: Stack is empty\n");
        return -1;
    }
    fossil_stack_node_t* temp = stack->top;
    stack->top = stack->top->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return 0;
}

size_t fossil_stack_size(const fossil_stack_t* stack) {
    if (!stack) {
        fprintf(stderr, "Error: Invalid stack\n");
        return 0;
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
    if (!stack) {
        fprintf(stderr, "Error: Invalid stack\n");
        return fossil_tofu_create("ghost", "");
    }
    if (!stack->top) {
        fprintf(stderr, "Error: Stack is empty\n");
        return fossil_tofu_create("ghost", "");
    }
    return stack->top->data;
}
