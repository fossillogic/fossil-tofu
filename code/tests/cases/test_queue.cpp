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

FOSSIL_TEST_SUITE(cpp_queue_tofu_fixture);

FOSSIL_SETUP(cpp_queue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_queue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_queue_insert_i8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("127")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_i16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("32767")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_i32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("2147483647")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_i64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("9223372036854775807")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_u8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("255")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_u16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("65535")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_u32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("4294967295")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_u64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("18446744073709551615")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_hex) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("0x1A3F")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_octal) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("0755")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_float) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("3.14")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_double) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("2.718281828459")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_wstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("L\"Wide String\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_cstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("\"C String\"")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_cchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("'C'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_wchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("L'W'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_bool) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_size) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_insert_any) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_queue_insert(queue, const_cast<char*>("genericpp_data")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_size(queue) == 1);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_i8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i8"));
    fossil_queue_insert(queue, const_cast<char*>("127"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_i16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i16"));
    fossil_queue_insert(queue, const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_i32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i32"));
    fossil_queue_insert(queue, const_cast<char*>("2147483647"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_i64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i64"));
    fossil_queue_insert(queue, const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_u8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u8"));
    fossil_queue_insert(queue, const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_u16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u16"));
    fossil_queue_insert(queue, const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_u32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u32"));
    fossil_queue_insert(queue, const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_u64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u64"));
    fossil_queue_insert(queue, const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_hex) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("hex"));
    fossil_queue_insert(queue, const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_octal) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("octal"));
    fossil_queue_insert(queue, const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_float) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("float"));
    fossil_queue_insert(queue, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_double) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("double"));
    fossil_queue_insert(queue, const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_wstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wstr"));
    fossil_queue_insert(queue, const_cast<char*>("L\"Wide String\""));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_cstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cstr"));
    fossil_queue_insert(queue, const_cast<char*>("\"C String\""));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_cchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cchar"));
    fossil_queue_insert(queue, const_cast<char*>("'C'"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_wchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wchar"));
    fossil_queue_insert(queue, const_cast<char*>("L'W'"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_bool) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("bool"));
    fossil_queue_insert(queue, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_size) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("size"));
    fossil_queue_insert(queue, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_remove_any) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("any"));
    fossil_queue_insert(queue, const_cast<char*>("genericpp_data"));
    ASSUME_ITS_TRUE(fossil_queue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_i8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i8"));
    fossil_queue_insert(queue, const_cast<char*>("127"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_i16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i16"));
    fossil_queue_insert(queue, const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_i32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i32"));
    fossil_queue_insert(queue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_i64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i64"));
    fossil_queue_insert(queue, const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_u8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u8"));
    fossil_queue_insert(queue, const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_u16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u16"));
    fossil_queue_insert(queue, const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_u32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u32"));
    fossil_queue_insert(queue, const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_u64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u64"));
    fossil_queue_insert(queue, const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_hex) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("hex"));
    fossil_queue_insert(queue, const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_octal) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("octal"));
    fossil_queue_insert(queue, const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_float) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("float"));
    fossil_queue_insert(queue, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_double) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("double"));
    fossil_queue_insert(queue, const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_wstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wstr"));
    fossil_queue_insert(queue, const_cast<char*>("L\"Wide String\""));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_cstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cstr"));
    fossil_queue_insert(queue, const_cast<char*>("\"C String\""));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_cchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cchar"));
    fossil_queue_insert(queue, const_cast<char*>("'C'"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_wchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wchar"));
    fossil_queue_insert(queue, const_cast<char*>("L'W'"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_bool) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("bool"));
    fossil_queue_insert(queue, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_size) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("size"));
    fossil_queue_insert(queue, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_empty_any) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("any"));
    fossil_queue_insert(queue, const_cast<char*>("genericpp_data"));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_i8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_i16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_i32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_i64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_u8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_u16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_u32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_u64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_hex) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_octal) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_float) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_double) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_wstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_cstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_cchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_wchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_bool) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_size) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_not_cnullptr_any) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue) == true);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_i8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("127"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_i16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_i32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_i64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_u8) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_u16) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_u32) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_u64) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_hex) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_octal) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_float) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_double) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_wstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("L\"Wide String\""));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_cstr) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("\"C String\""));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_cchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("'C'"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_wchar) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("L'W'"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_bool) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_size) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_empty_any) {
    fossil_queue_t* queue = fossil_queue_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == true);
    fossil_queue_insert(queue, const_cast<char*>("genericpp_data"));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue) == false);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_queue_is_cnullptr) {
    fossil_queue_t* queue = NULL;
    ASSUME_ITS_TRUE(fossil_queue_is_cnullptr(queue) == true);
}

