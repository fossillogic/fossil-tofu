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

// TODO: Add performance tests for each algorithm
// TODO: Make it so Algorithm class can play with the ToFu class directly

FOSSIL_TEST(cpp_test_algorithm_compare) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("10"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("20"));
    fossil_tofu_t tofu3 = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("10"));
    ASSUME_ITS_TRUE(Algorithm::compare(&tofu1, &tofu2) < 0);
    ASSUME_ITS_TRUE(Algorithm::compare(&tofu2, &tofu1) > 0);
    ASSUME_ITS_TRUE(Algorithm::compare(&tofu1, &tofu3) == 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
    fossil_tofu_destroy(&tofu3);
}

FOSSIL_TEST(cpp_test_algorithm_search) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("1"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("3"));
    fossil_tofu_t target = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    int idx = Algorithm::search(array, 3, &target);
    ASSUME_ITS_TRUE(idx >= 0 && idx < 3);
    ASSUME_ITS_EQUAL_I32(idx, 1);
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
    fossil_tofu_destroy(&target);
}

FOSSIL_TEST(cpp_test_algorithm_sort) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("3"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("1"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    int result = Algorithm::sort(array, 3, true);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[0]), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[1]), "2");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[2]), "3");
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

static int cpp_increment_transform(fossil_tofu_t *tofu) {
    int value = atoi(fossil_tofu_get_value(tofu));
    char buf[32];
#if defined(_MScpp_VER)
    _snprintf(buf, sizeof(buf), "%d", value + 1);
#else
    snprintf(buf, sizeof(buf), "%d", value + 1);
#endif
    buf[sizeof(buf) - 1] = '\0';
    return fossil_tofu_set_value(tofu, buf);
}

FOSSIL_TEST(cpp_test_algorithm_transform) {
    fossil_tofu_t array[2];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("10"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("20"));
    int result = Algorithm::transform(array, 2, cpp_increment_transform);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[0]), "11");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[1]), "21");
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
}

static void* cpp_accumulate_sum(const fossil_tofu_t *tofu, void *accum) {
    int *sum = (int*)accum;
    if (sum && tofu) {
        const char *val = fossil_tofu_get_value(tofu);
        if (val) {
            *sum += atoi(val);
        }
    }
    return accum;
}

FOSSIL_TEST(cpp_test_algorithm_accumulate) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("1"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("3"));
    int sum = 0;
    void *result = Algorithm::accumulate(array, 3, cpp_accumulate_sum, &sum);
    ASSUME_ITS_TRUE(result != nullptr);
    ASSUME_ITS_EQUAL_I32(sum, 6);
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

static bool cpp_filter_even(const fossil_tofu_t *tofu) {
    int value = atoi(fossil_tofu_get_value(tofu));
    return (value % 2) == 0;
}

FOSSIL_TEST(cpp_test_algorithm_filter) {
    fossil_tofu_t array[4];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("1"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("3"));
    array[3] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("4"));
    fossil_tofu_t *result = nullptr;
    size_t result_size = 0;
    int rc = Algorithm::filter(array, 4, cpp_filter_even, &result, &result_size);
    ASSUME_ITS_EQUAL_I32(rc, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result_size, 2);
    ASSUME_ITS_TRUE(result != nullptr);
    if (result != nullptr && result_size >= 2) {
        ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&result[0]), "2");
        ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&result[1]), "4");
    }
    for (size_t i = 0; i < 4; ++i) fossil_tofu_destroy(&array[i]);
    if (result != nullptr) {
        for (size_t i = 0; i < result_size; ++i) fossil_tofu_destroy(&result[i]);
        free(result);
        result = nullptr;
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("1"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("3"));
    int rc = Algorithm::reverse(array, 3);
    ASSUME_ITS_EQUAL_I32(rc, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[0]), "3");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[1]), "2");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[2]), "1");
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

FOSSIL_TEST(cpp_test_algorithm_min) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("5"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("8"));
    fossil_tofu_t *min = Algorithm::min(array, 3);
    ASSUME_ITS_TRUE(min != nullptr);
    if (min != nullptr) {
        ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(min), "2");
    }
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

FOSSIL_TEST(cpp_test_algorithm_max) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("5"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("8"));
    fossil_tofu_t *max = Algorithm::max(array, 3);
    ASSUME_ITS_TRUE(max != nullptr);
    if (max != nullptr) {
        ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(max), "8");
    }
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

static void* cpp_sum_fn(const fossil_tofu_t *tofu) {
    int *value = (int*)malloc(sizeof(int));
    if (!value) return nullptr;
    const char *str = fossil_tofu_get_value(tofu);
    *value = (str != nullptr) ? atoi(str) : 0;
    return value;
}

FOSSIL_TEST(cpp_test_algorithm_sum) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("2"));
    array[1] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("3"));
    array[2] = fossil_tofu_create(const_cast<char *>("i32"), const_cast<char *>("5"));
    int total = 0;
    for (size_t i = 0; i < 3; ++i) {
        int *v = (int*)cpp_sum_fn(&array[i]);
        if (v) {
            total += *v;
            free(v);
        }
    }
    ASSUME_ITS_EQUAL_I32(total, 10);
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_algorithm_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_compare);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_search);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_sort);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_transform);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_accumulate);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_filter);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_reverse);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_min);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_max);
    FOSSIL_TEST_ADD(cpp_algorithm_tofu_fixture, cpp_test_algorithm_sum);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_algorithm_tofu_fixture);
} // end of tests
