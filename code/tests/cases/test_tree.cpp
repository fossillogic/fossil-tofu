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
FOSSIL_SUITE(cpp_tree_tofu_fixture);

FOSSIL_SETUP(cpp_tree_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_tree_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_test_tree_create_and_destroy) {
    fossil::tofu::Tree tree("i32");
    ASSUME_ITS_EQUAL_I32(tree.size(), 0);
}

FOSSIL_TEST(cpp_test_tree_insert_and_search) {
    fossil::tofu::Tree tree("i32");
    fossil::tofu::Tofu v10("i32", "10");
    fossil::tofu::Tofu v20("i32", "20");
    fossil::tofu::Tofu v30("i32", "30");
    tree.insert(v10);
    tree.insert(v20);
    tree.insert(v30);
    fossil_tree_node_t* found = tree.search(v20);
    ASSUME_NOT_CNULL(found);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_compare(found->value, &v20.get_c_struct()), 0);
}

FOSSIL_TEST(cpp_test_tree_insert_duplicate) {
    fossil::tofu::Tree tree("i32");
    fossil::tofu::Tofu v10("i32", "10");
    tree.insert(v10);
    fossil::tofu::Tofu v10_dup("i32", "10");
    try {
        tree.insert(v10_dup);
        ASSUME_ITS_FALSE("Expected exception for duplicate insert");
    } catch (const std::runtime_error&) {
        ASSUME_ITS_TRUE(true);
    }
}

FOSSIL_TEST(cpp_test_tree_null_pointer_safety) {
    fossil::tofu::Tree* tree = nullptr;
    ASSUME_ITS_CNULL(tree);
    // No operation, as C++ wrapper does not allow null pointer usage
}

FOSSIL_TEST(cpp_test_tree_create_node_null_value) {
    fossil_tree_node_t* node = fossil_tree_create_node(NULL);
    ASSUME_ITS_CNULL(node);
}

FOSSIL_TEST(cpp_test_tree_search_not_found) {
    fossil::tofu::Tree tree("i32");
    fossil::tofu::Tofu v10("i32", "10");
    tree.insert(v10);
    fossil::tofu::Tofu v30("i32", "30");
    fossil_tree_node_t* found = tree.search(v30);
    ASSUME_ITS_CNULL(found);
}

FOSSIL_TEST(cpp_test_tree_insert_null_tree_or_value) {
    fossil::tofu::Tofu v10("i32", "10");
    try {
        fossil::tofu::Tree* tree = nullptr;
        tree->insert(v10);
        ASSUME_ITS_FALSE("Expected exception for null tree");
    } catch (...) {
        ASSUME_ITS_TRUE(true);
    }
    try {
        fossil::tofu::Tree tree("i32");
        tree.insert(*(static_cast<fossil::tofu::Tofu*>(nullptr)));
        ASSUME_ITS_FALSE("Expected exception for null value");
    } catch (...) {
        ASSUME_ITS_TRUE(true);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_tree_tofu_tests) {    
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_insert_and_search);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_insert_duplicate);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_null_pointer_safety);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_create_node_null_value);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_search_not_found);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_insert_null_tree_or_value);

    FOSSIL_TEST_REGISTER(cpp_tree_tofu_fixture);
} // end of tests
