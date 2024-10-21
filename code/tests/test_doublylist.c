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

FOSSIL_FIXTURE(struct_dlist_fixture);
fossil_dlist_t* mock_dlist;

FOSSIL_SETUP(struct_dlist_fixture) {
    mock_dlist = fossil_dlist_create("int");
}

FOSSIL_TEARDOWN(struct_dlist_fixture) {
    fossil_dlist_destroy(mock_dlist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_dlist_create_and_destroy) {
    // Check if the doubly linked list is created with the expected values
    ASSUME_NOT_CNULL(mock_dlist);
    ASSUME_ITS_CNULL(mock_dlist->head);
    ASSUME_ITS_CNULL(mock_dlist->tail);
}

FOSSIL_TEST(test_dlist_insert_and_size) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dlist_insert(mock_dlist, element1);
    fossil_dlist_insert(mock_dlist, element2);
    fossil_dlist_insert(mock_dlist, element3);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(3, fossil_dlist_size(mock_dlist));
}

FOSSIL_TEST(test_dlist_remove) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dlist_insert(mock_dlist, element1);
    fossil_dlist_insert(mock_dlist, element2);
    fossil_dlist_insert(mock_dlist, element3);

    // Remove an element
    fossil_tofu_t removedElement;
    fossil_dlist_remove(mock_dlist, &removedElement);

    // Check if the removed element is correct
    ASSUME_ITS_EQUAL_I32(5, removedElement.value.int_val);

    // Check if the size is correct
    ASSUME_ITS_EQUAL_SIZE(2, fossil_dlist_size(mock_dlist));  // Updated expected size to 2
}

FOSSIL_TEST(test_dlist_reverse_forward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dlist_insert(mock_dlist, element1);
    fossil_dlist_insert(mock_dlist, element2);
    fossil_dlist_insert(mock_dlist, element3);

    // Reverse the doubly linked list forward
    fossil_dlist_reverse_forward(mock_dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(mock_dlist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);  // Updated to reflect correct order

    retrievedElement = fossil_dlist_getter(mock_dlist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_dlist_getter(mock_dlist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);
}

FOSSIL_TEST(test_dlist_reverse_backward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_dlist_insert(mock_dlist, element1);
    fossil_dlist_insert(mock_dlist, element2);
    fossil_dlist_insert(mock_dlist, element3);

    // Reverse the doubly linked list backward
    fossil_dlist_reverse_backward(mock_dlist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_dlist_getter(mock_dlist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);  // Updated to reflect correct order

    retrievedElement = fossil_dlist_getter(mock_dlist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_dlist_getter(mock_dlist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(stress_test_dlist) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    TEST_BENCHMARK();

    // Insert the element
    fossil_dlist_insert(mock_dlist, element);

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_destroy(&element);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_dlist_structure_tests) {    
    ADD_TESTF(test_dlist_create_and_destroy, struct_dlist_fixture);
    ADD_TESTF(test_dlist_insert_and_size, struct_dlist_fixture);
    ADD_TESTF(test_dlist_remove, struct_dlist_fixture);
    ADD_TESTF(test_dlist_reverse_forward, struct_dlist_fixture);
    ADD_TESTF(test_dlist_reverse_backward, struct_dlist_fixture);

    ADD_TESTF(stress_test_dlist, struct_dlist_fixture);
} // end of tests
