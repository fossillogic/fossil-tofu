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
#include "fossil/tofu/tiranarylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tlist_t* fossil_tlist_create_container(char* type) {
    fossil_tlist_t* tlist = (fossil_tlist_t*)fossil_tofu_alloc(sizeof(fossil_tlist_t));
    if (tlist == NULL) {
        return NULL;
    }
    tlist->head = NULL;
    tlist->tail = NULL;
    tlist->type = type;
    return tlist;
}

fossil_tlist_t* fossil_tlist_create_default(void) {
    return fossil_tlist_create_container("any");
}

fossil_tlist_t* fossil_tlist_create_copy(const fossil_tlist_t* other) {
    fossil_tlist_t* tlist = (fossil_tlist_t*)fossil_tofu_alloc(sizeof(fossil_tlist_t));
    if (tlist == NULL) {
        return NULL;
    }
    tlist->type = other->type;
    tlist->head = NULL;
    tlist->tail = NULL;
    fossil_tlist_node_t* current = other->head;
    while (current) {
        fossil_tlist_insert(tlist, current->data.value.data);
        current = current->next;
    }
    return tlist;
}

fossil_tlist_t* fossil_tlist_create_move(fossil_tlist_t* other) {
    fossil_tlist_t* tlist = (fossil_tlist_t*)fossil_tofu_alloc(sizeof(fossil_tlist_t));
    if (tlist == NULL) {
        return NULL;
    }
    tlist->type = other->type;
    tlist->head = other->head;
    tlist->tail = other->tail;
    other->head = NULL;
    other->tail = NULL;
    return tlist;
}

void fossil_tlist_destroy(fossil_tlist_t* tlist) {
    if (tlist == NULL) {
        return;
    }
    fossil_tlist_node_t* current = tlist->head;
    while (current) {
        fossil_tlist_node_t* next = current->next;
        fossil_tofu_destroy(&current->data);
        fossil_tofu_free(current);
        current = next;
    }
    fossil_tofu_free(tlist);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int32_t fossil_tlist_insert(fossil_tlist_t* tlist, char *data) {
    if (tlist == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tlist_node_t* node = (fossil_tlist_node_t*)fossil_tofu_alloc(sizeof(fossil_tlist_node_t));
    if (node == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    node->data = fossil_tofu_create(tlist->type, data);
    node->prev = NULL;
    node->next = tlist->head;
    node->third = NULL;
    if (tlist->head) {
        tlist->head->prev = node;
    }
    tlist->head = node;
    if (tlist->tail == NULL) {
        tlist->tail = node;
    }
    return FOSSIL_TOFU_SUCCESS;
}

int32_t fossil_tlist_remove(fossil_tlist_t* tlist) {
    if (tlist == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    if (tlist->head == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }
    fossil_tlist_node_t* toDelete = tlist->head;
    tlist->head = tlist->head->next;
    if (tlist->head) {
        tlist->head->prev = NULL;
    } else {
        tlist->tail = NULL;
    }
    fossil_tofu_destroy(&toDelete->data);
    fossil_tofu_free(toDelete);
    return FOSSIL_TOFU_SUCCESS;
}

void fossil_tlist_reverse_forward(fossil_tlist_t* tlist) {
    if (tlist == NULL) {
        return;
    }
    fossil_tlist_node_t* current = tlist->head;
    while (current) {
        fossil_tlist_node_t* next = current->next;
        current->next = current->prev;
        current->prev = current->third;
        current->third = next;
        current = next;
    }
    fossil_tlist_node_t* temp = tlist->head;
    tlist->head = tlist->tail;
    tlist->tail = temp;
}

void fossil_tlist_reverse_backward(fossil_tlist_t* tlist) {
    if (tlist == NULL) {
        return;
    }
    fossil_tlist_node_t* current = tlist->tail;
    while (current) {
        fossil_tlist_node_t* prev = current->prev;
        current->prev = current->next;
        current->next = current->third;
        current->third = prev;
        current = prev;
    }
    fossil_tlist_node_t* temp = tlist->head;
    tlist->head = tlist->tail;
    tlist->tail = temp;
}

size_t fossil_tlist_size(const fossil_tlist_t* tlist) {
    size_t count = 0;
    fossil_tlist_node_t* current = tlist->head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

bool fossil_tlist_not_empty(const fossil_tlist_t* tlist) {
    return tlist->head != NULL;
}

bool fossil_tlist_not_cnullptr(const fossil_tlist_t* tlist) {
    return tlist != NULL;
}

bool fossil_tlist_is_empty(const fossil_tlist_t* tlist) {
    return tlist->head == NULL;
}

bool fossil_tlist_is_cnullptr(const fossil_tlist_t* tlist) {
    return tlist == NULL;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_tlist_get(const fossil_tlist_t* tlist, size_t index) {
    if (tlist == NULL) {
        return NULL;
    }
    fossil_tlist_node_t* current = tlist->head;
    for (size_t i = 0; i < index && current; i++) {
        current = current->next;
    }
    return current ? current->data.value.data : NULL;
}

char *fossil_tlist_get_front(const fossil_tlist_t* tlist) {
    if (tlist == NULL) {
        return NULL;
    }
    return tlist->head ? tlist->head->data.value.data : NULL;
}

char *fossil_tlist_get_back(const fossil_tlist_t* tlist) {
    if (tlist == NULL) {
        return NULL;
    }
    return tlist->tail ? tlist->tail->data.value.data : NULL;
}

void fossil_tlist_set(fossil_tlist_t* tlist, size_t index, char *element) {
    if (tlist == NULL) {
        return;
    }
    fossil_tlist_node_t* current = tlist->head;
    for (size_t i = 0; i < index && current; i++) {
        current = current->next;
    }
    if (current) {
        fossil_tofu_set_value(&current->data, element);
    }
}

void fossil_tlist_set_front(fossil_tlist_t* tlist, char *element) {
    if (tlist == NULL) {
        return;
    }
    if (tlist->head) {
        fossil_tofu_set_value(&tlist->head->data, element);
    }
}

void fossil_tlist_set_back(fossil_tlist_t* tlist, char *element) {
    if (tlist == NULL) {
        return;
    }
    if (tlist->tail) {
        fossil_tofu_set_value(&tlist->tail->data, element);
    }
}
