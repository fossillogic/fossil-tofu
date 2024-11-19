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

FOSSIL_TEST_SUITE(cpp_pqueue_tofu_fixture);

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

FOSSIL_TEST_CASE(cpp_test_pqueue_insert) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_pqueue_insert(pqueue, const_cast<char *>("42"), 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_size(pqueue) == 1);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_remove) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char *>("i32"));
    fossil_pqueue_insert(pqueue, const_cast<char *>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_remove(pqueue, 0) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_not_empty) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char *>("i32"));
    fossil_pqueue_insert(pqueue, const_cast<char *>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_not_empty(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_not_cnullptr) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_pqueue_not_cnullptr(pqueue) == true);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_is_empty) {
    fossil_pqueue_t* pqueue = fossil_pqueue_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == true);
    fossil_pqueue_insert(pqueue, const_cast<char *>("42"), 0);
    ASSUME_ITS_TRUE(fossil_pqueue_is_empty(pqueue) == false);
    fossil_pqueue_destroy(pqueue);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_is_cnullptr) {
    fossil_pqueue_t* pqueue = nullptr;
    ASSUME_ITS_TRUE(fossil_pqueue_is_cnullptr(pqueue) == true);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_get_front) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    ASSUME_ITS_TRUE(pqueue.get_front() == 42);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_get_back) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    pqueue.insert(84, 1);
    ASSUME_ITS_TRUE(pqueue.get_back() == 84);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_get_at) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    pqueue.insert(84, 1);
    ASSUME_ITS_TRUE(pqueue.get_at(1) == 84);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_set_front) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    pqueue.set_front(84);
    ASSUME_ITS_TRUE(pqueue.get_front() == 84);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_set_back) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    pqueue.insert(84, 1);
    pqueue.set_back(126);
    ASSUME_ITS_TRUE(pqueue.get_back() == 126);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_set_at) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    pqueue.insert(84, 1);
    pqueue.set_at(1, 126);
    ASSUME_ITS_TRUE(pqueue.get_at(1) == 126);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_copy_constructor) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    fossil::PQueue<int> pqueue_copy(pqueue);
    ASSUME_ITS_TRUE(pqueue_copy.get_front() == 42);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_move_constructor) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    fossil::PQueue<int> pqueue_moved(std::move(pqueue));
    ASSUME_ITS_TRUE(pqueue_moved.get_front() == 42);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_assignment_operator) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    fossil::PQueue<int> pqueue_assigned;
    pqueue_assigned = pqueue;
    ASSUME_ITS_TRUE(pqueue_assigned.get_front() == 42);
}

FOSSIL_TEST_CASE(cpp_test_pqueue_move_assignment_operator) {
    fossil::PQueue<int> pqueue;
    pqueue.insert(42, 0);
    fossil::PQueue<int> pqueue_moved;
    pqueue_moved = std::move(pqueue);
    ASSUME_ITS_TRUE(pqueue_moved.get_front() == 42);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_pqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_insert);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_remove);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_empty);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_is_empty);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_get_front);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_get_back);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_get_at);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_set_front);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_set_back);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_set_at);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_copy_constructor);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_move_constructor);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_assignment_operator);
    FOSSIL_TEST_ADD(cpp_pqueue_tofu_fixture, cpp_test_pqueue_move_assignment_operator);

    FOSSIL_TEST_REGISTER(cpp_pqueue_tofu_fixture);
} // end of tests
