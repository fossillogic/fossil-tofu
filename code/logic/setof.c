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

extern char* fossil_tofu_type_to_string(fossil_tofu_type_t type);

fossil_set_t* fossil_set_create_container(char* type) {
    fossil_set_t* set = (fossil_set_t*)fossil_tofu_alloc(sizeof(fossil_set_t));
    if (!set) {
        return NULL;
    }
    set->head = NULL;
    set->type = fossil_tofu_strdup(type);
    return set;
}

void fossil_set_destroy(fossil_set_t* set) {
    if (!set) {
        return;
    }

    fossil_set_node_t* current = set->head;
    while (current) {
        fossil_set_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(set->type);
    fossil_tofu_free(set);
}

int32_t fossil_set_insert(fossil_set_t* set, char *data) {
    if (!set) {
        return -1;
    }

    if (!set->head) {
        set->head = (fossil_set_node_t*)fossil_tofu_alloc(sizeof(fossil_set_node_t));
        if (!set->head) {
            return -1;
        }
        set->head->data = fossil_tofu_create(fossil_tofu_type_to_string(set->type), data);
        set->head->next = NULL;
        return 0;
    }

    fossil_set_node_t* current = set->head;
    while (current->next) {
        current = current->next;
    }

    current->next = (fossil_set_node_t*)fossil_tofu_alloc(sizeof(fossil_set_node_t));
    if (!current->next) {
        return -1;
    }
    current->next->data = fossil_tofu_create(fossil_tofu_type_to_string(set->type), data);
    current->next->next = NULL;
    return 0;
}

int32_t fossil_set_remove(fossil_set_t* set, char *data) {
    if (!set || !set->head) {
        return -1;
    }

    fossil_set_node_t* current = set->head;
    if (fossil_tofu_equal_value(current->data, fossil_tofu_create(fossil_tofu_type_to_string(set->type), data))) {
        set->head = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        return 0;
    }

    while (current->next) {
        if (fossil_tofu_equal_value(current->next->data, fossil_tofu_create(fossil_tofu_type_to_string(set->type), data))) {
            fossil_set_node_t* temp = current->next;
            current->next = current->next->next;
            fossil_tofu_destroy(&temp->data);
            fossil_tofu_free(temp);
            return 0;
        }
        current = current->next;
    }

    return -1;
}

size_t fossil_set_size(const fossil_set_t* set) {
    if (!set) {
        return 0;
    }

    size_t size = 0;
    fossil_set_node_t* current = set->head;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}

bool fossil_set_not_empty(const fossil_set_t* set) {
    return fossil_set_size(set) > 0;
}

bool fossil_set_not_cnullptr(const fossil_set_t* set) {
    return set != NULL;
}

bool fossil_set_is_empty(const fossil_set_t* set) {
    return fossil_set_size(set) == 0;
}

bool fossil_set_is_cnullptr(const fossil_set_t* set) {
    return set == NULL;
}

int32_t fossil_set_contains(const fossil_set_t* set, char *data) {
    return fossil_set_search(set, data);
}
