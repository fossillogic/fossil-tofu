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

FOSSIL_SUITE(cpp_dlist_tofu_fixture);

FOSSIL_SETUP(cpp_dlist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_dlist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::DList;

FOSSIL_TEST(cpp_test_dlist_create_and_destroy) {
    DList dlist("i32");
    ASSUME_ITS_TRUE(dlist.not_cnullptr());
    ASSUME_ITS_TRUE(std::string(dlist.get_front().c_str() ? dlist.get_front().c_str() : "") == "");
    ASSUME_ITS_TRUE(dlist.is_empty());
}

FOSSIL_TEST(cpp_test_dlist_create_default) {
    DList dlist;
    ASSUME_ITS_TRUE(dlist.not_cnullptr());
    // Default type is "any" in the C API, but not exposed in DList, so just check not null
}

FOSSIL_TEST(cpp_test_dlist_insert_and_size) {
    DList dlist("i32");
    ASSUME_ITS_EQUAL_I32(dlist.insert((char*)"10"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(dlist.insert((char*)"20"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(dlist.insert((char*)"30"), FOSSIL_TOFU_SUCCESS);
}

FOSSIL_TEST(cpp_test_dlist_remove) {
    DList dlist("i32");
    dlist.insert((char*)"1");
    dlist.insert((char*)"2");
    dlist.insert((char*)"3");
    size_t size_before = dlist.size();
    ASSUME_ITS_EQUAL_I32(dlist.remove(), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_SIZE(dlist.size(), size_before - 2);
}

FOSSIL_TEST(cpp_test_dlist_reverse_forward) {
    DList dlist("i32");
    dlist.insert((char*)"A");
    dlist.insert((char*)"B");
    dlist.insert((char*)"C");
    std::string front_before = dlist.get_front();
    std::string back_before = dlist.get_back();
    dlist.reverse_forward();
    std::string front_after = dlist.get_front();
    std::string back_after = dlist.get_back();
    ASSUME_ITS_EQUAL_CSTR(front_before.c_str(), back_after.c_str());
    ASSUME_ITS_EQUAL_CSTR(back_before.c_str(), front_after.c_str());
}

FOSSIL_TEST(cpp_test_dlist_reverse_backward) {
    DList dlist("i32");
    dlist.insert((char*)"X");
    dlist.insert((char*)"Y");
    dlist.insert((char*)"Z");
    std::string front_before = dlist.get_front();
    std::string back_before = dlist.get_back();
    dlist.reverse_backward();
    std::string front_after = dlist.get_front();
    std::string back_after = dlist.get_back();
    ASSUME_ITS_EQUAL_CSTR(front_before.c_str(), back_after.c_str());
    ASSUME_ITS_EQUAL_CSTR(back_before.c_str(), front_after.c_str());
}

FOSSIL_TEST(cpp_test_dlist_get_and_set) {
    DList dlist("i32");
    dlist.insert((char*)"100");
    dlist.insert((char*)"200");
    dlist.insert((char*)"300");
    ASSUME_ITS_EQUAL_CSTR(dlist.get(1).c_str(), "200");
    dlist.set(1, (char*)"250");
    ASSUME_ITS_EQUAL_CSTR(dlist.get(1).c_str(), "250");
}

FOSSIL_TEST(cpp_test_dlist_get_front_and_back) {
    DList dlist("i32");
    dlist.insert((char*)"first");
    dlist.insert((char*)"middle");
    dlist.insert((char*)"last");
    ASSUME_ITS_EQUAL_CSTR(dlist.get_front().c_str(), "first");
    ASSUME_ITS_EQUAL_CSTR(dlist.get_back().c_str(), "last");
}

FOSSIL_TEST(cpp_test_dlist_set_front_and_back) {
    DList dlist("i32");
    dlist.insert((char*)"one");
    dlist.insert((char*)"two");
    dlist.insert((char*)"three");
    dlist.set_front((char*)"ONE");
    dlist.set_back((char*)"THREE");
    ASSUME_ITS_EQUAL_CSTR(dlist.get_front().c_str(), "ONE");
    ASSUME_ITS_EQUAL_CSTR(dlist.get_back().c_str(), "THREE");
}

FOSSIL_TEST(cpp_test_dlist_copy_and_move) {
    DList dlist1("i32");
    dlist1.insert((char*)"5");
    dlist1.insert((char*)"10");
    dlist1.insert((char*)"15");
    DList dlist2 = dlist1; // Copy
    ASSUME_ITS_EQUAL_SIZE(dlist1.size(), dlist2.size());
    ASSUME_ITS_EQUAL_CSTR(dlist2.get(1).c_str(), "10");
    DList dlist3 = std::move(dlist1); // Move
    ASSUME_ITS_TRUE(dlist1.is_empty());
    ASSUME_ITS_EQUAL_SIZE(dlist3.size(), 3);
}

FOSSIL_TEST(cpp_test_dlist_empty_and_null_checks) {
    DList* dlist = nullptr;
    ASSUME_ITS_TRUE(dlist == nullptr || dlist->is_cnullptr());
    DList dlist2("i32");
    ASSUME_ITS_TRUE(dlist2.not_cnullptr());
    ASSUME_ITS_TRUE(dlist2.is_empty());
    dlist2.insert((char*)"42");
    ASSUME_ITS_TRUE(dlist2.not_empty());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_dlist_tofu_tests) {    
    // dlist ToFu Fixture
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_create_default);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_insert_and_size);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_remove);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_reverse_forward);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_reverse_backward);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_get_and_set);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_get_front_and_back);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_set_front_and_back);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_copy_and_move);
    FOSSIL_TEST_ADD(cpp_dlist_tofu_fixture, cpp_test_dlist_empty_and_null_checks);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_dlist_tofu_fixture);
} // end of tests
