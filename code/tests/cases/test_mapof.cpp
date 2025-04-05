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

FOSSIL_TEST_SUITE(cpp_mapof_tofu_fixture);

FOSSIL_SETUP(cpp_mapof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_mapof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_mapof_insert_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("wide_key"), const_cast<char*>("wide_value")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("0x1A")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("012")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1.23")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1.234567")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key"), const_cast<char*>("wide_value"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("wide_key")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("key")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("a")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("L'a'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("key")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("2")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("100")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("101")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1000")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1001")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("100000")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("100001")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("2")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("100")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("101")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1000")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1001")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("100000")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("100001")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("0x1A")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("0x1B")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("012")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("013")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1.23")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1.24")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1.234567")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1.234568")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key"), const_cast<char*>("wide_value"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("wide_key")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("other_key")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("key1")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("key2")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("a")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("c")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("L'a'")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("L'c'")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("true")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("false")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("1024")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("2049")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_contains_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("key")) == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, const_cast<char*>("other_key")) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("10")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("200")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("2000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("200000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("10")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("200")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("2000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("200000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("0x1A"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("0x2B")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("012"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("023")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1.23"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("4.56")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1.234567"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("8.9101112")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key"), const_cast<char*>("wide_value"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("wide_key"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("wide_value")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("key"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("value")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("a"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("b")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("L'a'"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("L'b'")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("false")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("2048")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_get_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("key"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("value")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("1"), const_cast<char*>("20")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("20")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("100"), const_cast<char*>("300")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("300")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("1000"), const_cast<char*>("3000")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("3000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("100000"), const_cast<char*>("300000")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("300000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("1"), const_cast<char*>("20")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("20")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("100"), const_cast<char*>("300")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("300")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("1000"), const_cast<char*>("3000")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("3000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("100000"), const_cast<char*>("300000")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("100000"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("300000")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("0x1A"), const_cast<char*>("0x3C")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("0x1A"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("0x3C")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("012"), const_cast<char*>("034")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("012"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("034")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("1.23"), const_cast<char*>("7.89")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1.23"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("7.89")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("1.234567"), const_cast<char*>("3.1415926")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1.234567"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("3.1415926")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key"), const_cast<char*>("wide_value"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("wide_key"), const_cast<char*>("new_value")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("wide_key"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("new_value")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("key"), const_cast<char*>("new_value")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("key"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("new_value")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("a"), const_cast<char*>("c")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("a"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("c")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("L'a'"), const_cast<char*>("L'c'")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("L'a'"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("L'c'")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("true"), const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("true"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("true")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("1024"), const_cast<char*>("4096")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("4096")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_set_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_set(map, const_cast<char*>("key"), const_cast<char*>("new_value")) == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, const_cast<char*>("key"));
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), const_cast<char*>("new_value")) == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    fossil_mapof_insert(map, const_cast<char*>("2"), const_cast<char*>("20"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    fossil_mapof_insert(map, const_cast<char*>("200"), const_cast<char*>("400"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    fossil_mapof_insert(map, const_cast<char*>("2000"), const_cast<char*>("4000"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    fossil_mapof_insert(map, const_cast<char*>("200000"), const_cast<char*>("400000"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    fossil_mapof_insert(map, const_cast<char*>("2"), const_cast<char*>("20"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    fossil_mapof_insert(map, const_cast<char*>("200"), const_cast<char*>("400"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    fossil_mapof_insert(map, const_cast<char*>("2000"), const_cast<char*>("4000"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    fossil_mapof_insert(map, const_cast<char*>("200000"), const_cast<char*>("400000"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    fossil_mapof_insert(map, const_cast<char*>("0x3C"), const_cast<char*>("0x4D"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    fossil_mapof_insert(map, const_cast<char*>("034"), const_cast<char*>("045"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    fossil_mapof_insert(map, const_cast<char*>("7.89"), const_cast<char*>("0.12"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    fossil_mapof_insert(map, const_cast<char*>("3.1415926"), const_cast<char*>("2.7182818"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key1"), const_cast<char*>("wide_value1"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key2"), const_cast<char*>("wide_value2"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1"));
    fossil_mapof_insert(map, const_cast<char*>("key2"), const_cast<char*>("value2"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    fossil_mapof_insert(map, const_cast<char*>("c"), const_cast<char*>("d"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    fossil_mapof_insert(map, const_cast<char*>("L'c'"), const_cast<char*>("L'd'"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    fossil_mapof_insert(map, const_cast<char*>("false"), const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    fossil_mapof_insert(map, const_cast<char*>("4096"), const_cast<char*>("8192"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_size_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1"));
    fossil_mapof_insert(map, const_cast<char*>("key2"), const_cast<char*>("value2"));
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key"), const_cast<char*>("wide_value"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_not_empty_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("wide_key"), const_cast<char*>("wide_value"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_is_empty_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, const_cast<char*>("key"), const_cast<char*>("value"));
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("2"), const_cast<char*>("20")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("3"), const_cast<char*>("30")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("200"), const_cast<char*>("400")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("300"), const_cast<char*>("600")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("2000"), const_cast<char*>("4000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("3000"), const_cast<char*>("6000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("200000"), const_cast<char*>("400000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("300000"), const_cast<char*>("600000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("2"), const_cast<char*>("20")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("3"), const_cast<char*>("30")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("200"), const_cast<char*>("400")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("300"), const_cast<char*>("600")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("2000"), const_cast<char*>("4000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("3000"), const_cast<char*>("6000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("200000"), const_cast<char*>("400000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("300000"), const_cast<char*>("600000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("0x3C"), const_cast<char*>("0x4D")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("0x5E"), const_cast<char*>("0x6F")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("034"), const_cast<char*>("045")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("056"), const_cast<char*>("067")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("7.89"), const_cast<char*>("0.12")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("3.45"), const_cast<char*>("6.78")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("3.1415926"), const_cast<char*>("2.7182818")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("9.8765432"), const_cast<char*>("1.2345678")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("wide_key1"), const_cast<char*>("wide_value1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("wide_key2"), const_cast<char*>("wide_value2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("wide_key3"), const_cast<char*>("wide_value3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key2"), const_cast<char*>("value2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key3"), const_cast<char*>("value3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("c"), const_cast<char*>("d")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("e"), const_cast<char*>("f")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("L'c'"), const_cast<char*>("L'd'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("L'e'"), const_cast<char*>("L'f'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("false"), const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("4096"), const_cast<char*>("8192")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("16384"), const_cast<char*>("32768")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_insert_multiple_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key2"), const_cast<char*>("value2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, const_cast<char*>("key3"), const_cast<char*>("value3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i8"), const_cast<char*>("i8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    fossil_mapof_insert(map, const_cast<char*>("2"), const_cast<char*>("20"));
    fossil_mapof_insert(map, const_cast<char*>("3"), const_cast<char*>("30"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i16"), const_cast<char*>("i16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    fossil_mapof_insert(map, const_cast<char*>("200"), const_cast<char*>("400"));
    fossil_mapof_insert(map, const_cast<char*>("300"), const_cast<char*>("600"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("200")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i32"), const_cast<char*>("i32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    fossil_mapof_insert(map, const_cast<char*>("2000"), const_cast<char*>("4000"));
    fossil_mapof_insert(map, const_cast<char*>("3000"), const_cast<char*>("6000"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("2000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("i64"), const_cast<char*>("i64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    fossil_mapof_insert(map, const_cast<char*>("200000"), const_cast<char*>("400000"));
    fossil_mapof_insert(map, const_cast<char*>("300000"), const_cast<char*>("600000"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("200000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u8"), const_cast<char*>("u8"));
    fossil_mapof_insert(map, const_cast<char*>("1"), const_cast<char*>("10"));
    fossil_mapof_insert(map, const_cast<char*>("2"), const_cast<char*>("20"));
    fossil_mapof_insert(map, const_cast<char*>("3"), const_cast<char*>("30"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u16"), const_cast<char*>("u16"));
    fossil_mapof_insert(map, const_cast<char*>("100"), const_cast<char*>("200"));
    fossil_mapof_insert(map, const_cast<char*>("200"), const_cast<char*>("400"));
    fossil_mapof_insert(map, const_cast<char*>("300"), const_cast<char*>("600"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("200")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u32"), const_cast<char*>("u32"));
    fossil_mapof_insert(map, const_cast<char*>("1000"), const_cast<char*>("2000"));
    fossil_mapof_insert(map, const_cast<char*>("2000"), const_cast<char*>("4000"));
    fossil_mapof_insert(map, const_cast<char*>("3000"), const_cast<char*>("6000"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("2000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("u64"), const_cast<char*>("u64"));
    fossil_mapof_insert(map, const_cast<char*>("100000"), const_cast<char*>("200000"));
    fossil_mapof_insert(map, const_cast<char*>("200000"), const_cast<char*>("400000"));
    fossil_mapof_insert(map, const_cast<char*>("300000"), const_cast<char*>("600000"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("100000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("200000")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("hex"), const_cast<char*>("hex"));
    fossil_mapof_insert(map, const_cast<char*>("0x1A"), const_cast<char*>("0x2B"));
    fossil_mapof_insert(map, const_cast<char*>("0x3C"), const_cast<char*>("0x4D"));
    fossil_mapof_insert(map, const_cast<char*>("0x5E"), const_cast<char*>("0x6F"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("0x1A")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("0x3C")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("octal"), const_cast<char*>("octal"));
    fossil_mapof_insert(map, const_cast<char*>("012"), const_cast<char*>("023"));
    fossil_mapof_insert(map, const_cast<char*>("034"), const_cast<char*>("045"));
    fossil_mapof_insert(map, const_cast<char*>("056"), const_cast<char*>("067"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("012")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("034")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_float) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("float"), const_cast<char*>("float"));
    fossil_mapof_insert(map, const_cast<char*>("1.23"), const_cast<char*>("4.56"));
    fossil_mapof_insert(map, const_cast<char*>("7.89"), const_cast<char*>("0.12"));
    fossil_mapof_insert(map, const_cast<char*>("3.45"), const_cast<char*>("6.78"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1.23")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("7.89")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_double) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("double"), const_cast<char*>("double"));
    fossil_mapof_insert(map, const_cast<char*>("1.234567"), const_cast<char*>("8.9101112"));
    fossil_mapof_insert(map, const_cast<char*>("3.1415926"), const_cast<char*>("2.7182818"));
    fossil_mapof_insert(map, const_cast<char*>("9.8765432"), const_cast<char*>("1.2345678"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1.234567")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("3.1415926")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wstr"), const_cast<char*>("wstr"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key1"), const_cast<char*>("wide_value1"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key2"), const_cast<char*>("wide_value2"));
    fossil_mapof_insert(map, const_cast<char*>("wide_key3"), const_cast<char*>("wide_value3"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("wide_key1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("wide_key2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cstr"), const_cast<char*>("cstr"));
    fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1"));
    fossil_mapof_insert(map, const_cast<char*>("key2"), const_cast<char*>("value2"));
    fossil_mapof_insert(map, const_cast<char*>("key3"), const_cast<char*>("value3"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("key1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("key2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("cchar"), const_cast<char*>("cchar"));
    fossil_mapof_insert(map, const_cast<char*>("a"), const_cast<char*>("b"));
    fossil_mapof_insert(map, const_cast<char*>("c"), const_cast<char*>("d"));
    fossil_mapof_insert(map, const_cast<char*>("e"), const_cast<char*>("f"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("a")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("c")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("wchar"), const_cast<char*>("wchar"));
    fossil_mapof_insert(map, const_cast<char*>("L'a'"), const_cast<char*>("L'b'"));
    fossil_mapof_insert(map, const_cast<char*>("L'c'"), const_cast<char*>("L'd'"));
    fossil_mapof_insert(map, const_cast<char*>("L'e'"), const_cast<char*>("L'f'"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("L'a'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("L'c'")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("bool"), const_cast<char*>("bool"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("false"));
    fossil_mapof_insert(map, const_cast<char*>("false"), const_cast<char*>("true"));
    fossil_mapof_insert(map, const_cast<char*>("true"), const_cast<char*>("true"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("true")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("false")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_size) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("size"), const_cast<char*>("size"));
    fossil_mapof_insert(map, const_cast<char*>("1024"), const_cast<char*>("2048"));
    fossil_mapof_insert(map, const_cast<char*>("4096"), const_cast<char*>("8192"));
    fossil_mapof_insert(map, const_cast<char*>("16384"), const_cast<char*>("32768"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("1024")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("4096")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST_CASE(cpp_test_mapof_remove_multiple_any) {
    fossil_mapof_t* map = fossil_mapof_create_container(const_cast<char*>("any"), const_cast<char*>("any"));
    fossil_mapof_insert(map, const_cast<char*>("key1"), const_cast<char*>("value1"));
    fossil_mapof_insert(map, const_cast<char*>("key2"), const_cast<char*>("value2"));
    fossil_mapof_insert(map, const_cast<char*>("key3"), const_cast<char*>("value3"));

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("key1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, const_cast<char*>("key2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_mapof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_contains_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_get_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_set_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_size_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_not_empty_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_is_empty_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_insert_multiple_any);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_i8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_i16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_i32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_i64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_u8);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_u16);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_u32);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_u64);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_hex);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_octal);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_float);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_double);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_wstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_cstr);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_cchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_wchar);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_bool);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_size);
    FOSSIL_TEST_ADD(cpp_mapof_tofu_fixture, cpp_test_mapof_remove_multiple_any);

    FOSSIL_TEST_REGISTER(cpp_mapof_tofu_fixture);
} // end of tests
