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
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "i32");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_value().c_str(), "42");
}

FOSSIL_TEST(cpp_test_tofu_struct_default) {
    fossil::tofu::Tofu tofu("i32", "0");
    ASSUME_ITS_EQUAL_CSTR(tofu.get_type_name().c_str(), "i32");
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

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_generic_tofu_fixture);
} // end of tests
