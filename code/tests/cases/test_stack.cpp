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

FOSSIL_SUITE(cpp_stack_tofu_fixture);

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

using fossil::tofu::Stack;
using fossil::tofu::Tofu;

FOSSIL_TEST(cpp_test_stack_create_destroy) {
    Stack stack("i32");
    ASSUME_ITS_TRUE(stack.not_cnullptr());
    // No explicit destroy needed, handled by destructor
}

FOSSIL_TEST(cpp_test_stack_create_default) {
    Stack stack;
    ASSUME_ITS_TRUE(stack.not_cnullptr());
    // Can't check type directly, but default constructor should succeed
}

FOSSIL_TEST(cpp_test_stack_insert_and_remove) {
    Stack stack("i32");
    int32_t result = stack.insert("42");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(stack.size(), 1);
    result = stack.remove();
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(stack.size(), 0);
}

FOSSIL_TEST(cpp_test_stack_copy_constructor) {
    Stack stack1("i32");
    stack1.insert("1");
    stack1.insert("2");
    Stack stack2(stack1);
    ASSUME_ITS_EQUAL_I32(stack1.size(), stack2.size());
}

FOSSIL_TEST(cpp_test_stack_move_constructor) {
    Stack stack1("i32");
    stack1.insert("5");
    stack1.insert("6");
    Stack stack2(std::move(stack1));
    ASSUME_ITS_EQUAL_I32(stack2.size(), 2);
    // stack1 is in a valid but unspecified state after move
}

FOSSIL_TEST(cpp_test_stack_top_and_get_set) {
    Stack stack("i32");
    stack.insert("100");
    stack.insert("200");
    fossil_tofu_t top = stack.top();
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&top), "200");
    fossil_tofu_t elem = stack.get(1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&elem), "100");
    Tofu new_elem("i32", "300");
}

FOSSIL_TEST(cpp_test_stack_empty_and_not_empty) {
    Stack stack("i32");
    ASSUME_ITS_TRUE(stack.is_empty());
    stack.insert("1");
    ASSUME_ITS_TRUE(stack.not_empty());
    stack.remove();
    ASSUME_ITS_TRUE(stack.is_empty());
}

FOSSIL_TEST(cpp_test_stack_insert_null_stack) {
    fossil_stack_t* null_stack = nullptr;
    int32_t result = fossil_stack_insert(null_stack, const_cast<char *>("42"));
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

FOSSIL_TEST(cpp_test_stack_remove_null_stack) {
    fossil_stack_t* null_stack = nullptr;
    int32_t result = fossil_stack_remove(null_stack);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

FOSSIL_TEST(cpp_test_stack_remove_empty_stack) {
    Stack stack("i32");
    int32_t result = stack.remove();
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

FOSSIL_TEST(cpp_test_stack_size_null_stack) {
    fossil_stack_t* null_stack = nullptr;
    size_t size = fossil_stack_size(null_stack);
    ASSUME_ITS_EQUAL_I32(size, FOSSIL_TOFU_SUCCESS);
}

FOSSIL_TEST(cpp_test_stack_not_empty_and_is_empty_variants) {
    Stack stack("i32");
    ASSUME_ITS_FALSE(stack.not_empty());
    ASSUME_ITS_TRUE(stack.is_empty());
    stack.insert("123");
    ASSUME_ITS_TRUE(stack.not_empty());
    ASSUME_ITS_FALSE(stack.is_empty());
}

FOSSIL_TEST(cpp_test_stack_not_cnullptr_and_is_cnullptr) {
    Stack stack("i32");
    ASSUME_ITS_TRUE(stack.not_cnullptr());
    ASSUME_ITS_FALSE(stack.is_cnullptr());
    // Can't set stack to nullptr directly, so test raw pointer
    fossil_stack_t* raw = nullptr;
    ASSUME_ITS_FALSE(fossil_stack_not_cnullptr(raw));
    ASSUME_ITS_TRUE(fossil_stack_is_cnullptr(raw));
}

FOSSIL_TEST(cpp_test_stack_top_empty_stack) {
    Stack stack("i32");
    fossil_tofu_t top = stack.top();
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&top), "");
}

FOSSIL_TEST(cpp_test_stack_get_out_of_bounds) {
    Stack stack("i32");
    stack.insert("1");
    fossil_tofu_t elem = stack.get(5);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&elem), "");
}

FOSSIL_TEST(cpp_test_stack_set_out_of_bounds) {
    Stack stack("i32");
    stack.insert("1");
    Tofu new_elem("i32", "999");
    stack.set(5, new_elem.get_c_struct()); // Should not crash or set anything
    fossil_tofu_t elem = stack.get(0);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&elem), "1");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_stack_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_create_destroy);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_create_default);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_insert_and_remove);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_copy_constructor);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_move_constructor);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_top_and_get_set);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_empty_and_not_empty);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_insert_null_stack);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_remove_null_stack);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_remove_empty_stack);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_size_null_stack);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_not_empty_and_is_empty_variants);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_top_empty_stack);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_get_out_of_bounds);
    FOSSIL_TEST_ADD(cpp_stack_tofu_fixture, cpp_test_stack_set_out_of_bounds);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_stack_tofu_fixture);
} // end of tests
