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

FOSSIL_SUITE(c_cqueue_tofu_fixture);

FOSSIL_SETUP(c_cqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_cqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_cqueue_create_container_and_destroy) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 3);
    ASSUME_NOT_CNULL(queue);
    ASSUME_ITS_EQUAL_CSTR(queue->type, "i32");
    ASSUME_ITS_EQUAL_I32(queue->capacity, 3);
    ASSUME_ITS_EQUAL_I32(queue->size, 0);
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST(c_test_cqueue_create_default_and_destroy) {
    fossil_cqueue_t* queue = fossil_cqueue_create_default();
    ASSUME_NOT_CNULL(queue);
    ASSUME_ITS_EQUAL_CSTR(queue->type, "any");
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST(c_test_cqueue_insert_and_remove) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 2);
    int32_t result1 = fossil_cqueue_insert(queue, "10");
    int32_t result2 = fossil_cqueue_insert(queue, "20");
    int32_t result3 = fossil_cqueue_insert(queue, "30"); // Should fail (full)
    ASSUME_ITS_EQUAL_I32(result1, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result2, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result3, FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_front(queue), "10");
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_rear(queue), "20");
    fossil_cqueue_remove(queue);
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue), 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_front(queue), "20");
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST(c_test_cqueue_create_copy) {
    fossil_cqueue_t* queue1 = fossil_cqueue_create_container("i32", 3);
    fossil_cqueue_insert(queue1, "1");
    fossil_cqueue_insert(queue1, "2");
    fossil_cqueue_t* queue2 = fossil_cqueue_create_copy(queue1);
    ASSUME_NOT_CNULL(queue2);
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue2), 2);
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_front(queue2), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_rear(queue2), "2");
    fossil_cqueue_destroy(queue1);
    fossil_cqueue_destroy(queue2);
}

FOSSIL_TEST(c_test_cqueue_create_move) {
    fossil_cqueue_t* queue1 = fossil_cqueue_create_container("i32", 2);
    fossil_cqueue_insert(queue1, "42");
    fossil_cqueue_t* queue2 = fossil_cqueue_create_move(queue1);
    ASSUME_NOT_CNULL(queue2);
    ASSUME_ITS_EQUAL_I32(queue2->size, 1);
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_front(queue2), "42");
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(queue1));
    fossil_cqueue_destroy(queue2);
    fossil_cqueue_destroy(queue1);
}

FOSSIL_TEST(c_test_cqueue_not_empty_and_is_empty) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 2);
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(queue));
    ASSUME_ITS_FALSE(fossil_cqueue_not_empty(queue));
    fossil_cqueue_insert(queue, "1");
    ASSUME_ITS_FALSE(fossil_cqueue_is_empty(queue));
    ASSUME_ITS_TRUE(fossil_cqueue_not_empty(queue));
    fossil_cqueue_remove(queue);
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(queue));
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST(c_test_cqueue_not_cnullptr_and_is_cnullptr) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 1);
    ASSUME_ITS_TRUE(fossil_cqueue_not_cnullptr(queue));
    ASSUME_ITS_FALSE(fossil_cqueue_is_cnullptr(queue));
    fossil_cqueue_destroy(queue);
    queue = NULL;
    ASSUME_ITS_FALSE(fossil_cqueue_not_cnullptr(queue));
    ASSUME_ITS_TRUE(fossil_cqueue_is_cnullptr(queue));
}

FOSSIL_TEST(c_test_cqueue_set_front_and_set_rear) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 2);
    fossil_cqueue_insert(queue, "100");
    fossil_cqueue_insert(queue, "200");
    fossil_cqueue_set_front(queue, "111");
    fossil_cqueue_set_rear(queue, "222");
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_front(queue), "111");
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_rear(queue), "222");
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST(c_test_cqueue_get_front_and_get_rear_empty) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 1);
    ASSUME_ITS_CNULL(fossil_cqueue_get_front(queue));
    ASSUME_ITS_CNULL(fossil_cqueue_get_rear(queue));
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST(c_test_cqueue_remove_empty) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 1);
    int32_t result = fossil_cqueue_remove(queue);
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST(c_test_cqueue_size_consistency) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container("i32", 3);
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue), 0);
    fossil_cqueue_insert(queue, "1");
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue), 1);
    fossil_cqueue_insert(queue, "2");
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue), 2);
    fossil_cqueue_remove(queue);
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue), 1);
    fossil_cqueue_remove(queue);
    ASSUME_ITS_EQUAL_I32(fossil_cqueue_size(queue), 0);
    fossil_cqueue_destroy(queue);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_cqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_create_container_and_destroy);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_create_default_and_destroy);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_insert_and_remove);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_create_copy);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_create_move);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_set_front_and_set_rear);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_get_front_and_get_rear_empty);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_remove_empty);
    FOSSIL_TEST_ADD(c_cqueue_tofu_fixture, c_test_cqueue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_cqueue_tofu_fixture);
} // end of tests
