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
#include <fossil/test/framework.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_SUITE(cpp_clist_tofu_fixture);

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

FOSSIL_TEST_CASE(cpp_test_clist_insert) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 1);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_remove) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    fossil_clist_insert(clist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_clist_remove(clist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist) == true);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_not_empty) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    fossil_clist_insert(clist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_clist_not_empty(clist) == true);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_not_cnullptr) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_clist_not_cnullptr(clist) == true);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_is_empty) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist) == true);
    fossil_clist_insert(clist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_clist_is_empty(clist) == false);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_is_cnullptr) {
    fossil_clist_t* clist = nullptr;
    ASSUME_ITS_TRUE(fossil_clist_is_cnullptr(clist) == true);
}

FOSSIL_TEST_CASE(cpp_test_clist_reverse) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    fossil_clist_insert(clist, const_cast<char*>("1"));
    fossil_clist_insert(clist, const_cast<char*>("2"));
    fossil_clist_insert(clist, const_cast<char*>("3"));
    fossil_clist_reverse(clist);

    ASSUME_ITS_EQUAL_I32(fossil_clist_size(clist), 3);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_size) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    fossil_clist_insert(clist, const_cast<char*>("1"));
    fossil_clist_insert(clist, const_cast<char*>("2"));
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 2);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_insert_multiple) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, const_cast<char*>("1")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, const_cast<char*>("2")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_insert(clist, const_cast<char*>("3")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 3);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_remove_multiple) {
    fossil_clist_t* clist = fossil_clist_create_container(const_cast<char*>("i32"));
    fossil_clist_insert(clist, const_cast<char*>("1"));
    fossil_clist_insert(clist, const_cast<char*>("2"));
    fossil_clist_insert(clist, const_cast<char*>("3"));
    ASSUME_ITS_TRUE(fossil_clist_remove(clist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_remove(clist) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_clist_size(clist) == 1);
    fossil_clist_destroy(clist);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_insert) {
    fossil::tofu::CList clist("i32");
    ASSUME_ITS_TRUE(clist.insert("42") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(clist.size() == 1);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_remove) {
    fossil::tofu::CList clist("i32");
    clist.insert("42");
    ASSUME_ITS_TRUE(clist.remove() == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(clist.is_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_not_empty) {
    fossil::tofu::CList clist("i32");
    clist.insert("42");
    ASSUME_ITS_TRUE(clist.not_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_not_cnullptr) {
    fossil::tofu::CList clist("i32");
    ASSUME_ITS_TRUE(clist.not_cnullptr() == true);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_is_empty) {
    fossil::tofu::CList clist("i32");
    ASSUME_ITS_TRUE(clist.is_empty() == true);
    clist.insert("42");
    ASSUME_ITS_TRUE(clist.is_empty() == false);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_is_cnullptr) {
    fossil::tofu::CList clist;
    ASSUME_ITS_TRUE(clist.is_cnullptr() == false);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_reverse) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.insert("3");
    clist.reverse();
    ASSUME_ITS_EQUAL_I32(clist.size(), 3);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_size) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    ASSUME_ITS_TRUE(clist.size() == 2);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_insert_multiple) {
    fossil::tofu::CList clist("i32");
    ASSUME_ITS_TRUE(clist.insert("1") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(clist.insert("2") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(clist.insert("3") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(clist.size() == 3);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_remove_multiple) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.insert("3");
    ASSUME_ITS_TRUE(clist.remove() == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(clist.remove() == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(clist.size() == 1);
}

FOSSIL_TEST_CASE(cpp_test_clist_class_get) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.insert("3");
    ASSUME_ITS_TRUE(clist.get(1) == "2");
}

FOSSIL_TEST_CASE(cpp_test_clist_class_get_front) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    ASSUME_ITS_TRUE(clist.get_front() == "1");
}

FOSSIL_TEST_CASE(cpp_test_clist_class_get_back) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    ASSUME_ITS_TRUE(clist.get_back() == "2");
}

FOSSIL_TEST_CASE(cpp_test_clist_class_set) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.set(1, "42");
    ASSUME_ITS_TRUE(clist.get(1) == "42");
}

FOSSIL_TEST_CASE(cpp_test_clist_class_set_front) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.set_front("42");
    ASSUME_ITS_TRUE(clist.get_front() == "42");
}

FOSSIL_TEST_CASE(cpp_test_clist_class_set_back) {
    fossil::tofu::CList clist("i32");
    clist.insert("1");
    clist.insert("2");
    clist.set_back("42");
    ASSUME_ITS_TRUE(clist.get_back() == "42");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_clist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_insert);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_remove);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_not_empty);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_not_cnullptr);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_is_empty);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_is_cnullptr);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_reverse);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_size);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_insert_multiple);
    FOSSIL_TEST_ADD(c_clist_tofu_fixture, c_test_clist_remove_multiple);

    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_insert);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_remove);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_not_empty);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_is_empty);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_reverse);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_size);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_insert_multiple);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_remove_multiple);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_get);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_get_front);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_get_back);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_set);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_set_front);
    FOSSIL_TEST_ADD(cpp_clist_tofu_fixture, cpp_test_clist_class_set_back);

    FOSSIL_TEST_REGISTER(cpp_clist_tofu_fixture);
} // end of tests
