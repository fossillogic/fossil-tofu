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

fossil_tree_t* fossil_tree_create(char *type) {
    fossil_tree_t *tree = (fossil_tree_t*)fossil_tofu_alloc(sizeof(fossil_tree_t));
    if (!tree) return NULL;
    tree->root = NULL;
    tree->size = 0;
    tree->type = type;
    return tree;
}

static void fossil_tree_destroy_node(fossil_tree_node_t *node) {
    if (!node) return;
    fossil_tree_destroy_node(node->left);
    fossil_tree_destroy_node(node->right);
    if (node->value) fossil_tofu_destroy(node->value);
    fossil_tofu_free(node);
}

void fossil_tree_destroy(fossil_tree_t *tree) {
    if (!tree) return;
    fossil_tree_destroy_node(tree->root);
    fossil_tofu_free(tree);
}

// *****************************************************************************
// Node Operations
// *****************************************************************************

fossil_tree_node_t* fossil_tree_create_node(fossil_tofu_t *value) {
    if (!value) return NULL;
    fossil_tree_node_t *node = (fossil_tree_node_t*)fossil_tofu_alloc(sizeof(fossil_tree_node_t));
    if (!node) return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int fossil_tree_insert(fossil_tree_t *tree, fossil_tofu_t *value) {
    if (!tree || !value) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;

    fossil_tree_node_t *node = fossil_tree_create_node(value);
    if (!node) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;

    if (!tree->root) {
        tree->root = node;
        tree->size++;
        return FOSSIL_TOFU_SUCCESS;
    }

    fossil_tree_node_t *current = tree->root;
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
            fossil_tofu_destroy(node->value);
            fossil_tofu_free(node);
            return FOSSIL_TOFU_ERROR_OVERFLOW;
        }
    }
}

fossil_tree_node_t* fossil_tree_search(fossil_tree_t *tree, const fossil_tofu_t *value) {
    if (!tree || !value) return NULL;
    fossil_tree_node_t *current = tree->root;
    while (current) {
        int cmp = fossil_tofu_compare(value, current->value);
        if (cmp < 0) current = current->left;
        else if (cmp > 0) current = current->right;
        else return current;
    }
    return NULL;
}

// *****************************************************************************
// Traversal Functions
// *****************************************************************************

void fossil_tree_traverse_inorder(fossil_tree_node_t *node, fossil_tree_visit_fn visit) {
    if (!node) return;
    fossil_tree_traverse_inorder(node->left, visit);
    visit(node->value);
    fossil_tree_traverse_inorder(node->right, visit);
}

void fossil_tree_traverse_preorder(fossil_tree_node_t *node, fossil_tree_visit_fn visit) {
    if (!node) return;
    visit(node->value);
    fossil_tree_traverse_preorder(node->left, visit);
    fossil_tree_traverse_preorder(node->right, visit);
}

void fossil_tree_traverse_postorder(fossil_tree_node_t *node, fossil_tree_visit_fn visit) {
    if (!node) return;
    fossil_tree_traverse_postorder(node->left, visit);
    fossil_tree_traverse_postorder(node->right, visit);
    visit(node->value);
}

void fossil_tree_traverse(fossil_tree_t *tree, fossil_tree_visit_fn visit) {
    if (!tree || !visit) return;
    fossil_tree_traverse_inorder(tree->root, visit);
}
