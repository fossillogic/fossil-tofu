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

FOSSIL_TEST_SUITE(c_generic_tofu_fixture);

FOSSIL_SETUP(c_generic_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_generic_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_create_destroy_i8) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "127");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I8);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "127");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_i16) {
    fossil_tofu_t tofu = fossil_tofu_create("i16", "32767");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I16);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "32767");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_i32) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "2147483647");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I32);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "2147483647");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_i64) {
    fossil_tofu_t tofu = fossil_tofu_create("i64", "9223372036854775807");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I64);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "9223372036854775807");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_u8) {
    fossil_tofu_t tofu = fossil_tofu_create("u8", "255");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U8);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "255");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_u16) {
    fossil_tofu_t tofu = fossil_tofu_create("u16", "65535");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U16);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "65535");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_u32) {
    fossil_tofu_t tofu = fossil_tofu_create("u32", "4294967295");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U32);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "4294967295");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_u64) {
    fossil_tofu_t tofu = fossil_tofu_create("u64", "18446744073709551615");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U64);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "18446744073709551615");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_hex) {
    fossil_tofu_t tofu = fossil_tofu_create("hex", "0x1A3F");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_HEX);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "0x1A3F");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_octal) {
    fossil_tofu_t tofu = fossil_tofu_create("octal", "0755");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_OCTAL);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "0755");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_float) {
    fossil_tofu_t tofu = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_FLOAT);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "3.14");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_double) {
    fossil_tofu_t tofu = fossil_tofu_create("double", "2.718281828459");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_DOUBLE);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "2.718281828459");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create("wstr", "Wide String");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_WSTR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "Wide String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create("cstr", "C String");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_CSTR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "C String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create("cchar", "A");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_CCHAR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "A");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create("wchar", "W");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_WCHAR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "W");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_bool) {
    fossil_tofu_t tofu = fossil_tofu_create("bool", "true");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_BOOL);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "true");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_size) {
    fossil_tofu_t tofu = fossil_tofu_create("size", "1024");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_SIZE);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "1024");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_destroy_any) {
    fossil_tofu_t tofu = fossil_tofu_create("any", "Generic Value");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "Generic Value");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_i8) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "127");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "127");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_i16) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "32767");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "32767");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_i32) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "2147483647");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "2147483647");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_i64) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "9223372036854775807");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "9223372036854775807");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_u8) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "255");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "255");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_u16) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "65535");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "65535");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_u32) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "4294967295");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "4294967295");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_u64) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "18446744073709551615");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "18446744073709551615");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_hex) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "0x1A3F");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "0x1A3F");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_octal) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "0755");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "0755");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_float) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "3.14");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "3.14");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_double) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "2.718281828459");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "2.718281828459");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_wstr) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "Wide String");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "Wide String");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_cstr) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "C String");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "C String");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_cchar) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "A");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "A");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_wchar) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "W");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "W");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_bool) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "true");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "true");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_size) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "1024");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "1024");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_default_any) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, "Generic Value");
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "Generic Value");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(c_test_create_copy_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i8", "127");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i16", "32767");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i64", "9223372036854775807");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u8", "255");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u16", "65535");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u32", "4294967295");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u64", "18446744073709551615");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create("hex", "0x1A3F");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create("octal", "0755");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create("float", "3.14");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create("double", "2.718281828459");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wstr", "Wide String");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cstr", "C String");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cchar", "A");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wchar", "W");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create("bool", "true");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create("size", "1024");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_copy_any) {
    fossil_tofu_t tofu1 = fossil_tofu_create("any", "Generic Value");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i8", "127");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i16", "32767");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "2147483647");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i64", "9223372036854775807");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u8", "255");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u16", "65535");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u32", "4294967295");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u64", "18446744073709551615");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create("hex", "0x1A3F");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create("octal", "0755");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create("float", "3.14");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create("double", "2.718281828459");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wstr", "Wide String");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cstr", "C String");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cchar", "A");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wchar", "W");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create("bool", "true");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_create_move_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create("size", "1024");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(c_test_set_get_value_i8) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "42");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "84") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "84");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_i16) {
    fossil_tofu_t tofu = fossil_tofu_create("i16", "32767");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "16384") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "16384");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_i32) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "2147483647");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "1073741824") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "1073741824");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_i64) {
    fossil_tofu_t tofu = fossil_tofu_create("i64", "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "4611686018427387904") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "4611686018427387904");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_u8) {
    fossil_tofu_t tofu = fossil_tofu_create("u8", "255");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "128") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "128");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_u16) {
    fossil_tofu_t tofu = fossil_tofu_create("u16", "65535");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "32768") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "32768");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_u32) {
    fossil_tofu_t tofu = fossil_tofu_create("u32", "4294967295");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "2147483648") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "2147483648");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_u64) {
    fossil_tofu_t tofu = fossil_tofu_create("u64", "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "9223372036854775808") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "9223372036854775808");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_hex) {
    fossil_tofu_t tofu = fossil_tofu_create("hex", "0x1A3F");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "0x2B4E") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "0x2B4E");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_octal) {
    fossil_tofu_t tofu = fossil_tofu_create("octal", "0755");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "0644") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "0644");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_float) {
    fossil_tofu_t tofu = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "2.71") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "2.71");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_double) {
    fossil_tofu_t tofu = fossil_tofu_create("double", "2.718281828459");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "3.141592653589") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "3.141592653589");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create("wstr", "Wide String");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "New Wide String") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "New Wide String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create("cstr", "C String");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "New C String") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "New C String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create("cchar", "A");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "B") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "B");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create("wchar", "W");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "X") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "X");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_bool) {
    fossil_tofu_t tofu = fossil_tofu_create("bool", "true");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "false") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "false");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_size) {
    fossil_tofu_t tofu = fossil_tofu_create("size", "1024");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "2048") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "2048");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_value_any) {
    fossil_tofu_t tofu = fossil_tofu_create("any", "Generic Value");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "New Generic Value") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "New Generic Value");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_i8) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "127");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_i16) {
    fossil_tofu_t tofu = fossil_tofu_create("i16", "32767");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_i32) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "2147483647");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_i64) {
    fossil_tofu_t tofu = fossil_tofu_create("i64", "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_u8) {
    fossil_tofu_t tofu = fossil_tofu_create("u8", "255");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_u16) {
    fossil_tofu_t tofu = fossil_tofu_create("u16", "65535");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_u32) {
    fossil_tofu_t tofu = fossil_tofu_create("u32", "4294967295");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_u64) {
    fossil_tofu_t tofu = fossil_tofu_create("u64", "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_hex) {
    fossil_tofu_t tofu = fossil_tofu_create("hex", "0x1A3F");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_octal) {
    fossil_tofu_t tofu = fossil_tofu_create("octal", "0755");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_float) {
    fossil_tofu_t tofu = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_double) {
    fossil_tofu_t tofu = fossil_tofu_create("double", "2.718281828459");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create("wstr", "Wide String");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create("cstr", "C String");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create("cchar", "A");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create("wchar", "W");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_bool) {
    fossil_tofu_t tofu = fossil_tofu_create("bool", "true");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_size) {
    fossil_tofu_t tofu = fossil_tofu_create("size", "1024");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_mutability_any) {
    fossil_tofu_t tofu = fossil_tofu_create("any", "Generic Value");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_i8) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "42");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_i16) {
    fossil_tofu_t tofu = fossil_tofu_create("i16", "32767");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_i32) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_i64) {
    fossil_tofu_t tofu = fossil_tofu_create("i64", "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_u8) {
    fossil_tofu_t tofu = fossil_tofu_create("u8", "255");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_u16) {
    fossil_tofu_t tofu = fossil_tofu_create("u16", "65535");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_u32) {
    fossil_tofu_t tofu = fossil_tofu_create("u32", "4294967295");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_u64) {
    fossil_tofu_t tofu = fossil_tofu_create("u64", "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_hex) {
    fossil_tofu_t tofu = fossil_tofu_create("hex", "0x1A3F");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_octal) {
    fossil_tofu_t tofu = fossil_tofu_create("octal", "0755");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_float) {
    fossil_tofu_t tofu = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_double) {
    fossil_tofu_t tofu = fossil_tofu_create("double", "2.718281828459");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create("wstr", "Wide String");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create("cstr", "C String");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create("cchar", "A");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create("wchar", "W");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_bool) {
    fossil_tofu_t tofu = fossil_tofu_create("bool", "true");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_size) {
    fossil_tofu_t tofu = fossil_tofu_create("size", "1024");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_set_get_attribute_any) {
    fossil_tofu_t tofu = fossil_tofu_create("any", "Generic Value");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(c_test_equals_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i8", "127");
    fossil_tofu_t tofu2 = fossil_tofu_create("i8", "127");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i16", "32767");
    fossil_tofu_t tofu2 = fossil_tofu_create("i16", "32767");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "2147483647");
    fossil_tofu_t tofu2 = fossil_tofu_create("i32", "2147483647");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i64", "9223372036854775807");
    fossil_tofu_t tofu2 = fossil_tofu_create("i64", "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u8", "255");
    fossil_tofu_t tofu2 = fossil_tofu_create("u8", "255");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u16", "65535");
    fossil_tofu_t tofu2 = fossil_tofu_create("u16", "65535");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u32", "4294967295");
    fossil_tofu_t tofu2 = fossil_tofu_create("u32", "4294967295");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u64", "18446744073709551615");
    fossil_tofu_t tofu2 = fossil_tofu_create("u64", "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create("hex", "0x1A3F");
    fossil_tofu_t tofu2 = fossil_tofu_create("hex", "0x1A3F");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create("octal", "0755");
    fossil_tofu_t tofu2 = fossil_tofu_create("octal", "0755");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create("float", "3.14");
    fossil_tofu_t tofu2 = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create("double", "2.718281828459");
    fossil_tofu_t tofu2 = fossil_tofu_create("double", "2.718281828459");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wstr", "Wide String");
    fossil_tofu_t tofu2 = fossil_tofu_create("wstr", "Wide String");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cstr", "C String");
    fossil_tofu_t tofu2 = fossil_tofu_create("cstr", "C String");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cchar", "A");
    fossil_tofu_t tofu2 = fossil_tofu_create("cchar", "A");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wchar", "W");
    fossil_tofu_t tofu2 = fossil_tofu_create("wchar", "W");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create("bool", "true");
    fossil_tofu_t tofu2 = fossil_tofu_create("bool", "true");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create("size", "1024");
    fossil_tofu_t tofu2 = fossil_tofu_create("size", "1024");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_equals_any) {
    fossil_tofu_t tofu1 = fossil_tofu_create("any", "Generic Value");
    fossil_tofu_t tofu2 = fossil_tofu_create("any", "Generic Value");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i8", "127");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i16", "32767");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i64", "9223372036854775807");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u8", "255");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u16", "65535");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u32", "4294967295");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create("u64", "18446744073709551615");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create("hex", "0x1A3F");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create("octal", "0755");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create("float", "3.14");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create("double", "2.718281828459");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wstr", "Wide String");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cstr", "C String");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("cchar", "A");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create("wchar", "W");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create("bool", "true");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create("size", "1024");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(c_test_copy_any) {
    fossil_tofu_t tofu1 = fossil_tofu_create("any", "Generic Value");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_size);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_destroy_any);

    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_size);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_default_any);

    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_move_size);

    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_size);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_create_copy_any);

    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_size);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_set_get_attribute_any);

    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_size);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_mutability_any);

    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_size);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_equals_any);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_i8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_i16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_i32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_i64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_u8);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_u16);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_u32);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_u64);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_hex);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_octal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_float);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_double);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_wstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_cstr);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_cchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_wchar);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_bool);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_size);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_copy_any);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_generic_tofu_fixture);
} // end of tests
