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

FOSSIL_TEST_SUITE(c_set_tofu_fixture);

FOSSIL_SETUP(c_set_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_set_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_set_insert) {
    fossil_set_t* set = fossil_set_create_container("i32");
    fossil_set_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_set_size(set) == 1);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(c_test_set_erase) {
    fossil_set_t* set = fossil_set_create_container("i32");
    fossil_set_insert(set, "42");
    fossil_set_erase(set);
    ASSUME_ITS_TRUE(fossil_set_is_empty(set) == true);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(c_test_set_not_empty) {
    fossil_set_t* set = fossil_set_create_container("i32");
    fossil_set_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_set_not_empty(set) == true);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(c_test_set_not_cnullptr) {
    fossil_set_t* set = fossil_set_create_container("i32");
    ASSUME_ITS_TRUE(fossil_set_not_cnullptr(set) == true);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(c_test_set_is_cnullptr) {
    fossil_set_t* set = NULL;
    ASSUME_ITS_TRUE(fossil_set_is_cnullptr(set) == true);
}

FOSSIL_TEST_CASE(c_test_set_is_empty) {
    fossil_set_t* set = fossil_set_create_container("i32");
    ASSUME_ITS_TRUE(fossil_set_is_empty(set) == true);
    fossil_set_destroy(set);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_set_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_set_tofu_fixture, c_test_set_insert);
    FOSSIL_TEST_ADD(c_set_tofu_fixture, c_test_set_erase);
    FOSSIL_TEST_ADD(c_set_tofu_fixture, c_test_set_not_empty);
    FOSSIL_TEST_ADD(c_set_tofu_fixture, c_test_set_not_cnullptr);
    FOSSIL_TEST_ADD(c_set_tofu_fixture, c_test_set_is_cnullptr);
    FOSSIL_TEST_ADD(c_set_tofu_fixture, c_test_set_is_empty);

    FOSSIL_TEST_REGISTER(c_set_tofu_fixture);
} // end of tests
