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

/**
    In the realm of quantum physics, our understanding of space, time, reality, and the observable universe takes
    on a fascinating and intricate character. Quantum physics delves into the fundamental nature of matter and
    energy at the smallest scales, challenging classical notions and ushering in a paradigm where the concepts of
    space and time undergo profound transformations.

    **Space in Quantum Physics:**
    At the quantum level, space is not a static, absolute backdrop but a dynamic, probabilistic arena where particles
    exist in multiple states simultaneously. Quantum superposition allows particles to occupy multiple positions at
    once until observed, at which point the wavefunction collapses, and a definite state is realized. Entanglement
    further blurs the boundaries of space, linking particles in ways that defy classical spatial separations, creating
    a non-local interconnectedness.

    **Time in Quantum Physics:**
    Quantum physics introduces a nuanced perspective on time, challenging the classical notion of a continuous and
    absolute flow. The concept of time is intricately interwoven with quantum entanglement, where correlated particles
    instantaneously influence each other regardless of distance. Additionally, time dilation effects, as predicted by
    the theory of relativity, become significant at quantum scales, revealing a profound connection between time,
    gravity, and the fabric of spacetime.

    **Reality and Observation:**
    Quantum mechanics introduces the enigmatic role of observation in shaping reality. The act of measurement collapses
    the wavefunction, determining the outcome of a quantum system. This observer-dependent reality challenges our classical
    understanding of an objective, independent world. The famous thought experiment known as the Schrödinger's cat illustrates
    the peculiar nature of reality in the quantum realm, where a system can exist in multiple states until observed.

    **The Observable Universe:**
    Quantum physics extends its influence to the observable universe, impacting our understanding of cosmic phenomena.
    Quantum fluctuations during the early moments of the universe gave rise to cosmic structures, influencing the distribution
    of galaxies and the large-scale structure we observe today. The cosmic microwave background radiation, a remnant from the
    early universe, reflects quantum fluctuations that seeded the formation of galaxies and clusters.

    In summary, quantum physics redefines our concepts of space, time, reality, and the observable universe. It invites us
    to explore a realm where particles exhibit wave-particle duality, space is a realm of probabilities, time is intertwined
    with gravity, and observation plays a crucial role in defining the nature of reality. The mysteries of quantum physics
    continue to challenge and reshape our perceptions of the fundamental fabric of the cosmos.
*/

#ifdef __cplusplus
extern "C"
{
#endif

// Consistent return values for functions in the "tofu" data structure.
enum {
    FOSSIL_TOFU_SUCCESS = 0,
    FOSSIL_TOFU_FAILURE = -1
};

// Enumerated types for representing various data types in the "tofu" data structure.
typedef enum {
    FOSSIL_TOFU_TYPE_GHOST, // Ghost type for unknown type.
    FOSSIL_TOFU_TYPE_INT,
    FOSSIL_TOFU_TYPE_UINT,
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
    FOSSIL_TOFU_TYPE_SIZE,
    FOSSIL_TOFU_TYPE_BOOL
} fossil_tofu_type_t;

// Union for holding different types of values
typedef union {
    int64_t int_val; // for signed int types
    uint64_t uint_val; // for unsigned int types
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
} fossil_tofu_value_t;

// Struct for tofu
typedef struct {
    fossil_tofu_type_t type;
    fossil_tofu_value_t value;
    bool is_cached;    // Flag to track if value is cached
    fossil_tofu_value_t cached_value; // Cached value for memorization
} fossil_tofu_t;

// Struct for iterator
typedef struct {
    fossil_tofu_t *array;
    size_t size;
    size_t current_index;
} fossil_tofu_iteratorof_t;

/**
 * @brief Allocate memory.
 * 
 * @param size Size of the memory to allocate.
 * @return Pointer to the allocated memory.
 */
typedef void * tofu_memory_t;

/**
 * Function to create a `fossil_tofu_t` object based on type and value strings.
 *
 * @param type The type string.
 * @param value The value string.
 * @return The created `fossil_tofu_t` object.
 */
fossil_tofu_t fossil_tofu_create(char* type, char* value);

/**
 * Memorization (caching) function for a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be memorized.
 */
void fossil_tofu_memorize(fossil_tofu_t *tofu);

/**
 * Utility function to print a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be printed.
 */
void fossil_tofu_print(fossil_tofu_t tofu);

/**
 * Function to destroy a `fossil_tofu_t` object and free the allocated memory.
 *
 * @param tofu The `fossil_tofu_t` object to be destroyed.
 */
void fossil_tofu_erase(fossil_tofu_t *tofu);

/**
 * Utility function to check if a given type is valid.
 *
 * @param type The type string to be checked.
 * @return `true` if the type is valid, `false` otherwise.
 */
bool fossil_tofu_is_valid_type(const char *type);

/**
 * Utility function to convert a `fossil_tofu_t` object's type to a string representation.
 *
 * @param type The `fossil_tofu_t` object's type.
 * @return The string representation of the type.
 */
const char* fossil_tofu_type_to_string(fossil_tofu_type_t type);

/**
 * Utility function to check if two `fossil_tofu_t` objects are equal.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal, `false` otherwise.
 */
bool fossil_tofu_equals(fossil_tofu_t tofu1, fossil_tofu_t tofu2);

/**
 * Utility function to copy a `fossil_tofu_t` object.
 *
 * @param tofu The `fossil_tofu_t` object to be copied.
 * @return The copied `fossil_tofu_t` object.
 */
fossil_tofu_t fossil_tofu_copy(fossil_tofu_t tofu);

/**
 * Utility function to compare two `fossil_tofu_t` objects.
 *
 * @param tofu1 The first `fossil_tofu_t` object.
 * @param tofu2 The second `fossil_tofu_t` object.
 * @return `true` if the objects are equal, `false` otherwise.
 */
bool fossil_tofu_compare(fossil_tofu_t *tofu1, fossil_tofu_t *tofu2);

/**
 * Transforms elements in an array using a given function.
 *
 * @param array The array of elements to be transformed.
 * @param size The size of the array.
 * @param func The function to be applied to each element.
 */
void fossil_tofu_actionof_transform(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t));

