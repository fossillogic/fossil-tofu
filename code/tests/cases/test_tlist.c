/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/test/framework.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_SUITE(c_tlist_tofu_fixture);

FOSSIL_SETUP(c_tlist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_tlist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_tlist_insert) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_tlist_insert(tlist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tlist_size(tlist) == 1);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_remove) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "42");
    ASSUME_ITS_TRUE(fossil_tlist_remove(tlist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tlist_is_empty(tlist) == true);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_not_empty) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "42");
    ASSUME_ITS_TRUE(fossil_tlist_not_empty(tlist) == true);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_not_cnullptr) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_tlist_not_cnullptr(tlist) == true);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_is_empty) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_tlist_is_empty(tlist) == true);
    fossil_tlist_insert(tlist, "42");
    ASSUME_ITS_TRUE(fossil_tlist_is_empty(tlist) == false);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_is_cnullptr) {
    fossil_tlist_t* tlist = NULL;
    ASSUME_ITS_TRUE(fossil_tlist_is_cnullptr(tlist) == true);
}

FOSSIL_TEST_CASE(c_test_tlist_reverse_forward) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    fossil_tlist_insert(tlist, "3");
    fossil_tlist_reverse_forward(tlist);

    ASSUME_ITS_EQUAL_I32(fossil_tlist_size(tlist), 3);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_reverse_backward) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    fossil_tlist_insert(tlist, "3");
    fossil_tlist_reverse_backward(tlist);

    ASSUME_ITS_EQUAL_I32(fossil_tlist_size(tlist), 3);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_size) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    ASSUME_ITS_TRUE(fossil_tlist_size(tlist) == 2);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_insert_multiple) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_tlist_insert(tlist, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tlist_insert(tlist, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tlist_insert(tlist, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tlist_size(tlist) == 3);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_remove_multiple) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    fossil_tlist_insert(tlist, "3");
    ASSUME_ITS_TRUE(fossil_tlist_remove(tlist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tlist_remove(tlist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tlist_size(tlist) == 1);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_get) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    ASSUME_ITS_TRUE(strcmp(fossil_tlist_get(tlist, 1), "2") == 0);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_get_front) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    ASSUME_ITS_TRUE(strcmp(fossil_tlist_get_front(tlist), "1") == 0);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_get_back) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    ASSUME_ITS_TRUE(strcmp(fossil_tlist_get_back(tlist), "2") == 0);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_set) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    fossil_tlist_set(tlist, 1, "42");
    ASSUME_ITS_TRUE(strcmp(fossil_tlist_get(tlist, 1), "42") == 0);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_set_front) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    fossil_tlist_set_front(tlist, "42");
    ASSUME_ITS_TRUE(strcmp(fossil_tlist_get_front(tlist), "42") == 0);
    fossil_tlist_destroy(tlist);
}

FOSSIL_TEST_CASE(c_test_tlist_set_back) {
    fossil_tlist_t* tlist = fossil_tlist_create_container("i32");
    fossil_tlist_insert(tlist, "1");
    fossil_tlist_insert(tlist, "2");
    fossil_tlist_set_back(tlist, "42");
    ASSUME_ITS_TRUE(strcmp(fossil_tlist_get_back(tlist), "42") == 0);
    fossil_tlist_destroy(tlist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_tlist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_insert);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_remove);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_not_empty);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_not_cnullptr);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_is_empty);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_is_cnullptr);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_reverse_forward);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_reverse_backward);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_size);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_insert_multiple);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_remove_multiple);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_get);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_get_front);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_get_back);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_set);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_set_front);
    FOSSIL_TEST_ADD(c_tlist_tofu_fixture, c_test_tlist_set_back);

    FOSSIL_TEST_REGISTER(c_tlist_tofu_fixture);
} // end of tests
