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

FOSSIL_TEST_SUITE(cpp_flist_tofu_fixture);

FOSSIL_SETUP(cpp_flist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_flist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_flist_insert_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("0x2A")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("052")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("3.14")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("3.14159")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("wide_string")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("char_string")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("c")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("w")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_insert_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_flist_insert(flist, const_cast<char*>("genericpp_value")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    fossil_flist_insert(flist, const_cast<char*>("0x2A"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    fossil_flist_insert(flist, const_cast<char*>("052"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    fossil_flist_insert(flist, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    fossil_flist_insert(flist, const_cast<char*>("3.14159"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    fossil_flist_insert(flist, const_cast<char*>("wide_string"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    fossil_flist_insert(flist, const_cast<char*>("char_string"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    fossil_flist_insert(flist, const_cast<char*>("c"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    fossil_flist_insert(flist, const_cast<char*>("w"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_remove_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    fossil_flist_insert(flist, const_cast<char*>("genericpp_value"));
    ASSUME_ITS_TRUE(fossil_flist_remove(flist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_i32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i32"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    fossil_flist_insert(flist, const_cast<char*>("0x2A"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    fossil_flist_insert(flist, const_cast<char*>("052"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    fossil_flist_insert(flist, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    fossil_flist_insert(flist, const_cast<char*>("3.14159"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    fossil_flist_insert(flist, const_cast<char*>("wide_string"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    fossil_flist_insert(flist, const_cast<char*>("char_string"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    fossil_flist_insert(flist, const_cast<char*>("c"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    fossil_flist_insert(flist, const_cast<char*>("w"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_empty_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    fossil_flist_insert(flist, const_cast<char*>("genericpp_value"));
    ASSUME_ITS_TRUE(fossil_flist_not_empty(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_i32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_not_cnullptr_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(flist) == true);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("0x2A"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("052"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("3.14159"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("wide_string"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("char_string"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("c"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("w"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_empty_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == true);
    fossil_flist_insert(flist, const_cast<char*>("genericpp_value"));
    ASSUME_ITS_TRUE(fossil_flist_is_empty(flist) == false);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_is_cnullptr) {
    fossil_flist_t* flist = nullptr;
    ASSUME_ITS_TRUE(fossil_flist_is_cnullptr(flist) == true);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_i32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i32"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    fossil_flist_insert(flist, const_cast<char*>("0x1"));
    fossil_flist_insert(flist, const_cast<char*>("0x2"));
    fossil_flist_insert(flist, const_cast<char*>("0x3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    fossil_flist_insert(flist, const_cast<char*>("01"));
    fossil_flist_insert(flist, const_cast<char*>("02"));
    fossil_flist_insert(flist, const_cast<char*>("03"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    fossil_flist_insert(flist, const_cast<char*>("1.1"));
    fossil_flist_insert(flist, const_cast<char*>("2.2"));
    fossil_flist_insert(flist, const_cast<char*>("3.3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    fossil_flist_insert(flist, const_cast<char*>("1.11"));
    fossil_flist_insert(flist, const_cast<char*>("2.22"));
    fossil_flist_insert(flist, const_cast<char*>("3.33"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    fossil_flist_insert(flist, const_cast<char*>("wide1"));
    fossil_flist_insert(flist, const_cast<char*>("wide2"));
    fossil_flist_insert(flist, const_cast<char*>("wide3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    fossil_flist_insert(flist, const_cast<char*>("char1"));
    fossil_flist_insert(flist, const_cast<char*>("char2"));
    fossil_flist_insert(flist, const_cast<char*>("char3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    fossil_flist_insert(flist, const_cast<char*>("a"));
    fossil_flist_insert(flist, const_cast<char*>("b"));
    fossil_flist_insert(flist, const_cast<char*>("c"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    fossil_flist_insert(flist, const_cast<char*>("wa"));
    fossil_flist_insert(flist, const_cast<char*>("wb"));
    fossil_flist_insert(flist, const_cast<char*>("wc"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    fossil_flist_insert(flist, const_cast<char*>("false"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    fossil_flist_insert(flist, const_cast<char*>("2048"));
    fossil_flist_insert(flist, const_cast<char*>("4096"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_forward_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    fossil_flist_insert(flist, const_cast<char*>("value1"));
    fossil_flist_insert(flist, const_cast<char*>("value2"));
    fossil_flist_insert(flist, const_cast<char*>("value3"));
    fossil_flist_reverse_forward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_i32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i32"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    fossil_flist_insert(flist, const_cast<char*>("0x1"));
    fossil_flist_insert(flist, const_cast<char*>("0x2"));
    fossil_flist_insert(flist, const_cast<char*>("0x3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    fossil_flist_insert(flist, const_cast<char*>("01"));
    fossil_flist_insert(flist, const_cast<char*>("02"));
    fossil_flist_insert(flist, const_cast<char*>("03"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    fossil_flist_insert(flist, const_cast<char*>("1.1"));
    fossil_flist_insert(flist, const_cast<char*>("2.2"));
    fossil_flist_insert(flist, const_cast<char*>("3.3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    fossil_flist_insert(flist, const_cast<char*>("1.11"));
    fossil_flist_insert(flist, const_cast<char*>("2.22"));
    fossil_flist_insert(flist, const_cast<char*>("3.33"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    fossil_flist_insert(flist, const_cast<char*>("wide1"));
    fossil_flist_insert(flist, const_cast<char*>("wide2"));
    fossil_flist_insert(flist, const_cast<char*>("wide3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    fossil_flist_insert(flist, const_cast<char*>("char1"));
    fossil_flist_insert(flist, const_cast<char*>("char2"));
    fossil_flist_insert(flist, const_cast<char*>("char3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    fossil_flist_insert(flist, const_cast<char*>("a"));
    fossil_flist_insert(flist, const_cast<char*>("b"));
    fossil_flist_insert(flist, const_cast<char*>("c"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    fossil_flist_insert(flist, const_cast<char*>("wa"));
    fossil_flist_insert(flist, const_cast<char*>("wb"));
    fossil_flist_insert(flist, const_cast<char*>("wc"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    fossil_flist_insert(flist, const_cast<char*>("false"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    fossil_flist_insert(flist, const_cast<char*>("2048"));
    fossil_flist_insert(flist, const_cast<char*>("4096"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_reverse_backward_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    fossil_flist_insert(flist, const_cast<char*>("value1"));
    fossil_flist_insert(flist, const_cast<char*>("value2"));
    fossil_flist_insert(flist, const_cast<char*>("value3"));
    fossil_flist_reverse_backward(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_i32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("0x2A"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("052"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("3.14159"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("wide_string"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("char_string"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("c"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("w"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_size_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 0);
    fossil_flist_insert(flist, const_cast<char*>("genericpp_value"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    fossil_flist_insert(flist, const_cast<char*>("0x1"));
    fossil_flist_insert(flist, const_cast<char*>("0x2"));
    fossil_flist_insert(flist, const_cast<char*>("0x3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    fossil_flist_insert(flist, const_cast<char*>("01"));
    fossil_flist_insert(flist, const_cast<char*>("02"));
    fossil_flist_insert(flist, const_cast<char*>("03"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    fossil_flist_insert(flist, const_cast<char*>("1.1"));
    fossil_flist_insert(flist, const_cast<char*>("2.2"));
    fossil_flist_insert(flist, const_cast<char*>("3.3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    fossil_flist_insert(flist, const_cast<char*>("1.11"));
    fossil_flist_insert(flist, const_cast<char*>("2.22"));
    fossil_flist_insert(flist, const_cast<char*>("3.33"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    fossil_flist_insert(flist, const_cast<char*>("wide1"));
    fossil_flist_insert(flist, const_cast<char*>("wide2"));
    fossil_flist_insert(flist, const_cast<char*>("wide3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    fossil_flist_insert(flist, const_cast<char*>("char1"));
    fossil_flist_insert(flist, const_cast<char*>("char2"));
    fossil_flist_insert(flist, const_cast<char*>("char3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    fossil_flist_insert(flist, const_cast<char*>("a"));
    fossil_flist_insert(flist, const_cast<char*>("b"));
    fossil_flist_insert(flist, const_cast<char*>("c"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    fossil_flist_insert(flist, const_cast<char*>("wa"));
    fossil_flist_insert(flist, const_cast<char*>("wb"));
    fossil_flist_insert(flist, const_cast<char*>("wc"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    fossil_flist_insert(flist, const_cast<char*>("false"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    fossil_flist_insert(flist, const_cast<char*>("2048"));
    fossil_flist_insert(flist, const_cast<char*>("4096"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_inserts_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    fossil_flist_insert(flist, const_cast<char*>("value1"));
    fossil_flist_insert(flist, const_cast<char*>("value2"));
    fossil_flist_insert(flist, const_cast<char*>("value3"));
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 3);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_i8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_i16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_i64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("i64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_u8) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u8"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_u16) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u16"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_u32) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u32"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_u64) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("u64"));
    fossil_flist_insert(flist, const_cast<char*>("1"));
    fossil_flist_insert(flist, const_cast<char*>("2"));
    fossil_flist_insert(flist, const_cast<char*>("3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_hex) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("hex"));
    fossil_flist_insert(flist, const_cast<char*>("0x1"));
    fossil_flist_insert(flist, const_cast<char*>("0x2"));
    fossil_flist_insert(flist, const_cast<char*>("0x3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_octal) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("octal"));
    fossil_flist_insert(flist, const_cast<char*>("01"));
    fossil_flist_insert(flist, const_cast<char*>("02"));
    fossil_flist_insert(flist, const_cast<char*>("03"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_float) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("float"));
    fossil_flist_insert(flist, const_cast<char*>("1.1"));
    fossil_flist_insert(flist, const_cast<char*>("2.2"));
    fossil_flist_insert(flist, const_cast<char*>("3.3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_double) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("double"));
    fossil_flist_insert(flist, const_cast<char*>("1.11"));
    fossil_flist_insert(flist, const_cast<char*>("2.22"));
    fossil_flist_insert(flist, const_cast<char*>("3.33"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_wstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wstr"));
    fossil_flist_insert(flist, const_cast<char*>("wide1"));
    fossil_flist_insert(flist, const_cast<char*>("wide2"));
    fossil_flist_insert(flist, const_cast<char*>("wide3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_cstr) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cstr"));
    fossil_flist_insert(flist, const_cast<char*>("char1"));
    fossil_flist_insert(flist, const_cast<char*>("char2"));
    fossil_flist_insert(flist, const_cast<char*>("char3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_cchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("cchar"));
    fossil_flist_insert(flist, const_cast<char*>("a"));
    fossil_flist_insert(flist, const_cast<char*>("b"));
    fossil_flist_insert(flist, const_cast<char*>("c"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_wchar) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("wchar"));
    fossil_flist_insert(flist, const_cast<char*>("wa"));
    fossil_flist_insert(flist, const_cast<char*>("wb"));
    fossil_flist_insert(flist, const_cast<char*>("wc"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_bool) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("bool"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    fossil_flist_insert(flist, const_cast<char*>("false"));
    fossil_flist_insert(flist, const_cast<char*>("true"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_size) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("size"));
    fossil_flist_insert(flist, const_cast<char*>("1024"));
    fossil_flist_insert(flist, const_cast<char*>("2048"));
    fossil_flist_insert(flist, const_cast<char*>("4096"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_multiple_removes_any) {
    fossil_flist_t* flist = fossil_flist_create_container(const_cast<char*>("any"));
    fossil_flist_insert(flist, const_cast<char*>("value1"));
    fossil_flist_insert(flist, const_cast<char*>("value2"));
    fossil_flist_insert(flist, const_cast<char*>("value3"));
    fossil_flist_remove(flist);
    fossil_flist_remove(flist);
    ASSUME_ITS_TRUE(fossil_flist_size(flist) == 1);
    fossil_flist_destroy(flist);
}

FOSSIL_TEST_CASE(cpp_test_flist_class_insert_and_get) {
    fossil::tofu::FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    ASSUME_ITS_TRUE(flist.size() == 3);
    ASSUME_ITS_TRUE(flist.get(0) == "10");
    ASSUME_ITS_TRUE(flist.get(1) == "20");
    ASSUME_ITS_TRUE(flist.get(2) == "30");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_remove) {
    fossil::tofu::FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    flist.remove();
    ASSUME_ITS_TRUE(flist.size() == 2);
    ASSUME_ITS_TRUE(flist.get(0) == "10");
    ASSUME_ITS_TRUE(flist.get(1) == "20");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_reverse_forward) {
    fossil::tofu::FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    flist.reverse_forward();
    ASSUME_ITS_TRUE(flist.get(0) == "30");
    ASSUME_ITS_TRUE(flist.get(1) == "20");
    ASSUME_ITS_TRUE(flist.get(2) == "10");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_reverse_backward) {
    fossil::tofu::FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    flist.reverse_backward();
    ASSUME_ITS_TRUE(flist.get(0) == "30");
    ASSUME_ITS_TRUE(flist.get(1) == "20");
    ASSUME_ITS_TRUE(flist.get(2) == "10");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_set_and_get) {
    fossil::tofu::FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    flist.set(1, "25");
    ASSUME_ITS_TRUE(flist.get(0) == "10");
    ASSUME_ITS_TRUE(flist.get(1) == "25");
    ASSUME_ITS_TRUE(flist.get(2) == "30");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_set_front_and_back) {
    fossil::tofu::FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    flist.set_front("5");
    flist.set_back("35");
    ASSUME_ITS_TRUE(flist.get_front() == "5");
    ASSUME_ITS_TRUE(flist.get_back() == "35");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_is_empty) {
    fossil::tofu::FList flist("i32");
    ASSUME_ITS_TRUE(flist.is_empty());
    flist.insert("10");
    ASSUME_ITS_TRUE(!flist.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_flist_class_not_empty) {
    fossil::tofu::FList flist("i32");
    ASSUME_ITS_TRUE(!flist.not_empty());
    flist.insert("10");
    ASSUME_ITS_TRUE(flist.not_empty());
}

FOSSIL_TEST_CASE(cpp_test_flist_class_get_front_and_back) {
    fossil::tofu::FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    ASSUME_ITS_TRUE(flist.get_front() == "10");
    ASSUME_ITS_TRUE(flist.get_back() == "30");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_copy_constructor) {
    fossil::tofu::FList flist1("i32");
    flist1.insert("10");
    flist1.insert("20");
    fossil::tofu::FList flist2(flist1);
    ASSUME_ITS_TRUE(flist2.size() == 2);
    ASSUME_ITS_TRUE(flist2.get(0) == "10");
    ASSUME_ITS_TRUE(flist2.get(1) == "20");
}

FOSSIL_TEST_CASE(cpp_test_flist_class_move_constructor) {
    fossil::tofu::FList flist1("i32");
    flist1.insert("10");
    flist1.insert("20");
    fossil::tofu::FList flist2(std::move(flist1));
    ASSUME_ITS_TRUE(flist2.size() == 2);
    ASSUME_ITS_TRUE(flist2.get(0) == "10");
    ASSUME_ITS_TRUE(flist2.get(1) == "20");
    ASSUME_ITS_TRUE(flist1.is_cnullptr());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_flist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_i32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_empty_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_i32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_not_cnullptr_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_empty_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_is_cnullptr);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_i32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_i32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_i32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_size_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_inserts_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_i8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_i16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_i64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_u8);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_u16);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_u32);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_u64);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_hex);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_octal);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_float);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_double);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_wstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_cstr);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_cchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_wchar);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_bool);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_multiple_removes_any);

    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_insert_and_get);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_remove);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_reverse_forward);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_reverse_backward);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_set_and_get);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_set_front_and_back);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_is_empty);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_not_empty);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_get_front_and_back);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_copy_constructor);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_class_move_constructor);

    FOSSIL_TEST_REGISTER(cpp_flist_tofu_fixture);
} // end of tests
