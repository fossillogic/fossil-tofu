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

FOSSIL_SUITE(objc_stack_tofu_fixture);

FOSSIL_SETUP(objc_stack_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(objc_stack_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(objc_test_stack_create_destroy) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_NOT_CNULL(stack);
    ASSUME_ITS_EQUAL_CSTR(stack->type, "i32");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_create_default) {
    fossil_stack_t* stack = fossil_stack_create_default();
    ASSUME_NOT_CNULL(stack);
    ASSUME_ITS_EQUAL_CSTR(stack->type, "any");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_insert_and_remove) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    int32_t result = fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_stack_size(stack), 1);
    result = fossil_stack_remove(stack);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_stack_size(stack), 0);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_copy_constructor) {
    fossil_stack_t* stack1 = fossil_stack_create_container("i32");
    fossil_stack_insert(stack1, "1");
    fossil_stack_insert(stack1, "2");
    fossil_stack_t* stack2 = fossil_stack_create_copy(stack1);
    ASSUME_NOT_CNULL(stack2);
    ASSUME_ITS_EQUAL_I32(fossil_stack_size(stack1), fossil_stack_size(stack2));
    fossil_stack_destroy(stack1);
    fossil_stack_destroy(stack2);
}

FOSSIL_TEST(objc_test_stack_move_constructor) {
    fossil_stack_t* stack1 = fossil_stack_create_container("i32");
    fossil_stack_insert(stack1, "5");
    fossil_stack_insert(stack1, "6");
    fossil_stack_t* stack2 = fossil_stack_create_move(stack1);
    ASSUME_NOT_CNULL(stack2);
    ASSUME_ITS_EQUAL_I32(fossil_stack_size(stack2), 2);
    ASSUME_ITS_EQUAL_I32(fossil_stack_size(stack1), 0);
    fossil_stack_destroy(stack1);
    fossil_stack_destroy(stack2);
}

FOSSIL_TEST(objc_test_stack_top_and_get_set) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "100");
    fossil_stack_insert(stack, "200");
    fossil_tofu_t top = fossil_stack_top(stack);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&top), "200");
    fossil_tofu_t elem = fossil_stack_get(stack, 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&elem), "100");
    fossil_tofu_t new_elem = fossil_tofu_create("i32", "300");
    fossil_stack_set(stack, 1, new_elem);
    fossil_tofu_t changed = fossil_stack_get(stack, 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&changed), "300");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_empty_and_not_empty) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack));
    fossil_stack_insert(stack, "1");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack));
    fossil_stack_remove(stack);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack));
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_insert_null_stack) {
    int32_t result = fossil_stack_insert(NULL, "42");
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

FOSSIL_TEST(objc_test_stack_remove_null_stack) {
    int32_t result = fossil_stack_remove(NULL);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

FOSSIL_TEST(objc_test_stack_remove_empty_stack) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    int32_t result = fossil_stack_remove(stack);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_size_null_stack) {
    size_t size = fossil_stack_size(NULL);
    ASSUME_ITS_EQUAL_I32(size, FOSSIL_TOFU_SUCCESS);
}

FOSSIL_TEST(objc_test_stack_not_empty_and_is_empty_variants) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_FALSE(fossil_stack_not_empty(stack));
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack));
    fossil_stack_insert(stack, "123");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack));
    ASSUME_ITS_FALSE(fossil_stack_is_empty(stack));
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_not_cnullptr_and_is_cnullptr) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack));
    ASSUME_ITS_FALSE(fossil_stack_is_cnullptr(stack));
    fossil_stack_destroy(stack);
    stack = NULL;
    ASSUME_ITS_FALSE(fossil_stack_not_cnullptr(stack));
    ASSUME_ITS_TRUE(fossil_stack_is_cnullptr(stack));
}

FOSSIL_TEST(objc_test_stack_top_empty_stack) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_tofu_t top = fossil_stack_top(stack);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&top), "");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_get_out_of_bounds) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "1");
    fossil_tofu_t elem = fossil_stack_get(stack, 5);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&elem), "");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST(objc_test_stack_set_out_of_bounds) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "1");
    fossil_tofu_t new_elem = fossil_tofu_create("i32", "999");
    // Should not crash or set anything
    fossil_stack_set(stack, 5, new_elem);
    fossil_tofu_t elem = fossil_stack_get(stack, 0);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&elem), "1");
    fossil_stack_destroy(stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(objc_stack_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_create_destroy);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_create_default);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_insert_and_remove);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_copy_constructor);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_move_constructor);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_top_and_get_set);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_empty_and_not_empty);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_insert_null_stack);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_remove_null_stack);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_remove_empty_stack);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_size_null_stack);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_not_empty_and_is_empty_variants);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_top_empty_stack);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_get_out_of_bounds);
    FOSSIL_TEST_ADD(objc_stack_tofu_fixture, objc_test_stack_set_out_of_bounds);

    // Register the test group
    FOSSIL_TEST_REGISTER(objc_stack_tofu_fixture);
} // end of tests
