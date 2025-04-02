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

FOSSIL_TEST_SUITE(c_slist_tofu_fixture);

FOSSIL_SETUP(c_slist_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_slist_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_CASE(c_test_slist_insert) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    ASSUME_ITS_TRUE(fossil_slist_insert(slist, "hello") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_slist_size(slist) == 1);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_remove) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    fossil_slist_insert(slist, "hello");
    ASSUME_ITS_TRUE(fossil_slist_remove(slist, "hello") == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(fossil_slist_is_empty(slist) == true);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_find) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    fossil_slist_insert(slist, "world");
    ASSUME_ITS_TRUE(fossil_slist_find(slist, "world") == true);
    ASSUME_ITS_TRUE(fossil_slist_find(slist, "not_found") == false);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_size) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    ASSUME_ITS_TRUE(fossil_slist_size(slist) == 0);
    fossil_slist_insert(slist, "item1");
    fossil_slist_insert(slist, "item2");
    ASSUME_ITS_TRUE(fossil_slist_size(slist) == 2);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_not_empty) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    ASSUME_ITS_TRUE(fossil_slist_not_empty(slist) == false);
    fossil_slist_insert(slist, "data");
    ASSUME_ITS_TRUE(fossil_slist_not_empty(slist) == true);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_is_empty) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    ASSUME_ITS_TRUE(fossil_slist_is_empty(slist) == true);
    fossil_slist_insert(slist, "data");
    ASSUME_ITS_TRUE(fossil_slist_is_empty(slist) == false);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_multiple_inserts) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    fossil_slist_insert(slist, "item1");
    fossil_slist_insert(slist, "item2");
    fossil_slist_insert(slist, "item3");
    ASSUME_ITS_TRUE(fossil_slist_size(slist) == 3);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_multiple_removes) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    fossil_slist_insert(slist, "item1");
    fossil_slist_insert(slist, "item2");
    fossil_slist_insert(slist, "item3");
    fossil_slist_remove(slist, "item1");
    fossil_slist_remove(slist, "item2");
    ASSUME_ITS_TRUE(fossil_slist_size(slist) == 1);
    fossil_slist_destroy(slist);
}

FOSSIL_TEST_CASE(c_test_slist_create_copy) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    fossil_slist_insert(slist, "copy_test");
    fossil_slist_t* slist_copy = fossil_slist_create_copy(slist);
    ASSUME_ITS_TRUE(fossil_slist_size(slist_copy) == 1);
    ASSUME_ITS_TRUE(fossil_slist_find(slist_copy, "copy_test") == true);
    fossil_slist_destroy(slist);
    fossil_slist_destroy(slist_copy);
}

FOSSIL_TEST_CASE(c_test_slist_create_move) {
    fossil_slist_t* slist = fossil_slist_create_container("cstr", 16, 0.5f);
    fossil_slist_insert(slist, "move_test");
    fossil_slist_t* slist_moved = fossil_slist_create_move(slist);
    ASSUME_ITS_TRUE(fossil_slist_size(slist_moved) == 1);
    ASSUME_ITS_TRUE(fossil_slist_find(slist_moved, "move_test") == true);
    ASSUME_ITS_TRUE(slist->header == NULL); // Ensure the original list is empty
    fossil_slist_destroy(slist_moved);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_slist_tofu_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_insert);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_remove);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_find);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_size);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_not_empty);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_is_empty);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_multiple_inserts);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_multiple_removes);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_create_copy);
    FOSSIL_TEST_ADD(c_slist_tofu_fixture, c_test_slist_create_move);

    FOSSIL_TEST_REGISTER(c_slist_tofu_fixture);
} // end of tests
