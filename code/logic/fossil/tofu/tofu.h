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
#include <stddef.h>
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

namespace fossil {

namespace tofu {

    class Tofu {
    public:
        /**
         * @brief Default constructor for Tofu class.
         * Creates a default tofu object.
         * @throws std::runtime_error if the tofu creation fails.
         */
        Tofu() {
            tofu_ = fossil_tofu_create_default();
            if (!tofu_) {
                throw std::runtime_error("Failed to create default tofu.");
            }
        }

        /**
         * @brief Copy constructor for Tofu class.
         * Creates a new tofu object by copying another.
         * @param other The Tofu object to copy.
         * @throws std::runtime_error if the tofu copy fails.
         */
        Tofu(const Tofu& other) {
            tofu_ = fossil_tofu_create_copy(other.tofu_);
            if (!tofu_) {
                throw std::runtime_error("Failed to copy tofu.");
            }
        }

        /**
         * @brief Move constructor for Tofu class.
         * Transfers ownership of the tofu object from another Tofu instance.
         * @param other The Tofu object to move.
         */
        Tofu(Tofu&& other) noexcept {
            tofu_ = other.tofu_;
            other.tofu_ = nullptr;
        }

        /**
         * @brief Destructor for Tofu class.
         * Cleans up the tofu object.
         */
        ~Tofu() {
            if (tofu_) {
                fossil_tofu_destroy(tofu_);
            }
        }

        /**
         * @brief Copy assignment operator for Tofu class.
         * Copies the tofu object from another Tofu instance.
         * @param other The Tofu object to copy.
         * @return Reference to the current Tofu object.
         * @throws std::runtime_error if the tofu copy fails.
         */
        Tofu& operator=(const Tofu& other) {
            if (this != &other) {
                fossil_tofu_t* new_tofu = fossil_tofu_create_copy(other.tofu_);
                if (!new_tofu) {
                    throw std::runtime_error("Failed to copy tofu.");
                }
                fossil_tofu_destroy(tofu_);
                tofu_ = new_tofu;
            }
            return *this;
        }

        /**
         * @brief Move assignment operator for Tofu class.
         * Transfers ownership of the tofu object from another Tofu instance.
         * @param other The Tofu object to move.
         * @return Reference to the current Tofu object.
         */
        Tofu& operator=(Tofu&& other) noexcept {
            if (this != &other) {
                fossil_tofu_destroy(tofu_);
                tofu_ = other.tofu_;
                other.tofu_ = nullptr;
            }
            return *this;
        }

        /**
         * @brief Sets the value of the tofu object.
         * @param value The value to set.
         * @throws std::runtime_error if setting the value fails.
         */
        void set_value(const std::string& value) {
            if (fossil_tofu_set_value(tofu_, const_cast<char*>(value.c_str())) != FOSSIL_TOFU_SUCCESS) {
                throw std::runtime_error("Failed to set tofu value.");
            }
        }

        /**
         * @brief Gets the value of the tofu object.
         * @return The value as a string.
         * @throws std::runtime_error if retrieving the value fails.
         */
        std::string get_value() const {
            char* value = fossil_tofu_get_value(tofu_);
            if (!value) {
                throw std::runtime_error("Failed to get tofu value.");
            }
            return std::string(value);
        }

        /**
         * @brief Checks if the tofu object is mutable.
         * @return True if mutable, false otherwise.
         */
        bool is_mutable() const {
            return fossil_tofu_is_mutable(tofu_);
        }

        /**
         * @brief Sets the mutability of the tofu object.
         * @param mutable_flag True for mutable, false for immutable.
         * @throws std::runtime_error if setting mutability fails.
         */
        void set_mutable(bool mutable_flag) {
            if (fossil_tofu_set_mutable(tofu_, mutable_flag) != FOSSIL_TOFU_SUCCESS) {
                throw std::runtime_error("Failed to set tofu mutability.");
            }
        }

        /**
         * @brief Gets the type of the tofu object.
         * @return The type as a fossil_tofu_type_t enum value.
         */
        fossil_tofu_type_t get_type() const {
            return fossil_tofu_get_type(tofu_);
        }

        /**
         * @brief Gets the type name of the tofu object.
         * @return The type name as a string.
         * @throws std::runtime_error if retrieving the type name fails.
         */
        std::string get_type_name() const {
            const char* type_name = fossil_tofu_type_name(get_type());
            if (!type_name) {
                throw std::runtime_error("Failed to get tofu type name.");
            }
            return std::string(type_name);
        }

        /**
         * @brief Sets an attribute for the tofu object.
         * @param name The attribute name.
         * @param description The attribute description.
         * @param id The unique identifier for the attribute.
         * @throws std::runtime_error if setting the attribute fails.
         */
        void set_attribute(const std::string& name, const std::string& description, const std::string& id) {
            if (fossil_tofu_set_attribute(tofu_, name.c_str(), description.c_str(), id.c_str()) != FOSSIL_TOFU_SUCCESS) {
                throw std::runtime_error("Failed to set tofu attribute.");
            }
        }

        /**
         * @brief Gets the attribute of the tofu object.
         * @return The attribute as a fossil_tofu_attribute_t struct.
         * @throws std::runtime_error if retrieving the attribute fails.
         */
        fossil_tofu_attribute_t get_attribute() const {
            const fossil_tofu_attribute_t* attr = fossil_tofu_get_attribute(tofu_);
            if (!attr) {
                throw std::runtime_error("Failed to get tofu attribute.");
            }
            return *attr;
        }

        /**
         * @brief Compares the current tofu object with another for equality.
         * @param other The Tofu object to compare with.
         * @return True if equal, false otherwise.
         */
        bool equals(const Tofu& other) const {
            return fossil_tofu_equals(tofu_, other.tofu_);
        }

    private:
        fossil_tofu_t* tofu_; /**< Pointer to the underlying tofu object. */
    };

} // namespace tofu

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
