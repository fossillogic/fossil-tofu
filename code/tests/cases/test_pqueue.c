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

FOSSIL_SUITE(c_pqueue_tofu_fixture);

FOSSIL_SETUP(c_pqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_pqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_pqueue_insert_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "2A", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "52", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42.0", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42.0", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "wide_string", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "string", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "c", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "w", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "true", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_insert_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, "42", 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i8");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i16");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i64");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u8");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u16");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u32");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u64");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("hex");
    fossil_pqueue_insert(pqueue, "2A", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("octal");
    fossil_pqueue_insert(pqueue, "52", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("float");
    fossil_pqueue_insert(pqueue, "42.0", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("double");
    fossil_pqueue_insert(pqueue, "42.0", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wstr");
    fossil_pqueue_insert(pqueue, "wide_string", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cstr");
    fossil_pqueue_insert(pqueue, "string", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cchar");
    fossil_pqueue_insert(pqueue, "c", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wchar");
    fossil_pqueue_insert(pqueue, "w", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("bool");
    fossil_pqueue_insert(pqueue, "true", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("size");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_remove_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("any");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i8");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i16");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i64");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u8");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u16");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u32");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u64");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("hex");
    fossil_pqueue_insert(pqueue, "2A", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("octal");
    fossil_pqueue_insert(pqueue, "52", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("float");
    fossil_pqueue_insert(pqueue, "42.0", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("double");
    fossil_pqueue_insert(pqueue, "42.0", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wstr");
    fossil_pqueue_insert(pqueue, "wide_string", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cstr");
    fossil_pqueue_insert(pqueue, "string", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cchar");
    fossil_pqueue_insert(pqueue, "c", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wchar");
    fossil_pqueue_insert(pqueue, "w", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("bool");
    fossil_pqueue_insert(pqueue, "true", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("size");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_empty_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("any");
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_not_cnullptr_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "2A", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "52", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42.0", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42.0", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "wide_string", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "string", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "c", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "w", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "true", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_empty_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, "42", 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(c_test_pqueue_is_cnullptr) {
    fossil_pqueue_t* pqueue = NULL;
    ASSUME_ITS_TRUE(fossil_pqueue_is_cnullptr(pqueue) == true);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_pqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_i8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_i16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_i32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_i64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_u8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_u16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_u32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_u64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_hex);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_octal);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_float);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_double);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_wstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_cstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_cchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_wchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_bool);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_size);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_insert_any);

    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_i8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_i16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_i32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_i64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_u8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_u16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_u32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_u64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_hex);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_octal);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_float);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_double);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_wstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_cstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_cchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_wchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_bool);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_size);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_remove_any);

    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_i8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_i16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_i32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_i64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_u8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_u16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_u32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_u64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_hex);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_octal);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_float);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_double);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_wstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_cstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_cchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_wchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_bool);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_size);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_empty_any);

    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_i8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_i16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_i32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_i64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_u8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_u16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_u32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_u64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_hex);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_octal);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_float);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_double);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_wstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_cstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_cchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_wchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_bool);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_size);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_not_cnullptr_any);

    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_i8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_i16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_i32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_i64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_u8);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_u16);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_u32);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_u64);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_hex);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_octal);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_float);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_double);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_wstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_cstr);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_cchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_wchar);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_bool);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_size);
    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_empty_any);

    FOSSIL_TEST_ADD(c_pqueue_tofu_fixture, c_test_pqueue_is_cnullptr);

    FOSSIL_TEST_REGISTER(c_pqueue_tofu_fixture);
} // end of tests
