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

// *****************************************************************************
// Circular Queue Test Cases
// *****************************************************************************

FOSSIL_TEST(cpp_test_cqueue_insert) {
    fossil_cqueue_t* cqueue = fossil_cqueue_create_container(const_cast<char*>("i32"), 5);
    ASSUME_ITS_TRUE(fossil_cqueue_insert(cqueue, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_cqueue_size(cqueue) == 1);
    fossil_cqueue_destroy(cqueue);
}

FOSSIL_TEST(cpp_test_cqueue_remove) {
    fossil_cqueue_t* cqueue = fossil_cqueue_create_container(const_cast<char*>("i32"), 5);
    fossil_cqueue_insert(cqueue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_cqueue_remove(cqueue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(cqueue) == true);
    fossil_cqueue_destroy(cqueue);
}

FOSSIL_TEST(cpp_test_cqueue_not_empty) {
    fossil_cqueue_t* cqueue = fossil_cqueue_create_container(const_cast<char*>("i32"), 5);
    fossil_cqueue_insert(cqueue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_cqueue_not_empty(cqueue) == true);
    fossil_cqueue_destroy(cqueue);
}

FOSSIL_TEST(cpp_test_cqueue_not_cnullptr) {
    fossil_cqueue_t* cqueue = fossil_cqueue_create_container(const_cast<char*>("i32"), 5);
    ASSUME_ITS_TRUE(fossil_cqueue_not_cnullptr(cqueue) == true);
    fossil_cqueue_destroy(cqueue);
}

FOSSIL_TEST(cpp_test_cqueue_is_empty) {
    fossil_cqueue_t* cqueue = fossil_cqueue_create_container(const_cast<char*>("i32"), 5);
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(cqueue) == true);
    fossil_cqueue_insert(cqueue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(cqueue) == false);
    fossil_cqueue_destroy(cqueue);
}

FOSSIL_TEST(cpp_test_cqueue_is_cnullptr) {
    fossil_cqueue_t* cqueue = NULL;
    ASSUME_ITS_TRUE(fossil_cqueue_is_cnullptr(cqueue) == true);
}

FOSSIL_TEST(cpp_test_cqueue_get_front_and_rear) {
    fossil_cqueue_t* cqueue = fossil_cqueue_create_container(const_cast<char*>("i32"), 5);
    fossil_cqueue_insert(cqueue, const_cast<char*>("1"));
    fossil_cqueue_insert(cqueue, const_cast<char*>("2"));
    fossil_cqueue_insert(cqueue, const_cast<char*>("3"));

    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_front(cqueue), "1");
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_rear(cqueue), "3");

    fossil_cqueue_destroy(cqueue);
}

FOSSIL_TEST(cpp_test_cqueue_set_front_and_rear) {
    fossil_cqueue_t* cqueue = fossil_cqueue_create_container(const_cast<char*>("i32"), 5);
    fossil_cqueue_insert(cqueue, const_cast<char*>("1"));
    fossil_cqueue_insert(cqueue, const_cast<char*>("2"));
    fossil_cqueue_insert(cqueue, const_cast<char*>("3"));

    fossil_cqueue_set_front(cqueue, const_cast<char*>("42"));
    fossil_cqueue_set_rear(cqueue, const_cast<char*>("99"));

    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_front(cqueue), "42");
    ASSUME_ITS_EQUAL_CSTR(fossil_cqueue_get_rear(cqueue), "99");

    fossil_cqueue_destroy(cqueue);
}

FOSSIL_TEST(cpp_test_cqueue_class_insert) {
    fossil::tofu::CQueue cqueue(const_cast<char*>("i32"), 5);
    ASSUME_ITS_TRUE(cqueue.insert(const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(cqueue.size() == 1);
}

FOSSIL_TEST(cpp_test_cqueue_class_remove) {
    fossil::tofu::CQueue cqueue(const_cast<char*>("i32"), 5);
    cqueue.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(cqueue.remove() == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(cqueue.is_empty() == true);
}

FOSSIL_TEST(cpp_test_cqueue_class_not_empty) {
    fossil::tofu::CQueue cqueue(const_cast<char*>("i32"), 5);
    cqueue.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(cqueue.not_empty() == true);
}

FOSSIL_TEST(cpp_test_cqueue_class_not_cnullptr) {
    fossil::tofu::CQueue cqueue(const_cast<char*>("i32"), 5);
    ASSUME_ITS_TRUE(cqueue.not_cnullptr() == true);
}

FOSSIL_TEST(cpp_test_cqueue_class_is_empty) {
    fossil::tofu::CQueue cqueue(const_cast<char*>("i32"), 5);
    ASSUME_ITS_TRUE(cqueue.is_empty() == true);
    cqueue.insert(const_cast<char*>("42"));
    ASSUME_ITS_TRUE(cqueue.is_empty() == false);
}

FOSSIL_TEST(cpp_test_cqueue_class_get_front_and_rear) {
    fossil::tofu::CQueue cqueue(const_cast<char*>("i32"), 5);
    cqueue.insert(const_cast<char*>("1"));
    cqueue.insert(const_cast<char*>("2"));
    cqueue.insert(const_cast<char*>("3"));

    ASSUME_ITS_EQUAL_CSTR(cqueue.get_front(), "1");
    ASSUME_ITS_EQUAL_CSTR(cqueue.get_rear(), "3");
}

FOSSIL_TEST(cpp_test_cqueue_class_set_front_and_rear) {
    fossil::tofu::CQueue cqueue(const_cast<char*>("i32"), 5);
    cqueue.insert(const_cast<char*>("1"));
    cqueue.insert(const_cast<char*>("2"));
    cqueue.insert(const_cast<char*>("3"));

    cqueue.set_front(const_cast<char*>("42"));
    cqueue.set_rear(const_cast<char*>("99"));

    ASSUME_ITS_EQUAL_CSTR(cqueue.get_front(), "42");
    ASSUME_ITS_EQUAL_CSTR(cqueue.get_rear(), "99");
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_cqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_insert);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_remove);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_not_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_is_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_get_front_and_rear);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_set_front_and_rear);

    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_class_insert);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_class_remove);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_class_not_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_class_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_class_is_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_class_get_front_and_rear);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_class_set_front_and_rear);

    FOSSIL_TEST_REGISTER(cpp_cqueue_tofu_fixture);
} // end of tests
