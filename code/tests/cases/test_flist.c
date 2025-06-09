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

FOSSIL_SUITE(c_flist_tofu_fixture);

FOSSIL_SETUP(c_flist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_flist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_flist_insert_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "0x2A") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "052") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "3.14") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "3.14159") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "wide_string") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "char_string") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "c") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "w") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_insert_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, "generic_value") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    fossil_flist_insert(flist, "0x2A");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    fossil_flist_insert(flist, "052");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    fossil_flist_insert(flist, "3.14");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    fossil_flist_insert(flist, "3.14159");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    fossil_flist_insert(flist, "wide_string");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    fossil_flist_insert(flist, "char_string");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    fossil_flist_insert(flist, "c");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    fossil_flist_insert(flist, "w");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    fossil_flist_insert(flist, "true");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    fossil_flist_insert(flist, "1024");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_remove_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    fossil_flist_insert(flist, "generic_value");
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_i32) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    fossil_flist_insert(flist, "0x2A");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    fossil_flist_insert(flist, "052");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    fossil_flist_insert(flist, "3.14");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    fossil_flist_insert(flist, "3.14159");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    fossil_flist_insert(flist, "wide_string");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    fossil_flist_insert(flist, "char_string");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    fossil_flist_insert(flist, "c");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    fossil_flist_insert(flist, "w");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    fossil_flist_insert(flist, "true");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    fossil_flist_insert(flist, "1024");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_empty_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    fossil_flist_insert(flist, "generic_value");
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_i32) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_not_cnullptr_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "0x2A");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "052");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "3.14");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "3.14159");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "wide_string");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "char_string");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "c");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "w");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "true");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "1024");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_empty_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, "generic_value");
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_is_cnullptr) {
    fossil_flist_t* flist = NULL;
    ASSUME_ITS_TRUE(fossil_flist_is_cnullptr(flist) == true);
}

