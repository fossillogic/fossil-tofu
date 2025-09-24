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

FOSSIL_SUITE(c_trie_tofu_fixture);

FOSSIL_SETUP(c_trie_tofu_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(c_trie_tofu_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(c_test_trie_create_and_destroy) {
    fossil_trie_t* trie = fossil_trie_create("cstr");
    ASSUME_NOT_CNULL(trie);
    ASSUME_ITS_EQUAL_CSTR(trie->value_type, "cstr");
    ASSUME_ITS_TRUE(fossil_trie_is_empty(trie));
    fossil_trie_destroy(trie);
}

FOSSIL_TEST(c_test_trie_create_default) {
    fossil_trie_t* trie = fossil_trie_create_default();
    ASSUME_NOT_CNULL(trie);
    fossil_trie_destroy(trie);
}

FOSSIL_TEST(c_test_trie_insert_and_get) {
    fossil_trie_t* trie = fossil_trie_create("cstr");
    ASSUME_ITS_EQUAL_I32(fossil_trie_insert(trie, "apple", "fruit"), FOSSIL_TOFU_SUCCESS);
    fossil_tofu_t v = fossil_trie_get(trie, "apple");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&v), "fruit");
    fossil_trie_destroy(trie);
}

FOSSIL_TEST(c_test_trie_insert_multiple_and_size) {
    fossil_trie_t* trie = fossil_trie_create("cstr");
    fossil_trie_insert(trie, "cat", "animal");
    fossil_trie_insert(trie, "car", "vehicle");
    fossil_trie_insert(trie, "cart", "object");
    ASSUME_ITS_EQUAL_SIZE(fossil_trie_size(trie), 3);
    fossil_trie_destroy(trie);
}

FOSSIL_TEST(c_test_trie_remove) {
    fossil_trie_t* trie = fossil_trie_create("cstr");
    fossil_trie_insert(trie, "dog", "animal");
    ASSUME_ITS_EQUAL_I32(fossil_trie_remove(trie, "dog"), FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_FALSE(fossil_trie_contains(trie, "dog"));
    fossil_trie_destroy(trie);
}

FOSSIL_TEST(c_test_trie_contains) {
    fossil_trie_t* trie = fossil_trie_create("cstr");
    fossil_trie_insert(trie, "key", "value");
    ASSUME_ITS_TRUE(fossil_trie_contains(trie, "key"));
    ASSUME_ITS_FALSE(fossil_trie_contains(trie, "notfound"));
    fossil_trie_destroy(trie);
}

FOSSIL_TEST(c_test_trie_copy_and_move) {
    fossil_trie_t* trie1 = fossil_trie_create("cstr");
    fossil_trie_insert(trie1, "one", "1");
    fossil_trie_insert(trie1, "two", "2");
    fossil_trie_t* trie2 = fossil_trie_create_copy(trie1);
    ASSUME_ITS_EQUAL_SIZE(fossil_trie_size(trie2), 2);
    fossil_tofu_t v = fossil_trie_get(trie2, "two");
    ASSUME_ITS_EQUAL_CSTR(fossil_tofu_get_value(&v), "2");
    fossil_trie_t* trie3 = fossil_trie_create_move(trie1);
    ASSUME_ITS_TRUE(fossil_trie_is_empty(trie1));
    ASSUME_ITS_EQUAL_SIZE(fossil_trie_size(trie3), 2);
    fossil_trie_destroy(trie2);
    fossil_trie_destroy(trie3);
    fossil_trie_destroy(trie1);
}

FOSSIL_TEST(c_test_trie_clear) {
    fossil_trie_t* trie = fossil_trie_create("cstr");
    fossil_trie_insert(trie, "foo", "bar");
    fossil_trie_insert(trie, "baz", "qux");
    fossil_trie_clear(trie);
    ASSUME_ITS_TRUE(fossil_trie_is_empty(trie));
    fossil_trie_destroy(trie);
}

FOSSIL_TEST(c_test_trie_get_keys_with_prefix) {
    fossil_trie_t* trie = fossil_trie_create("cstr");
    fossil_trie_insert(trie, "star", "A");
    fossil_trie_insert(trie, "start", "B");
    fossil_trie_insert(trie, "stark", "C");
    fossil_trie_insert(trie, "stack", "D");
    char** keys = NULL;
    size_t count = 0;
    int32_t res = fossil_trie_get_keys_with_prefix(trie, "sta", &keys, &count);
    ASSUME_ITS_EQUAL_I32(res, FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_TRUE(count >= 3);
    for (size_t i = 0; i < count; ++i) free(keys[i]);
    free(keys);
    fossil_trie_destroy(trie);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_trie_tofu_tests) {    
    // trie ToFu Fixture
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_create_and_destroy);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_create_default);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_insert_and_get);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_insert_multiple_and_size);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_remove);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_contains);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_copy_and_move);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_clear);
    FOSSIL_TEST_ADD(c_trie_tofu_fixture, c_test_trie_get_keys_with_prefix);

    // Register the test group
    FOSSIL_TEST_REGISTER(c_trie_tofu_fixture);
} // end of tests
