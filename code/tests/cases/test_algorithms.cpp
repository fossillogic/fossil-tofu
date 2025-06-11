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

FOSSIL_SUITE(cpp_algorithm_tofu_fixture);

FOSSIL_SETUP(cpp_algorithm_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_algorithm_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::Algorithm;
using fossil::tofu::Tofu;

FOSSIL_TEST(cpp_algorithm_compare) {
    Tofu tofu1("i32", "10");
    Tofu tofu2("i32", "20");
    Tofu tofu3("i32", "10");
    ASSUME_ITS_TRUE(Algorithm::compare(&tofu1.get_c_struct(), &tofu2.get_c_struct()) < 0);
    ASSUME_ITS_TRUE(Algorithm::compare(&tofu2.get_c_struct(), &tofu1.get_c_struct()) > 0);
    ASSUME_ITS_TRUE(Algorithm::compare(&tofu1.get_c_struct(), &tofu3.get_c_struct()) == 0);
}

FOSSIL_TEST(cpp_algorithm_search) {
    Tofu array[3] = { Tofu("i32", "1"), Tofu("i32", "2"), Tofu("i32", "3") };
    Tofu target("i32", "2");
    fossil_tofu_t cpp_array[3] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct() };
    int idx = Algorithm::search(cpp_array, 3, &target.get_c_struct());
    ASSUME_ITS_EQUAL_I32(idx, 1);
}

FOSSIL_TEST(cpp_algorithm_sort_ascending) {
    Tofu array[3] = { Tofu("i32", "3"), Tofu("i32", "1"), Tofu("i32", "2") };
    fossil_tofu_t cpp_array[3] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct() };
    int result = Algorithm::sort(cpp_array, 3, true);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[0]), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[1]), "2");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[2]), "3");
}

FOSSIL_TEST(cpp_algorithm_sort_descending) {
    Tofu array[3] = { Tofu("i32", "3"), Tofu("i32", "1"), Tofu("i32", "2") };
    fossil_tofu_t cpp_array[3] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct() };
    int result = Algorithm::sort(cpp_array, 3, false);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[0]), "3");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[1]), "2");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[2]), "1");
}

static int cpp_increment_transform(fossil_tofu_t *tofu) {
    int value = atoi(fossil_tofu_get_value(tofu));
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", value + 2);
    return fossil_tofu_set_value(tofu, buf);
}

FOSSIL_TEST(cpp_algorithm_transform) {
    Tofu array[2] = { Tofu("i32", "10"), Tofu("i32", "20") };
    fossil_tofu_t cpp_array[2] = { array[0].get_c_struct(), array[1].get_c_struct() };
    int result = Algorithm::transform(cpp_array, 2, cpp_increment_transform);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[0]), "12");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[1]), "22");
}

static void* cpp_accumulate_sum(const fossil_tofu_t *tofu, void *accum) {
    int *sum = (int*)accum;
    *sum += atoi(fossil_tofu_get_value(tofu));
    return sum;
}

FOSSIL_TEST(cpp_algorithm_accumulate) {
    Tofu array[3] = { Tofu("i32", "4"), Tofu("i32", "5"), Tofu("i32", "6") };
    int initial = 1;
    fossil_tofu_t cpp_array[3] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct() };
    int *result = (int*)Algorithm::accumulate(cpp_array, 3, cpp_accumulate_sum, &initial);
    ASSUME_ITS_EQUAL_I32(*result, 16);
}

static bool cpp_filter_odd(const fossil_tofu_t *tofu) {
    int value = atoi(fossil_tofu_get_value(tofu));
    return (value % 2) != 0;
}

FOSSIL_TEST(cpp_algorithm_filter) {
    Tofu array[4] = { Tofu("i32", "1"), Tofu("i32", "2"), Tofu("i32", "3"), Tofu("i32", "4") };
    fossil_tofu_t cpp_array[4] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct(), array[3].get_c_struct() };
    fossil_tofu_t *result = NULL;
    size_t result_size = 0;
    int rc = Algorithm::filter(cpp_array, 4, cpp_filter_odd, &result, &result_size);
    ASSUME_ITS_EQUAL_I32(rc, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result_size, 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&result[0]), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&result[1]), "3");
    for (size_t i = 0; i < result_size; ++i) fossil_tofu_destroy(&result[i]);
    free(result);
}

FOSSIL_TEST(cpp_algorithm_reverse) {
    Tofu array[3] = { Tofu("i32", "7"), Tofu("i32", "8"), Tofu("i32", "9") };
    fossil_tofu_t cpp_array[3] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct() };
    int rc = Algorithm::reverse(cpp_array, 3);
    ASSUME_ITS_EQUAL_I32(rc, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[0]), "9");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[1]), "8");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&cpp_array[2]), "7");
}

FOSSIL_TEST(cpp_algorithm_min) {
    Tofu array[3] = { Tofu("i32", "15"), Tofu("i32", "12"), Tofu("i32", "18") };
    fossil_tofu_t cpp_array[3] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct() };
    fossil_tofu_t *min = Algorithm::min(cpp_array, 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(min), "12");
}

FOSSIL_TEST(cpp_algorithm_max) {
    Tofu array[3] = { Tofu("i32", "15"), Tofu("i32", "12"), Tofu("i32", "18") };
    fossil_tofu_t cpp_array[3] = { array[0].get_c_struct(), array[1].get_c_struct(), array[2].get_c_struct() };
    fossil_tofu_t *max = Algorithm::max(cpp_array, 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(max), "18");
}

static void* cpp_sum_fn(const fossil_tofu_t *tofu) {
    int *value = (int*)malloc(sizeof(int));
    *value = atoi(fossil_tofu_get_value(tofu));
    return value;
}

FOSSIL_TEST(cpp_algorithm_sum) {
    Tofu array[3] = { Tofu("i32", "2"), Tofu("i32", "3"), Tofu("i32", "5") };
    int total = 0;
    int *values[3];
    for (size_t i = 0; i < 3; ++i) {
        values[i] = (int*)cpp_sum_fn(&array[i].get_c_struct());
        total += *values[i];
        free(values[i]);
    }
    ASSUME_ITS_EQUAL_I32(total, 10);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_algorithm_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_compare);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_search);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_sort_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_sort_descending);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_transform);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_accumulate);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_filter);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_reverse);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_min);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_max);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_algorithm_sum);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_algorithm_tofu_fixture);
} // end of tests
