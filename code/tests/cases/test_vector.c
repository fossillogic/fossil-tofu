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
#include <fossil/pizza/framework.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_SUITE(c_vector_tofu_fixture);

FOSSIL_SETUP(c_vector_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_vector_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_vector_create_and_destroy) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    ASSUME_NOT_CNULL(vector);
    ASSUME_ITS_EQUAL_I32(fossil_vector_size(vector), 0);
    ASSUME_ITS_EQUAL_I32(fossil_vector_capacity(vector), INITIAL_CAPACITY);
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_and_get) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "10");
    fossil_vector_push_back(vector, "20");
    fossil_vector_push_back(vector, "30");
    ASSUME_ITS_EQUAL_I32(fossil_vector_size(vector), 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "10");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "20");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "30");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_front_and_pop_front) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_front(vector, "1");
    fossil_vector_push_front(vector, "2");
    fossil_vector_push_front(vector, "3");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get_front(vector), "3");
    fossil_vector_pop_front(vector);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get_front(vector), "2");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_and_pop_at) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "a");
    fossil_vector_push_back(vector, "b");
    fossil_vector_push_back(vector, "d");
    fossil_vector_push_at(vector, 2, "c"); // Insert "c" at index 2
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "c");
    fossil_vector_pop_at(vector, 1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "c");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_set_and_get) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "100");
    fossil_vector_push_back(vector, "200");
    fossil_vector_set(vector, 1, "250");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "250");
    fossil_vector_set_front(vector, "50");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get_front(vector), "50");
    fossil_vector_set_back(vector, "300");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get_back(vector), "300");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_erase_and_empty) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "1");
    fossil_vector_push_back(vector, "2");
    fossil_vector_erase(vector);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector));
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_copy_and_move) {
    fossil_vector_t* vector1 = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector1, "5");
    fossil_vector_push_back(vector1, "10");
    fossil_vector_t* vector2 = fossil_vector_create_copy(vector1);
    ASSUME_ITS_EQUAL_I32(fossil_vector_size(vector2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector2, 1), "10");
    fossil_vector_t* vector3 = fossil_vector_create_move(vector2);
    ASSUME_ITS_EQUAL_I32(fossil_vector_size(vector3), 2);
    fossil_vector_destroy(vector1);
    fossil_vector_destroy(vector3);
    // vector2 is now empty after move
}

FOSSIL_TEST(c_test_vector_pop_back) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "1");
    fossil_vector_push_back(vector, "2");
    fossil_vector_push_back(vector, "3");
    fossil_vector_pop_back(vector);
    ASSUME_ITS_EQUAL_I32(fossil_vector_size(vector), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get_back(vector), "2");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_beyond_initial_capacity) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    // Push more elements than INITIAL_CAPACITY to test resizing
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        fossil_vector_push_back(vector, buf);
    }
    ASSUME_ITS_TRUE(fossil_vector_size(vector) > INITIAL_CAPACITY);
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, i), buf);
    }
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_until_empty) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "1");
    fossil_vector_push_back(vector, "2");
    fossil_vector_push_back(vector, "3");
    fossil_vector_pop_back(vector);
    fossil_vector_pop_back(vector);
    fossil_vector_pop_back(vector);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector));
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_front_until_empty) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "a");
    fossil_vector_push_back(vector, "b");
    fossil_vector_push_back(vector, "c");
    fossil_vector_pop_front(vector);
    fossil_vector_pop_front(vector);
    fossil_vector_pop_front(vector);
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector));
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_null_pointer_safety) {
    fossil_vector_t* vector = NULL;
    ASSUME_ITS_TRUE(fossil_vector_is_cnullptr(vector));
    ASSUME_ITS_FALSE(fossil_vector_not_cnullptr(vector));
    ASSUME_ITS_TRUE(fossil_vector_is_empty(vector));
    ASSUME_ITS_FALSE(fossil_vector_not_empty(vector));
    ASSUME_ITS_EQUAL_I32(fossil_vector_size(vector), 0);
    ASSUME_ITS_EQUAL_I32(fossil_vector_capacity(vector), 0);
    fossil_vector_pop_back(vector); // Should not crash
    fossil_vector_erase(vector);    // Should not crash
}

FOSSIL_TEST(c_test_vector_set_at_various_positions) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "a");
    fossil_vector_push_back(vector, "b");
    fossil_vector_push_back(vector, "c");
    fossil_vector_set_at(vector, 0, "x");
    fossil_vector_set_at(vector, 1, "y");
    fossil_vector_set_at(vector, 2, "z");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "x");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "y");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "z");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_push_at_beginning_and_end) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "middle");
    fossil_vector_push_at(vector, 0, "start");
    fossil_vector_push_at(vector, 2, "end");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "start");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "middle");
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 2), "end");
    fossil_vector_destroy(vector);
}

FOSSIL_TEST(c_test_vector_pop_at_various_positions) {
    fossil_vector_t* vector = fossil_vector_create_container("i32");
    fossil_vector_push_back(vector, "a");
    fossil_vector_push_back(vector, "b");
    fossil_vector_push_back(vector, "c");
    fossil_vector_push_back(vector, "d");
    fossil_vector_pop_at(vector, 1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 1), "c");
    fossil_vector_pop_at(vector, 0); // Remove "a"
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "c");
    fossil_vector_pop_at(vector, 1); // Remove "d"
    ASSUME_ITS_EQUAL_CSTR(fossil_vector_get(vector, 0), "c");
    ASSUME_ITS_EQUAL_I32(fossil_vector_size(vector), 1);
    fossil_vector_destroy(vector);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_vector_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_create_and_destroy);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_and_get);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_front_and_pop_front);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_and_pop_at);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_set_and_get);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_erase_and_empty);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_copy_and_move);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_back);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_beyond_initial_capacity);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_until_empty);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_front_until_empty);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_null_pointer_safety);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_set_at_various_positions);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_push_at_beginning_and_end);
    FOSSIL_TEST_ADD(c_vector_tofu_fixture, c_test_vector_pop_at_various_positions);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_vector_tofu_fixture);
} // end of tests
