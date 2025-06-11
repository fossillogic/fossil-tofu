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

FOSSIL_SUITE(c_dqueue_tofu_fixture);

FOSSIL_SETUP(c_dqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_dqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_dqueue_create_container_and_destroy) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    ASSUME_NOT_CNULL(dqueue);
    ASSUME_ITS_EQUAL_CSTR(dqueue->type, "i32");
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 0);
    fossil_dqueue_destroy(dqueue);
}

FOSSIL_TEST(c_test_dqueue_create_default_and_destroy) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_default();
    ASSUME_NOT_CNULL(dqueue);
    ASSUME_ITS_EQUAL_CSTR(dqueue->type, "any");
    fossil_dqueue_destroy(dqueue);
}

FOSSIL_TEST(c_test_dqueue_insert_and_remove) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    int32_t result1 = fossil_dqueue_insert(dqueue, "10");
    int32_t result2 = fossil_dqueue_insert(dqueue, "20");
    ASSUME_ITS_EQUAL_I32(result1, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result2, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_front(dqueue), "10");
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_back(dqueue), "20");
    fossil_dqueue_remove(dqueue);
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_front(dqueue), "20");
    fossil_dqueue_destroy(dqueue);
}

FOSSIL_TEST(c_test_dqueue_create_copy) {
    fossil_dqueue_t* dqueue1 = fossil_dqueue_create_container("i32");
    fossil_dqueue_insert(dqueue1, "1");
    fossil_dqueue_insert(dqueue1, "2");
    fossil_dqueue_t* dqueue2 = fossil_dqueue_create_copy(dqueue1);
    ASSUME_NOT_CNULL(dqueue2);
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_front(dqueue2), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_back(dqueue2), "2");
    fossil_dqueue_destroy(dqueue1);
    fossil_dqueue_destroy(dqueue2);
}

FOSSIL_TEST(c_test_dqueue_create_move) {
    fossil_dqueue_t* dqueue1 = fossil_dqueue_create_container("i32");
    fossil_dqueue_insert(dqueue1, "42");
    fossil_dqueue_t* dqueue2 = fossil_dqueue_create_move(dqueue1);
    ASSUME_NOT_CNULL(dqueue2);
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue2), 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_front(dqueue2), "42");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(dqueue1)); // dqueue1 should be empty after move
    fossil_dqueue_destroy(dqueue1);
    fossil_dqueue_destroy(dqueue2);
}

FOSSIL_TEST(c_test_dqueue_not_empty_and_is_empty) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(dqueue));
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(dqueue));
    fossil_dqueue_insert(dqueue, "1");
    ASSUME_ITS_FALSE(fossil_dqueue_is_empty(dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(dqueue));
    fossil_dqueue_remove(dqueue);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(dqueue));
    fossil_dqueue_destroy(dqueue);
}

FOSSIL_TEST(c_test_dqueue_not_cnullptr_and_is_cnullptr) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(dqueue));
    ASSUME_ITS_FALSE(fossil_dqueue_is_cnullptr(dqueue));
    fossil_dqueue_destroy(dqueue);
    dqueue = NULL;
    ASSUME_ITS_FALSE(fossil_dqueue_not_cnullptr(dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_cnullptr(dqueue));
}

FOSSIL_TEST(c_test_dqueue_set_front_and_set_back) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    fossil_dqueue_insert(dqueue, "100");
    fossil_dqueue_insert(dqueue, "200");
    fossil_dqueue_set_front(dqueue, "111");
    fossil_dqueue_set_back(dqueue, "222");
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_front(dqueue), "111");
    ASSUME_ITS_EQUAL_CSTR(fossil_dqueue_get_back(dqueue), "222");
    fossil_dqueue_destroy(dqueue);
}

FOSSIL_TEST(c_test_dqueue_get_front_and_get_back_empty) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_CNULL(fossil_dqueue_get_front(dqueue));
    ASSUME_ITS_CNULL(fossil_dqueue_get_back(dqueue));
    fossil_dqueue_destroy(dqueue);
}

FOSSIL_TEST(c_test_dqueue_remove_empty) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    int32_t result = fossil_dqueue_remove(dqueue);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
    fossil_dqueue_destroy(dqueue);
}

FOSSIL_TEST(c_test_dqueue_size_consistency) {
    fossil_dqueue_t* dqueue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 0);
    fossil_dqueue_insert(dqueue, "1");
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 1);
    fossil_dqueue_insert(dqueue, "2");
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 2);
    fossil_dqueue_remove(dqueue);
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 1);
    fossil_dqueue_remove(dqueue);
    ASSUME_ITS_EQUAL_I32(fossil_dqueue_size(dqueue), 0);
    fossil_dqueue_destroy(dqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_dqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_create_container_and_destroy);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_create_default_and_destroy);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_and_remove);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_create_copy);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_create_move);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_set_front_and_set_back);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_get_front_and_get_back_empty);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_empty);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_dqueue_tofu_fixture);
} // end of tests
