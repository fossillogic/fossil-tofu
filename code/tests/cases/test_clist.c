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
#include <fossil/pizza/framework.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_SUITE(c_clist_tofu_fixture);

FOSSIL_SETUP(c_clist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_clist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_clist_insert) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 1);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_remove) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "42");
    ASSUME_ITS_TRUE(fossil_clist_remove(clist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist) == true);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_not_empty) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "42");
    ASSUME_ITS_TRUE(fossil_clist_not_empty(clist) == true);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_not_cnullptr) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_clist_not_cnullptr(clist) == true);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_is_empty) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist) == true);
    fossil_clist_insert(clist, "42");
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist) == false);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_is_cnullptr) {
    fossil_clist_t* clist = NULL;
    ASSUME_ITS_TRUE(fossil_clist_is_cnullptr(clist) == true);
}

FOSSIL_TEST(c_test_clist_reverse) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "1");
    fossil_clist_insert(clist, "2");
    fossil_clist_insert(clist, "3");
    fossil_clist_reverse(clist);

    ASSUME_ITS_EQUAL_I32(fossil_clist_size(clist), 3);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_size) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "1");
    fossil_clist_insert(clist, "2");
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 2);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_insert_multiple) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 3);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST(c_test_clist_remove_multiple) {
    fossil_clist_t* clist = fossil_clist_create_container("i32");
    fossil_clist_insert(clist, "1");
    fossil_clist_insert(clist, "2");
    fossil_clist_insert(clist, "3");
    ASSUME_ITS_TRUE(fossil_clist_remove(clist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_remove(clist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 1);
    fossil_clist_destroy(clist);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_clist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_insert);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_remove);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_not_empty);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_not_cnullptr);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_is_empty);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_is_cnullptr);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_reverse);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_size);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_insert_multiple);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_remove_multiple);

    FOSSIL_TEST_REGISTER(c_clist_tofu_fixture);
} // end of tests
