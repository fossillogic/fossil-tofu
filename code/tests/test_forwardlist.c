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

FOSSIL_FIXTURE(struct_flist_fixture);
fossil_flist_t* mock_flist;

FOSSIL_SETUP(struct_flist_fixture) {
    mock_flist = fossil_flist_create("int");
}

FOSSIL_TEARDOWN(struct_flist_fixture) {
    fossil_flist_erase(mock_flist);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_flist_create_and_erase) {
    // Check if the linked list is created with the expected values
    ASSUME_ITS_CNULL(mock_flist->head);
}

FOSSIL_TEST(test_flist_insert_and_size) {
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

FOSSIL_TEST(test_flist_remove) {
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

FOSSIL_TEST(test_flist_reverse_forward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Reverse the linked list forward
    fossil_flist_reverse_forward(mock_flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(mock_flist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);
}

FOSSIL_TEST(test_flist_reverse_backward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Reverse the linked list backward
    fossil_flist_reverse_backward(mock_flist);

    // Check if the elements are in reverse order
    fossil_tofu_t* retrievedElement = fossil_flist_getter(mock_flist, element3);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(5, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element2);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(10, retrievedElement->value.int_val);

    retrievedElement = fossil_flist_getter(mock_flist, element1);
    ASSUME_NOT_CNULL(retrievedElement);
    ASSUME_ITS_EQUAL_I32(42, retrievedElement->value.int_val);
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(benchmark_flist_insert) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Start the benchmark
    TEST_BENCHMARK();

    // Insert the element
    fossil_flist_insert(mock_flist, element);

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_erase(&element);
}

FOSSIL_TEST(benchmark_flist_remove) {
    // Create an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");

    // Insert the element
    fossil_flist_insert(mock_flist, element);

    // Start the benchmark
    TEST_BENCHMARK();

    // Remove the element
    fossil_tofu_t removedElement;
    fossil_flist_remove(mock_flist, &removedElement);

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_erase(&element);
}

FOSSIL_TEST(benchmark_flist_reverse_forward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Start the benchmark
    TEST_BENCHMARK();

    // Reverse the linked list forward
    fossil_flist_reverse_forward(mock_flist);

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_erase(&element1);
    fossil_tofu_erase(&element2);
    fossil_tofu_erase(&element3);
}

FOSSIL_TEST(benchmark_flist_reverse_backward) {
    // Insert some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_flist_insert(mock_flist, element1);
    fossil_flist_insert(mock_flist, element2);
    fossil_flist_insert(mock_flist, element3);

    // Start the benchmark
    TEST_BENCHMARK();

    // Reverse the linked list backward
    fossil_flist_reverse_backward(mock_flist);

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    fossil_tofu_erase(&element1);
    fossil_tofu_erase(&element2);
    fossil_tofu_erase(&element3);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_flist_structure_tests) {    
    ADD_TESTF(test_flist_create_and_erase, struct_flist_fixture);
    ADD_TESTF(test_flist_insert_and_size, struct_flist_fixture);
    ADD_TESTF(test_flist_remove, struct_flist_fixture);
    ADD_TESTF(test_flist_reverse_forward, struct_flist_fixture);
    ADD_TESTF(test_flist_reverse_backward, struct_flist_fixture);

    // Benchmarking cases
    ADD_TEST(benchmark_flist_insert);
    ADD_TEST(benchmark_flist_remove);
    ADD_TEST(benchmark_flist_reverse_forward);
    ADD_TEST(benchmark_flist_reverse_backward);
} // end of tests
