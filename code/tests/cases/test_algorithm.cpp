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

// Define the fossil_tofu_sum function
void* fossil_tofu_sum(const fossil_tofu_t* array, size_t size) {
    // Implement the sum logic here based on the type of data
    // Example: Summing integers
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += static_cast<int>(atoi(array[i].value.data)); // Assuming value.data is a string representation of the number
    }
    char* result = static_cast<char*>(malloc(20)); // Allocate memory for the result
    snprintf(result, 20, "%d", sum); // Convert sum to string
    return result;
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_SUITE(cpp_algorithm_fixture);

FOSSIL_SETUP(cpp_algorithm_fixture) {
    // Setup the test fixture
}

FOSSIL_TEARDOWN(cpp_algorithm_fixture) {
    // Teardown the test fixture
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(cpp_test_algorithm_compare_i8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_i16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_i32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_i64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_u8) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_u16) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_u32) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_u64) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_hex) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x2A"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x54"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_octal) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("052"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("124"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_float) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("42.0"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_double) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("42.0"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("84.0"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_wstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("alpha"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("beta"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_cstr) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("alpha"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_bool) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("1"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_size) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_compare_any) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_search_i8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_i16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_i64) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_u8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_u16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_u32) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_hex) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x2A")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x54")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x7E"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x54"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_octal) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("052")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0124")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0176"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0124"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_float) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("126.0"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_double) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("84.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("126.0"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("84.0"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_wstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("beta")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("gamma"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("beta"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_cstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("gamma"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_bool) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("1")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("1"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_size) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_search_any) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil_algorithm_search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_sort_i8_ascending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_i8_descending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

// Repeat similar test cases for other types
FOSSIL_TEST(cpp_test_algorithm_sort_i16_ascending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_i16_descending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_i32_ascending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_i32_descending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_u64_ascending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_u64_descending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("84"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_float_ascending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("126.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42.0");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84.0");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126.0");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_float_descending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("126.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126.0");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84.0");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42.0");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_cstr_ascending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("gamma")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "alpha");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "beta");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "gamma");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_sort_cstr_descending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("gamma")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta"))
    };

    ASSUME_ITS_TRUE(fossil_algorithm_sort(array, 3, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "gamma");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "beta");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "alpha");

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_i8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_i16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_i64) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_u8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_u16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_u32) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_u64) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_hex) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x2A")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x54")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x7E"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("0x7E"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("0x54"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("0x2A"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_octal) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("052")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0124")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0176"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("0176"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("0124"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("052"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_float) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("126.0"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126.0"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84.0"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42.0"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_double) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("84.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("126.0"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126.0"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84.0"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42.0"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_wstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("beta")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("gamma"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("gamma"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("beta"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("alpha"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_cstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("gamma"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("gamma"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("beta"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("alpha"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_bool) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("1")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("0"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("1"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("0"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_size) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_reverse_any) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("any"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil_algorithm_reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, const_cast<char*>("126"));
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, const_cast<char*>("84"));
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, const_cast<char*>("42"));
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_i8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_i16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_i32) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_i64) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_u8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_u16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_u32) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_u64) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_hex) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x7E")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x2A")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x54"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("0x2A"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_octal) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0176")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("052")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0124"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("052"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_float) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("126.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42.0"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_double) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("126.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("84.0"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42.0"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_wstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("gamma")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("beta"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("alpha"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_cstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("gamma")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("alpha"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_bool) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("1")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("1"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("0"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_min_size) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("84"))
    };

    fossil_tofu_t *min = fossil_algorithm_min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, const_cast<char*>("42"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_i8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_i16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i16"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_i32) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i32"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_i64) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i64"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_u8) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u8"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_u16) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u16"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_u32) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u32"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_u64) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("u64"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_hex) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x2A")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x54")),
        fossil_tofu_create(const_cast<char*>("hex"), const_cast<char*>("0x7E"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("0x7E"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_octal) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("052")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0124")),
        fossil_tofu_create(const_cast<char*>("octal"), const_cast<char*>("0176"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("0176"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_float) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("84.0")),
        fossil_tofu_create(const_cast<char*>("float"), const_cast<char*>("126.0"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126.0"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_double) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("42.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("84.0")),
        fossil_tofu_create(const_cast<char*>("double"), const_cast<char*>("126.0"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126.0"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_wstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("beta")),
        fossil_tofu_create(const_cast<char*>("wstr"), const_cast<char*>("gamma"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("gamma"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_cstr) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("alpha")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("beta")),
        fossil_tofu_create(const_cast<char*>("cstr"), const_cast<char*>("gamma"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("gamma"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_bool) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("1")),
        fossil_tofu_create(const_cast<char*>("bool"), const_cast<char*>("0"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("1"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_max_size) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("size"), const_cast<char*>("126"))
    };

    fossil_tofu_t *max = fossil_algorithm_max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, const_cast<char*>("126"));

    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_class_compare) {
    fossil_tofu_t tofu1 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42"));
    fossil_tofu_t tofu2 = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil::tofu::Algorithm::compare(&tofu1, &tofu2) < 0);
    fossil_tofu_destroy(&tofu1);
    fossil_tofu_destroy(&tofu2);
}

FOSSIL_TEST(cpp_test_algorithm_class_search) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126"))
    };
    fossil_tofu_t tofu = fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"));
    ASSUME_ITS_TRUE(fossil::tofu::Algorithm::search(array, 3, &tofu) == 1);
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
    fossil_tofu_destroy(&tofu);
}

FOSSIL_TEST(cpp_test_algorithm_class_sort_ascending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"))
    };
    ASSUME_ITS_TRUE(fossil::tofu::Algorithm::sort(array, 3, true) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "42");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "126");
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_class_sort_descending) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"))
    };
    ASSUME_ITS_TRUE(fossil::tofu::Algorithm::sort(array, 3, false) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_class_reverse) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126"))
    };
    ASSUME_ITS_TRUE(fossil::tofu::Algorithm::reverse(array, 3) == FOSSIL_TOFU_SUCCESS);
    ASSUME_ITS_EQUAL_CSTR(array[0].value.data, "126");
    ASSUME_ITS_EQUAL_CSTR(array[1].value.data, "84");
    ASSUME_ITS_EQUAL_CSTR(array[2].value.data, "42");
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_class_min) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84"))
    };
    fossil_tofu_t* min = fossil::tofu::Algorithm::min(array, 3);
    ASSUME_ITS_EQUAL_CSTR(min->value.data, "42");
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

