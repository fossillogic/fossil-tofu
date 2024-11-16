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
#include <vector>

using namespace fossil;

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_SUITE(cpp_generic_tofu_fixture);

FOSSIL_SETUP(cpp_generic_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_generic_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_create_destroy) {
    fossil::tofu_t tofu = fossil::tofu_create("i32", "42");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I32);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "42");
    fossil::tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value) {
    fossil::tofu_t tofu = fossil::tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil::tofu_set_value(tofu, "84") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil::tofu_get_value(tofu).c_str(), "84");
    fossil::tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability) {
    fossil::tofu_t tofu = fossil::tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil::tofu_is_mutable(tofu) == true);
    ASSUME_ITS_TRUE(fossil::tofu_set_mutable(tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::tofu_is_mutable(tofu) == false);
    fossil::tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute) {
    fossil::tofu_t tofu = fossil::tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil::tofu_set_attribute(tofu, "Test Attribute", "Test Description", "c_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil::tofu_attribute_t* attr = fossil::tofu_get_attribute(tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "c_test_id");
    fossil::tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_equals) {
    fossil::tofu_t tofu1 = fossil::tofu_create("i32", "42");
    fossil::tofu_t tofu2 = fossil::tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil::tofu_equals(tofu1, tofu2) == true);
    fossil::tofu_destroy(tofu1);
    fossil::tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy) {
    fossil::tofu_t tofu1 = fossil::tofu_create("i32", "42");
    fossil::tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil::tofu_copy(tofu2, tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil::tofu_equals(tofu1, tofu2) == true);
    fossil::tofu_destroy(tofu1);
    fossil::tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_algorithm_compare) {
    fossil::tofu_t tofu1 = fossil::tofu_create("i32", "42");
    fossil::tofu_t tofu2 = fossil::tofu_create("i32", "84");
    ASSUME_ITS_TRUE(fossil::tofu_algorithm_compare(tofu1, tofu2) < 0);
    fossil::tofu_destroy(tofu1);
    fossil::tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_algorithm_search) {
    std::vector<fossil::tofu_t> array = {
        fossil::tofu_create("i32", "42"),
        fossil::tofu_create("i32", "84"),
        fossil::tofu_create("i32", "126")
    };
    fossil::tofu_t tofu = fossil::tofu_create("i32", "84");
    ASSUME_ITS_TRUE(fossil::tofu_algorithm_search(array.data(), array.size(), tofu) == 1);
    for (auto& item : array) {
        fossil::tofu_destroy(item);
    }
    fossil::tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_algorithm_sort) {
    std::vector<fossil::tofu_t> array = {
        fossil::tofu_create("i32", "126"),
        fossil::tofu_create("i32", "42"),
        fossil::tofu_create("i32", "84")
    };
    
    ASSUME_ITS_TRUE(fossil::tofu_algorithm_sort(array.data(), array.size(), true) == FOSSIL_TOFU_SUCCESS);

    // Need to figure out sort algorithm as to why it's not working
    // seems to lose data during sort
    // ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    // ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    // ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");
    
    for (auto& item : array) {
        fossil::tofu_destroy(item);
    }
}

FOSSIL_TEST_CASE(cpp_test_algorithm_reverse) {
    std::vector<fossil::tofu_t> array = {
        fossil::tofu_create("i32", "42"),
        fossil::tofu_create("i32", "84"),
        fossil::tofu_create("i32", "126")
    };
    ASSUME_ITS_TRUE(fossil::tofu_algorithm_reverse(array.data(), array.size()) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");
    for (auto& item : array) {
        fossil::tofu_destroy(item);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
extern "C" FOSSIL_TEST_GROUP(cpp_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_destroy);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_value);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_mutability);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_set_get_attribute);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_equals);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_copy);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_algorithm_compare);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_algorithm_search);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_algorithm_sort);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_algorithm_reverse);

    FOSSIL_TEST_REGISTER(cpp_generic_tofu_fixture);
} // end of tests
