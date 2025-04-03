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

FOSSIL_TEST_SUITE(cpp_generic_tofu_fixture);

FOSSIL_SETUP(cpp_generic_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_generic_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_create_destroy_i8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("127"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I8);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "127");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_i16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I16);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "32767");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_i32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("2147483647"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I32);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "2147483647");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_i64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I64);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "9223372036854775807");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_u8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U8);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "255");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_u16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U16);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "65535");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_u32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U32);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "4294967295");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_u64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_U64);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "18446744073709551615");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_hex) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_HEX);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "0x1A3F");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_octal) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_OCTAL);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "0755");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_float) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_FLOAT);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "3.14");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_double) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_DOUBLE);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "2.718281828459");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_WSTR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "Wide String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_CSTR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "C String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_CCHAR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "A");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_WCHAR);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "W");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_bool) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_BOOL);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "true");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_size) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_SIZE);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "1024");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_destroy_any) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "Generic Value");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_i8) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("127"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "127");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_i16) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("32767"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "32767");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_i32) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("2147483647"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "2147483647");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_i64) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "9223372036854775807");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_u8) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("255"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "255");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_u16) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("65535"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "65535");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_u32) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("4294967295"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "4294967295");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_u64) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "18446744073709551615");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_hex) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("0x1A3F"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "0x1A3F");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_octal) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("0755"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "0755");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_float) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("3.14"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "3.14");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_double) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("2.718281828459"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "2.718281828459");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_wstr) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("Wide String"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "Wide String");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_cstr) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("C String"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "C String");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_cchar) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("A"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "A");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_wchar) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("W"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "W");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_bool) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("true"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "true");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_size) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("1024"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "1024");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default_any) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != nullptr);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_set_value(tofu, const_cast<char*>("Generic Value"));
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "Generic Value");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("127"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_copy_any) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("127"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("2147483647"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != nullptr);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == nullptr);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_i8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("84")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "84");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_i16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("16384")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "16384");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_i32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("2147483647"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("1073741824")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "1073741824");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_i64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("4611686018427387904")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "4611686018427387904");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_u8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("128")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "128");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_u16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("32768")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "32768");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_u32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("2147483648")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "2147483648");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_u64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("9223372036854775808")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "9223372036854775808");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_hex) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("0x2B4E")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "0x2B4E");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_octal) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("0644")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "0644");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_float) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("2.71")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "2.71");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_double) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("3.141592653589")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "3.141592653589");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("New Wide String")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "New Wide String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("New C String")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "New C String");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("B")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "B");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("X")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "X");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_bool) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("false")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "false");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_size) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("2048")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "2048");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value_any) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, const_cast<char*>("New Generic Value")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "New Generic Value");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_i8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("127"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_i16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_i32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("2147483647"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_i64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_u8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_u16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_u32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_u64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_hex) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_octal) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_float) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_double) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_bool) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_size) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability_any) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_i8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_i16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_i32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_i64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_u8) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_u16) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_u32) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_u64) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_hex) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_octal) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_float) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_double) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_wstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_cstr) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_cchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_wchar) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_bool) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_size) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute_any) {
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, const_cast<char*>("Test Attribute"), const_cast<char*>("Test Description"), const_cast<char*>("cpp_test_id")) == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_equals_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("127"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("127"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("2147483647"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("2147483647"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_equals_any) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("127"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("32767"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("9223372036854775807"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("255"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("65535"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("4294967295"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("18446744073709551615"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x1A3F"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0755"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("3.14"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("2.718281828459"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("Wide String"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("C String"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_cchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cchar"), const_cast<char*>("A"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_wchar) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wchar"), const_cast<char*>("W"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("true"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("1024"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy_any) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("Generic Value"));
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_create_destroy) {
    fossil::tofu::Tofu tofu("i32", "42");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 32-bit Integer");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "42");
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_copy_constructor) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2(tofu1);
    ASSUME_ITS_TRUE(tofu1.equals(tofu2));
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_move_constructor) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2(std::move(tofu1));
    ASSUME_ITS_EQUAL_CSTR(tofu2.get_value().c_str(), "42");
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_copy_assignment) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2("i32", "0");
    tofu2 = tofu1;
    ASSUME_ITS_TRUE(tofu1.equals(tofu2));
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_move_assignment) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2("i32", "0");
    tofu2 = std::move(tofu1);
    ASSUME_ITS_EQUAL_CSTR(tofu2.get_value().c_str(), "42");
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_set_get_value) {
    fossil::tofu::Tofu tofu("i32", "0");
    tofu.set_value("100");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "100");
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_mutability) {
    fossil::tofu::Tofu tofu("i32", "42");
    tofu.set_mutable(true);
    ASSUME_ITS_TRUE(tofu.is_mutable());
    tofu.set_mutable(false);
    ASSUME_ITS_TRUE(!tofu.is_mutable());
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_set_get_attribute) {
    fossil::tofu::Tofu tofu("i32", "42");
    tofu.set_attribute("Test Attribute", "Test Description", "cpp_test_id");
    const fossil_tofu_attribute_t* attr = tofu.get_attribute();
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
}

FOSSIL_TEST_CASE(cpp_test_tofu_class_equals) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2("i32", "42");
    ASSUME_ITS_TRUE(tofu1.equals(tofu2));
}

#include <iostream>
FOSSIL_TEST_CASE(cpp_test_tofu_class_type_info) {
    fossil::tofu::Tofu tofu("i32", "42");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 32-bit Integer");
    ASSUME_ITS_TRUE(!tofu.get_type_info().empty());
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_info().c_str(), "Signed 32-bit Integer");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy_any);

    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default_any);

    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move_size);

    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy_any);

    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute_any);

    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability_any);

    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals_any);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_octal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_float);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_double);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_wstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_cchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_wchar);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy_any);

    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_create_destroy);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_copy_constructor);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_move_constructor);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_copy_assignment);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_move_assignment);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_set_get_value);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_mutability);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_set_get_attribute);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_equals);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_class_type_info);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_generic_tofu_fixture);
} // end of tests
