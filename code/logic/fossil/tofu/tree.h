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

typedef struct fossil_tofu_tree_node_t {
    fossil_tofu_t *value;
    struct fossil_tofu_tree_node_t *left;
    struct fossil_tofu_tree_node_t *right;
} fossil_tofu_tree_node_t;

typedef struct {
    fossil_tofu_tree_node_t *root;
    char *type;
    size_t size;
} fossil_tofu_tree_t;

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
 * @return Pointer to the newly created fossil_tofu_tree_t structure.
 */
fossil_tofu_tree_t* fossil_tofu_tree_create(char *type);

/**
 * @brief Destroys the specified tree and releases its resources.
 * 
 * @param tree Pointer to the tree to be destroyed.
 */
void fossil_tofu_tree_destroy(fossil_tofu_tree_t *tree);

/**
 * -----------------------------------------------------------------------------
 * Node Operations
 * -----------------------------------------------------------------------------
 */

/**
 * @brief Creates a new tree node with the given value.
 * 
 * @param value Pointer to the value to store in the node.
 * @return Pointer to the newly created fossil_tofu_tree_node_t structure.
 */
fossil_tofu_tree_node_t* fossil_tofu_tree_create_node(fossil_tofu_t *value);

/**
 * @brief Inserts a value into the tree.
 * 
 * @param tree Pointer to the tree where the value will be inserted.
 * @param value Pointer to the value to insert.
 * @return 0 on success, non-zero on failure.
 */
int fossil_tofu_tree_insert(fossil_tofu_tree_t *tree, fossil_tofu_t *value);

/**
 * @brief Searches for a node with the specified value in the tree.
 * 
 * @param tree Pointer to the tree to search.
 * @param value Pointer to the value to search for.
 * @return Pointer to the found node, or NULL if not found.
 */
fossil_tofu_tree_node_t* fossil_tofu_tree_search(fossil_tofu_tree_t *tree, const fossil_tofu_t *value);

/**
 * @brief Removes a node with the specified value from the tree.
 * 
 * @param tree Pointer to the tree.
 * @param value Pointer to the value to remove.
 * @return 0 on success, non-zero on failure.
 */
int fossil_tofu_tree_remove(fossil_tofu_tree_t *tree, const fossil_tofu_t *value);

/**
 * @brief Compares two fossil_tofu_t values for ordering.
 * 
 * @param a Pointer to the first value.
 * @param b Pointer to the second value.
 * @return Negative if a < b, 0 if a == b, positive if a > b.
 */
int fossil_tofu_tree_compare(const fossil_tofu_t *a, const fossil_tofu_t *b);

/**
 * @brief Gets the minimum value node in the tree.
 * 
 * @param tree Pointer to the tree.
 * @return Pointer to the node with the minimum value, or NULL if tree is empty.
 */
fossil_tofu_tree_node_t* fossil_tofu_tree_min(fossil_tofu_tree_t *tree);

/**
 * @brief Gets the maximum value node in the tree.
 * 
 * @param tree Pointer to the tree.
 * @return Pointer to the node with the maximum value, or NULL if tree is empty.
 */
fossil_tofu_tree_node_t* fossil_tofu_tree_max(fossil_tofu_tree_t *tree);

/**
 * @brief Gets the height of the tree.
 * 
 * @param tree Pointer to the tree.
 * @return Height of the tree.
 */
int fossil_tofu_tree_height(fossil_tofu_tree_t *tree);

/**
 * @brief Checks if the tree is empty.
 * 
 * @param tree Pointer to the tree.
 * @return 1 if empty, 0 otherwise.
 */
int fossil_tofu_tree_is_empty(fossil_tofu_tree_t *tree);

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
typedef void (*fossil_tofu_tree_visit_fn)(fossil_tofu_t *value);

/**
 * @brief Traverses the tree using the specified visit function.
 * 
 * @param tree Pointer to the tree to traverse.
 * @param visit Function to call for each node's value.
 */
void fossil_tofu_tree_traverse(fossil_tofu_tree_t *tree, fossil_tofu_tree_visit_fn visit);

/**
 * @brief Performs an inorder traversal of the tree nodes.
 * 
 * @param node Pointer to the current node.
 * @param visit Function to call for each node's value.
 */
void fossil_tofu_tree_traverse_inorder(fossil_tofu_tree_node_t *node, fossil_tofu_tree_visit_fn visit);

/**
 * @brief Performs a preorder traversal of the tree nodes.
 * 
 * @param node Pointer to the current node.
 * @param visit Function to call for each node's value.
 */
void fossil_tofu_tree_traverse_preorder(fossil_tofu_tree_node_t *node, fossil_tofu_tree_visit_fn visit);

/**
 * @brief Performs a postorder traversal of the tree nodes.
 * 
 * @param node Pointer to the current node.
 * @param visit Function to call for each node's value.
 */
void fossil_tofu_tree_traverse_postorder(fossil_tofu_tree_node_t *node, fossil_tofu_tree_visit_fn visit);

/**
 * -----------------------------------------------------------------------------
 * Utility Functions
 * -----------------------------------------------------------------------------
 */

/**
 * @brief Clears all nodes from the tree, but does not destroy the tree itself.
 * 
 * @param tree Pointer to the tree to clear.
 */
void fossil_tofu_tree_clear(fossil_tofu_tree_t *tree);

/**
 * @brief Returns the number of nodes in the tree.
 * 
 * @param tree Pointer to the tree.
 * @return Number of nodes in the tree.
 */
