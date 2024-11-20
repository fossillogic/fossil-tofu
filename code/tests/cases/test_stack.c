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

FOSSIL_TEST_SUITE(c_stack_tofu_fixture);

FOSSIL_SETUP(c_stack_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_stack_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_stack_create_container) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_default) {
    fossil_stack_t* stack = fossil_stack_create_default();
    ASSUME_ITS_TRUE(stack != NULL);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_create_copy) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* copy = fossil_stack_create_copy(stack);
    ASSUME_ITS_TRUE(copy != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(copy).value.data, "42");
    fossil_stack_destroy(stack);
    fossil_stack_destroy(copy);
}

FOSSIL_TEST_CASE(c_test_stack_create_move) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_t* moved = fossil_stack_create_move(stack);
    ASSUME_ITS_TRUE(moved != NULL);
    ASSUME_ITS_TRUE(fossil_stack_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(moved).value.data, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(moved);
}

FOSSIL_TEST_CASE(c_test_stack_get) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 0).value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_set) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    fossil_tofu_t new_value = fossil_tofu_create("i32", "21");
    fossil_stack_set(stack, 1, new_value);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_get(stack, 1).value.data, "21");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_insert) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_insert(stack, "42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_remove) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_remove(stack) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_size) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    fossil_stack_insert(stack, "84");
    ASSUME_ITS_TRUE(fossil_stack_size(stack) == 2);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_empty) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_not_empty(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_not_cnullptr) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(stack) == true);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_empty) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == true);
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_TRUE(fossil_stack_is_empty(stack) == false);
    fossil_stack_destroy(stack);
}

FOSSIL_TEST_CASE(c_test_stack_is_cnullptr) {
    fossil_stack_t* stack = NULL;
    ASSUME_ITS_TRUE(fossil_stack_is_cnullptr(stack) == true);
}

FOSSIL_TEST_CASE(c_test_stack_top) {
    fossil_stack_t* stack = fossil_stack_create_container("i32");
    fossil_stack_insert(stack, "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_stack_top(stack).value.data, "42");
    fossil_stack_destroy(stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_stack_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_insert);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_remove);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_size);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_empty);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_not_cnullptr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_empty);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_is_cnullptr);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_top);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_container);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_default);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_copy);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_create_move);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_get);
    FOSSIL_TEST_ADD(c_stack_tofu_fixture, c_test_stack_set);

    FOSSIL_TEST_REGISTER(c_stack_tofu_fixture);
} // end of tests
