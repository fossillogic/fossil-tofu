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

FOSSIL_TEST_SUITE(c_generic_tofu_fixture);

FOSSIL_SETUP(c_generic_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_generic_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define a transformation function
fossil_tofu_t double_value(fossil_tofu_t tofu) {
    if (tofu.type == FOSSIL_TOFU_TYPE_INT) {
        tofu.value.int_val *= 2;
    }
    return tofu;
}

// Define a predicate function for filtering
bool tofu_mock_is_even(fossil_tofu_t tofu) {
    if (tofu.type == FOSSIL_TOFU_TYPE_INT) {
        return tofu.value.int_val % 2 == 0;
    }
    return false;  // For other types, consider them as not matching the predicate
}

// Define a reduction function
fossil_tofu_t sum_function(fossil_tofu_t a, fossil_tofu_t b) {
    if (a.type == FOSSIL_TOFU_TYPE_INT && b.type == FOSSIL_TOFU_TYPE_INT) {
        a.value.int_val += b.value.int_val;
    }
    return a;
}

// Define an accumulation function
fossil_tofu_t sum(fossil_tofu_t a, fossil_tofu_t b) {
    a.value.int_val += b.value.int_val;
    return a;
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test case for fossil_tofu_create function
FOSSIL_TEST_CASE(test_fossil_tofu_create) {
    // Test creating different types of fossil_tofu_t objects
    fossil_tofu_t tofu_int = fossil_tofu_create("int", "123");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_INT, tofu_int.type);
    ASSUME_ITS_EQUAL_I64(123, tofu_int.value.int_val);

    fossil_tofu_t tofu_uint = fossil_tofu_create("uint", "123");
    ASSUME_ITS_EQUAL_U32(FOSSIL_TOFU_TYPE_UINT, tofu_uint.type);
    ASSUME_ITS_EQUAL_U64(123, tofu_uint.value.uint_val);

    fossil_tofu_t tofu_bool = fossil_tofu_create("bool", "true");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_BOOL, tofu_bool.type);
    ASSUME_ITS_TRUE(tofu_bool.value.bool_val);

    fossil_tofu_t tofu_float = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_FLOAT, tofu_float.type);
    ASSUME_ITS_EQUAL_F32(3.14f, tofu_float.value.float_val, FOSSIL_TEST_FLOAT_EPSILON);

    fossil_tofu_t tofu_double = fossil_tofu_create("double", "3.14");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_DOUBLE, tofu_double.type);
    ASSUME_ITS_EQUAL_F64(3.14, tofu_double.value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);

    fossil_tofu_t tofu_cstr = fossil_tofu_create("cstr", "Hello");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_CSTR, tofu_cstr.type);
    ASSUME_ITS_EQUAL_CSTR("Hello", tofu_cstr.value.cchar_string_val);
}

// Test case for fossil_tofu_equals function
FOSSIL_TEST_CASE(test_fossil_tofu_equals) {
    fossil_tofu_t tofu1 = fossil_tofu_create("int", "100");
    fossil_tofu_t tofu2 = fossil_tofu_create("int", "100");
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu1, tofu2));

    fossil_tofu_t tofu3 = fossil_tofu_create("float", "3.14");
    fossil_tofu_t tofu4 = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_FALSE(fossil_tofu_equals(tofu1, tofu3));
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu3, tofu4));

    fossil_tofu_t tofu5 = fossil_tofu_create("cstr", "Hello");
    fossil_tofu_t tofu6 = fossil_tofu_create("cstr", "Hello");
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu5, tofu6));
}

// Test case for fossil_tofu_copy function
FOSSIL_TEST_CASE(test_fossil_tofu_copy) {
    fossil_tofu_t tofu_orig = fossil_tofu_create("cstr", "Original");
    fossil_tofu_t tofu_copy = fossil_tofu_copy(tofu_orig);

    ASSUME_ITS_EQUAL_I32(tofu_orig.type, tofu_copy.type);
    ASSUME_ITS_EQUAL_CSTR(tofu_orig.value.cchar_string_val, tofu_copy.value.cchar_string_val);
    ASSUME_ITS_EQUAL_I32(tofu_orig.is_cached, tofu_copy.is_cached);
}

FOSSIL_TEST_CASE(test_fossil_tofu_iteratorof_create) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    ASSUME_ITS_EQUAL_I32(0, iterator.current_index);
    ASSUME_ITS_EQUAL_I32(2, iterator.size);
}

