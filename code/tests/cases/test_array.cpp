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
FOSSIL_SUITE(cpp_array_tofu_fixture);

FOSSIL_SETUP(cpp_array_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_array_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
using fossil::tofu::Array;

FOSSIL_TEST(cpp_test_array_create_and_destroy) {
    Array array("i32");
    ASSUME_ITS_EQUAL_I32(array.size(), 0);
    ASSUME_ITS_EQUAL_I32(array.capacity(), INITIAL_CAPACITY);
}

FOSSIL_TEST(cpp_test_array_push_and_get) {
    Array array("i32");
    array.push_back("10");
    array.push_back("20");
    array.push_back("30");
    ASSUME_ITS_EQUAL_I32(array.size(), 3);
    ASSUME_ITS_EQUAL_CSTR(array.get(0).c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(array.get(1).c_str(), "20");
    ASSUME_ITS_EQUAL_CSTR(array.get(2).c_str(), "30");
}

FOSSIL_TEST(cpp_test_array_push_front_and_pop_front) {
    Array array("i32");
    array.push_front("1");
    array.push_front("2");
    array.push_front("3");
    ASSUME_ITS_EQUAL_CSTR(array.get_front().c_str(), "3");
    array.pop_front();
    ASSUME_ITS_EQUAL_CSTR(array.get_front().c_str(), "2");
}

FOSSIL_TEST(cpp_test_array_push_at_and_pop_at) {
    Array array("char");
    array.push_back("a");
    array.push_back("b");
    array.push_back("d");
    array.push_at(2, "c"); // Insert "c" at index 2
    ASSUME_ITS_EQUAL_CSTR(array.get(2).c_str(), "c");
    array.pop_at(1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(array.get(1).c_str(), "c");
}

FOSSIL_TEST(cpp_test_array_set_and_get) {
    Array array("i32");
    array.push_back("100");
    array.push_back("200");
    array.set(1, "250");
    ASSUME_ITS_EQUAL_CSTR(array.get(1).c_str(), "250");
    array.set_front("50");
    ASSUME_ITS_EQUAL_CSTR(array.get_front().c_str(), "50");
    array.set_back("300");
    ASSUME_ITS_EQUAL_CSTR(array.get_back().c_str(), "300");
}

FOSSIL_TEST(cpp_test_array_erase_and_empty) {
    Array array("i32");
    array.push_back("1");
    array.push_back("2");
    array.erase();
    ASSUME_ITS_TRUE(array.is_empty());
}

FOSSIL_TEST(cpp_test_array_copy_and_move) {
    Array array1("i32");
    array1.push_back("5");
    array1.push_back("10");
    Array array2(array1);
    ASSUME_ITS_EQUAL_I32(array2.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(array2.get(1).c_str(), "10");
    Array array3(std::move(array2));
    ASSUME_ITS_EQUAL_I32(array3.size(), 2);
    // array2 is now empty after move
}

FOSSIL_TEST(cpp_test_array_pop_back) {
    Array array("i32");
    array.push_back("1");
    array.push_back("2");
    array.push_back("3");
    array.pop_back();
    ASSUME_ITS_EQUAL_I32(array.size(), 2);
    ASSUME_ITS_EQUAL_CSTR(array.get_back().c_str(), "2");
}

FOSSIL_TEST(cpp_test_array_push_beyond_initial_capacity) {
    Array array("i32");
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        array.push_back(buf);
    }
    ASSUME_ITS_TRUE(array.size() > INITIAL_CAPACITY);
    for (int i = 0; i < INITIAL_CAPACITY + 5; ++i) {
        char buf[16];
        snprintf(buf, sizeof(buf), "%d", i);
        ASSUME_ITS_EQUAL_CSTR(array.get(i).c_str(), buf);
    }
}

FOSSIL_TEST(cpp_test_array_pop_until_empty) {
    Array array("i32");
    array.push_back("1");
    array.push_back("2");
    array.push_back("3");
    array.pop_back();
    array.pop_back();
    array.pop_back();
    ASSUME_ITS_TRUE(array.is_empty());
}

FOSSIL_TEST(cpp_test_array_pop_front_until_empty) {
    Array array("char");
    array.push_back("a");
    array.push_back("b");
    array.push_back("c");
    array.pop_front();
    array.pop_front();
    array.pop_front();
    ASSUME_ITS_TRUE(array.is_empty());
}

// Null pointer safety test is not applicable for C++ class, so we skip it.

FOSSIL_TEST(cpp_test_array_set_at_various_positions) {
    Array array("cstr");
    array.push_back("a");
    array.push_back("b");
    array.push_back("c");
    array.set_at(0, "x");
    array.set_at(1, "y");
    array.set_at(2, "z");
    ASSUME_ITS_EQUAL_CSTR(array.get(0).c_str(), "x");
    ASSUME_ITS_EQUAL_CSTR(array.get(1).c_str(), "y");
    ASSUME_ITS_EQUAL_CSTR(array.get(2).c_str(), "z");
}

FOSSIL_TEST(cpp_test_array_push_at_beginning_and_end) {
    Array array("cstr");
    array.push_back("middle");
    array.push_at(0, "start");
    array.push_at(2, "end");
    ASSUME_ITS_EQUAL_CSTR(array.get(0).c_str(), "start");
    ASSUME_ITS_EQUAL_CSTR(array.get(1).c_str(), "middle");
    ASSUME_ITS_EQUAL_CSTR(array.get(2).c_str(), "end");
}

FOSSIL_TEST(cpp_test_array_pop_at_various_positions) {
    Array array("char");
    array.push_back("a");
    array.push_back("b");
    array.push_back("c");
    array.push_back("d");
    array.pop_at(1); // Remove "b"
    ASSUME_ITS_EQUAL_CSTR(array.get(1).c_str(), "c");
    array.pop_at(0); // Remove "a"
    ASSUME_ITS_EQUAL_CSTR(array.get(0).c_str(), "c");
    array.pop_at(1); // Remove "d"
    ASSUME_ITS_EQUAL_CSTR(array.get(0).c_str(), "c");
    ASSUME_ITS_EQUAL_I32(array.size(), 1);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_array_tofu_tests) {    
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_push_and_get);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_push_front_and_pop_front);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_push_at_and_pop_at);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_set_and_get);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_erase_and_empty);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_copy_and_move);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_pop_back);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_push_beyond_initial_capacity);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_pop_until_empty);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_pop_front_until_empty);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_set_at_various_positions);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_push_at_beginning_and_end);
    FOSSIL_TEST_ADD(cpp_array_tofu_fixture, cpp_test_array_pop_at_various_positions);

    FOSSIL_TEST_REGISTER(cpp_array_tofu_fixture);
} // end of tests
