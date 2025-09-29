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
#ifndef FOSSIL_TOFU_TYPE_H
#define FOSSIL_TOFU_TYPE_H

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define INITIAL_CAPACITY 10

#ifdef __cplusplus
extern "C"
{
#endif

// *****************************************************************************
// Type definitions
// *****************************************************************************

// Error codes for the "tofu" data structure.
enum {
    FOSSIL_TOFU_SUCCESS = 0,                      // Operation successful
    FOSSIL_TOFU_FAILURE = -1,                     // General failure
    FOSSIL_TOFU_ERROR_INVALID_ARGUMENT = -2,      // Invalid argument provided to function
    FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION = -3,     // Memory allocation failed
    FOSSIL_TOFU_ERROR_TYPE_MISMATCH = -4,         // Type mismatch encountered
    FOSSIL_TOFU_ERROR_NOT_FOUND = -5,             // Requested item not found
    FOSSIL_TOFU_ERROR_OVERFLOW = -6,       // Value too large for the type
    FOSSIL_TOFU_ERROR_UNDERFLOW = -7,      // Value too small for the type
    FOSSIL_TOFU_ERROR_IMMUTABLE = -8,      // Tried to modify an immutable value
    FOSSIL_TOFU_ERROR_NULL_POINTER = -9,   // NULL pointer provided where not allowed
    FOSSIL_TOFU_ERROR_UNSUPPORTED = -10,   // Operation not supported for this type
    FOSSIL_TOFU_ERROR_CAPACITY = -11,      // Container reached max capacity
    FOSSIL_TOFU_ERROR_PARSE = -12          // Failed to parse input into a value
};

// Enumerated types for representing various data types in the "tofu" data structure.
typedef enum {
    FOSSIL_TOFU_TYPE_I8,        // 8-bit signed integer
    FOSSIL_TOFU_TYPE_I16,       // 16-bit signed integer
    FOSSIL_TOFU_TYPE_I32,       // 32-bit signed integer
    FOSSIL_TOFU_TYPE_I64,       // 64-bit signed integer
    FOSSIL_TOFU_TYPE_U8,        // 8-bit unsigned integer
    FOSSIL_TOFU_TYPE_U16,       // 16-bit unsigned integer
    FOSSIL_TOFU_TYPE_U32,       // 32-bit unsigned integer
    FOSSIL_TOFU_TYPE_U64,       // 64-bit unsigned integer
    FOSSIL_TOFU_TYPE_HEX,       // Hexadecimal value (string or integer)
    FOSSIL_TOFU_TYPE_OCT,       // Octal value (string or integer)
    FOSSIL_TOFU_TYPE_BIN,       // Binary value (compatible with C11 and C23 implmentations)
    FOSSIL_TOFU_TYPE_F32,       // Single-precision floating point
    FOSSIL_TOFU_TYPE_F64,       // Double-precision floating point
    FOSSIL_TOFU_TYPE_CSTR,      // C-style string (null-terminated)
    FOSSIL_TOFU_TYPE_CCHAR,     // Single character
    FOSSIL_TOFU_TYPE_BOOL,      // Boolean value
    FOSSIL_TOFU_TYPE_SIZE,      // Size type (e.g., size_t)
    FOSSIL_TOFU_TYPE_DATETIME,  // ISO 8601 datetime */
    FOSSIL_TOFU_TYPE_DURATION,  // Time span (e.g. "30s", "5m", "1h") */
    FOSSIL_TOFU_TYPE_ANY,       // Any type (generic)
    FOSSIL_TOFU_TYPE_CNULL      // Null pointer type
} fossil_tofu_type_t;

typedef struct {
    char *data;        // Pointer to the data
    bool mutable_flag; // Whether the data is mutable_flag or immutable
    uint64_t hash;     // Unique 64-bit hash value for the tofu
} fossil_tofu_value_t;

// Struct for tofu attributes
typedef struct {
    char* name;          // Name of the attribute
    char* description;   // Description of the attribute
    char* id;            // Unique identifier for the attribute
    bool required;       // Whether this attribute must be set
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
fossil_tofu_t fossil_tofu_create(const char* type, const char* value);

/**
 * @brief Creates a new tofu with default values.
 *
 * @return The created tofu.
 * @note Time complexity: O(1)
 */
fossil_tofu_t* fossil_tofu_create_default(void);

/**
 * @brief Creates a new tofu by copying an existing tofu.
 *
 * @param other The tofu to copy.
 * @return The created tofu.
 * @note Time complexity: O(n)
 */
fossil_tofu_t* fossil_tofu_create_copy(const fossil_tofu_t* other);

/**
 * @brief Creates a new tofu by moving an existing tofu.
 *
 * @param other The tofu to move.
 * @return The created tofu.
 * @note Time complexity: O(1)
 */
fossil_tofu_t* fossil_tofu_create_move(fossil_tofu_t* other);

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
 * Function to compare two `fossil_tofu_t` objects.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return A negative value if tofu1 < tofu2, 0 if tofu1 == tofu2, or a positive value if tofu1 > tofu2.
 */
int fossil_tofu_compare(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2);

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
 * @param type_str The type string to validate (e.g., "i8", "f32").
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

/**
 * @brief Serializes a tofu object to a FSON-like string.
 *
 * @param tofu The tofu object to serialize.
 * @return A newly allocated string containing the serialized representation.
 *         Caller must free the string.
 * @note O(n) - Linear complexity based on data size.
 */
char* fossil_tofu_serialize(const fossil_tofu_t *tofu);

/**
 * @brief Parses a string into a tofu object.
 *
 * @param serialized The serialized string.
 * @return A newly allocated tofu object or NULL on failure.
 * @note O(n) - Linear complexity based on input size.
 */
fossil_tofu_t* fossil_tofu_parse(const char *serialized);

/**
 * @brief Dumps the internal state of a tofu object for debugging.
 *
 * @param tofu The tofu object to dump.
 */
void fossil_tofu_dump(const fossil_tofu_t *tofu);

/**
 * @brief Gets the value as a string or returns a default if NULL.
 */
const char* fossil_tofu_get_value_or_default(const fossil_tofu_t *tofu, const char *default_value);

/**
 * @brief Checks if the tofu is empty (no data).
 *
 * @param tofu The tofu object.
 * @return true if empty, false otherwise.
 */
bool fossil_tofu_is_empty(const fossil_tofu_t *tofu);

/**
 * @brief Deep clones a tofu object, including its data and attributes.
 *
 * @param tofu The tofu object to clone.
 * @return A newly allocated tofu object or NULL on failure.
 */
fossil_tofu_t* fossil_tofu_clone(const fossil_tofu_t *tofu);

/**
 * @brief Permanently locks a tofu object to make it immutable.
 */
int fossil_tofu_lock(fossil_tofu_t *tofu);

// *****************************************************************************
// "as type" and "from type" function prototypes
// *****************************************************************************

/**
 * @brief Converts a tofu object to an int8_t value.
 * @param tofu Pointer to the tofu object.
 * @return The int8_t value represented by the tofu object.
 */
int8_t fossil_tofu_as_i8(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from an int8_t value.
 * @param value The int8_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_i8(int8_t value);

/**
 * @brief Converts a tofu object to an int16_t value.
 * @param tofu Pointer to the tofu object.
 * @return The int16_t value represented by the tofu object.
 */
int16_t fossil_tofu_as_i16(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from an int16_t value.
 * @param value The int16_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_i16(int16_t value);

/**
 * @brief Converts a tofu object to an int32_t value.
 * @param tofu Pointer to the tofu object.
 * @return The int32_t value represented by the tofu object.
 */
int32_t fossil_tofu_as_i32(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from an int32_t value.
 * @param value The int32_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_i32(int32_t value);

/**
 * @brief Converts a tofu object to an int64_t value.
 * @param tofu Pointer to the tofu object.
 * @return The int64_t value represented by the tofu object.
 */
int64_t fossil_tofu_as_i64(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from an int64_t value.
 * @param value The int64_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_i64(int64_t value);

/**
 * @brief Converts a tofu object to a uint8_t value.
 * @param tofu Pointer to the tofu object.
 * @return The uint8_t value represented by the tofu object.
 */
uint8_t fossil_tofu_as_u8(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a uint8_t value.
 * @param value The uint8_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_u8(uint8_t value);

/**
 * @brief Converts a tofu object to a uint16_t value.
 * @param tofu Pointer to the tofu object.
 * @return The uint16_t value represented by the tofu object.
 */
uint16_t fossil_tofu_as_u16(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a uint16_t value.
 * @param value The uint16_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_u16(uint16_t value);

/**
 * @brief Converts a tofu object to a uint32_t value.
 * @param tofu Pointer to the tofu object.
 * @return The uint32_t value represented by the tofu object.
 */
uint32_t fossil_tofu_as_u32(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a uint32_t value.
 * @param value The uint32_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_u32(uint32_t value);

/**
 * @brief Converts a tofu object to a uint64_t value.
 * @param tofu Pointer to the tofu object.
 * @return The uint64_t value represented by the tofu object.
 */
uint64_t fossil_tofu_as_u64(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a uint64_t value.
 * @param value The uint64_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_u64(uint64_t value);

/**
 * @brief Converts a tofu object to a hexadecimal string representation.
 * @param tofu Pointer to the tofu object.
 * @return The hexadecimal string, or NULL if not applicable.
 */
const char* fossil_tofu_as_hex(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a hexadecimal string.
 * @param hex_str The hexadecimal string to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_hex(const char *hex_str);

/**
 * @brief Converts a tofu object to an octal string representation.
 * @param tofu Pointer to the tofu object.
 * @return The octal string, or NULL if not applicable.
 */
const char* fossil_tofu_as_oct(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from an octal string.
 * @param oct_str The octal string to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_oct(const char *oct_str);

/**
 * @brief Converts a tofu object to a binary string representation.
 * @param tofu Pointer to the tofu object.
 * @return The binary string, or NULL if not applicable.
 */
const char* fossil_tofu_as_bin(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a binary string.
 * @param bin_str The binary string to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_bin(const char *bin_str);

/**
 * @brief Converts a tofu object to a float (single-precision).
 * @param tofu Pointer to the tofu object.
 * @return The float value represented by the tofu object.
 */
float fossil_tofu_as_f32(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a float value.
 * @param value The float value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_f32(float value);

/**
 * @brief Converts a tofu object to a double (double-precision).
 * @param tofu Pointer to the tofu object.
 * @return The double value represented by the tofu object.
 */
double fossil_tofu_as_f64(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a double value.
 * @param value The double value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_f64(double value);

/**
 * @brief Converts a tofu object to a C-style string.
 * @param tofu Pointer to the tofu object.
 * @return The C-string, or NULL if not applicable.
 */
const char* fossil_tofu_as_cstr(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a C-style string.
 * @param str The string to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_cstr(const char *str);

/**
 * @brief Converts a tofu object to a char value.
 * @param tofu Pointer to the tofu object.
 * @return The char value represented by the tofu object.
 */
char fossil_tofu_as_char(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a char value.
 * @param value The char value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_char(char value);

/**
 * @brief Converts a tofu object to a boolean value.
 * @param tofu Pointer to the tofu object.
 * @return The boolean value represented by the tofu object.
 */
bool fossil_tofu_as_bool(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a boolean value.
 * @param value The boolean value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_bool(bool value);

/**
 * @brief Converts a tofu object to a size_t value.
 * @param tofu Pointer to the tofu object.
 * @return The size_t value represented by the tofu object.
 */
size_t fossil_tofu_as_size(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a size_t value.
 * @param value The size_t value to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_size(size_t value);

/**
 * @brief Converts a tofu object to a datetime string (ISO 8601).
 * @param tofu Pointer to the tofu object.
 * @return The datetime string, or NULL if not applicable.
 */
const char* fossil_tofu_as_datetime(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a datetime string.
 * @param datetime_str The datetime string to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_datetime(const char *datetime_str);

/**
 * @brief Converts a tofu object to a duration string.
 * @param tofu Pointer to the tofu object.
 * @return The duration string, or NULL if not applicable.
 */
const char* fossil_tofu_as_duration(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a duration string.
 * @param duration_str The duration string to store.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_duration(const char *duration_str);

/**
 * @brief Converts a tofu object to a generic pointer (void*), if applicable.
 * @param tofu Pointer to the tofu object.
 * @return A pointer to the internal data, or NULL if not applicable.
 */
void* fossil_tofu_as_any(const fossil_tofu_t *tofu);

/**
 * @brief Creates a tofu object from a generic pointer and size.
 * @param data Pointer to the data to store.
 * @param size Size of the data in bytes.
 * @return The created tofu object.
 */
fossil_tofu_t fossil_tofu_from_any(void *data, size_t size);

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
#include <stdexcept>
#include <utility>
#include <string>

/**
 * @namespace fossil
 * Root namespace for all components in the Fossil library.
 */
namespace fossil {

    /**
     * @namespace tofu
     * Contains the C++ interface for the Fossil Tofu system, which manages dynamically typed values
     * with optional attributes, mutability, and runtime type information.
     */
    namespace tofu {

        /**
         * @class Tofu
         * A C++ wrapper around the `fossil_tofu_t` C structure that provides RAII-safe management of
         * typed value objects, supporting copy/move semantics, attribute assignment, and value mutation.
         */
        class Tofu {
        public:
            /**
             * @brief Constructs a new Tofu object with the given type and value.
             * Throws a runtime_error if the type is invalid or creation fails.
             */
            Tofu(const std::string& type, const std::string& value) {
                tofu_ = fossil_tofu_create(const_cast<char*>(type.c_str()), const_cast<char*>(value.c_str()));
                if (tofu_.type == FOSSIL_TOFU_TYPE_ANY) {
                    throw std::runtime_error("Failed to create Tofu object");
                }
            }

            /**
             * @brief Default constructor. Creates a Tofu object with default values.
             */
            Tofu() {
                fossil_tofu_t* ptr = fossil_tofu_create_default();
                if (!ptr) throw std::runtime_error("Failed to create default Tofu");
                tofu_ = *ptr;
                fossil_tofu_free(ptr);
            }

            /**
             * @brief Constructs a Tofu object from a fossil_tofu_t struct.
             */
            Tofu(const fossil_tofu_t& tofu) {
                tofu_ = *fossil_tofu_create_copy(&tofu);
            }

            /**
             * @brief Destructor. Automatically destroys the internal C Tofu object.
             */
            ~Tofu() {
                fossil_tofu_destroy(&tofu_);
            }

            /**
             * @brief Copy constructor. Creates a deep copy of another Tofu object.
             */
            Tofu(const Tofu& other) {
                tofu_ = *fossil_tofu_create_copy(&other.tofu_);
            }

            /**
             * @brief Move constructor. Transfers ownership of another Tofu object.
             */
            Tofu(Tofu&& other) noexcept {
                tofu_ = *fossil_tofu_create_move(&other.tofu_);
                other.tofu_.type = FOSSIL_TOFU_TYPE_ANY;
            }

            /**
             * @brief Copy assignment operator. Destroys current value and copies from another Tofu.
             */
            Tofu& operator=(const Tofu& other) {
                if (this != &other) {
                    fossil_tofu_destroy(&tofu_);
                    tofu_ = *fossil_tofu_create_copy(&other.tofu_);
                }
                return *this;
            }

            /**
             * @brief Move assignment operator. Transfers ownership of another Tofu.
             */
            Tofu& operator=(Tofu&& other) noexcept {
                if (this != &other) {
                    fossil_tofu_destroy(&tofu_);
                    tofu_ = *fossil_tofu_create_move(&other.tofu_);
                    other.tofu_.type = FOSSIL_TOFU_TYPE_ANY;
                }
                return *this;
            }

            /**
             * @brief Gets the value stored in the Tofu object as a string.
             */
            std::string get_value() const {
                const char* value = fossil_tofu_get_value(&tofu_);
                return value ? std::string(value) : std::string();
            }

            /**
             * @brief Compares this Tofu object with another.
             * Returns negative if this < other, 0 if equal, positive if this > other.
             */
            int compare(const Tofu& other) const {
                return fossil_tofu_compare(&tofu_, &other.tofu_);
            }

            /**
             * @brief Checks if the value of this Tofu object is mutable.
             */
            bool is_mutable() const {
                return fossil_tofu_is_mutable(&tofu_);
            }

            /**
             * @brief Sets a new value for this Tofu object. Throws on failure.
             */
            void set_value(const std::string& value) {
                if (fossil_tofu_set_value(&tofu_, const_cast<char*>(value.c_str())) != FOSSIL_TOFU_SUCCESS) {
                    throw std::runtime_error("Failed to set value");
                }
            }

            /**
             * @brief Sets the mutability of this Tofu object. Throws on failure.
             */
            void set_mutable(bool mutable_flag) {
                if (fossil_tofu_set_mutable(&tofu_, mutable_flag) != FOSSIL_TOFU_SUCCESS) {
                    throw std::runtime_error("Failed to set mutable flag");
                }
            }

            /**
             * @brief Compares this Tofu object with another for equality.
             */
            bool equals(const Tofu& other) const {
                return fossil_tofu_equals(&tofu_, &other.tofu_);
            }

            /**
             * @brief Gets the name of the Tofu object's type.
             */
            std::string get_type_name() const {
                const char* type_name = fossil_tofu_type_name(tofu_.type);
                return type_name ? std::string(type_name) : std::string();
            }

            /**
             * @brief Gets detailed type information about the Tofu object's type.
             */
            std::string get_type_info() const {
                const char* type_info = fossil_tofu_type_info(tofu_.type);
                return type_info ? std::string(type_info) : std::string();
            }

            /**
             * @brief Retrieves the attribute metadata (name, description, id) of this Tofu object.
             */
            const fossil_tofu_attribute_t* get_attribute() const {
                return fossil_tofu_get_attribute(&tofu_);
            }

            /**
             * @brief Sets the attribute metadata for this Tofu object. Throws on failure.
             */
            void set_attribute(const std::string& name, const std::string& description, const std::string& id) {
                if (fossil_tofu_set_attribute(&tofu_, name.c_str(), description.c_str(), id.c_str()) != FOSSIL_TOFU_SUCCESS) {
                    throw std::runtime_error("Failed to set attribute");
                }
            }

            /**
             * @brief Serializes this Tofu object to a JSON-like string.
             */
            std::string serialize() const {
                char* serialized = fossil_tofu_serialize(&tofu_);
                std::string result = serialized ? std::string(serialized) : std::string();
                if (serialized) fossil_tofu_free(serialized);
                return result;
            }

            /**
             * @brief Parses a serialized string into a new Tofu object.
             * Throws std::runtime_error on failure.
             */
            static Tofu parse(const std::string& serialized) {
                fossil_tofu_t* parsed = fossil_tofu_parse(serialized.c_str());
                if (!parsed) throw std::runtime_error("Failed to parse Tofu");
                Tofu result(*parsed);
                fossil_tofu_destroy(parsed);
                fossil_tofu_free(parsed);
                return result;
            }

            /**
             * @brief Gets the value as a string, or returns the provided default if NULL.
             */
            std::string get_value_or_default(const std::string& default_value) const {
                const char* val = fossil_tofu_get_value_or_default(&tofu_, default_value.c_str());
                return val ? std::string(val) : default_value;
            }

            /**
             * @brief Checks if the Tofu object is empty (no data).
             */
            bool is_empty() const {
                return fossil_tofu_is_empty(&tofu_);
            }

            /**
             * @brief Deep clones this Tofu object.
             * Throws std::runtime_error on failure.
             */
            Tofu clone() const {
                fossil_tofu_t* cloned = fossil_tofu_clone(&tofu_);
                if (!cloned) throw std::runtime_error("Failed to clone Tofu");
                Tofu result(*cloned);
                fossil_tofu_destroy(cloned);
                fossil_tofu_free(cloned);
                return result;
            }

            /**
             * @brief Permanently locks this Tofu object to make it immutable.
             * Throws std::runtime_error on failure.
             */
            void lock() {
                if (fossil_tofu_lock(&tofu_) != FOSSIL_TOFU_SUCCESS) {
                    throw std::runtime_error("Failed to lock Tofu");
                }
            }

            // "as type" and "from type" C++ wrappers

            /**
             * @brief Converts the Tofu object to an int8_t value.
             * @return The int8_t value represented by the Tofu object.
             */
            int8_t as_i8() const { return fossil_tofu_as_i8(&tofu_); }

            /**
             * @brief Creates a Tofu object from an int8_t value.
             * @param value The int8_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_i8(int8_t value) { return Tofu(fossil_tofu_from_i8(value)); }

            /**
             * @brief Converts the Tofu object to an int16_t value.
             * @return The int16_t value represented by the Tofu object.
             */
            int16_t as_i16() const { return fossil_tofu_as_i16(&tofu_); }

            /**
             * @brief Creates a Tofu object from an int16_t value.
             * @param value The int16_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_i16(int16_t value) { return Tofu(fossil_tofu_from_i16(value)); }

            /**
             * @brief Converts the Tofu object to an int32_t value.
             * @return The int32_t value represented by the Tofu object.
             */
            int32_t as_i32() const { return fossil_tofu_as_i32(&tofu_); }

            /**
             * @brief Creates a Tofu object from an int32_t value.
             * @param value The int32_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_i32(int32_t value) { return Tofu(fossil_tofu_from_i32(value)); }

            /**
             * @brief Converts the Tofu object to an int64_t value.
             * @return The int64_t value represented by the Tofu object.
             */
            int64_t as_i64() const { return fossil_tofu_as_i64(&tofu_); }

            /**
             * @brief Creates a Tofu object from an int64_t value.
             * @param value The int64_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_i64(int64_t value) { return Tofu(fossil_tofu_from_i64(value)); }

            /**
             * @brief Converts the Tofu object to a uint8_t value.
             * @return The uint8_t value represented by the Tofu object.
             */
            uint8_t as_u8() const { return fossil_tofu_as_u8(&tofu_); }

            /**
             * @brief Creates a Tofu object from a uint8_t value.
             * @param value The uint8_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_u8(uint8_t value) { return Tofu(fossil_tofu_from_u8(value)); }

            /**
             * @brief Converts the Tofu object to a uint16_t value.
             * @return The uint16_t value represented by the Tofu object.
             */
            uint16_t as_u16() const { return fossil_tofu_as_u16(&tofu_); }

            /**
             * @brief Creates a Tofu object from a uint16_t value.
             * @param value The uint16_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_u16(uint16_t value) { return Tofu(fossil_tofu_from_u16(value)); }

            /**
             * @brief Converts the Tofu object to a uint32_t value.
             * @return The uint32_t value represented by the Tofu object.
             */
            uint32_t as_u32() const { return fossil_tofu_as_u32(&tofu_); }

            /**
             * @brief Creates a Tofu object from a uint32_t value.
             * @param value The uint32_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_u32(uint32_t value) { return Tofu(fossil_tofu_from_u32(value)); }

            /**
             * @brief Converts the Tofu object to a uint64_t value.
             * @return The uint64_t value represented by the Tofu object.
             */
            uint64_t as_u64() const { return fossil_tofu_as_u64(&tofu_); }

            /**
             * @brief Creates a Tofu object from a uint64_t value.
             * @param value The uint64_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_u64(uint64_t value) { return Tofu(fossil_tofu_from_u64(value)); }

            /**
             * @brief Converts the Tofu object to a hexadecimal string representation.
             * @return The hexadecimal string, or an empty string if not applicable.
             */
            std::string as_hex() const {
                const char* s = fossil_tofu_as_hex(&tofu_);
                return s ? std::string(s) : std::string();
            }

            /**
             * @brief Creates a Tofu object from a hexadecimal string.
             * @param hex_str The hexadecimal string to store.
             * @return The created Tofu object.
             */
            static Tofu from_hex(const std::string& hex_str) { return Tofu(fossil_tofu_from_hex(hex_str.c_str())); }

            /**
             * @brief Converts the Tofu object to an octal string representation.
             * @return The octal string, or an empty string if not applicable.
             */
            std::string as_oct() const {
                const char* s = fossil_tofu_as_oct(&tofu_);
                return s ? std::string(s) : std::string();
            }

            /**
             * @brief Creates a Tofu object from an octal string.
             * @param oct_str The octal string to store.
             * @return The created Tofu object.
             */
            static Tofu from_oct(const std::string& oct_str) { return Tofu(fossil_tofu_from_oct(oct_str.c_str())); }

            /**
             * @brief Converts the Tofu object to a binary string representation.
             * @return The binary string, or an empty string if not applicable.
             */
            std::string as_bin() const {
                const char* s = fossil_tofu_as_bin(&tofu_);
                return s ? std::string(s) : std::string();
            }

            /**
             * @brief Creates a Tofu object from a binary string.
             * @param bin_str The binary string to store.
             * @return The created Tofu object.
             */
            static Tofu from_bin(const std::string& bin_str) { return Tofu(fossil_tofu_from_bin(bin_str.c_str())); }

            /**
             * @brief Converts the Tofu object to a float (single-precision).
             * @return The float value represented by the Tofu object.
             */
            float as_f32() const { return fossil_tofu_as_f32(&tofu_); }

            /**
             * @brief Creates a Tofu object from a float value.
             * @param value The float value to store.
             * @return The created Tofu object.
             */
            static Tofu from_f32(float value) { return Tofu(fossil_tofu_from_f32(value)); }

            /**
             * @brief Converts the Tofu object to a double (double-precision).
             * @return The double value represented by the Tofu object.
             */
            double as_f64() const { return fossil_tofu_as_f64(&tofu_); }

            /**
             * @brief Creates a Tofu object from a double value.
             * @param value The double value to store.
             * @return The created Tofu object.
             */
            static Tofu from_f64(double value) { return Tofu(fossil_tofu_from_f64(value)); }

            /**
             * @brief Converts the Tofu object to a C-style string.
             * @return The C-string, or an empty string if not applicable.
             */
            std::string as_cstr() const {
                const char* s = fossil_tofu_as_cstr(&tofu_);
                return s ? std::string(s) : std::string();
            }

            /**
             * @brief Creates a Tofu object from a C-style string.
             * @param str The string to store.
             * @return The created Tofu object.
             */
            static Tofu from_cstr(const std::string& str) { return Tofu(fossil_tofu_from_cstr(str.c_str())); }

            /**
             * @brief Converts the Tofu object to a char value.
             * @return The char value represented by the Tofu object.
             */
            char as_char() const { return fossil_tofu_as_char(&tofu_); }

            /**
             * @brief Creates a Tofu object from a char value.
             * @param value The char value to store.
             * @return The created Tofu object.
             */
            static Tofu from_char(char value) { return Tofu(fossil_tofu_from_char(value)); }

            /**
             * @brief Converts the Tofu object to a boolean value.
             * @return The boolean value represented by the Tofu object.
             */
            bool as_bool() const { return fossil_tofu_as_bool(&tofu_); }

            /**
             * @brief Creates a Tofu object from a boolean value.
             * @param value The boolean value to store.
             * @return The created Tofu object.
             */
            static Tofu from_bool(bool value) { return Tofu(fossil_tofu_from_bool(value)); }

            /**
             * @brief Converts the Tofu object to a size_t value.
             * @return The size_t value represented by the Tofu object.
             */
            size_t as_size() const { return fossil_tofu_as_size(&tofu_); }

            /**
             * @brief Creates a Tofu object from a size_t value.
             * @param value The size_t value to store.
             * @return The created Tofu object.
             */
            static Tofu from_size(size_t value) { return Tofu(fossil_tofu_from_size(value)); }

            /**
             * @brief Converts the Tofu object to a datetime string (ISO 8601).
             * @return The datetime string, or an empty string if not applicable.
             */
            std::string as_datetime() const {
                const char* s = fossil_tofu_as_datetime(&tofu_);
                return s ? std::string(s) : std::string();
            }

            /**
             * @brief Creates a Tofu object from a datetime string.
             * @param datetime_str The datetime string to store.
             * @return The created Tofu object.
             */
            static Tofu from_datetime(const std::string& datetime_str) { return Tofu(fossil_tofu_from_datetime(datetime_str.c_str())); }

            /**
             * @brief Converts the Tofu object to a duration string.
             * @return The duration string, or an empty string if not applicable.
             */
            std::string as_duration() const {
                const char* s = fossil_tofu_as_duration(&tofu_);
                return s ? std::string(s) : std::string();
            }

            /**
             * @brief Creates a Tofu object from a duration string.
             * @param duration_str The duration string to store.
             * @return The created Tofu object.
             */
            static Tofu from_duration(const std::string& duration_str) { return Tofu(fossil_tofu_from_duration(duration_str.c_str())); }

            /**
             * @brief Converts the Tofu object to a generic pointer (void*), if applicable.
             * @return A pointer to the internal data, or NULL if not applicable.
             */
            void* as_any() const { return fossil_tofu_as_any(&tofu_); }

            /**
             * @brief Creates a Tofu object from a generic pointer and size.
             * @param data Pointer to the data to store.
             * @param size Size of the data in bytes.
             * @return The created Tofu object.
             */
            static Tofu from_any(void* data, size_t size) { return Tofu(fossil_tofu_from_any(data, size)); }

            /**
             * @brief Displays the Tofu object using the default renderer (typically to stdout).
             */
            void display() const {
                fossil_tofu_display(&tofu_);
            }

            // Operator overloads

            // Equality operator
            bool operator==(const Tofu& other) const {
                return equals(other);
            }

            // Inequality operator
            bool operator!=(const Tofu& other) const {
                return !equals(other);
            }

            // Less-than operator (compares type first, then value lexicographically)
            bool operator<(const Tofu& other) const {
                if (tofu_.type != other.tofu_.type)
                    return tofu_.type < other.tofu_.type;
                const char* val1 = fossil_tofu_get_value(&tofu_);
                const char* val2 = fossil_tofu_get_value(&other.tofu_);
                if (!val1 && !val2) return false;
                if (!val1) return true;
                if (!val2) return false;
                return std::string(val1) < std::string(val2);
            }

            // Greater-than operator
            bool operator>(const Tofu& other) const {
                return other < *this;
            }

            // Less-than or equal operator
            bool operator<=(const Tofu& other) const {
                return !(other < *this);
            }

            // Greater-than or equal operator
            bool operator>=(const Tofu& other) const {
                return !(*this < other);
            }

            /**
             * @brief Provides access to the underlying C struct for advanced use cases.
             * @return const reference to the internal fossil_tofu_t struct.
             */
            const fossil_tofu_t& get_c_struct() const {
                return tofu_;
            }

        private:
            /**
             * @brief Internal C-style Tofu object managed by the wrapper.
             */
            fossil_tofu_t tofu_;
        };

    } // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
