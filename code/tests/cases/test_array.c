/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include <fossil/pizza/framework.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_SUITE(c_array_tofu_fixture);

FOSSIL_SETUP(c_array_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_array_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST(c_test_array_create_and_destroy) {
    fossil_array_t* array = fossil_array_create_container("i32");
    ASSUME_NOT_CNULL(array);
    ASSUME_ITS_EQUAL_I32(fossil_array_size(array), 0);
    ASSUME_ITS_EQUAL_I32(fossil_array_capacity(array), INITIAL_CAPACITY);
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_push_and_get) {
    fossil_array_t* array = fossil_array_create_container("i32");
    fossil_array_push_back(array, "10");
    fossil_array_push_back(array, "20");
    fossil_array_push_back(array, "30");
    ASSUME_ITS_EQUAL_I32(fossil_array_size(array), 3);
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 0), "10");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 1), "20");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 2), "30");
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_push_front_and_pop_front) {
    fossil_array_t* array = fossil_array_create_container("i32");
    fossil_array_push_front(array, "1");
    fossil_array_push_front(array, "2");
    fossil_array_push_front(array, "3");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get_front(array), "3");
    fossil_array_pop_front(array);
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get_front(array), "2");
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_push_at_and_pop_at) {
    fossil_array_t* array = fossil_array_create_container("char");
    fossil_array_push_back(array, "a");
    fossil_array_push_back(array, "b");
    fossil_array_push_back(array, "d");
    fossil_array_push_at(array, 2, "c"); // Insert "c" at index 2
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 2), "c");
    fossil_array_pop_at(array, 1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 1), "c");
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_set_and_get) {
    fossil_array_t* array = fossil_array_create_container("i32");
    fossil_array_push_back(array, "100");
    fossil_array_push_back(array, "200");
    fossil_array_set(array, 1, "250");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 1), "250");
    fossil_array_set_front(array, "50");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get_front(array), "50");
    fossil_array_set_back(array, "300");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get_back(array), "300");
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_erase_and_empty) {
    fossil_array_t* array = fossil_array_create_container("i32");
    fossil_array_push_back(array, "1");
    fossil_array_push_back(array, "2");
    fossil_array_erase(array);
    ASSUME_ITS_TRUE(fossil_array_is_empty(array));
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_copy_and_move) {
    fossil_array_t* array1 = fossil_array_create_container("i32");
    fossil_array_push_back(array1, "5");
    fossil_array_push_back(array1, "10");
    fossil_array_t* array2 = fossil_array_create_copy(array1);
    ASSUME_ITS_EQUAL_I32(fossil_array_size(array2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array2, 1), "10");
    fossil_array_t* array3 = fossil_array_create_move(array2);
    ASSUME_ITS_EQUAL_I32(fossil_array_size(array3), 2);
    fossil_array_destroy(array1);
    fossil_array_destroy(array3);
    // array2 is now empty after move
}

FOSSIL_TEST(c_test_array_pop_back) {
    fossil_array_t* array = fossil_array_create_container("i32");
    fossil_array_push_back(array, "1");
    fossil_array_push_back(array, "2");
    fossil_array_push_back(array, "3");
    fossil_array_pop_back(array);
    ASSUME_ITS_EQUAL_I32(fossil_array_size(array), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get_back(array), "2");
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_push_beyond_initial_capacity) {
    fossil_array_t* array = fossil_array_create_container("i32");
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        fossil_array_push_back(array, buf);
    }
    ASSUME_ITS_TRUE(fossil_array_size(array) > INITIAL_CAPACITY);
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, i), buf);
    }
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_pop_until_empty) {
    fossil_array_t* array = fossil_array_create_container("i32");
    fossil_array_push_back(array, "1");
    fossil_array_push_back(array, "2");
    fossil_array_push_back(array, "3");
    fossil_array_pop_back(array);
    fossil_array_pop_back(array);
    fossil_array_pop_back(array);
    ASSUME_ITS_TRUE(fossil_array_is_empty(array));
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_pop_front_until_empty) {
    fossil_array_t* array = fossil_array_create_container("char");
    fossil_array_push_back(array, "a");
    fossil_array_push_back(array, "b");
    fossil_array_push_back(array, "c");
    fossil_array_pop_front(array);
    fossil_array_pop_front(array);
    fossil_array_pop_front(array);
    ASSUME_ITS_TRUE(fossil_array_is_empty(array));
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_null_pointer_safety) {
    fossil_array_t* array = NULL;
    ASSUME_ITS_TRUE(fossil_array_is_cnullptr(array));
    ASSUME_ITS_FALSE(fossil_array_not_cnullptr(array));
    ASSUME_ITS_TRUE(fossil_array_is_empty(array));
    ASSUME_ITS_FALSE(fossil_array_not_empty(array));
    ASSUME_ITS_EQUAL_I32(fossil_array_size(array), 0);
    ASSUME_ITS_EQUAL_I32(fossil_array_capacity(array), 0);
    fossil_array_pop_back(array); // Should not crash
    fossil_array_erase(array);    // Should not crash
}

FOSSIL_TEST(c_test_array_set_at_various_positions) {
    fossil_array_t* array = fossil_array_create_container("cstr");
    fossil_array_push_back(array, "a");
    fossil_array_push_back(array, "b");
    fossil_array_push_back(array, "c");
    fossil_array_set_at(array, 0, "x");
    fossil_array_set_at(array, 1, "y");
    fossil_array_set_at(array, 2, "z");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 0), "x");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 1), "y");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 2), "z");
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_push_at_beginning_and_end) {
    fossil_array_t* array = fossil_array_create_container("cstr");
    fossil_array_push_back(array, "middle");
    fossil_array_push_at(array, 0, "start");
    fossil_array_push_at(array, 2, "end");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 0), "start");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 1), "middle");
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 2), "end");
    fossil_array_destroy(array);
}

FOSSIL_TEST(c_test_array_pop_at_various_positions) {
    fossil_array_t* array = fossil_array_create_container("char");
    fossil_array_push_back(array, "a");
    fossil_array_push_back(array, "b");
    fossil_array_push_back(array, "c");
    fossil_array_push_back(array, "d");
    fossil_array_pop_at(array, 1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 1), "c");
    fossil_array_pop_at(array, 0); // Remove "a"
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 0), "c");
    fossil_array_pop_at(array, 1); // Remove "d"
    ASSUME_ITS_EQUAL_CSTR(fossil_array_get(array, 0), "c");
    ASSUME_ITS_EQUAL_I32(fossil_array_size(array), 1);
    fossil_array_destroy(array);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_array_tofu_tests) {    
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_create_and_destroy);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_push_and_get);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_push_front_and_pop_front);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_push_at_and_pop_at);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_set_and_get);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_erase_and_empty);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_copy_and_move);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_pop_back);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_push_beyond_initial_capacity);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_pop_until_empty);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_pop_front_until_empty);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_null_pointer_safety);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_set_at_various_positions);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_push_at_beginning_and_end);
    FOSSIL_TEST_ADD(c_array_tofu_fixture, c_test_array_pop_at_various_positions);

    FOSSIL_TEST_REGISTER(c_array_tofu_fixture);
} // end of tests
