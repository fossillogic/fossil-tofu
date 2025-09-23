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

FOSSIL_SUITE(cpp_clist_tofu_fixture);

FOSSIL_SETUP(cpp_clist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_clist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

using fossil::tofu::CList;

FOSSIL_TEST(cpp_test_clist_create_and_destroy) {
    CList clist("i32");
    ASSUME_ITS_TRUE(clist.not_cnullptr());
    ASSUME_ITS_TRUE(clist.is_empty());
}

FOSSIL_TEST(cpp_test_clist_create_default) {
    CList clist;
    ASSUME_ITS_TRUE(clist.not_cnullptr());
    // Default type is "any" in C API, but C++ wrapper does not expose type directly.
    ASSUME_ITS_TRUE(clist.is_empty());
}

FOSSIL_TEST(cpp_test_clist_insert_and_size) {
    CList clist("i32");
    ASSUME_ITS_EQUAL_I32(clist.insert("10"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(clist.insert("20"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_I32(clist.insert("30"), FOSSIL_TOFU_SUCCESS);
}

FOSSIL_TEST(cpp_test_clist_remove) {
    CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.insert("3");
    size_t size_before = clist.size();
    ASSUME_ITS_EQUAL_I32(clist.remove(), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_SIZE(clist.size(), size_before - 2);
}

FOSSIL_TEST(cpp_test_clist_reverse) {
    CList clist("i32");
    clist.insert("A");
    clist.insert("B");
    clist.insert("C");
    std::string front_before = clist.get_front();
    std::string back_before = clist.get_back();
    clist.reverse();
    std::string front_after = clist.get_front();
    std::string back_after = clist.get_back();
    ASSUME_NOT_EQUAL_CSTR(front_before.c_str(), back_after.c_str());
    ASSUME_NOT_EQUAL_CSTR(back_before.c_str(), front_after.c_str());
}

FOSSIL_TEST(cpp_test_clist_get_and_set) {
    CList clist("i32");
    clist.insert("100");
    clist.insert("200");
    clist.insert("300");
    ASSUME_ITS_EQUAL_CSTR(clist.get(1).c_str(), "200");
    clist.set(1, "250");
    ASSUME_ITS_EQUAL_CSTR(clist.get(1).c_str(), "250");
}

FOSSIL_TEST(cpp_test_clist_get_front_and_back) {
    CList clist("i32");
    clist.insert("first");
    clist.insert("middle");
    clist.insert("last");
    ASSUME_ITS_EQUAL_CSTR(clist.get_front().c_str(), "first");
    ASSUME_ITS_EQUAL_CSTR(clist.get_back().c_str(), "last");
}

FOSSIL_TEST(cpp_test_clist_set_front_and_back) {
    CList clist("i32");
    clist.insert("one");
    clist.insert("two");
    clist.insert("three");
    clist.set_front("ONE");
    clist.set_back("THREE");
    ASSUME_ITS_EQUAL_CSTR(clist.get_front().c_str(), "ONE");
    ASSUME_ITS_EQUAL_CSTR(clist.get_back().c_str(), "THREE");
}

FOSSIL_TEST(cpp_test_clist_copy_and_move) {
    CList clist1("i32");
    clist1.insert("5");
    clist1.insert("10");
    clist1.insert("15");

    // Test copy constructor
    CList clist2(clist1); // copy
    ASSUME_ITS_EQUAL_SIZE(clist1.size(), clist2.size());
    ASSUME_ITS_EQUAL_CSTR(clist2.get(1).c_str(), "10");

    // Test move constructor
    CList clist3(std::move(clist1)); // move
    // The move constructor should transfer ownership, leaving clist1 empty.
    ASSUME_ITS_TRUE(clist1.is_empty()); // clist1 should be empty after move
    ASSUME_ITS_EQUAL_SIZE(clist3.size(), 3);
    ASSUME_ITS_EQUAL_CSTR(clist3.get(0).c_str(), "5");
    ASSUME_ITS_EQUAL_CSTR(clist3.get(1).c_str(), "10");
    ASSUME_ITS_EQUAL_CSTR(clist3.get(2).c_str(), "15");
}

FOSSIL_TEST(cpp_test_clist_empty_and_null_checks) {
    CList* clist = nullptr;
    ASSUME_ITS_TRUE(clist == nullptr);
    CList clist2("i32");
    ASSUME_ITS_TRUE(clist2.not_cnullptr());
    ASSUME_ITS_TRUE(clist2.is_empty());
    clist2.insert("42");
    ASSUME_ITS_TRUE(clist2.not_empty());
}

FOSSIL_TEST(cpp_test_clist_exception_on_create_invalid_type) {
    try {
        CList clist(""); // Empty type string, may be invalid
        ASSUME_ITS_TRUE(clist.not_cnullptr());
    } catch (const std::exception& e) {
        ASSUME_ITS_TRUE(true); // Exception thrown as expected
    }
}

FOSSIL_TEST(cpp_test_clist_exception_on_copy_null) {
    CList* clist_null = nullptr;
    try {
        CList clist_copy(*clist_null);
        ASSUME_ITS_TRUE(false); // Should not reach here
    } catch (const std::exception& e) {
        ASSUME_ITS_TRUE(true); // Exception thrown as expected
    }
}

FOSSIL_TEST(cpp_test_clist_get_out_of_range_throws) {
    CList clist("i32");
    clist.insert("A");
    try {
        clist.get(5); // Out of range
        ASSUME_ITS_TRUE(false); // Should not reach here
    } catch (const std::out_of_range& e) {
        ASSUME_ITS_TRUE(true); // Exception thrown as expected
    }
}

FOSSIL_TEST(cpp_test_clist_get_front_empty_throws) {
    CList clist("i32");
    try {
        clist.get_front();
        ASSUME_ITS_TRUE(false); // Should not reach here
    } catch (const std::runtime_error& e) {
        ASSUME_ITS_TRUE(true); // Exception thrown as expected
    }
}

FOSSIL_TEST(cpp_test_clist_get_back_empty_throws) {
    CList clist("i32");
    try {
        clist.get_back();
        ASSUME_ITS_TRUE(false); // Should not reach here
    } catch (const std::runtime_error& e) {
        ASSUME_ITS_TRUE(true); // Exception thrown as expected
    }
}

FOSSIL_TEST(cpp_test_clist_set_out_of_range_does_not_throw) {
    CList clist("i32");
    clist.insert("A");
    try {
        clist.set(5, "B"); // Out of range, should not throw
        ASSUME_ITS_EQUAL_CSTR(clist.get(0).c_str(), "A");
    } catch (...) {
        ASSUME_ITS_TRUE(false); // Should not throw
    }
}

FOSSIL_TEST(cpp_test_clist_set_front_and_back_empty_list) {
    CList clist("i32");
    try {
        clist.set_front("X"); // Should not throw
        clist.set_back("Y");  // Should not throw
        ASSUME_ITS_TRUE(clist.is_empty());
    } catch (...) {
        ASSUME_ITS_TRUE(false); // Should not throw
    }
}

FOSSIL_TEST(cpp_test_clist_multiple_reverse) {
    CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.insert("3");
    clist.reverse();
    clist.reverse();
    ASSUME_ITS_EQUAL_CSTR(clist.get_front().c_str(), "1");
    ASSUME_ITS_EQUAL_CSTR(clist.get_back().c_str(), "3");
}

FOSSIL_TEST(cpp_test_clist_large_insert_and_access) {
    CList clist("i32");
    for (int i = 0; i < 100; ++i) {
        clist.insert(std::to_string(i));
    }
    ASSUME_ITS_EQUAL_SIZE(clist.size(), 100);
    ASSUME_ITS_EQUAL_CSTR(clist.get(99).c_str(), "99");
    ASSUME_ITS_EQUAL_CSTR(clist.get_front().c_str(), "0");
    ASSUME_ITS_EQUAL_CSTR(clist.get_back().c_str(), "99");
}

FOSSIL_TEST(cpp_test_clist_remove_until_empty) {
    CList clist("i32");
    clist.insert("A");
    clist.insert("B");
    clist.insert("C");
    while (!clist.is_empty()) {
        clist.remove();
    }
    ASSUME_ITS_TRUE(clist.is_empty());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_clist_tofu_tests) {    
    // clist ToFu Fixture
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_create_and_destroy);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_create_default);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_insert_and_size);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_remove);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_reverse);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_get_and_set);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_get_front_and_back);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_set_front_and_back);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_copy_and_move);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_empty_and_null_checks);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_exception_on_create_invalid_type);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_exception_on_copy_null);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_get_out_of_range_throws);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_get_front_empty_throws);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_get_back_empty_throws);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_set_out_of_range_does_not_throw);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_set_front_and_back_empty_list);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_multiple_reverse);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_large_insert_and_access);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_remove_until_empty);

    // Register the test group
    FOSSIL_TEST_REGISTER(cpp_clist_tofu_fixture);
} // end of tests
