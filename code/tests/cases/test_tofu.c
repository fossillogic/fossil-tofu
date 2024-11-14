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

    fossil_tofu_t tofu_int8 = fossil_tofu_create("int8", "123");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_I8, tofu_int8.type);
    ASSUME_ITS_EQUAL_I8(123, tofu_int8.value.int8_val);

    fossil_tofu_t tofu_uint8 = fossil_tofu_create("uint8", "123");
    ASSUME_ITS_EQUAL_U32(FOSSIL_TOFU_TYPE_U8, tofu_uint8.type);
    ASSUME_ITS_EQUAL_U8(123, tofu_uint8.value.uint8_val);

    fossil_tofu_t tofu_int16 = fossil_tofu_create("int16", "123");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_I16, tofu_int16.type);
    ASSUME_ITS_EQUAL_I16(123, tofu_int16.value.int16_val);

    fossil_tofu_t tofu_uint16 = fossil_tofu_create("uint16", "123");
    ASSUME_ITS_EQUAL_U32(FOSSIL_TOFU_TYPE_U16, tofu_uint16.type);
    ASSUME_ITS_EQUAL_U16(123, tofu_uint16.value.uint16_val);

    fossil_tofu_t tofu_int32 = fossil_tofu_create("int32", "123");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_I32, tofu_int32.type);
    ASSUME_ITS_EQUAL_I32(123, tofu_int32.value.int32_val);

    fossil_tofu_t tofu_uint32 = fossil_tofu_create("uint32", "123");
    ASSUME_ITS_EQUAL_U32(FOSSIL_TOFU_TYPE_U32, tofu_uint32.type);
    ASSUME_ITS_EQUAL_U32(123, tofu_uint32.value.uint32_val);

    fossil_tofu_t tofu_int64 = fossil_tofu_create("int64", "123");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_I64, tofu_int64.type);
    ASSUME_ITS_EQUAL_I64(123, tofu_int64.value.int64_val);

    fossil_tofu_t tofu_uint64 = fossil_tofu_create("uint64", "123");
    ASSUME_ITS_EQUAL_U32(FOSSIL_TOFU_TYPE_U64, tofu_uint64.type);
    ASSUME_ITS_EQUAL_U64(123, tofu_uint64.value.uint64_val);

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

    fossil_tofu_t tofu_ghost = fossil_tofu_create("ghost", "invisible");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_GHOST, tofu_ghost.type);
    ASSUME_ITS_EQUAL_CSTR("invisible", tofu_ghost.value.ghost_val);

    // Cleanup the tofu objects
    fossil_tofu_destroy(&tofu_int);
    fossil_tofu_destroy(&tofu_uint);
    fossil_tofu_destroy(&tofu_int8);
    fossil_tofu_destroy(&tofu_uint8);
    fossil_tofu_destroy(&tofu_int16);
    fossil_tofu_destroy(&tofu_uint16);
    fossil_tofu_destroy(&tofu_int32);
    fossil_tofu_destroy(&tofu_uint32);
    fossil_tofu_destroy(&tofu_int64);
    fossil_tofu_destroy(&tofu_uint64);
    fossil_tofu_destroy(&tofu_bool);
    fossil_tofu_destroy(&tofu_float);
    fossil_tofu_destroy(&tofu_double);
    fossil_tofu_destroy(&tofu_cstr);
    fossil_tofu_destroy(&tofu_ghost);
}

