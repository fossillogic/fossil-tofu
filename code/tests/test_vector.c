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

FOSSIL_FIXTURE(struct_vect_fixture);
fossil_vector_t* mock_vector;

FOSSIL_SETUP(struct_vect_fixture) {
    mock_vector = fossil_vector_create("int");
}

FOSSIL_TEARDOWN(struct_vect_fixture) {
    fossil_vector_destroy(mock_vector);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_vector_push_front) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_front(mock_vector, element1);
    fossil_vector_push_front(mock_vector, element2);
    fossil_vector_push_front(mock_vector, element3);

    // Check if the elements are added correctly
    ASSUME_ITS_EQUAL_U32(3, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, mock_vector->data[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[2].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_push_back) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Check if the elements are added correctly
    ASSUME_ITS_EQUAL_U32(3, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, mock_vector->data[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[2].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_push_at) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Push at some elements
    fossil_tofu_t element4 = fossil_tofu_create("int", "100");
    fossil_vector_push_at(mock_vector, 1, element4);

    // Check if the elements are added correctly
    ASSUME_ITS_EQUAL_U32(4, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(100, mock_vector->data[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, mock_vector->data[2].value.int_val);
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[3].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
    fossil_tofu_destroy(&element4);
}

FOSSIL_TEST(test_vector_pop_front) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_front(mock_vector, element1);
    fossil_vector_push_front(mock_vector, element2);
    fossil_vector_push_front(mock_vector, element3);

    // Pop front some elements
    fossil_vector_pop_front(mock_vector);
    fossil_vector_pop_front(mock_vector);

    // Check if the elements are removed correctly
    ASSUME_ITS_EQUAL_U32(1, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_pop_back) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Pop back some elements
    fossil_vector_pop_back(mock_vector);
    fossil_vector_pop_back(mock_vector);

    // Check if the elements are removed correctly
    ASSUME_ITS_EQUAL_U32(1, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_pop_at) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Pop at some elements
    fossil_vector_pop_at(mock_vector, 1);

    // Check if the elements are removed correctly
    ASSUME_ITS_EQUAL_U32(2, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[1].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_erase) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Erase some elements
    fossil_vector_erase(mock_vector, 1);

    // Check if the elements are removed correctly
    ASSUME_ITS_EQUAL_U32(2, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[1].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_erase_if) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Erase some elements
    fossil_tofu_t targetElement = fossil_tofu_create("int", "10");
    fossil_vector_erase_if(mock_vector, targetElement);

    // Check if the elements are removed correctly
    ASSUME_ITS_EQUAL_U32(2, mock_vector->size);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[1].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
    fossil_tofu_destroy(&targetElement);
}

FOSSIL_TEST(test_vector_search) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Search for elements
    ASSUME_ITS_EQUAL_I32(0, fossil_vector_search(mock_vector, element1));
    ASSUME_ITS_EQUAL_I32(1, fossil_vector_search(mock_vector, element2));
    ASSUME_ITS_EQUAL_I32(2, fossil_vector_search(mock_vector, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = fossil_tofu_create("int", "100");
    ASSUME_ITS_EQUAL_I32(-1, fossil_vector_search(mock_vector, nonExistingElement));

    fossil_tofu_destroy(&nonExistingElement);
    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_reverse) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Reverse the vector
    fossil_vector_reverse(mock_vector);

    // Check if the elements are reversed
    ASSUME_ITS_EQUAL_I32(5, mock_vector->data[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, mock_vector->data[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(42, mock_vector->data[2].value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_size) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Check the size of the vector
    ASSUME_ITS_EQUAL_U32(3, fossil_vector_size(mock_vector));

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
}

FOSSIL_TEST(test_vector_is_cullptr) {
    // Check if the vector is cullptr
    ASSUME_ITS_FALSE(fossil_vector_is_cnullptr(mock_vector));
}

FOSSIL_TEST(test_vector_not_cullptr) {
    // Check if the vector is not cullptr
    ASSUME_ITS_TRUE(fossil_vector_not_cnullptr(mock_vector));
}

FOSSIL_TEST(test_vector_is_empty) {
    // Check if the vector is empty
    ASSUME_ITS_TRUE(fossil_vector_is_empty(mock_vector));
}

FOSSIL_TEST(test_vector_not_empty) {
    // Check if the vector is not empty
    ASSUME_ITS_FALSE(fossil_vector_not_empty(mock_vector));
}

FOSSIL_TEST(test_vector_is_capacity) {
    // Check the capacity of the vector
    ASSUME_ITS_EQUAL_SIZE(INITIAL_CAPACITY, fossil_vector_capacity(mock_vector));
}

FOSSIL_TEST(test_vector_is_setter_and_getter) {
    // Push back some elements
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    fossil_vector_push_back(mock_vector, element1);
    fossil_vector_push_back(mock_vector, element2);
    fossil_vector_push_back(mock_vector, element3);

    // Set and get some elements
    fossil_tofu_t element4 = fossil_tofu_create("int", "100");
    fossil_vector_setter(mock_vector, 1, element4);
    fossil_tofu_t* element = fossil_vector_getter(mock_vector, 1);

    // Check if the elements are set and get correctly
    ASSUME_ITS_EQUAL_I32(100, element->value.int_val);

    fossil_tofu_destroy(&element1);
    fossil_tofu_destroy(&element2);
    fossil_tofu_destroy(&element3);
    fossil_tofu_destroy(&element4);
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(stress_test_vector_usage) {
    // setup nodes
    fossil_tofu_t element1 = fossil_tofu_create("int", "42");
    fossil_tofu_t element2 = fossil_tofu_create("int", "10");
    fossil_tofu_t element3 = fossil_tofu_create("int", "5");

    // Start the benchmark
    TEST_BENCHMARK();

    for (size_t i = 0; i < 1000000; i++) {
        fossil_vector_push_back(mock_vector, element1);
        fossil_vector_push_back(mock_vector, element2);
        fossil_vector_push_back(mock_vector, element3);
    }

    // Stop the benchmark
    TEST_DURATION_SEC(TEST_CURRENT_TIME(), 1.0);

    // Check if the elements are added correctly
    ASSUME_ITS_EQUAL_I32(3000000, mock_vector->size);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_vector_structure_tests) {    
    // Vector Fixture
    ADD_TESTF(test_vector_push_front, struct_vect_fixture);
    ADD_TESTF(test_vector_push_back, struct_vect_fixture);
    ADD_TESTF(test_vector_push_at, struct_vect_fixture);
    ADD_TESTF(test_vector_pop_front, struct_vect_fixture);
    ADD_TESTF(test_vector_pop_back, struct_vect_fixture);
    ADD_TESTF(test_vector_pop_at, struct_vect_fixture);
    ADD_TESTF(test_vector_erase, struct_vect_fixture);
    ADD_TESTF(test_vector_erase_if, struct_vect_fixture);
    ADD_TESTF(test_vector_search, struct_vect_fixture);
    ADD_TESTF(test_vector_reverse, struct_vect_fixture);
    ADD_TESTF(test_vector_size, struct_vect_fixture);
    ADD_TESTF(test_vector_is_cullptr, struct_vect_fixture);
    ADD_TESTF(test_vector_not_cullptr, struct_vect_fixture);
    ADD_TESTF(test_vector_is_empty, struct_vect_fixture);
    ADD_TESTF(test_vector_not_empty, struct_vect_fixture);
    ADD_TESTF(test_vector_is_capacity, struct_vect_fixture);
    // ADD_TESTF(test_vector_is_setter_and_getter, struct_vect_fixture);

    // Vector Benchmark
    ADD_TESTF(stress_test_vector_usage, struct_vect_fixture);
} // end of tests
