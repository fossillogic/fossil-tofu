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

FOSSIL_SUITE(cpp_vector_tofu_fixture);

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

FOSSIL_TEST(cpp_test_vector_create_destroy_i8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i8"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_i16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i16"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_i32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_i64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i64"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_u8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u8"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_u16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u16"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_u32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u32"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_u64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u64"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_hex) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("hex"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_octal) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("octal"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_float) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("float"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_double) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("double"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wstr"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cstr"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cchar"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wchar"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_bool) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("bool"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_size) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("size"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_create_destroy_any) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("any"));
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_i8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_i16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_i32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_i64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_u8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_u16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_u32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_u64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_hex) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("hex"));
    fossil_vector_push_back(vector, const_cast<char *>("2A"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "2A");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_octal) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("octal"));
    fossil_vector_push_back(vector, const_cast<char *>("52"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "52");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_float) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("float"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_double) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("double"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wstr"));
    fossil_vector_push_back(vector, const_cast<char *>("wide_string"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "wide_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cstr"));
    fossil_vector_push_back(vector, const_cast<char *>("c_string"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "c_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cchar"));
    fossil_vector_push_back(vector, const_cast<char *>("c"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "c");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wchar"));
    fossil_vector_push_back(vector, const_cast<char *>("w"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "w");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_bool) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("bool"));
    fossil_vector_push_back(vector, const_cast<char *>("true"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "true");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_size) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("size"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_back_any) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("any"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_i8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_i16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_i32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_i64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_u8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_u16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_u32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_u64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_hex) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("hex"));
    fossil_vector_push_back(vector, const_cast<char *>("2A"));
    fossil_vector_push_front(vector, const_cast<char *>("54"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "54");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "2A");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_octal) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("octal"));
    fossil_vector_push_back(vector, const_cast<char *>("52"));
    fossil_vector_push_front(vector, const_cast<char *>("124"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "124");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "52");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_float) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("float"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_front(vector, const_cast<char *>("84.0"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_double) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("double"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_front(vector, const_cast<char *>("84.0"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wstr"));
    fossil_vector_push_back(vector, const_cast<char *>("wide_string"));
    fossil_vector_push_front(vector, const_cast<char *>("another_wide_string"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "another_wide_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "wide_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cstr"));
    fossil_vector_push_back(vector, const_cast<char *>("c_string"));
    fossil_vector_push_front(vector, const_cast<char *>("another_c_string"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "another_c_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "c_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cchar"));
    fossil_vector_push_back(vector, const_cast<char *>("c"));
    fossil_vector_push_front(vector, const_cast<char *>("d"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "d");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "c");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wchar"));
    fossil_vector_push_back(vector, const_cast<char *>("w"));
    fossil_vector_push_front(vector, const_cast<char *>("x"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "x");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "w");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_bool) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("bool"));
    fossil_vector_push_back(vector, const_cast<char *>("true"));
    fossil_vector_push_front(vector, const_cast<char *>("false"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "false");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "true");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_size) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("size"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_front_any) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("any"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_front(vector, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_i8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_i16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_i32) {
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

FOSSIL_TEST(cpp_test_vector_push_at_i64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_u8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_u16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_u32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_u64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_hex) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("hex"));
    fossil_vector_push_back(vector, const_cast<char *>("2A"));
    fossil_vector_push_back(vector, const_cast<char *>("7E"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("54"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "2A");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "54");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "7E");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_octal) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("octal"));
    fossil_vector_push_back(vector, const_cast<char *>("52"));
    fossil_vector_push_back(vector, const_cast<char *>("176"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("124"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "52");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "124");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "176");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_float) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("float"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("126.0"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84.0"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_double) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("double"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("126.0"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84.0"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wstr"));
    fossil_vector_push_back(vector, const_cast<char *>("wide_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_wide_string"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("middle_wide_string"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "wide_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "middle_wide_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "another_wide_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cstr"));
    fossil_vector_push_back(vector, const_cast<char *>("c_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_c_string"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("middle_c_string"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "c_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "middle_c_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "another_c_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cchar"));
    fossil_vector_push_back(vector, const_cast<char *>("a"));
    fossil_vector_push_back(vector, const_cast<char *>("c"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("b"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "a");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "b");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "c");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wchar"));
    fossil_vector_push_back(vector, const_cast<char *>("x"));
    fossil_vector_push_back(vector, const_cast<char *>("z"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("y"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "x");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "y");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "z");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_bool) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("bool"));
    fossil_vector_push_back(vector, const_cast<char *>("true"));
    fossil_vector_push_back(vector, const_cast<char *>("false"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("true"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "true");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "true");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "false");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_size) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("size"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_push_at_any) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("any"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_push_at(vector, 1, const_cast<char *>("84"));
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_i8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_i16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_i32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_i64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_u8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_u16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_u32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_u64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_hex) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("hex"));
    fossil_vector_push_back(vector, const_cast<char *>("2A"));
    fossil_vector_push_back(vector, const_cast<char *>("54"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "2A");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_octal) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("octal"));
    fossil_vector_push_back(vector, const_cast<char *>("52"));
    fossil_vector_push_back(vector, const_cast<char *>("124"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "52");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_float) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("float"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("84.0"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_double) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("double"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("84.0"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wstr"));
    fossil_vector_push_back(vector, const_cast<char *>("wide_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_wide_string"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "wide_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cstr"));
    fossil_vector_push_back(vector, const_cast<char *>("c_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_c_string"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "c_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cchar"));
    fossil_vector_push_back(vector, const_cast<char *>("a"));
    fossil_vector_push_back(vector, const_cast<char *>("b"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "a");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wchar"));
    fossil_vector_push_back(vector, const_cast<char *>("x"));
    fossil_vector_push_back(vector, const_cast<char *>("y"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "x");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_bool) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("bool"));
    fossil_vector_push_back(vector, const_cast<char *>("true"));
    fossil_vector_push_back(vector, const_cast<char *>("false"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "true");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_size) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("size"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_back_any) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("any"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_i8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_i16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_i32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_i64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_u8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_u16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_u32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_u64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_hex) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("hex"));
    fossil_vector_push_back(vector, const_cast<char *>("2A"));
    fossil_vector_push_back(vector, const_cast<char *>("54"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "54");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_octal) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("octal"));
    fossil_vector_push_back(vector, const_cast<char *>("52"));
    fossil_vector_push_back(vector, const_cast<char *>("124"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "124");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_float) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("float"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("84.0"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_double) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("double"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("84.0"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wstr"));
    fossil_vector_push_back(vector, const_cast<char *>("wide_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_wide_string"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "another_wide_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cstr"));
    fossil_vector_push_back(vector, const_cast<char *>("c_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_c_string"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "another_c_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cchar"));
    fossil_vector_push_back(vector, const_cast<char *>("a"));
    fossil_vector_push_back(vector, const_cast<char *>("b"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "b");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wchar"));
    fossil_vector_push_back(vector, const_cast<char *>("x"));
    fossil_vector_push_back(vector, const_cast<char *>("y"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "y");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_bool) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("bool"));
    fossil_vector_push_back(vector, const_cast<char *>("true"));
    fossil_vector_push_back(vector, const_cast<char *>("false"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "false");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_size) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("size"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_front_any) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("any"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_i8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_i16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_i32) {
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

FOSSIL_TEST(cpp_test_vector_pop_at_i64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("i64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_u8) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u8"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_u16) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u16"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_u32) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u32"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_u64) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("u64"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_hex) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("hex"));
    fossil_vector_push_back(vector, const_cast<char *>("2A"));
    fossil_vector_push_back(vector, const_cast<char *>("54"));
    fossil_vector_push_back(vector, const_cast<char *>("7E"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "2A");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "7E");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_octal) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("octal"));
    fossil_vector_push_back(vector, const_cast<char *>("52"));
    fossil_vector_push_back(vector, const_cast<char *>("124"));
    fossil_vector_push_back(vector, const_cast<char *>("176"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "52");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "176");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_float) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("float"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("84.0"));
    fossil_vector_push_back(vector, const_cast<char *>("126.0"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_double) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("double"));
    fossil_vector_push_back(vector, const_cast<char *>("42.0"));
    fossil_vector_push_back(vector, const_cast<char *>("84.0"));
    fossil_vector_push_back(vector, const_cast<char *>("126.0"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126.0");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wstr"));
    fossil_vector_push_back(vector, const_cast<char *>("wide_string"));
    fossil_vector_push_back(vector, const_cast<char *>("middle_wide_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_wide_string"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "wide_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "another_wide_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cstr"));
    fossil_vector_push_back(vector, const_cast<char *>("c_string"));
    fossil_vector_push_back(vector, const_cast<char *>("middle_c_string"));
    fossil_vector_push_back(vector, const_cast<char *>("another_c_string"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "c_string");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "another_c_string");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("cchar"));
    fossil_vector_push_back(vector, const_cast<char *>("a"));
    fossil_vector_push_back(vector, const_cast<char *>("b"));
    fossil_vector_push_back(vector, const_cast<char *>("c"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "a");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "c");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("wchar"));
    fossil_vector_push_back(vector, const_cast<char *>("x"));
    fossil_vector_push_back(vector, const_cast<char *>("y"));
    fossil_vector_push_back(vector, const_cast<char *>("z"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "x");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "z");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_bool) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("bool"));
    fossil_vector_push_back(vector, const_cast<char *>("true"));
    fossil_vector_push_back(vector, const_cast<char *>("false"));
    fossil_vector_push_back(vector, const_cast<char *>("true"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "true");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "true");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_size) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("size"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_pop_at_any) {
    fossil_vector_t* vector = fossil_vector_create_container(const_cast<char *>("any"));
    fossil_vector_push_back(vector, const_cast<char *>("42"));
    fossil_vector_push_back(vector, const_cast<char *>("84"));
    fossil_vector_push_back(vector, const_cast<char *>("126"));
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_i8) {
    fossil::tofu::Vector vector("i8");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_i16) {
    fossil::tofu::Vector vector("i16");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_i32) {
    fossil::tofu::Vector vector("i32");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_i64) {
    fossil::tofu::Vector vector("i64");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_u8) {
    fossil::tofu::Vector vector("u8");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_u16) {
    fossil::tofu::Vector vector("u16");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_u32) {
    fossil::tofu::Vector vector("u32");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_u64) {
    fossil::tofu::Vector vector("u64");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_hex) {
    fossil::tofu::Vector vector("hex");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_octal) {
    fossil::tofu::Vector vector("octal");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_float) {
    fossil::tofu::Vector vector("float");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_double) {
    fossil::tofu::Vector vector("double");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_wstr) {
    fossil::tofu::Vector vector("wstr");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_cstr) {
    fossil::tofu::Vector vector("cstr");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_cchar) {
    fossil::tofu::Vector vector("cchar");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_wchar) {
    fossil::tofu::Vector vector("wchar");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_bool) {
    fossil::tofu::Vector vector("bool");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_size) {
    fossil::tofu::Vector vector("size");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_create_destroy_any) {
    fossil::tofu::Vector vector("any");
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_push_back_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back("42");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back("2A");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "2A");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back("52");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "52");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back("42.0");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back("42.0");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back("wide_string");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "wide_string");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "c_string");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back(const_cast<char *>("c"));
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "c");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back(const_cast<char *>("w"));
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "w");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back(const_cast<char *>("true"));
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "true");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_back_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back(const_cast<char *>("42"));
    vector.push_front(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back(const_cast<char *>("2A"));
    vector.push_front(const_cast<char *>("54"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "54");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "2A");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back(const_cast<char *>("52"));
    vector.push_front(const_cast<char *>("124"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "124");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "52");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back(const_cast<char *>("42.0"));
    vector.push_front(const_cast<char *>("84.0"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42.0");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back(const_cast<char *>("42.0"));
    vector.push_front(const_cast<char *>("84.0"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42.0");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back(const_cast<char *>("wide_string"));
    vector.push_front(const_cast<char *>("another_wide_string"));
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "another_wide_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "wide_string");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    vector.push_front("another_c_string");
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "another_c_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "c_string");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back("c");
    vector.push_front("d");
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "d");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "c");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back("w");
    vector.push_front("x");
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "x");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "w");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back("true");
    vector.push_front("false");
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "false");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "true");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back("42");
    vector.push_front("84");
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_front_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back("42");
    vector.push_front("84");
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "42");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back("2A");
    vector.push_back("7E");
    vector.push_at(1, "54");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "2A");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "54");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "7E");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back("52");
    vector.push_back("176");
    vector.push_at(1, "124");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "52");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "124");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "176");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back("42.0");
    vector.push_back("126.0");
    vector.push_at(1, "84.0");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126.0");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back("42.0");
    vector.push_back("126.0");
    vector.push_at(1, "84.0");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126.0");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back("wide_string");
    vector.push_back("another_wide_string");
    vector.push_at(1, "middle_wide_string");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "wide_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "middle_wide_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "another_wide_string");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    vector.push_back("another_c_string");
    vector.push_at(1, "middle_c_string");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "c_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "middle_c_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "another_c_string");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back("a");
    vector.push_back("c");
    vector.push_at(1, "b");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "a");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "b");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "c");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back("x");
    vector.push_back("z");
    vector.push_at(1, "y");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "x");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "y");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "z");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back("true");
    vector.push_back("false");
    vector.push_at(1, "true");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "true");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "true");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "false");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_push_at_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back("42");
    vector.push_back("126");
    vector.push_at(1, "84");
    ASSUME_ITS_TRUE(vector.size() == 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back("2A");
    vector.push_back("54");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "2A");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back("52");
    vector.push_back("124");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "52");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back("wide_string");
    vector.push_back("another_wide_string");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "wide_string");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    vector.push_back("another_c_string");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "c_string");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back("a");
    vector.push_back("b");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "a");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back("x");
    vector.push_back("y");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "x");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back("true");
    vector.push_back("false");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "true");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_back_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back("2A");
    vector.push_back("54");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "54");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back("52");
    vector.push_back("124");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "124");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84.0");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84.0");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back("wide_string");
    vector.push_back("another_wide_string");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "another_wide_string");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    vector.push_back("another_c_string");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "another_c_string");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back("a");
    vector.push_back("b");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "b");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back("x");
    vector.push_back("y");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "y");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back("true");
    vector.push_back("false");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "false");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_front_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back("42");
    vector.push_back("84");
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back("2A");
    vector.push_back("54");
    vector.push_back("7E");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "2A");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "7E");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back("52");
    vector.push_back("124");
    vector.push_back("176");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "52");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "176");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.push_back("126.0");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126.0");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.push_back("126.0");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126.0");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back("wide_string");
    vector.push_back("middle_wide_string");
    vector.push_back("another_wide_string");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "wide_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "another_wide_string");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    vector.push_back("middle_c_string");
    vector.push_back("another_c_string");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "c_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "another_c_string");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back("a");
    vector.push_back("b");
    vector.push_back("c");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "a");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "c");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back("x");
    vector.push_back("y");
    vector.push_back("z");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "x");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "z");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back("true");
    vector.push_back("false");
    vector.push_back("true");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "true");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "true");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_pop_at_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back("42");
    vector.push_back("84");
    vector.push_back("126");
    vector.pop_at(1);
    ASSUME_ITS_TRUE(vector.size() == 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "42");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1), "126");
}