size_t fossil_tofu_tree_size(fossil_tofu_tree_t *tree);

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
                tree_ = fossil_tofu_tree_create(const_cast<char*>(type.c_str()));
                if (!tree_) {
                    throw std::runtime_error("Failed to create tree.");
                }
            }

            /**
             * @brief Destroys the Tree object and releases its resources.
             */
            ~Tree() {
                fossil_tofu_tree_destroy(tree_);
            }

            /**
             * @brief Inserts a new Tofu value into the tree.
             * @param value The Tofu object to insert.
             * @throws std::runtime_error If the insertion fails.
             */
            void insert(const Tofu& value) {
                fossil_tofu_t tofu_copy = value.get_c_struct();
                if (fossil_tofu_tree_insert(tree_, &tofu_copy) != 0) {
                    throw std::runtime_error("Failed to insert value into tree.");
                }
            }

            /**
             * @brief Searches for a node with the specified Tofu value in the tree.
             * @param value The Tofu object to search for.
             * @return Pointer to the found node, or nullptr if not found.
             */
            fossil_tofu_tree_node_t* search(const Tofu& value) const {
                // If value is empty, return nullptr for safety
                if (value.is_empty()) return nullptr;
                fossil_tofu_tree_node_t* node = fossil_tofu_tree_search(tree_, &value.get_c_struct());
                return node;
            }

            /**
             * @brief Removes a node with the specified Tofu value from the tree.
             * @param value The Tofu object to remove.
             * @throws std::runtime_error If the removal fails (including if value not found).
             */
            void remove(const Tofu& value) {
                // If value is empty, throw immediately
                if (value.is_empty()) {
                    throw std::runtime_error("Cannot remove empty value from tree.");
                }
                // Check if value exists before attempting removal
                fossil_tofu_tree_node_t* node = fossil_tofu_tree_search(tree_, &value.get_c_struct());
                if (!node) {
                    throw std::runtime_error("Value not found in tree.");
                }
                if (fossil_tofu_tree_remove(tree_, &value.get_c_struct()) != 0) {
                    throw std::runtime_error("Failed to remove value from tree.");
                }
            }

            /**
             * @brief Compares two Tofu values for ordering.
             * @param a The first Tofu object.
             * @param b The second Tofu object.
             * @return Negative if a < b, 0 if a == b, positive if a > b.
             */
            int compare(const Tofu& a, const Tofu& b) const {
                return fossil_tofu_tree_compare(&a.get_c_struct(), &b.get_c_struct());
            }

            /**
             * @brief Gets the node with the minimum value in the tree.
             * @return Pointer to the node with the minimum value, or nullptr if tree is empty.
             */
            fossil_tofu_tree_node_t* min() const {
                if (tree_->size == 0) return nullptr;
                return fossil_tofu_tree_min(tree_);
            }

            /**
             * @brief Gets the node with the maximum value in the tree.
             * @return Pointer to the node with the maximum value, or nullptr if tree is empty.
             */
            fossil_tofu_tree_node_t* max() const {
                if (tree_->size == 0) return nullptr;
                return fossil_tofu_tree_max(tree_);
            }

            /**
             * @brief Gets the height of the tree.
             * @return Height of the tree.
             */
            int height() const {
                if (!tree_ || tree_->size == 0) return 0;
                return fossil_tofu_tree_height(tree_);
            }

            /**
             * @brief Checks if the tree is empty.
             * @return True if the tree is empty, false otherwise.
             */
            bool empty() const {
                return !tree_ || tree_->size == 0;
            }

            /**
             * @brief Gets the number of nodes in the tree.
             * @return The number of nodes in the tree.
             */
            size_t size() const {
                return tree_ ? tree_->size : 0;
            }

            /**
             * @brief Checks if the tree is empty.
             * @return True if the tree is empty, false otherwise.
             */
            bool is_empty() const {
                return size() == 0;
            }

            /**
             * @brief Traverses the tree using the specified visit function.
             * @param visit Function to call for each node's value.
             */
            void traverse(fossil_tofu_tree_visit_fn visit) {
                if (!tree_ || !visit) return;
                fossil_tofu_tree_traverse(tree_, visit);
            }

            /**
             * @brief Performs an inorder traversal of the tree nodes.
             * @param visit Function to call for each node's value.
             */
            void traverse_inorder(fossil_tofu_tree_visit_fn visit) {
                if (!tree_ || !tree_->root || !visit) return;
                fossil_tofu_tree_traverse_inorder(tree_->root, visit);
            }

            /**
             * @brief Performs a preorder traversal of the tree nodes.
             * @param visit Function to call for each node's value.
             */
            void traverse_preorder(fossil_tofu_tree_visit_fn visit) {
                if (!tree_ || !tree_->root || !visit) return;
                fossil_tofu_tree_traverse_preorder(tree_->root, visit);
            }

            /**
             * @brief Performs a postorder traversal of the tree nodes.
             * @param visit Function to call for each node's value.
             */
            void traverse_postorder(fossil_tofu_tree_visit_fn visit) {
                if (!tree_ || !tree_->root || !visit) return;
                fossil_tofu_tree_traverse_postorder(tree_->root, visit);
            }

            /**
             * @brief Clears all nodes from the tree, but does not destroy the tree itself.
             */
            void clear() {
                if (!tree_) return;
                fossil_tofu_tree_clear(tree_);
            }

            /**
             * @brief Returns the number of nodes in the tree.
             * @return The number of nodes in the tree.
             */
            size_t get_size() const {
                return fossil_tofu_tree_size(tree_);
            }

        private:
            fossil_tofu_tree_t* tree_; /**< Pointer to the underlying C tree structure. */
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
