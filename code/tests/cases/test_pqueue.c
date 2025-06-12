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

FOSSIL_SUITE(c_pqueue_tofu_fixture);

FOSSIL_SETUP(c_pqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_pqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_pqueue_create_container_and_destroy) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_NOT_CNULL(pqueue);
    ASSUME_ITS_EQUAL_CSTR(pqueue->type, "i32");
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 0);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_create_default_and_destroy) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_default();
    ASSUME_NOT_CNULL(pqueue);
    ASSUME_ITS_EQUAL_CSTR(pqueue->type, "any");
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_and_remove) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    int32_t result1 = fossil_pqueue_insert(pqueue, "10", 2);
    int32_t result2 = fossil_pqueue_insert(pqueue, "20", 1);
    ASSUME_ITS_EQUAL_I32(result1, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result2, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_front(pqueue), "20"); // highest priority (lowest number)
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_back(pqueue), "10");  // lowest priority (highest number)
    fossil_pqueue_remove(pqueue, 1);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_front(pqueue), "10");
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_create_copy) {
    fossil_pqueue_t* pqueue1 = fossil_pqueue_create_container("i32");
    fossil_pqueue_insert(pqueue1, "1", 1);
    fossil_pqueue_insert(pqueue1, "2", 2);
    fossil_pqueue_t* pqueue2 = fossil_pqueue_create_copy(pqueue1);
    ASSUME_NOT_CNULL(pqueue2);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_front(pqueue2), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_back(pqueue2), "2");
    fossil_pqueue_destroy(pqueue1);
    fossil_pqueue_destroy(pqueue2);
}

FOSSIL_TEST(c_test_pqueue_create_move) {
    fossil_pqueue_t* pqueue1 = fossil_pqueue_create_container("i32");
    fossil_pqueue_insert(pqueue1, "42", 5);
    fossil_pqueue_t* pqueue2 = fossil_pqueue_create_move(pqueue1);
    ASSUME_NOT_CNULL(pqueue2);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue2), 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_front(pqueue2), "42");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue1));
    fossil_pqueue_destroy(pqueue2);
    fossil_pqueue_destroy(pqueue1);
}

FOSSIL_TEST(c_test_pqueue_not_empty_and_is_empty) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue));
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(pqueue));
    fossil_pqueue_insert(pqueue, "1", 1);
    ASSUME_ITS_FALSE(fossil_pqueue_is_empty(pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue));
    fossil_pqueue_remove(pqueue, 1);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue));
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_and_is_cnullptr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue));
    ASSUME_ITS_FALSE(fossil_pqueue_is_cnullptr(pqueue));
    fossil_pqueue_destroy(pqueue);
    pqueue = NULL;
    ASSUME_ITS_FALSE(fossil_pqueue_not_cnullptr(pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_cnullptr(pqueue));
}

FOSSIL_TEST(c_test_pqueue_set_front_and_set_back) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    fossil_pqueue_insert(pqueue, "100", 1);
    fossil_pqueue_insert(pqueue, "200", 2);
    fossil_pqueue_set_front(pqueue, "111");
    fossil_pqueue_set_back(pqueue, "222");
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_front(pqueue), "111");
    ASSUME_ITS_EQUAL_CSTR(fossil_pqueue_get_back(pqueue), "222");
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_get_front_and_get_back_empty) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_ITS_CNULL(fossil_pqueue_get_front(pqueue));
    ASSUME_ITS_CNULL(fossil_pqueue_get_back(pqueue));
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_empty) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    int32_t result = fossil_pqueue_remove(pqueue, 1);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_size_consistency) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 0);
    fossil_pqueue_insert(pqueue, "1", 1);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 1);
    fossil_pqueue_insert(pqueue, "2", 2);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 2);
    fossil_pqueue_remove(pqueue, 1);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 1);
    fossil_pqueue_remove(pqueue, 2);
    ASSUME_ITS_EQUAL_I32(fossil_pqueue_size(pqueue), 0);
    fossil_pqueue_destroy(pqueue);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_pqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_create_container_and_destroy);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_create_default_and_destroy);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_and_remove);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_create_copy);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_create_move);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_set_front_and_set_back);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_get_front_and_get_back_empty);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_empty);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_pqueue_tofu_fixture);
} // end of tests
