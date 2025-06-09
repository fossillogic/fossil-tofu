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

FOSSIL_SUITE(c_vector_tofu_fixture);

FOSSIL_SETUP(c_vector_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_vector_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_vector_create_destroy_i8) {
    fossil_vector_t* vector = fossil_vector_create_container("i8");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_i16) {
    fossil_vector_t* vector = fossil_vector_create_container("i16");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_i32) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_i64) {
    fossil_vector_t* vector = fossil_vector_create_container("i64");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_u8) {
    fossil_vector_t* vector = fossil_vector_create_container("u8");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_u16) {
    fossil_vector_t* vector = fossil_vector_create_container("u16");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_u32) {
    fossil_vector_t* vector = fossil_vector_create_container("u32");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_u64) {
    fossil_vector_t* vector = fossil_vector_create_container("u64");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_hex) {
    fossil_vector_t* vector = fossil_vector_create_container("hex");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_octal) {
    fossil_vector_t* vector = fossil_vector_create_container("octal");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_float) {
    fossil_vector_t* vector = fossil_vector_create_container("float");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_double) {
    fossil_vector_t* vector = fossil_vector_create_container("double");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container("wstr");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container("cstr");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container("cchar");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container("wchar");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_bool) {
    fossil_vector_t* vector = fossil_vector_create_container("bool");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_size) {
    fossil_vector_t* vector = fossil_vector_create_container("size");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_create_destroy_any) {
    fossil_vector_t* vector = fossil_vector_create_container("any");
    ASSUME_ITS_TRUE(vector != NULL);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector) == true);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_i8) {
    fossil_vector_t* vector = fossil_vector_create_container("i8");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_i16) {
    fossil_vector_t* vector = fossil_vector_create_container("i16");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_i32) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_i64) {
    fossil_vector_t* vector = fossil_vector_create_container("i64");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_u8) {
    fossil_vector_t* vector = fossil_vector_create_container("u8");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_u16) {
    fossil_vector_t* vector = fossil_vector_create_container("u16");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_u32) {
    fossil_vector_t* vector = fossil_vector_create_container("u32");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_u64) {
    fossil_vector_t* vector = fossil_vector_create_container("u64");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_hex) {
    fossil_vector_t* vector = fossil_vector_create_container("hex");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_octal) {
    fossil_vector_t* vector = fossil_vector_create_container("octal");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_float) {
    fossil_vector_t* vector = fossil_vector_create_container("float");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_double) {
    fossil_vector_t* vector = fossil_vector_create_container("double");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container("wstr");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container("cstr");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container("cchar");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container("wchar");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_bool) {
    fossil_vector_t* vector = fossil_vector_create_container("bool");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_size) {
    fossil_vector_t* vector = fossil_vector_create_container("size");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_back_any) {
    fossil_vector_t* vector = fossil_vector_create_container("any");
    fossil_vector_push_back(vector, "42");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_i8) {
    fossil_vector_t* vector = fossil_vector_create_container("i8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_i16) {
    fossil_vector_t* vector = fossil_vector_create_container("i16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_i32) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_i64) {
    fossil_vector_t* vector = fossil_vector_create_container("i64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_u8) {
    fossil_vector_t* vector = fossil_vector_create_container("u8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_u16) {
    fossil_vector_t* vector = fossil_vector_create_container("u16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_u32) {
    fossil_vector_t* vector = fossil_vector_create_container("u32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_u64) {
    fossil_vector_t* vector = fossil_vector_create_container("u64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_hex) {
    fossil_vector_t* vector = fossil_vector_create_container("hex");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_octal) {
    fossil_vector_t* vector = fossil_vector_create_container("octal");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_float) {
    fossil_vector_t* vector = fossil_vector_create_container("float");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_double) {
    fossil_vector_t* vector = fossil_vector_create_container("double");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container("wstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container("cstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container("cchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container("wchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_bool) {
    fossil_vector_t* vector = fossil_vector_create_container("bool");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_size) {
    fossil_vector_t* vector = fossil_vector_create_container("size");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_any) {
    fossil_vector_t* vector = fossil_vector_create_container("any");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_front(vector, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_i8) {
    fossil_vector_t* vector = fossil_vector_create_container("i8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_i16) {
    fossil_vector_t* vector = fossil_vector_create_container("i16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_i32) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_i64) {
    fossil_vector_t* vector = fossil_vector_create_container("i64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_u8) {
    fossil_vector_t* vector = fossil_vector_create_container("u8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_u16) {
    fossil_vector_t* vector = fossil_vector_create_container("u16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_u32) {
    fossil_vector_t* vector = fossil_vector_create_container("u32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_u64) {
    fossil_vector_t* vector = fossil_vector_create_container("u64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_hex) {
    fossil_vector_t* vector = fossil_vector_create_container("hex");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_octal) {
    fossil_vector_t* vector = fossil_vector_create_container("octal");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_float) {
    fossil_vector_t* vector = fossil_vector_create_container("float");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_double) {
    fossil_vector_t* vector = fossil_vector_create_container("double");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container("wstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container("cstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container("cchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container("wchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_bool) {
    fossil_vector_t* vector = fossil_vector_create_container("bool");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_size) {
    fossil_vector_t* vector = fossil_vector_create_container("size");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_any) {
    fossil_vector_t* vector = fossil_vector_create_container("any");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "126");
    fossil_vector_push_at(vector, 1, "84");
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_i8) {
    fossil_vector_t* vector = fossil_vector_create_container("i8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_i16) {
    fossil_vector_t* vector = fossil_vector_create_container("i16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_i32) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_i64) {
    fossil_vector_t* vector = fossil_vector_create_container("i64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_u8) {
    fossil_vector_t* vector = fossil_vector_create_container("u8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_u16) {
    fossil_vector_t* vector = fossil_vector_create_container("u16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_u32) {
    fossil_vector_t* vector = fossil_vector_create_container("u32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_u64) {
    fossil_vector_t* vector = fossil_vector_create_container("u64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_hex) {
    fossil_vector_t* vector = fossil_vector_create_container("hex");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_octal) {
    fossil_vector_t* vector = fossil_vector_create_container("octal");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_float) {
    fossil_vector_t* vector = fossil_vector_create_container("float");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_double) {
    fossil_vector_t* vector = fossil_vector_create_container("double");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container("wstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container("cstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container("cchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container("wchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_bool) {
    fossil_vector_t* vector = fossil_vector_create_container("bool");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_size) {
    fossil_vector_t* vector = fossil_vector_create_container("size");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_back_any) {
    fossil_vector_t* vector = fossil_vector_create_container("any");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_i8) {
    fossil_vector_t* vector = fossil_vector_create_container("i8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_i16) {
    fossil_vector_t* vector = fossil_vector_create_container("i16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_i32) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_i64) {
    fossil_vector_t* vector = fossil_vector_create_container("i64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_u8) {
    fossil_vector_t* vector = fossil_vector_create_container("u8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_u16) {
    fossil_vector_t* vector = fossil_vector_create_container("u16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_u32) {
    fossil_vector_t* vector = fossil_vector_create_container("u32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_u64) {
    fossil_vector_t* vector = fossil_vector_create_container("u64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_hex) {
    fossil_vector_t* vector = fossil_vector_create_container("hex");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_octal) {
    fossil_vector_t* vector = fossil_vector_create_container("octal");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_float) {
    fossil_vector_t* vector = fossil_vector_create_container("float");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_double) {
    fossil_vector_t* vector = fossil_vector_create_container("double");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container("wstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container("cstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container("cchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container("wchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_bool) {
    fossil_vector_t* vector = fossil_vector_create_container("bool");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_size) {
    fossil_vector_t* vector = fossil_vector_create_container("size");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_any) {
    fossil_vector_t* vector = fossil_vector_create_container("any");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "84");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_i8) {
    fossil_vector_t* vector = fossil_vector_create_container("i8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_i16) {
    fossil_vector_t* vector = fossil_vector_create_container("i16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_i32) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_i64) {
    fossil_vector_t* vector = fossil_vector_create_container("i64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_u8) {
    fossil_vector_t* vector = fossil_vector_create_container("u8");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_u16) {
    fossil_vector_t* vector = fossil_vector_create_container("u16");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_u32) {
    fossil_vector_t* vector = fossil_vector_create_container("u32");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_u64) {
    fossil_vector_t* vector = fossil_vector_create_container("u64");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_hex) {
    fossil_vector_t* vector = fossil_vector_create_container("hex");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_octal) {
    fossil_vector_t* vector = fossil_vector_create_container("octal");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_float) {
    fossil_vector_t* vector = fossil_vector_create_container("float");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_double) {
    fossil_vector_t* vector = fossil_vector_create_container("double");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_wstr) {
    fossil_vector_t* vector = fossil_vector_create_container("wstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_cstr) {
    fossil_vector_t* vector = fossil_vector_create_container("cstr");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_cchar) {
    fossil_vector_t* vector = fossil_vector_create_container("cchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_wchar) {
    fossil_vector_t* vector = fossil_vector_create_container("wchar");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_bool) {
    fossil_vector_t* vector = fossil_vector_create_container("bool");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_size) {
    fossil_vector_t* vector = fossil_vector_create_container("size");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_any) {
    fossil_vector_t* vector = fossil_vector_create_container("any");
    fossil_vector_push_back(vector, "42");
    fossil_vector_push_back(vector, "84");
    fossil_vector_push_back(vector, "126");
    fossil_vector_pop_at(vector, 1);
    ASSUME_ITS_TRUE(fossil_vector_size(vector) == 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "126");
    fossil_vector_destroy(vector);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_vector_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_i8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_i16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_i32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_i64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_u8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_u16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_u32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_u64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_hex);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_octal);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_float);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_double);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_wstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_cstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_cchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_wchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_bool);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_size);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_back_any);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_i8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_i16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_i32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_i64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_u8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_u16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_u32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_u64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_hex);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_octal);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_float);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_double);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_wstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_cstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_cchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_wchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_bool);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_size);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_any);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_i8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_i16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_i32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_i64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_u8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_u16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_u32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_u64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_hex);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_octal);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_float);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_double);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_wstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_cstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_cchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_wchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_bool);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_size);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back_any);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_i8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_i16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_i32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_i64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_u8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_u16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_u32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_u64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_hex);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_octal);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_float);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_double);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_wstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_cstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_cchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_wchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_bool);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_size);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_any);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_i8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_i16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_i32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_i64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_u8);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_u16);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_u32);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_u64);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_hex);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_octal);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_float);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_double);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_wstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_cstr);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_cchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_wchar);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_bool);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_size);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_any);

    FOSSIL_TEST_REGISTER(c_vector_tofu_fixture);
} // end of tests


