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

FOSSIL_SUITE(cpp_queue_tofu_fixture);

FOSSIL_SETUP(cpp_queue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_queue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::Queue;

FOSSIL_TEST(cpp_test_queue_create_container_and_destroy) {
    Queue queue("i32");
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "");
    // Type checking is not exposed in the C++ wrapper, so we skip it.
}

FOSSIL_TEST(cpp_test_queue_create_default_and_destroy) {
    Queue queue;
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "");
    // Type checking is not exposed in the C++ wrapper, so we skip it.
}

FOSSIL_TEST(cpp_test_queue_insert_and_remove) {
    Queue queue("i32");
    int32_t result1 = queue.insert("10");
    int32_t result2 = queue.insert("20");
    ASSUME_ITS_EQUAL_I32(result1, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result2, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(queue.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(queue.get_rear().c_str(), "20");
    queue.remove();
    ASSUME_ITS_EQUAL_I32(queue.size(), 1);
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "20");
}

FOSSIL_TEST(cpp_test_queue_create_copy) {
    Queue queue1("i32");
    queue1.insert("1");
    queue1.insert("2");
    Queue queue2(queue1);
    ASSUME_ITS_EQUAL_I32(queue2.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(queue2.get_front().c_str(), "1");
    ASSUME_ITS_EQUAL_CSTR(queue2.get_rear().c_str(), "2");
}

FOSSIL_TEST(cpp_test_queue_create_move) {
    Queue queue1("i32");
    queue1.insert("42");
    Queue queue2(std::move(queue1));
    ASSUME_ITS_EQUAL_I32(queue2.size(), 1);
    ASSUME_ITS_EQUAL_CSTR(queue2.get_front().c_str(), "42");
    // After move, queue1 is in a valid but unspecified state; skip further checks.
}

FOSSIL_TEST(cpp_test_queue_not_empty_and_is_empty) {
    Queue queue("i32");
    ASSUME_ITS_TRUE(queue.is_empty());
    ASSUME_ITS_FALSE(queue.not_empty());
    queue.insert("1");
    ASSUME_ITS_FALSE(queue.is_empty());
    ASSUME_ITS_TRUE(queue.not_empty());
    queue.remove();
    ASSUME_ITS_TRUE(queue.is_empty());
}

FOSSIL_TEST(cpp_test_queue_not_cnullptr_and_is_cnullptr) {
    Queue* queue = new Queue("i32");
    ASSUME_ITS_TRUE(queue->not_cnullptr());
    ASSUME_ITS_FALSE(queue->is_cnullptr());
    delete queue;
    queue = nullptr;
    // After deletion, pointer is nullptr, but methods can't be called; skip further checks.
}

FOSSIL_TEST(cpp_test_queue_set_front_and_set_rear) {
    Queue queue("i32");
    queue.insert("100");
    queue.insert("200");
    queue.set_front("111");
    queue.set_rear("222");
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "111");
    ASSUME_ITS_EQUAL_CSTR(queue.get_rear().c_str(), "222");
}

FOSSIL_TEST(cpp_test_queue_get_front_and_get_rear_empty) {
    Queue queue("i32");
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "");
    ASSUME_ITS_EQUAL_CSTR(queue.get_rear().c_str(), "");
}

FOSSIL_TEST(cpp_test_queue_remove_empty) {
    Queue queue("i32");
    int32_t result = queue.remove();
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

FOSSIL_TEST(cpp_test_queue_size_consistency) {
    Queue queue("i32");
    ASSUME_ITS_EQUAL_I32(queue.size(), 0);
    queue.insert("1");
    ASSUME_ITS_EQUAL_I32(queue.size(), 1);
    queue.insert("2");
    ASSUME_ITS_EQUAL_I32(queue.size(), 2);
    queue.remove();
    ASSUME_ITS_EQUAL_I32(queue.size(), 1);
    queue.remove();
    ASSUME_ITS_EQUAL_I32(queue.size(), 0);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_queue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_create_container_and_destroy);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_create_default_and_destroy);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_insert_and_remove);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_create_copy);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_create_move);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_set_front_and_set_rear);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_get_front_and_get_rear_empty);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_remove_empty);
    FOSSIL_TEST_ADD(cpp_queue_tofu_fixture, cpp_test_queue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_queue_tofu_fixture);
} // end of tests
