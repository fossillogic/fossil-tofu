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
#include <fossil/unittest/framework.h>
#include <fossil/xassume.h>

#include "fossil/tofu/framework.h"

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder for implementation

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_fossil_tofu_mapof_create) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    ASSUME_ITS_EQUAL_I32(0, fossil_tofu_mapof_size(&map));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_add_and_get) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    fossil_tofu_t retrieved = fossil_tofu_mapof_get(&map, key);
    ASSUME_ITS_EQUAL_I32(100, retrieved.value.int_val);
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_contains) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    ASSUME_ITS_TRUE(fossil_tofu_mapof_contains(&map, key));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_remove) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    fossil_tofu_mapof_remove(&map, key);
    ASSUME_ITS_FALSE(fossil_tofu_mapof_contains(&map, key));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_size) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key1 = fossil_tofu_create("int", "1");
    fossil_tofu_t value1 = fossil_tofu_create("int", "100");
    fossil_tofu_t key2 = fossil_tofu_create("int", "2");
    fossil_tofu_t value2 = fossil_tofu_create("int", "200");
    fossil_tofu_mapof_add(&map, key1, value1);
    fossil_tofu_mapof_add(&map, key2, value2);
    ASSUME_ITS_EQUAL_I32(2, fossil_tofu_mapof_size(&map));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_is_empty) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    ASSUME_ITS_TRUE(fossil_tofu_mapof_is_empty(&map));
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    ASSUME_ITS_FALSE(fossil_tofu_mapof_is_empty(&map));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_clear) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    fossil_tofu_mapof_clear(&map);
    ASSUME_ITS_EQUAL_I32(0, fossil_tofu_mapof_size(&map));
    ASSUME_ITS_TRUE(fossil_tofu_mapof_is_empty(&map));
    fossil_tofu_mapof_erase(&map);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(c_mapof_structure_tests) {    
    // Generic ToFu MapOf Fixture
    ADD_TEST(test_fossil_tofu_mapof_create);
    ADD_TEST(test_fossil_tofu_mapof_add_and_get);
    ADD_TEST(test_fossil_tofu_mapof_contains);
    ADD_TEST(test_fossil_tofu_mapof_remove);
    ADD_TEST(test_fossil_tofu_mapof_size);
    ADD_TEST(test_fossil_tofu_mapof_is_empty);
    ADD_TEST(test_fossil_tofu_mapof_clear);
} // end of tests
