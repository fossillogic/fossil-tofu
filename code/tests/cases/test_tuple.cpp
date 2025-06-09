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

FOSSIL_SUITE(cpp_tuple_tofu_fixture);

FOSSIL_SETUP(cpp_tuple_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_tuple_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_test_tuple_create_destroy_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_destroy_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_default) {
    fossil_tuple_t* tuple = fossil_tuple_create_default();
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_i8) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_i16) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_i32) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_i64) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_u8) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_u16) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_u32) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_u64) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_hex) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_octal) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_float) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_double) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_wstr) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_cstr) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_cchar) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_wchar) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_bool) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_size) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_copy_any) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST(cpp_test_tuple_create_move_i8) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_i16) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_i32) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_i64) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_u8) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_u16) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_u32) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_u64) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_hex) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_octal) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_float) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_double) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_wstr) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_cstr) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_cchar) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_wchar) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_bool) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_size) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_create_move_any) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(original, const_cast<char*>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST(cpp_test_tuple_add_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_add_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_remove_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_clear_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_front_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("42"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_get_back_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), const_cast<char*>("84"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_front_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_front(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_i8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_i16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_i32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_i64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("i64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_u8) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u8"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_u16) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u16"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_u32) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u32"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_u64) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("u64"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_hex) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("hex"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_octal) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("octal"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_float) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("float"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_double) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("double"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_wstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_cstr) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cstr"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_cchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("cchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_wchar) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("wchar"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_bool) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("bool"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_size) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("size"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_set_back_any) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char*>("any"));
    fossil_tuple_add(tuple, const_cast<char*>("42"));
    fossil_tuple_add(tuple, const_cast<char*>("84"));
    fossil_tuple_set_back(tuple, const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), const_cast<char*>("21"));
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST(cpp_test_tuple_class_create_with_type) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(tuple.is_empty());
}

FOSSIL_TEST(cpp_test_tuple_class_create_default) {
    fossil::tofu::Tuple tuple;
    ASSUME_ITS_TRUE(tuple.is_empty());
}

FOSSIL_TEST(cpp_test_tuple_class_create_copy) {
    fossil::tofu::Tuple original(const_cast<char*>("i32"));
    original.add(const_cast<char*>("42"));
    fossil::tofu::Tuple copy(original);
    ASSUME_ITS_TRUE(copy.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(copy.get(0), const_cast<char*>("42"));
}

FOSSIL_TEST(cpp_test_tuple_class_create_move) {
    fossil::tofu::Tuple original(const_cast<char*>("i32"));
    original.add(const_cast<char*>("42"));
    fossil::tofu::Tuple moved(std::move(original));
    ASSUME_ITS_TRUE(moved.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(moved.get(0), const_cast<char*>("42"));
    ASSUME_ITS_TRUE(original.is_empty());
}

FOSSIL_TEST(cpp_test_tuple_class_add_element) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(tuple.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0), const_cast<char*>("42"));
}

FOSSIL_TEST(cpp_test_tuple_class_remove_element) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    tuple.add(const_cast<char*>("84"));
    tuple.remove(0);
    ASSUME_ITS_TRUE(tuple.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0), const_cast<char*>("84"));
}

FOSSIL_TEST(cpp_test_tuple_class_clear) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    tuple.add(const_cast<char*>("84"));
    tuple.clear();
    ASSUME_ITS_TRUE(tuple.is_empty());
}

FOSSIL_TEST(cpp_test_tuple_class_get_front) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    tuple.add(const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_front(), const_cast<char*>("42"));
}

FOSSIL_TEST(cpp_test_tuple_class_get_back) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    tuple.add(const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_back(), const_cast<char*>("84"));
}

FOSSIL_TEST(cpp_test_tuple_class_set_element) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    tuple.set(0, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0), const_cast<char*>("84"));
}

FOSSIL_TEST(cpp_test_tuple_class_set_front) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    tuple.add(const_cast<char*>("84"));
    tuple.set_front(const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_front(), const_cast<char*>("21"));
}

FOSSIL_TEST(cpp_test_tuple_class_set_back) {
    fossil::tofu::Tuple tuple(const_cast<char*>("i32"));
    tuple.add(const_cast<char*>("42"));
    tuple.add(const_cast<char*>("84"));
    tuple.set_back(const_cast<char*>("21"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_back(), const_cast<char*>("21"));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_tuple_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_default);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_i8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_i16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_i32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_i64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_u8);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_u16);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_u32);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_u64);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_hex);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_octal);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_float);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_double);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_wstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_cstr);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_cchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_wchar);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_bool);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_size);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back_any);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_with_type);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_default);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_copy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_move);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_add_element);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_remove_element);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_clear);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_get_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_get_back);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_set_element);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_set_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_set_back);

    FOSSIL_TEST_REGISTER(cpp_tuple_tofu_fixture);
} // end of tests