FOSSIL_TEST(c_test_flist_reverse_forward_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_i32) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    fossil_flist_insert(flist, "0x1");
    fossil_flist_insert(flist, "0x2");
    fossil_flist_insert(flist, "0x3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    fossil_flist_insert(flist, "01");
    fossil_flist_insert(flist, "02");
    fossil_flist_insert(flist, "03");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    fossil_flist_insert(flist, "1.1");
    fossil_flist_insert(flist, "2.2");
    fossil_flist_insert(flist, "3.3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    fossil_flist_insert(flist, "1.11");
    fossil_flist_insert(flist, "2.22");
    fossil_flist_insert(flist, "3.33");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    fossil_flist_insert(flist, "wide1");
    fossil_flist_insert(flist, "wide2");
    fossil_flist_insert(flist, "wide3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    fossil_flist_insert(flist, "char1");
    fossil_flist_insert(flist, "char2");
    fossil_flist_insert(flist, "char3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    fossil_flist_insert(flist, "a");
    fossil_flist_insert(flist, "b");
    fossil_flist_insert(flist, "c");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    fossil_flist_insert(flist, "wa");
    fossil_flist_insert(flist, "wb");
    fossil_flist_insert(flist, "wc");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    fossil_flist_insert(flist, "true");
    fossil_flist_insert(flist, "false");
    fossil_flist_insert(flist, "true");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    fossil_flist_insert(flist, "1024");
    fossil_flist_insert(flist, "2048");
    fossil_flist_insert(flist, "4096");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_forward_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    fossil_flist_insert(flist, "value1");
    fossil_flist_insert(flist, "value2");
    fossil_flist_insert(flist, "value3");
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_i32) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    fossil_flist_insert(flist, "0x1");
    fossil_flist_insert(flist, "0x2");
    fossil_flist_insert(flist, "0x3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    fossil_flist_insert(flist, "01");
    fossil_flist_insert(flist, "02");
    fossil_flist_insert(flist, "03");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    fossil_flist_insert(flist, "1.1");
    fossil_flist_insert(flist, "2.2");
    fossil_flist_insert(flist, "3.3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    fossil_flist_insert(flist, "1.11");
    fossil_flist_insert(flist, "2.22");
    fossil_flist_insert(flist, "3.33");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    fossil_flist_insert(flist, "wide1");
    fossil_flist_insert(flist, "wide2");
    fossil_flist_insert(flist, "wide3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    fossil_flist_insert(flist, "char1");
    fossil_flist_insert(flist, "char2");
    fossil_flist_insert(flist, "char3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    fossil_flist_insert(flist, "a");
    fossil_flist_insert(flist, "b");
    fossil_flist_insert(flist, "c");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    fossil_flist_insert(flist, "wa");
    fossil_flist_insert(flist, "wb");
    fossil_flist_insert(flist, "wc");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    fossil_flist_insert(flist, "true");
    fossil_flist_insert(flist, "false");
    fossil_flist_insert(flist, "true");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    fossil_flist_insert(flist, "1024");
    fossil_flist_insert(flist, "2048");
    fossil_flist_insert(flist, "4096");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_reverse_backward_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    fossil_flist_insert(flist, "value1");
    fossil_flist_insert(flist, "value2");
    fossil_flist_insert(flist, "value3");
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_i32) {
    fossil_flist_t* flist = fossil_flist_create_container("i32");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "42");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "0x2A");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "052");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "3.14");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "3.14159");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "wide_string");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "char_string");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "c");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "w");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "true");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "1024");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_size_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, "generic_value");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    fossil_flist_insert(flist, "0x1");
    fossil_flist_insert(flist, "0x2");
    fossil_flist_insert(flist, "0x3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    fossil_flist_insert(flist, "01");
    fossil_flist_insert(flist, "02");
    fossil_flist_insert(flist, "03");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    fossil_flist_insert(flist, "1.1");
    fossil_flist_insert(flist, "2.2");
    fossil_flist_insert(flist, "3.3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    fossil_flist_insert(flist, "1.11");
    fossil_flist_insert(flist, "2.22");
    fossil_flist_insert(flist, "3.33");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    fossil_flist_insert(flist, "wide1");
    fossil_flist_insert(flist, "wide2");
    fossil_flist_insert(flist, "wide3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    fossil_flist_insert(flist, "char1");
    fossil_flist_insert(flist, "char2");
    fossil_flist_insert(flist, "char3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    fossil_flist_insert(flist, "a");
    fossil_flist_insert(flist, "b");
    fossil_flist_insert(flist, "c");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    fossil_flist_insert(flist, "wa");
    fossil_flist_insert(flist, "wb");
    fossil_flist_insert(flist, "wc");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    fossil_flist_insert(flist, "true");
    fossil_flist_insert(flist, "false");
    fossil_flist_insert(flist, "true");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    fossil_flist_insert(flist, "1024");
    fossil_flist_insert(flist, "2048");
    fossil_flist_insert(flist, "4096");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_inserts_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    fossil_flist_insert(flist, "value1");
    fossil_flist_insert(flist, "value2");
    fossil_flist_insert(flist, "value3");
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_i8) {
    fossil_flist_t* flist = fossil_flist_create_container("i8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_i16) {
    fossil_flist_t* flist = fossil_flist_create_container("i16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_i64) {
    fossil_flist_t* flist = fossil_flist_create_container("i64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_u8) {
    fossil_flist_t* flist = fossil_flist_create_container("u8");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_u16) {
    fossil_flist_t* flist = fossil_flist_create_container("u16");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_u32) {
    fossil_flist_t* flist = fossil_flist_create_container("u32");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_u64) {
    fossil_flist_t* flist = fossil_flist_create_container("u64");
    fossil_flist_insert(flist, "1");
    fossil_flist_insert(flist, "2");
    fossil_flist_insert(flist, "3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_hex) {
    fossil_flist_t* flist = fossil_flist_create_container("hex");
    fossil_flist_insert(flist, "0x1");
    fossil_flist_insert(flist, "0x2");
    fossil_flist_insert(flist, "0x3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_octal) {
    fossil_flist_t* flist = fossil_flist_create_container("octal");
    fossil_flist_insert(flist, "01");
    fossil_flist_insert(flist, "02");
    fossil_flist_insert(flist, "03");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_float) {
    fossil_flist_t* flist = fossil_flist_create_container("float");
    fossil_flist_insert(flist, "1.1");
    fossil_flist_insert(flist, "2.2");
    fossil_flist_insert(flist, "3.3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_double) {
    fossil_flist_t* flist = fossil_flist_create_container("double");
    fossil_flist_insert(flist, "1.11");
    fossil_flist_insert(flist, "2.22");
    fossil_flist_insert(flist, "3.33");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container("wstr");
    fossil_flist_insert(flist, "wide1");
    fossil_flist_insert(flist, "wide2");
    fossil_flist_insert(flist, "wide3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container("cstr");
    fossil_flist_insert(flist, "char1");
    fossil_flist_insert(flist, "char2");
    fossil_flist_insert(flist, "char3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container("cchar");
    fossil_flist_insert(flist, "a");
    fossil_flist_insert(flist, "b");
    fossil_flist_insert(flist, "c");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container("wchar");
    fossil_flist_insert(flist, "wa");
    fossil_flist_insert(flist, "wb");
    fossil_flist_insert(flist, "wc");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_bool) {
    fossil_flist_t* flist = fossil_flist_create_container("bool");
    fossil_flist_insert(flist, "true");
    fossil_flist_insert(flist, "false");
    fossil_flist_insert(flist, "true");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_size) {
    fossil_flist_t* flist = fossil_flist_create_container("size");
    fossil_flist_insert(flist, "1024");
    fossil_flist_insert(flist, "2048");
    fossil_flist_insert(flist, "4096");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST(c_test_flist_multiple_removes_any) {
    fossil_flist_t* flist = fossil_flist_create_container("any");
    fossil_flist_insert(flist, "value1");
    fossil_flist_insert(flist, "value2");
    fossil_flist_insert(flist, "value3");
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_flist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_insert_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_remove_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_i32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_empty_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_i32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_not_cnullptr_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_empty_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_is_cnullptr);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_i32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_forward_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_i32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_reverse_backward_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_i32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_size_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_inserts_any);

    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_i8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_i16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_i64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_u8);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_u16);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_u32);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_u64);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_hex);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_octal);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_float);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_double);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_wstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_cstr);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_cchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_wchar);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_bool);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_size);
    FOSSIL_TEST_ADD(c_flist_tofu_fixture, c_test_flist_multiple_removes_any);

    FOSSIL_TEST_REGISTER(c_flist_tofu_fixture);
} // end of tests
