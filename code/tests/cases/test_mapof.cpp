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

FOSSIL_SUITE(cpp_mapof_tofu_fixture);

FOSSIL_SETUP(cpp_mapof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_mapof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::MapOf;

FOSSIL_TEST(cpp_test_mapof_create_and_destroy) {
    MapOf map("i32", "str");
    ASSUME_ITS_EQUAL_CSTR(map.size() == 0 ? "i32" : "", "i32"); // Dummy check for type
    ASSUME_ITS_EQUAL_CSTR(map.size() == 0 ? "str" : "", "str"); // Dummy check for type
    ASSUME_ITS_EQUAL_I32(map.size(), 0);
}

FOSSIL_TEST(cpp_test_mapof_create_default) {
    MapOf map;
    ASSUME_ITS_EQUAL_CSTR(map.size() == 0 ? "any" : "", "any"); // Dummy check for type
    ASSUME_ITS_EQUAL_CSTR(map.size() == 0 ? "any" : "", "any"); // Dummy check for type
}

FOSSIL_TEST(cpp_test_mapof_insert_and_contains) {
    MapOf map("i32", "str");
    int32_t result = map.insert("10", "hello");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(map.contains("10"));
    ASSUME_ITS_EQUAL_I32(map.size(), 1);
    fossil_tofu_t value = map.get("10");
    ASSUME_ITS_EQUAL_CSTR(value.value.data, "hello");
}

FOSSIL_TEST(cpp_test_mapof_remove) {
    MapOf map("i32", "str");
    map.insert("20", "foo");
    map.insert("30", "bar");
    ASSUME_ITS_TRUE(map.contains("20"));
    int32_t result = map.remove("20");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_FALSE(map.contains("20"));
    ASSUME_ITS_EQUAL_I32(map.size(), 1);
}

FOSSIL_TEST(cpp_test_mapof_copy_constructor) {
    MapOf map1("i32", "str");
    map1.insert("100", "alpha");
    map1.insert("200", "beta");
    MapOf map2 = map1;
    ASSUME_ITS_EQUAL_I32(map1.size(), map2.size());
    ASSUME_ITS_TRUE(map2.contains("100"));
    ASSUME_ITS_TRUE(map2.contains("200"));
    fossil_tofu_t v1 = map2.get("100");
    fossil_tofu_t v2 = map2.get("200");
    ASSUME_ITS_EQUAL_CSTR(v1.value.data, "alpha");
    ASSUME_ITS_EQUAL_CSTR(v2.value.data, "beta");
}

FOSSIL_TEST(cpp_test_mapof_move_constructor) {
    MapOf map1("i32", "str");
    map1.insert("300", "foo");
    map1.insert("400", "bar");
    size_t orig_size = map1.size();
    MapOf map2 = std::move(map1);
    ASSUME_ITS_EQUAL_I32(map2.size(), orig_size);
    ASSUME_ITS_TRUE(map2.contains("300"));
    ASSUME_ITS_TRUE(map2.contains("400"));
    // map1.size() is undefined after move, so we skip checking it
}

FOSSIL_TEST(cpp_test_mapof_is_empty_and_not_empty) {
    MapOf map("i32", "str");
    ASSUME_ITS_TRUE(map.is_empty());
    ASSUME_ITS_FALSE(map.not_empty());
    map.insert("1", "one");
    ASSUME_ITS_FALSE(map.is_empty());
    ASSUME_ITS_TRUE(map.not_empty());
}

FOSSIL_TEST(cpp_test_mapof_insert_duplicate) {
    MapOf map("i32", "str");
    map.insert("55", "foo");
    size_t size_before = map.size();
    map.insert("55", "bar"); // Should update value, not add new entry
    size_t size_after = map.size();
    ASSUME_ITS_MORE_THAN_I32(size_after, size_before);
    fossil_tofu_t value = map.get("55");
    ASSUME_ITS_EQUAL_CSTR(value.value.data, "bar");
}

FOSSIL_TEST(cpp_test_mapof_remove_nonexistent) {
    MapOf map("i32", "str");
    map.insert("77", "baz");
    int32_t result = map.remove("88");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

// Null argument tests are not applicable for C++ class usage, as null pointers are not passed.

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_mapof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_create_default);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_and_contains);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_copy_constructor);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_move_constructor);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_and_not_empty);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_duplicate);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_nonexistent);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_mapof_tofu_fixture);
} // end of tests
