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

FOSSIL_TEST_SUITE(cpp_pqueue_tofu_fixture);

FOSSIL_SETUP(cpp_pqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_pqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_pqueue_insert) {
    auto pqueue = fossil::pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::pqueue_size(pqueue) == 1);
    fossil::pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_remove) {
    auto pqueue = fossil::pqueue_create_container("i32");
    fossil::pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil::pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::pqueue_is_empty(pqueue) == true);
    fossil::pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_not_empty) {
    auto pqueue = fossil::pqueue_create_container("i32");
    fossil::pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil::pqueue_not_empty(pqueue) == true);
    fossil::pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_not_cnullptr) {
    auto pqueue = fossil::pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::pqueue_not_cnullptr(pqueue) == true);
    fossil::pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_is_empty) {
    auto pqueue = fossil::pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil::pqueue_is_empty(pqueue) == true);
    fossil::pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil::pqueue_is_empty(pqueue) == false);
    fossil::pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_is_cnullptr) {
    auto pqueue = nullptr;
    ASSUME_ITS_TRUE(fossil::pqueue_is_cnullptr(pqueue) == true);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_pqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty);

    FOSSIL_TEST_REGISTER(cpp_pqueue_tofu_fixture);
} // end of tests
