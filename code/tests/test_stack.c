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
#include <fossil/benchmark/framework.h>
#include <fossil/unittest/assume.h>

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
    fossil_stack_destroy(mock_stack);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_stack_create_and_destroy) {
    // Check if the stack is created with the expected values
    ASSUME_NOT_CNULL(mock_stack);
    ASSUME_ITS_CNULL(mock_stack->top);
}

FOSSIL_TEST(test_stack_insert) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Check if the element is inserted correctly
    ASSUME_ITS_TRUE(fossil_stack_insert(mock_stack, element) == 0);

    fossil_tofu_destroy(&element);
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

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_stack_search) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_stack_insert(mock_stack, element1);
    fossil_stack_insert(mock_stack, element2);
    fossil_stack_insert(mock_stack, element3);

    // Search for an element
    fossil_tofu_t searchElement = fossil_tofu_create("int", "10");
    ASSUME_ITS_TRUE(fossil_stack_search(mock_stack, searchElement) == 0);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
    fossil_tofu_destroy(&searchElement);
}

FOSSIL_TEST(test_stack_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_stack_insert(mock_stack, element1);
    fossil_stack_insert(mock_stack, element2);
    fossil_stack_insert(mock_stack, element3);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_stack_size(mock_stack));

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_stack_getter_and_setter) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_stack_insert(mock_stack, element1);
    fossil_stack_insert(mock_stack, element2);
    fossil_stack_insert(mock_stack, element3);

    // Get an element
    fossil_tofu_t searchElement = fossil_tofu_create("int", "10");
    fossil_tofu_t* foundElement = fossil_stack_getter(mock_stack, searchElement);
    ASSUME_NOT_CNULL(foundElement);
    ASSUME_ITS_EQUAL_I32(10, foundElement->value.int_val);

    // Set an element
    fossil_tofu_t newElement = fossil_tofu_create("int", "100");
    ASSUME_ITS_TRUE(fossil_stack_setter(mock_stack, newElement) == 0);

    // Check if the element is set correctly
    fossil_tofu_t* updatedElement = fossil_stack_getter(mock_stack, newElement);
    ASSUME_NOT_CNULL(updatedElement);
    ASSUME_ITS_EQUAL_I32(100, updatedElement->value.int_val);
    
    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
    fossil_tofu_destroy(&searchElement);
    fossil_tofu_destroy(&newElement);
}

FOSSIL_TEST(test_stack_is_empty) {
    // Check if the stack is empty
    ASSUME_ITS_TRUE(fossil_stack_is_empty(mock_stack));
}

FOSSIL_TEST(test_stack_not_empty) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    fossil_stack_insert(mock_stack, element);

    // Check if the stack is not empty
    ASSUME_ITS_TRUE(fossil_stack_not_empty(mock_stack));

    fossil_tofu_destroy(&element);
}

FOSSIL_TEST(test_stack_is_cnullptr) {
    // Check if the stack is not a nullptr
    ASSUME_ITS_TRUE(fossil_stack_is_cnullptr(mock_stack) == 0);
}

FOSSIL_TEST(test_stack_not_cnullptr) {
    // Check if the stack is not a nullptr
    ASSUME_ITS_TRUE(fossil_stack_not_cnullptr(mock_stack));
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(stress_test_stack) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    TEST_BENCHMARK();

    for (size_t i = 0; i < 1000000; i++) {
        fossil_stack_insert(mock_stack, element);
        fossil_stack_remove(mock_stack, &element);
    }

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_destroy(&element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_stack_structure_tests) {
    // Stack Fixture
    ADD_TESTF(test_stack_create_and_destroy, struct_stack_fixture);
    ADD_TESTF(test_stack_insert, struct_stack_fixture);
    ADD_TESTF(test_stack_remove, struct_stack_fixture);
    ADD_TESTF(test_stack_search, struct_stack_fixture);
    ADD_TESTF(test_stack_size, struct_stack_fixture);
    // ADD_TESTF(test_stack_getter_and_setter, struct_stack_fixture);
    ADD_TESTF(test_stack_is_empty, struct_stack_fixture);
    ADD_TESTF(test_stack_not_empty, struct_stack_fixture);
    ADD_TESTF(test_stack_is_cnullptr, struct_stack_fixture);
    ADD_TESTF(test_stack_not_cnullptr, struct_stack_fixture);

    // Stack Benchmark
    ADD_TESTF(stress_test_stack, struct_stack_fixture);
} // end of tests
