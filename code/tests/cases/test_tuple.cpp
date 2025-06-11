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

FOSSIL_SUITE(cpp_tuple_tofu_fixture);

FOSSIL_SETUP(cpp_tuple_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_tuple_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::Tuple;

FOSSIL_TEST(cpp_test_tuple_create_and_destroy) {
    Tuple tuple("i32");
    ASSUME_ITS_EQUAL_I32(tuple.size(), 0);
}

FOSSIL_TEST(cpp_test_tuple_create_default) {
    Tuple tuple;
    ASSUME_ITS_EQUAL_I32(tuple.size(), 0);
}

FOSSIL_TEST(cpp_test_tuple_add_and_get) {
    Tuple tuple("i32");
    tuple.add("10");
    tuple.add("20");
    tuple.add("30");
    ASSUME_ITS_EQUAL_I32(tuple.size(), 3);
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0).c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(tuple.get(1).c_str(), "20");
    ASSUME_ITS_EQUAL_CSTR(tuple.get(2).c_str(), "30");
}

FOSSIL_TEST(cpp_test_tuple_get_front_and_back) {
    Tuple tuple("i32");
    tuple.add("100");
    tuple.add("200");
    tuple.add("300");
    ASSUME_ITS_EQUAL_CSTR(tuple.get_front().c_str(), "100");
    ASSUME_ITS_EQUAL_CSTR(tuple.get_back().c_str(), "300");
}

FOSSIL_TEST(cpp_test_tuple_set_and_get) {
    Tuple tuple("i32");
    tuple.add("1");
    tuple.add("2");
    tuple.add("3");
    tuple.set(1, "42");
    ASSUME_ITS_EQUAL_CSTR(tuple.get(1).c_str(), "42");
    tuple.set_front("99");
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0).c_str(), "99");
    tuple.set_back("77");
    ASSUME_ITS_EQUAL_CSTR(tuple.get(2).c_str(), "77");
}

FOSSIL_TEST(cpp_test_tuple_remove) {
    Tuple tuple("i32");
    tuple.add("a");
    tuple.add("b");
    tuple.add("c");
    tuple.remove(1); // remove "b"
    ASSUME_ITS_EQUAL_I32(tuple.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0).c_str(), "a");
    ASSUME_ITS_EQUAL_CSTR(tuple.get(1).c_str(), "c");
}

FOSSIL_TEST(cpp_test_tuple_clear_and_is_empty) {
    Tuple tuple("i32");
    tuple.add("x");
    tuple.add("y");
    ASSUME_ITS_FALSE(tuple.is_empty());
    tuple.clear();
    ASSUME_ITS_TRUE(tuple.is_empty());
    ASSUME_ITS_EQUAL_I32(tuple.size(), 0);
}

FOSSIL_TEST(cpp_test_tuple_capacity_growth) {
    Tuple tuple("i32");
    size_t initial_capacity = tuple.capacity();
    for (int i = 0; i < (int)initial_capacity + 2; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        tuple.add(buf);
    }
    ASSUME_ITS_TRUE(tuple.capacity() > initial_capacity);
}

FOSSIL_TEST(cpp_test_tuple_copy_constructor) {
    Tuple tuple1("i32");
    tuple1.add("1");
    tuple1.add("2");
    Tuple tuple2 = tuple1;
    ASSUME_ITS_EQUAL_I32(tuple2.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(tuple2.get(0).c_str(), "1");
    ASSUME_ITS_EQUAL_CSTR(tuple2.get(1).c_str(), "2");
}

FOSSIL_TEST(cpp_test_tuple_move_constructor) {
    Tuple tuple1("i32");
    tuple1.add("5");
    tuple1.add("6");
    Tuple tuple2 = std::move(tuple1);
    ASSUME_ITS_EQUAL_I32(tuple2.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(tuple2.get(0).c_str(), "5");
    ASSUME_ITS_EQUAL_CSTR(tuple2.get(1).c_str(), "6");
    // tuple1 should be empty now
    ASSUME_ITS_EQUAL_I32(tuple1.size(), 0);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_tuple_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_default);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add_and_get);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front_and_back);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_and_get);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear_and_is_empty);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_capacity_growth);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_copy_constructor);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_move_constructor);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_tuple_tofu_fixture);
} // end of tests
