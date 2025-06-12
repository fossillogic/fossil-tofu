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

FOSSIL_SUITE(c_setof_tofu_fixture);

FOSSIL_SETUP(c_setof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_setof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_setof_create_and_destroy) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_NOT_CNULL(set);
    ASSUME_ITS_EQUAL_CSTR(set->type, "i32");
    ASSUME_ITS_EQUAL_I32(fossil_setof_size(set), 0);
    fossil_setof_destroy(set);
}

FOSSIL_TEST(c_test_setof_create_default) {
    fossil_setof_t* set = fossil_setof_create_default();
    ASSUME_NOT_CNULL(set);
    ASSUME_ITS_EQUAL_CSTR(set->type, "any");
    fossil_setof_destroy(set);
}

FOSSIL_TEST(c_test_setof_insert_and_contains) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    int32_t result = fossil_setof_insert(set, "10");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "10"));
    ASSUME_ITS_EQUAL_I32(fossil_setof_size(set), 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST(c_test_setof_remove) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "20");
    fossil_setof_insert(set, "30");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "20"));
    int32_t result = fossil_setof_remove(set, "20");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_FALSE(fossil_setof_contains(set, "20"));
    ASSUME_ITS_EQUAL_I32(fossil_setof_size(set), 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST(c_test_setof_copy_constructor) {
    fossil_setof_t* set1 = fossil_setof_create_container("i32");
    fossil_setof_insert(set1, "100");
    fossil_setof_insert(set1, "200");
    fossil_setof_t* set2 = fossil_setof_create_copy(set1);
    ASSUME_ITS_EQUAL_I32(fossil_setof_size(set1), fossil_setof_size(set2));
    ASSUME_ITS_TRUE(fossil_setof_contains(set2, "100"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set2, "200"));
    fossil_setof_destroy(set1);
    fossil_setof_destroy(set2);
}

FOSSIL_TEST(c_test_setof_move_constructor) {
    fossil_setof_t* set1 = fossil_setof_create_container("i32");
    fossil_setof_insert(set1, "300");
    fossil_setof_insert(set1, "400");
    size_t orig_size = fossil_setof_size(set1);
    fossil_setof_t* set2 = fossil_setof_create_move(set1);
    ASSUME_ITS_EQUAL_I32(fossil_setof_size(set2), orig_size);
    ASSUME_ITS_TRUE(fossil_setof_contains(set2, "300"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set2, "400"));
    ASSUME_ITS_EQUAL_I32(fossil_setof_size(set1), 0);
    fossil_setof_destroy(set1);
    fossil_setof_destroy(set2);
}

FOSSIL_TEST(c_test_setof_is_empty_and_not_empty) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set));
    ASSUME_ITS_FALSE(fossil_setof_not_empty(set));
    fossil_setof_insert(set, "1");
    ASSUME_ITS_FALSE(fossil_setof_is_empty(set));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set));
    fossil_setof_destroy(set);
}

FOSSIL_TEST(c_test_setof_insert_duplicate) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "55");
    size_t size_before = fossil_setof_size(set);
    fossil_setof_insert(set, "55"); // Should allow duplicate, as per current implementation
    size_t size_after = fossil_setof_size(set);
    ASSUME_ITS_EQUAL_I32(size_after, size_before + 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST(c_test_setof_remove_nonexistent) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "77");
    int32_t result = fossil_setof_remove(set, "88");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
    fossil_setof_destroy(set);
}

FOSSIL_TEST(c_test_setof_null_args) {
    ASSUME_ITS_EQUAL_I32(fossil_setof_insert(NULL, "1"), FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_EQUAL_I32(fossil_setof_insert((fossil_setof_t*)1, NULL), FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_EQUAL_I32(fossil_setof_remove(NULL, "1"), FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_EQUAL_I32(fossil_setof_remove((fossil_setof_t*)1, NULL), FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_FALSE(fossil_setof_contains(NULL, "1"));
    ASSUME_ITS_FALSE(fossil_setof_contains((fossil_setof_t*)1, NULL));
    ASSUME_ITS_EQUAL_I32(fossil_setof_size(NULL), 0);
    ASSUME_ITS_FALSE(fossil_setof_not_empty(NULL));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(NULL));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_setof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_and_destroy);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_default);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_and_contains);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_copy_constructor);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_move_constructor);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_and_not_empty);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_duplicate);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_nonexistent);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_null_args);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_setof_tofu_fixture);
} // end of tests
