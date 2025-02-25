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
#include "fossil/tofu/setof.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_set_t* fossil_set_create_container(char* type) {
    fossil_set_t* set = (fossil_set_t*)fossil_tofu_alloc(sizeof(fossil_set_t));
    if (set == NULL) {
        return NULL;
    }
    set->type = type;
    set->head = NULL;
    return set;
}

fossil_set_t* fossil_set_create_default(void) {
    return fossil_set_create_container("any");
}

fossil_set_t* fossil_set_create_copy(const fossil_set_t* other) {
    fossil_set_t* set = (fossil_set_t*)fossil_tofu_alloc(sizeof(fossil_set_t));
    if (set == NULL) {
        return NULL;
    }
    set->type = other->type;
    set->head = NULL;
    fossil_set_node_t* current = other->head;
    while (current != NULL) {
        fossil_set_insert(set, current->data.value.data);
        current = current->next;
    }
    return set;
}

fossil_set_t* fossil_set_create_move(fossil_set_t* other) {
    fossil_set_t* set = (fossil_set_t*)fossil_tofu_alloc(sizeof(fossil_set_t));
    if (set == NULL) {
        return NULL;
    }
    set->type = other->type;
    set->head = other->head;
    other->head = NULL;
    return set;
}

void fossil_set_destroy(fossil_set_t* set) {
    if (set == NULL) {
        return;
    }
    while (set->head != NULL) {
        fossil_set_node_t* temp = set->head;
        set->head = set->head->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
    fossil_tofu_free(set);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_set_insert(fossil_set_t* set, char *data) {
    if (set == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_set_node_t* node = (fossil_set_node_t*)fossil_tofu_alloc(sizeof(fossil_set_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(set->type, data);
    node->next = set->head;
    set->head = node;
    return FOSSIL_TOFU_SUCCESS;
}

void fossil_set_erase(fossil_set_t *set) {
    if (set == NULL) {
        return;
    }
    while (set->head != NULL) {
        fossil_set_node_t* temp = set->head;
        set->head = set->head->next;
        fossil_tofu_destroy(&temp->data);
        fossil_tofu_free(temp);
    }
}

size_t fossil_set_size(const fossil_set_t* set) {
    size_t size = 0;
    fossil_set_node_t* current = set->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_set_not_empty(const fossil_set_t* set) {
    return set != NULL && set->head != NULL;
}

bool fossil_set_not_cnullptr(const fossil_set_t* set) {
    return set != NULL;
}

bool fossil_set_is_empty(const fossil_set_t* set) {
    return set == NULL || set->head == NULL;
}

bool fossil_set_is_cnullptr(const fossil_set_t* set) {
    return set == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_set_get(const fossil_set_t* set, size_t index) {
    size_t i = 0;
    fossil_set_node_t* current = set->head;
    while (current != NULL) {
        if (i == index) {
            return fossil_tofu_get_value(&current->data);
        }
        i++;
        current = current->next;
    }
    return NULL;
}

char *fossil_set_get_front(const fossil_set_t* set) {
    return set == NULL || set->head == NULL ? NULL : fossil_tofu_get_value(&set->head->data);
}

char *fossil_set_get_back(const fossil_set_t* set) {
    fossil_set_node_t* current = set->head;
    while (current->next != NULL) {
        current = current->next;
    }
    return fossil_tofu_get_value(&current->data);
}

void fossil_set_set(fossil_set_t* set, size_t index, char *element) {
    size_t i = 0;
    fossil_set_node_t* current = set->head;
    while (current != NULL) {
        if (i == index) {
            fossil_tofu_set_value(&current->data, element);
            return;
        }
        i++;
        current = current->next;
    }
}

void fossil_set_set_front(fossil_set_t* set, char *element) {
    fossil_tofu_set_value(&set->head->data, element);
}

void fossil_set_set_back(fossil_set_t* set, char *element) {
    fossil_set_node_t* current = set->head;
    while (current->next != NULL) {
        current = current->next;
    }
    fossil_tofu_set_value(&current->data, element);
}
