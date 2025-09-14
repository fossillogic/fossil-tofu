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

FOSSIL_SUITE(cpp_flist_tofu_fixture);

FOSSIL_SETUP(cpp_flist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_flist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::FList;

FOSSIL_TEST(cpp_test_flist_create_and_destroy) {
    FList flist("i32");
    ASSUME_ITS_TRUE(flist.not_cnullptr());
    // Type check not available directly; assume creation is correct.
    ASSUME_ITS_TRUE(flist.is_empty());
}

FOSSIL_TEST(cpp_test_flist_create_default) {
    FList flist;
    ASSUME_ITS_TRUE(flist.not_cnullptr());
    // Type check not available directly; assume default is "any".
}

FOSSIL_TEST(cpp_test_flist_insert_and_size) {
    FList flist("i32");
    flist.insert("10");
    flist.insert("20");
    flist.insert("30");
    ASSUME_ITS_EQUAL_CSTR(flist.get(0).c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(flist.get(1).c_str(), "20");
    ASSUME_ITS_EQUAL_CSTR(flist.get(2).c_str(), "30");
}

FOSSIL_TEST(cpp_test_flist_remove) {
    FList flist("i32");
    flist.insert("1");
    flist.insert("2");
    flist.insert("3");
    size_t size_before = flist.size();
    flist.remove();
    ASSUME_ITS_EQUAL_SIZE(flist.size(), size_before - 1);
}

FOSSIL_TEST(cpp_test_flist_reverse_forward) {
    FList flist("i32");
    flist.insert("A");
    flist.insert("B");
    flist.insert("C");
    std::string front_before = flist.front();
    std::string back_before = flist.back();
    flist.reverse_forward();
    std::string front_after = flist.front();
    std::string back_after = flist.back();
    ASSUME_NOT_EQUAL_CSTR(front_before.c_str(), front_after.c_str());
    ASSUME_NOT_EQUAL_CSTR(back_before.c_str(), back_after.c_str());
}

FOSSIL_TEST(cpp_test_flist_reverse_backward) {
    FList flist("i32");
    flist.insert("X");
    flist.insert("Y");
    flist.insert("Z");
    std::string front_before = flist.front();
    std::string back_before = flist.back();
    flist.reverse_backward();
    std::string front_after = flist.front();
    std::string back_after = flist.back();
    ASSUME_NOT_EQUAL_CSTR(front_before.c_str(), front_after.c_str());
    ASSUME_NOT_EQUAL_CSTR(back_before.c_str(), back_after.c_str());
}

FOSSIL_TEST(cpp_test_flist_get_and_set) {
    FList flist("i32");
    flist.insert("100");
    flist.insert("200");
    flist.insert("300");
    ASSUME_ITS_EQUAL_CSTR(flist.get(1).c_str(), "200");
    flist.set(1, "250");
    ASSUME_ITS_EQUAL_CSTR(flist.get(1).c_str(), "250");
}

FOSSIL_TEST(cpp_test_flist_get_front_and_back) {
    FList flist("i32");
    flist.insert("first");
    flist.insert("middle");
    flist.insert("last");
    ASSUME_ITS_EQUAL_CSTR(flist.front().c_str(), "first");
    ASSUME_ITS_EQUAL_CSTR(flist.back().c_str(), "last");
}

FOSSIL_TEST(cpp_test_flist_set_front_and_back) {
    FList flist("i32");
    flist.insert("one");
    flist.insert("two");
    flist.insert("three");
    flist.set_front("ONE");
    flist.set_back("THREE");
    ASSUME_ITS_EQUAL_CSTR(flist.front().c_str(), "ONE");
    ASSUME_ITS_EQUAL_CSTR(flist.back().c_str(), "THREE");
}

FOSSIL_TEST(cpp_test_flist_copy_and_move) {
    FList flist1("i32");
    flist1.insert("5");
    flist1.insert("10");
    flist1.insert("15");

    FList flist2 = flist1; // Copy constructor
    ASSUME_ITS_EQUAL_SIZE(flist1.size(), flist2.size());
    ASSUME_ITS_EQUAL_CSTR(flist2.get(1).c_str(), "10");
    FList flist3 = std::move(flist1); // Move constructor
    ASSUME_ITS_TRUE(flist1.is_empty() || flist1.is_cnullptr());
    ASSUME_ITS_EQUAL_CSTR(flist3.get(0).c_str(), "5");
    ASSUME_ITS_EQUAL_CSTR(flist3.get(1).c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(flist3.get(2).c_str(), "15");
}

FOSSIL_TEST(cpp_test_flist_empty_and_null_checks) {
    FList* flist = nullptr;
    // Nullptr check
    ASSUME_ITS_TRUE(flist == nullptr);
    FList flist2("i32");
    ASSUME_ITS_TRUE(flist2.not_cnullptr());
    ASSUME_ITS_TRUE(flist2.is_empty());
    flist2.insert("42");
    ASSUME_ITS_TRUE(flist2.not_empty());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_flist_tofu_tests) {    
    // flist ToFu Fixture
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_create_default);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_insert_and_size);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_remove);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_forward);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_reverse_backward);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_get_and_set);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_get_front_and_back);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_set_front_and_back);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_copy_and_move);
    FOSSIL_TEST_ADD(cpp_flist_tofu_fixture, cpp_test_flist_empty_and_null_checks);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_flist_tofu_fixture);
} // end of tests
