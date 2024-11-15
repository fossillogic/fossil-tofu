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

using namespace fossil;

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_SUITE(cpp_vector_tofu_fixture);

FOSSIL_SETUP(cpp_vector_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_vector_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_CASE(cpp_test_vector_create_destroy) {
    fossil_vector_t* vect = fossil::vector_create_container("i32");
    ASSUME_ITS_TRUE(vect != NULL);
    ASSUME_ITS_TRUE(fossil::vector_is_empty(vect) == true);
    fossil::vector_destroy(vect);
}

FOSSIL_TEST_CASE(cpp_test_vector_push_back) {
    fossil_vector_t* vect = fossil::vector_create_container("i32");
    fossil::vector_push_back(vect, "42");
    ASSUME_ITS_TRUE(fossil::vector_size(vect) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 0).c_str(), "42");
    fossil::vector_destroy(vect);
}

FOSSIL_TEST_CASE(cpp_test_vector_push_front) {
    fossil_vector_t* vect = fossil::vector_create_container("i32");
    fossil::vector_push_back(vect, "42");
    fossil::vector_push_front(vect, "84");
    ASSUME_ITS_TRUE(fossil::vector_size(vect) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 0).c_str(), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 1).c_str(), "42");
    fossil::vector_destroy(vect);
}

FOSSIL_TEST_CASE(cpp_test_vector_push_at) {
    fossil_vector_t* vect = fossil::vector_create_container("i32");
    fossil::vector_push_back(vect, "42");
    fossil::vector_push_back(vect, "126");
    fossil::vector_push_at(vect, 1, "84");
    ASSUME_ITS_TRUE(fossil::vector_size(vect) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 0).c_str(), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 1).c_str(), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 2).c_str(), "126");
    fossil::vector_destroy(vect);
}

FOSSIL_TEST_CASE(cpp_test_vector_pop_back) {
    fossil_vector_t* vect = fossil::vector_create_container("i32");
    fossil::vector_push_back(vect, "42");
    fossil::vector_push_back(vect, "84");
    fossil::vector_pop_back(vect);
    ASSUME_ITS_TRUE(fossil::vector_size(vect) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 0).c_str(), "42");
    fossil::vector_destroy(vect);
}

FOSSIL_TEST_CASE(cpp_test_vector_pop_front) {
    fossil_vector_t* vect = fossil::vector_create_container("i32");
    fossil::vector_push_back(vect, "42");
    fossil::vector_push_back(vect, "84");
    fossil::vector_pop_front(vect);
    ASSUME_ITS_TRUE(fossil::vector_size(vect) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 0).c_str(), "84");
    fossil::vector_destroy(vect);
}

FOSSIL_TEST_CASE(cpp_test_vector_pop_at) {
    fossil_vector_t* vect = fossil::vector_create_container("i32");
    fossil::vector_push_back(vect, "42");
    fossil::vector_push_back(vect, "84");
    fossil::vector_push_back(vect, "126");
    fossil::vector_pop_at(vect, 1);
    ASSUME_ITS_TRUE(fossil::vector_size(vect) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 0).c_str(), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil::vector_get(vect, 1).c_str(), "126");
    fossil::vector_destroy(vect);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_vector_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_front);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_at);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at);

    FOSSIL_TEST_REGISTER(cpp_vector_tofu_fixture);
} // end of tests
