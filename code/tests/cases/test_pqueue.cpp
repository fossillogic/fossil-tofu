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

FOSSIL_SUITE(cpp_pqueue_tofu_fixture);

FOSSIL_SETUP(cpp_pqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_pqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_test_pqueue_insert_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("2A"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("52"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("wide_string"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("string"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("c"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("w"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("true"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_insert_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i8"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i16"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i32"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i64"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u8"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u16"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u32"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u64"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("hex"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("2A"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("octal"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("52"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("float"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("double"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wstr"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("wide_string"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cstr"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("string"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cchar"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("c"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wchar"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("w"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("bool"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("true"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("size"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_remove_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("any"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i8"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i16"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i32"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i64"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u8"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u16"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u32"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u64"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("hex"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("2A"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("octal"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("52"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("float"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("double"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wstr"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("wide_string"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cstr"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("string"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cchar"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("c"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wchar"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("w"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("bool"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("true"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("size"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("any"));
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_i8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_i16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_i32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_i64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_u8) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_u16) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_u32) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_u64) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_hex) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("2A"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_octal) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("52"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_float) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_double) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42.0"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_wstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("wide_string"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_cstr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("string"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_cchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("c"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_wchar) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("w"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_bool) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("true"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_size) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_empty_any) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char*>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_is_cnullptr) {
    fossil_pqueue_t* pqueue = NULL;
    ASSUME_ITS_TRUE(fossil_pqueue_is_cnullptr(pqueue) == true);
}

FOSSIL_TEST(cpp_test_pqueue_class_insert) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    ASSUME_ITS_TRUE(pqueue.size() == 1);
    ASSUME_ITS_TRUE(pqueue.not_empty());
}

FOSSIL_TEST(cpp_test_pqueue_class_remove) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    pqueue.remove(0);
    ASSUME_ITS_TRUE(pqueue.is_empty());
}

FOSSIL_TEST(cpp_test_pqueue_class_get_front) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    ASSUME_ITS_TRUE(pqueue.get_front() == "42");
}

FOSSIL_TEST(cpp_test_pqueue_class_get_back) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    ASSUME_ITS_TRUE(pqueue.get_back() == "42");
}

FOSSIL_TEST(cpp_test_pqueue_class_get_at) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    ASSUME_ITS_TRUE(pqueue.get_at(0) == "42");
}

FOSSIL_TEST(cpp_test_pqueue_class_set_front) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    pqueue.set_front("84");
    ASSUME_ITS_TRUE(pqueue.get_front() == "84");
}

FOSSIL_TEST(cpp_test_pqueue_class_set_back) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    pqueue.set_back("84");
    ASSUME_ITS_TRUE(pqueue.get_back() == "84");
}

FOSSIL_TEST(cpp_test_pqueue_class_set_at) {
    fossil::tofu::PQueue pqueue("i32");
    pqueue.insert("42", 0);
    pqueue.set_at(0, "84");
    ASSUME_ITS_TRUE(pqueue.get_at(0) == "84");
}

FOSSIL_TEST(cpp_test_pqueue_class_not_cnullptr) {
    fossil::tofu::PQueue pqueue("i32");
    ASSUME_ITS_TRUE(pqueue.not_cnullptr());
}

FOSSIL_TEST(cpp_test_pqueue_class_is_cnullptr) {
    fossil::tofu::PQueue* pqueue = nullptr;
    ASSUME_ITS_TRUE(pqueue == nullptr);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_pqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_i8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_i16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_i32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_i64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_u8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_u16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_u32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_u64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_hex);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_octal);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_float);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_double);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_wstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_cstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_cchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_wchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_bool);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_size);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_any);

    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_i8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_i16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_i32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_i64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_u8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_u16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_u32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_u64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_hex);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_octal);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_float);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_double);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_wstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_cstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_cchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_wchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_bool);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_size);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_any);

    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_i8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_i16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_i32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_i64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_u8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_u16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_u32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_u64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_hex);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_octal);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_float);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_double);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_wstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_cstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_cchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_wchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_bool);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_size);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_any);

    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_i8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_i16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_i32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_i64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_u8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_u16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_u32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_u64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_hex);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_octal);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_float);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_double);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_wstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_cstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_cchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_wchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_bool);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_size);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_any);

    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_i8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_i16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_i32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_i64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_u8);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_u16);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_u32);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_u64);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_hex);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_octal);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_float);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_double);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_wstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_cstr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_cchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_wchar);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_bool);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_size);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty_any);

    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_cnullptr);

    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_insert);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_remove);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_get_front);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_get_back);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_get_at);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_set_front);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_set_back);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_set_at);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_class_is_cnullptr);

    FOSSIL_TEST_REGISTER(cpp_pqueue_tofu_fixture);
} // end of tests
