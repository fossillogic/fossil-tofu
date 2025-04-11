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

FOSSIL_TEST_SUITE(c_stack_tofu_fixture);

FOSSIL_SETUP(c_stack_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_stack_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_stack_create_destroy_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_destroy_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_default) {
    fossil_stack_t* stack = fossil_stack_create_default();
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_create_move_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_get_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_get_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("i8", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("i16", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("i32", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("i64", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("u8", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("u16", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("u32", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("u64", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("hex", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("octal", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("float", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("double", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("wstr", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("cstr", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("cchar", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("wchar", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("bool", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("size", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("any", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_cnullptr) {
    fossil_stack_t* stack = NULL;
    ASSUME_ITS_TRUE(fossil_stack_is_cnullptr(stack) == true);
}

FOSSIL_TEST_CASE(c_test_stack_top_i8) {
    fossil_stack_t* stack = fossil_stack_create_container("i8");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_i16) {
    fossil_stack_t* stack = fossil_stack_create_container("i16");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_i32) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_i64) {
    fossil_stack_t* stack = fossil_stack_create_container("i64");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_u8) {
    fossil_stack_t* stack = fossil_stack_create_container("u8");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_u16) {
    fossil_stack_t* stack = fossil_stack_create_container("u16");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_u32) {
    fossil_stack_t* stack = fossil_stack_create_container("u32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_u64) {
    fossil_stack_t* stack = fossil_stack_create_container("u64");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_hex) {
    fossil_stack_t* stack = fossil_stack_create_container("hex");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_octal) {
    fossil_stack_t* stack = fossil_stack_create_container("octal");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_float) {
    fossil_stack_t* stack = fossil_stack_create_container("float");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_double) {
    fossil_stack_t* stack = fossil_stack_create_container("double");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_wstr) {
    fossil_stack_t* stack = fossil_stack_create_container("wstr");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_cstr) {
    fossil_stack_t* stack = fossil_stack_create_container("cstr");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_cchar) {
    fossil_stack_t* stack = fossil_stack_create_container("cchar");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_wchar) {
    fossil_stack_t* stack = fossil_stack_create_container("wchar");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_bool) {
    fossil_stack_t* stack = fossil_stack_create_container("bool");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_size) {
    fossil_stack_t* stack = fossil_stack_create_container("size");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_top_any) {
    fossil_stack_t* stack = fossil_stack_create_container("any");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_stack_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_cnullptr);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_default);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get_any);

    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_i8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_i16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_i32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_i64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_u8);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_u16);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_u32);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_u64);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_hex);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_octal);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_float);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_double);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_wstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_cstr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_cchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_wchar);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_bool);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set_any);

    FOSSIL_TEST_REGISTER(c_stack_tofu_fixture);
} // end of tests
