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

FOSSIL_SUITE(c_algorithm_tofu_fixture);

FOSSIL_SETUP(c_algorithm_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_algorithm_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_algorithm_compare) {
    fossil_tofu_t tofu1 = {0};
    fossil_tofu_t tofu2 = {0};
    fossil_tofu_t tofu3 = {0};
    tofu1 = fossil_tofu_create("i32", "10");
    tofu2 = fossil_tofu_create("i32", "20");
    tofu3 = fossil_tofu_create("i32", "10");
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu2, &tofu1) > 0);
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu3) == 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
    fossil_tofu_destroy(&tofu3);
}

FOSSIL_TEST(c_test_algorithm_search) {
    fossil_tofu_t array[3] = {{0}};
    array[0] = fossil_tofu_create("i32", "1");
    array[1] = fossil_tofu_create("i32", "2");
    array[2] = fossil_tofu_create("i32", "3");
    fossil_tofu_t target = fossil_tofu_create("i32", "2");
    int idx = fossil_algorithm_search(array, 3, &target);
    ASSUME_ITS_TRUE(idx >= 0 && idx < 3);
    ASSUME_ITS_EQUAL_I32(idx, 1);
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
    fossil_tofu_destroy(&target);
}

FOSSIL_TEST(c_test_algorithm_sort) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create("i32", "3");
    array[1] = fossil_tofu_create("i32", "1");
    array[2] = fossil_tofu_create("i32", "2");
    int result = fossil_algorithm_sort(array, 3, true);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[0]), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[1]), "2");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[2]), "3");
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

static int increment_transform(fossil_tofu_t *tofu) {
    int value = atoi(fossil_tofu_get_value(tofu));
    char buf[32];
#if defined(_MSC_VER)
    _snprintf(buf, sizeof(buf), "%d", value + 1);
#else
    snprintf(buf, sizeof(buf), "%d", value + 1);
#endif
    buf[sizeof(buf) - 1] = '\0'; // Ensure null-termination
    return fossil_tofu_set_value(tofu, buf);
}

FOSSIL_TEST(c_test_algorithm_transform) {
    fossil_tofu_t array[2];
    array[0] = fossil_tofu_create("i32", "10");
    array[1] = fossil_tofu_create("i32", "20");
    int result = fossil_algorithm_transform(array, 2, increment_transform);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_SUCCESS);
    // Defensive: Ensure null-termination for Windows safety
    for (int i = 0; i < 2; ++i) {
        fossil_tofu_get_value(&array[i])[31] = '\0';
    }
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[0]), "11");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[1]), "21");
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
}

static void* accumulate_sum(const fossil_tofu_t *tofu, void *accum) {
    int *sum = (int*)accum;
    if (sum && tofu) {
        const char *val = fossil_tofu_get_value(tofu);
        if (val) {
            *sum += atoi(val);
        }
    }
    return sum;
}

FOSSIL_TEST(c_test_algorithm_accumulate) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create("i32", "1");
    array[1] = fossil_tofu_create("i32", "2");
    array[2] = fossil_tofu_create("i32", "3");
    int sum = 0;
    void *result = fossil_algorithm_accumulate(array, 3, accumulate_sum, &sum);
    ASSUME_ITS_TRUE(result != NULL);
    ASSUME_ITS_EQUAL_I32(sum, 6);
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

static bool filter_even(const fossil_tofu_t *tofu) {
    int value = atoi(fossil_tofu_get_value(tofu));
    return (value % 2) == 0;
}

FOSSIL_TEST(c_test_algorithm_filter) {
    fossil_tofu_t array[4];
    array[0] = fossil_tofu_create("i32", "1");
    array[1] = fossil_tofu_create("i32", "2");
    array[2] = fossil_tofu_create("i32", "3");
    array[3] = fossil_tofu_create("i32", "4");
    fossil_tofu_t *result = NULL;
    size_t result_size = 0;
    int rc = fossil_algorithm_filter(array, 4, filter_even, &result, &result_size);
    ASSUME_ITS_EQUAL_I32(rc, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result_size, 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&result[0]), "2");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&result[1]), "4");
    for (size_t i = 0; i < 4; ++i) fossil_tofu_destroy(&array[i]);
    for (size_t i = 0; i < result_size; ++i) fossil_tofu_destroy(&result[i]);
    free(result);
    result = NULL;
}

FOSSIL_TEST(c_test_algorithm_reverse) {
    fossil_tofu_t array[3] = {{0}};
    array[0] = fossil_tofu_create("i32", "1");
    array[1] = fossil_tofu_create("i32", "2");
    array[2] = fossil_tofu_create("i32", "3");
    int rc = fossil_algorithm_reverse(array, 3);
    ASSUME_ITS_EQUAL_I32(rc, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[0]), "3");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[1]), "2");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&array[2]), "1");
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

FOSSIL_TEST(c_test_algorithm_min) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create("i32", "5");
    array[1] = fossil_tofu_create("i32", "2");
    array[2] = fossil_tofu_create("i32", "8");
    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_TRUE(min != NULL);
    if (min != NULL) {
        ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(min), "2");
    }
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

FOSSIL_TEST(c_test_algorithm_max) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create("i32", "5");
    array[1] = fossil_tofu_create("i32", "2");
    array[2] = fossil_tofu_create("i32", "8");
    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_TRUE(max != NULL);
    if (max != NULL) {
        ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(max), "8");
    }
    fossil_tofu_destroy(&array[0]);
    fossil_tofu_destroy(&array[1]);
    fossil_tofu_destroy(&array[2]);
}

static void* sum_fn(const fossil_tofu_t *tofu) {
    int *value = (int*)fossil_tofu_alloc(sizeof(int));
    if (!value) return NULL;
    const char *str = fossil_tofu_get_value(tofu);
    *value = (str != NULL) ? atoi(str) : 0;
    return value;
}

FOSSIL_TEST(c_test_algorithm_sum) {
    fossil_tofu_t array[3];
    array[0] = fossil_tofu_create("i32", "2");
    array[1] = fossil_tofu_create("i32", "3");
    array[2] = fossil_tofu_create("i32", "5");
    int total = 0;
    for (size_t i = 0; i < 3; ++i) {
        int *v = (int*)sum_fn(&array[i]);
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
FOSSIL_TEST_GROUP(c_algorithm_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_compare);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_search);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_sort);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_transform);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_accumulate);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_filter);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_reverse);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_min);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_max);
    FOSSIL_TEST_ADD(c_algorithm_tofu_fixture, c_test_algorithm_sum);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_algorithm_tofu_fixture);
} // end of tests
