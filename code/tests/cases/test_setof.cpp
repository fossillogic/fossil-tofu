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
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_SUITE(cpp_setof_tofu_fixture);

FOSSIL_SETUP(cpp_setof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_setof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::SetOf;

FOSSIL_TEST(cpp_test_setof_create_and_destroy) {
    SetOf set("i32");
    ASSUME_ITS_EQUAL_I32(set.size(), 0);
}

FOSSIL_TEST(cpp_test_setof_insert_and_contains) {
    SetOf set("i32");
    set.insert("10");
    ASSUME_ITS_TRUE(set.contains("10"));
    ASSUME_ITS_EQUAL_I32(set.size(), 1);
}

FOSSIL_TEST(cpp_test_setof_remove) {
    SetOf set("i32");
    set.insert("20");
    set.insert("30");
    ASSUME_ITS_TRUE(set.contains("20"));
    set.remove("20");
    ASSUME_ITS_FALSE(set.contains("20"));
    ASSUME_ITS_EQUAL_I32(set.size(), 1);
}

FOSSIL_TEST(cpp_test_setof_is_empty_and_not_empty) {
    SetOf set("i32");
    ASSUME_ITS_TRUE(set.is_empty());
    ASSUME_ITS_FALSE(set.not_empty());
    set.insert("1");
    ASSUME_ITS_FALSE(set.is_empty());
    ASSUME_ITS_TRUE(set.not_empty());
}

FOSSIL_TEST(cpp_test_setof_insert_duplicate) {
    SetOf set("i32");
    set.insert("55");
    size_t size_before = set.size();
    set.insert("55"); // Should allow duplicate, as per current implementation
    size_t size_after = set.size();
    ASSUME_ITS_EQUAL_I32(size_after, size_before + 1);
}

FOSSIL_TEST(cpp_test_setof_remove_nonexistent) {
    SetOf set("i32");
    set.insert("77");
    try {
        set.remove("88");
        ASSUME_ITS_FALSE(true); // Should not reach here
    } catch (const std::runtime_error&) {
        ASSUME_ITS_TRUE(true); // Exception expected
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_setof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_and_contains);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_and_not_empty);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_duplicate);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_nonexistent);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_setof_tofu_fixture);
} // end of tests
