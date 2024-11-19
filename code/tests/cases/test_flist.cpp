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

FOSSIL_TEST_SUITE(cpp_flist_tofu_fixture);

FOSSIL_SETUP(cpp_flist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_flist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_flist_insert) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char *>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    fossil_flist_insert(flist, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    fossil_flist_insert(flist, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_cnullptr) {
    fossil_flist_t* flist = nullptr;
    ASSUME_ITS_TRUE(fossil_flist_is_cnullptr(flist) == true);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    fossil_flist_insert(flist, const_cast<char *>("1"));
    fossil_flist_insert(flist, const_cast<char *>("2"));
    fossil_flist_insert(flist, const_cast<char *>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);

    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    fossil_flist_insert(flist, const_cast<char *>("1"));
    fossil_flist_insert(flist, const_cast<char *>("2"));
    fossil_flist_insert(flist, const_cast<char *>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);

    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    fossil_flist_insert(flist, const_cast<char *>("1"));
    fossil_flist_insert(flist, const_cast<char *>("2"));
    fossil_flist_insert(flist, const_cast<char *>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char *>("i32"));
    fossil_flist_insert(flist, const_cast<char *>("1"));
    fossil_flist_insert(flist, const_cast<char *>("2"));
    fossil_flist_insert(flist, const_cast<char *>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_flist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes);

    FOSSIL_TEST_REGISTER(cpp_flist_tofu_fixture);
} // end of tests
