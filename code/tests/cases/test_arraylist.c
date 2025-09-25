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

FOSSIL_SUITE(c_arraylist_tofu_fixture);

FOSSIL_SETUP(c_arraylist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_arraylist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_arraylist_create_and_destroy) {
    fossil_tofu_arraylist_t* alist = fossil_tofu_arraylist_create_container("i32", 8);
    ASSUME_NOT_CNULL(alist);
    ASSUME_ITS_EQUAL_CSTR(alist->type, "i32");
    ASSUME_ITS_TRUE(fossil_tofu_arraylist_is_empty(alist));
    fossil_tofu_arraylist_destroy(alist);
}

FOSSIL_TEST(c_test_arraylist_create_default) {
    fossil_tofu_arraylist_t* alist = fossil_tofu_arraylist_create_default();
    ASSUME_NOT_CNULL(alist);
    ASSUME_ITS_EQUAL_CSTR(alist->type, "any");
    fossil_tofu_arraylist_destroy(alist);
}

FOSSIL_TEST(c_test_arraylist_insert_and_size) {
    fossil_tofu_arraylist_t* alist = fossil_tofu_arraylist_create_container("i32", 4);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_arraylist_insert(alist, "10"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_arraylist_insert(alist, "20"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_arraylist_insert(alist, "30"), FOSSIL_TOFU_SUCCESS);
    fossil_tofu_arraylist_destroy(alist);
}

FOSSIL_TEST(c_test_arraylist_remove) {
    fossil_tofu_arraylist_t* alist = fossil_tofu_arraylist_create_container("i32", 4);
    fossil_tofu_arraylist_insert(alist, "1");
    fossil_tofu_arraylist_insert(alist, "2");
    fossil_tofu_arraylist_insert(alist, "3");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_arraylist_remove(alist, 1), FOSSIL_TOFU_SUCCESS);
    fossil_tofu_arraylist_destroy(alist);
}

FOSSIL_TEST(c_test_arraylist_get_and_set) {
    fossil_tofu_arraylist_t* alist = fossil_tofu_arraylist_create_container("i32", 4);
    fossil_tofu_arraylist_insert(alist, "100");
    fossil_tofu_arraylist_insert(alist, "200");
    fossil_tofu_arraylist_insert(alist, "300");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_arraylist_get(alist, 1), "200");
    fossil_tofu_arraylist_set(alist, 1, "250");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_arraylist_get(alist, 1), "250");
    fossil_tofu_arraylist_destroy(alist);
}

FOSSIL_TEST(c_test_arraylist_get_front_and_back) {
    fossil_tofu_arraylist_t* alist = fossil_tofu_arraylist_create_container("i32", 4);
    fossil_tofu_arraylist_insert(alist, "first");
    fossil_tofu_arraylist_insert(alist, "middle");
    fossil_tofu_arraylist_insert(alist, "last");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_arraylist_get_front(alist), "first");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_arraylist_get_back(alist), "last");
    fossil_tofu_arraylist_destroy(alist);
}

FOSSIL_TEST(c_test_arraylist_set_front_and_back) {
    fossil_tofu_arraylist_t* alist = fossil_tofu_arraylist_create_container("i32", 4);
    fossil_tofu_arraylist_insert(alist, "one");
    fossil_tofu_arraylist_insert(alist, "two");
    fossil_tofu_arraylist_insert(alist, "three");
    fossil_tofu_arraylist_set_front(alist, "ONE");
    fossil_tofu_arraylist_set_back(alist, "THREE");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_arraylist_get_front(alist), "ONE");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_arraylist_get_back(alist), "THREE");
    fossil_tofu_arraylist_destroy(alist);
}

FOSSIL_TEST(c_test_arraylist_copy_and_move) {
    fossil_tofu_arraylist_t* alist1 = fossil_tofu_arraylist_create_container("i32", 4);
    fossil_tofu_arraylist_insert(alist1, "5");
    fossil_tofu_arraylist_insert(alist1, "10");
    fossil_tofu_arraylist_insert(alist1, "15");
    fossil_tofu_arraylist_t* alist2 = fossil_tofu_arraylist_create_copy(alist1);
    ASSUME_ITS_EQUAL_SIZE(fossil_tofu_arraylist_size(alist1), fossil_tofu_arraylist_size(alist2));
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_arraylist_get(alist2, 1), "10");
    fossil_tofu_arraylist_t* alist3 = fossil_tofu_arraylist_create_move(alist1);
    ASSUME_ITS_TRUE(fossil_tofu_arraylist_is_empty(alist1));
    ASSUME_ITS_EQUAL_SIZE(fossil_tofu_arraylist_size(alist3), 3);
    fossil_tofu_arraylist_destroy(alist2);
    fossil_tofu_arraylist_destroy(alist3);
    fossil_tofu_arraylist_destroy(alist1);
}

FOSSIL_TEST(c_test_arraylist_empty_and_null_checks) {
    fossil_tofu_arraylist_t* alist = NULL;
    ASSUME_ITS_TRUE(fossil_tofu_arraylist_is_cnullptr(alist));
    alist = fossil_tofu_arraylist_create_container("i32", 4);
    ASSUME_ITS_TRUE(fossil_tofu_arraylist_not_cnullptr(alist));
    ASSUME_ITS_TRUE(fossil_tofu_arraylist_is_empty(alist));
    fossil_tofu_arraylist_insert(alist, "42");
    ASSUME_ITS_TRUE(fossil_tofu_arraylist_not_empty(alist));
    fossil_tofu_arraylist_destroy(alist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_arraylist_tofu_tests) {    
    // arraylist ToFu Fixture
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_create_and_destroy);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_create_default);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_insert_and_size);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_remove);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_get_and_set);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_get_front_and_back);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_set_front_and_back);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_copy_and_move);
    FOSSIL_TEST_ADD(c_arraylist_tofu_fixture, c_test_arraylist_empty_and_null_checks);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_arraylist_tofu_fixture);
} // end of tests
