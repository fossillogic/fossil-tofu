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

FOSSIL_SUITE(cpp_cqueue_tofu_fixture);

FOSSIL_SETUP(cpp_cqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_cqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::CQueue;

FOSSIL_TEST(cpp_test_cqueue_create_container_and_destroy) {
    CQueue queue("i32", 3);
    ASSUME_ITS_EQUAL_CSTR(queue.type().c_str(), "i32");
    ASSUME_ITS_EQUAL_I32(queue.size(), 0);
}

FOSSIL_TEST(cpp_test_cqueue_create_default_and_destroy) {
    CQueue queue;
    ASSUME_ITS_EQUAL_CSTR(queue.type().c_str(), "any");
    ASSUME_ITS_EQUAL_I32(queue.size(), 0);
}

FOSSIL_TEST(cpp_test_cqueue_insert_and_remove) {
    CQueue queue("i32", 2);
    int32_t result1 = queue.insert("10");
    int32_t result2 = queue.insert("20");
    int32_t result3 = queue.insert("30"); // Should fail (full)
    ASSUME_ITS_EQUAL_I32(result1, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result2, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(result3, FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_EQUAL_I32(queue.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(queue.get_rear().c_str(), "20");
    queue.remove();
    ASSUME_ITS_EQUAL_I32(queue.size(), 1);
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "20");
}

FOSSIL_TEST(cpp_test_cqueue_create_copy) {
    CQueue queue1("i32", 3);
    queue1.insert("1");
    queue1.insert("2");
    CQueue queue2(queue1);
    ASSUME_ITS_EQUAL_I32(queue2.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(queue2.get_front().c_str(), "1");
    ASSUME_ITS_EQUAL_CSTR(queue2.get_rear().c_str(), "2");
}

FOSSIL_TEST(cpp_test_cqueue_create_move) {
    CQueue queue1("i32", 2);
    queue1.insert("42");
    CQueue queue2(std::move(queue1));
    ASSUME_ITS_EQUAL_I32(queue2.size(), 1);
    ASSUME_ITS_EQUAL_CSTR(queue2.get_front().c_str(), "42");
    //ASSUME_ITS_TRUE(queue1.is_empty());
}

FOSSIL_TEST(cpp_test_cqueue_not_empty_and_is_empty) {
    CQueue queue("i32", 2);
    ASSUME_ITS_TRUE(queue.is_empty());
    ASSUME_ITS_FALSE(queue.not_empty());
    queue.insert("1");
    ASSUME_ITS_FALSE(queue.is_empty());
    ASSUME_ITS_TRUE(queue.not_empty());
    queue.remove();
    ASSUME_ITS_TRUE(queue.is_empty());
}

FOSSIL_TEST(cpp_test_cqueue_not_cnullptr_and_is_cnullptr) {
    CQueue* queue = new CQueue("i32", 1);
    ASSUME_ITS_TRUE(queue->not_cnullptr());
    ASSUME_ITS_FALSE(queue->is_cnullptr());
    delete queue;
    queue = nullptr;
    // Can't call methods on nullptr, so just check pointer
    ASSUME_ITS_FALSE(queue);
}

FOSSIL_TEST(cpp_test_cqueue_set_front_and_set_rear) {
    CQueue queue("i32", 2);
    queue.insert("100");
    queue.insert("200");
    queue.set_front("111");
    queue.set_rear("222");
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "111");
    ASSUME_ITS_EQUAL_CSTR(queue.get_rear().c_str(), "222");
}

FOSSIL_TEST(cpp_test_cqueue_get_front_and_get_rear_empty) {
    CQueue queue("i32", 1);
    ASSUME_ITS_EQUAL_CSTR(queue.get_front().c_str(), "");
    ASSUME_ITS_EQUAL_CSTR(queue.get_rear().c_str(), "");
}

FOSSIL_TEST(cpp_test_cqueue_remove_empty) {
    CQueue queue("i32", 1);
    int32_t result = queue.remove();
    ASSUME_ITS_EQUAL_I32(result, FOSSIL_TOFU_FAILURE);
}

FOSSIL_TEST(cpp_test_cqueue_size_consistency) {
    CQueue queue("i32", 3);
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
FOSSIL_TEST_GROUP(cpp_cqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_create_container_and_destroy);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_create_default_and_destroy);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_insert_and_remove);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_create_copy);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_create_move);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_set_front_and_set_rear);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_get_front_and_get_rear_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_remove_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_cqueue_tofu_fixture);
} // end of tests
