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

FOSSIL_TEST_SUITE(cpp_stack_tofu_fixture);

FOSSIL_SETUP(cpp_stack_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_stack_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_stack_create_container) {
    auto stack = fossil::stack_create_container("i32");
    ASSUME_ITS_TRUE(stack != nullptr);
    ASSUME_ITS_TRUE(fossil::stack_is_empty(stack) == true);
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_create_default) {
    auto stack = fossil::stack_create_default();
    ASSUME_ITS_TRUE(stack != nullptr);
    ASSUME_ITS_TRUE(fossil::stack_is_empty(stack) == true);
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_create_copy) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    auto copy = fossil::stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil::stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(std::string(fossil::stack_top(copy).value.data), std::string("42"));
    fossil::stack_destroy(stack);
    fossil::stack_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_stack_create_move) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    auto moved = fossil::stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil::stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(std::string(fossil::stack_top(moved).value.data), std::string("42"));
    ASSUME_ITS_TRUE(fossil::stack_is_empty(stack) == true);
    fossil::stack_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_stack_get) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    fossil::stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(std::string(fossil::stack_get(stack, 0).value.data), std::string("84"));
    ASSUME_ITS_EQUAL_CSTR(std::string(fossil::stack_get(stack, 1).value.data), std::string("42"));
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_set) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    fossil::stack_insert(stack, "84");
    auto new_value = fossil::tofu_create("i32", "21");
    fossil::stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(std::string(fossil::stack_get(stack, 1).value.data), std::string("21"));
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_insert) {
    auto stack = fossil::stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil::stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(std::string(fossil::stack_top(stack).value.data), std::string("42"));
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_remove) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil::stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::stack_is_empty(stack) == true);
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_size) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    fossil::stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil::stack_size(stack) == 2);
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_not_empty) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil::stack_not_empty(stack) == true);
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_not_cnullptr) {
    auto stack = fossil::stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil::stack_not_cnullptr(stack) == true);
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_is_empty) {
    auto stack = fossil::stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil::stack_is_empty(stack) == true);
    fossil::stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil::stack_is_empty(stack) == false);
    fossil::stack_destroy(stack);
}

FOSSIL_TEST_CASE(cpp_test_stack_is_cnullptr) {
    auto stack = nullptr;
    ASSUME_ITS_TRUE(fossil::stack_is_cnullptr(stack) == true);
}

FOSSIL_TEST_CASE(cpp_test_stack_top) {
    auto stack = fossil::stack_create_container("i32");
    fossil::stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(std::string(fossil::stack_top(stack).value.data), std::string("42"));
    fossil::stack_destroy(stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_stack_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_insert);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_remove);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_size);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_not_empty);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_is_empty);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_top);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_create_container);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_create_default);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_create_copy);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_create_move);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_get);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_set);

    FOSSIL_TEST_REGISTER(cpp_stack_tofu_fixture);
} // end of tests
