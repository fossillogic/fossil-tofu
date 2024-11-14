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
#ifndef FOSSIL_TOFU_TYPE_H
#define FOSSIL_TOFU_TYPE_H

#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Consistent return values for functions in the "tofu" data structure.
enum {
    FOSSIL_TOFU_SUCCESS = 0,
    FOSSIL_TOFU_FAILURE = -1
};

// Enumerated types for representing various data types in the "tofu" data structure.
typedef enum {
    FOSSIL_TOFU_TYPE_GHOST, // Ghost type for unknown type.
    FOSSIL_TOFU_TYPE_INT,
    FOSSIL_TOFU_TYPE_I8,
    FOSSIL_TOFU_TYPE_I16,
    FOSSIL_TOFU_TYPE_I32,
    FOSSIL_TOFU_TYPE_I64,
    FOSSIL_TOFU_TYPE_UINT,
    FOSSIL_TOFU_TYPE_U8,
    FOSSIL_TOFU_TYPE_U16,
    FOSSIL_TOFU_TYPE_U32,
    FOSSIL_TOFU_TYPE_U64,
    FOSSIL_TOFU_TYPE_HEX,
    FOSSIL_TOFU_TYPE_OCTAL,
    FOSSIL_TOFU_TYPE_FLOAT,
    FOSSIL_TOFU_TYPE_DOUBLE,
    FOSSIL_TOFU_TYPE_BSTR,
    FOSSIL_TOFU_TYPE_WSTR,
    FOSSIL_TOFU_TYPE_CSTR,
    FOSSIL_TOFU_TYPE_BCHAR,
    FOSSIL_TOFU_TYPE_CCHAR,
    FOSSIL_TOFU_TYPE_WCHAR,
    FOSSIL_TOFU_TYPE_BOOL,
    FOSSIL_TOFU_TYPE_SIZE,
    FOSSIL_TOFU_TYPE_ANY
} fossil_tofu_type_t;

// Union for holding different types of values
typedef union {
    int64_t int_val; // for signed int types
    int8_t int8_val; // for signed int types
    int16_t int16_val; // for signed int types
    int32_t int32_val; // for signed int types
    int64_t int64_val; // for signed int types
    uint64_t uint_val; // for unsigned int types
    uint8_t uint8_val; // for unsigned int types
    uint16_t uint16_val; // for unsigned int types
    uint32_t uint32_val; // for unsigned int types
    uint64_t uint64_val; // for unsigned int types
    double double_val; // for double types
    float float_val; // for float types
    uint16_t *uchar_string_val; // for byte string types
    wchar_t *wchar_string_val; // for wide string types
    char *cchar_string_val; // for C string type
    char cchar_val; // for char types
    wchar_t wchar_val; // for wide char types
    uint16_t uchar_val; // for byte types
    size_t size_val; // for size types
    uint8_t bool_val; // for bool types
    void *any_val; // for any type, to mimic C++ std::any
    void *ghost_val; // for ghost type
} fossil_tofu_value_t;

// Struct for tofu attributes
typedef struct {
    char* name; // Name of the attribute
    char* description; // Description of the attribute
    char* id; // Unique identifier for the attribute
} fossil_tofu_attribute_t;

// Struct for tofu
typedef struct {
    fossil_tofu_type_t type;
    fossil_tofu_value_t value;
    fossil_tofu_attribute_t attribute;
} fossil_tofu_t;

// *****************************************************************************
// Function prototypes
// *****************************************************************************

/**
 * Function to create a `fossil_tofu_t` object based on type and value strings.
 *
 * @param type The type string.
 * @param value The value string.
 * @return The created `fossil_tofu_t` object.
 * @note O(1) - Constant time complexity.
 */
fossil_tofu_t fossil_tofu_create(char* type, char* value);

/**
 * Function to destroy a `fossil_tofu_t` object and free the allocated memory.
 *
 * @param tofu The `fossil_tofu_t` object to be destroyed.
 * @note O(1) - Constant time complexity.
 */
