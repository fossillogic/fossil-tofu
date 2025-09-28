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

FOSSIL_SUITE(cpp_generic_tofu_fixture);

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

FOSSIL_TEST(cpp_test_tofu_struct_create_destroy) {
    fossil::tofu::Tofu tofu("i32", "42");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 32-bit Integer");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "42");
}

FOSSIL_TEST(cpp_test_tofu_struct_default) {
    fossil::tofu::Tofu tofu("i32", "0");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 32-bit Integer");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "0");
}

FOSSIL_TEST(cpp_test_tofu_struct_copy_constructor) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2 = tofu1; // Copy constructor
    ASSUME_ITS_TRUE(tofu1.equals(tofu2));
    ASSUME_ITS_EQUAL_CSTR(tofu2.get_value().c_str(), "42");
}

FOSSIL_TEST(cpp_test_tofu_struct_move_constructor) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2 = std::move(tofu1); // Move constructor
    ASSUME_ITS_EQUAL_CSTR(tofu2.get_value().c_str(), "42");
}

FOSSIL_TEST(cpp_test_tofu_struct_copy_assignment) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2("i32", "0");
    tofu2 = tofu1; // Copy assignment
    ASSUME_ITS_TRUE(tofu1.equals(tofu2));
    ASSUME_ITS_EQUAL_CSTR(tofu2.get_value().c_str(), "42");
}

FOSSIL_TEST(cpp_test_tofu_struct_move_assignment) {
    fossil::tofu::Tofu tofu1("i32", "42");
    fossil::tofu::Tofu tofu2("i32", "0");
    tofu2 = std::move(tofu1); // Move assignment
    ASSUME_ITS_EQUAL_CSTR(tofu2.get_value().c_str(), "42");
}

FOSSIL_TEST(cpp_test_tofu_struct_set_value) {
    fossil::tofu::Tofu tofu("i32", "0");
    tofu.set_value("123");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "123");
}

FOSSIL_TEST(cpp_test_tofu_struct_set_attribute) {
    fossil::tofu::Tofu tofu("i32", "42");
    tofu.set_attribute("answer", "The answer to everything", "42id");
    const fossil_tofu_attribute_t* attr = tofu.get_attribute();
    ASSUME_ITS_EQUAL_CSTR(attr->name, "answer");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "The answer to everything");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "42id");
}

FOSSIL_TEST(cpp_test_tofu_set_and_get_value) {
    fossil::tofu::Tofu tofu("i16", "123");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "123");
    tofu.set_value("456");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "456");
}

FOSSIL_TEST(cpp_test_tofu_mutability) {
    fossil::tofu::Tofu tofu("u8", "99");
    ASSUME_ITS_TRUE(tofu.is_mutable());
    tofu.set_mutable(false);
    ASSUME_ITS_FALSE(tofu.is_mutable());
    try {
        tofu.set_value("100");
        ASSUME_ITS_TRUE(false); // Should not reach here
    } catch (const std::runtime_error&) {
        ASSUME_ITS_TRUE(true); // Exception expected
    }
}

FOSSIL_TEST(cpp_test_tofu_type_and_info) {
    fossil::tofu::Tofu tofu("f32", "3.14");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Float");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_info().c_str(), "A single-precision floating point value");
}

FOSSIL_TEST(cpp_test_tofu_set_and_get_attribute) {
    fossil::tofu::Tofu tofu("u16", "65535");
    tofu.set_attribute("Custom Name", "Custom Description", "custom_id");
    const fossil_tofu_attribute_t* attr = tofu.get_attribute();
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Custom Name");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Custom Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "custom_id");
}

FOSSIL_TEST(cpp_test_tofu_validate_type) {
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("i32"), FOSSIL_TOFU_TYPE_I32);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("f64"), FOSSIL_TOFU_TYPE_F64);
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("any"), FOSSIL_TOFU_TYPE_ANY);
}

FOSSIL_TEST(cpp_test_tofu_create_invalid_type) {
    try {
        fossil::tofu::Tofu tofu("invalid_type", "value");
        ASSUME_ITS_TRUE(false); // Should not reach here
    } catch (const std::runtime_error&) {
        ASSUME_ITS_TRUE(true); // Exception expected
    }
}

