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

FOSSIL_SUITE(objcpp_dqueue_tofu_fixture);

FOSSIL_SETUP(objcpp_dqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(objcpp_dqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::DQueue;

FOSSIL_TEST(objcpp_test_dqueue_create_container_and_destroy) {
    DQueue dqueue("i32");
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 0);
}

FOSSIL_TEST(objcpp_test_dqueue_create_default_and_destroy) {
    DQueue dqueue;
    // Default type is "any" in the C API, but not exposed in DQueue
    // So just check creation and no throw
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 0);
}

FOSSIL_TEST(objcpp_test_dqueue_insert_and_remove) {
    DQueue dqueue("i32");
    dqueue.insert("10");
    dqueue.insert("20");
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(dqueue.get_front().c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(dqueue.get_back().c_str(), "20");
    dqueue.remove();
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 1);
    ASSUME_ITS_EQUAL_CSTR(dqueue.get_front().c_str(), "20");
}

FOSSIL_TEST(objcpp_test_dqueue_create_copy) {
    DQueue dqueue1("i32");
    dqueue1.insert("1");
    dqueue1.insert("2");
    DQueue dqueue2 = dqueue1;
    ASSUME_ITS_EQUAL_I32(dqueue2.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(dqueue2.get_front().c_str(), "1");
    ASSUME_ITS_EQUAL_CSTR(dqueue2.get_back().c_str(), "2");
}

FOSSIL_TEST(objcpp_test_dqueue_create_move) {
    DQueue dqueue1("i32");
    dqueue1.insert("1");
    DQueue dqueue2(std::move(dqueue1));
    ASSUME_ITS_EQUAL_I32(dqueue2.size(), 1);
    ASSUME_ITS_EQUAL_CSTR(dqueue2.get(0).c_str(), "1");
}

FOSSIL_TEST(objcpp_test_dqueue_not_empty_and_is_empty) {
    DQueue dqueue("i32");
    ASSUME_ITS_TRUE(dqueue.is_empty());
    ASSUME_ITS_FALSE(dqueue.not_empty());
    dqueue.insert("1");
    ASSUME_ITS_FALSE(dqueue.is_empty());
    ASSUME_ITS_TRUE(dqueue.not_empty());
    dqueue.remove();
    ASSUME_ITS_TRUE(dqueue.is_empty());
}

FOSSIL_TEST(objcpp_test_dqueue_not_cnullptr_and_is_cnullptr) {
    DQueue dqueue("i32");
    ASSUME_ITS_TRUE(dqueue.not_cnullptr());
    ASSUME_ITS_FALSE(dqueue.is_cnullptr());
    // Can't set to nullptr directly, so just check after destruction
    // (Destruction is automatic, so skip further checks)
}

FOSSIL_TEST(objcpp_test_dqueue_set_front_and_set_back) {
    DQueue dqueue("i32");
    dqueue.insert("100");
    dqueue.insert("200");
    dqueue.set_front("111");
    dqueue.set_back("222");
    ASSUME_ITS_EQUAL_CSTR(dqueue.get_front().c_str(), "111");
    ASSUME_ITS_EQUAL_CSTR(dqueue.get_back().c_str(), "222");
}

FOSSIL_TEST(objcpp_test_dqueue_get_front_and_get_back_empty) {
    DQueue dqueue("i32");
    ASSUME_ITS_EQUAL_CSTR(dqueue.get_front().c_str(), "");
    ASSUME_ITS_EQUAL_CSTR(dqueue.get_back().c_str(), "");
}

FOSSIL_TEST(objcpp_test_dqueue_remove_empty) {
    DQueue dqueue("i32");
    bool threw = false;
    try {
        dqueue.remove();
    } catch (const std::runtime_error&) {
        threw = true;
    }
    ASSUME_ITS_TRUE(threw);
}

FOSSIL_TEST(objcpp_test_dqueue_size_consistency) {
    DQueue dqueue("i32");
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 0);
    dqueue.insert("1");
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 1);
    dqueue.insert("2");
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 2);
    dqueue.remove();
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 1);
    dqueue.remove();
    ASSUME_ITS_EQUAL_I32(dqueue.size(), 0);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(objcpp_dqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_create_container_and_destroy);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_create_default_and_destroy);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_insert_and_remove);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_create_copy);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_create_move);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_not_empty_and_is_empty);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_not_cnullptr_and_is_cnullptr);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_set_front_and_set_back);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_get_front_and_get_back_empty);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_remove_empty);
    FOSSIL_TEST_ADD(objcpp_dqueue_tofu_fixture, objcpp_test_dqueue_size_consistency);

    // Register the test group
    FOSSIL_TEST_REGISTER(objcpp_dqueue_tofu_fixture);
} // end of tests