void fossil_tofu_destroy(fossil_tofu_t *tofu);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Utility function to print a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be printed.
 * @note O(1) - Constant time complexity.
 */
void fossil_tofu_print(fossil_tofu_t tofu);

/**
 * Utility function to check if a given type is valid.
 *
 * @param type The type string to be checked.
 * @return `true` if the type is valid, `false` otherwise.
 * @note O(n) - Linear time complexity, where n is the number of valid types.
 */
bool fossil_tofu_is_valid_type(const char *type);

/**
 * Utility function to check if two `fossil_tofu_t` objects are equal in value.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal in value, `false` otherwise.
 * @note O(1) - Constant time complexity.
 */
bool fossil_tofu_equal_type(fossil_tofu_t tofu1, fossil_tofu_t tofu2);

/**
 * Utility function to check if two `fossil_tofu_t` objects are equal in attribute.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal in attribute, `false` otherwise.
 * @note O(1) - Constant time complexity.
 */
bool fossil_tofu_equal_value(fossil_tofu_t tofu1, fossil_tofu_t tofu2);

/**
 * Utility function to check if two `fossil_tofu_t` objects are equal in attribute.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal in attribute, `false` otherwise.
 * @note O(1) - Constant time complexity.
 */
bool fossil_tofu_equal_attribute(fossil_tofu_t tofu1, fossil_tofu_t tofu2);

/**
 * Utility function to copy a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be copied.
 * @return The copied `fossil_tofu_t` object.
 * @note O(1) - Constant time complexity.
 */
fossil_tofu_t fossil_tofu_copy(fossil_tofu_t tofu);

/**
 * Utility function to move a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be moved.
 * @return The moved `fossil_tofu_t` object.
 * @note O(1) - Constant time complexity.
 */
fossil_tofu_t fossil_tofu_move(fossil_tofu_t tofu);

/**
 * Utility function to get the name of a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return The name of the `fossil_tofu_t` object.
 * @note O(1) - Constant time complexity.
 */
const char *fossil_tofu_get_name(fossil_tofu_t tofu);

/**
 * Utility function to get the info of a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return The info of the `fossil_tofu_t` object.
 * @note O(1) - Constant time complexity.
 */
const char *fossil_tofu_get_info(fossil_tofu_t tofu);

/**
 * Utility function to get the ID of a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return The ID of the `fossil_tofu_t` object.
 * @note O(1) - Constant time complexity.
 */
const char *fossil_tofu_get_id(fossil_tofu_t tofu);

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

/**
 * Transforms elements in an array using a given function.
 *
 * @param array The array of elements to be transformed.
 * @param size The size of the array.
 * @param func The function to be applied to each element.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
void fossil_tofu_algorithm_transform(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t));

/**
 * Accumulates elements in an array using a given function and initial value.
 *
 * @param array The array of elements to be accumulated.
 * @param size The size of the array.
 * @param init The initial value for accumulation.
 * @param func The function to be applied to each element during accumulation.
 * @return The accumulated value.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
fossil_tofu_t fossil_tofu_algorithm_accumulate(fossil_tofu_t *array, size_t size, fossil_tofu_t init, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Filters elements in an array based on a given predicate function.
 *
 * @param array The array of elements to be filtered.
 * @param size The size of the array.
 * @param pred The predicate function to determine whether an element should be included in the filtered result.
 * @return The number of elements that pass the filter.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
size_t fossil_tofu_algorithm_filter(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t));

/**
 * Searches for an element in an array using a given key and comparison function.
 *
 * @param array The array of elements to be searched.
 * @param size The size of the array.
 * @param key The key to search for.
 * @param compare The comparison function to determine equality between elements.
 * @return A pointer to the first occurrence of the key in the array, or NULL if not found.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
fossil_tofu_t* fossil_tofu_algorithm_search(fossil_tofu_t *array, size_t size, fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t));

/**
 * Reverses the order of elements in an array.
 *
 * @param array The array of elements to be reversed.
 * @param size The size of the array.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
void fossil_tofu_algorithm_reverse(fossil_tofu_t *array, size_t size);

/**
 * Swaps two elements in an array.
 *
 * @param array The array containing the elements to be swapped.
 * @param index1 The index of the first element to be swapped.
 * @param index2 The index of the second element to be swapped.
 * @note O(1) - Constant time complexity.
 */
