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
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST_CASE(cpp_test_vector_push_back) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST_CASE(cpp_test_vector_push_front) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST_CASE(cpp_test_vector_push_at) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST_CASE(cpp_test_vector_pop_back) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST_CASE(cpp_test_vector_pop_front) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST_CASE(cpp_test_vector_pop_at) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST_CASE(cpp_test_vector_template_create_destroy) {
    fossil::tofu::Vector vector;
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_vector_template_push_back) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST_CASE(cpp_test_vector_template_push_front) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST_CASE(cpp_test_vector_template_push_at) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    vector.push_back(const_cast<char *>("126"));
    vector.push_at(1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST_CASE(cpp_test_vector_template_pop_back) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    vector.push_back(const_cast<char *>("84"));
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST_CASE(cpp_test_vector_template_pop_front) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    vector.push_back(const_cast<char *>("84"));
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST_CASE(cpp_test_vector_template_pop_at) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    vector.push_back(const_cast<char *>("84"));
    vector.push_back(const_cast<char *>("126"));
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST_CASE(cpp_test_vector_template_erase) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    vector.push_back(const_cast<char *>("84"));
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_vector_template_set) {
    fossil::tofu::Vector vector;
    vector.push_back(const_cast<char *>("42"));
    vector.set(0, const_cast<char *>("84"));
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
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
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_front);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_at);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set);

    FOSSIL_TEST_REGISTER(cpp_vector_tofu_fixture);
} // end of tests
