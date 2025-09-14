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

FOSSIL_SUITE(cpp_pqueue_tofu_fixture);

FOSSIL_SETUP(cpp_pqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_pqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

#include <string>
#include <stdexcept>
using fossil::tofu::PQueue;

FOSSIL_TEST(cpp_test_pqueue_create_container_and_destroy) {
    PQueue pqueue("i32");
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 0u);
    // No direct type check; assume construction worked.
}

FOSSIL_TEST(cpp_test_pqueue_create_default_and_destroy) {
    PQueue pqueue;
    // No direct type check; assume construction worked.
}

FOSSIL_TEST(cpp_test_pqueue_insert_and_remove) {
    PQueue pqueue("i32");
    pqueue.insert("10", 2);
    pqueue.insert("20", 1);
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 2u);
    ASSUME_ITS_EQUAL_CSTR(pqueue.get_front().c_str(), "20"); // highest priority (lowest number)
    ASSUME_ITS_EQUAL_CSTR(pqueue.get_back().c_str(), "10");  // lowest priority (highest number)
    pqueue.remove(1);
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 1u);
    ASSUME_ITS_EQUAL_CSTR(pqueue.get_front().c_str(), "10");
}

FOSSIL_TEST(cpp_test_pqueue_create_copy) {
    PQueue pqueue1("i32");
    pqueue1.insert("1", 1);
    pqueue1.insert("2", 2);
    PQueue pqueue2 = pqueue1;
    ASSUME_ITS_EQUAL_U32(pqueue2.size(), 2u);
    ASSUME_ITS_EQUAL_CSTR(pqueue2.get_front().c_str(), "1");
    ASSUME_ITS_EQUAL_CSTR(pqueue2.get_back().c_str(), "2");
}

FOSSIL_TEST(cpp_test_pqueue_create_move) {
    PQueue pqueue1("i32");
    pqueue1.insert("42", 5);
    PQueue pqueue2 = std::move(pqueue1);
    ASSUME_ITS_EQUAL_U32(pqueue2.size(), 1u);
    ASSUME_ITS_EQUAL_CSTR(pqueue2.get_front().c_str(), "42");
    ASSUME_ITS_TRUE(pqueue1.is_empty());
}

FOSSIL_TEST(cpp_test_pqueue_not_empty_and_is_empty) {
    PQueue pqueue("i32");
    ASSUME_ITS_TRUE(pqueue.is_empty());
    ASSUME_ITS_FALSE(pqueue.not_empty());
    pqueue.insert("1", 1);
    ASSUME_ITS_FALSE(pqueue.is_empty());
    ASSUME_ITS_TRUE(pqueue.not_empty());
    pqueue.remove(1);
    ASSUME_ITS_TRUE(pqueue.is_empty());
}

FOSSIL_TEST(cpp_test_pqueue_not_cnullptr_and_is_cnullptr) {
    PQueue* pqueue = new PQueue("i32");
    ASSUME_ITS_TRUE(pqueue->not_cnullptr());
    ASSUME_ITS_FALSE(pqueue->is_cnullptr());
    delete pqueue;
    pqueue = nullptr;
    // Can't call member functions on nullptr, so just check pointer.
    ASSUME_ITS_FALSE(pqueue);
}

FOSSIL_TEST(cpp_test_pqueue_set_front_and_set_back) {
    PQueue pqueue("i32");
    pqueue.insert("100", 1);
    pqueue.insert("200", 2);
    pqueue.set_front("111");
    pqueue.set_back("222");
    ASSUME_ITS_EQUAL_CSTR(pqueue.get_front().c_str(), "111");
    ASSUME_ITS_EQUAL_CSTR(pqueue.get_back().c_str(), "222");
}

FOSSIL_TEST(cpp_test_pqueue_get_front_and_get_back_empty) {
    PQueue pqueue("i32");
    ASSUME_ITS_EQUAL_CSTR(pqueue.get_front().c_str(), "");
    ASSUME_ITS_EQUAL_CSTR(pqueue.get_back().c_str(), "");
}

FOSSIL_TEST(cpp_test_pqueue_remove_empty) {
    PQueue pqueue("i32");
    // Remove from empty queue should not throw, but nothing to check.
    pqueue.remove(1);
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 0u);
}

FOSSIL_TEST(cpp_test_pqueue_size_consistency) {
    PQueue pqueue("i32");
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 0u);
    pqueue.insert("1", 1);
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 1u);
    pqueue.insert("2", 2);
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 2u);
    pqueue.remove(1);
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 1u);
    pqueue.remove(2);
    ASSUME_ITS_EQUAL_U32(pqueue.size(), 0u);
}


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_pqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_create_container_and_destroy);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_create_default_and_destroy);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert_and_remove);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_create_copy);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_create_move);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_set_front_and_set_back);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_get_front_and_get_back_empty);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove_empty);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_pqueue_tofu_fixture);
} // end of tests
