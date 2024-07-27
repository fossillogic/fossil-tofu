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
#include <fossil/unittest/framework.h>
#include <fossil/xassume.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_stack_fixture);
fossil_stack_t* mock_stack;

FOSSIL_SETUP(struct_stack_fixture) {
    mock_stack = fossil_stack_create("int");
}

FOSSIL_TEARDOWN(struct_stack_fixture) {
    fossil_stack_erase(mock_stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_stack_create_and_erase) {
    // Check if the stack is created with the expected values
    ASSUME_NOT_CNULL(mock_stack);
    ASSUME_ITS_CNULL(mock_stack->top);
}

FOSSIL_TEST(test_stack_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_stack_insert(mock_stack, element1) == 0);
    ASSUME_ITS_TRUE(fossil_stack_insert(mock_stack, element2) == 0);
    ASSUME_ITS_TRUE(fossil_stack_insert(mock_stack, element3) == 0);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_stack_size(mock_stack));

    fossil_tofu_erase(&element1);
    fossil_tofu_erase(&element2);
    fossil_tofu_erase(&element3);
}

FOSSIL_TEST(test_stack_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_stack_insert(mock_stack, element1);
    fossil_stack_insert(mock_stack, element2);
    fossil_stack_insert(mock_stack, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_stack_remove(mock_stack, &removedElement) == 0);

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_stack_size(mock_stack));

    fossil_tofu_erase(&element1);
    fossil_tofu_erase(&element2);
    fossil_tofu_erase(&element3);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_stack_structure_tests) {
    // Stack Fixture
    ADD_TESTF(test_stack_create_and_erase, struct_stack_fixture);
    ADD_TESTF(test_stack_insert_and_size, struct_stack_fixture);
    ADD_TESTF(test_stack_remove, struct_stack_fixture);
} // end of tests
