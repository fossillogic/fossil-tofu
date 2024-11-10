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

FOSSIL_TEST_SUITE(c_queue_fixture);
fossil_queue_t *mock_queue;

FOSSIL_TEST_SETUP(c_queue_fixture) {
    mock_queue = fossil_queue_create("int");
}

FOSSIL_TEST_TEARDOWN(c_queue_fixture) {
    fossil_queue_destroy(mock_queue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(test_queue_create_and_destroy) {
    // Check if the queue is created with the expected values
    ASSUME_NOT_CNULL(mock_queue);
    ASSUME_ITS_CNULL(mock_queue->front);
    ASSUME_ITS_CNULL(mock_queue->rear);
}

FOSSIL_TEST_CASE(test_queue_insert) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    ASSUME_ITS_TRUE(fossil_queue_insert(mock_queue, element) == 0);

    fossil_tofu_destroy(&element);
}

FOSSIL_TEST_CASE(test_queue_remove) {
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

FOSSIL_TEST_CASE(test_queue_search) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_queue_insert(mock_queue, element1);
    fossil_queue_insert(mock_queue, element2);
    fossil_queue_insert(mock_queue, element3);

    // Check if the elements are in the queue
    ASSUME_ITS_TRUE(fossil_queue_search(mock_queue, element1) == 0);
    ASSUME_ITS_TRUE(fossil_queue_search(mock_queue, element3) == 0);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST_CASE(test_queue_is_cnullptr) {
    // Check if the queue is a nullptr
    ASSUME_ITS_FALSE(fossil_queue_is_cnullptr(mock_queue));
}

FOSSIL_TEST_CASE(test_queue_not_cnullptr) {
    // Check if the queue is not a nullptr
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(mock_queue));
}

FOSSIL_TEST_CASE(test_queue_is_empty) {
    // Check if the queue is empty
    ASSUME_ITS_TRUE(fossil_queue_is_empty(mock_queue));
}

FOSSIL_TEST_CASE(test_queue_not_empty) {
    // Check if the queue is not empty
    ASSUME_ITS_FALSE(fossil_queue_not_empty(mock_queue));
}

FOSSIL_TEST_CASE(test_queue_size) {
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

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST_CASE(stress_test_queue) {
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
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_create_and_destroy);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_insert);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_remove);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_search);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_is_cnullptr);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_not_cnullptr);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_is_empty);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_not_empty);
    FOSSIL_TEST_ADD(c_queue_fixture, test_queue_size);
    FOSSIL_TEST_ADD(c_queue_fixture, stress_test_queue);

    FOSSIL_TEST_REGISTER(c_queue_fixture);
} // end of tests
