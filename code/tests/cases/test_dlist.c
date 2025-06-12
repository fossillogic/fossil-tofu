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

FOSSIL_SUITE(c_dlist_tofu_fixture);

FOSSIL_SETUP(c_dlist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_dlist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_dlist_create_and_destroy) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    ASSUME_NOT_CNULL(dlist);
    ASSUME_ITS_EQUAL_CSTR(dlist->type, "i32");
    ASSUME_ITS_TRUE(fossil_dlist_is_empty(dlist));
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_create_default) {
    fossil_dlist_t* dlist = fossil_dlist_create_default();
    ASSUME_NOT_CNULL(dlist);
    ASSUME_ITS_EQUAL_CSTR(dlist->type, "any");
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_insert_and_size) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    ASSUME_ITS_EQUAL_I32(fossil_dlist_insert(dlist, "10"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_dlist_insert(dlist, "20"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_dlist_insert(dlist, "30"), FOSSIL_TOFU_SUCCESS);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_remove) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    fossil_dlist_insert(dlist, "1");
    fossil_dlist_insert(dlist, "2");
    fossil_dlist_insert(dlist, "3");
    size_t size_before = fossil_dlist_size(dlist);
    ASSUME_ITS_EQUAL_I32(fossil_dlist_remove(dlist), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_SIZE(fossil_dlist_size(dlist), size_before - 2);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_reverse_forward) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    fossil_dlist_insert(dlist, "A");
    fossil_dlist_insert(dlist, "B");
    fossil_dlist_insert(dlist, "C");
    char* front_before = fossil_dlist_get_front(dlist);
    char* back_before = fossil_dlist_get_back(dlist);
    fossil_dlist_reverse_forward(dlist);
    char* front_after = fossil_dlist_get_front(dlist);
    char* back_after = fossil_dlist_get_back(dlist);
    ASSUME_ITS_EQUAL_CSTR(front_before, back_after);
    ASSUME_ITS_EQUAL_CSTR(back_before, front_after);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_reverse_backward) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    fossil_dlist_insert(dlist, "X");
    fossil_dlist_insert(dlist, "Y");
    fossil_dlist_insert(dlist, "Z");
    char* front_before = fossil_dlist_get_front(dlist);
    char* back_before = fossil_dlist_get_back(dlist);
    fossil_dlist_reverse_backward(dlist);
    char* front_after = fossil_dlist_get_front(dlist);
    char* back_after = fossil_dlist_get_back(dlist);
    ASSUME_ITS_EQUAL_CSTR(front_before, back_after);
    ASSUME_ITS_EQUAL_CSTR(back_before, front_after);
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_get_and_set) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    fossil_dlist_insert(dlist, "100");
    fossil_dlist_insert(dlist, "200");
    fossil_dlist_insert(dlist, "300");
    ASSUME_ITS_EQUAL_CSTR(fossil_dlist_get(dlist, 1), "200");
    fossil_dlist_set(dlist, 1, "250");
    ASSUME_ITS_EQUAL_CSTR(fossil_dlist_get(dlist, 1), "250");
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_get_front_and_back) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    fossil_dlist_insert(dlist, "first");
    fossil_dlist_insert(dlist, "middle");
    fossil_dlist_insert(dlist, "last");
    ASSUME_ITS_EQUAL_CSTR(fossil_dlist_get_front(dlist), "first");
    ASSUME_ITS_EQUAL_CSTR(fossil_dlist_get_back(dlist), "last");
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_set_front_and_back) {
    fossil_dlist_t* dlist = fossil_dlist_create_container("i32");
    fossil_dlist_insert(dlist, "one");
    fossil_dlist_insert(dlist, "two");
    fossil_dlist_insert(dlist, "three");
    fossil_dlist_set_front(dlist, "ONE");
    fossil_dlist_set_back(dlist, "THREE");
    ASSUME_ITS_EQUAL_CSTR(fossil_dlist_get_front(dlist), "ONE");
    ASSUME_ITS_EQUAL_CSTR(fossil_dlist_get_back(dlist), "THREE");
    fossil_dlist_destroy(dlist);
}

FOSSIL_TEST(c_test_dlist_copy_and_move) {
    fossil_dlist_t* dlist1 = fossil_dlist_create_container("i32");
    fossil_dlist_insert(dlist1, "5");
    fossil_dlist_insert(dlist1, "10");
    fossil_dlist_insert(dlist1, "15");
    fossil_dlist_t* dlist2 = fossil_dlist_create_copy(dlist1);
    ASSUME_ITS_EQUAL_SIZE(fossil_dlist_size(dlist1), fossil_dlist_size(dlist2));
    ASSUME_ITS_EQUAL_CSTR(fossil_dlist_get(dlist2, 1), "10");
    fossil_dlist_t* dlist3 = fossil_dlist_create_move(dlist1);
    ASSUME_ITS_TRUE(fossil_dlist_is_empty(dlist1));
    ASSUME_ITS_EQUAL_SIZE(fossil_dlist_size(dlist3), 3);
    fossil_dlist_destroy(dlist2);
    fossil_dlist_destroy(dlist3);
    fossil_dlist_destroy(dlist1);
}

FOSSIL_TEST(c_test_dlist_empty_and_null_checks) {
    fossil_dlist_t* dlist = NULL;
    ASSUME_ITS_TRUE(fossil_dlist_is_cnullptr(dlist));
    dlist = fossil_dlist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dlist_not_cnullptr(dlist));
    ASSUME_ITS_TRUE(fossil_dlist_is_empty(dlist));
    fossil_dlist_insert(dlist, "42");
    ASSUME_ITS_TRUE(fossil_dlist_not_empty(dlist));
    fossil_dlist_destroy(dlist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_dlist_tofu_tests) {    
    // dlist ToFu Fixture
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_create_and_destroy);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_create_default);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_insert_and_size);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_remove);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_reverse_forward);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_reverse_backward);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_get_and_set);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_get_front_and_back);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_set_front_and_back);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_copy_and_move);
    FOSSIL_TEST_ADD(c_dlist_tofu_fixture, c_test_dlist_empty_and_null_checks);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_dlist_tofu_fixture);
} // end of tests
