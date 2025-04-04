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

FOSSIL_TEST_SUITE(c_setof_tofu_fixture);

FOSSIL_SETUP(c_setof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_setof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_setof_insert_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "127") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "32767") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2147483647") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "9223372036854775807") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "255") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "65535") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "4294967295") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "18446744073709551615") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "0x1A3F") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "0755") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3.14") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2.718281828459045") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L\"wide string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "\"char string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "'c'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L'W'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "random_data") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    fossil_setof_insert(set, "127");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "127") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    fossil_setof_insert(set, "32767");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "32767") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "2147483647");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2147483647") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    fossil_setof_insert(set, "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "9223372036854775807") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    fossil_setof_insert(set, "255");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "255") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    fossil_setof_insert(set, "65535");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "65535") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    fossil_setof_insert(set, "4294967295");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "4294967295") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    fossil_setof_insert(set, "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "18446744073709551615") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    fossil_setof_insert(set, "0x1A3F");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "0x1A3F") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    fossil_setof_insert(set, "0755");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "0755") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    fossil_setof_insert(set, "3.14");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "3.14") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    fossil_setof_insert(set, "2.718281828459045");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2.718281828459045") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    fossil_setof_insert(set, "L\"wide string\"");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "L\"wide string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    fossil_setof_insert(set, "\"char string\"");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "\"char string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    fossil_setof_insert(set, "'c'");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "'c'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    fossil_setof_insert(set, "L'W'");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "L'W'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    fossil_setof_insert(set, "true");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    fossil_setof_insert(set, "1024");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    fossil_setof_insert(set, "random_data");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "random_data") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    fossil_setof_insert(set, "127");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "127") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "99") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    fossil_setof_insert(set, "32767");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "32767") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "12345") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "2147483647");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "2147483647") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "123456789") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    fossil_setof_insert(set, "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "9223372036854775807") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "1234567890123456789") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    fossil_setof_insert(set, "255");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "255") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "128") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    fossil_setof_insert(set, "65535");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "65535") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "12345") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    fossil_setof_insert(set, "4294967295");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "4294967295") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "123456789") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    fossil_setof_insert(set, "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "18446744073709551615") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "1234567890123456789") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    fossil_setof_insert(set, "0x1A3F");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "0x1A3F") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "0xFFFF") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    fossil_setof_insert(set, "0755");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "0755") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "0777") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    fossil_setof_insert(set, "3.14");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "3.14") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "2.71") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    fossil_setof_insert(set, "2.718281828459045");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "2.718281828459045") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "3.141592653589793") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    fossil_setof_insert(set, "L\"wide string\"");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "L\"wide string\"") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "L\"other string\"") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    fossil_setof_insert(set, "\"char string\"");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "\"char string\"") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "\"other string\"") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    fossil_setof_insert(set, "'c'");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "'c'") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "'d'") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    fossil_setof_insert(set, "L'W'");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "L'W'") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "L'X'") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    fossil_setof_insert(set, "true");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "true") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "false") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    fossil_setof_insert(set, "1024");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "1024") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "2048") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_contains_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    fossil_setof_insert(set, "random_data");
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "random_data") == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "other_data") == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    fossil_setof_insert(set, "0x2A");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    fossil_setof_insert(set, "052");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    fossil_setof_insert(set, "3.14");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    fossil_setof_insert(set, "2.718281828459045");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    fossil_setof_insert(set, "L\"wide string\"");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    fossil_setof_insert(set, "\"char string\"");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    fossil_setof_insert(set, "'c'");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    fossil_setof_insert(set, "L'W'");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    fossil_setof_insert(set, "true");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    fossil_setof_insert(set, "1024");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_not_empty_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    fossil_setof_insert(set, "random_data");
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "42");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "0x2A");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "052");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "3.14");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "2.718281828459045");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "L\"wide string\"");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "\"char string\"");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "'c'");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "L'W'");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "true");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "1024");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_is_empty_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, "random_data");
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    fossil_setof_insert(set, "0x1");
    fossil_setof_insert(set, "0x2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    fossil_setof_insert(set, "01");
    fossil_setof_insert(set, "02");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    fossil_setof_insert(set, "1.1");
    fossil_setof_insert(set, "2.2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    fossil_setof_insert(set, "1.1");
    fossil_setof_insert(set, "2.2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    fossil_setof_insert(set, "L\"one\"");
    fossil_setof_insert(set, "L\"two\"");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    fossil_setof_insert(set, "\"one\"");
    fossil_setof_insert(set, "\"two\"");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    fossil_setof_insert(set, "'a'");
    fossil_setof_insert(set, "'b'");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    fossil_setof_insert(set, "L'a'");
    fossil_setof_insert(set, "L'b'");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    fossil_setof_insert(set, "true");
    fossil_setof_insert(set, "false");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    fossil_setof_insert(set, "1024");
    fossil_setof_insert(set, "2048");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_size_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    fossil_setof_insert(set, "data1");
    fossil_setof_insert(set, "data2");
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "0x1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "0x2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "0x3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "01") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "02") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "03") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1.1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2.2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3.3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1.1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2.2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3.3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L\"one\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L\"two\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L\"three\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "\"one\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "\"two\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "\"three\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "'c'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L'c'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2048") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "4096") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_insert_multiple_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "data1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "data2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "data3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    fossil_setof_insert(set, "1");
    fossil_setof_insert(set, "2");
    fossil_setof_insert(set, "3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    fossil_setof_insert(set, "0x1");
    fossil_setof_insert(set, "0x2");
    fossil_setof_insert(set, "0x3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "0x1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "0x2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    fossil_setof_insert(set, "01");
    fossil_setof_insert(set, "02");
    fossil_setof_insert(set, "03");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "01") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "02") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    fossil_setof_insert(set, "1.1");
    fossil_setof_insert(set, "2.2");
    fossil_setof_insert(set, "3.3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1.1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2.2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    fossil_setof_insert(set, "1.1");
    fossil_setof_insert(set, "2.2");
    fossil_setof_insert(set, "3.3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1.1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2.2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    fossil_setof_insert(set, "L\"one\"");
    fossil_setof_insert(set, "L\"two\"");
    fossil_setof_insert(set, "L\"three\"");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "L\"one\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "L\"two\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    fossil_setof_insert(set, "\"one\"");
    fossil_setof_insert(set, "\"two\"");
    fossil_setof_insert(set, "\"three\"");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "\"one\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "\"two\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    fossil_setof_insert(set, "'a'");
    fossil_setof_insert(set, "'b'");
    fossil_setof_insert(set, "'c'");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    fossil_setof_insert(set, "L'a'");
    fossil_setof_insert(set, "L'b'");
    fossil_setof_insert(set, "L'c'");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "L'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "L'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    fossil_setof_insert(set, "true");
    fossil_setof_insert(set, "false");
    fossil_setof_insert(set, "true");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    fossil_setof_insert(set, "1024");
    fossil_setof_insert(set, "2048");
    fossil_setof_insert(set, "4096");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "2048") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_remove_multiple_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    fossil_setof_insert(set, "data1");
    fossil_setof_insert(set, "data2");
    fossil_setof_insert(set, "data3");
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "data1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, "data2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    fossil_setof_insert(set, "127");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "127") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    fossil_setof_insert(set, "32767");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "32767") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "2147483647");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "2147483647") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    fossil_setof_insert(set, "9223372036854775807");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "9223372036854775807") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    fossil_setof_insert(set, "255");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "255") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    fossil_setof_insert(set, "65535");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "65535") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    fossil_setof_insert(set, "4294967295");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "4294967295") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    fossil_setof_insert(set, "18446744073709551615");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "18446744073709551615") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    fossil_setof_insert(set, "0x1A3F");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "0x1A3F") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    fossil_setof_insert(set, "0755");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "0755") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    fossil_setof_insert(set, "3.14");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "3.14") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    fossil_setof_insert(set, "2.718281828459045");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "2.718281828459045") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    fossil_setof_insert(set, "L\"wide string\"");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "L\"wide string\"") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    fossil_setof_insert(set, "\"char string\"");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "\"char string\"") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    fossil_setof_insert(set, "'c'");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "'c'") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    fossil_setof_insert(set, "L'W'");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "L'W'") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    fossil_setof_insert(set, "true");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "true") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    fossil_setof_insert(set, "1024");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "1024") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_copy_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    fossil_setof_insert(set, "random_data");
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, "random_data") == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    fossil_setof_insert(set, "127");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "127") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    fossil_setof_insert(set, "32767");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "32767") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    fossil_setof_insert(set, "2147483647");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "2147483647") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    fossil_setof_insert(set, "9223372036854775807");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "9223372036854775807") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    fossil_setof_insert(set, "255");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "255") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    fossil_setof_insert(set, "65535");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "65535") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    fossil_setof_insert(set, "4294967295");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "4294967295") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    fossil_setof_insert(set, "18446744073709551615");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "18446744073709551615") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    fossil_setof_insert(set, "0x1A3F");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "0x1A3F") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    fossil_setof_insert(set, "0755");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "0755") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    fossil_setof_insert(set, "3.14");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "3.14") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    fossil_setof_insert(set, "2.718281828459045");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "2.718281828459045") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    fossil_setof_insert(set, "L\"wide string\"");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "L\"wide string\"") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    fossil_setof_insert(set, "\"char string\"");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "\"char string\"") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    fossil_setof_insert(set, "'c'");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "'c'") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    fossil_setof_insert(set, "L'W'");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "L'W'") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    fossil_setof_insert(set, "true");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "true") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    fossil_setof_insert(set, "1024");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "1024") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_move_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    fossil_setof_insert(set, "random_data");
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, "random_data") == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_setof_create_i8) {
    fossil_setof_t* set = fossil_setof_create_container("i8");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "127") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "127") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_i16) {
    fossil_setof_t* set = fossil_setof_create_container("i16");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "32767") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "32767") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_i32) {
    fossil_setof_t* set = fossil_setof_create_container("i32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2147483647") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "2147483647") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_i64) {
    fossil_setof_t* set = fossil_setof_create_container("i64");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "9223372036854775807") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "9223372036854775807") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_u8) {
    fossil_setof_t* set = fossil_setof_create_container("u8");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "255") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "255") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_u16) {
    fossil_setof_t* set = fossil_setof_create_container("u16");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "65535") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "65535") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_u32) {
    fossil_setof_t* set = fossil_setof_create_container("u32");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "4294967295") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "4294967295") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_u64) {
    fossil_setof_t* set = fossil_setof_create_container("u64");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "18446744073709551615") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "18446744073709551615") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_hex) {
    fossil_setof_t* set = fossil_setof_create_container("hex");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "0x1A3F") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "0x1A3F") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_octal) {
    fossil_setof_t* set = fossil_setof_create_container("octal");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "0755") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "0755") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_float) {
    fossil_setof_t* set = fossil_setof_create_container("float");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "3.14") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "3.14") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_double) {
    fossil_setof_t* set = fossil_setof_create_container("double");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "2.718281828459045") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "2.718281828459045") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_wstr) {
    fossil_setof_t* set = fossil_setof_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L\"wide string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "L\"wide string\"") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_cstr) {
    fossil_setof_t* set = fossil_setof_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "\"char string\"") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "\"char string\"") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_cchar) {
    fossil_setof_t* set = fossil_setof_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "'c'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "'c'") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_wchar) {
    fossil_setof_t* set = fossil_setof_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "L'W'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "L'W'") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_bool) {
    fossil_setof_t* set = fossil_setof_create_container("bool");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "true") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_size) {
    fossil_setof_t* set = fossil_setof_create_container("size");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "1024") == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(c_test_setof_create_any) {
    fossil_setof_t* set = fossil_setof_create_container("any");
    ASSUME_ITS_TRUE(fossil_setof_insert(set, "random_data") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, "random_data") == true);
    fossil_setof_destroy(set);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_setof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_contains_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_not_empty_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_is_empty_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_size_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_insert_multiple_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_remove_multiple_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_copy_any);

    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_i8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_i16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_i32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_i64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_u8);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_u16);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_u32);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_u64);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_hex);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_octal);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_float);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_double);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_wstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_cstr);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_cchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_wchar);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_bool);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_size);
    FOSSIL_TEST_ADD(c_setof_tofu_fixture, c_test_setof_create_move_any);

    FOSSIL_TEST_REGISTER(c_setof_tofu_fixture);
} // end of tests
