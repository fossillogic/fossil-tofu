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

FOSSIL_SUITE(c_generic_tofu_fixture);

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

FOSSIL_TEST(c_test_tofu_struct_create_destroy) {
    // Test fossil_tofu_create and fossil_tofu_destroy
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_type_name(tofu.type), "Signed 32-bit Integer");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "42");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_struct_default) {
    // Test fossil_tofu_create_default
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_NOT_CNULL(tofu);
    // Optionally check default values if known
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST(c_test_tofu_struct_copy_constructor) {
    // Test fossil_tofu_create_copy
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2));
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST(c_test_tofu_struct_move_constructor) {
    // Test fossil_tofu_create_move
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(tofu2), "42");
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST(c_test_tofu_set_and_get_value) {
    fossil_tofu_t tofu = fossil_tofu_create("i16", "123");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "123");
    int result = fossil_tofu_set_value(&tofu, "456");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "456");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_mutability) {
    fossil_tofu_t tofu = fossil_tofu_create("u8", "99");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu));
    fossil_tofu_set_mutable(&tofu, false);
    ASSUME_ITS_FALSE(fossil_tofu_is_mutable(&tofu));
    int result = fossil_tofu_set_value(&tofu, "100");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_type_and_info) {
    fossil_tofu_t tofu = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_get_type(&tofu), FOSSIL_TOFU_TYPE_FLOAT);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_type_name(tofu.type), "Float");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_type_info(tofu.type), "A single-precision floating point value");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_set_and_get_attribute) {
    fossil_tofu_t tofu = fossil_tofu_create("u16", "65535");
    int result = fossil_tofu_set_attribute(&tofu, "Custom Name", "Custom Description", "custom_id");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Custom Name");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Custom Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "custom_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_equals_and_copy) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i8", "7");
    fossil_tofu_t tofu2 = fossil_tofu_create("i8", "7");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2));
    fossil_tofu_set_value(&tofu2, "8");
    ASSUME_ITS_FALSE(fossil_tofu_equals(&tofu1, &tofu2));
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);

    fossil_tofu_t tofu3 = fossil_tofu_create("i16", "22");
    fossil_tofu_t tofu4;
    int copy_result = fossil_tofu_copy(&tofu4, &tofu3);
    ASSUME_ITS_EQUAL_I32(copy_result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu3, &tofu4));
    fossil_tofu_destroy(&tofu3);
    fossil_tofu_destroy(&tofu4);
}

FOSSIL_TEST(c_test_tofu_validate_type) {
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("i32"), FOSSIL_TOFU_TYPE_I32);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("double"), FOSSIL_TOFU_TYPE_DOUBLE);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("any"), FOSSIL_TOFU_TYPE_ANY);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_create_destroy);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_default);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_copy_constructor);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_move_constructor);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_set_and_get_value);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_mutability);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_type_and_info);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_set_and_get_attribute);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_equals_and_copy);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_validate_type);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_generic_tofu_fixture);
} // end of tests
