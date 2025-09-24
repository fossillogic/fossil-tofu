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

static fossil_trie_node_t* fossil_trie_node_find_child(fossil_trie_node_t* node, char ch) {
    for (size_t i = 0; i < node->child_count; i++) {
        if (node->children[i]->ch == ch) return node->children[i];
    }
    return NULL;
}

static fossil_trie_node_t* fossil_trie_node_add_child(fossil_trie_node_t* node, char ch) {
    fossil_trie_node_t* child = fossil_trie_node_create(ch);
    if (!child) return NULL;
    node->children = (fossil_trie_node_t**)realloc(node->children, (node->child_count + 1) * sizeof(fossil_trie_node_t*));
    node->children[node->child_count++] = child;
    return child;
}

// *****************************************************************************
// Public API
// *****************************************************************************

fossil_trie_t* fossil_trie_create(const char* value_type) {
    fossil_trie_t* trie = (fossil_trie_t*)calloc(1, sizeof(fossil_trie_t));
    if (!trie) return NULL;
    trie->root = fossil_trie_node_create('\0');  // root has null char
    trie->value_type = value_type ? fossil_tofu_strdup(value_type) : NULL;
    trie->size = 0;
    return trie;
}

fossil_trie_t* fossil_trie_create_default(void) {
    return fossil_trie_create(NULL);
}

fossil_trie_t* fossil_trie_create_copy(const fossil_trie_t* other) {
    if (!other) return NULL;
    // Shallow allocation first
    fossil_trie_t* copy = fossil_trie_create(other->value_type);
    if (!copy) return NULL;

    // Recursive copy helper
    void copy_node(fossil_trie_node_t* dest, fossil_trie_node_t* src) {
        dest->is_terminal = src->is_terminal;
        if (src->is_terminal) dest->value = fossil_tofu_create_copy(&src->value)[0];
        for (size_t i = 0; i < src->child_count; i++) {
            fossil_trie_node_t* child = fossil_trie_node_add_child(dest, src->children[i]->ch);
            copy_node(child, src->children[i]);
        }
    }

    copy_node(copy->root, other->root);
    copy->size = other->size;
    return copy;
}

fossil_trie_t* fossil_trie_create_move(fossil_trie_t* other) {
    if (!other) return NULL;
    fossil_trie_t* moved = (fossil_trie_t*)malloc(sizeof(fossil_trie_t));
    *moved = *other;
    memset(other, 0, sizeof(fossil_trie_t));
    return moved;
}

void fossil_trie_destroy(fossil_trie_t* trie) {
    if (!trie) return;
    fossil_trie_node_destroy(trie->root);
    free(trie->value_type);
    free(trie);
}

int32_t fossil_trie_insert(fossil_trie_t* trie, const char* key, const char* value) {
    if (!trie || !key) return -1;
    fossil_trie_node_t* node = trie->root;
    for (size_t i = 0; key[i]; i++) {
        fossil_trie_node_t* child = fossil_trie_node_find_child(node, key[i]);
        if (!child) child = fossil_trie_node_add_child(node, key[i]);
        if (!child) return -1;
        node = child;
    }
    if (!node->is_terminal) trie->size++;
    node->is_terminal = true;
    node->value = fossil_tofu_create(trie->value_type, value);
    return 0;
}

fossil_tofu_t fossil_trie_get(const fossil_trie_t* trie, const char* key) {
    fossil_tofu_t empty = *fossil_tofu_create_default();
    if (!trie || !key) return empty;

    fossil_trie_node_t* node = trie->root;
    for (size_t i = 0; key[i]; i++) {
        node = fossil_trie_node_find_child(node, key[i]);
        if (!node) return empty;
    }
    return node->is_terminal ? node->value : empty;
}

