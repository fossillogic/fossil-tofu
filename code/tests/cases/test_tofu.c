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

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_create_destroy);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_default);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_copy_constructor);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, c_test_tofu_struct_move_constructor);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_generic_tofu_fixture);
} // end of tests
