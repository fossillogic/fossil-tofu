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

FOSSIL_SUITE(objc_tuple_tofu_fixture);

FOSSIL_SETUP(objc_tuple_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(objc_tuple_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(objc_test_tuple_create_and_destroy) {
    fossil_tuple_t* tuple = fossil_tuple_create("i32");
    ASSUME_NOT_CNULL(tuple);
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple), 0);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_create_default) {
    fossil_tuple_t* tuple = fossil_tuple_create_default();
    ASSUME_NOT_CNULL(tuple);
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple), 0);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_add_and_get) {
    fossil_tuple_t* tuple = fossil_tuple_create("i32");
    fossil_tuple_add(tuple, "10");
    fossil_tuple_add(tuple, "20");
    fossil_tuple_add(tuple, "30");
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple), 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), "10");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 1), "20");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 2), "30");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_get_front_and_back) {
    fossil_tuple_t* tuple = fossil_tuple_create("i32");
    fossil_tuple_add(tuple, "100");
    fossil_tuple_add(tuple, "200");
    fossil_tuple_add(tuple, "300");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), "100");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), "300");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_set_and_get) {
    fossil_tuple_t* tuple = fossil_tuple_create("i32");
    fossil_tuple_add(tuple, "1");
    fossil_tuple_add(tuple, "2");
    fossil_tuple_add(tuple, "3");
    fossil_tuple_set(tuple, 1, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 1), "42");
    fossil_tuple_set_front(tuple, "99");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), "99");
    fossil_tuple_set_back(tuple, "77");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 2), "77");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_remove) {
    fossil_tuple_t* tuple = fossil_tuple_create("i32");
    fossil_tuple_add(tuple, "a");
    fossil_tuple_add(tuple, "b");
    fossil_tuple_add(tuple, "c");
    fossil_tuple_remove(tuple, 1); // remove "b"
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), "a");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 1), "c");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_clear_and_is_empty) {
    fossil_tuple_t* tuple = fossil_tuple_create("i32");
    fossil_tuple_add(tuple, "x");
    fossil_tuple_add(tuple, "y");
    ASSUME_ITS_FALSE(fossil_tuple_is_empty(tuple));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple));
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple), 0);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_capacity_growth) {
    fossil_tuple_t* tuple = fossil_tuple_create("i32");
    size_t initial_capacity = fossil_tuple_capacity(tuple);
    for (int i = 0; i < (int)initial_capacity + 2; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        fossil_tuple_add(tuple, buf);
    }
    ASSUME_ITS_TRUE(fossil_tuple_capacity(tuple) > initial_capacity);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(objc_test_tuple_copy_constructor) {
    fossil_tuple_t* tuple1 = fossil_tuple_create("i32");
    fossil_tuple_add(tuple1, "1");
    fossil_tuple_add(tuple1, "2");
    fossil_tuple_t* tuple2 = fossil_tuple_create_copy(tuple1);
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple2, 0), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple2, 1), "2");
    fossil_tuple_destroy(tuple1);
    fossil_tuple_destroy(tuple2);
}

FOSSIL_TEST(objc_test_tuple_move_constructor) {
    fossil_tuple_t* tuple1 = fossil_tuple_create("i32");
    fossil_tuple_add(tuple1, "5");
    fossil_tuple_add(tuple1, "6");
    fossil_tuple_t* tuple2 = fossil_tuple_create_move(tuple1);
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple2, 0), "5");
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple2, 1), "6");
    // tuple1 should be empty now
    ASSUME_ITS_EQUAL_I32(fossil_tuple_size(tuple1), 0);
    fossil_tuple_destroy(tuple1);
    fossil_tuple_destroy(tuple2);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(objc_tuple_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_create_and_destroy);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_create_default);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_add_and_get);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_get_front_and_back);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_set_and_get);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_remove);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_clear_and_is_empty);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_capacity_growth);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_copy_constructor);
    FOSSIL_TEST_ADD(objc_tuple_tofu_fixture, objc_test_tuple_move_constructor);

    // Register the test group
    FOSSIL_TEST_REGISTER(objc_tuple_tofu_fixture);
} // end of tests
