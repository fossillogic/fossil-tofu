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

FOSSIL_TEST_SUITE(cpp_set_tofu_fixture);

FOSSIL_SETUP(cpp_set_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_set_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_set_insert) {
    fossil_set_t* set = fossil_set_create_container(const_cast<char*>("i32"));
    fossil_set_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_set_size(set) == 1);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_set_erase) {
    fossil_set_t* set = fossil_set_create_container(const_cast<char*>("i32"));
    fossil_set_insert(set, const_cast<char*>("42"));
    fossil_set_erase(set);
    ASSUME_ITS_TRUE(fossil_set_is_empty(set) == true);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_set_not_empty) {
    fossil_set_t* set = fossil_set_create_container(const_cast<char*>("i32"));
    fossil_set_insert(set, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_set_not_empty(set) == true);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_set_not_cnullptr) {
    fossil_set_t* set = fossil_set_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_set_not_cnullptr(set) == true);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_set_is_cnullptr) {
    fossil_set_t* set = nullptr;
    ASSUME_ITS_TRUE(fossil_set_is_cnullptr(set) == true);
}

FOSSIL_TEST_CASE(cpp_test_set_is_empty) {
    fossil_set_t* set = fossil_set_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_set_is_empty(set) == true);
    fossil_set_destroy(set);
}

FOSSIL_TEST_CASE(cpp_test_set_template_insert) {
    fossil::Set<int> set;
    set.insert(42);
    ASSUME_ITS_TRUE(set.size() == 1);
}

FOSSIL_TEST_CASE(cpp_test_set_template_erase) {
    fossil::Set<int> set;
    set.insert(42);
    set.erase(42);
    ASSUME_ITS_TRUE(set.is_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_set_template_not_empty) {
    fossil::Set<int> set;
    set.insert(42);
    ASSUME_ITS_TRUE(set.not_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_set_template_is_empty) {
    fossil::Set<int> set;
    ASSUME_ITS_TRUE(set.is_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_set_template_get) {
    fossil::Set<int> set;
    set.insert(42);
    ASSUME_ITS_TRUE(set.get(0) == 42);
}

FOSSIL_TEST_CASE(cpp_test_set_template_get_front) {
    fossil::Set<int> set;
    set.insert(42);
    ASSUME_ITS_TRUE(set.get_front() == 42);
}

FOSSIL_TEST_CASE(cpp_test_set_template_get_back) {
    fossil::Set<int> set;
    set.insert(42);
    ASSUME_ITS_TRUE(set.get_back() == 42);
}

FOSSIL_TEST_CASE(cpp_test_set_template_set) {
    fossil::Set<int> set;
    set.insert(42);
    set.set(0, 84);
    ASSUME_ITS_TRUE(set.get(0) == 84);
}

FOSSIL_TEST_CASE(cpp_test_set_template_set_front) {
    fossil::Set<int> set;
    set.insert(42);
    set.set_front(84);
    ASSUME_ITS_TRUE(set.get_front() == 84);
}

FOSSIL_TEST_CASE(cpp_test_set_template_set_back) {
    fossil::Set<int> set;
    set.insert(42);
    set.set_back(84);
    ASSUME_ITS_TRUE(set.get_back() == 84);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_set_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_insert);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_erase);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_not_empty);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_is_empty);

    // Template class tests
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_insert);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_erase);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_not_empty);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_is_empty);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_get);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_get_front);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_get_back);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_set);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_set_front);
    FOSSIL_TEST_ADD(cpp_set_tofu_fixture, cpp_test_set_template_set_back);

    FOSSIL_TEST_REGISTER(cpp_set_tofu_fixture);
} // end of tests
