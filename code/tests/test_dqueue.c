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

#include <fossil/tofu/framework.h>

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(struct_dqueue_fixture);
fossil_dqueue_t* mock_dqueue;

FOSSIL_SETUP(struct_dqueue_fixture) {
    mock_dqueue = fossil_dqueue_create("int");
}

FOSSIL_TEARDOWN(struct_dqueue_fixture) {
    fossil_dqueue_erase(mock_dqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_dqueue_create_and_erase) {
    // Check if the deque is created with the expected values
    ASSUME_NOT_CNULL(mock_dqueue);
    ASSUME_ITS_CNULL(mock_dqueue->front);
    ASSUME_ITS_CNULL(mock_dqueue->rear);
}

FOSSIL_TEST(test_dqueue_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dqueue_insert(mock_dqueue, element1);
    fossil_dqueue_insert(mock_dqueue, element2);
    fossil_dqueue_insert(mock_dqueue, element3);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_dqueue_size(mock_dqueue));
}

FOSSIL_TEST(test_dqueue_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dqueue_insert(mock_dqueue, element1);
    fossil_dqueue_insert(mock_dqueue, element2);
    fossil_dqueue_insert(mock_dqueue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    fossil_dqueue_remove(mock_dqueue, &removedElement);

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_dqueue_size(mock_dqueue));
}

FOSSIL_TEST(test_dqueue_getter_and_setter) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_dqueue_insert(mock_dqueue, element));

    // Get the value for an element
    fossil_tofu_t* retrievedElement = fossil_dqueue_getter(mock_dqueue, element);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);

    // Update the value for an element
    fossil_tofu_t updatedElement = fossil_tofu_create("int", "50");
    ASSUME_ITS_TRUE(fossil_dqueue_setter(mock_dqueue, updatedElement));

    // Get the updated value for the element
    retrievedElement = fossil_dqueue_getter(mock_dqueue, updatedElement);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(50, retrievedElement->value.int_val);
}

FOSSIL_TEST(test_dqueue_not_empty_and_is_empty) {
    // Check initially empty
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(mock_dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(mock_dqueue));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    fossil_dqueue_insert(mock_dqueue, element);

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(mock_dqueue));
    ASSUME_ITS_FALSE(fossil_dqueue_is_empty(mock_dqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    fossil_dqueue_remove(mock_dqueue, &removedElement);

    // Check empty after removal
    ASSUME_ITS_FALSE(fossil_dqueue_not_empty(mock_dqueue));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(mock_dqueue));
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(benchmark_dqueue_insert) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    MARK_START(dqueue_insert);

    // Insert the element
    fossil_dqueue_insert(mock_dqueue, element);

    // Stop the benchmark
    MARK_STOP(dqueue_insert);

    fossil_tofu_erase(&element);
}

FOSSIL_TEST(benchmark_dqueue_remove) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Insert the element
    fossil_dqueue_insert(mock_dqueue, element);

    // Start the benchmark
    MARK_START(dqueue_remove);

    // Remove the element
    fossil_tofu_t removedElement;
    fossil_dqueue_remove(mock_dqueue, &removedElement);

    // Stop the benchmark
    MARK_STOP(dqueue_remove);

    fossil_tofu_erase(&element);
}

FOSSIL_TEST(benchmark_dqueue_size) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Insert the element
    fossil_dqueue_insert(mock_dqueue, element);

    // Start the benchmark
    MARK_START(dqueue_size);

    // Get the size
    fossil_dqueue_size(mock_dqueue);

    // Stop the benchmark
    MARK_STOP(dqueue_size);

    fossil_tofu_erase(&element);
}

FOSSIL_TEST(benchmark_dqueue_not_empty) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Insert the element
    fossil_dqueue_insert(mock_dqueue, element);

    // Start the benchmark
    MARK_START(dqueue_not_empty);

    for (size_t i = 0; i < 1000000; i++) {
        fossil_dqueue_not_empty(mock_dqueue);
    }

    // Stop the benchmark
    MARK_STOP(dqueue_not_empty);

    fossil_tofu_erase(&element);
}

FOSSIL_TEST(benchmark_dqueue_is_empty) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Insert the element
    fossil_dqueue_insert(mock_dqueue, element);

    // Start the benchmark
    MARK_START(dqueue_is_empty);

    for (size_t i = 0; i < 1000000; i++) {
        fossil_dqueue_is_empty(mock_dqueue);
    }

    // Stop the benchmark
    MARK_STOP(dqueue_is_empty);

    fossil_tofu_erase(&element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_dqueue_structure_tests) {    
    ADD_TESTF(test_dqueue_create_and_erase, struct_dqueue_fixture);
    ADD_TESTF(test_dqueue_insert_and_size, struct_dqueue_fixture);
    ADD_TESTF(test_dqueue_remove, struct_dqueue_fixture);
    //ADD_TESTF(test_dqueue_getter_and_setter, struct_dqueue_fixture);
    ADD_TESTF(test_dqueue_not_empty_and_is_empty, struct_dqueue_fixture);

    // Benchmarking cases
    ADD_TEST(benchmark_dqueue_insert);
    ADD_TEST(benchmark_dqueue_remove);
    ADD_TEST(benchmark_dqueue_size);
    ADD_TEST(benchmark_dqueue_not_empty);
    ADD_TEST(benchmark_dqueue_is_empty);
} // end of tests