FOSSIL_TEST(cpp_test_vector_template_erase_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back("2A");
    vector.push_back("54");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back("52");
    vector.push_back("124");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back("42.0");
    vector.push_back("84.0");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back("wide_string");
    vector.push_back("another_wide_string");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    vector.push_back("another_c_string");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back("a");
    vector.push_back("b");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back("x");
    vector.push_back("y");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back("true");
    vector.push_back("false");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_erase_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back("42");
    vector.push_back("84");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_template_set_i8) {
    fossil::tofu::Vector vector("i8");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_i16) {
    fossil::tofu::Vector vector("i16");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_i32) {
    fossil::tofu::Vector vector("i32");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_i64) {
    fossil::tofu::Vector vector("i64");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_u8) {
    fossil::tofu::Vector vector("u8");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_u16) {
    fossil::tofu::Vector vector("u16");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_u32) {
    fossil::tofu::Vector vector("u32");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_u64) {
    fossil::tofu::Vector vector("u64");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_hex) {
    fossil::tofu::Vector vector("hex");
    vector.push_back("2A");
    vector.set(0, "54");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "54");
}

FOSSIL_TEST(cpp_test_vector_template_set_octal) {
    fossil::tofu::Vector vector("octal");
    vector.push_back("52");
    vector.set(0, "124");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "124");
}

