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

fossil_flist_t* fossil_flist_create_container(char* type) {
    fossil_flist_t* flist = (fossil_flist_t*)fossil_tofu_alloc(sizeof(fossil_flist_t));
    if (!flist) {
        return NULL;
    }
    flist->head = NULL;
    flist->type = fossil_tofu_strdup(type);
    return flist;
}

void fossil_flist_destroy(fossil_flist_t* flist) {
    if (!flist) {
        return;
    }

    fossil_flist_node_t* current = flist->head;
    while (current) {
        fossil_flist_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(flist->type);
    fossil_tofu_free(flist);
}

int32_t fossil_flist_insert(fossil_flist_t* flist, char *data) {
    if (!flist) {
        return -1;
    }

    if (!flist->head) {
        flist->head = (fossil_flist_node_t*)fossil_tofu_alloc(sizeof(fossil_flist_node_t));
        if (!flist->head) {
            return -1;
        }
        flist->head->data = fossil_tofu_create(flist->type, data);
        flist->head->next = NULL;
        return 0;
    }

    fossil_flist_node_t* current = flist->head;
    while (current->next) {
        current = current->next;
    }

    current->next = (fossil_flist_node_t*)fossil_tofu_alloc(sizeof(fossil_flist_node_t));
    if (!current->next) {
        return -1;
    }

    current->next->data = fossil_tofu_create(flist->type, data);
    current->next->next = NULL;
    return 0;
}

int32_t fossil_flist_remove(fossil_flist_t* flist, char *data) {
    if (!flist || !flist->head) {
        return -1;
    }

    fossil_flist_node_t* temp = flist->head;
    flist->head = flist->head->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return 0;
}

void fossil_flist_reverse_forward(fossil_flist_t* flist) {
    if (!flist || !flist->head) {
        return;
    }

    fossil_flist_node_t* current = flist->head;
    fossil_flist_node_t* previous = NULL;
    while (current) {
        fossil_flist_node_t* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    flist->head = previous;
}

void fossil_flist_reverse_backward(fossil_flist_t* flist) {
    if (!flist || !flist->head) {
        return;
    }

    fossil_flist_node_t* current = flist->head;
    fossil_flist_node_t* previous = NULL;
    while (current) {
        fossil_flist_node_t* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    flist->head = previous;
}

size_t fossil_flist_size(const fossil_flist_t* flist) {
    if (!flist) {
        return 0;
    }

    size_t size = 0;
    fossil_flist_node_t* current = flist->head;
    while (current) {
        size++;
        current = current->next;
    }

    return size;
}

bool fossil_flist_not_empty(const fossil_flist_t* flist) {
    return fossil_flist_size(flist) > 0;
}

bool fossil_flist_not_cnullptr(const fossil_flist_t* flist) {
    return flist != NULL;
}

bool fossil_flist_is_empty(const fossil_flist_t* flist) {
    return fossil_flist_size(flist) == 0;
}

bool fossil_flist_is_cnullptr(const fossil_flist_t* flist) {
    return flist == NULL;
}
