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
#ifndef FOSSIL_TOFU_TREE_H
#define FOSSIL_TOFU_TREE_H

#include "tofu.h"

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type Definitions
// *****************************************************************************

typedef struct fossil_tree_node_t {
    fossil_tofu_t *value;
    struct fossil_tree_node_t *left;
    struct fossil_tree_node_t *right;
} fossil_tree_node_t;

typedef struct {
    fossil_tree_node_t *root;
    char *type;
    size_t size;
} fossil_tree_t;

/**
 * -----------------------------------------------------------------------------
 * Tree Management Functions
 * -----------------------------------------------------------------------------
 */

/**
 * @brief Creates a new tree structure.
 * 
 * @param type The type of values the tree will hold.
 * 
 * @return Pointer to the newly created fossil_tree_t structure.
 */
fossil_tree_t* fossil_tree_create(char *type);

/**
 * @brief Destroys the specified tree and releases its resources.
 * 
 * @param tree Pointer to the tree to be destroyed.
 */
void fossil_tree_destroy(fossil_tree_t *tree);

/**
 * -----------------------------------------------------------------------------
 * Node Operations
 * -----------------------------------------------------------------------------
 */

/**
 * @brief Creates a new tree node with the given value.
 * 
 * @param value Pointer to the value to store in the node.
 * @return Pointer to the newly created fossil_tree_node_t structure.
 */
fossil_tree_node_t* fossil_tree_create_node(fossil_tofu_t *value);

/**
 * @brief Inserts a value into the tree.
 * 
 * @param tree Pointer to the tree where the value will be inserted.
 * @param value Pointer to the value to insert.
 * @return 0 on success, non-zero on failure.
 */
int fossil_tree_insert(fossil_tree_t *tree, fossil_tofu_t *value);

/**
 * @brief Searches for a node with the specified value in the tree.
 * 
 * @param tree Pointer to the tree to search.
 * @param value Pointer to the value to search for.
 * @return Pointer to the found node, or NULL if not found.
 */
fossil_tree_node_t* fossil_tree_search(fossil_tree_t *tree, const fossil_tofu_t *value);

/**
 * -----------------------------------------------------------------------------
 * Traversal Functions
 * -----------------------------------------------------------------------------
 */

/**
 * @brief Function pointer type for visiting tree nodes during traversal.
 * 
 * @param value Pointer to the value in the node being visited.
 */
typedef void (*fossil_tree_visit_fn)(fossil_tofu_t *value);

/**
 * @brief Traverses the tree using the specified visit function.
 * 
 * @param tree Pointer to the tree to traverse.
 * @param visit Function to call for each node's value.
 */
void fossil_tree_traverse(fossil_tree_t *tree, fossil_tree_visit_fn visit);

/**
 * @brief Performs an inorder traversal of the tree nodes.
 * 
 * @param node Pointer to the current node.
 * @param visit Function to call for each node's value.
 */
void fossil_tree_traverse_inorder(fossil_tree_node_t *node, fossil_tree_visit_fn visit);

/**
 * @brief Performs a preorder traversal of the tree nodes.
 * 
 * @param node Pointer to the current node.
 * @param visit Function to call for each node's value.
 */
void fossil_tree_traverse_preorder(fossil_tree_node_t *node, fossil_tree_visit_fn visit);

/**
 * @brief Performs a postorder traversal of the tree nodes.
 * 
 * @param node Pointer to the current node.
 * @param visit Function to call for each node's value.
 */
void fossil_tree_traverse_postorder(fossil_tree_node_t *node, fossil_tree_visit_fn visit);

#ifdef __cplusplus
}
#include <stdexcept>
#include <string>

namespace fossil {

namespace tofu {

    /**
     * @class Tree
     * @brief A C++ wrapper class for managing a binary tree using the Fossil Logic library and Tofu objects.
     */
    class Tree {
    public:
        /**
         * @brief Constructs a new Tree object.
         * @throws std::runtime_error If the tree cannot be created.
         */
        explicit Tree(const std::string& type) {
            tree_ = fossil_tree_create(const_cast<char*>(type.c_str()));
            if (!tree_) {
                throw std::runtime_error("Failed to create tree.");
            }
        }

        /**
         * @brief Destroys the Tree object and releases its resources.
         */
        ~Tree() {
            fossil_tree_destroy(tree_);
        }

        /**
         * @brief Inserts a new Tofu value into the tree.
         * @param value The Tofu object to insert.
         * @throws std::runtime_error If the insertion fails.
         */
        void insert(const Tofu& value) {
            fossil_tofu_t tofu_copy = value.get_c_struct();
            if (fossil_tree_insert(tree_, &tofu_copy) != 0) {
                throw std::runtime_error("Failed to insert value into tree.");
            }
        }

        /**
         * @brief Searches for a node with the specified Tofu value in the tree.
         * @param value The Tofu object to search for.
         * @return Pointer to the found node, or nullptr if not found.
         */
        fossil_tree_node_t* search(const Tofu& value) const {
            return fossil_tree_search(tree_, &value.get_c_struct());
        }

        /**
         * @brief Gets the number of nodes in the tree.
         * @return The number of nodes in the tree.
         */
        size_t size() const {
            return tree_->size;
        }

        /**
         * @brief Checks if the tree is empty.
         * @return True if the tree is empty, false otherwise.
         */
        bool is_empty() const {
            return tree_->size == 0;
        }

        /**
         * @brief Traverses the tree using the specified visit function.
         * @param visit Function to call for each node's value.
         */
        void traverse(fossil_tree_visit_fn visit) {
            fossil_tree_traverse(tree_, visit);
        }

        /**
         * @brief Performs an inorder traversal of the tree nodes.
         * @param visit Function to call for each node's value.
         */
        void traverse_inorder(fossil_tree_visit_fn visit) {
            fossil_tree_traverse_inorder(tree_->root, visit);
        }

        /**
         * @brief Performs a preorder traversal of the tree nodes.
         * @param visit Function to call for each node's value.
         */
        void traverse_preorder(fossil_tree_visit_fn visit) {
            fossil_tree_traverse_preorder(tree_->root, visit);
        }

        /**
         * @brief Performs a postorder traversal of the tree nodes.
         * @param visit Function to call for each node's value.
         */
        void traverse_postorder(fossil_tree_visit_fn visit) {
            fossil_tree_traverse_postorder(tree_->root, visit);
        }

    private:
        fossil_tree_t* tree_; /**< Pointer to the underlying C tree structure. */
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