FOSSIL_TEST_CASE(test_fossil_tofu_iteratorof_has_next) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    ASSUME_ITS_TRUE(fossil_tofu_iteratorof_has_next(&iterator));
    iterator.current_index = 2;
    ASSUME_ITS_FALSE(fossil_tofu_iteratorof_has_next(&iterator));
}

FOSSIL_TEST_CASE(test_fossil_tofu_iteratorof_next) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    fossil_tofu_t first = fossil_tofu_iteratorof_next(&iterator);
    ASSUME_ITS_EQUAL_I32(1, first.value.int_val);
    fossil_tofu_t second = fossil_tofu_iteratorof_next(&iterator);
    ASSUME_ITS_EQUAL_I32(2, second.value.int_val);
}

FOSSIL_TEST_CASE(test_fossil_tofu_iteratorof_reset) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    fossil_tofu_iteratorof_next(&iterator);
    fossil_tofu_iteratorof_reset(&iterator);
    ASSUME_ITS_EQUAL_I32(0, iterator.current_index);
}

// Test for transform function
FOSSIL_TEST_CASE(test_transform) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_actionof_transform(array, size, double_value);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_I32(20, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(40, array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(60, array[2].value.int_val);
}

// Test for accumulate function
FOSSIL_TEST_CASE(test_accumulate) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t init = fossil_tofu_create("int", "0");

    fossil_tofu_t result = fossil_tofu_actionof_accumulate(array, size, init, sum);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_I32(60, result.value.int_val);
}

// Test for filter function
FOSSIL_TEST_CASE(test_filter) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_actionof_filter(array, size, tofu_mock_is_even);

    ASSUME_ITS_EQUAL_I32(10, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(30, array[2].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
}

// Test for reverse function
FOSSIL_TEST_CASE(test_reverse) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_actionof_reverse(array, size);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_I32(30, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, array[2].value.int_val);
}

// Test for swap function
FOSSIL_TEST_CASE(test_swap) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };

    fossil_tofu_actionof_swap(array, 0, 2);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_I32(30, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, array[2].value.int_val);
}

// Test for reduce function
FOSSIL_TEST_CASE(test_reduce) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t result = fossil_tofu_actionof_reduce(array, size, sum_function);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_I32(60, result.value.int_val);
}

// Test case for verifying assumptions using xassume.h
FOSSIL_TEST_CASE(test_fossil_verification_checks) {
    // Create a valid tofu object and check assumption
    fossil_tofu_t tofu_int = fossil_tofu_create("int", "100");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_INT, tofu_int.type);
    ASSUME_ITS_EQUAL_I64(100, tofu_int.value.int_val);

    // Create an invalid type (force invalid assumption check)
    fossil_tofu_t tofu_invalid = fossil_tofu_create("int", "abc");  // invalid integer
    ASSUME_ITS_FALSE(fossil_tofu_equals(tofu_int, tofu_invalid));   // this should fail, catch

    // Test verification failure for mismatching types
    fossil_tofu_t tofu_float = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_FALSE(fossil_tofu_equals(tofu_int, tofu_float));

    // Add more cases to trigger assertion failures and validate xassume behavior
    fossil_tofu_t tofu_bstr = fossil_tofu_create("bstr", "hello");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_BSTR, tofu_bstr.type); // expected to pass
    ASSUME_ITS_FALSE(fossil_tofu_equals(tofu_float, tofu_bstr));  // this check must succeed

    // Check for invalid tofu types
    fossil_tofu_t tofu_ghost = fossil_tofu_create("ghost", "invisible");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_GHOST, tofu_ghost.type); // ensure it's recognized as invalid/ghost
}

// Test case for failed verification checks in fossil_tofu_create
FOSSIL_TEST_CASE(test_fossil_tofu_create_invalid) {
    // Try to create a tofu object with an invalid type
    fossil_tofu_t tofu_invalid_type = fossil_tofu_create("invalid_type", "123");
    // Verification should fail and return FOSSIL_TOFU_TYPE_GHOST or other failure result
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_GHOST, tofu_invalid_type.type);

    // Try to create a tofu object with an invalid value format for int
    fossil_tofu_t tofu_invalid_value = fossil_tofu_create("int", "invalid_int");
    // Verification should fail and return FOSSIL_TOFU_TYPE_GHOST
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_GHOST, tofu_invalid_value.type);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_create);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_equals);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_copy);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_iteratorof_create);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_iteratorof_has_next);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_iteratorof_next);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_iteratorof_reset);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_transform);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_accumulate);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_filter);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_reverse);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_swap);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_reduce);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_verification_checks);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_create_invalid);

    FOSSIL_TEST_REGISTER(c_generic_tofu_fixture);
} // end of tests
