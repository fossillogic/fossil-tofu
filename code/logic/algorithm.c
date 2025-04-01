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
            int cmp = 0;

            // Compare based on type
            switch (array[i].type) {
                case FOSSIL_TOFU_TYPE_I8:
                case FOSSIL_TOFU_TYPE_I16:
                case FOSSIL_TOFU_TYPE_I32:
                case FOSSIL_TOFU_TYPE_I64:
                case FOSSIL_TOFU_TYPE_U8:
                case FOSSIL_TOFU_TYPE_U16:
                case FOSSIL_TOFU_TYPE_U32:
                case FOSSIL_TOFU_TYPE_U64:
                case FOSSIL_TOFU_TYPE_SIZE: {
                    long long value1 = atoll(array[i].value.data);
                    long long value2 = atoll(array[j].value.data);
                    cmp = (value1 > value2) - (value1 < value2);
                    break;
                }
                case FOSSIL_TOFU_TYPE_FLOAT:
                case FOSSIL_TOFU_TYPE_DOUBLE: {
                    double value1 = atof(array[i].value.data);
                    double value2 = atof(array[j].value.data);
                    cmp = (value1 > value2) - (value1 < value2);
                    break;
                }
                case FOSSIL_TOFU_TYPE_BOOL: {
                    int value1 = atoi(array[i].value.data);
                    int value2 = atoi(array[j].value.data);
                    cmp = (value1 > value2) - (value1 < value2);
                    break;
                }
                case FOSSIL_TOFU_TYPE_HEX:
                case FOSSIL_TOFU_TYPE_OCTAL: {
                    long long value1 = strtoll(array[i].value.data, NULL, 
                        (array[i].type == FOSSIL_TOFU_TYPE_HEX) ? 16 : 8);
                    long long value2 = strtoll(array[j].value.data, NULL, 
                        (array[j].type == FOSSIL_TOFU_TYPE_HEX) ? 16 : 8);
                    cmp = (value1 > value2) - (value1 < value2);
                    break;
                }
                case FOSSIL_TOFU_TYPE_WSTR:
                case FOSSIL_TOFU_TYPE_CSTR:
                case FOSSIL_TOFU_TYPE_CCHAR:
                case FOSSIL_TOFU_TYPE_WCHAR:
                case FOSSIL_TOFU_TYPE_ANY: {
                    cmp = strcmp(array[i].value.data, array[j].value.data);
                    break;
                }
                default:
                    cmp = 0;
                    break;
            }

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
        int cmp = 0;

        // Compare based on type
        switch (array[i].type) {
            case FOSSIL_TOFU_TYPE_I8:
            case FOSSIL_TOFU_TYPE_I16:
            case FOSSIL_TOFU_TYPE_I32:
            case FOSSIL_TOFU_TYPE_I64:
            case FOSSIL_TOFU_TYPE_U8:
            case FOSSIL_TOFU_TYPE_U16:
            case FOSSIL_TOFU_TYPE_U32:
            case FOSSIL_TOFU_TYPE_U64:
            case FOSSIL_TOFU_TYPE_SIZE: {
                long long value1 = atoll(array[i].value.data);
                long long value2 = atoll(min->value.data);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_FLOAT:
            case FOSSIL_TOFU_TYPE_DOUBLE: {
                double value1 = atof(array[i].value.data);
                double value2 = atof(min->value.data);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_BOOL: {
                int value1 = atoi(array[i].value.data);
                int value2 = atoi(min->value.data);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_HEX:
            case FOSSIL_TOFU_TYPE_OCTAL: {
                long long value1 = strtoll(array[i].value.data, NULL, 
                    (array[i].type == FOSSIL_TOFU_TYPE_HEX) ? 16 : 8);
                long long value2 = strtoll(min->value.data, NULL, 
                    (min->type == FOSSIL_TOFU_TYPE_HEX) ? 16 : 8);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_WSTR:
            case FOSSIL_TOFU_TYPE_CSTR:
            case FOSSIL_TOFU_TYPE_CCHAR:
            case FOSSIL_TOFU_TYPE_WCHAR:
            case FOSSIL_TOFU_TYPE_ANY: {
                cmp = strcmp(array[i].value.data, min->value.data);
                break;
            }
            default:
                cmp = 0;
                break;
        }

        if (cmp < 0) {
            min = (fossil_tofu_t*)&array[i];
        }
    }

    return min;
}

fossil_tofu_t* fossil_algorithm_max(const fossil_tofu_t *array, size_t size, int (*compare_fn)(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2)) {
    if (array == NULL || size == 0) return NULL;

    fossil_tofu_t *max = (fossil_tofu_t*)&array[0];
    for (size_t i = 1; i < size; i++) {
        int cmp = 0;

        // Compare based on type
        switch (array[i].type) {
            case FOSSIL_TOFU_TYPE_I8:
            case FOSSIL_TOFU_TYPE_I16:
            case FOSSIL_TOFU_TYPE_I32:
            case FOSSIL_TOFU_TYPE_I64:
            case FOSSIL_TOFU_TYPE_U8:
            case FOSSIL_TOFU_TYPE_U16:
            case FOSSIL_TOFU_TYPE_U32:
            case FOSSIL_TOFU_TYPE_U64:
            case FOSSIL_TOFU_TYPE_SIZE: {
                long long value1 = atoll(array[i].value.data);
                long long value2 = atoll(max->value.data);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_FLOAT:
            case FOSSIL_TOFU_TYPE_DOUBLE: {
                double value1 = atof(array[i].value.data);
                double value2 = atof(max->value.data);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_BOOL: {
                int value1 = atoi(array[i].value.data);
                int value2 = atoi(max->value.data);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_HEX:
            case FOSSIL_TOFU_TYPE_OCTAL: {
                long long value1 = strtoll(array[i].value.data, NULL, 
                    (array[i].type == FOSSIL_TOFU_TYPE_HEX) ? 16 : 8);
                long long value2 = strtoll(max->value.data, NULL, 
                    (max->type == FOSSIL_TOFU_TYPE_HEX) ? 16 : 8);
                cmp = (value1 > value2) - (value1 < value2);
                break;
            }
            case FOSSIL_TOFU_TYPE_WSTR:
            case FOSSIL_TOFU_TYPE_CSTR:
            case FOSSIL_TOFU_TYPE_CCHAR:
            case FOSSIL_TOFU_TYPE_WCHAR:
            case FOSSIL_TOFU_TYPE_ANY: {
                cmp = strcmp(array[i].value.data, max->value.data);
                break;
            }
            default:
                cmp = 0;
                break;
        }

        if (cmp > 0) {
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
