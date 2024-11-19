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

FOSSIL_TEST_SUITE(cpp_dlist_tofu_fixture);

FOSSIL_SETUP(cpp_dlist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_dlist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_dlist_insert) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_dlist_insert(dlist, const_cast<char *>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dlist_size(dlist) == 1);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_remove) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    fossil_dlist_insert(dlist, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_dlist_remove(dlist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dlist_is_empty(dlist) == true);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_not_empty) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    fossil_dlist_insert(dlist, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_dlist_not_empty(dlist) == true);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_not_cnullptr) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_dlist_not_cnullptr(dlist) == true);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_is_empty) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_dlist_is_empty(dlist) == true);
    fossil_dlist_insert(dlist, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_dlist_is_empty(dlist) == false);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_is_cnullptr) {
    fossil_dlist_t* dlist = nullptr;
    ASSUME_ITS_TRUE(fossil_dlist_is_cnullptr(dlist) == true);
}

FOSSIL_TEST_CASE(cpp_test_dlist_reverse_forward) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    fossil_dlist_insert(dlist, const_cast<char *>("1"));
    fossil_dlist_insert(dlist, const_cast<char *>("2"));
    fossil_dlist_insert(dlist, const_cast<char *>("3"));
    fossil_dlist_reverse_forward(dlist);

    ASSUME_ITS_EQUAL_I32(fossil_dlist_size(dlist), 3);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_reverse_backward) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    fossil_dlist_insert(dlist, const_cast<char *>("1"));
    fossil_dlist_insert(dlist, const_cast<char *>("2"));
    fossil_dlist_insert(dlist, const_cast<char *>("3"));
    fossil_dlist_reverse_backward(dlist);

    ASSUME_ITS_EQUAL_I32(fossil_dlist_size(dlist), 3);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_size) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    fossil_dlist_insert(dlist, const_cast<char *>("1"));
    fossil_dlist_insert(dlist, const_cast<char *>("2"));
    ASSUME_ITS_TRUE(fossil_dlist_size(dlist) == 2);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_insert_multiple) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_dlist_insert(dlist, const_cast<char *>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dlist_insert(dlist, const_cast<char *>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dlist_insert(dlist, const_cast<char *>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dlist_size(dlist) == 3);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST_CASE(cpp_test_dlist_remove_multiple) {
    fossil_dlist_t* dlist = fossil_dlist_create_container(const_cast<char *>("i32"));
    fossil_dlist_insert(dlist, const_cast<char *>("1"));
    fossil_dlist_insert(dlist, const_cast<char *>("2"));
    fossil_dlist_insert(dlist, const_cast<char *>("3"));
    ASSUME_ITS_TRUE(fossil_dlist_remove(dlist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dlist_remove(dlist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dlist_size(dlist) == 1);
    fossil_dlist_destroy(dlist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_dlist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_insert);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_remove);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_not_empty);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_is_empty);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_reverse_forward);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_reverse_backward);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_size);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_insert_multiple);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_remove_multiple);

    FOSSIL_TEST_REGISTER(cpp_dlist_tofu_fixture);
} // end of tests
