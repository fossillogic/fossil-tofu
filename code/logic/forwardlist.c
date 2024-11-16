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
#include "fossil/tofu/forwardlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_flist_t* fossil_flist_create_container(char* type) {
    fossil_flist_t* flist = (fossil_flist_t*)fossil_tofu_alloc(sizeof(fossil_flist_t));
    if (flist == NULL) {
        return NULL;
    }
    flist->head = NULL;
    flist->type = fossil_tofu_strdup(type);
    return flist;
}

void fossil_flist_destroy(fossil_flist_t* flist) {
    fossil_flist_node_t* current = flist->head;
    while (current != NULL) {
        fossil_flist_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(flist->type);
    fossil_tofu_free(flist);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_flist_insert(fossil_flist_t* flist, char *data) {
    fossil_flist_node_t* node = (fossil_flist_node_t*)fossil_tofu_alloc(sizeof(fossil_flist_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(flist->type, data);
    node->next = flist->head;
    flist->head = node;
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_flist_remove(fossil_flist_t* flist) {
    if (flist->head == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_flist_node_t* node = flist->head;
    flist->head = node->next;
    fossil_tofu_destroy(&node->data);
    fossil_tofu_free(node);
    return FOSSIL_TOFU_SUCCESS;
}

void fossil_flist_reverse_forward(fossil_flist_t* flist) {
    fossil_flist_node_t* prev = NULL;
    fossil_flist_node_t* current = flist->head;
    fossil_flist_node_t* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    flist->head = prev;
}

void fossil_flist_reverse_backward(fossil_flist_t* flist) {
    fossil_flist_reverse_forward(flist);
}

size_t fossil_flist_size(const fossil_flist_t* flist) {
    size_t size = 0;
    fossil_flist_node_t* current = flist->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_flist_not_empty(const fossil_flist_t* flist) {
    return flist->head != NULL;
}

bool fossil_flist_not_cnullptr(const fossil_flist_t* flist) {
    return flist != NULL;
}

bool fossil_flist_is_empty(const fossil_flist_t* flist) {
    return flist->head == NULL;
}

bool fossil_flist_is_cnullptr(const fossil_flist_t* flist) {
    return flist == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_flist_get(const fossil_flist_t* flist, size_t index) {
    size_t i = 0;
    fossil_flist_node_t* current = flist->head;
    while (current != NULL) {
        if (i == index) {
            return fossil_tofu_get_value(&current->data);
        }
        i++;
        current = current->next;
    }
    return NULL;
}

char *fossil_flist_get_front(const fossil_flist_t* flist) {
    return fossil_tofu_get_value(&flist->head->data);
}

char *fossil_flist_get_back(const fossil_flist_t* flist) {
    fossil_flist_node_t* current = flist->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return fossil_tofu_get_value(&current->data);
}

void fossil_flist_set(fossil_flist_t* flist, size_t index, char *element) {
    size_t i = 0;
    fossil_flist_node_t* current = flist->head;
    while (current != NULL) {
        if (i == index) {
            fossil_tofu_set_value(&current->data, element);
            return;
        }
        i++;
        current = current->next;
    }
}

void fossil_flist_set_front(fossil_flist_t* flist, char *element) {
    fossil_tofu_set_value(&flist->head->data, element);
}

void fossil_flist_set_back(fossil_flist_t* flist, char *element) {
    fossil_flist_node_t* current = flist->head;
    while (current->next != NULL) {
        current = current->next;
    }
    fossil_tofu_set_value(&current->data, element);
}