FOSSIL_TEST(cpp_test_tofu_compare_equal_and_not_equal) {
    fossil::tofu::Tofu tofu1("i16", "123");
    fossil::tofu::Tofu tofu2("i16", "123");
    fossil::tofu::Tofu tofu3("i16", "456");
    fossil::tofu::Tofu tofu4("u16", "123");
    ASSUME_ITS_EQUAL_I32(tofu1.compare(tofu2), 0);
    ASSUME_ITS_TRUE(tofu1.compare(tofu3) < 0);
    ASSUME_ITS_TRUE(tofu1.compare(tofu4) < 0);
}

FOSSIL_TEST(cpp_test_tofu_set_value_immutable) {
    fossil::tofu::Tofu tofu("i8", "1");
    tofu.set_mutable(false);
    try {
        tofu.set_value("2");
        ASSUME_ITS_TRUE(false); // Should not reach here
    } catch (const std::runtime_error&) {
        ASSUME_ITS_TRUE(true); // Exception expected
    }
}

FOSSIL_TEST(cpp_test_tofu_get_value_or_default) {
    fossil::tofu::Tofu tofu("i8", "1");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value_or_default("default").c_str(), "1");
}

FOSSIL_TEST(cpp_test_tofu_is_empty) {
    fossil::tofu::Tofu tofu("i8", "");
    ASSUME_ITS_TRUE(tofu.is_empty());
}

FOSSIL_TEST(cpp_test_tofu_clone) {
    fossil::tofu::Tofu tofu("i8", "1");
    fossil::tofu::Tofu clone = tofu.clone();
    ASSUME_ITS_TRUE(tofu.equals(clone));
}

FOSSIL_TEST(cpp_test_tofu_lock) {
    fossil::tofu::Tofu tofu("i8", "1");
    tofu.lock();
    ASSUME_ITS_FALSE(tofu.is_mutable());
}

FOSSIL_TEST(cpp_test_tofu_as_from_i8) {
    auto tofu = fossil::tofu::Tofu::from_i8(-42);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 8-bit Integer");
    ASSUME_ITS_EQUAL_I32(tofu.as_i8(), -42);
}

FOSSIL_TEST(cpp_test_tofu_as_from_i16) {
    auto tofu = fossil::tofu::Tofu::from_i16(-12345);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 16-bit Integer");
    ASSUME_ITS_EQUAL_I32(tofu.as_i16(), -12345);
}

FOSSIL_TEST(cpp_test_tofu_as_from_i32) {
    auto tofu = fossil::tofu::Tofu::from_i32(-123456789);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 32-bit Integer");
    ASSUME_ITS_EQUAL_I32(tofu.as_i32(), -123456789);
}

FOSSIL_TEST(cpp_test_tofu_as_from_i64) {
    auto tofu = fossil::tofu::Tofu::from_i64(-1234567890123LL);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Signed 64-bit Integer");
    ASSUME_ITS_EQUAL_I64(tofu.as_i64(), -1234567890123LL);
}

FOSSIL_TEST(cpp_test_tofu_as_from_u8) {
    auto tofu = fossil::tofu::Tofu::from_u8(200);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Unsigned 8-bit Integer");
    ASSUME_ITS_EQUAL_U32(tofu.as_u8(), 200);
}

FOSSIL_TEST(cpp_test_tofu_as_from_u16) {
    auto tofu = fossil::tofu::Tofu::from_u16(60000);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Unsigned 16-bit Integer");
    ASSUME_ITS_EQUAL_U32(tofu.as_u16(), 60000);
}

FOSSIL_TEST(cpp_test_tofu_as_from_u32) {
    auto tofu = fossil::tofu::Tofu::from_u32(4000000000U);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Unsigned 32-bit Integer");
    ASSUME_ITS_EQUAL_U32(tofu.as_u32(), 4000000000U);
}

FOSSIL_TEST(cpp_test_tofu_as_from_u64) {
    auto tofu = fossil::tofu::Tofu::from_u64(9000000000000000000ULL);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Unsigned 64-bit Integer");
    ASSUME_ITS_EQUAL_U64(tofu.as_u64(), 9000000000000000000ULL);
}

