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

#define INITIAL_CAPACITY 10

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
    FOSSIL_TOFU_TYPE_I8,
    FOSSIL_TOFU_TYPE_I16,
    FOSSIL_TOFU_TYPE_I32,
    FOSSIL_TOFU_TYPE_I64,
    FOSSIL_TOFU_TYPE_U8,
    FOSSIL_TOFU_TYPE_U16,
    FOSSIL_TOFU_TYPE_U32,
    FOSSIL_TOFU_TYPE_U64,
    FOSSIL_TOFU_TYPE_HEX,
    FOSSIL_TOFU_TYPE_OCTAL,
    FOSSIL_TOFU_TYPE_FLOAT,
    FOSSIL_TOFU_TYPE_DOUBLE,
    FOSSIL_TOFU_TYPE_WSTR,
    FOSSIL_TOFU_TYPE_CSTR,
    FOSSIL_TOFU_TYPE_CCHAR,
    FOSSIL_TOFU_TYPE_WCHAR,
    FOSSIL_TOFU_TYPE_BOOL,
    FOSSIL_TOFU_TYPE_SIZE,
    FOSSIL_TOFU_TYPE_ANY
} fossil_tofu_type_t;

typedef struct {
    char *data;
    bool mutable_flag;
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
// Managment functions
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
 * Function to destroy a `fossil_tofu_t` object and fossil_tofu_free the allocated memory.
 *
 * @param tofu The `fossil_tofu_t` object to be destroyed.
 * @note O(1) - Constant time complexity.
 */
void fossil_tofu_destroy(fossil_tofu_t *tofu);

// *****************************************************************************
// Utility functions
// *****************************************************************************

/**
 * Function to set the value of a `fossil_tofu_t` object.
 *
 * @param tofu Pointer to the `fossil_tofu_t` object.
 * @param value The value string to be set.
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int fossil_tofu_set_value(fossil_tofu_t *tofu, char *value);

/**
 * Function to get the value of a `fossil_tofu_t` object as a string.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return The value string or `NULL` if the object is invalid.
 * @note O(1) - Constant time complexity.
 */
char* fossil_tofu_get_value(const fossil_tofu_t *tofu);

/**
 * Function to check if the `fossil_tofu_t` object is mutable_flag.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return `true` if mutable_flag, `false` otherwise.
 * @note O(1) - Constant time complexity.
 */
bool fossil_tofu_is_mutable(const fossil_tofu_t *tofu);

/**
 * Function to set the mutability of the `fossil_tofu_t` object.
 *
 * @param tofu Pointer to the `fossil_tofu_t` object.
 * @param mutable_flag The mutability flag to be set (`true` for mutable_flag, `false` for immutable).
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int fossil_tofu_set_mutable(fossil_tofu_t *tofu, bool mutable_flag);

/**
 * Function to get the type of a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return The type identifier as a `fossil_tofu_type_t` enum value.
 * @note O(1) - Constant time complexity.
 */
fossil_tofu_type_t fossil_tofu_get_type(const fossil_tofu_t *tofu);

/**
 * Function to get the type name string of a `fossil_tofu_t` object.
 *
 * @param type The type identifier.
 * @return The type name string or `NULL` if invalid.
 * @note O(1) - Constant time complexity.
 */
const char* fossil_tofu_type_name(fossil_tofu_type_t type);

/**
 * Function to get the description of a `fossil_tofu_t` object type.
 *
 * @param type The type identifier.
 * @return The description string or `NULL` if invalid.
 * @note O(1) - Constant time complexity.
 */
const char* fossil_tofu_type_info(fossil_tofu_type_t type);

/**
 * Function to display the details of a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to display.
 * @note O(1) - Constant time complexity.
 */
void fossil_tofu_display(const fossil_tofu_t *tofu);

/**
 * Function to validate if a string corresponds to a valid `fossil_tofu_type_t`.
 *
 * @param type_str The type string to validate (e.g., "i8", "float").
 * @return The corresponding `fossil_tofu_type_t` value if valid, `FOSSIL_TOFU_FAILURE` otherwise.
 * @note O(n) - Linear time complexity based on the number of types.
 */
fossil_tofu_type_t fossil_tofu_validate_type(const char *type_str);

/**
 * Function to set an attribute for the `fossil_tofu_t` object.
 *
 * @param tofu Pointer to the `fossil_tofu_t` object.
 * @param name The attribute name.
 * @param description The attribute description.
 * @param id The unique identifier for the attribute.
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int fossil_tofu_set_attribute(fossil_tofu_t *tofu, const char *name, const char *description, const char *id);

/**
 * Function to get the attribute of the `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return A pointer to the `fossil_tofu_attribute_t` struct or `NULL` if invalid.
 * @note O(1) - Constant time complexity.
 */
const fossil_tofu_attribute_t* fossil_tofu_get_attribute(const fossil_tofu_t *tofu);

/**
 * Function to compare two `fossil_tofu_t` objects for equality.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal, `false` otherwise.
 * @note O(1) - Constant time complexity.
 */
bool fossil_tofu_equals(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2);

/**
 * Function to copy a `fossil_tofu_t` object.
 *
 * @param dest Pointer to the destination `fossil_tofu_t` object.
 * @param src The source `fossil_tofu_t` object to copy from.
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int fossil_tofu_copy(fossil_tofu_t *dest, const fossil_tofu_t *src);

// *****************************************************************************
// Algorithm functions
// *****************************************************************************

/**
 * Function to compare two `fossil_tofu_t` objects.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return A negative value if tofu1 < tofu2, 0 if tofu1 == tofu2, or a positive value if tofu1 > tofu2.
 */
int fossil_tofu_algorithm_compare(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2);

/**
 * Function to search for a `fossil_tofu_t` object in an array of `fossil_tofu_t` objects.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param tofu The `fossil_tofu_t` object to search for.
 * @return The index of the tofu object if found, or -1 if not found.
 */
int fossil_tofu_algorithm_search(const fossil_tofu_t *array, size_t size, const fossil_tofu_t *tofu);

/**
 * Function to sort an array of `fossil_tofu_t` objects based on their values.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param ascending A boolean flag to indicate sorting order: `true` for ascending, `false` for descending.
 * @return `FOSSIL_TOFU_SUCCESS` if sorting is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int fossil_tofu_algorithm_sort(fossil_tofu_t *array, size_t size, bool ascending);

/**
 * Function to transform an array of `fossil_tofu_t` objects using a given transformation function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param transform_fn A function pointer to a transformation function that modifies `fossil_tofu_t` objects.
 * @return `FOSSIL_TOFU_SUCCESS` if transformation is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int fossil_tofu_algorithm_transform(fossil_tofu_t *array, size_t size, int (*transform_fn)(fossil_tofu_t *tofu));

/**
 * Function to accumulate a value from an array of `fossil_tofu_t` objects based on a given accumulation function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param accumulate_fn A function pointer to an accumulation function that processes `fossil_tofu_t` objects.
 * @param initial The initial value to start the accumulation.
 * @return The accumulated result.
 */
void* fossil_tofu_algorithm_accumulate(const fossil_tofu_t *array, size_t size, void* (*accumulate_fn)(const fossil_tofu_t *tofu, void *accum), void* initial);

/**
 * Function to filter an array of `fossil_tofu_t` objects based on a given filtering function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param filter_fn A function pointer to a filtering function that returns `true` if the tofu should be kept, or `false` if it should be excluded.
 * @param result The filtered result, which will be populated with the matching tofu objects.
 * @param result_size A pointer to a size variable that will hold the number of filtered elements.
 * @return `FOSSIL_TOFU_SUCCESS` if filtering is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int fossil_tofu_algorithm_filter(const fossil_tofu_t *array, size_t size, bool (*filter_fn)(const fossil_tofu_t *tofu), fossil_tofu_t **result, size_t *result_size);

/**
 * Function to reverse an array of `fossil_tofu_t` objects.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @return `FOSSIL_TOFU_SUCCESS` if reversal is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int fossil_tofu_algorithm_reverse(fossil_tofu_t *array, size_t size);

/**
 * Function to find the minimum `fossil_tofu_t` object from an array based on a given comparison function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param compare_fn A function pointer to a comparison function to determine the minimum.
 * @return A pointer to the minimum `fossil_tofu_t` object.
 */
fossil_tofu_t* fossil_tofu_algorithm_min(const fossil_tofu_t *array, size_t size, int (*compare_fn)(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2));

/**
 * Function to find the maximum `fossil_tofu_t` object from an array based on a given comparison function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param compare_fn A function pointer to a comparison function to determine the maximum.
 * @return A pointer to the maximum `fossil_tofu_t` object.
 */
fossil_tofu_t* fossil_tofu_algorithm_max(const fossil_tofu_t *array, size_t size, int (*compare_fn)(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2));

/**
 * Function to calculate the sum of numerical values in an array of `fossil_tofu_t` objects.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param sum_fn A function pointer to a sum function that calculates the sum based on tofu values.
 * @return The sum result.
 */
void* fossil_tofu_algorithm_sum(const fossil_tofu_t *array, size_t size, void* (*sum_fn)(const fossil_tofu_t *tofu));

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
 * @param ptr Pointer to the memory to fossil_tofu_free.
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

#ifdef __cplusplus
#include <string>

namespace fossil {

typedef fossil_tofu_attribute_t tofu_attribute_t;
typedef fossil_tofu_value_t tofu_value_t;
typedef fossil_tofu_t tofu_t;

/**
 * Function to create a `fossil_tofu_t` object based on type and value strings.
 *
 * @param type The type string.
 * @param value The value string.
 * @return The created `fossil_tofu_t` object.
 * @note O(1) - Constant time complexity.
 */
fossil_tofu_t tofu_create(std::string type, std::string value) {
    return fossil_tofu_create(const_cast<char*>(type.c_str()), const_cast<char*>(value.c_str()));
}

/**
 * Function to destroy a `fossil_tofu_t` object and fossil_tofu_free the allocated memory.
 *
 * @param tofu The `fossil_tofu_t` object to be destroyed.
 * @note O(1) - Constant time complexity.
 */
void tofu_destroy(fossil_tofu_t &tofu) {
    fossil_tofu_destroy(&tofu);
}

/**
 * Function to set the value of a `fossil_tofu_t` object.
 *
 * @param tofu Reference to the `fossil_tofu_t` object.
 * @param value The value string to be set.
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int tofu_set_value(fossil_tofu_t &tofu, std::string value) {
    return fossil_tofu_set_value(&tofu, const_cast<char*>(value.c_str()));
}

/**
 * Function to get the value of a `fossil_tofu_t` object as a string.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return The value string or `NULL` if the object is invalid.
 * @note O(1) - Constant time complexity.
 */
std::string tofu_get_value(const fossil_tofu_t &tofu) {
    char* value = fossil_tofu_get_value(&tofu);
    return value ? std::string(value) : std::string();
}

/**
 * Function to check if the `fossil_tofu_t` object is mutable_flag.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return `true` if mutable_flag, `false` otherwise.
 * @note O(1) - Constant time complexity.
 */
bool tofu_is_mutable(const fossil_tofu_t &tofu) {
    return fossil_tofu_is_mutable(&tofu);
}

/**
 * Function to set the mutability of the `fossil_tofu_t` object.
 *
 * @param tofu Reference to the `fossil_tofu_t` object.
 * @param mutable_flag The mutability flag to be set (`true` for mutable_flag, `false` for immutable).
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int tofu_set_mutable(fossil_tofu_t &tofu, bool mutable_flag) {
    return fossil_tofu_set_mutable(&tofu, mutable_flag);
}

/**
 * Function to get the type of a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return The type identifier as a `fossil_tofu_type_t` enum value.
 * @note O(1) - Constant time complexity.
 */
fossil_tofu_type_t tofu_get_type(const fossil_tofu_t &tofu) {
    return fossil_tofu_get_type(&tofu);
}

/**
 * Function to get the type name string of a `fossil_tofu_t` object.
 *
 * @param type The type identifier.
 * @return The type name string or `NULL` if invalid.
 * @note O(1) - Constant time complexity.
 */
std::string tofu_type_name(fossil_tofu_type_t type) {
    const char* name = fossil_tofu_type_name(type);
    return name ? std::string(name) : std::string();
}

/**
 * Function to get the description of a `fossil_tofu_t` object type.
 *
 * @param type The type identifier.
 * @return The description string or `NULL` if invalid.
 * @note O(1) - Constant time complexity.
 */
std::string tofu_type_info(fossil_tofu_type_t type) {
    const char* info = fossil_tofu_type_info(type);
    return info ? std::string(info) : std::string();
}

/**
 * Function to display the details of a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to display.
 * @note O(1) - Constant time complexity.
 */
void tofu_display(const fossil_tofu_t &tofu) {
    fossil_tofu_display(&tofu);
}

/**
 * Function to validate if a string corresponds to a valid `fossil_tofu_type_t`.
 *
 * @param type_str The type string to validate (e.g., "i8", "float").
 * @return The corresponding `fossil_tofu_type_t` value if valid, `FOSSIL_TOFU_FAILURE` otherwise.
 * @note O(n) - Linear time complexity based on the number of types.
 */
fossil_tofu_type_t tofu_validate_type(const std::string &type_str) {
    return fossil_tofu_validate_type(type_str.c_str());
}

/**
 * Function to set an attribute for the `fossil_tofu_t` object.
 *
 * @param tofu Reference to the `fossil_tofu_t` object.
 * @param name The attribute name.
 * @param description The attribute description.
 * @param id The unique identifier for the attribute.
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int tofu_set_attribute(fossil_tofu_t &tofu, const std::string &name, const std::string &description, const std::string &id) {
    return fossil_tofu_set_attribute(&tofu, name.c_str(), description.c_str(), id.c_str());
}

/**
 * Function to get the attribute of the `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object.
 * @return A pointer to the `fossil_tofu_attribute_t` struct or `NULL` if invalid.
 * @note O(1) - Constant time complexity.
 */
const fossil_tofu_attribute_t* tofu_get_attribute(const fossil_tofu_t &tofu) {
    return fossil_tofu_get_attribute(&tofu);
}

/**
 * Function to compare two `fossil_tofu_t` objects for equality.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal, `false` otherwise.
 * @note O(1) - Constant time complexity.
 */
bool tofu_equals(const fossil_tofu_t &tofu1, const fossil_tofu_t &tofu2) {
    return fossil_tofu_equals(&tofu1, &tofu2);
}

/**
 * Function to copy a `fossil_tofu_t` object.
 *
 * @param dest Reference to the destination `fossil_tofu_t` object.
 * @param src The source `fossil_tofu_t` object to copy from.
 * @return `FOSSIL_TOFU_SUCCESS` on success, `FOSSIL_TOFU_FAILURE` on failure.
 * @note O(1) - Constant time complexity.
 */
int tofu_copy(fossil_tofu_t &dest, const fossil_tofu_t &src) {
    return fossil_tofu_copy(&dest, &src);
}

/**
 * Function to compare two `fossil_tofu_t` objects.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return A negative value if tofu1 < tofu2, 0 if tofu1 == tofu2, or a positive value if tofu1 > tofu2.
 */
int tofu_algorithm_compare(const fossil_tofu_t &tofu1, const fossil_tofu_t &tofu2) {
    return fossil_tofu_algorithm_compare(&tofu1, &tofu2);
}

/**
 * Function to search for a `fossil_tofu_t` object in an array of `fossil_tofu_t` objects.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param tofu The `fossil_tofu_t` object to search for.
 * @return The index of the tofu object if found, or -1 if not found.
 */
int tofu_algorithm_search(const fossil_tofu_t *array, size_t size, const fossil_tofu_t &tofu) {
    return fossil_tofu_algorithm_search(array, size, &tofu);
}

/**
 * Function to sort an array of `fossil_tofu_t` objects based on their values.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param ascending A boolean flag to indicate sorting order: `true` for ascending, `false` for descending.
 * @return `FOSSIL_TOFU_SUCCESS` if sorting is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int tofu_algorithm_sort(fossil_tofu_t *array, size_t size, bool ascending) {
    return fossil_tofu_algorithm_sort(array, size, ascending);
}

/**
 * Function to transform an array of `fossil_tofu_t` objects using a given transformation function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param transform_fn A function pointer to a transformation function that modifies `fossil_tofu_t` objects.
 * @return `FOSSIL_TOFU_SUCCESS` if transformation is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int tofu_algorithm_transform(fossil_tofu_t *array, size_t size, int (*transform_fn)(fossil_tofu_t *tofu)) {
    return fossil_tofu_algorithm_transform(array, size, transform_fn);
}

/**
 * Function to accumulate a value from an array of `fossil_tofu_t` objects based on a given accumulation function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param accumulate_fn A function pointer to an accumulation function that processes `fossil_tofu_t` objects.
 * @param initial The initial value to start the accumulation.
 * @return The accumulated result.
 */
template <typename T>
T tofu_algorithm_accumulate(const fossil_tofu_t *array, size_t size, T (*accumulate_fn)(const fossil_tofu_t &tofu, T accum), T initial) {
    return *static_cast<T*>(fossil_tofu_algorithm_accumulate(array, size, reinterpret_cast<void* (*)(const fossil_tofu_t*, void*)>(accumulate_fn), &initial));
}

/**
 * Function to filter an array of `fossil_tofu_t` objects based on a given filtering function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param filter_fn A function pointer to a filtering function that returns `true` if the tofu should be kept, or `false` if it should be excluded.
 * @param result The filtered result, which will be populated with the matching tofu objects.
 * @param result_size A pointer to a size variable that will hold the number of filtered elements.
 * @return `FOSSIL_TOFU_SUCCESS` if filtering is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int tofu_algorithm_filter(const fossil_tofu_t *array, size_t size, bool (*filter_fn)(const fossil_tofu_t *tofu), fossil_tofu_t **result, size_t *result_size) {
    return fossil_tofu_algorithm_filter(array, size, filter_fn, result, result_size);
}

/**
 * Function to reverse an array of `fossil_tofu_t` objects.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @return `FOSSIL_TOFU_SUCCESS` if reversal is successful, or `FOSSIL_TOFU_FAILURE` if an error occurs.
 */
int tofu_algorithm_reverse(fossil_tofu_t *array, size_t size) {
    return fossil_tofu_algorithm_reverse(array, size);
}

/**
 * Function to find the minimum `fossil_tofu_t` object from an array based on a given comparison function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param compare_fn A function pointer to a comparison function to determine the minimum.
 * @return A pointer to the minimum `fossil_tofu_t` object.
 */
fossil_tofu_t tofu_algorithm_min(const fossil_tofu_t *array, size_t size, int (*compare_fn)(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2)) {
    return *fossil_tofu_algorithm_min(array, size, compare_fn);
}

/**
 * Function to find the maximum `fossil_tofu_t` object from an array based on a given comparison function.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param compare_fn A function pointer to a comparison function to determine the maximum.
 * @return A pointer to the maximum `fossil_tofu_t` object.
 */
fossil_tofu_t tofu_algorithm_max(const fossil_tofu_t *array, size_t size, int (*compare_fn)(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2)) {
    return *fossil_tofu_algorithm_max(array, size, compare_fn);
}

/**
 * Function to calculate the sum of numerical values in an array of `fossil_tofu_t` objects.
 *
 * @param array The array of `fossil_tofu_t` objects.
 * @param size The number of elements in the array.
 * @param sum_fn A function pointer to a sum function that calculates the sum based on tofu values.
 * @return The sum result.
 */
template <typename T>
T tofu_algorithm_sum(const fossil_tofu_t *array, size_t size, T (*sum_fn)(const fossil_tofu_t *tofu)) {
    return *static_cast<T*>(fossil_tofu_algorithm_sum(array, size, reinterpret_cast<void* (*)(const fossil_tofu_t*)>(sum_fn)));
}

} // namespace fossil
#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
