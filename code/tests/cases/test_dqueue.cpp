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

FOSSIL_TEST_SUITE(cpp_dqueue_tofu_fixture);

FOSSIL_SETUP(cpp_dqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_dqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_dqueue_insert) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::dqueue_size(queue) == 1);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_remove) {
    auto queue = fossil::dqueue_create_container("i32");
    fossil::dqueue_insert(queue, "42");
    ASSUME_ITS_TRUE(fossil::dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::dqueue_is_empty(queue) == true);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_not_empty) {
    auto queue = fossil::dqueue_create_container("i32");
    fossil::dqueue_insert(queue, "42");
    ASSUME_ITS_TRUE(fossil::dqueue_not_empty(queue) == true);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_not_cnullptr) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_not_cnullptr(queue) == true);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_is_empty) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_is_empty(queue) == true);
    fossil::dqueue_insert(queue, "42");
    ASSUME_ITS_TRUE(fossil::dqueue_is_empty(queue) == false);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_is_cnullptr) {
    auto queue = nullptr;
    ASSUME_ITS_TRUE(fossil::dqueue_is_cnullptr(queue) == true);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_multiple_insert) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::dqueue_size(queue) == 2);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_insert_remove) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::dqueue_size(queue) == 1);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_insert_null) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_insert(queue, nullptr) == FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_TRUE(fossil::dqueue_size(queue) == 0);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_remove_empty) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_remove(queue) == FOSSIL_TOFU_FAILURE);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_size_empty) {
    auto queue = fossil::dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::dqueue_size(queue) == 0);
    fossil::dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_size_after_operations) {
    auto queue = fossil::dqueue_create_container("i32");
    fossil::dqueue_insert(queue, "42");
    fossil::dqueue_insert(queue, "43");
    fossil::dqueue_remove(queue);
    ASSUME_ITS_TRUE(fossil::dqueue_size(queue) == 1);
    fossil::dqueue_destroy(queue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_dqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_insert);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_remove);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_not_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_is_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_multiple_insert);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_insert_remove);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_insert_null);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_remove_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_size_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_size_after_operations);

    FOSSIL_TEST_REGISTER(cpp_dqueue_tofu_fixture);
} // end of tests