// Test case for fossil_tofu_equals function
FOSSIL_TEST_CASE(test_fossil_tofu_equals) {
    fossil_tofu_t tofu1 = fossil_tofu_create("int", "100");
    fossil_tofu_t tofu2 = fossil_tofu_create("int", "100");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu1, tofu2));

    fossil_tofu_t tofu3 = fossil_tofu_create("float", "3.14");
    fossil_tofu_t tofu4 = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_FALSE(fossil_tofu_equal_value(tofu1, tofu3));
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu3, tofu4));

    fossil_tofu_t tofu5 = fossil_tofu_create("cstr", "Hello");
    fossil_tofu_t tofu6 = fossil_tofu_create("cstr", "Hello");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu5, tofu6));

    fossil_tofu_t tofu7 = fossil_tofu_create("double", "3.14");
    fossil_tofu_t tofu8 = fossil_tofu_create("double", "3.14");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu7, tofu8));

    fossil_tofu_t tofu9 = fossil_tofu_create("bool", "true");
    fossil_tofu_t tofu10 = fossil_tofu_create("bool", "true");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu9, tofu10));

    fossil_tofu_t tofu11 = fossil_tofu_create("int8", "127");
    fossil_tofu_t tofu12 = fossil_tofu_create("int8", "127");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu11, tofu12));

    fossil_tofu_t tofu13 = fossil_tofu_create("uint8", "255");
    fossil_tofu_t tofu14 = fossil_tofu_create("uint8", "255");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu13, tofu14));

    fossil_tofu_t tofu15 = fossil_tofu_create("int16", "32767");
    fossil_tofu_t tofu16 = fossil_tofu_create("int16", "32767");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu15, tofu16));

    fossil_tofu_t tofu17 = fossil_tofu_create("uint16", "65535");
    fossil_tofu_t tofu18 = fossil_tofu_create("uint16", "65535");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu17, tofu18));

    fossil_tofu_t tofu19 = fossil_tofu_create("int32", "2147483647");
    fossil_tofu_t tofu20 = fossil_tofu_create("int32", "2147483647");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu19, tofu20));

    fossil_tofu_t tofu21 = fossil_tofu_create("uint32", "4294967295");
    fossil_tofu_t tofu22 = fossil_tofu_create("uint32", "4294967295");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu21, tofu22));

    fossil_tofu_t tofu23 = fossil_tofu_create("int64", "9223372036854775807");
    fossil_tofu_t tofu24 = fossil_tofu_create("int64", "9223372036854775807");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu23, tofu24));

    fossil_tofu_t tofu25 = fossil_tofu_create("uint64", "18446744073709551615");
    fossil_tofu_t tofu26 = fossil_tofu_create("uint64", "18446744073709551615");
    ASSUME_ITS_TRUE(fossil_tofu_equal_value(tofu25, tofu26));

    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
    fossil_tofu_destroy(&tofu3);
    fossil_tofu_destroy(&tofu4);
    fossil_tofu_destroy(&tofu5);
    fossil_tofu_destroy(&tofu6);
    fossil_tofu_destroy(&tofu7);
    fossil_tofu_destroy(&tofu8);
    fossil_tofu_destroy(&tofu9);
    fossil_tofu_destroy(&tofu10);
    fossil_tofu_destroy(&tofu11);
    fossil_tofu_destroy(&tofu12);
    fossil_tofu_destroy(&tofu13);
    fossil_tofu_destroy(&tofu14);
    fossil_tofu_destroy(&tofu15);
    fossil_tofu_destroy(&tofu16);
    fossil_tofu_destroy(&tofu17);
    fossil_tofu_destroy(&tofu18);
    fossil_tofu_destroy(&tofu19);
    fossil_tofu_destroy(&tofu20);
    fossil_tofu_destroy(&tofu21);
    fossil_tofu_destroy(&tofu22);
    fossil_tofu_destroy(&tofu23);
    fossil_tofu_destroy(&tofu24);
    fossil_tofu_destroy(&tofu25);
    fossil_tofu_destroy(&tofu26);
}

// Test case for fossil_tofu_copy function
FOSSIL_TEST_CASE(test_fossil_tofu_copy) {
    fossil_tofu_t tofu_orig = fossil_tofu_create("cstr", "Original");
    fossil_tofu_t tofu_copy = fossil_tofu_copy(tofu_orig);

    ASSUME_ITS_EQUAL_I32(tofu_orig.type, tofu_copy.type);
    ASSUME_ITS_EQUAL_CSTR(tofu_orig.value.cchar_string_val, tofu_copy.value.cchar_string_val);

    fossil_tofu_destroy(&tofu_orig);
    fossil_tofu_destroy(&tofu_copy);
}

// Test case for verifying assumptions using xassume.h
FOSSIL_TEST_CASE(test_fossil_verification_checks) {
    // Create a valid tofu object and check assumption
    fossil_tofu_t tofu_int = fossil_tofu_create("int", "100");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_INT, tofu_int.type);
    ASSUME_ITS_EQUAL_I64(100, tofu_int.value.int_val);

    // Create an invalid type (force invalid assumption check)
    fossil_tofu_t tofu_invalid = fossil_tofu_create("int", "abc");  // invalid integer
    ASSUME_ITS_FALSE(fossil_tofu_equal_value(tofu_int, tofu_invalid));   // this should fail, catch

    // Test verification failure for mismatching types
    fossil_tofu_t tofu_float = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_FALSE(fossil_tofu_equal_value(tofu_int, tofu_float));

    // Add more cases to trigger assertion failures and validate xassume behavior
    fossil_tofu_t tofu_bstr = fossil_tofu_create("bstr", "hello");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_BSTR, tofu_bstr.type); // expected to pass
    ASSUME_ITS_FALSE(fossil_tofu_equal_value(tofu_float, tofu_bstr));  // this check must succeed

    // Check for invalid tofu types
    fossil_tofu_t tofu_ghost = fossil_tofu_create("ghost", "invisible");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_GHOST, tofu_ghost.type); // ensure it's recognized as invalid/ghost

    // Cleanup the tofu objects
    fossil_tofu_destroy(&tofu_int);
    fossil_tofu_destroy(&tofu_invalid);
    fossil_tofu_destroy(&tofu_float);
    fossil_tofu_destroy(&tofu_bstr);
    fossil_tofu_destroy(&tofu_ghost);
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

    // Cleanup the tofu objects
    fossil_tofu_destroy(&tofu_invalid_type);
    fossil_tofu_destroy(&tofu_invalid_value);
}

