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

FOSSIL_TEST_SUITE(cpp_setof_tofu_fixture);

FOSSIL_SETUP(cpp_setof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_setof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_setof_insert) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "42") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "99") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "42");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "42") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "42");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "42") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_setof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move);

    FOSSIL_TEST_REGISTER(cpp_setof_tofu_fixture);
} // end of tests
