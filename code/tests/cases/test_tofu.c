/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
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
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_ERROR_IMMUTABLE);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_type_and_info) {
    fossil_tofu_t tofu = fossil_tofu_create("f32", "3.14");
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

FOSSIL_TEST(c_test_tofu_validate_type) {
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("i32"), FOSSIL_TOFU_TYPE_I32);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("f64"), FOSSIL_TOFU_TYPE_F64);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("any"), FOSSIL_TOFU_TYPE_ANY);
}

FOSSIL_TEST(c_test_tofu_create_invalid_type) {
    fossil_tofu_t tofu = fossil_tofu_create("invalid_type", "value");
    ASSUME_ITS_EQUAL_I32(tofu.type, FOSSIL_TOFU_TYPE_ANY);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_compare_equal_and_not_equal) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i16", "123");
    fossil_tofu_t tofu2 = fossil_tofu_create("i16", "123");
    fossil_tofu_t tofu3 = fossil_tofu_create("i16", "456");
    fossil_tofu_t tofu4 = fossil_tofu_create("u16", "123");
    ASSUME_ITS_EQUAL_I32(fossil_tofu_compare(&tofu1, &tofu2), 0);
    ASSUME_ITS_TRUE(fossil_tofu_compare(&tofu1, &tofu3) < 0);
    ASSUME_ITS_TRUE(fossil_tofu_compare(&tofu1, &tofu4) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
    fossil_tofu_destroy(&tofu3);
    fossil_tofu_destroy(&tofu4);
}

FOSSIL_TEST(c_test_tofu_set_value_null_and_immutable) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "1");
    int result_null = fossil_tofu_set_value(NULL, "2");
    int result_immutable = fossil_tofu_set_mutable(&tofu, false);
    int result_set = fossil_tofu_set_value(&tofu, "2");
    ASSUME_ITS_EQUAL_I32(result_null, FOSSIL_TOFU_ERROR_NULL_POINTER);
    ASSUME_ITS_EQUAL_I32(result_immutable, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result_set, FOSSIL_TOFU_ERROR_IMMUTABLE);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_get_value_null) {
    ASSUME_ITS_CNULL(fossil_tofu_get_value(NULL));
}

FOSSIL_TEST(c_test_tofu_is_mutable_null) {
    ASSUME_ITS_FALSE(fossil_tofu_is_mutable(NULL));
}

FOSSIL_TEST(c_test_tofu_set_mutable_null) {
    int result = fossil_tofu_set_mutable(NULL, true);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_ERROR_NULL_POINTER);
}

FOSSIL_TEST(c_test_tofu_get_type_null) {
    ASSUME_ITS_EQUAL_I32(fossil_tofu_get_type(NULL), FOSSIL_TOFU_TYPE_ANY);
}

FOSSIL_TEST(c_test_tofu_type_name_and_info_invalid) {
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_type_name(-1), "Unknown Type");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_type_info(-1), "No type info available.");
}

FOSSIL_TEST(c_test_tofu_set_attribute_null) {
    int result = fossil_tofu_set_attribute(NULL, "name", "desc", "id");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_ERROR_NULL_POINTER);
}

FOSSIL_TEST(c_test_tofu_get_attribute_null) {
    ASSUME_ITS_CNULL(fossil_tofu_get_attribute(NULL));
}

FOSSIL_TEST(c_test_tofu_equals_null) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "1");
    ASSUME_ITS_FALSE(fossil_tofu_equals(NULL, &tofu));
    ASSUME_ITS_FALSE(fossil_tofu_equals(&tofu, NULL));
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_copy_null) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "1");
    int result1 = fossil_tofu_copy(NULL, &tofu);
    int result2 = fossil_tofu_copy(&tofu, NULL);
    ASSUME_ITS_EQUAL_I32(result1, FOSSIL_TOFU_ERROR_NULL_POINTER);
    ASSUME_ITS_EQUAL_I32(result2, FOSSIL_TOFU_ERROR_NULL_POINTER);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(c_test_tofu_get_value_or_default) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value_or_default(&tofu, "default"), "1");
    fossil_tofu_destroy(&tofu);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value_or_default(NULL, "default"), "default");
}

FOSSIL_TEST(c_test_tofu_is_empty) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "");
    ASSUME_ITS_TRUE(fossil_tofu_is_empty(&tofu));
    fossil_tofu_destroy(&tofu);
    ASSUME_ITS_TRUE(fossil_tofu_is_empty(NULL));
}

FOSSIL_TEST(c_test_tofu_clone) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "1");
    fossil_tofu_t* clone = fossil_tofu_clone(&tofu);
    ASSUME_NOT_CNULL(clone);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu, clone));
    fossil_tofu_destroy(&tofu);
    fossil_tofu_destroy(clone);
}

FOSSIL_TEST(c_test_tofu_lock) {
    fossil_tofu_t tofu = fossil_tofu_create("i8", "1");
    int result = fossil_tofu_lock(&tofu);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_FALSE(fossil_tofu_is_mutable(&tofu));
    fossil_tofu_destroy(&tofu);
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
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_validate_type);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_create_invalid_type);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_compare_equal_and_not_equal);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_set_value_null_and_immutable);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_get_value_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_is_mutable_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_set_mutable_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_get_type_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_type_name_and_info_invalid);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_set_attribute_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_get_attribute_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_equals_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_copy_null);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_get_value_or_default);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_is_empty);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_clone);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_lock);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_generic_tofu_fixture);
} // end of tests
