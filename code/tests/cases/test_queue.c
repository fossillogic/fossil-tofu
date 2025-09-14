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
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_SUITE(c_queue_tofu_fixture);

FOSSIL_SETUP(c_queue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_queue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_queue_create_container_and_destroy) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    ASSUME_NOT_CNULL(queue);
    ASSUME_ITS_EQUAL_CSTR(queue->type, "i32");
    fossil_queue_destroy(queue);
}

FOSSIL_TEST(c_test_queue_create_default_and_destroy) {
    fossil_queue_t* queue = fossil_queue_create_default();
    ASSUME_NOT_CNULL(queue);
    ASSUME_ITS_EQUAL_CSTR(queue->type, "any");
    fossil_queue_destroy(queue);
}

FOSSIL_TEST(c_test_queue_insert_and_remove) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    int32_t result1 = fossil_queue_insert(queue, "10");
    int32_t result2 = fossil_queue_insert(queue, "20");
    ASSUME_ITS_EQUAL_I32(result1, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result2, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_front(queue), "10");
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_rear(queue), "20");
    fossil_queue_remove(queue);
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue), 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_front(queue), "20");
    fossil_queue_destroy(queue);
}

FOSSIL_TEST(c_test_queue_create_copy) {
    fossil_queue_t* queue1 = fossil_queue_create_container("i32");
    fossil_queue_insert(queue1, "1");
    fossil_queue_insert(queue1, "2");
    fossil_queue_t* queue2 = fossil_queue_create_copy(queue1);
    ASSUME_NOT_CNULL(queue2);
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_front(queue2), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_rear(queue2), "2");
    fossil_queue_destroy(queue1);
    fossil_queue_destroy(queue2);
}

FOSSIL_TEST(c_test_queue_create_move) {
    fossil_queue_t* queue1 = fossil_queue_create_container("i32");
    fossil_queue_insert(queue1, "42");
    fossil_queue_t* queue2 = fossil_queue_create_move(queue1);
    ASSUME_NOT_CNULL(queue2);
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue2), 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_front(queue2), "42");
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue1));
    fossil_queue_destroy(queue2);
    fossil_queue_destroy(queue1);
}

FOSSIL_TEST(c_test_queue_not_empty_and_is_empty) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue));
    ASSUME_ITS_FALSE(fossil_queue_not_empty(queue));
    fossil_queue_insert(queue, "1");
    ASSUME_ITS_FALSE(fossil_queue_is_empty(queue));
    ASSUME_ITS_TRUE(fossil_queue_not_empty(queue));
    fossil_queue_remove(queue);
    ASSUME_ITS_TRUE(fossil_queue_is_empty(queue));
    fossil_queue_destroy(queue);
}

FOSSIL_TEST(c_test_queue_not_cnullptr_and_is_cnullptr) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    ASSUME_ITS_TRUE(fossil_queue_not_cnullptr(queue));
    ASSUME_ITS_FALSE(fossil_queue_is_cnullptr(queue));
    fossil_queue_destroy(queue);
    queue = NULL;
    ASSUME_ITS_FALSE(fossil_queue_not_cnullptr(queue));
    ASSUME_ITS_TRUE(fossil_queue_is_cnullptr(queue));
}

FOSSIL_TEST(c_test_queue_set_front_and_set_rear) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    fossil_queue_insert(queue, "100");
    fossil_queue_insert(queue, "200");
    fossil_queue_set_front(queue, "111");
    fossil_queue_set_rear(queue, "222");
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_front(queue), "111");
    ASSUME_ITS_EQUAL_CSTR(fossil_queue_get_rear(queue), "222");
    fossil_queue_destroy(queue);
}

FOSSIL_TEST(c_test_queue_get_front_and_get_rear_empty) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    ASSUME_ITS_CNULL(fossil_queue_get_front(queue));
    ASSUME_ITS_CNULL(fossil_queue_get_rear(queue));
    fossil_queue_destroy(queue);
}

FOSSIL_TEST(c_test_queue_remove_empty) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    int32_t result = fossil_queue_remove(queue);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
    fossil_queue_destroy(queue);
}

FOSSIL_TEST(c_test_queue_size_consistency) {
    fossil_queue_t* queue = fossil_queue_create_container("i32");
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue), 0);
    fossil_queue_insert(queue, "1");
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue), 1);
    fossil_queue_insert(queue, "2");
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue), 2);
    fossil_queue_remove(queue);
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue), 1);
    fossil_queue_remove(queue);
    ASSUME_ITS_EQUAL_I32(fossil_queue_size(queue), 0);
    fossil_queue_destroy(queue);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_queue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_create_container_and_destroy);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_create_default_and_destroy);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_insert_and_remove);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_create_copy);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_create_move);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_set_front_and_set_rear);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_get_front_and_get_rear_empty);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_remove_empty);
    FOSSIL_TEST_ADD(c_queue_tofu_fixture, c_test_queue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_queue_tofu_fixture);
} // end of tests
