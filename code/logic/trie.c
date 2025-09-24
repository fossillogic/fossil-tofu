/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/tofu/trie.h"

// *****************************************************************************
// Internal helpers
// *****************************************************************************

static fossil_trie_node_t* fossil_trie_node_create(char ch) {
    fossil_trie_node_t* node = (fossil_trie_node_t*)calloc(1, sizeof(fossil_trie_node_t));
    if (!node) return NULL;
    node->ch = ch;
    node->is_terminal = false;
    node->children = NULL;
    node->child_count = 0;
    node->value = fossil_tofu_create_default() ? *fossil_tofu_create_default() : (fossil_tofu_t){0};
    return node;
}

static void fossil_trie_node_destroy(fossil_trie_node_t* node) {
    if (!node) return;
    for (size_t i = 0; i < node->child_count; i++) {
        fossil_trie_node_destroy(node->children[i]);
    }
    free(node->children);
    fossil_tofu_destroy(&node->value);
    free(node);
}

static fossil_trie_node_t* fossil_trie_find_child(fossil_trie_node_t* parent, char ch) {
    for (size_t i = 0; i < parent->child_count; i++) {
        if (parent->children[i]->ch == ch) {
            return parent->children[i];
        }
    }
    return NULL;
}

static fossil_trie_node_t* fossil_trie_add_child(fossil_trie_node_t* parent, char ch) {
    fossil_trie_node_t* child = fossil_trie_node_create(ch);
    if (!child) return NULL;

    fossil_trie_node_t** new_children =
        realloc(parent->children, (parent->child_count + 1) * sizeof(fossil_trie_node_t*));
    if (!new_children) {
        free(child);
        return NULL;
    }

    parent->children = new_children;
    parent->children[parent->child_count++] = child;
    return child;
}

// *****************************************************************************
// Public API
// *****************************************************************************

fossil_trie_t* fossil_trie_create(const char* value_type) {
    fossil_trie_t* trie = (fossil_trie_t*)calloc(1, sizeof(fossil_trie_t));
    if (!trie) return NULL;
    trie->root = fossil_trie_node_create('\0');
    trie->value_type = value_type ? strdup(value_type) : NULL;
    trie->size = 0;
    return trie;
}

fossil_trie_t* fossil_trie_create_default(void) {
    return fossil_trie_create(NULL);
}

void clone_node(fossil_trie_node_t* dst, const fossil_trie_node_t* src) {
    dst->is_terminal = src->is_terminal;
    fossil_tofu_copy(&dst->value, &src->value);
    for (size_t i = 0; i < src->child_count; i++) {
        fossil_trie_node_t* child = fossil_trie_add_child(dst, src->children[i]->ch);
        clone_node(child, src->children[i]);
    }
}

fossil_trie_t* fossil_trie_create_copy(const fossil_trie_t* other) {
    if (!other) return NULL;
    fossil_trie_t* copy = fossil_trie_create(other->value_type);
    if (!copy) return NULL;

    // Simple recursive DFS clone
    // Helper lambda-like function
    
    clone_node(copy->root, other->root);
    copy->size = other->size;
    return copy;
}

fossil_trie_t* fossil_trie_create_move(fossil_trie_t* other) {
    if (!other) return NULL;
    fossil_trie_t* new_trie = (fossil_trie_t*)calloc(1, sizeof(fossil_trie_t));
    if (!new_trie) return NULL;
    *new_trie = *other;
    other->root = NULL;
    other->value_type = NULL;
    other->size = 0;
    return new_trie;
}

void fossil_trie_destroy(fossil_trie_t* trie) {
    if (!trie) return;
    fossil_trie_node_destroy(trie->root);
    free(trie->value_type);
    free(trie);
}

int32_t fossil_trie_insert(fossil_trie_t* trie, const char* key, const char* value) {
    if (!trie || !key) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;

    fossil_trie_node_t* current = trie->root;
    for (const char* p = key; *p; ++p) {
        fossil_trie_node_t* child = fossil_trie_find_child(current, *p);
        if (!child) {
            child = fossil_trie_add_child(current, *p);
            if (!child) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
        }
        current = child;
    }

    if (!current->is_terminal) {
        current->is_terminal = true;
        trie->size++;
    }
    fossil_tofu_set_value(&current->value, (char*)value);
    return FOSSIL_TOFU_SUCCESS;
}

fossil_tofu_t fossil_trie_get(const fossil_trie_t* trie, const char* key) {
    fossil_tofu_t empty = {0};
    if (!trie || !key) return empty;

    fossil_trie_node_t* current = trie->root;
    for (const char* p = key; *p; ++p) {
        current = fossil_trie_find_child(current, *p);
        if (!current) return empty;
    }
    if (current->is_terminal) return current->value;
    return empty;
}

bool fossil_trie_contains(const fossil_trie_t* trie, const char* key) {
    fossil_tofu_t v = fossil_trie_get(trie, key);
    return !fossil_tofu_is_empty(&v);
}

// Recursive function to remove key and prune empty nodes
bool remove_rec(fossil_trie_node_t* node, const char* k) {
    if (*k == '\0') {
        if (!node->is_terminal) return false;
        node->is_terminal = false;
        fossil_tofu_destroy(&node->value);
        return node->child_count == 0;
    }
    fossil_trie_node_t* child = fossil_trie_find_child(node, *k);
    if (!child) return false;
    bool should_prune = remove_rec(child, k + 1);
    if (should_prune) {
        // Remove child from parent's array
        for (size_t i = 0; i < node->child_count; i++) {
            if (node->children[i] == child) {
                fossil_trie_node_destroy(child);
                memmove(&node->children[i], &node->children[i + 1],
                        (node->child_count - i - 1) * sizeof(fossil_trie_node_t*));
                node->child_count--;
                break;
            }
        }
        if (node->child_count == 0 && !node->is_terminal) return true;
    }
    return false;
}

int32_t fossil_trie_remove(fossil_trie_t* trie, const char* key) {
    if (!trie || !key) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;
    bool removed = remove_rec(trie->root, key);
    if (removed) trie->size--;
    return removed ? FOSSIL_TOFU_SUCCESS : FOSSIL_TOFU_ERROR_NOT_FOUND;
}

size_t fossil_trie_size(const fossil_trie_t* trie) {
    return trie ? trie->size : 0;
}

bool fossil_trie_is_empty(const fossil_trie_t* trie) {
    return trie ? (trie->size == 0) : true;
}

void fossil_trie_clear(fossil_trie_t* trie) {
    if (!trie) return;
    fossil_trie_node_destroy(trie->root);
    trie->root = fossil_trie_node_create('\0');
    trie->size = 0;
}

void dump_rec(const fossil_trie_node_t* node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("%c%s\n", node->ch ? node->ch : '*', node->is_terminal ? " (end)" : "");
    for (size_t i = 0; i < node->child_count; i++) {
        dump_rec(node->children[i], depth + 1);
    }
}

void fossil_trie_dump(const fossil_trie_t* trie) {
    if (!trie) return;
    dump_rec(trie->root, 0);
}
