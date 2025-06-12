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

FOSSIL_SUITE(cpp_vector_tofu_fixture);

FOSSIL_SETUP(cpp_vector_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_vector_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::Vector;

FOSSIL_TEST(cpp_test_vector_create_and_destroy) {
    Vector vector("i32");
    ASSUME_ITS_EQUAL_I32(vector.size(), 0);
}

FOSSIL_TEST(cpp_test_vector_push_and_get) {
    Vector vector("i32");
    vector.push_back("10");
    vector.push_back("20");
    vector.push_back("30");
    ASSUME_ITS_EQUAL_I32(vector.size(), 3);
    ASSUME_ITS_EQUAL_CSTR(vector.get(0).c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1).c_str(), "20");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2).c_str(), "30");
}

FOSSIL_TEST(cpp_test_vector_push_front_and_pop_front) {
    Vector vector("i32");
    vector.push_front("1");
    vector.push_front("2");
    vector.push_front("3");
    ASSUME_ITS_EQUAL_CSTR(vector.get_front().c_str(), "3");
    vector.pop_front();
    ASSUME_ITS_EQUAL_CSTR(vector.get_front().c_str(), "2");
}

FOSSIL_TEST(cpp_test_vector_push_at_and_pop_at) {
    Vector vector("i32");
    vector.push_back("a");
    vector.push_back("b");
    vector.push_back("d");
    vector.push_at(2, "c"); // Insert "c" at index 2
    ASSUME_ITS_EQUAL_CSTR(vector.get(2).c_str(), "c");
    vector.pop_at(1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(vector.get(1).c_str(), "c");
}

FOSSIL_TEST(cpp_test_vector_set_and_get) {
    Vector vector("i32");
    vector.push_back("100");
    vector.push_back("200");
    vector.set(1, "250");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1).c_str(), "250");
    vector.set_front("50");
    ASSUME_ITS_EQUAL_CSTR(vector.get_front().c_str(), "50");
    vector.set_back("300");
    ASSUME_ITS_EQUAL_CSTR(vector.get_back().c_str(), "300");
}

FOSSIL_TEST(cpp_test_vector_erase_and_empty) {
    Vector vector("i32");
    vector.push_back("1");
    vector.push_back("2");
    vector.erase();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_copy_and_move) {
    Vector vector1("i32");
    vector1.push_back("5");
    vector1.push_back("10");
    Vector vector2 = vector1;
    ASSUME_ITS_EQUAL_I32(vector2.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(vector2.get(1).c_str(), "10");
    Vector vector3 = std::move(vector2);
    ASSUME_ITS_EQUAL_I32(vector3.size(), 2);
    // vector2 is now empty after move
}

FOSSIL_TEST(cpp_test_vector_pop_back) {
    Vector vector("i32");
    vector.push_back("1");
    vector.push_back("2");
    vector.push_back("3");
    vector.pop_back();
    ASSUME_ITS_EQUAL_I32(vector.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(vector.get_back().c_str(), "2");
}

FOSSIL_TEST(cpp_test_vector_push_beyond_initial_capacity) {
    Vector vector("i32");
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        vector.push_back(buf);
    }
    ASSUME_ITS_TRUE(vector.size() > INITIAL_CAPACITY);
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        ASSUME_ITS_EQUAL_CSTR(vector.get(i).c_str(), buf);
    }
}

FOSSIL_TEST(cpp_test_vector_pop_until_empty) {
    Vector vector("i32");
    vector.push_back("1");
    vector.push_back("2");
    vector.push_back("3");
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    ASSUME_ITS_TRUE(vector.is_empty());
}

FOSSIL_TEST(cpp_test_vector_pop_front_until_empty) {
    Vector vector("i32");
    vector.push_back("a");
    vector.push_back("b");
    vector.push_back("c");
    vector.pop_front();
    vector.pop_front();
    vector.pop_front();
    ASSUME_ITS_TRUE(vector.is_empty());
}

// Null pointer safety is not directly applicable to C++ class, but we can check default construction
FOSSIL_TEST(cpp_test_vector_null_pointer_safety) {
    Vector* vector = nullptr;
    ASSUME_ITS_TRUE(vector == nullptr);
}

FOSSIL_TEST(cpp_test_vector_set_at_various_positions) {
    Vector vector("i32");
    vector.push_back("a");
    vector.push_back("b");
    vector.push_back("c");
    vector.set_at(0, "x");
    vector.set_at(1, "y");
    vector.set_at(2, "z");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0).c_str(), "x");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1).c_str(), "y");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2).c_str(), "z");
}

FOSSIL_TEST(cpp_test_vector_push_at_beginning_and_end) {
    Vector vector("i32");
    vector.push_back("middle");
    vector.push_at(0, "start");
    vector.push_at(2, "end");
    ASSUME_ITS_EQUAL_CSTR(vector.get(0).c_str(), "start");
    ASSUME_ITS_EQUAL_CSTR(vector.get(1).c_str(), "middle");
    ASSUME_ITS_EQUAL_CSTR(vector.get(2).c_str(), "end");
}

FOSSIL_TEST(cpp_test_vector_pop_at_various_positions) {
    Vector vector("i32");
    vector.push_back("a");
    vector.push_back("b");
    vector.push_back("c");
    vector.push_back("d");
    vector.pop_at(1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(vector.get(1).c_str(), "c");
    vector.pop_at(0); // Remove "a"
    ASSUME_ITS_EQUAL_CSTR(vector.get(0).c_str(), "c");
    vector.pop_at(1); // Remove "d"
    ASSUME_ITS_EQUAL_CSTR(vector.get(0).c_str(), "c");
    ASSUME_ITS_EQUAL_I32(vector.size(), 1);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_vector_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_and_get);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_front_and_pop_front);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_at_and_pop_at);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_set_and_get);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_erase_and_empty);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_copy_and_move);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_back);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_beyond_initial_capacity);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_until_empty);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_front_until_empty);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_null_pointer_safety);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_set_at_various_positions);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_push_at_beginning_and_end);
    FOSSIL_TEST_ADD(cpp_vector_tofu_fixture, cpp_test_vector_pop_at_various_positions);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_vector_tofu_fixture);
} // end of tests
