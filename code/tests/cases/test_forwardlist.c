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

FOSSIL_TEST_SUITE(c_flist_fixture);
fossil_flist_t* mock_flist;

FOSSIL_SETUP(c_flist_fixture) {
    mock_flist = fossil_flist_create("int");
}

FOSSIL_TEARDOWN(c_flist_fixture) {
    fossil_flist_destroy(mock_flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(test_flist_create_and_destroy) {
    // Check if the linked list is created with the expected values
    ASSUME_ITS_CNULL(mock_flist->head);
}

FOSSIL_TEST_CASE(test_flist_insert) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_flist_insert(mock_flist, element) == 0);
}

FOSSIL_TEST_CASE(test_flist_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    ASSUME_ITS_TRUE(fossil_flist_remove(mock_flist, &removedElement) == 0);

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_flist_size(mock_flist));
}

FOSSIL_TEST_CASE(test_flist_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    ASSUME_ITS_TRUE(fossil_flist_insert(mock_flist, element1) == 0);
    ASSUME_ITS_TRUE(fossil_flist_insert(mock_flist, element2) == 0);
    ASSUME_ITS_TRUE(fossil_flist_insert(mock_flist, element3) == 0);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_flist_size(mock_flist));
}

FOSSIL_TEST_CASE(test_flist_search) {
    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    fossil_flist_insert(mock_flist, element);

    // Search for the element
    ASSUME_ITS_TRUE(fossil_flist_search(mock_flist, element) == 0);

    // Search for a non-existent element
    fossil_tofu_t nonExistentElement = fossil_tofu_create("int", "100");
    ASSUME_ITS_TRUE(fossil_flist_search(mock_flist, nonExistentElement) == -1);

    fossil_tofu_destroy(&nonExistentElement);
    fossil_tofu_destroy(&element);
}

FOSSIL_TEST_CASE(test_flist_reverse_forward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Reverse the linked list forward
    fossil_flist_reverse_forward(mock_flist);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST_CASE(test_flist_reverse_backward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Reverse the linked list backward
    fossil_flist_reverse_backward(mock_flist);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST_CASE(test_flist_is_empty) {
    // Check initially empty
    ASSUME_ITS_TRUE(fossil_flist_is_empty(mock_flist));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    fossil_flist_insert(mock_flist, element);

    // Check if the linked list is not empty
    ASSUME_ITS_FALSE(fossil_flist_is_empty(mock_flist));

    fossil_tofu_destroy(&element);
}

FOSSIL_TEST_CASE(test_flist_not_empty) {
    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_flist_not_empty(mock_flist));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    fossil_flist_insert(mock_flist, element);

    // Check if the linked list is not empty
    ASSUME_ITS_TRUE(fossil_flist_not_empty(mock_flist));

    fossil_tofu_destroy(&element);
}

FOSSIL_TEST_CASE(test_flist_is_cnullptr) {
    // Check initially cnullptr
    ASSUME_ITS_FALSE(fossil_flist_is_cnullptr(mock_flist));
}

FOSSIL_TEST_CASE(test_flist_not_cnullptr) {
    // Check initially not cnullptr
    ASSUME_ITS_TRUE(fossil_flist_not_cnullptr(mock_flist));
}


// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST_CASE(stress_test_flist) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    TEST_BENCHMARK();

    for (size_t i = 0; i < 1000000; i++) {
        fossil_flist_insert(mock_flist, element);
        fossil_flist_remove(mock_flist, &element);
    }

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_destroy(&element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_flist_structure_tests) {    
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_create_and_destroy);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_insert);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_remove);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_size);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_search);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_reverse_forward);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_reverse_backward);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_is_empty);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_not_empty);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_is_cnullptr);
    FOSSIL_TEST_ADD(c_flist_fixture, test_flist_not_cnullptr);
    FOSSIL_TEST_ADD(c_flist_fixture, stress_test_flist);

    FOSSIL_TEST_REGISTER(c_flist_fixture);
} // end of tests
