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

FOSSIL_FIXTURE(struct_queue_fixture);
fossil_queue_t *mock_queue;

FOSSIL_SETUP(struct_queue_fixture) {
    mock_queue = fossil_queue_create("int");
}

FOSSIL_TEARDOWN(struct_queue_fixture) {
    fossil_queue_destroy(mock_queue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_queue_create_and_destroy) {
    // Check if the queue is created with the expected values
    ASSUME_NOT_CNULL(mock_queue);
    ASSUME_ITS_CNULL(mock_queue->front);
    ASSUME_ITS_CNULL(mock_queue->rear);
}

FOSSIL_TEST(test_queue_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element1) == 0);
    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element2) == 0);
    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element3) == 0);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_queue_size(mock_queue));
}

FOSSIL_TEST(test_queue_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_queue_insert(mock_queue, element1);
    fossil_queue_insert(mock_queue, element2);
    fossil_queue_insert(mock_queue, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_queue_remove(mock_queue, &removedElement) == 0);

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(42, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_queue_size(mock_queue));

    fossil_tofu_destroy(&removedElement);
    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_queue_not_empty_and_is_empty) {
    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_queue_not_empty(mock_queue));
    ASSUME_ITS_TRUE(fossil_queue_is_empty(mock_queue));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element) == 0);

    // Check not empty after insertion
    ASSUME_ITS_FALSE(fossil_queue_is_empty(mock_queue));

    fossil_tofu_destroy(&element);
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(stress_test_queue) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    TEST_BENCHMARK();

    for (size_t i = 0; i < 1000000; i++) {
        fossil_queue_insert(mock_queue, element);
        fossil_queue_remove(mock_queue, &element);
    }

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_destroy(&element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_structure_tests) {    
    // Queue Fixture
    ADD_TESTF(test_queue_create_and_destroy, struct_queue_fixture);
    ADD_TESTF(test_queue_insert_and_size, struct_queue_fixture);
    ADD_TESTF(test_queue_remove, struct_queue_fixture);
    ADD_TESTF(test_queue_not_empty_and_is_empty, struct_queue_fixture);

    // Benchmarking
    ADD_TESTF(stress_test_queue, struct_queue_fixture);
} // end of tests
