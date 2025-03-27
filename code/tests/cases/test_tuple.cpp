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

FOSSIL_TEST_SUITE(cpp_tuple_tofu_fixture);

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

FOSSIL_TEST_CASE(cpp_test_tuple_create_destroy) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_create_default) {
    fossil_tuple_t* tuple = fossil_tuple_create_default();
    ASSUME_ITS_TRUE(tuple != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_create_copy) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(original, const_cast<char *>("42"));
    fossil_tuple_t* copy = fossil_tuple_create_copy(original);
    ASSUME_ITS_TRUE(copy != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(copy) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(copy, 0), "42");
    fossil_tuple_destroy(original);
    fossil_tuple_destroy(copy);
}

FOSSIL_TEST_CASE(cpp_test_tuple_create_move) {
    fossil_tuple_t* original = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(original, const_cast<char *>("42"));
    fossil_tuple_t* moved = fossil_tuple_create_move(original);
    ASSUME_ITS_TRUE(moved != nullptr);
    ASSUME_ITS_TRUE(fossil_tuple_size(moved) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(moved, 0), "42");
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(original) == true);
    fossil_tuple_destroy(moved);
}

FOSSIL_TEST_CASE(cpp_test_tuple_add) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), "42");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_remove) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    fossil_tuple_add(tuple, const_cast<char *>("84"));
    fossil_tuple_remove(tuple, 0);
    ASSUME_ITS_TRUE(fossil_tuple_size(tuple) == 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), "84");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_clear) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    fossil_tuple_add(tuple, const_cast<char *>("84"));
    fossil_tuple_clear(tuple);
    ASSUME_ITS_TRUE(fossil_tuple_is_empty(tuple) == true);
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_get_front) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    fossil_tuple_add(tuple, const_cast<char *>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), "42");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_get_back) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    fossil_tuple_add(tuple, const_cast<char *>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), "84");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_set) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    fossil_tuple_set(tuple, 0, const_cast<char *>("84"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get(tuple, 0), "84");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_set_front) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    fossil_tuple_add(tuple, const_cast<char *>("84"));
    fossil_tuple_set_front(tuple, const_cast<char *>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_front(tuple), "21");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_set_back) {
    fossil_tuple_t* tuple = fossil_tuple_create(const_cast<char *>("i32"));
    fossil_tuple_add(tuple, const_cast<char *>("42"));
    fossil_tuple_add(tuple, const_cast<char *>("84"));
    fossil_tuple_set_back(tuple, const_cast<char *>("21"));
    ASSUME_ITS_EQUAL_CSTR(fossil_tuple_get_back(tuple), "21");
    fossil_tuple_destroy(tuple);
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_create_destroy) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(tuple.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_create_default) {
    fossil::tofu::Tuple tuple;
    ASSUME_ITS_TRUE(tuple.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_create_copy) {
    fossil::tofu::Tuple original(const_cast<char *>("i32"));
    original.add(const_cast<char *>("42"));
    fossil::tofu::Tuple copy(original);
    ASSUME_ITS_TRUE(copy.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(copy.get(0), "42");
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_create_move) {
    fossil::tofu::Tuple original(const_cast<char *>("i32"));
    original.add(const_cast<char *>("42"));
    fossil::tofu::Tuple moved(std::move(original));
    ASSUME_ITS_TRUE(moved.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(moved.get(0), "42");
    ASSUME_ITS_TRUE(original.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_add) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(tuple.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0), "42");
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_remove) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    tuple.add(const_cast<char *>("84"));
    tuple.remove(0);
    ASSUME_ITS_TRUE(tuple.size() == 1);
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0), "84");
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_clear) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    tuple.add(const_cast<char *>("84"));
    tuple.clear();
    ASSUME_ITS_TRUE(tuple.is_empty());
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_get_front) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    tuple.add(const_cast<char *>("84"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_front(), "42");
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_get_back) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    tuple.add(const_cast<char *>("84"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_back(), "84");
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_set) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    tuple.set(0, const_cast<char *>("84"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get(0), "84");
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_set_front) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    tuple.add(const_cast<char *>("84"));
    tuple.set_front(const_cast<char *>("21"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_front(), "21");
}

FOSSIL_TEST_CASE(cpp_test_tuple_class_set_back) {
    fossil::tofu::Tuple tuple(const_cast<char *>("i32"));
    tuple.add(const_cast<char *>("42"));
    tuple.add(const_cast<char *>("84"));
    tuple.set_back(const_cast<char *>("21"));
    ASSUME_ITS_EQUAL_CSTR(tuple.get_back(), "21");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_tuple_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_destroy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_default);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_copy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_create_move);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_add);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_remove);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_clear);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_get_back);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_set_back);

    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_destroy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_default);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_copy);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_create_move);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_add);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_remove);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_clear);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_get_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_get_back);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_set);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_set_front);
    FOSSIL_TEST_ADD(cpp_tuple_tofu_fixture, cpp_test_tuple_class_set_back);

    FOSSIL_TEST_REGISTER(cpp_tuple_tofu_fixture);
} // end of tests