/**
 * Accumulates elements in an array using a given function and initial value.
 *
 * @param array The array of elements to be accumulated.
 * @param size The size of the array.
 * @param init The initial value for accumulation.
 * @param func The function to be applied to each element during accumulation.
 * @return The accumulated value.
 */
fossil_tofu_t fossil_tofu_actionof_accumulate(fossil_tofu_t *array, size_t size, fossil_tofu_t init, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Filters elements in an array based on a given predicate function.
 *
 * @param array The array of elements to be filtered.
 * @param size The size of the array.
 * @param pred The predicate function to determine whether an element should be included in the filtered result.
 * @return The number of elements that pass the filter.
 */
size_t fossil_tofu_actionof_filter(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t));

/**
 * Searches for an element in an array using a given key and comparison function.
 *
 * @param array The array of elements to be searched.
 * @param size The size of the array.
 * @param key The key to search for.
 * @param compare The comparison function to determine equality between elements.
 * @return A pointer to the first occurrence of the key in the array, or NULL if not found.
 */
fossil_tofu_t* fossil_tofu_actionof_search(fossil_tofu_t *array, size_t size, fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t));

/**
 * Reverses the order of elements in an array.
 *
 * @param array The array of elements to be reversed.
 * @param size The size of the array.
 */
void fossil_tofu_actionof_reverse(fossil_tofu_t *array, size_t size);

/**
 * Swaps two elements in an array.
 *
 * @param array The array containing the elements to be swapped.
 * @param index1 The index of the first element to be swapped.
 * @param index2 The index of the second element to be swapped.
 */
void fossil_tofu_actionof_swap(fossil_tofu_t *array, size_t index1, size_t index2);

/**
 * Compares two elements.
 *
 * @param a The first element to be compared.
 * @param b The second element to be compared.
 * @return A negative value if a is less than b, a positive value if a is greater than b, or zero if they are equal.
 */
int fossil_tofu_actionof_compare(fossil_tofu_t a, fossil_tofu_t b);

/**
 * Reduces elements in an array using a given function.
 *
 * @param array The array of elements to be reduced.
 * @param size The size of the array.
 * @param func The function to be applied to each pair of elements during reduction.
 * @return The reduced value.
 */
