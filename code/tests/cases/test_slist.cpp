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

FOSSIL_SUITE(cpp_slist_tofu_fixture);

FOSSIL_SETUP(cpp_slist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_slist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_test_slist_create_container) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(slist != nullptr);
    ASSUME_ITS_TRUE(strcmp(slist->type, const_cast<char*>("i32")) == 0);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_create_default) {
    fossil_slist_t* slist = fossil_slist_create_default();
    ASSUME_ITS_TRUE(slist != nullptr);
    ASSUME_ITS_TRUE(strcmp(slist->type, const_cast<char*>("any")) == 0);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_create_copy) {
    fossil_slist_t* slist1 = fossil_slist_create_container(const_cast<char*>("i32"));
    fossil_slist_insert(slist1, const_cast<char*>("42"));
    fossil_slist_t* slist2 = fossil_slist_create_copy(slist1);
    ASSUME_ITS_TRUE(slist2 != nullptr);
    ASSUME_ITS_TRUE(strcmp(slist2->type, const_cast<char*>("i32")) == 0);
    ASSUME_ITS_TRUE(fossil_slist_size(slist2) == 1);
    fossil_slist_destroy(slist1);
    fossil_slist_destroy(slist2);
}

FOSSIL_TEST(cpp_test_slist_create_move) {
    fossil_slist_t* slist1 = fossil_slist_create_container(const_cast<char*>("i32"));
    fossil_slist_insert(slist1, const_cast<char*>("42"));
    fossil_slist_t* slist2 = fossil_slist_create_move(slist1);
    ASSUME_ITS_TRUE(slist2 != nullptr);
    ASSUME_ITS_TRUE(strcmp(slist2->type, const_cast<char*>("i32")) == 0);
    ASSUME_ITS_TRUE(fossil_slist_size(slist2) == 1);
    fossil_slist_destroy(slist2);
}

FOSSIL_TEST(cpp_test_slist_insert) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_slist_insert(slist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_slist_size(slist) == 1);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_remove) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    fossil_slist_insert(slist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_slist_remove(slist, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_slist_is_empty(slist) == true);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_not_empty) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    fossil_slist_insert(slist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_slist_not_empty(slist) == true);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_not_cnullptr) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_slist_not_cnullptr(slist) == true);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_is_empty) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_slist_is_empty(slist) == true);
    fossil_slist_insert(slist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_slist_is_empty(slist) == false);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_is_cnullptr) {
    fossil_slist_t* slist = nullptr;
    ASSUME_ITS_TRUE(fossil_slist_is_cnullptr(slist) == true);
}

FOSSIL_TEST(cpp_test_slist_search) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    fossil_slist_insert(slist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(strcmp(fossil_slist_search(slist, const_cast<char*>("42")), const_cast<char*>("42")) == 0);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_get_front) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    fossil_slist_insert(slist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(strcmp(fossil_slist_get_front(slist), const_cast<char*>("42")) == 0);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_get_back) {
    fossil_slist_t* slist = fossil_slist_create_container(const_cast<char*>("i32"));
    fossil_slist_insert(slist, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(strcmp(fossil_slist_get_back(slist), const_cast<char*>("42")) == 0);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST(cpp_test_slist_class_create_with_type) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(slist.not_cnullptr());
}

FOSSIL_TEST(cpp_test_slist_class_create_default) {
    fossil::tofu::SList slist;
    ASSUME_ITS_TRUE(slist.not_cnullptr());
    ASSUME_ITS_TRUE(slist.is_empty());
}

FOSSIL_TEST(cpp_test_slist_class_insert) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(slist.insert(const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(slist.size() == 1);
    ASSUME_ITS_TRUE(strcmp(slist.get_front(), const_cast<char*>("42")) == 0);
}

FOSSIL_TEST(cpp_test_slist_class_remove) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    slist.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(slist.remove(const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(slist.is_empty());
}

FOSSIL_TEST(cpp_test_slist_class_search) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    slist.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(strcmp(slist.search(const_cast<char*>("42")), const_cast<char*>("42")) == 0);
    ASSUME_ITS_TRUE(slist.search(const_cast<char*>("nonexistent")) == nullptr);
}

FOSSIL_TEST(cpp_test_slist_class_get_front_and_back) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    slist.insert(const_cast<char*>("42"));
    slist.insert(const_cast<char*>("84"));
    ASSUME_ITS_TRUE(strcmp(slist.get_front(), const_cast<char*>("42")) == 0);
    ASSUME_ITS_TRUE(strcmp(slist.get_back(), const_cast<char*>("84")) == 0);
}

FOSSIL_TEST(cpp_test_slist_class_is_empty) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(slist.is_empty());
    slist.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(!slist.is_empty());
}

FOSSIL_TEST(cpp_test_slist_class_not_empty) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    slist.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(slist.not_empty());
}

FOSSIL_TEST(cpp_test_slist_class_size) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(slist.size() == 0);
    slist.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(slist.size() == 1);
    slist.insert(const_cast<char*>("84"));
    ASSUME_ITS_TRUE(slist.size() == 2);
}

FOSSIL_TEST(cpp_test_slist_class_not_cnullptr) {
    fossil::tofu::SList slist(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(slist.not_cnullptr());
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_slist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_create_container);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_create_default);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_create_copy);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_create_move);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_insert);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_remove);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_not_empty);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_is_empty);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_search);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_get_front);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_get_back);

    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_create_with_type);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_create_default);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_insert);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_remove);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_search);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_get_front_and_back);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_is_empty);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_not_empty);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_size);
    FOSSIL_TEST_ADD(cpp_slist_tofu_fixture, cpp_test_slist_class_not_cnullptr);

    FOSSIL_TEST_REGISTER(cpp_slist_tofu_fixture);
} // end of tests
