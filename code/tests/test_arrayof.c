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
#include <fossil/unittest/framework.h>
#include <fossil/benchmark/framework.h>
#include <fossil/unittest/assume.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder for implementation

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_fossil_array_create) {
    fossil_array_t array = fossil_array_create("int", 3, "10", "20", "30");
    ASSUME_ITS_EQUAL_I32(3, fossil_array_size(&array));
    ASSUME_ITS_EQUAL_I32(10, array.array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array.array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(30, array.array[2].value.int_val);
    fossil_array_destroy(&array);
}

FOSSIL_TEST(test_fossil_array_add) {
    fossil_array_t array = fossil_array_create("int", 0);
    fossil_tofu_t tofu1 = fossil_tofu_create("int", "10");
    fossil_tofu_t tofu2 = fossil_tofu_create("int", "20");
    fossil_array_add(&array, tofu1);
    fossil_array_add(&array, tofu2);
    ASSUME_ITS_EQUAL_I32(2, fossil_array_size(&array));
    ASSUME_ITS_EQUAL_I32(10, array.array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array.array[1].value.int_val);
    fossil_array_destroy(&array);
}

FOSSIL_TEST(test_fossil_array_get) {
    fossil_array_t array = fossil_array_create("int", 3, "10", "20", "30");
    fossil_tofu_t tofu = fossil_array_get(&array, 1);
    ASSUME_ITS_EQUAL_I32(20, tofu.value.int_val);
    fossil_array_destroy(&array);
}

FOSSIL_TEST(test_fossil_array_size) {
    fossil_array_t array = fossil_array_create("int", 2, "10", "20");
    ASSUME_ITS_EQUAL_I32(2, fossil_array_size(&array));
    fossil_array_destroy(&array);
}

FOSSIL_TEST(test_fossil_array_is_empty) {
    fossil_array_t array = fossil_array_create("int", 0);
    ASSUME_ITS_TRUE(fossil_array_is_empty(&array));
    fossil_array_destroy(&array);
}

FOSSIL_TEST(test_fossil_array_clear) {
    fossil_array_t array = fossil_array_create("int", 3, "10", "20", "30");
    fossil_array_clear(&array);
    ASSUME_ITS_EQUAL_I32(0, fossil_array_size(&array));
    ASSUME_ITS_TRUE(fossil_array_is_empty(&array));
    fossil_array_destroy(&array);
}

// benchmarking cases to capture the true
// performence based on current structures
// implmentation.

FOSSIL_TEST(stress_test_array) {
    fossil_array_t array = fossil_array_create("int", 0);
    for (int i = 0; i < 1000000; i++) {
        fossil_tofu_t tofu = fossil_tofu_create("int", "10");
        fossil_array_add(&array, tofu);
    }
    fossil_array_destroy(&array);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_arrayof_structure_tests) {    
    // Generic ToFu ArrayOf Fixture
    ADD_TEST(test_fossil_array_create);
    ADD_TEST(test_fossil_array_add);
    ADD_TEST(test_fossil_array_get);
    ADD_TEST(test_fossil_array_size);
    ADD_TEST(test_fossil_array_is_empty);
    ADD_TEST(test_fossil_array_clear);

    // Benchmarking
    ADD_TEST(stress_test_array);
} // end of tests