FOSSIL_TEST(cpp_test_algorithm_class_max) {
    fossil_tofu_t array[3] = {
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("42")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("84")),
        fossil_tofu_create(const_cast<char*>("i8"), const_cast<char*>("126"))
    };
    fossil_tofu_t* max = fossil::tofu::Algorithm::max(array, 3);
    ASSUME_ITS_EQUAL_CSTR(max->value.data, "126");
    for (int i = 0; i < 3; i++) {
        fossil_tofu_destroy(&array[i]);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(cpp_algorithm_tests) {    
    // Generic ToFu Fixture
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_i8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_i16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_i64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_u8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_u16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_u32);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_u64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_hex);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_octal);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_float);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_double);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_wstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_cstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_bool);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_size);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_compare_any);

    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_i8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_i16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_i64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_u8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_u16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_u32);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_hex);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_octal);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_float);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_double);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_wstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_cstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_bool);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_size);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_search_any);

    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_i8_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_i8_descending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_i16_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_i16_descending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_i32_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_i32_descending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_u64_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_u64_descending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_float_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_float_descending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_cstr_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_sort_cstr_descending);

    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_i8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_i16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_i64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_u8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_u16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_u32);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_u64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_hex);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_octal);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_float);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_double);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_wstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_cstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_bool);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_size);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_reverse_any);

    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_i8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_i16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_i32);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_i64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_u8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_u16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_u32);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_u64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_hex);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_octal);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_float);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_double);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_wstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_cstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_bool);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_min_size);

    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_i8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_i16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_i32);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_i64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_u8);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_u16);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_u32);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_u64);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_hex);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_octal);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_float);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_double);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_wstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_cstr);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_bool);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_max_size);

    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_class_compare);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_class_search);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_class_sort_ascending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_class_sort_descending);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_class_reverse);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_class_min);
    FOSSIL_TEST_ADD(cpp_algorithm_fixture, cpp_test_algorithm_class_max);
    

    // Register the fixture
    FOSSIL_TEST_REGISTER(cpp_algorithm_fixture);
} // end of tests