fossil_tofu_t fossil_tofu_actionof_reduce(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Shuffles elements in an array randomly.
 *
 * @param array The array of elements to be shuffled.
 * @param size The size of the array.
 */
void fossil_tofu_actionof_shuffle(fossil_tofu_t *array, size_t size);

/**
 * Applies a function to each element in an array.
 *
 * @param array The array of elements to apply the function to.
 * @param size The size of the array.
 * @param func The function to be applied to each element.
 */
void fossil_tofu_actionof_for_each(fossil_tofu_t *array, size_t size, void (*func)(fossil_tofu_t));

/**
 * Partitions elements in an array based on a given predicate function.
 *
 * @param array The array of elements to be partitioned.
 * @param size The size of the array.
 * @param pred The predicate function to determine the partitioning condition.
 * @return The index of the first element in the second partition.
 */
size_t fossil_tofu_actionof_partition(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t));

/**
 * Calculates the summary of elements in an array using a given function.
 *
 * @param array The array of elements to calculate the summary for.
 * @param size The size of the array.
 * @param func The function to be applied to each pair of elements during calculation.
 * @return The calculated summary.
 */
fossil_tofu_t fossil_tofu_actionof_summary(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t));

/**
 * Calculates the average of elements in an array.
 *
 * @param array The array of elements to calculate the average for.
 * @param size The size of the array.
 * @return The calculated average.
 */
fossil_tofu_t fossil_tofu_actionof_average(fossil_tofu_t *array, size_t size);

/**
 * @brief Function to create a new iterator for an array of tofu.
 *
 * This function creates a new iterator for the given array of tofu with the specified size.
 *
 * @param array The array of tofu.
 * @param size The size of the array.
 * @return The created iterator.
 */
fossil_tofu_iteratorof_t fossil_tofu_iteratorof_create(fossil_tofu_t *array, size_t size);

/**
 * @brief Function to check if the iterator has more elements.
 *
 * This function checks if the iterator has more elements to iterate over.
 *
 * @param iterator The iterator to check.
 * @return true if the iterator has more elements, false otherwise.
 */
bool fossil_tofu_iteratorof_has_next(fossil_tofu_iteratorof_t *iterator);

/**
 * @brief Function to get the next element in the iterator.
 *
 * This function returns the next element in the iterator and advances the iterator to the next position.
 *
 * @param iterator The iterator.
 * @return The next element in the iterator.
 */
fossil_tofu_t fossil_tofu_iteratorof_next(fossil_tofu_iteratorof_t *iterator);

/**
 * @brief Function to reset the iterator to the beginning.
 *
 * This function resets the iterator to the beginning, allowing iteration from the start again.
 *
 * @param iterator The iterator to reset.
 */
void fossil_tofu_iteratorof_reset(fossil_tofu_iteratorof_t *iterator);

/**
 * @brief Allocate memory.
 * 
 * @param size Size of the memory to allocate.
 * @return Pointer to the allocated memory.
 */
tofu_memory_t fossil_tofu_alloc(size_t size);

/**
 * @brief Reallocate memory.
 * 
 * @param ptr Pointer to the memory to reallocate.
 * @param size Size of the memory to reallocate.
 * @return Pointer to the reallocated memory.
 */
tofu_memory_t fossil_tofu_realloc(tofu_memory_t ptr, size_t size);

/**
 * @brief Free memory.
 * 
 * @param ptr Pointer to the memory to free.
 */
void fossil_tofu_free(tofu_memory_t ptr);

/**
 * @brief Duplicate a string.
 * 
 * @param str String to duplicate.
 * @return Pointer to the duplicated string.
 */
char* fossil_tofu_strdup(const char* str);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <string>

namespace fossil {

    namespace tofu {

    fossil_tofu_t create(std::string type, std::string value) {
        return fossil_tofu_create(type.c_str(), value.c_str());
    }

    void memorize(fossil_tofu_t *tofu) {
        fossil_tofu_memorize(tofu);
    }

    void print(fossil_tofu_t tofu) {
        fossil_tofu_print(tofu);
    }

    void erase(fossil_tofu_t *tofu) {
        fossil_tofu_erase(tofu);
    }

    bool is_valid_type(const char *type) {
        return fossil_tofu_is_valid_type(type);
    }

    const char* type_to_string(fossil_tofu_type_t type) {
        return fossil_tofu_type_to_string(type);
    }

    bool equals(fossil_tofu_t tofu1, fossil_tofu_t tofu2) {
        return fossil_tofu_equals(tofu1, tofu2);
    }

