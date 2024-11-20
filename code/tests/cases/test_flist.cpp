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

FOSSIL_TEST_CASE(cpp_test_flist_template_insert) {
    fossil::ForwardList<int> flist;
    flist.insert(42);
    ASSUME_ITS_TRUE(flist.size() == 1);
    ASSUME_ITS_TRUE(flist.front() == 42);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_remove) {
    fossil::ForwardList<int> flist;
    flist.insert(42);
    flist.remove();
    ASSUME_ITS_TRUE(flist.isEmpty() == true);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_reverse) {
    fossil::ForwardList<int> flist;
    flist.insert(1);
    flist.insert(2);
    flist.insert(3);
    flist.reverse();
    ASSUME_ITS_TRUE(flist.size() == 3);
    ASSUME_ITS_TRUE(flist.front() == 1);
    ASSUME_ITS_TRUE(flist.back() == 3);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_size) {
    fossil::ForwardList<int> flist;
    ASSUME_ITS_TRUE(flist.size() == 0);
    flist.insert(42);
    ASSUME_ITS_TRUE(flist.size() == 1);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_is_empty) {
    fossil::ForwardList<int> flist;
    ASSUME_ITS_TRUE(flist.isEmpty() == true);
    flist.insert(42);
    ASSUME_ITS_TRUE(flist.isEmpty() == false);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_get) {
    fossil::ForwardList<int> flist;
    flist.insert(1);
    flist.insert(2);
    flist.insert(3);
    ASSUME_ITS_TRUE(flist.get(0) == 3);
    ASSUME_ITS_TRUE(flist.get(1) == 2);
    ASSUME_ITS_TRUE(flist.get(2) == 1);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_front) {
    fossil::ForwardList<int> flist;
    flist.insert(42);
    ASSUME_ITS_TRUE(flist.front() == 42);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_back) {
    fossil::ForwardList<int> flist;
    flist.insert(1);
    flist.insert(2);
    flist.insert(3);
    ASSUME_ITS_TRUE(flist.back() == 1);
}

FOSSIL_TEST_CASE(cpp_test_flist_template_clear) {
    fossil::ForwardList<int> flist;
    flist.insert(42);
    flist.clear();
    ASSUME_ITS_TRUE(flist.isEmpty() == true);
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

    // Template class tests
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_insert);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_remove);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_reverse);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_is_empty);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_get);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_front);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_back);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_template_clear);

    FOSSIL_TEST_REGISTER(cpp_flist_tofu_fixture);
} // end of tests
