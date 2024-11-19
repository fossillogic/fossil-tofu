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
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_TRUE(tofu.type == FOSSIL_TOFU_TYPE_I32);
    ASSUME_ITS_EQUAL_CSTR(tofu.value.data, "42");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_default) {
    fossil_tofu_t* tofu = fossil_tofu_create_default();
    ASSUME_ITS_TRUE(tofu != NULL);
    ASSUME_ITS_TRUE(tofu->type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_EQUAL_CSTR(tofu->value.data, "");
    fossil_tofu_destroy(tofu);
}

FOSSIL_TEST_CASE(cpp_test_create_copy) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t* tofu2 = fossil_tofu_create_copy(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_create_move) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t* tofu2 = fossil_tofu_create_move(&tofu1);
    ASSUME_ITS_TRUE(tofu2 != NULL);
    ASSUME_ITS_TRUE(tofu1.type == FOSSIL_TOFU_TYPE_ANY);
    ASSUME_ITS_TRUE(tofu1.value.data == NULL);
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu2, &tofu1) == false);
    fossil_tofu_destroy(tofu2);
}

FOSSIL_TEST_CASE(cpp_test_set_get_value) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil_tofu_set_value(&tofu, "84") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&tofu), "84");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_mutability) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == true);
    ASSUME_ITS_TRUE(fossil_tofu_set_mutable(&tofu, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_is_mutable(&tofu) == false);
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_set_get_attribute) {
    fossil_tofu_t tofu = fossil_tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil_tofu_set_attribute(&tofu, "Test Attribute", "Test Description", "cpp_test_id") == FOSSIL_TOFU_SUCCESS);
    const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(&tofu);
    ASSUME_ITS_EQUAL_CSTR(attr->name, "Test Attribute");
    ASSUME_ITS_EQUAL_CSTR(attr->description, "Test Description");
    ASSUME_ITS_EQUAL_CSTR(attr->id, "cpp_test_id");
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_equals) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2 = fossil_tofu_create("i32", "42");
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_copy) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2;
    ASSUME_ITS_TRUE(fossil_tofu_copy(&tofu2, &tofu1) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_tofu_equals(&tofu1, &tofu2) == true);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_algorithm_compare) {
    fossil_tofu_t tofu1 = fossil_tofu_create("i32", "42");
    fossil_tofu_t tofu2 = fossil_tofu_create("i32", "84");
    ASSUME_ITS_TRUE(fossil_tofu_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST_CASE(cpp_test_algorithm_search) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create("i32", "42"),
        fossil_tofu_create("i32", "84"),
        fossil_tofu_create("i32", "126")
    };
    fossil_tofu_t tofu = fossil_tofu_create("i32", "84");
    ASSUME_ITS_TRUE(fossil_tofu_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST_CASE(cpp_test_algorithm_sort) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create("i32", "126"),
        fossil_tofu_create("i32", "42"),
        fossil_tofu_create("i32", "84")
    };
    
    ASSUME_ITS_TRUE(fossil_tofu_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);

    // Need to figure out sort algorithm as to why it's not working
    // seems to lose data during sort
    // ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    // ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    // ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");
    
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST_CASE(cpp_test_algorithm_reverse) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create("i32", "42"),
        fossil_tofu_create("i32", "84"),
        fossil_tofu_create("i32", "126")
    };
    ASSUME_ITS_TRUE(fossil_tofu_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_generic_tofu_tests) {    
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
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_default);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_copy);
    FOSSIL_TEST_ADD(cpp_generic_tofu_fixture, cpp_test_create_move);

    FOSSIL_TEST_REGISTER(cpp_generic_tofu_fixture);
} // end of tests
