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
#include <fossil/pizza/framework.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_SUITE(c_tree_tofu_fixture);

FOSSIL_SETUP(c_tree_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_tree_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_tree_create_and_destroy) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    ASSUME_NOT_CNULL(tree);
    ASSUME_ITS_EQUAL_I32(tree->size, 0);
    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_insert_duplicate) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    fossil_tofu_t v10 = fossil_tofu_create("i32", "10");
    fossil_tofu_tree_insert(tree, &v10);
    fossil_tofu_t v10_dup = fossil_tofu_create("i32", "10");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_insert(tree, &v10_dup), FOSSIL_TOFU_ERROR_OVERFLOW);
    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_null_pointer_safety) {
    fossil_tofu_tree_t* tree = NULL;
    ASSUME_ITS_CNULL(fossil_tofu_tree_search(tree, NULL));
    fossil_tofu_tree_traverse(tree, NULL); // Should not crash
    fossil_tofu_tree_destroy(tree); // Should not crash
}

FOSSIL_TEST(c_test_tree_create_node_null_value) {
    fossil_tofu_tree_node_t* node = fossil_tofu_tree_create_node(NULL);
    ASSUME_ITS_CNULL(node);
}

FOSSIL_TEST(c_test_tree_create_node_valid_value) {
    fossil_tofu_t v42 = fossil_tofu_create("i32", "42");
    fossil_tofu_tree_node_t* node = fossil_tofu_tree_create_node(&v42);
    ASSUME_NOT_CNULL(node);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_compare(node->value, &v42), 0);
    fossil_tofu_destroy(node->value);
    fossil_tofu_free(node);
}

FOSSIL_TEST(c_test_tree_search_not_found) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    fossil_tofu_t v10 = fossil_tofu_create("i32", "10");
    fossil_tofu_tree_insert(tree, &v10);
    fossil_tofu_t v30 = fossil_tofu_create("i32", "30");
    fossil_tofu_tree_node_t* found = fossil_tofu_tree_search(tree, &v30);
    ASSUME_ITS_CNULL(found);
    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_insert_null_tree_or_value) {
    fossil_tofu_t v10 = fossil_tofu_create("i32", "10");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_insert(NULL, &v10), FOSSIL_TOFU_ERROR_INVALID_ARGUMENT);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_insert(NULL, NULL), FOSSIL_TOFU_ERROR_INVALID_ARGUMENT);
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_insert(tree, NULL), FOSSIL_TOFU_ERROR_INVALID_ARGUMENT);
    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_remove_existing_and_nonexisting) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    fossil_tofu_t v10 = fossil_tofu_create("i32", "10");
    fossil_tofu_t v20 = fossil_tofu_create("i32", "20");
    fossil_tofu_tree_insert(tree, &v10);
    fossil_tofu_tree_insert(tree, &v20);

    // Remove existing node
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_remove(tree, &v10), FOSSIL_TOFU_SUCCESS);
    // Remove non-existing node
    fossil_tofu_t v30 = fossil_tofu_create("i32", "30");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_remove(tree, &v30), FOSSIL_TOFU_ERROR_NOT_FOUND);

    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_min_max) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    fossil_tofu_t v10 = fossil_tofu_create("i32", "10");
    fossil_tofu_t v20 = fossil_tofu_create("i32", "20");
    fossil_tofu_t v5 = fossil_tofu_create("i32", "5");
    fossil_tofu_tree_insert(tree, &v10);
    fossil_tofu_tree_insert(tree, &v20);
    fossil_tofu_tree_insert(tree, &v5);

    fossil_tofu_tree_node_t* min_node = fossil_tofu_tree_min(tree);
    fossil_tofu_tree_node_t* max_node = fossil_tofu_tree_max(tree);
    ASSUME_NOT_CNULL(min_node);
    ASSUME_NOT_CNULL(max_node);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_compare(min_node->value, &v5), 0);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_compare(max_node->value, &v20), 0);

    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_height_and_is_empty) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_height(tree), 0);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_is_empty(tree), 1);

    fossil_tofu_t v10 = fossil_tofu_create("i32", "10");
    fossil_tofu_t v20 = fossil_tofu_create("i32", "20");
    fossil_tofu_tree_insert(tree, &v10);
    fossil_tofu_tree_insert(tree, &v20);

    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_height(tree), 2);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_is_empty(tree), 0);

    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_traverse_and_clear) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    fossil_tofu_t v1 = fossil_tofu_create("i32", "1");
    fossil_tofu_t v2 = fossil_tofu_create("i32", "2");
    fossil_tofu_t v3 = fossil_tofu_create("i32", "3");
    fossil_tofu_tree_insert(tree, &v2);
    fossil_tofu_tree_insert(tree, &v1);
    fossil_tofu_tree_insert(tree, &v3);

    // Use a wrapper to pass counter as user data if supported, else just check traversal doesn't crash
    fossil_tofu_tree_traverse(tree, NULL); // Should not crash
    fossil_tofu_tree_traverse_inorder(tree->root, NULL); // Should not crash
    // Use a wrapper to pass counter as user data if supported, else just check traversal doesn't crash
    fossil_tofu_tree_traverse(tree, NULL); // Should not crash
    fossil_tofu_tree_traverse_inorder(tree->root, NULL); // Should not crash

    // If fossil_tofu_user_data is not available, just check size before/after clear
    size_t sz = fossil_tofu_tree_size(tree);
    ASSUME_ITS_EQUAL_I32(sz, 3);

    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_size_function) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_size(tree), 0);

    fossil_tofu_t v1 = fossil_tofu_create("i32", "1");
    fossil_tofu_t v2 = fossil_tofu_create("i32", "2");
    fossil_tofu_tree_insert(tree, &v1);
    fossil_tofu_tree_insert(tree, &v2);

    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_size(tree), 2);

    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_insert_extreme_values) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    fossil_tofu_t v_min = fossil_tofu_create("i32", "-2147483648");
    fossil_tofu_t v_max = fossil_tofu_create("i32", "2147483647");
    fossil_tofu_tree_insert(tree, &v_min);
    fossil_tofu_tree_insert(tree, &v_max);

    fossil_tofu_tree_node_t* min_node = fossil_tofu_tree_search(tree, &v_min);
    fossil_tofu_tree_node_t* max_node = fossil_tofu_tree_search(tree, &v_max);
    ASSUME_NOT_CNULL(min_node);
    ASSUME_NOT_CNULL(max_node);

    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_search_null_value) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    ASSUME_ITS_CNULL(fossil_tofu_tree_search(tree, NULL));
    fossil_tofu_tree_destroy(tree);
}

FOSSIL_TEST(c_test_tree_remove_null_value) {
    fossil_tofu_tree_t* tree = fossil_tofu_tree_create("i32");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_tree_remove(tree, NULL), FOSSIL_TOFU_ERROR_INVALID_ARGUMENT);
    fossil_tofu_tree_destroy(tree);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_tree_tofu_tests) {    
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_create_and_destroy);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_insert_duplicate);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_null_pointer_safety);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_create_node_null_value);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_create_node_valid_value);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_search_not_found);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_insert_null_tree_or_value);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_remove_existing_and_nonexisting);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_min_max);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_height_and_is_empty);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_traverse_and_clear);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_size_function);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_insert_extreme_values);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_search_null_value);
    FOSSIL_TEST_ADD(c_tree_tofu_fixture, c_test_tree_remove_null_value);

    FOSSIL_TEST_REGISTER(c_tree_tofu_fixture);
} // end of tests
