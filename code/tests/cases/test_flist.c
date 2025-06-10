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

FOSSIL_SUITE(c_flist_tofu_fixture);

FOSSIL_SETUP(c_flist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_flist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_flist_create_and_destroy) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    ASSUME_NOT_CNULL(flist);
    ASSUME_ITS_EQUAL_CSTR(flist->type, "i32");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist));
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_create_default) {
    fossil_flist_t* flist = fossil_flist_create_default();
    ASSUME_NOT_CNULL(flist);
    ASSUME_ITS_EQUAL_CSTR(flist->type, "any");
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_and_size) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    ASSUME_ITS_EQUAL_I32(fossil_flist_insert(flist, "10"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_flist_insert(flist, "20"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_flist_insert(flist, "30"), FOSSIL_TOFU_SUCCESS);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    size_t size_before = fossil_flist_size(flist);
    ASSUME_ITS_EQUAL_I32(fossil_flist_remove(flist), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_SIZE(fossil_flist_size(flist), size_before - 2);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "A");
    fossil_flist_insert(flist, "B");
    fossil_flist_insert(flist, "C");
    char* front_before = fossil_flist_get_front(flist);
    char* back_before = fossil_flist_get_back(flist);
    fossil_flist_reverse_forward(flist);
    char* front_after = fossil_flist_get_front(flist);
    char* back_after = fossil_flist_get_back(flist);
    ASSUME_NOT_EQUAL_CSTR(front_before, front_after);
    ASSUME_NOT_EQUAL_CSTR(back_before, back_after);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "X");
    fossil_flist_insert(flist, "Y");
    fossil_flist_insert(flist, "Z");
    char* front_before = fossil_flist_get_front(flist);
    char* back_before = fossil_flist_get_back(flist);
    fossil_flist_reverse_backward(flist);
    char* front_after = fossil_flist_get_front(flist);
    char* back_after = fossil_flist_get_back(flist);
    ASSUME_NOT_EQUAL_CSTR(front_before, front_after);
    ASSUME_NOT_EQUAL_CSTR(back_before, back_after);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_get_and_set) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "100");
    fossil_flist_insert(flist, "200");
    fossil_flist_insert(flist, "300");
    ASSUME_ITS_EQUAL_CSTR(fossil_flist_get(flist, 1), "200");
    fossil_flist_set(flist, 1, "250");
    ASSUME_ITS_EQUAL_CSTR(fossil_flist_get(flist, 1), "250");
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_get_front_and_back) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "first");
    fossil_flist_insert(flist, "middle");
    fossil_flist_insert(flist, "last");
    ASSUME_ITS_EQUAL_CSTR(fossil_flist_get_front(flist), "first");
    ASSUME_ITS_EQUAL_CSTR(fossil_flist_get_back(flist), "last");
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_set_front_and_back) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "one");
    fossil_flist_insert(flist, "two");
    fossil_flist_insert(flist, "three");
    fossil_flist_set_front(flist, "ONE");
    fossil_flist_set_back(flist, "THREE");
    ASSUME_ITS_EQUAL_CSTR(fossil_flist_get_front(flist), "ONE");
    ASSUME_ITS_EQUAL_CSTR(fossil_flist_get_back(flist), "THREE");
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_copy_and_move) {
    fossil_flist_t* flist1 = fossil_flist_create_container("i32");
    fossil_flist_insert(flist1, "5");
    fossil_flist_insert(flist1, "10");
    fossil_flist_insert(flist1, "15");
    fossil_flist_t* flist2 = fossil_flist_create_copy(flist1);
    ASSUME_ITS_EQUAL_SIZE(fossil_flist_size(flist1), fossil_flist_size(flist2));
    ASSUME_ITS_EQUAL_CSTR(fossil_flist_get(flist2, 1), "10");
    fossil_flist_t* flist3 = fossil_flist_create_move(flist1);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist1));
    fossil_flist_destroy(flist2);
    fossil_flist_destroy(flist3);
    fossil_flist_destroy(flist1);
}

FOSSIL_TEST(c_test_flist_empty_and_null_checks) {
    fossil_flist_t* flist = NULL;
    ASSUME_ITS_TRUE(fossil_flist_is_cnullptr(flist));
    flist = fossil_flist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist));
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist));
    fossil_flist_destroy(flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_flist_tofu_tests) {    
    // flist ToFu Fixture
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_create_and_destroy);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_create_default);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_and_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_get_and_set);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_get_front_and_back);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_set_front_and_back);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_copy_and_move);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_empty_and_null_checks);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_flist_tofu_fixture);
} // end of tests
