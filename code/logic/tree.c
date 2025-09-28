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
#include "fossil/tofu/tree.h"

// *****************************************************************************
// Tree Management Functions
// *****************************************************************************

fossil_tofu_tree_t* fossil_tofu_tree_create(char *type) {
    fossil_tofu_tree_t *tree = (fossil_tofu_tree_t*)fossil_tofu_alloc(sizeof(fossil_tofu_tree_t));
    if (!tree) return NULL;
    tree->root = NULL;
    tree->size = 0;
    tree->type = type ? fossil_tofu_strdup(type) : NULL;
    return tree;
}

static void fossil_tofu_tree_destroy_node(fossil_tofu_tree_node_t *node) {
    if (!node) return;
    fossil_tofu_tree_destroy_node(node->left);
    fossil_tofu_tree_destroy_node(node->right);
    if (node->value) fossil_tofu_destroy(node->value);
    fossil_tofu_free(node);
}

void fossil_tofu_tree_destroy(fossil_tofu_tree_t *tree) {
    if (!tree) return;
    fossil_tofu_tree_destroy_node(tree->root);
    if (tree->type) free(tree->type);
    fossil_tofu_free(tree);
}

// *****************************************************************************
// Node Operations
// *****************************************************************************

fossil_tofu_tree_node_t* fossil_tofu_tree_create_node(fossil_tofu_t *value) {
    if (!value) return NULL;
    fossil_tofu_tree_node_t *node = (fossil_tofu_tree_node_t*)fossil_tofu_alloc(sizeof(fossil_tofu_tree_node_t));
    if (!node) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int fossil_tofu_tree_insert(fossil_tofu_tree_t *tree, fossil_tofu_t *value) {
    if (!tree || !value) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;

    fossil_tofu_tree_node_t *node = fossil_tofu_tree_create_node(value);
    if (!node) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;

    if (!tree->root) {
        tree->root = node;
        tree->size++;
        return FOSSIL_TOFU_SUCCESS;
    }

    fossil_tofu_tree_node_t *current = tree->root;
    while (true) {
        int cmp = fossil_tofu_compare(value, current->value);
        if (cmp < 0) {
            if (!current->left) {
                current->left = node;
                tree->size++;
                return FOSSIL_TOFU_SUCCESS;
            }
            current = current->left;
        } else if (cmp > 0) {
            if (!current->right) {
                current->right = node;
                tree->size++;
                return FOSSIL_TOFU_SUCCESS;
            }
            current = current->right;
        } else {
            // Duplicate values not allowed
            fossil_tofu_free(node);
            return FOSSIL_TOFU_ERROR_OVERFLOW;
        }
    }
}

fossil_tofu_tree_node_t* fossil_tofu_tree_search(fossil_tofu_tree_t *tree, const fossil_tofu_t *value) {
    if (!tree || !value) return NULL;
    fossil_tofu_tree_node_t *current = tree->root;
    while (current) {
        int cmp = fossil_tofu_compare(value, current->value);
        if (cmp < 0) current = current->left;
        else if (cmp > 0) current = current->right;
        else return current;
    }
    return NULL;
}

int fossil_tofu_tree_remove(fossil_tofu_tree_t *tree, const fossil_tofu_t *value) {
    if (!tree || !value) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;

    fossil_tofu_tree_node_t **parent_link = &tree->root;
    fossil_tofu_tree_node_t *current = tree->root;
    while (current) {
        int cmp = fossil_tofu_compare(value, current->value);
        if (cmp < 0) {
            parent_link = &current->left;
            current = current->left;
        } else if (cmp > 0) {
            parent_link = &current->right;
            current = current->right;
        } else {
            // Node found
            if (!current->left) {
                *parent_link = current->right;
            } else if (!current->right) {
                *parent_link = current->left;
            } else {
                // Two children: find inorder successor
                fossil_tofu_tree_node_t **succ_link = &current->right;
                fossil_tofu_tree_node_t *succ = current->right;
                while (succ->left) {
                    succ_link = &succ->left;
                    succ = succ->left;
                }
                // Replace current's value with successor's value
                fossil_tofu_destroy(current->value);
                current->value = fossil_tofu_clone(succ->value);
                // Remove successor node
                fossil_tofu_tree_node_t *to_delete = succ;
                *succ_link = succ->right;
                fossil_tofu_free(to_delete);
                tree->size--;
                return FOSSIL_TOFU_SUCCESS;
            }
            fossil_tofu_destroy(current->value);
            fossil_tofu_free(current);
            tree->size--;
            return FOSSIL_TOFU_SUCCESS;
        }
    }
    return FOSSIL_TOFU_ERROR_NOT_FOUND;
}

int fossil_tofu_tree_compare(const fossil_tofu_t *a, const fossil_tofu_t *b) {
    if (!a && !b) return 0;
    if (!a) return -1;
    if (!b) return 1;
    return fossil_tofu_compare(a, b);
}

fossil_tofu_tree_node_t* fossil_tofu_tree_min(fossil_tofu_tree_t *tree) {
    if (!tree || !tree->root) return NULL;
    fossil_tofu_tree_node_t *current = tree->root;
    while (current->left) current = current->left;
    return current;
}

fossil_tofu_tree_node_t* fossil_tofu_tree_max(fossil_tofu_tree_t *tree) {
    if (!tree || !tree->root) return NULL;
    fossil_tofu_tree_node_t *current = tree->root;
    while (current->right) current = current->right;
    return current;
}

static int fossil_tofu_tree_node_height(fossil_tofu_tree_node_t *node) {
    if (!node) return 0;
    int left = fossil_tofu_tree_node_height(node->left);
    int right = fossil_tofu_tree_node_height(node->right);
    return 1 + (left > right ? left : right);
}

int fossil_tofu_tree_height(fossil_tofu_tree_t *tree) {
    if (!tree) return 0;
    return fossil_tofu_tree_node_height(tree->root);
}

int fossil_tofu_tree_is_empty(fossil_tofu_tree_t *tree) {
    return (!tree || tree->size == 0) ? 1 : 0;
}

// *****************************************************************************
// Traversal Functions
// *****************************************************************************

void fossil_tofu_tree_traverse_inorder(fossil_tofu_tree_node_t *node, fossil_tofu_tree_visit_fn visit) {
    if (!node || !visit) return;
    fossil_tofu_tree_traverse_inorder(node->left, visit);
    visit(node->value);
    fossil_tofu_tree_traverse_inorder(node->right, visit);
}

void fossil_tofu_tree_traverse_preorder(fossil_tofu_tree_node_t *node, fossil_tofu_tree_visit_fn visit) {
    if (!node || !visit) return;
    visit(node->value);
    fossil_tofu_tree_traverse_preorder(node->left, visit);
    fossil_tofu_tree_traverse_preorder(node->right, visit);
}

void fossil_tofu_tree_traverse_postorder(fossil_tofu_tree_node_t *node, fossil_tofu_tree_visit_fn visit) {
    if (!node || !visit) return;
    fossil_tofu_tree_traverse_postorder(node->left, visit);
    fossil_tofu_tree_traverse_postorder(node->right, visit);
    visit(node->value);
}

void fossil_tofu_tree_traverse(fossil_tofu_tree_t *tree, fossil_tofu_tree_visit_fn visit) {
    if (!tree || !visit) return;
    fossil_tofu_tree_traverse_inorder(tree->root, visit);
}

/**
 * -----------------------------------------------------------------------------
 * Utility Functions
 * -----------------------------------------------------------------------------
 */

void fossil_tofu_tree_clear(fossil_tofu_tree_t *tree) {
    if (!tree) return;
    fossil_tofu_tree_destroy_node(tree->root);
    tree->root = NULL;
    tree->size = 0;
}

size_t fossil_tofu_tree_size(fossil_tofu_tree_t *tree) {
    return tree ? tree->size : 0;
}
