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

FOSSIL_SUITE(cpp_arraylist_tofu_fixture);

FOSSIL_SETUP(cpp_arraylist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_arraylist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::ArrayList;

FOSSIL_TEST(cpp_test_arraylist_create_and_destroy) {
    ArrayList alist("i32", 8);
    ASSUME_ITS_TRUE(alist.not_cnullptr());
    ASSUME_ITS_TRUE(alist.is_empty());
    ASSUME_ITS_EQUAL_CSTR(alist.raw()->type, "i32");
}

FOSSIL_TEST(cpp_test_arraylist_create_default) {
    ArrayList alist;
    ASSUME_ITS_TRUE(alist.not_cnullptr());
    ASSUME_ITS_EQUAL_CSTR(alist.raw()->type, "any");
}

FOSSIL_TEST(cpp_test_arraylist_insert_and_size) {
    ArrayList alist("i32", 4);
    alist.insert("10");
    alist.insert("20");
    alist.insert("30");
    ASSUME_ITS_EQUAL_SIZE(alist.size(), 3);
}

FOSSIL_TEST(cpp_test_arraylist_remove) {
    ArrayList alist("i32", 4);
    alist.insert("1");
    alist.insert("2");
    alist.insert("3");
    size_t size_before = alist.size();
    alist.remove(1);
    ASSUME_ITS_EQUAL_SIZE(alist.size(), size_before - 1);
}

FOSSIL_TEST(cpp_test_arraylist_get_and_set) {
    ArrayList alist("i32", 4);
    alist.insert("100");
    alist.insert("200");
    alist.insert("300");
    ASSUME_ITS_EQUAL_CSTR(alist.get(1).c_str(), "200");
    alist.set(1, "250");
    ASSUME_ITS_EQUAL_CSTR(alist.get(1).c_str(), "250");
}

FOSSIL_TEST(cpp_test_arraylist_get_front_and_back) {
    ArrayList alist("i32", 4);
    alist.insert("first");
    alist.insert("middle");
    alist.insert("last");
    ASSUME_ITS_EQUAL_CSTR(alist.front().c_str(), "first");
    ASSUME_ITS_EQUAL_CSTR(alist.back().c_str(), "last");
}

FOSSIL_TEST(cpp_test_arraylist_set_front_and_back) {
    ArrayList alist("i32", 4);
    alist.insert("one");
    alist.insert("two");
    alist.insert("three");
    alist.set_front("ONE");
    alist.set_back("THREE");
    ASSUME_ITS_EQUAL_CSTR(alist.front().c_str(), "ONE");
    ASSUME_ITS_EQUAL_CSTR(alist.back().c_str(), "THREE");
}

FOSSIL_TEST(cpp_test_arraylist_copy_and_move) {
    ArrayList alist1("i32", 4);
    alist1.insert("5");
    alist1.insert("10");
    alist1.insert("15");
    ArrayList alist2 = alist1;
    ASSUME_ITS_EQUAL_SIZE(alist1.size(), alist2.size());
    ASSUME_ITS_EQUAL_CSTR(alist2.get(1).c_str(), "10");
    ArrayList alist3 = std::move(alist1);
    ASSUME_ITS_TRUE(alist1.is_empty());
    ASSUME_ITS_EQUAL_SIZE(alist3.size(), 3);
}

FOSSIL_TEST(cpp_test_arraylist_empty_and_null_checks) {
    ArrayList* alist = nullptr;
    ASSUME_ITS_TRUE(alist == nullptr);
    ArrayList alist2("i32", 4);
    ASSUME_ITS_TRUE(alist2.not_cnullptr());
    ASSUME_ITS_TRUE(alist2.is_empty());
    alist2.insert("42");
    ASSUME_ITS_TRUE(alist2.not_empty());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_arraylist_tofu_tests) {    
    // arraylist ToFu Fixture
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_create_default);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_insert_and_size);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_remove);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_get_and_set);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_get_front_and_back);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_set_front_and_back);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_copy_and_move);
    FOSSIL_TEST_ADD(cpp_arraylist_tofu_fixture, cpp_test_arraylist_empty_and_null_checks);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_arraylist_tofu_fixture);
} // end of tests
