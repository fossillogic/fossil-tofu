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
    fossil::tofu::Tofu tofu("float", "3.14");
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
    ASSUME_ITS_EQUAL_I32(fossil_tofu_validate_type("double"), FOSSIL_TOFU_TYPE_DOUBLE);
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

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_generic_tofu_fixture);
} // end of tests
