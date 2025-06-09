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

FOSSIL_SUITE(c_mapof_tofu_fixture);

FOSSIL_SETUP(c_mapof_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_mapof_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_mapof_insert_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1", "10") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100", "200") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1000", "2000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100000", "200000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1", "10") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100", "200") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1000", "2000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100000", "200000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "0x1A", "0x2B") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "012", "023") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1.23", "4.56") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1.234567", "8.9101112") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "wide_key", "wide_value") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key", "value") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "a", "b") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "L'a'", "L'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "true", "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1024", "2048") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key", "value") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    fossil_mapof_insert(map, "0x1A", "0x2B");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "0x1A") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    fossil_mapof_insert(map, "012", "023");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "012") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    fossil_mapof_insert(map, "1.23", "4.56");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1.23") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1.234567") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    fossil_mapof_insert(map, "wide_key", "wide_value");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "wide_key") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "key") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    fossil_mapof_insert(map, "a", "b");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "a") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    fossil_mapof_insert(map, "L'a'", "L'b'");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "L'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    fossil_mapof_insert(map, "true", "false");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    fossil_mapof_insert(map, "1024", "2048");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "key") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "2") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "100") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "101") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1000") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1001") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "100000") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "100001") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "2") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "100") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "101") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1000") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1001") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "100000") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "100001") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    fossil_mapof_insert(map, "0x1A", "0x2B");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "0x1A") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "0x1B") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    fossil_mapof_insert(map, "012", "023");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "012") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "013") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    fossil_mapof_insert(map, "1.23", "4.56");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1.23") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1.24") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1.234567") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1.234568") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    fossil_mapof_insert(map, "wide_key", "wide_value");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "wide_key") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "other_key") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    fossil_mapof_insert(map, "key1", "value1");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "key1") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "key2") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    fossil_mapof_insert(map, "a", "b");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "a") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "c") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    fossil_mapof_insert(map, "L'a'", "L'b'");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "L'a'") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "L'c'") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    fossil_mapof_insert(map, "true", "false");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "true") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "false") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    fossil_mapof_insert(map, "1024", "2048");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "1024") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "2049") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_contains_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "key") == true);
    ASSUME_ITS_TRUE(fossil_mapof_contains(map, "other_key") == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    fossil_mapof_insert(map, "1", "10");
    fossil_tofu_t value = fossil_mapof_get(map, "1");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "10") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    fossil_mapof_insert(map, "100", "200");
    fossil_tofu_t value = fossil_mapof_get(map, "100");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "200") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    fossil_mapof_insert(map, "1000", "2000");
    fossil_tofu_t value = fossil_mapof_get(map, "1000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "2000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    fossil_mapof_insert(map, "100000", "200000");
    fossil_tofu_t value = fossil_mapof_get(map, "100000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "200000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    fossil_mapof_insert(map, "1", "10");
    fossil_tofu_t value = fossil_mapof_get(map, "1");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "10") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    fossil_mapof_insert(map, "100", "200");
    fossil_tofu_t value = fossil_mapof_get(map, "100");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "200") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    fossil_mapof_insert(map, "1000", "2000");
    fossil_tofu_t value = fossil_mapof_get(map, "1000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "2000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    fossil_mapof_insert(map, "100000", "200000");
    fossil_tofu_t value = fossil_mapof_get(map, "100000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "200000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    fossil_mapof_insert(map, "0x1A", "0x2B");
    fossil_tofu_t value = fossil_mapof_get(map, "0x1A");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "0x2B") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    fossil_mapof_insert(map, "012", "023");
    fossil_tofu_t value = fossil_mapof_get(map, "012");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "023") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    fossil_mapof_insert(map, "1.23", "4.56");
    fossil_tofu_t value = fossil_mapof_get(map, "1.23");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "4.56") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    fossil_tofu_t value = fossil_mapof_get(map, "1.234567");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "8.9101112") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    fossil_mapof_insert(map, "wide_key", "wide_value");
    fossil_tofu_t value = fossil_mapof_get(map, "wide_key");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "wide_value") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    fossil_mapof_insert(map, "key", "value");
    fossil_tofu_t value = fossil_mapof_get(map, "key");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "value") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    fossil_mapof_insert(map, "a", "b");
    fossil_tofu_t value = fossil_mapof_get(map, "a");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "b") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    fossil_mapof_insert(map, "L'a'", "L'b'");
    fossil_tofu_t value = fossil_mapof_get(map, "L'a'");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "L'b'") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    fossil_mapof_insert(map, "true", "false");
    fossil_tofu_t value = fossil_mapof_get(map, "true");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "false") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    fossil_mapof_insert(map, "1024", "2048");
    fossil_tofu_t value = fossil_mapof_get(map, "1024");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "2048") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_get_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    fossil_mapof_insert(map, "key", "value");
    fossil_tofu_t value = fossil_mapof_get(map, "key");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "value") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "1", "20") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "1");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "20") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "100", "300") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "100");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "300") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "1000", "3000") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "1000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "3000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "100000", "300000") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "100000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "300000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "1", "20") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "1");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "20") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "100", "300") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "100");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "300") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "1000", "3000") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "1000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "3000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "100000", "300000") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "100000");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "300000") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    fossil_mapof_insert(map, "0x1A", "0x2B");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "0x1A", "0x3C") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "0x1A");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "0x3C") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    fossil_mapof_insert(map, "012", "023");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "012", "034") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "012");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "034") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    fossil_mapof_insert(map, "1.23", "4.56");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "1.23", "7.89") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "1.23");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "7.89") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "1.234567", "3.1415926") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "1.234567");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "3.1415926") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    fossil_mapof_insert(map, "wide_key", "wide_value");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "wide_key", "new_value") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "wide_key");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "new_value") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "key", "new_value") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "key");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "new_value") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    fossil_mapof_insert(map, "a", "b");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "a", "c") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "a");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "c") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    fossil_mapof_insert(map, "L'a'", "L'b'");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "L'a'", "L'c'") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "L'a'");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "L'c'") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    fossil_mapof_insert(map, "true", "false");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "true", "true") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "true");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "true") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    fossil_mapof_insert(map, "1024", "2048");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "1024", "4096") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "1024");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "4096") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_set_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_set(map, "key", "new_value") == FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t value = fossil_mapof_get(map, "key");
    ASSUME_ITS_TRUE(strcmp(fossil_tofu_get_value(&value), "new_value") == 0);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    fossil_mapof_insert(map, "1", "10");
    fossil_mapof_insert(map, "2", "20");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    fossil_mapof_insert(map, "100", "200");
    fossil_mapof_insert(map, "200", "400");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    fossil_mapof_insert(map, "1000", "2000");
    fossil_mapof_insert(map, "2000", "4000");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    fossil_mapof_insert(map, "100000", "200000");
    fossil_mapof_insert(map, "200000", "400000");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    fossil_mapof_insert(map, "1", "10");
    fossil_mapof_insert(map, "2", "20");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    fossil_mapof_insert(map, "100", "200");
    fossil_mapof_insert(map, "200", "400");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    fossil_mapof_insert(map, "1000", "2000");
    fossil_mapof_insert(map, "2000", "4000");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    fossil_mapof_insert(map, "100000", "200000");
    fossil_mapof_insert(map, "200000", "400000");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    fossil_mapof_insert(map, "0x1A", "0x2B");
    fossil_mapof_insert(map, "0x3C", "0x4D");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    fossil_mapof_insert(map, "012", "023");
    fossil_mapof_insert(map, "034", "045");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    fossil_mapof_insert(map, "1.23", "4.56");
    fossil_mapof_insert(map, "7.89", "0.12");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    fossil_mapof_insert(map, "3.1415926", "2.7182818");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    fossil_mapof_insert(map, "wide_key1", "wide_value1");
    fossil_mapof_insert(map, "wide_key2", "wide_value2");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    fossil_mapof_insert(map, "key1", "value1");
    fossil_mapof_insert(map, "key2", "value2");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    fossil_mapof_insert(map, "a", "b");
    fossil_mapof_insert(map, "c", "d");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    fossil_mapof_insert(map, "L'a'", "L'b'");
    fossil_mapof_insert(map, "L'c'", "L'd'");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    fossil_mapof_insert(map, "true", "false");
    fossil_mapof_insert(map, "false", "true");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    fossil_mapof_insert(map, "1024", "2048");
    fossil_mapof_insert(map, "4096", "8192");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_size_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    fossil_mapof_insert(map, "key1", "value1");
    fossil_mapof_insert(map, "key2", "value2");
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 2);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    fossil_mapof_insert(map, "0x1A", "0x2B");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    fossil_mapof_insert(map, "012", "023");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    fossil_mapof_insert(map, "1.23", "4.56");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    fossil_mapof_insert(map, "wide_key", "wide_value");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    fossil_mapof_insert(map, "a", "b");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    fossil_mapof_insert(map, "L'a'", "L'b'");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    fossil_mapof_insert(map, "true", "false");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    fossil_mapof_insert(map, "1024", "2048");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_not_empty_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_not_empty(map) == true);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "1", "10");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "100", "200");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "1000", "2000");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "100000", "200000");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "0x1A", "0x2B");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "012", "023");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "1.23", "4.56");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "wide_key", "wide_value");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "key1", "value1");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "a", "b");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "L'a'", "L'b'");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "true", "false");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "1024", "2048");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_is_empty_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == true);
    fossil_mapof_insert(map, "key", "value");
    ASSUME_ITS_TRUE(fossil_mapof_is_empty(map) == false);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1", "10") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "2", "20") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "3", "30") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100", "200") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "200", "400") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "300", "600") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1000", "2000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "2000", "4000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "3000", "6000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100000", "200000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "200000", "400000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "300000", "600000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1", "10") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "2", "20") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "3", "30") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100", "200") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "200", "400") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "300", "600") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1000", "2000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "2000", "4000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "3000", "6000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "100000", "200000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "200000", "400000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "300000", "600000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "0x1A", "0x2B") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "0x3C", "0x4D") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "0x5E", "0x6F") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "012", "023") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "034", "045") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "056", "067") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1.23", "4.56") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "7.89", "0.12") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "3.45", "6.78") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1.234567", "8.9101112") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "3.1415926", "2.7182818") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "9.8765432", "1.2345678") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "wide_key1", "wide_value1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "wide_key2", "wide_value2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "wide_key3", "wide_value3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key1", "value1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key2", "value2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key3", "value3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "a", "b") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "c", "d") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "e", "f") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "L'a'", "L'b'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "L'c'", "L'd'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "L'e'", "L'f'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "true", "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "false", "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "true", "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "1024", "2048") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "4096", "8192") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "16384", "32768") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_insert_multiple_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key1", "value1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key2", "value2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_insert(map, "key3", "value3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 3);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_i8) {
    fossil_mapof_t* map = fossil_mapof_create_container("i8", "i8");
    fossil_mapof_insert(map, "1", "10");
    fossil_mapof_insert(map, "2", "20");
    fossil_mapof_insert(map, "3", "30");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_i16) {
    fossil_mapof_t* map = fossil_mapof_create_container("i16", "i16");
    fossil_mapof_insert(map, "100", "200");
    fossil_mapof_insert(map, "200", "400");
    fossil_mapof_insert(map, "300", "600");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "200") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_i32) {
    fossil_mapof_t* map = fossil_mapof_create_container("i32", "i32");
    fossil_mapof_insert(map, "1000", "2000");
    fossil_mapof_insert(map, "2000", "4000");
    fossil_mapof_insert(map, "3000", "6000");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "2000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_i64) {
    fossil_mapof_t* map = fossil_mapof_create_container("i64", "i64");
    fossil_mapof_insert(map, "100000", "200000");
    fossil_mapof_insert(map, "200000", "400000");
    fossil_mapof_insert(map, "300000", "600000");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "200000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_u8) {
    fossil_mapof_t* map = fossil_mapof_create_container("u8", "u8");
    fossil_mapof_insert(map, "1", "10");
    fossil_mapof_insert(map, "2", "20");
    fossil_mapof_insert(map, "3", "30");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_u16) {
    fossil_mapof_t* map = fossil_mapof_create_container("u16", "u16");
    fossil_mapof_insert(map, "100", "200");
    fossil_mapof_insert(map, "200", "400");
    fossil_mapof_insert(map, "300", "600");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "200") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_u32) {
    fossil_mapof_t* map = fossil_mapof_create_container("u32", "u32");
    fossil_mapof_insert(map, "1000", "2000");
    fossil_mapof_insert(map, "2000", "4000");
    fossil_mapof_insert(map, "3000", "6000");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "2000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_u64) {
    fossil_mapof_t* map = fossil_mapof_create_container("u64", "u64");
    fossil_mapof_insert(map, "100000", "200000");
    fossil_mapof_insert(map, "200000", "400000");
    fossil_mapof_insert(map, "300000", "600000");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "100000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "200000") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_hex) {
    fossil_mapof_t* map = fossil_mapof_create_container("hex", "hex");
    fossil_mapof_insert(map, "0x1A", "0x2B");
    fossil_mapof_insert(map, "0x3C", "0x4D");
    fossil_mapof_insert(map, "0x5E", "0x6F");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "0x1A") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "0x3C") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_octal) {
    fossil_mapof_t* map = fossil_mapof_create_container("octal", "octal");
    fossil_mapof_insert(map, "012", "023");
    fossil_mapof_insert(map, "034", "045");
    fossil_mapof_insert(map, "056", "067");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "012") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "034") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_float) {
    fossil_mapof_t* map = fossil_mapof_create_container("float", "float");
    fossil_mapof_insert(map, "1.23", "4.56");
    fossil_mapof_insert(map, "7.89", "0.12");
    fossil_mapof_insert(map, "3.45", "6.78");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1.23") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "7.89") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_double) {
    fossil_mapof_t* map = fossil_mapof_create_container("double", "double");
    fossil_mapof_insert(map, "1.234567", "8.9101112");
    fossil_mapof_insert(map, "3.1415926", "2.7182818");
    fossil_mapof_insert(map, "9.8765432", "1.2345678");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1.234567") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "3.1415926") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_wstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("wstr", "wstr");
    fossil_mapof_insert(map, "wide_key1", "wide_value1");
    fossil_mapof_insert(map, "wide_key2", "wide_value2");
    fossil_mapof_insert(map, "wide_key3", "wide_value3");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "wide_key1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "wide_key2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_cstr) {
    fossil_mapof_t* map = fossil_mapof_create_container("cstr", "cstr");
    fossil_mapof_insert(map, "key1", "value1");
    fossil_mapof_insert(map, "key2", "value2");
    fossil_mapof_insert(map, "key3", "value3");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "key1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "key2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_cchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("cchar", "cchar");
    fossil_mapof_insert(map, "a", "b");
    fossil_mapof_insert(map, "c", "d");
    fossil_mapof_insert(map, "e", "f");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "a") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "c") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_wchar) {
    fossil_mapof_t* map = fossil_mapof_create_container("wchar", "wchar");
    fossil_mapof_insert(map, "L'a'", "L'b'");
    fossil_mapof_insert(map, "L'c'", "L'd'");
    fossil_mapof_insert(map, "L'e'", "L'f'");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "L'a'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "L'c'") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_bool) {
    fossil_mapof_t* map = fossil_mapof_create_container("bool", "bool");
    fossil_mapof_insert(map, "true", "false");
    fossil_mapof_insert(map, "false", "true");
    fossil_mapof_insert(map, "true", "true");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "true") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_size) {
    fossil_mapof_t* map = fossil_mapof_create_container("size", "size");
    fossil_mapof_insert(map, "1024", "2048");
    fossil_mapof_insert(map, "4096", "8192");
    fossil_mapof_insert(map, "16384", "32768");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "1024") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "4096") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

FOSSIL_TEST(c_test_mapof_remove_multiple_any) {
    fossil_mapof_t* map = fossil_mapof_create_container("any", "any");
    fossil_mapof_insert(map, "key1", "value1");
    fossil_mapof_insert(map, "key2", "value2");
    fossil_mapof_insert(map, "key3", "value3");

    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "key1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_remove(map, "key2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_mapof_size(map) == 1);
    fossil_mapof_destroy(map);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_mapof_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_contains_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_get_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_set_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_size_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_not_empty_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_is_empty_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_insert_multiple_any);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_i8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_i16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_i32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_i64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_u8);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_u16);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_u32);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_u64);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_hex);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_octal);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_float);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_double);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_wstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_cstr);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_cchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_wchar);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_bool);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_size);
    FOSSIL_TEST_ADD(c_mapof_tofu_fixture, c_test_mapof_remove_multiple_any);

    FOSSIL_TEST_REGISTER(c_mapof_tofu_fixture);
} // end of tests