// Test case for fossil_tofu_destroy function
FOSSIL_TEST_CASE(test_fossil_tofu_destroy) {
    fossil_tofu_t tofu = fossil_tofu_create("cstr", "Temporary");
    fossil_tofu_destroy(&tofu);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_GHOST, tofu.type);
}

// Test case for fossil_tofu_is_valid_type function
FOSSIL_TEST_CASE(test_fossil_tofu_is_valid_type) {
    ASSUME_ITS_TRUE(fossil_tofu_is_valid_type("int"));
    ASSUME_ITS_TRUE(fossil_tofu_is_valid_type("float"));
    ASSUME_ITS_FALSE(fossil_tofu_is_valid_type("invalid_type"));
}

// Test case for fossil_tofu_get_name function
FOSSIL_TEST_CASE(test_fossil_tofu_get_name) {
    fossil_tofu_t tofu = fossil_tofu_create("int", "123");
    ASSUME_ITS_EQUAL_CSTR("Signed Integer", fossil_tofu_get_name(tofu));

    fossil_tofu_t tofu2 = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_EQUAL_CSTR("Floating Point", fossil_tofu_get_name(tofu2));

    fossil_tofu_t tofu3 = fossil_tofu_create("cstr", "Hello");
    ASSUME_ITS_EQUAL_CSTR("Character String", fossil_tofu_get_name(tofu3));

    fossil_tofu_t tofu4 = fossil_tofu_create("bool", "true");
    ASSUME_ITS_EQUAL_CSTR("Boolean", fossil_tofu_get_name(tofu4));

    fossil_tofu_destroy(&tofu);
    fossil_tofu_destroy(&tofu2);
    fossil_tofu_destroy(&tofu3);
    fossil_tofu_destroy(&tofu4);    
}

// Test case for fossil_tofu_get_info function
FOSSIL_TEST_CASE(test_fossil_tofu_get_info) {
    fossil_tofu_t tofu = fossil_tofu_create("int", "123");
    ASSUME_ITS_EQUAL_CSTR("A signed integer value", fossil_tofu_get_info(tofu));

    fossil_tofu_t tofu2 = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_EQUAL_CSTR("A floating point value", fossil_tofu_get_info(tofu2));

    fossil_tofu_t tofu3 = fossil_tofu_create("cstr", "Hello");
    ASSUME_ITS_EQUAL_CSTR("A character string value", fossil_tofu_get_info(tofu3));

    fossil_tofu_t tofu4 = fossil_tofu_create("bool", "true");
    ASSUME_ITS_EQUAL_CSTR("A boolean value", fossil_tofu_get_info(tofu4));

    fossil_tofu_destroy(&tofu);
    fossil_tofu_destroy(&tofu2);
    fossil_tofu_destroy(&tofu3);
    fossil_tofu_destroy(&tofu4);
}

// Test case for fossil_tofu_get_id function
FOSSIL_TEST_CASE(test_fossil_tofu_get_id) {
    fossil_tofu_t tofu = fossil_tofu_create("int", "123");
    ASSUME_ITS_EQUAL_CSTR("int", fossil_tofu_get_id(tofu));

    fossil_tofu_t tofu2 = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_EQUAL_CSTR("float", fossil_tofu_get_id(tofu2));

    fossil_tofu_t tofu3 = fossil_tofu_create("cstr", "Hello");
    ASSUME_ITS_EQUAL_CSTR("cstr", fossil_tofu_get_id(tofu3));

    fossil_tofu_t tofu4 = fossil_tofu_create("bool", "true");
    ASSUME_ITS_EQUAL_CSTR("bool", fossil_tofu_get_id(tofu4));

    fossil_tofu_destroy(&tofu);
    fossil_tofu_destroy(&tofu2);
    fossil_tofu_destroy(&tofu3);
    fossil_tofu_destroy(&tofu4);
}

