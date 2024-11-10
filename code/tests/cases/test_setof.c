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

FOSSIL_TEST_SUITE(c_set_fixture);
fossil_set_t* mock_set;

FOSSIL_TEST_SETUP(c_set_fixture) {
    mock_set = fossil_set_create("int");
}

FOSSIL_TEST_TEARDOWN(c_set_fixture) {
    fossil_set_destroy(mock_set);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(test_set_create_and_destroy) {
    // Check if the set is created with the expected values
    ASSUME_NOT_CNULL(mock_set);
    ASSUME_ITS_CNULL(mock_set->head);
}

FOSSIL_TEST_CASE(test_set_insert) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    ASSUME_ITS_TRUE(fossil_set_insert(mock_set, element) == 0);

    fossil_tofu_destroy(&element);
}

FOSSIL_TEST_CASE(test_set_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_set_insert(mock_set, element1);
    fossil_set_insert(mock_set, element2);
    fossil_set_insert(mock_set, element3);

    // Remove an element
    ASSUME_ITS_TRUE(fossil_set_remove(mock_set, element2) == 0);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_set_size(mock_set));
}

FOSSIL_TEST_CASE(test_set_search) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_set_insert(mock_set, element1);
    fossil_set_insert(mock_set, element2);
    fossil_set_insert(mock_set, element3);

    // Search for an element
    ASSUME_ITS_TRUE(fossil_set_search(mock_set, element1) == 0);

    // Check for non-existing element
    fossil_tofu_t nonExistingElement = fossil_tofu_create("int", "44");
    ASSUME_NOT_TRUE(fossil_set_search(mock_set, nonExistingElement) == 1);

    fossil_tofu_destroy(&nonExistingElement);
    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST_CASE(test_set_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_set_insert(mock_set, element1) == 0);
    ASSUME_ITS_TRUE(fossil_set_insert(mock_set, element2) == 0);
    ASSUME_ITS_TRUE(fossil_set_insert(mock_set, element3) == 0);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_set_size(mock_set));

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST_CASE(test_set_contains) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_set_insert(mock_set, element1);
    fossil_set_insert(mock_set, element2);
    fossil_set_insert(mock_set, element3);

    // Check if elements are contained in the set
    ASSUME_ITS_TRUE(fossil_set_contains(mock_set, element1));
    ASSUME_ITS_TRUE(fossil_set_contains(mock_set, element3));

    // Check for non-existing element
    fossil_tofu_t nonExistingElement = fossil_tofu_create("int", "42");
    ASSUME_ITS_FALSE(fossil_set_contains(mock_set, nonExistingElement) == 0);

    fossil_tofu_destroy(&nonExistingElement);
    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST_CASE(test_set_is_cnullptr) {
    // Check if the set is not a nullptr
    ASSUME_ITS_FALSE(fossil_set_is_cnullptr(mock_set));
}

FOSSIL_TEST_CASE(test_set_not_cnullptr) {
    // Check if the set is not a nullptr
    ASSUME_ITS_TRUE(fossil_set_not_cnullptr(mock_set));
}

FOSSIL_TEST_CASE(test_set_is_empty) {
    // Check if the set is empty
    ASSUME_ITS_TRUE(fossil_set_is_empty(mock_set));
}

FOSSIL_TEST_CASE(test_set_not_empty) {
    // Check if the set is empty
    ASSUME_ITS_FALSE(fossil_set_not_empty(mock_set));
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST_CASE(stress_test_set) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    TEST_BENCHMARK();

    for (size_t i = 0; i < 1000000; i++) {
        fossil_set_insert(mock_set, element);
        fossil_set_remove(mock_set, element);
    }

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_destroy(&element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_setof_structure_tests) {
    // Set Fixture
    FOSSIL_TEST_ADD(c_set_fixture, test_set_create_and_destroy);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_insert);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_remove);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_search);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_size);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_contains);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_is_cnullptr);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_not_cnullptr);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_is_empty);
    FOSSIL_TEST_ADD(c_set_fixture, test_set_not_empty);
    FOSSIL_TEST_ADD(c_set_fixture, stress_test_set);

    FOSSIL_TEST_REGISTER(c_set_fixture);
} // end of tests
