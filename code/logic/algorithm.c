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
#include "fossil/tofu/algorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *****************************************************************************
// Function prototypes
// *****************************************************************************

int fossil_algorithm_compare(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2) {
    if (tofu1 == NULL || tofu2 == NULL || tofu1->value.data == NULL || tofu2->value.data == NULL) return FOSSIL_TOFU_SUCCESS;

    if (tofu1->type != tofu2->type) {
        return (int)tofu1->type - (int)tofu2->type;
    }

    return strcmp(tofu1->value.data, tofu2->value.data);
}

int fossil_algorithm_search(const fossil_tofu_t *array, size_t size, const fossil_tofu_t *tofu) {
    if (array == NULL || tofu == NULL) return FOSSIL_TOFU_FAILURE;

    for (size_t i = 0; i < size; i++) {
        if (fossil_tofu_equals(&array[i], tofu)) {
            return (int)i;
        }
    }

    return FOSSIL_TOFU_FAILURE;
}

int fossil_algorithm_sort(fossil_tofu_t *array, size_t size, bool ascending) {
    if (array == NULL || size == 0) return FOSSIL_TOFU_FAILURE;

    // Perform sorting using bubble-sort style
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = i + 1; j < size; j++) {
            int cmp = fossil_algorithm_compare(&array[i], &array[j]);

            // Determine if we need to swap based on ascending/descending order
            if ((ascending && cmp > 0) || (!ascending && cmp < 0)) {
                // Swap entire `fossil_tofu_t` elements
                fossil_tofu_t temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return FOSSIL_TOFU_SUCCESS;
}

int fossil_algorithm_transform(fossil_tofu_t *array, size_t size, int (*transform_fn)(fossil_tofu_t *tofu)) {
    if (array == NULL || size == 0) return FOSSIL_TOFU_FAILURE;

    for (size_t i = 0; i < size; i++) {
        if (transform_fn(&array[i]) != FOSSIL_TOFU_SUCCESS) {
            return FOSSIL_TOFU_FAILURE;
        }
    }

    return FOSSIL_TOFU_SUCCESS;
}

void* fossil_algorithm_accumulate(const fossil_tofu_t *array, size_t size, void* (*accumulate_fn)(const fossil_tofu_t *tofu, void *accum), void* initial) {
    if (array == NULL || size == 0) return NULL;

    void *accum = initial;
    for (size_t i = 0; i < size; i++) {
        accum = accumulate_fn(&array[i], accum);
    }

    return accum;
}

int fossil_algorithm_filter(const fossil_tofu_t *array, size_t size, bool (*filter_fn)(const fossil_tofu_t *tofu), fossil_tofu_t **result, size_t *result_size) {
    if (array == NULL || size == 0) return FOSSIL_TOFU_FAILURE;

    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (filter_fn(&array[i])) {
            count++;
        }
    }

    if (count == 0) {
        *result = NULL;
        *result_size = 0;
        return FOSSIL_TOFU_SUCCESS;
    }

    *result = fossil_tofu_alloc(count * sizeof(fossil_tofu_t));
    if (*result == NULL) {
        return FOSSIL_TOFU_FAILURE;
    }

    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (filter_fn(&array[i])) {
            fossil_tofu_copy(&(*result)[j], &array[i]);
            j++;
        }
    }

    *result_size = count;
    return FOSSIL_TOFU_SUCCESS;
}

int fossil_algorithm_reverse(fossil_tofu_t *array, size_t size) {
    if (array == NULL || size == 0) return FOSSIL_TOFU_FAILURE;

    fossil_tofu_t temp;
    for (size_t i = 0; i < size / 2; i++) {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }

    return FOSSIL_TOFU_SUCCESS;
}

fossil_tofu_t* fossil_algorithm_min(const fossil_tofu_t *array, size_t size, int (*compare_fn)(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2)) {
    if (array == NULL || size == 0) return NULL;

    fossil_tofu_t *min = (fossil_tofu_t*)&array[0];
    for (size_t i = 1; i < size; i++) {
        if (compare_fn(&array[i], min) < 0) {
            min = (fossil_tofu_t*)&array[i];
        }
    }

    return min;
}

fossil_tofu_t* fossil_algorithm_max(const fossil_tofu_t *array, size_t size, int (*compare_fn)(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2)) {
    if (array == NULL || size == 0) return NULL;

    fossil_tofu_t *max = (fossil_tofu_t*)&array[0];
    for (size_t i = 1; i < size; i++) {
        if (compare_fn(&array[i], max) > 0) {
            max = (fossil_tofu_t*)&array[i];
        }
    }

    return max;
}

void* fossil_algorithm_sum(const fossil_tofu_t *array, size_t size, void* (*sum_fn)(const fossil_tofu_t *tofu)) {
    if (array == NULL || size == 0) return NULL;

    void *sum = sum_fn(&array[0]);
    for (size_t i = 1; i < size; i++) {
        sum = sum_fn(&array[i]);
    }

    return sum;
}