// Test case for fossil_tofu_algorithm_search function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_search) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    fossil_tofu_t key = fossil_tofu_create("int", "20");

    fossil_tofu_t *result = fossil_tofu_algorithm_search(array, size, key, fossil_tofu_equal_value);
    ASSUME_NOT_CNULL(result);
    ASSUME_ITS_EQUAL_I32(20, result->value.int_val);
}

// Test case for fossil_tofu_algorithm_partition function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_partition) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "15"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "25")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    size_t partition_index = fossil_tofu_algorithm_partition(array, size, tofu_mock_is_even);
    ASSUME_ITS_EQUAL_I32(2, partition_index);
    ASSUME_ITS_EQUAL_I32(10, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
}

// Test case for fossil_tofu_algorithm_shuffle function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_shuffle) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_algorithm_shuffle(array, size);

    // Since shuffle is random, we just check that all elements are still present
    bool found_10 = false, found_20 = false, found_30 = false;
    for (size_t i = 0; i < size; i++) {
        if (array[i].value.int_val == 10) found_10 = true;
        if (array[i].value.int_val == 20) found_20 = true;
        if (array[i].value.int_val == 30) found_30 = true;
    }
    ASSUME_ITS_TRUE(found_10);
    ASSUME_ITS_TRUE(found_20);
    ASSUME_ITS_TRUE(found_30);
}

// Test case for fossil_tofu_algorithm_sort function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_sort) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "30"),
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_algorithm_sort(array, size);

    ASSUME_ITS_EQUAL_I32(10, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(30, array[2].value.int_val);
}

// Test case for fossil_tofu_algorithm_average function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_average) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("double", "10.0"),
        fossil_tofu_create("double", "20.0"),
        fossil_tofu_create("double", "30.0")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t average = fossil_tofu_algorithm_average(array, size);

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_DOUBLE, average.type);
    ASSUME_ITS_EQUAL_F64(20.0, average.value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// Test case for fossil_tofu_algorithm_for_each function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_for_each) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_algorithm_for_each(array, size, fossil_tofu_print);
}

// Test case for fossil_tofu_algorithm_summary function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_summary) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t summary = fossil_tofu_algorithm_summary(array, size, sum_function);

    ASSUME_ITS_EQUAL_I32(60, summary.value.int_val);
}

// Test case for fossil_tofu_algorithm_compare function
FOSSIL_TEST_CASE(test_fossil_tofu_algorithm_compare) {
    fossil_tofu_t tofu1 = fossil_tofu_create("int", "10");
    fossil_tofu_t tofu2 = fossil_tofu_create("int", "20");

    int comparison = fossil_tofu_algorithm_compare(tofu1, tofu2);
    ASSUME_ITS_LESS_THAN_I32(0, comparison);

    comparison = fossil_tofu_algorithm_compare(tofu2, tofu1);
    ASSUME_ITS_GREATER_THAN_I32(0, comparison);

    comparison = fossil_tofu_algorithm_compare(tofu1, tofu1);
    ASSUME_ITS_EQUAL_I32(0, comparison);
}

