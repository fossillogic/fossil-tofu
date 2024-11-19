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

FOSSIL_TEST_SUITE(cpp_dqueue_tofu_fixture);

FOSSIL_SETUP(cpp_dqueue_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_dqueue_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(cpp_test_dqueue_insert) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_remove) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    fossil_dqueue_insert(queue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_not_empty) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    fossil_dqueue_insert(queue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_dqueue_not_empty(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_not_cnullptr) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_not_cnullptr(queue) == true);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_is_empty) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == true);
    fossil_dqueue_insert(queue, const_cast<char*>("42"));
    ASSUME_ITS_TRUE(fossil_dqueue_is_empty(queue) == false);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_is_cnullptr) {
    fossil_dqueue_t* queue = nullptr;
    ASSUME_ITS_TRUE(fossil_dqueue_is_cnullptr(queue) == true);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_multiple_insert) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, const_cast<char*>("43")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 2);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_insert_remove) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, const_cast<char*>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, const_cast<char*>("43")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_insert_null) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_insert(queue, nullptr) == FOSSIL_TOFU_FAILURE);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 0);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_remove_empty) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_remove(queue) == FOSSIL_TOFU_FAILURE);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_size_empty) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 0);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_size_after_operations) {
    fossil_dqueue_t* queue = fossil_dqueue_create_container(const_cast<char*>("i32"));
    fossil_dqueue_insert(queue, const_cast<char*>("42"));
    fossil_dqueue_insert(queue, const_cast<char*>("43"));
    fossil_dqueue_remove(queue);
    ASSUME_ITS_TRUE(fossil_dqueue_size(queue) == 1);
    fossil_dqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_insert) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    ASSUME_ITS_TRUE(queue.getSize() == 1);
    ASSUME_ITS_TRUE(queue.getFront() == 42);
    ASSUME_ITS_TRUE(queue.getBack() == 42);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_remove) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    queue.remove();
    ASSUME_ITS_TRUE(queue.isEmpty() == true);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_multiple_insert) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    queue.insert(43);
    ASSUME_ITS_TRUE(queue.getSize() == 2);
    ASSUME_ITS_TRUE(queue.getFront() == 42);
    ASSUME_ITS_TRUE(queue.getBack() == 43);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_insert_remove) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    queue.insert(43);
    queue.remove();
    ASSUME_ITS_TRUE(queue.getSize() == 1);
    ASSUME_ITS_TRUE(queue.getFront() == 43);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_get) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    queue.insert(43);
    ASSUME_ITS_TRUE(queue.get(0) == 42);
    ASSUME_ITS_TRUE(queue.get(1) == 43);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_set) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    queue.insert(43);
    queue.set(0, 44);
    ASSUME_ITS_TRUE(queue.get(0) == 44);
    ASSUME_ITS_TRUE(queue.get(1) == 43);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_setFront) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    queue.setFront(44);
    ASSUME_ITS_TRUE(queue.getFront() == 44);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_setBack) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    queue.setBack(44);
    ASSUME_ITS_TRUE(queue.getBack() == 44);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_isEmpty) {
    fossil::DQueue<int> queue;
    ASSUME_ITS_TRUE(queue.isEmpty() == true);
    queue.insert(42);
    ASSUME_ITS_TRUE(queue.isEmpty() == false);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_getSize) {
    fossil::DQueue<int> queue;
    ASSUME_ITS_TRUE(queue.getSize() == 0);
    queue.insert(42);
    ASSUME_ITS_TRUE(queue.getSize() == 1);
    queue.insert(43);
    ASSUME_ITS_TRUE(queue.getSize() == 2);
    queue.remove();
    ASSUME_ITS_TRUE(queue.getSize() == 1);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_getFront) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    ASSUME_ITS_TRUE(queue.getFront() == 42);
}

FOSSIL_TEST_CASE(cpp_test_dqueue_template_getBack) {
    fossil::DQueue<int> queue;
    queue.insert(42);
    ASSUME_ITS_TRUE(queue.getBack() == 42);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_dqueue_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_insert);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_remove);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_not_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_not_cnullptr);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_is_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_is_cnullptr);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_multiple_insert);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_insert_remove);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_insert_null);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_remove_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_size_empty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_size_after_operations);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_insert);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_remove);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_multiple_insert);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_insert_remove);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_get);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_set);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_setFront);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_setBack);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_isEmpty);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_getSize);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_getFront);
    FOSSIL_TEST_ADD(cpp_dqueue_tofu_fixture, cpp_test_dqueue_template_getBack);

    FOSSIL_TEST_REGISTER(cpp_dqueue_tofu_fixture);
} // end of tests