int32_t fossil_trie_remove(fossil_trie_t* trie, const char* key) {
    if (!trie || !key) return -1;

    // Stack to keep track of the path
    typedef struct {
        fossil_trie_node_t* node;
        size_t index;
    } StackItem;

    StackItem* stack = NULL;
    size_t stack_size = 0;

    fossil_trie_node_t* node = trie->root;
    for (size_t i = 0; key[i]; i++) {
        fossil_trie_node_t* child = fossil_trie_node_find_child(node, key[i]);
        if (!child) {
            free(stack);
            return -1;  // Key not found
        }
        stack = (StackItem*)realloc(stack, (stack_size + 1) * sizeof(StackItem));
        stack[stack_size++] = (StackItem){node, i};
        node = child;
    }

    if (!node->is_terminal) {
        free(stack);
        return -1;  // Key not found
    }

    // Mark the node as non-terminal and free its value
    node->is_terminal = false;
    fossil_tofu_destroy(&node->value);
    trie->size--;

    // Clean up nodes if they are no longer needed
    for (ssize_t i = stack_size - 1; i >= 0; i--) {
        fossil_trie_node_t* parent = stack[i].node;
        char ch = key[stack[i].index];
        fossil_trie_node_t* child = fossil_trie_node_find_child(parent, ch);

        if (child->is_terminal || child->child_count > 0) break;  // Stop if child is still needed

        // Remove child from parent
        size_t j;
        for (j = 0; j < parent->child_count; j++) {
            if (parent->children[j] == child) break;
        }
        if (j < parent->child_count) {
            free(child);
            for (size_t k = j; k < parent->child_count - 1; k++) {
                parent->children[k] = parent->children[k + 1];
            }
            parent->child_count--;
            parent->children = (fossil_trie_node_t**)realloc(parent->children, parent->child_count * sizeof(fossil_trie_node_t*));
        }
    }

    free(stack);
    return 0;
}

bool fossil_trie_contains(const fossil_trie_t* trie, const char* key) {
    fossil_tofu_t value = fossil_trie_get(trie, key);
    return !fossil_tofu_is_empty(&value);
}

size_t fossil_trie_size(const fossil_trie_t* trie) {
    return trie ? trie->size : 0;
}

bool fossil_trie_is_empty(const fossil_trie_t* trie) {
    return trie ? trie->size == 0 : true;
}

int32_t fossil_trie_get_keys_with_prefix(const fossil_trie_t* trie, const char* prefix, char*** out_keys, size_t* out_count) {
    if (!trie || !prefix || !out_keys || !out_count) return -1;
    *out_keys = NULL;
    *out_count = 0;

    fossil_trie_node_t* node = trie->root;
    for (size_t i = 0; prefix[i]; i++) {
        node = fossil_trie_node_find_child(node, prefix[i]);
        if (!node) return 0;  // No keys with this prefix
    }

    // Recursive helper to collect keys
    void collect_keys(fossil_trie_node_t* n, char* buffer, size_t depth) {
        if (n->is_terminal) {
            buffer[depth] = '\0';
            *out_keys = (char**)realloc(*out_keys, (*out_count + 1) * sizeof(char*));
            (*out_keys)[*out_count] = fossil_tofu_strdup(buffer);
            (*out_count)++;
        }
        for (size_t i = 0; i < n->child_count; i++) {
            buffer[depth] = n->children[i]->ch;
            collect_keys(n->children[i], buffer, depth + 1);
        }
    }

    char buffer[256];  // Assuming max key length is 255
    strncpy(buffer, prefix, sizeof(buffer) - 1);
    collect_keys(node, buffer, strlen(prefix));
    return 0;
}

void fossil_trie_clear(fossil_trie_t* trie) {
    if (!trie) return;
    fossil_trie_node_destroy(trie->root);
    trie->root = fossil_trie_node_create('\0');
    trie->size = 0;
}

void fossil_trie_dump(const fossil_trie_t* trie) {
    if (!trie) return;
    printf("Trie size: %zu\n", trie->size);
    void dump_node(fossil_trie_node_t* node, int depth) {
        if (!node) return;
        for (int i = 0; i < depth; i++) printf("  ");
        printf("%c%s\n", node->ch ? node->ch : '*', node->is_terminal ? " [T]" : "");
        for (size_t i = 0; i < node->child_count; i++) dump_node(node->children[i], depth + 1);
    }
    dump_node(trie->root, 0);
}
