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

FOSSIL_SUITE(objc_clist_tofu_fixture);

FOSSIL_SETUP(objc_clist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(objc_clist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(objc_test_clist_create_and_destroy) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    ASSUME_NOT_CNULL(clist);
    ASSUME_ITS_EQUAL_CSTR(clist->type, "i32");
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist));
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_create_default) {
    fossil_clist_t* clist = fossil_clist_create_default();
    ASSUME_NOT_CNULL(clist);
    ASSUME_ITS_EQUAL_CSTR(clist->type, "any");
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_insert_and_size) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    ASSUME_ITS_EQUAL_I32(fossil_clist_insert(clist, "10"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_clist_insert(clist, "20"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_clist_insert(clist, "30"), FOSSIL_TOFU_SUCCESS);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_remove) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "1");
    fossil_clist_insert(clist, "2");
    fossil_clist_insert(clist, "3");
    size_t size_before = fossil_clist_size(clist);
    ASSUME_ITS_EQUAL_I32(fossil_clist_remove(clist), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_SIZE(fossil_clist_size(clist), size_before - 2);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_reverse) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "A");
    fossil_clist_insert(clist, "B");
    fossil_clist_insert(clist, "C");
    char* front_before = fossil_clist_get_front(clist);
    char* back_before = fossil_clist_get_back(clist);
    fossil_clist_reverse(clist);
    char* front_after = fossil_clist_get_front(clist);
    char* back_after = fossil_clist_get_back(clist);
    ASSUME_NOT_EQUAL_CSTR(front_before, back_after);
    ASSUME_NOT_EQUAL_CSTR(front_after, back_before);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_get_and_set) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "100");
    fossil_clist_insert(clist, "200");
    fossil_clist_insert(clist, "300");
    ASSUME_ITS_EQUAL_CSTR(fossil_clist_get(clist, 1), "200");
    fossil_clist_set(clist, 1, "250");
    ASSUME_ITS_EQUAL_CSTR(fossil_clist_get(clist, 1), "250");
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_get_front_and_back) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "first");
    fossil_clist_insert(clist, "middle");
    fossil_clist_insert(clist, "last");
    ASSUME_ITS_EQUAL_CSTR(fossil_clist_get_front(clist), "first");
    ASSUME_ITS_EQUAL_CSTR(fossil_clist_get_back(clist), "last");
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_set_front_and_back) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "one");
    fossil_clist_insert(clist, "two");
    fossil_clist_insert(clist, "three");
    fossil_clist_set_front(clist, "ONE");
    fossil_clist_set_back(clist, "THREE");
    ASSUME_ITS_EQUAL_CSTR(fossil_clist_get_front(clist), "ONE");
    ASSUME_ITS_EQUAL_CSTR(fossil_clist_get_back(clist), "THREE");
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(objc_test_clist_copy_and_move) {
    fossil_clist_t* clist1 = fossil_clist_create_container("i32");
    fossil_clist_insert(clist1, "5");
    fossil_clist_insert(clist1, "10");
    fossil_clist_insert(clist1, "15");
    fossil_clist_t* clist2 = fossil_clist_create_copy(clist1);
    ASSUME_ITS_EQUAL_SIZE(fossil_clist_size(clist1), fossil_clist_size(clist2));
    ASSUME_ITS_EQUAL_CSTR(fossil_clist_get(clist2, 1), "10");
    fossil_clist_t* clist3 = fossil_clist_create_move(clist1);
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist1));
    ASSUME_ITS_EQUAL_SIZE(fossil_clist_size(clist3), 3);
    fossil_clist_destroy(clist2);
    fossil_clist_destroy(clist3);
    fossil_clist_destroy(clist1);
}

FOSSIL_TEST(objc_test_clist_empty_and_null_checks) {
    fossil_clist_t* clist = NULL;
    ASSUME_ITS_TRUE(fossil_clist_is_cnullptr(clist));
    clist = fossil_clist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_clist_not_cnullptr(clist));
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist));
    fossil_clist_insert(clist, "42");
    ASSUME_ITS_TRUE(fossil_clist_not_empty(clist));
    fossil_clist_destroy(clist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(objc_clist_tofu_tests) {    
    // clist ToFu Fixture
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_create_and_destroy);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_create_default);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_insert_and_size);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_remove);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_reverse);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_get_and_set);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_get_front_and_back);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_set_front_and_back);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_copy_and_move);
    FOSSIL_TEST_ADD(objc_clist_tofu_fixture, objc_test_clist_empty_and_null_checks);

    // Register the test group
    FOSSIL_TEST_REGISTER(objc_clist_tofu_fixture);
} // end of tests