FOSSIL_TEST(cpp_test_vector_template_set_float) {
    fossil::tofu::Vector vector("float");
    vector.push_back("42.0");
    vector.set(0, "84.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84.0");
}

FOSSIL_TEST(cpp_test_vector_template_set_double) {
    fossil::tofu::Vector vector("double");
    vector.push_back("42.0");
    vector.set(0, "84.0");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84.0");
}

FOSSIL_TEST(cpp_test_vector_template_set_wstr) {
    fossil::tofu::Vector vector("wstr");
    vector.push_back("wide_string");
    vector.set(0, "new_wide_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "new_wide_string");
}

FOSSIL_TEST(cpp_test_vector_template_set_cstr) {
    fossil::tofu::Vector vector("cstr");
    vector.push_back("c_string");
    vector.set(0, "new_c_string");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "new_c_string");
}

FOSSIL_TEST(cpp_test_vector_template_set_cchar) {
    fossil::tofu::Vector vector("cchar");
    vector.push_back("a");
    vector.set(0, "b");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "b");
}

FOSSIL_TEST(cpp_test_vector_template_set_wchar) {
    fossil::tofu::Vector vector("wchar");
    vector.push_back("x");
    vector.set(0, "y");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "y");
}

FOSSIL_TEST(cpp_test_vector_template_set_bool) {
    fossil::tofu::Vector vector("bool");
    vector.push_back("true");
    vector.set(0, "false");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "false");
}

FOSSIL_TEST(cpp_test_vector_template_set_size) {
    fossil::tofu::Vector vector("size");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

FOSSIL_TEST(cpp_test_vector_template_set_any) {
    fossil::tofu::Vector vector("any");
    vector.push_back("42");
    vector.set(0, "84");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0), "84");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_vector_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_destroy_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_back_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_size);

    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_any);
    
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_create_destroy_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_push_back_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_back_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_front_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_pop_at_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_erase_any);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_i8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_i16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_i32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_i64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_u8);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_u16);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_u32);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_u64);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_hex);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_octal);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_float);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_double);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_wstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_cstr);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_cchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_wchar);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_bool);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_size);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_template_set_any);

    FOSSIL_TEST_REGISTER(cpp_vector_tofu_fixture);
} // end of tests
