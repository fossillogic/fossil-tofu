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

FOSSIL_TEST_SUITE(cpp_cqueue_tofu_fixture);

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

FOSSIL_TEST_CASE(cpp_test_cqueue_insert) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_cqueue_insert(queue, const_cast<char *>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_cqueue_size(queue) == 1);
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_remove) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container(const_cast<char *>("i32"));
    fossil_cqueue_insert(queue, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_cqueue_remove(queue) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(queue) == true);
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_not_empty) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container(const_cast<char *>("i32"));
    fossil_cqueue_insert(queue, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_cqueue_not_empty(queue) == true);
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_not_cnullptr) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_cqueue_not_cnullptr(queue) == true);
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_is_empty) {
    fossil_cqueue_t* queue = fossil_cqueue_create_container(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(queue) == true);
    fossil_cqueue_insert(queue, const_cast<char *>("42"));
    ASSUME_ITS_TRUE(fossil_cqueue_is_empty(queue) == false);
    fossil_cqueue_destroy(queue);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_is_cnullptr) {
    fossil_cqueue_t* queue = nullptr;
    ASSUME_ITS_TRUE(fossil_cqueue_is_cnullptr(queue) == true);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_template_insert) {
    fossil::tofu::CQueue queue(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(queue.insert(const_cast<char *>("42")) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(queue.size() == 1);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_template_remove) {
    fossil::tofu::CQueue queue(const_cast<char *>("i32"));
    queue.insert(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(queue.remove() == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(queue.is_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_template_not_empty) {
    fossil::tofu::CQueue queue(const_cast<char *>("i32"));
    queue.insert(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(queue.not_empty() == true);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_template_is_empty) {
    fossil::tofu::CQueue queue(const_cast<char *>("i32"));
    ASSUME_ITS_TRUE(queue.is_empty() == true);
    queue.insert(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(queue.is_empty() == false);
}

FOSSIL_TEST_CASE(cpp_test_cqueue_template_get_front) {
    fossil::tofu::CQueue queue(const_cast<char *>("i32"));
    queue.insert(const_cast<char *>("42"));
    ASSUME_ITS_TRUE(std::string(queue.get_front()) == "42");
}

FOSSIL_TEST_CASE(cpp_test_cqueue_template_get_rear) {
    fossil::tofu::CQueue queue(const_cast<char *>("i32"));
    queue.insert(const_cast<char *>("42"));
    queue.insert(const_cast<char *>("84"));
    ASSUME_ITS_TRUE(std::string(queue.get_rear()) == "84");
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

    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_template_insert);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_template_remove);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_template_not_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_template_is_empty);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_template_get_front);
    FOSSIL_TEST_ADD(cpp_cqueue_tofu_fixture, cpp_test_cqueue_template_get_rear);

    FOSSIL_TEST_REGISTER(cpp_cqueue_tofu_fixture);
} // end of tests
