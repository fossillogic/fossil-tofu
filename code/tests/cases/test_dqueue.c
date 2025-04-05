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

FOSSIL_TEST_SUITE(c_dqueue_tofu_fixture);

FOSSIL_SETUP(c_dqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_dqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_dqueue_insert_i8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "127") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_i16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "32767") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_i32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2147483647") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_i64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "9223372036854775807") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_u8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "255") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_u16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "65535") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_u32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "4294967295") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_u64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "18446744073709551615") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_hex) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "0x1A3F") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_octal) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "0755") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_float) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "3.14") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_double) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2.718281828459") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_wstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L\"wide string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_cstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "\"c string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_cchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "'c'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_wchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L'W'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_bool) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_size) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_any) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "generic_data") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_i8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i8");
    fossil_dqueue_insert(queue, "127");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_i16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i16");
    fossil_dqueue_insert(queue, "32767");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_i32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    fossil_dqueue_insert(queue, "42");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_i64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i64");
    fossil_dqueue_insert(queue, "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_u8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u8");
    fossil_dqueue_insert(queue, "255");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_u16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u16");
    fossil_dqueue_insert(queue, "65535");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_u32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u32");
    fossil_dqueue_insert(queue, "4294967295");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_u64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u64");
    fossil_dqueue_insert(queue, "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_hex) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("hex");
    fossil_dqueue_insert(queue, "0x1A3F");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_octal) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("octal");
    fossil_dqueue_insert(queue, "0755");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_float) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("float");
    fossil_dqueue_insert(queue, "3.14");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_double) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("double");
    fossil_dqueue_insert(queue, "2.718281828459");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_wstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wstr");
    fossil_dqueue_insert(queue, "L\"wide string\"");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_cstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cstr");
    fossil_dqueue_insert(queue, "\"c string\"");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_cchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cchar");
    fossil_dqueue_insert(queue, "'c'");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_wchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wchar");
    fossil_dqueue_insert(queue, "L'W'");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_bool) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("bool");
    fossil_dqueue_insert(queue, "true");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_size) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("size");
    fossil_dqueue_insert(queue, "1024");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_any) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("any");
    fossil_dqueue_insert(queue, "generic_data");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_i8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i8");
    fossil_dqueue_insert(queue, "127");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_i16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i16");
    fossil_dqueue_insert(queue, "32767");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_i32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    fossil_dqueue_insert(queue, "42");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_i64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i64");
    fossil_dqueue_insert(queue, "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_u8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u8");
    fossil_dqueue_insert(queue, "255");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_u16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u16");
    fossil_dqueue_insert(queue, "65535");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_u32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u32");
    fossil_dqueue_insert(queue, "4294967295");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_u64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u64");
    fossil_dqueue_insert(queue, "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_hex) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("hex");
    fossil_dqueue_insert(queue, "0x1A3F");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_octal) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("octal");
    fossil_dqueue_insert(queue, "0755");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_float) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("float");
    fossil_dqueue_insert(queue, "3.14");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_double) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("double");
    fossil_dqueue_insert(queue, "2.718281828459");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_wstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wstr");
    fossil_dqueue_insert(queue, "L\"wide string\"");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_cstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cstr");
    fossil_dqueue_insert(queue, "\"c string\"");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_cchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cchar");
    fossil_dqueue_insert(queue, "'c'");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_wchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wchar");
    fossil_dqueue_insert(queue, "L'W'");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_bool) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("bool");
    fossil_dqueue_insert(queue, "true");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_size) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("size");
    fossil_dqueue_insert(queue, "1024");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_empty_any) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("any");
    fossil_dqueue_insert(queue, "generic_data");
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_i8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_i16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_i32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_i64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_u8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_u16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_u32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_u64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_hex) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_octal) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_float) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_double) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_wstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_cstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_cchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_wchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_bool) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_size) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_not_cnullptr_any) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_i8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "127");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_i16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "32767");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_i32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "42");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_i64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_u8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "255");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_u16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "65535");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_u32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "4294967295");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_u64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_hex) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "0x1A3F");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_octal) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "0755");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_float) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "3.14");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_double) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "2.718281828459");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_wstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "L\"wide string\"");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_cstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "\"c string\"");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_cchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "'c'");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_wchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "L'W'");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_bool) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "true");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_size) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "1024");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_empty_any) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, "generic_data");
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_is_cnullptr) {
    fossil_dqueue_t* queue = NULL;
    ASSUME_ITS_TRUE(fossil_dqueue_is_cnullptr(queue) == true);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_i8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_i16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_i32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_i64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_u8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_u16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_u32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_u64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_hex) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "0x2A") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "0x2B") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_octal) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "052") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "053") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_float) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "3.14") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2.71") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_double) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "3.141592653589") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2.718281828459") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_wstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L\"wide string 1\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L\"wide string 2\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_cstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "\"c string 1\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "\"c string 2\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_cchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_wchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L'A'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L'B'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_bool) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_size) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2048") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_multiple_insert_any) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "data1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "data2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_i8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i8");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_i16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i16");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_i32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_i64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i64");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_u8) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u8");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_u16) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u16");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_u32) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u32");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_u64) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("u64");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "43") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_hex) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("hex");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "0x2A") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "0x2B") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_octal) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("octal");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "052") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "053") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_float) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("float");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "3.14") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2.71") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_double) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("double");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "3.141592653589") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2.718281828459") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_wstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L\"wide string 1\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L\"wide string 2\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_cstr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "\"c string 1\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "\"c string 2\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_cchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_wchar) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L'A'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "L'B'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_bool) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("bool");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_size) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("size");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "2048") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_remove_any) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("any");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "data1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, "data2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_insert_null) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, NULL) == FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 0);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_remove_empty) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_FAILURE);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_size_empty) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 0);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(c_test_dqueue_size_after_operations) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container("i32");
    fossil_dqueue_insert(queue, "42");
    fossil_dqueue_insert(queue, "43");
    fossil_dqueue_remove(queue);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_dqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_i8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_i8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_i8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_i8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_i8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_cnullptr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_i8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_i8);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_i16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_i16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_i16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_i16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_i16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_i16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_i16);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_i32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_i32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_i32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_i32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_i32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_i32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_i32);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_i64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_i64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_i64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_i64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_i64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_i64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_i64);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_u8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_u8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_u8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_u8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_u8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_u8);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_u8);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_u16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_u16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_u16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_u16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_u16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_u16);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_u16);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_u32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_u32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_u32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_u32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_u32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_u32);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_u32);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_u64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_u64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_u64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_u64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_u64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_u64);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_u64);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_hex);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_hex);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_hex);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_hex);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_hex);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_hex);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_hex);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_octal);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_octal);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_octal);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_octal);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_octal);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_octal);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_octal);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_float);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_float);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_float);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_float);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_float);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_float);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_float);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_double);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_double);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_double);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_double);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_double);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_double);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_double);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_wstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_wstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_wstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_wstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_wstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_wstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_wstr);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_cstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_cstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_cstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_cstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_cstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_cstr);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_cstr);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_cchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_cchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_cchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_cchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_cchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_cchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_cchar);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_wchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_wchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_wchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_wchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_wchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_wchar);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_wchar);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_bool);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_bool);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_bool);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_bool);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_bool);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_bool);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_bool);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_size);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_size);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_size);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_size);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_size);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_size);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_size);

    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_any);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_any);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_empty_any);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_not_cnullptr_any);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_is_empty_any);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_multiple_insert_any);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_remove_any);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_insert_null);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_remove_empty);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_size_empty);
    FOSSIL_TEST_ADD(c_dqueue_tofu_fixture, c_test_dqueue_size_after_operations);

    FOSSIL_TEST_REGISTER(c_dqueue_tofu_fixture);
} // end of tests
