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

FOSSIL_FIXTURE(struct_vect_fixture);
fossil_vector_t* mock_vector;

FOSSIL_SETUP(struct_vect_fixture) {
    mock_vector = fossil_vector_create("int");
}

FOSSIL_TEARDOWN(struct_vect_fixture) {
    fossil_vector_erase(mock_vector);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

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

    fossil_tofu_erase(&element1);
    fossil_tofu_erase(&element2);
    fossil_tofu_erase(&element3);
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

    fossil_tofu_erase(&nonExistingElement);
    fossil_tofu_erase(&element1);
    fossil_tofu_erase(&element2);
    fossil_tofu_erase(&element3);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_vector_structure_tests) {    
    // Vector Fixture
    ADD_TESTF(test_vector_push_back, struct_vect_fixture);
    ADD_TESTF(test_vector_search, struct_vect_fixture);
} // end of tests
