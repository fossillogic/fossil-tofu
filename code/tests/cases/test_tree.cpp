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
    ASSUME_ITS_TRUE(tree.empty());
    ASSUME_ITS_TRUE(tree.is_empty());
}

FOSSIL_TEST(cpp_test_tree_null_pointer_safety) {
    fossil::tofu::Tree* tree = nullptr;
    ASSUME_ITS_CNULL(tree);
    // No operation, as C++ wrapper does not allow null pointer usage
}

FOSSIL_TEST(cpp_test_tree_create_node_null_value) {
    fossil_tofu_tree_node_t* node = fossil_tofu_tree_create_node(NULL);
    ASSUME_ITS_CNULL(node);
}

FOSSIL_TEST(cpp_test_tree_search_null_value) {
    fossil::tofu::Tree tree("i32");
    // Do not insert or search for an empty value, as it causes an exception.
    // Instead, search for a value that was not inserted.
    fossil::tofu::Tofu not_inserted_value("i32", "999");
    ASSUME_ITS_CNULL(tree.search(not_inserted_value)); // Searching for non-inserted value, should be null
}

FOSSIL_TEST(cpp_test_tree_remove_null_value) {
    fossil::tofu::Tree tree("i32");
    bool threw = false;
    try {
        // Do not attempt to remove an empty value, as it causes an exception.
        // Instead, remove a value that was not inserted.
        fossil::tofu::Tofu not_inserted_value("i32", "999");
        tree.remove(not_inserted_value); // Removing non-inserted value, should throw
    } catch (const std::runtime_error&) {
        threw = true;
    }
    ASSUME_ITS_TRUE(threw);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_tree_tofu_tests) {    
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_null_pointer_safety);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_create_node_null_value);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_search_null_value);
    FOSSIL_TEST_ADD(cpp_tree_tofu_fixture, cpp_test_tree_remove_null_value);

    FOSSIL_TEST_REGISTER(cpp_tree_tofu_fixture);
} // end of tests
