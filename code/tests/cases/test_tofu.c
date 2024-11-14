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
    ASSUME_ITS_MORE_THAN_I32(0, comparison);

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
    ASSUME_ITS_MORE_THAN_I32(0, comparison);

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
