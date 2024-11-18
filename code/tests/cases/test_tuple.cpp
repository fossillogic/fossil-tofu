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

FOSSIL_TEST_SUITE(cpp_tuple_tofu_fixture);

FOSSIL_SETUP(cpp_tuple_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_tuple_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_tuple_create_destroy) {
    auto tuple = fossil::tuple_create("i32");
    ASSUME_ITS_TRUE(tuple != NULL);
    ASSUME_ITS_TRUE(fossil::tuple_is_empty(tuple) == true);
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_create_default) {
    auto tuple = fossil::tuple_create_default();
    ASSUME_ITS_TRUE(tuple != NULL);
    ASSUME_ITS_TRUE(fossil::tuple_is_empty(tuple) == true);
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_create_copy) {
    auto original = fossil::tuple_create("i32");
    fossil::tuple_add(original, "42");
    auto copy = fossil::tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil::tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get(copy, 0), std::string("42"));
    fossil::tuple_destroy(original);
    fossil::tuple_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_tuple_create_move) {
    auto original = fossil::tuple_create("i32");
    fossil::tuple_add(original, "42");
    auto moved = fossil::tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil::tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get(moved, 0), std::string("42"));
    ASSUME_ITS_TRUE(fossil::tuple_is_empty(original) == true);
    fossil::tuple_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_tuple_add) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    ASSUME_ITS_TRUE(fossil::tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get(tuple, 0), std::string("42"));
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_remove) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    fossil::tuple_add(tuple, "84");
    fossil::tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil::tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get(tuple, 0), std::string("84"));
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_clear) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    fossil::tuple_add(tuple, "84");
    fossil::tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil::tuple_is_empty(tuple) == true);
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_get_front) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    fossil::tuple_add(tuple, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get_front(tuple), std::string("42"));
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_get_back) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    fossil::tuple_add(tuple, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get_back(tuple), std::string("84"));
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_set) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    fossil::tuple_set(tuple, 0, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get(tuple, 0), std::string("84"));
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_set_front) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    fossil::tuple_add(tuple, "84");
    fossil::tuple_set_front(tuple, "21");
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get_front(tuple), std::string("21"));
    fossil::tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_set_back) {
    auto tuple = fossil::tuple_create("i32");
    fossil::tuple_add(tuple, "42");
    fossil::tuple_add(tuple, "84");
    fossil::tuple_set_back(tuple, "21");
    ASSUME_ITS_EQUAL_CSTR(fossil::tuple_get_back(tuple), std::string("21"));
    fossil::tuple_destroy(tuple);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_tuple_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_default);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back);

    FOSSIL_TEST_REGISTER(cpp_tuple_tofu_fixture);
} // end of tests