FOSSIL_TEST(cpp_test_tofu_as_from_hex) {
    auto tofu = fossil::tofu::Tofu::from_hex("0x1A2B3C");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Hexadecimal");
    ASSUME_ITS_EQUAL_CSTR(tofu.as_hex().c_str(), "0x1A2B3C");
}

FOSSIL_TEST(cpp_test_tofu_as_from_oct) {
    auto tofu = fossil::tofu::Tofu::from_oct("0755");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Octal");
    ASSUME_ITS_EQUAL_CSTR(tofu.as_oct().c_str(), "0755");
}

FOSSIL_TEST(cpp_test_tofu_as_from_bin) {
    auto tofu = fossil::tofu::Tofu::from_bin("101010");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Binary");
    ASSUME_ITS_EQUAL_CSTR(tofu.as_bin().c_str(), "101010");
}

FOSSIL_TEST(cpp_test_tofu_as_from_f32) {
    auto tofu = fossil::tofu::Tofu::from_f32(3.14159f);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Float");
    ASSUME_ITS_TRUE(fabsf(tofu.as_f32() - 3.14159f) < 0.0001f);
}

FOSSIL_TEST(cpp_test_tofu_as_from_f64) {
    auto tofu = fossil::tofu::Tofu::from_f64(2.718281828459);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Double");
    ASSUME_ITS_EQUAL_F64(tofu.as_f64(), 2.718281828459, 1e-6);
}

FOSSIL_TEST(cpp_test_tofu_as_from_cstr) {
    auto tofu = fossil::tofu::Tofu::from_cstr("hello world");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "C String");
    ASSUME_ITS_EQUAL_CSTR(tofu.as_cstr().c_str(), "hello world");
}

FOSSIL_TEST(cpp_test_tofu_as_from_char) {
    auto tofu = fossil::tofu::Tofu::from_char('Z');
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Char");
    ASSUME_ITS_EQUAL_I32(tofu.as_char(), 'Z');
}

FOSSIL_TEST(cpp_test_tofu_as_from_bool) {
    auto tofu_true = fossil::tofu::Tofu::from_bool(true);
    auto tofu_false = fossil::tofu::Tofu::from_bool(false);
    ASSUME_ITS_EQUAL_CSTR(tofu_true.get_type_name().c_str(), "Boolean");
    ASSUME_ITS_TRUE(tofu_true.as_bool());
    ASSUME_ITS_FALSE(tofu_false.as_bool());
}

FOSSIL_TEST(cpp_test_tofu_as_from_size) {
    size_t val = 123456;
    auto tofu = fossil::tofu::Tofu::from_size(val);
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Size");
    ASSUME_ITS_EQUAL_U64(tofu.as_size(), val);
}

FOSSIL_TEST(cpp_test_tofu_as_from_datetime) {
    auto tofu = fossil::tofu::Tofu::from_datetime("2024-06-01T12:34:56Z");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Date time");
    ASSUME_ITS_EQUAL_CSTR(tofu.as_datetime().c_str(), "2024-06-01T12:34:56Z");
}

FOSSIL_TEST(cpp_test_tofu_as_from_duration) {
    auto tofu = fossil::tofu::Tofu::from_duration("PT1H30M");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Duration");
    ASSUME_ITS_EQUAL_CSTR(tofu.as_duration().c_str(), "PT1H30M");
}

FOSSIL_TEST(cpp_test_tofu_as_from_any) {
    int x = 42;
    auto tofu = fossil::tofu::Tofu::from_any(&x, sizeof(x));
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "Any");
    void* ptr = tofu.as_any();
    ASSUME_NOT_CNULL(ptr);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_create_destroy);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_default);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_copy_constructor);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_move_constructor);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_copy_assignment);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_move_assignment);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_set_value);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_struct_set_attribute);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_set_and_get_value);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_mutability);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_type_and_info);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_set_and_get_attribute);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_validate_type);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_create_invalid_type);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_compare_equal_and_not_equal);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_set_value_immutable);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_get_value_or_default);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_is_empty);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_clone);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_lock);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_i8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_i16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_i32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_i64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_u8);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_u16);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_u32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_u64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_hex);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_oct);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_bin);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_f32);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_f64);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_cstr);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_char);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_bool);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_size);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_datetime);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_duration);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_tofu_as_from_any);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_generic_tofu_fixture);
} // end of tests
