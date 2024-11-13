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
#include "fossil/tofu/doublylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_dlist_t* fossil_dlist_create_container(char* type) {
    fossil_dlist_t* dlist = (fossil_dlist_t*)fossil_tofu_alloc(sizeof(fossil_dlist_t));
    if (!dlist) {
        return NULL;
    }
    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->type = fossil_tofu_strdup(type);
    return dlist;
}

void fossil_dlist_destroy(fossil_dlist_t* dlist) {
    if (!dlist) {
        return;
    }

    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        fossil_dlist_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }

    fossil_tofu_free(dlist->type);
    fossil_tofu_free(dlist);
}

int32_t fossil_dlist_insert(fossil_dlist_t* dlist, char *data) {
    if (!dlist) {
        return -1;
    }

    if (!dlist->head) {
        dlist->head = (fossil_dlist_node_t*)fossil_tofu_alloc(sizeof(fossil_dlist_node_t));
        if (!dlist->head) {
            return -1;
        }
        dlist->head->data = fossil_tofu_create(dlist->type, data);
        dlist->head->prev = NULL;
        dlist->head->next = NULL;
        dlist->tail = dlist->head;
        return 0;
    }

    fossil_dlist_node_t* current = dlist->head;
    while (current->next) {
        current = current->next;
    }

    current->next = (fossil_dlist_node_t*)fossil_tofu_alloc(sizeof(fossil_dlist_node_t));
    if (!current->next) {
        return -1;
    }

    current->next->data = fossil_tofu_create(dlist->type, data);
    current->next->prev = current;
    current->next->next = NULL;
    dlist->tail = current->next;
    return 0;
}

int32_t fossil_dlist_remove(fossil_dlist_t* dlist) {
    if (!dlist || !dlist->head) {
        return -1;
    }

    fossil_dlist_node_t* temp = dlist->head;
    dlist->head = dlist->head->next;
    fossil_tofu_destroy(&temp->data);
    fossil_tofu_free(temp);
    return 0;
}

void fossil_dlist_reverse_forward(fossil_dlist_t* dlist) {
    if (!dlist) {
        return;
    }

    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = NULL;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) {
        dlist->head = temp->prev;
    }
}

void fossil_dlist_reverse_backward(fossil_dlist_t* dlist) {
    if (!dlist) {
        return;
    }

    fossil_dlist_node_t* current = dlist->head;
    fossil_dlist_node_t* temp = NULL;
    while (current) {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    }

    if (temp) {
        dlist->head = temp->next;
    }
}

size_t fossil_dlist_size(const fossil_dlist_t* dlist) {
    if (!dlist) {
        return 0;
    }

    size_t size = 0;
    fossil_dlist_node_t* current = dlist->head;
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

bool fossil_dlist_not_empty(const fossil_dlist_t* dlist) {
    return fossil_dlist_size(dlist) > 0;
}

bool fossil_dlist_not_cnullptr(const fossil_dlist_t* dlist) {
    return dlist != NULL;
}

bool fossil_dlist_is_empty(const fossil_dlist_t* dlist) {
    return fossil_dlist_size(dlist) == 0;
}

bool fossil_dlist_is_cnullptr(const fossil_dlist_t* dlist) {
    return dlist == NULL;
}