FOSSIL_TEST_CASE(cpp_test_queue_class_insert) {
    fossil::tofu::Queue queue("i32");
    ASSUME_ITS_TRUE(queue.insert("42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(queue.size() == 1);
}

FOSSIL_TEST_CASE(cpp_test_queue_class_remove) {
    fossil::tofu::Queue queue("i32");
    queue.insert("42");
    ASSUME_ITS_TRUE(queue.remove() == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(queue.is_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_queue_class_not_empty) {
    fossil::tofu::Queue queue("i32");
    queue.insert("42");
    ASSUME_ITS_TRUE(queue.not_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_queue_class_is_empty) {
    fossil::tofu::Queue queue("i32");
    ASSUME_ITS_TRUE(queue.is_empty() == true);
    queue.insert("42");
    ASSUME_ITS_TRUE(queue.is_empty() == false);
}

FOSSIL_TEST_CASE(cpp_test_queue_class_get_front) {
    fossil::tofu::Queue queue("i32");
    queue.insert("42");
    ASSUME_ITS_TRUE(queue.get_front() == "42");
}

FOSSIL_TEST_CASE(cpp_test_queue_class_get_rear) {
    fossil::tofu::Queue queue("i32");
    queue.insert("42");
    ASSUME_ITS_TRUE(queue.get_rear() == "42");
}

FOSSIL_TEST_CASE(cpp_test_queue_class_set_front) {
    fossil::tofu::Queue queue("i32");
    queue.insert("42");
    queue.set_front("84");
    ASSUME_ITS_TRUE(queue.get_front() == "84");
}

FOSSIL_TEST_CASE(cpp_test_queue_class_set_rear) {
    fossil::tofu::Queue queue("i32");
    queue.insert("42");
    queue.set_rear("84");
    ASSUME_ITS_TRUE(queue.get_rear() == "84");
}

FOSSIL_TEST_CASE(cpp_test_queue_class_copy_constructor) {
    fossil::tofu::Queue original("i32");
    original.insert("42");
    fossil::tofu::Queue copy(original);
    ASSUME_ITS_TRUE(copy.size() == 1);
    ASSUME_ITS_TRUE(copy.get_front() == "42");
}

FOSSIL_TEST_CASE(cpp_test_queue_class_move_constructor) {
    fossil::tofu::Queue original("i32");
    original.insert("42");
    fossil::tofu::Queue moved(std::move(original));
    ASSUME_ITS_TRUE(moved.size() == 1);
    ASSUME_ITS_TRUE(moved.get_front() == "42");
    ASSUME_ITS_TRUE(original.is_cnullptr() == true);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_queue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_i8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_i16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_i32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_i64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_u8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_u16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_u32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_u64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_hex);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_octal);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_float);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_double);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_wstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_cstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_cchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_wchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_bool);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_size);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_any);

    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_i8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_i16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_i32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_i64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_u8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_u16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_u32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_u64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_hex);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_octal);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_float);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_double);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_wstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_cstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_cchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_wchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_bool);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_size);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_any);

    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_i8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_i16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_i32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_i64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_u8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_u16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_u32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_u64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_hex);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_octal);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_float);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_double);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_wstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_cstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_cchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_wchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_bool);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_size);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_any);

    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_i8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_i16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_i32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_i64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_u8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_u16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_u32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_u64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_hex);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_octal);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_float);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_double);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_wstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_cstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_cchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_wchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_bool);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_size);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_any);

    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_i8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_i16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_i32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_i64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_u8);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_u16);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_u32);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_u64);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_hex);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_octal);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_float);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_double);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_wstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_cstr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_cchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_wchar);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_bool);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_size);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_empty_any);

    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_is_cnullptr);

    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_insert);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_remove);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_not_empty);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_is_empty);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_get_front);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_get_rear);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_set_front);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_set_rear);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_copy_constructor);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_class_move_constructor);

    FOSSIL_TEST_REGISTER(cpp_queue_tofu_fixture);
} // end of tests