void fossil_tofu_algorithm_swap(fossil_tofu_t *array, size_t index1, size_t index2);

/**
 * Compares two elements.
 *
 * @param a The first element to be compared.
 * @param b The second element to be compared.
 * @return A negative value if a is less than b, a positive value if a is greater than b, or zero if they are equal.
 * @note O(1) - Constant time complexity.
 */
int fossil_tofu_algorithm_compare(fossil_tofu_t a, fossil_tofu_t b);

/**
 * Reduces elements in an array using a given function.
 *
 * @param array The array of elements to be reduced.
 * @param size The size of the array.
 * @param func The function to be applied to each pair of elements during reduction.
 * @return The reduced value.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
fossil_tofu_t fossil_tofu_algorithm_reduce(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Shuffles elements in an array randomly.
 *
 * @param array The array of elements to be shuffled.
 * @param size The size of the array.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
void fossil_tofu_algorithm_shuffle(fossil_tofu_t *array, size_t size);

/**
 * Applies a function to each element in an array.
 *
 * @param array The array of elements to apply the function to.
 * @param size The size of the array.
 * @param func The function to be applied to each element.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
void fossil_tofu_algorithm_for_each(fossil_tofu_t *array, size_t size, void (*func)(fossil_tofu_t));

/**
 * Partitions elements in an array based on a given predicate function.
 *
 * @param array The array of elements to be partitioned.
 * @param size The size of the array.
 * @param pred The predicate function to determine the partitioning condition.
 * @return The index of the first element in the second partition.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
size_t fossil_tofu_algorithm_partition(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t));

/**
 * Calculates the summary of elements in an array using a given function.
 *
 * @param array The array of elements to calculate the summary for.
 * @param size The size of the array.
 * @param func The function to be applied to each pair of elements during calculation.
 * @return The calculated summary.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
fossil_tofu_t fossil_tofu_algorithm_summary(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Calculates the average of elements in an array.
 *
 * @param array The array of elements to calculate the average for.
 * @param size The size of the array.
 * @return The calculated average.
 * @note O(n) - Linear time complexity, where n is the size of the array.
 */
fossil_tofu_t fossil_tofu_algorithm_average(fossil_tofu_t *array, size_t size);

/**
 * Sorts elements in an array using insertion sort algorithm.
 *
 * @param array The array of elements to be sorted.
 * @param size The size of the array.
 * @note O(n^2) - Quadratic time complexity, where n is the size of the array.
 */
void fossil_tofu_algorithm_sort(fossil_tofu_t *array, size_t size);

// *****************************************************************************
// Memory management functions
// *****************************************************************************

/**
 * @brief Allocate memory.
 * 
 * @param size Size of the memory to allocate.
 * @return Pointer to the allocated memory.
 */
typedef void * tofu_memory_t;

/**
 * @brief Allocate memory.
 * 
 * @param size Size of the memory to allocate.
 * @return Pointer to the allocated memory.
 * @note O(1) - Constant time complexity.
 */
tofu_memory_t fossil_tofu_alloc(size_t size);

/**
 * @brief Reallocate memory.
 * 
 * @param ptr Pointer to the memory to reallocate.
 * @param size Size of the memory to reallocate.
 * @return Pointer to the reallocated memory.
 * @note O(1) - Constant time complexity.
 */
tofu_memory_t fossil_tofu_realloc(tofu_memory_t ptr, size_t size);

/**
 * @brief Free memory.
 * 
 * @param ptr Pointer to the memory to free.
 * @note O(1) - Constant time complexity.
 */
void fossil_tofu_free(tofu_memory_t ptr);

/**
 * @brief Duplicate a string.
 * 
 * @param str String to duplicate.
 * @return Pointer to the duplicated string.
 * @note O(n) - Linear time complexity, where n is the length of the string.
 */
char* fossil_tofu_strdup(const char* str);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
