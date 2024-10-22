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

FOSSIL_FIXTURE(struct_pqueue_fixture);
fossil_pqueue_t* mock_pqueue;

FOSSIL_SETUP(struct_pqueue_fixture) {
    mock_pqueue = fossil_pqueue_create("int");
}

FOSSIL_TEARDOWN(struct_pqueue_fixture) {
    fossil_pqueue_destroy(mock_pqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_pqueue_create_and_destroy) {
    // Check if the priority queue is created with the expected values
    ASSUME_NOT_CNULL(mock_pqueue);
    ASSUME_ITS_CNULL(mock_pqueue->front);
}

FOSSIL_TEST(test_pqueue_insert) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element, 2) == 0);
}

FOSSIL_TEST(test_pqueue_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_pqueue_insert(mock_pqueue, element1, 2);
    fossil_pqueue_insert(mock_pqueue, element2, 1);
    fossil_pqueue_insert(mock_pqueue, element3, 3);

    // Remove an element
    fossil_tofu_t removedElement;
    int removedPriority = 0;
    ASSUME_ITS_TRUE(fossil_pqueue_remove(mock_pqueue, &removedElement, removedPriority));
}

FOSSIL_TEST(test_pqueue_search) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    fossil_pqueue_insert(mock_pqueue, element, 2);

    // Search for the element
    ASSUME_ITS_TRUE(fossil_pqueue_search(mock_pqueue, element, 2) == 0);
}

FOSSIL_TEST(test_pqueue_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element1, 2) == 0);
    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element2, 1) == 0);
    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element3, 3) == 0);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_pqueue_size(mock_pqueue));
}

FOSSIL_TEST(test_pqueue_setter_and_getter) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    fossil_pqueue_insert(mock_pqueue, element, 2);

    // Get the element
    fossil_tofu_t* gottenElement = fossil_pqueue_getter(mock_pqueue, element, 2);
    ASSUME_NOT_CNULL(gottenElement);

    // Set the element
    fossil_pqueue_setter(mock_pqueue, element, 2);
    gottenElement = fossil_pqueue_getter(mock_pqueue, element, 2);
    ASSUME_NOT_CNULL(gottenElement);

    fossil_tofu_destroy(&element);
    fossil_tofu_destroy(gottenElement);
}

FOSSIL_TEST(test_pqueue_is_cnullptr) {
    // Check initially cnullptr
    ASSUME_ITS_FALSE(fossil_pqueue_is_cnullptr(mock_pqueue));
}

FOSSIL_TEST(test_pqueue_not_cnullptr) {
    // Check initially not cnullptr
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(mock_pqueue));
}

FOSSIL_TEST(test_pqueue_is_empty) {
    // Check initially empty
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(mock_pqueue));
}

FOSSIL_TEST(test_pqueue_not_empty) {
    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(mock_pqueue));
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(stress_test_pqueue) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    TEST_BENCHMARK();

    for (size_t i = 0; i < 1000000; i++) {
        fossil_pqueue_insert(mock_pqueue, element, 2);
        fossil_pqueue_remove(mock_pqueue, &element, 2);
    }

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_destroy(&element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_pqueue_structure_tests) {    
    // Priority Queue Fixture
    ADD_TESTF(test_pqueue_create_and_destroy, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_insert, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_remove, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_search, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_size, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_setter_and_getter, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_is_cnullptr, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_not_cnullptr, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_is_empty, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_not_empty, struct_pqueue_fixture);

    // Benchmarking
    ADD_TESTF(stress_test_pqueue, struct_pqueue_fixture);
} // end of tests
