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
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_type_name(&tofu), "Signed 32-bit Integer");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "42");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_struct_copy_constructor) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2));
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST(c_test_tofu_struct_move_constructor) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(tofu2), "42");
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST(c_test_tofu_struct_copy_assignment) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2 = fossil_tofu_create("i32", "0");
    fossil_tofu_copy(&tofu2, &tofu1);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2));
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(c_test_tofu_struct_move_assignment) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2 = fossil_tofu_create("i32", "0");
    fossil_tofu_move(&tofu2, &tofu1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu2), "42");
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(c_test_tofu_struct_set_get_value) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "0");
    fossil_tofu_set_value(&tofu, "100");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "100");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_struct_mutability) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    fossil_tofu_set_mutable(&tofu, true);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu));
    fossil_tofu_set_mutable(&tofu, false);
    ASSUME_ITS_TRUE(!fossil_tofu_is_mutable(&tofu));
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_struct_set_get_attribute) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "c_test_id");
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_struct_equals) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2 = fossil_tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2));
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(c_test_tofu_struct_type_info) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_type_name(&tofu), "Signed 32-bit Integer");
    const char* type_info = fossil_tofu_type_info(&tofu);
    ASSUME_ITS_TRUE(type_info != NULL && type_info[0] != '\0');
    ASSUME_ITS_EQUAL_CSTR(type_info, "Signed 32-bit Integer");
    fossil_tofu_destroy(&tofu);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_create_destroy);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_copy_constructor);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_move_constructor);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_copy_assignment);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_move_assignment);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_set_get_value);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_mutability);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_set_get_attribute);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_equals);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_type_info);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_generic_tofu_fixture);
} // end of tests