// Test case for fossil_tofu_algorithm_transform with different types
FOSSIL_TEST_CASE(test_transform_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_algorithm_transform(array, size, double_value);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_I32(20, array[0].value.int_val);
    ASSUME_ITS_EQUAL_F32(20.5f, array[1].value.float_val, FOSSIL_TEST_FLOAT_EPSILON);
    ASSUME_ITS_EQUAL_F64(30.75, array[2].value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// Test case for fossil_tofu_algorithm_accumulate with different types
FOSSIL_TEST_CASE(test_accumulate_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t init = fossil_tofu_create("double", "0.0");

    fossil_tofu_t result = fossil_tofu_algorithm_accumulate(array, size, init, sum);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_F64(61.25, result.value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// Test case for fossil_tofu_algorithm_filter with different types
FOSSIL_TEST_CASE(test_filter_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    size_t filtered_size = fossil_tofu_algorithm_filter(array, size, tofu_mock_is_even);

    ASSUME_ITS_EQUAL_I32(1, filtered_size);
    ASSUME_ITS_EQUAL_I32(10, array[0].value.int_val);
}

// Test case for fossil_tofu_algorithm_reverse with different types
FOSSIL_TEST_CASE(test_reverse_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_algorithm_reverse(array, size);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_F64(30.75, array[0].value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
    ASSUME_ITS_EQUAL_F32(20.5f, array[1].value.float_val, FOSSIL_TEST_FLOAT_EPSILON);
    ASSUME_ITS_EQUAL_I32(10, array[2].value.int_val);
}

// Test case for fossil_tofu_algorithm_swap with different types
FOSSIL_TEST_CASE(test_swap_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };

    fossil_tofu_algorithm_swap(array, 0, 2);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_F64(30.75, array[0].value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
    ASSUME_ITS_EQUAL_I32(10, array[2].value.int_val);
}

// Test case for fossil_tofu_algorithm_reduce with different types
FOSSIL_TEST_CASE(test_reduce_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t result = fossil_tofu_algorithm_reduce(array, size, sum_function);

    // Assertions using Fossil Test
    ASSUME_ITS_EQUAL_F64(61.25, result.value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// Test case for fossil_tofu_algorithm_summary with different types
FOSSIL_TEST_CASE(test_summary_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t summary = fossil_tofu_algorithm_summary(array, size, sum_function);

    ASSUME_ITS_EQUAL_F64(61.25, summary.value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// Test case for fossil_tofu_algorithm_average with different types
FOSSIL_TEST_CASE(test_average_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("double", "10.0"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t average = fossil_tofu_algorithm_average(array, size);

    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_DOUBLE, average.type);
    ASSUME_ITS_EQUAL_F64(20.1666666667, average.value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// Test case for fossil_tofu_algorithm_sort with different types
FOSSIL_TEST_CASE(test_sort_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("double", "30.75"),
        fossil_tofu_create("float", "10.5"),
        fossil_tofu_create("int", "20")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_algorithm_sort(array, size);

    ASSUME_ITS_EQUAL_F32(10.5f, array[0].value.float_val, FOSSIL_TEST_FLOAT_EPSILON);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
    ASSUME_ITS_EQUAL_F64(30.75, array[2].value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// Test case for fossil_tofu_algorithm_compare with different types
FOSSIL_TEST_CASE(test_compare_different_types) {
    fossil_tofu_t tofu1 = fossil_tofu_create("int", "10");
    fossil_tofu_t tofu2 = fossil_tofu_create("float", "20.5");

    int comparison = fossil_tofu_algorithm_compare(tofu1, tofu2);
    ASSUME_ITS_LESS_THAN_I32(0, comparison);

    comparison = fossil_tofu_algorithm_compare(tofu2, tofu1);
    ASSUME_ITS_GREATER_THAN_I32(0, comparison);

    fossil_tofu_t tofu3 = fossil_tofu_create("double", "10.0");
    comparison = fossil_tofu_algorithm_compare(tofu1, tofu3);
    ASSUME_ITS_EQUAL_I32(0, comparison);
}

// Test case for fossil_tofu_algorithm_shuffle with different types
FOSSIL_TEST_CASE(test_shuffle_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "20.5"),
        fossil_tofu_create("double", "30.75")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_algorithm_shuffle(array, size);

    // Since shuffle is random, we just check that all elements are still present
    bool found_10 = false, found_20_5 = false, found_30_75 = false;
    for (size_t i = 0; i < size; i++) {
        if (array[i].value.int_val == 10) found_10 = true;
        if (array[i].value.float_val == 20.5f) found_20_5 = true;
        if (array[i].value.double_val == 30.75) found_30_75 = true;
    }
    ASSUME_ITS_TRUE(found_10);
    ASSUME_ITS_TRUE(found_20_5);
    ASSUME_ITS_TRUE(found_30_75);
}

// Test case for fossil_tofu_algorithm_partition with different types
FOSSIL_TEST_CASE(test_partition_different_types) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("float", "15.5"),
        fossil_tofu_create("double", "20.75"),
        fossil_tofu_create("int", "25")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    size_t partition_index = fossil_tofu_algorithm_partition(array, size, tofu_mock_is_even);
    ASSUME_ITS_EQUAL_I32(2, partition_index);
    ASSUME_ITS_EQUAL_I32(10, array[0].value.int_val);
    ASSUME_ITS_EQUAL_F64(20.75, array[1].value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_generic_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_create);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_equals);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_copy);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_verification_checks);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_create_invalid);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_destroy);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_is_valid_type);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_get_name);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_get_info);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_get_id);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_search);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_partition);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_shuffle);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_sort);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_average);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_for_each);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_summary);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_fossil_tofu_algorithm_compare);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_transform_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_accumulate_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_filter_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_reverse_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_swap_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_reduce_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_summary_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_average_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_sort_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_compare_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_shuffle_different_types);
    FOSSIL_TEST_ADD(c_generic_tofu_fixture, test_partition_different_types);

    FOSSIL_TEST_REGISTER(c_generic_tofu_fixture);
} // end of tests
