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
 * @brief Creates a new tree with default values.
 *
 * @return Pointer to the created tree.
 * @note Time complexity: O(1)
 */
fossil_tofu_tree_t* fossil_tofu_tree_create_default(void);

/**
 * @brief Creates a new tree by copying an existing tree.
 *
 * @param other The tree to copy.
 * @return Pointer to the created tree.
 * @note Time complexity: O(n)
 */
fossil_tofu_tree_t* fossil_tofu_tree_create_copy(const fossil_tofu_tree_t* other);

/**
 * @brief Creates a new tree by moving an existing tree.
 *
 * @param other The tree to move.
 * @return Pointer to the created tree.
 * @note Time complexity: O(1)
 */
fossil_tofu_tree_t* fossil_tofu_tree_create_move(fossil_tofu_tree_t* other);

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
             * @brief Constructs a new Tree object with default values.
             * @throws std::runtime_error If the tree cannot be created.
             */
            Tree() {
                tree_ = fossil_tofu_tree_create_default();
                if (!tree_) {
                    throw std::runtime_error("Failed to create default tree.");
                }
            }

            /**
             * @brief Constructs a new Tree object by copying another Tree.
             * @param other The Tree to copy.
             * @throws std::runtime_error If the tree cannot be copied.
             */
            Tree(const Tree& other) {
                tree_ = fossil_tofu_tree_create_copy(other.tree_);
                if (!tree_) {
                    throw std::runtime_error("Failed to copy tree.");
                }
            }

            /**
             * @brief Constructs a new Tree object by moving another Tree.
             * @param other The Tree to move.
             */
            Tree(Tree&& other) noexcept {
                tree_ = other.tree_;
                other.tree_ = nullptr;
            }

            /**
             * @brief Assignment operator for copying another Tree.
             * @param other The Tree to copy.
             * @return Reference to this Tree.
             */
            Tree& operator=(const Tree& other) {
                if (this != &other) {
                    if (tree_) {
                        fossil_tofu_tree_destroy(tree_);
                    }
                    tree_ = fossil_tofu_tree_create_copy(other.tree_);
                    if (!tree_) {
                        throw std::runtime_error("Failed to copy tree in assignment.");
                    }
                }
                return *this;
            }

            /**
             * @brief Assignment operator for moving another Tree.
             * @param other The Tree to move.
             * @return Reference to this Tree.
             */
            Tree& operator=(Tree&& other) noexcept {
                if (this != &other) {
                    if (tree_) {
                        fossil_tofu_tree_destroy(tree_);
                    }
                    tree_ = other.tree_;
                    other.tree_ = nullptr;
                }
                return *this;
            }

            /**
             * @brief Destroys the Tree object and releases its resources.
             */
            ~Tree() {
                if (tree_) {
                    fossil_tofu_tree_destroy(tree_);
                    tree_ = nullptr;
                }
            }

            /**
             * @brief Inserts a new Tofu value into the tree.
             * @param value The Tofu object to insert.
             * @throws std::runtime_error If the insertion fails or value is empty.
             */
            void insert(const Tofu& value) {
                if (!tree_) {
                    throw std::runtime_error("Tree is null.");
                }
                if (value.is_empty()) {
                    throw std::runtime_error("Cannot insert empty value into tree.");
                }

                // Check for duplicate before inserting
                fossil_tofu_tree_node_t* existing = fossil_tofu_tree_search(tree_, &value.get_c_struct());
                if (existing) {
                    throw std::runtime_error("Duplicate value insert attempted.");
                }

                // Dynamically allocate a copy to ensure lifetime is managed
                fossil_tofu_t* tofu_copy = new fossil_tofu_t(value.get_c_struct());
                int rc = fossil_tofu_tree_insert(tree_, tofu_copy);
                if (rc != 0) {
                    delete tofu_copy;
                    throw std::runtime_error("Failed to insert value into tree.");
                }
                // The tree now owns tofu_copy and is responsible for deleting it
            }

            /**
             * @brief Searches for a node with the specified Tofu value in the tree.
             * @param value The Tofu object to search for.
             * @return Pointer to the found node, or nullptr if not found or value is empty.
             */
            fossil_tofu_tree_node_t* search(const Tofu& value) const {
                if (!tree_ || value.is_empty()) return nullptr;
                fossil_tofu_tree_node_t* node = fossil_tofu_tree_search(tree_, &value.get_c_struct());
                return node;
            }

            /**
             * @brief Removes a node with the specified Tofu value from the tree.
             * @param value The Tofu object to remove.
             * @throws std::runtime_error If the removal fails (including if value not found or empty).
             */
            void remove(const Tofu& value) {
                if (!tree_) {
                    throw std::runtime_error("Tree is null.");
                }
                if (value.is_empty()) {
                    throw std::runtime_error("Cannot remove empty value from tree.");
                }
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
                if (!tree_ || tree_->size == 0) return nullptr;
                return fossil_tofu_tree_min(tree_);
            }

            /**
             * @brief Gets the node with the maximum value in the tree.
             * @return Pointer to the node with the maximum value, or nullptr if tree is empty.
             */
            fossil_tofu_tree_node_t* max() const {
                if (!tree_ || tree_->size == 0) return nullptr;
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
             * @return 1 if the tree is empty, 0 otherwise.
             */
            int is_empty() const {
                return (tree_ == nullptr || tree_->size == 0) ? 1 : 0;
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
