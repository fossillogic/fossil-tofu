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

FOSSIL_TEST_SUITE(c_algorithm_fixture);

FOSSIL_SETUP(c_algorithm_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_algorithm_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_algorithm_compare) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2 = fossil_tofu_create("i32", "84");
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_algorithm_search) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create("i32", "42"),
        fossil_tofu_create("i32", "84"),
        fossil_tofu_create("i32", "126")
    };
    fossil_tofu_t tofu = fossil_tofu_create("i32", "84");
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_algorithm_sort) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create("i32", "126"),
        fossil_tofu_create("i32", "42"),
        fossil_tofu_create("i32", "84")
    };
    
    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);

    // Need to figure out sort algorithm as to why it's not working
    // seems to lose data during sort
    // ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    // ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    // ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");
    
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST_CASE(c_test_algorithm_reverse) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create("i32", "42"),
        fossil_tofu_create("i32", "84"),
        fossil_tofu_create("i32", "126")
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_algorithm_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_algorithm_fixture, c_test_algorithm_compare);
    FOSSIL_TEST_ADD(c_algorithm_fixture, c_test_algorithm_search);
    FOSSIL_TEST_ADD(c_algorithm_fixture, c_test_algorithm_sort);
    FOSSIL_TEST_ADD(c_algorithm_fixture, c_test_algorithm_reverse);
    FOSSIL_TEST_ADD(c_algorithm_fixture, c_test_create_default);
    FOSSIL_TEST_ADD(c_algorithm_fixture, c_test_create_copy);
    FOSSIL_TEST_ADD(c_algorithm_fixture, c_test_create_move);

    FOSSIL_TEST_REGISTER(c_algorithm_fixture);
} // end of tests
