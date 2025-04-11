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

FOSSIL_TEST_SUITE(cpp_setof_tofu_fixture);

FOSSIL_SETUP(cpp_setof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_setof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_setof_insert_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("127")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("32767")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2147483647")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("9223372036854775807")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("255")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("65535")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("4294967295")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("18446744073709551615")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("0x1A3F")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("0755")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3.14")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2.718281828459045")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L\"wide string\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("\"char string\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("'c'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L'W'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("random_data")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    fossil_setof_insert(set, const_cast<char*>("127"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("127")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    fossil_setof_insert(set, const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("32767")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    fossil_setof_insert(set, const_cast<char*>("2147483647"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2147483647")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    fossil_setof_insert(set, const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("9223372036854775807")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    fossil_setof_insert(set, const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("255")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    fossil_setof_insert(set, const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("65535")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    fossil_setof_insert(set, const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("4294967295")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    fossil_setof_insert(set, const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("18446744073709551615")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    fossil_setof_insert(set, const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("0x1A3F")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    fossil_setof_insert(set, const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("0755")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    fossil_setof_insert(set, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("3.14")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    fossil_setof_insert(set, const_cast<char*>("2.718281828459045"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2.718281828459045")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    fossil_setof_insert(set, const_cast<char*>("L\"wide string\""));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("L\"wide string\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    fossil_setof_insert(set, const_cast<char*>("\"char string\""));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("\"char string\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    fossil_setof_insert(set, const_cast<char*>("'c'"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("'c'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    fossil_setof_insert(set, const_cast<char*>("L'W'"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("L'W'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    fossil_setof_insert(set, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    fossil_setof_insert(set, const_cast<char*>("random_data"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("random_data")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    fossil_setof_insert(set, const_cast<char*>("127"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("127")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("99")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    fossil_setof_insert(set, const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("32767")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("12345")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    fossil_setof_insert(set, const_cast<char*>("2147483647"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("2147483647")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("123456789")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    fossil_setof_insert(set, const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("9223372036854775807")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("1234567890123456789")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    fossil_setof_insert(set, const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("255")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("128")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    fossil_setof_insert(set, const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("65535")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("12345")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    fossil_setof_insert(set, const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("4294967295")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("123456789")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    fossil_setof_insert(set, const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("18446744073709551615")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("1234567890123456789")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    fossil_setof_insert(set, const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("0x1A3F")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("0xFFFF")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    fossil_setof_insert(set, const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("0755")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("0777")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    fossil_setof_insert(set, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("3.14")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("2.71")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    fossil_setof_insert(set, const_cast<char*>("2.718281828459045"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("2.718281828459045")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("3.141592653589793")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    fossil_setof_insert(set, const_cast<char*>("L\"wide string\""));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("L\"wide string\"")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("L\"other string\"")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    fossil_setof_insert(set, const_cast<char*>("\"char string\""));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("\"char string\"")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("\"other string\"")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    fossil_setof_insert(set, const_cast<char*>("'c'"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("'c'")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("'d'")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    fossil_setof_insert(set, const_cast<char*>("L'W'"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("L'W'")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("L'X'")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("true")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("false")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    fossil_setof_insert(set, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("1024")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("2048")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_contains_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    fossil_setof_insert(set, const_cast<char*>("random_data"));
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("random_data")) == true);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("other_data")) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    fossil_setof_insert(set, const_cast<char*>("0x2A"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    fossil_setof_insert(set, const_cast<char*>("052"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    fossil_setof_insert(set, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    fossil_setof_insert(set, const_cast<char*>("2.718281828459045"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    fossil_setof_insert(set, const_cast<char*>("L\"wide string\""));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    fossil_setof_insert(set, const_cast<char*>("\"char string\""));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    fossil_setof_insert(set, const_cast<char*>("'c'"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    fossil_setof_insert(set, const_cast<char*>("L'W'"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    fossil_setof_insert(set, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_not_empty_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    fossil_setof_insert(set, const_cast<char*>("random_data"));
    ASSUME_ITS_TRUE(fossil_setof_not_empty(set) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("0x2A"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("052"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("2.718281828459045"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("L\"wide string\""));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("\"char string\""));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("'c'"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("L'W'"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_is_empty_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_insert(set, const_cast<char*>("random_data"));
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == false);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    fossil_setof_insert(set, const_cast<char*>("0x1"));
    fossil_setof_insert(set, const_cast<char*>("0x2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    fossil_setof_insert(set, const_cast<char*>("01"));
    fossil_setof_insert(set, const_cast<char*>("02"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    fossil_setof_insert(set, const_cast<char*>("1.1"));
    fossil_setof_insert(set, const_cast<char*>("2.2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    fossil_setof_insert(set, const_cast<char*>("1.1"));
    fossil_setof_insert(set, const_cast<char*>("2.2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    fossil_setof_insert(set, const_cast<char*>("L\"one\""));
    fossil_setof_insert(set, const_cast<char*>("L\"two\""));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    fossil_setof_insert(set, const_cast<char*>("\"one\""));
    fossil_setof_insert(set, const_cast<char*>("\"two\""));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    fossil_setof_insert(set, const_cast<char*>("'a'"));
    fossil_setof_insert(set, const_cast<char*>("'b'"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    fossil_setof_insert(set, const_cast<char*>("L'a'"));
    fossil_setof_insert(set, const_cast<char*>("L'b'"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    fossil_setof_insert(set, const_cast<char*>("false"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    fossil_setof_insert(set, const_cast<char*>("1024"));
    fossil_setof_insert(set, const_cast<char*>("2048"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_size_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    fossil_setof_insert(set, const_cast<char*>("data1"));
    fossil_setof_insert(set, const_cast<char*>("data2"));
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 2);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("0x1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("0x2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("0x3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("01")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("02")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("03")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1.1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2.2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3.3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1.1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2.2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3.3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L\"one\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L\"two\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L\"three\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("\"one\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("\"two\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("\"three\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("'a'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("'b'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("'c'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L'a'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L'b'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L'c'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("false")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2048")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("4096")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_insert_multiple_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("data1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("data2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("data3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 3);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    fossil_setof_insert(set, const_cast<char*>("1"));
    fossil_setof_insert(set, const_cast<char*>("2"));
    fossil_setof_insert(set, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    fossil_setof_insert(set, const_cast<char*>("0x1"));
    fossil_setof_insert(set, const_cast<char*>("0x2"));
    fossil_setof_insert(set, const_cast<char*>("0x3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("0x1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("0x2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    fossil_setof_insert(set, const_cast<char*>("01"));
    fossil_setof_insert(set, const_cast<char*>("02"));
    fossil_setof_insert(set, const_cast<char*>("03"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("01")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("02")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    fossil_setof_insert(set, const_cast<char*>("1.1"));
    fossil_setof_insert(set, const_cast<char*>("2.2"));
    fossil_setof_insert(set, const_cast<char*>("3.3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1.1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2.2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    fossil_setof_insert(set, const_cast<char*>("1.1"));
    fossil_setof_insert(set, const_cast<char*>("2.2"));
    fossil_setof_insert(set, const_cast<char*>("3.3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1.1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2.2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    fossil_setof_insert(set, const_cast<char*>("L\"one\""));
    fossil_setof_insert(set, const_cast<char*>("L\"two\""));
    fossil_setof_insert(set, const_cast<char*>("L\"three\""));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("L\"one\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("L\"two\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    fossil_setof_insert(set, const_cast<char*>("\"one\""));
    fossil_setof_insert(set, const_cast<char*>("\"two\""));
    fossil_setof_insert(set, const_cast<char*>("\"three\""));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("\"one\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("\"two\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    fossil_setof_insert(set, const_cast<char*>("'a'"));
    fossil_setof_insert(set, const_cast<char*>("'b'"));
    fossil_setof_insert(set, const_cast<char*>("'c'"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("'a'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("'b'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    fossil_setof_insert(set, const_cast<char*>("L'a'"));
    fossil_setof_insert(set, const_cast<char*>("L'b'"));
    fossil_setof_insert(set, const_cast<char*>("L'c'"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("L'a'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("L'b'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    fossil_setof_insert(set, const_cast<char*>("false"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("false")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    fossil_setof_insert(set, const_cast<char*>("1024"));
    fossil_setof_insert(set, const_cast<char*>("2048"));
    fossil_setof_insert(set, const_cast<char*>("4096"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("2048")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_remove_multiple_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    fossil_setof_insert(set, const_cast<char*>("data1"));
    fossil_setof_insert(set, const_cast<char*>("data2"));
    fossil_setof_insert(set, const_cast<char*>("data3"));
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("data1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_remove(set, const_cast<char*>("data2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    fossil_setof_insert(set, const_cast<char*>("127"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("127")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    fossil_setof_insert(set, const_cast<char*>("32767"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("32767")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    fossil_setof_insert(set, const_cast<char*>("2147483647"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("2147483647")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    fossil_setof_insert(set, const_cast<char*>("9223372036854775807"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("9223372036854775807")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    fossil_setof_insert(set, const_cast<char*>("255"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("255")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    fossil_setof_insert(set, const_cast<char*>("65535"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("65535")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    fossil_setof_insert(set, const_cast<char*>("4294967295"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("4294967295")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    fossil_setof_insert(set, const_cast<char*>("18446744073709551615"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("18446744073709551615")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    fossil_setof_insert(set, const_cast<char*>("0x1A3F"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("0x1A3F")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    fossil_setof_insert(set, const_cast<char*>("0755"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("0755")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    fossil_setof_insert(set, const_cast<char*>("3.14"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("3.14")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    fossil_setof_insert(set, const_cast<char*>("2.718281828459045"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("2.718281828459045")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    fossil_setof_insert(set, const_cast<char*>("L\"wide string\""));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("L\"wide string\"")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    fossil_setof_insert(set, const_cast<char*>("\"char string\""));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("\"char string\"")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    fossil_setof_insert(set, const_cast<char*>("'c'"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("'c'")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    fossil_setof_insert(set, const_cast<char*>("L'W'"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("L'W'")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("true")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    fossil_setof_insert(set, const_cast<char*>("1024"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("1024")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_copy_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    fossil_setof_insert(set, const_cast<char*>("random_data"));
    fossil_setof_t* copy = fossil_setof_create_copy(set);
    ASSUME_ITS_TRUE(fossil_setof_size(copy) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(copy, const_cast<char*>("random_data")) == true);
    fossil_setof_destroy(set);
    fossil_setof_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    fossil_setof_insert(set, const_cast<char*>("127"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("127")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    fossil_setof_insert(set, const_cast<char*>("32767"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("32767")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    fossil_setof_insert(set, const_cast<char*>("2147483647"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("2147483647")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    fossil_setof_insert(set, const_cast<char*>("9223372036854775807"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("9223372036854775807")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    fossil_setof_insert(set, const_cast<char*>("255"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("255")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    fossil_setof_insert(set, const_cast<char*>("65535"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("65535")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    fossil_setof_insert(set, const_cast<char*>("4294967295"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("4294967295")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    fossil_setof_insert(set, const_cast<char*>("18446744073709551615"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("18446744073709551615")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    fossil_setof_insert(set, const_cast<char*>("0x1A3F"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("0x1A3F")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    fossil_setof_insert(set, const_cast<char*>("0755"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("0755")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    fossil_setof_insert(set, const_cast<char*>("3.14"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("3.14")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    fossil_setof_insert(set, const_cast<char*>("2.718281828459045"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("2.718281828459045")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    fossil_setof_insert(set, const_cast<char*>("L\"wide string\""));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("L\"wide string\"")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    fossil_setof_insert(set, const_cast<char*>("\"char string\""));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("\"char string\"")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    fossil_setof_insert(set, const_cast<char*>("'c'"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("'c'")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    fossil_setof_insert(set, const_cast<char*>("L'W'"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("L'W'")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    fossil_setof_insert(set, const_cast<char*>("true"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("true")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    fossil_setof_insert(set, const_cast<char*>("1024"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("1024")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_move_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    fossil_setof_insert(set, const_cast<char*>("random_data"));
    fossil_setof_t* moved = fossil_setof_create_move(set);
    ASSUME_ITS_TRUE(fossil_setof_size(moved) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(moved, const_cast<char*>("random_data")) == true);
    ASSUME_ITS_TRUE(fossil_setof_is_empty(set) == true);
    fossil_setof_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_i8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("127")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("127")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_i16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("32767")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("32767")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_i32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2147483647")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("2147483647")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_i64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("9223372036854775807")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("9223372036854775807")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_u8) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("255")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("255")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_u16) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("65535")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("65535")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_u32) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("4294967295")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("4294967295")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_u64) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("18446744073709551615")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("18446744073709551615")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_hex) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("0x1A3F")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("0x1A3F")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_octal) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("0755")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("0755")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_float) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("3.14")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("3.14")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_double) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("2.718281828459045")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("2.718281828459045")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_wstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L\"wide string\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("L\"wide string\"")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_cstr) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("\"char string\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("\"char string\"")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_cchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("'c'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("'c'")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_wchar) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("L'W'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("L'W'")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_bool) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("true")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_size) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("1024")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_create_any) {
    fossil_setof_t* set = fossil_setof_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_setof_insert(set, const_cast<char*>("random_data")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_setof_size(set) == 1);
    ASSUME_ITS_TRUE(fossil_setof_contains(set, const_cast<char*>("random_data")) == true);
    fossil_setof_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_setof_class_insert_and_contains) {
    fossil::tofu::SetOf set("i32");
    set.insert("42");
    ASSUME_ITS_TRUE(set.contains("42"));
}

FOSSIL_TEST_CASE(cpp_test_setof_class_remove) {
    fossil::tofu::SetOf set("i32");
    set.insert("42");
    set.remove("42");
    ASSUME_ITS_TRUE(!set.contains("42"));
}

FOSSIL_TEST_CASE(cpp_test_setof_class_size) {
    fossil::tofu::SetOf set("i32");
    set.insert("42");
    set.insert("84");
    ASSUME_ITS_TRUE(set.size() == 2);
}

FOSSIL_TEST_CASE(cpp_test_setof_class_is_empty) {
    fossil::tofu::SetOf set("i32");
    ASSUME_ITS_TRUE(set.is_empty());
    set.insert("42");
    ASSUME_ITS_TRUE(!set.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_setof_class_not_empty) {
    fossil::tofu::SetOf set("i32");
    ASSUME_ITS_TRUE(!set.not_empty());
    set.insert("42");
    ASSUME_ITS_TRUE(set.not_empty());
}

FOSSIL_TEST_CASE(cpp_test_setof_class_multiple_operations) {
    fossil::tofu::SetOf set("i32");
    set.insert("42");
    set.insert("84");
    ASSUME_ITS_TRUE(set.size() == 2);
    ASSUME_ITS_TRUE(set.contains("42"));
    set.remove("42");
    ASSUME_ITS_TRUE(!set.contains("42"));
    ASSUME_ITS_TRUE(set.size() == 1);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_setof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_contains_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_not_empty_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_is_empty_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_size_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_insert_multiple_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_remove_multiple_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_copy_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_i8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_i16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_i32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_i64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_u8);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_u16);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_u32);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_u64);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_hex);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_octal);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_float);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_double);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_wstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_cstr);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_cchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_wchar);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_bool);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_create_move_any);

    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_class_insert_and_contains);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_class_remove);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_class_size);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_class_is_empty);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_class_not_empty);
    FOSSIL_TEST_ADD(cpp_setof_tofu_fixture, cpp_test_setof_class_multiple_operations);

    FOSSIL_TEST_REGISTER(cpp_setof_tofu_fixture);
} // end of tests
