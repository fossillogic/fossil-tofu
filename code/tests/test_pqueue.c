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
    fossil_pqueue_erase(mock_pqueue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_pqueue_create_and_erase) {
    // Check if the priority queue is created with the expected values
    ASSUME_NOT_CNULL(mock_pqueue);
    ASSUME_ITS_CNULL(mock_pqueue->front);
}

FOSSIL_TEST(test_pqueue_insert_and_size) {
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

FOSSIL_TEST(test_pqueue_not_empty_and_is_empty) {
    // Check initially not empty
    ASSUME_ITS_FALSE(fossil_pqueue_not_empty(mock_pqueue));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(mock_pqueue));

    // Insert an element
    fossil_tofu_t element = fossil_tofu_create("int", "42");
    ASSUME_ITS_TRUE(fossil_pqueue_insert(mock_pqueue, element, 2) == 0);

    // Check not empty after insertion
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(mock_pqueue));

    // Remove the element
    fossil_tofu_t removedElement;
    int removedPriority = 0;
    ASSUME_ITS_TRUE(fossil_pqueue_remove(mock_pqueue, &removedElement, removedPriority));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_pqueue_structure_tests) {    
    // Priority Queue Fixture
    ADD_TESTF(test_pqueue_create_and_erase, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_insert_and_size, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_remove, struct_pqueue_fixture);
    ADD_TESTF(test_pqueue_not_empty_and_is_empty, struct_pqueue_fixture);
} // end of tests