    fossil_tofu_t copy(fossil_tofu_t tofu) {
        return fossil_tofu_copy(tofu);
    }

    bool compare(fossil_tofu_t *tofu1, fossil_tofu_t *tofu2) {
        return fossil_tofu_compare(tofu1, tofu2);
    }

    void actionof_transform(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t)) {
        fossil_tofu_actionof_transform(array, size, func);
    }

    fossil_tofu_t actionof_accumulate(fossil_tofu_t *array, size_t size, fossil_tofu_t init, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
        return fossil_tofu_actionof_accumulate(array, size, init, func);
    }

    size_t actionof_filter(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
        return fossil_tofu_actionof_filter(array, size, pred);
    }

    fossil_tofu_t* actionof_search(fossil_tofu_t *array, size_t size, fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t)) {
        return fossil_tofu_actionof_search(array, size, key, compare);
    }

    void actionof_reverse(fossil_tofu_t *array, size_t size) {
        fossil_tofu_actionof_reverse(array, size);
    }

    void actionof_swap(fossil_tofu_t *array, size_t index1, size_t index2) {
        fossil_tofu_actionof_swap(array, index1, index2);
    }

    int actionof_compare(fossil_tofu_t a, fossil_tofu_t b) {
        return fossil_tofu_actionof_compare(a, b);
    }

    fossil_tofu_t actionof_reduce(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
        return fossil_tofu_actionof_reduce(array, size, func);
    }

    void actionof_shuffle(fossil_tofu_t *array, size_t size) {
        fossil_tofu_actionof_shuffle(array, size);
    }

    void actionof_for_each(fossil_tofu_t *array, size_t size, void (*func)(fossil_tofu_t)) {
        fossil_tofu_actionof_for_each(array, size, func);
    }

    size_t actionof_partition(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
        return fossil_tofu_actionof_partition(array, size, pred);
    }

    fossil_tofu_t actionof_summary(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
        return fossil_tofu_actionof_summary(array, size, func);
    }

    fossil_tofu_t actionof_average(fossil_tofu_t *array, size_t size) {
        return fossil_tofu_actionof_average(array, size);
    }

    fossil_tofu_iteratorof_t iteratorof_create(fossil_tofu_t *array, size_t size) {
        return fossil_tofu_iteratorof_create(array, size);
    }

    bool iteratorof_has_next(fossil_tofu_iteratorof_t *iterator) {
        return fossil_tofu_iteratorof_has_next(iterator);
    }

    fossil_tofu_t iteratorof_next(fossil_tofu_iteratorof_t *iterator) {
        return fossil_tofu_iteratorof_next(iterator);
    }

    void iteratorof_reset(fossil_tofu_iteratorof_t *iterator) {
        fossil_tofu_iteratorof_reset(iterator);
    }

    char* strdup(std::string str) {
        return fossil_tofu_strdup(str.c_str());
    }

    } // namespace tofu


    class ToFu {
    public:
        ToFu(fossil_tofu_t *array, size_t size) : array_(array), size_(size) {}

        size_t filter(bool (*pred)(fossil_tofu_t)) {
            return fossil::tofu::actionof_filter(array_, size_, pred);
        }

        fossil_tofu_t* search(fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t)) {
            return fossil::tofu::actionof_search(array_, size_, key, compare);
        }

        void swap(size_t index1, size_t index2) {
            fossil::tofu::actionof_swap(array_, index1, index2);
        }

        int compare(fossil_tofu_t a, fossil_tofu_t b) {
            return fossil::tofu::actionof_compare(a, b);
        }

        fossil_tofu_t reduce(fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
            return fossil::tofu::actionof_reduce(array_, size_, func);
        }

        void shuffle() {
            fossil::tofu::actionof_shuffle(array_, size_);
        }

        void for_each(void (*func)(fossil_tofu_t)) {
            fossil::tofu::actionof_for_each(array_, size_, func);
        }

        size_t partition(bool (*pred)(fossil_tofu_t)) {
            return fossil::tofu::actionof_partition(array_, size_, pred);
        }

        fossil_tofu_t summary(fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
            return fossil::tofu::actionof_summary(array_, size_, func);
        }

        fossil_tofu_t average() {
            return fossil::tofu::actionof_average(array_, size_);
        }

    private:
        fossil_tofu_t *array_;
        size_t size_;
    };

} // namespace fossil

#endif

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
