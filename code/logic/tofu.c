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
#include "fossil/tofu/tofu.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <uchar.h>
#include <inttypes.h>
#include <stdbool.h>
#include <time.h>

// Lookup table for valid strings corresponding to each tofu type.
static const char *tofu_type_strings[] = {
    "ghost", "int", "uint", "hex", "octal",
    "float", "double", "bstr", "wstr", "cstr",
    "bchar", "cchar", "wchar", "size", "bool"
};

wchar_t *custom_wcsdup(const wchar_t *src) {
    if (src == NULL) {
        return NULL;
    }

    size_t len = wcslen(src) + 1; // +1 for the null terminator
    wchar_t *dup = (wchar_t *)malloc(len * sizeof(wchar_t));
    if (dup) {
        wcscpy(dup, src);
    }

    return dup;
}

// Function to convert a multibyte string to a UTF-16 string
static char16_t *mbstoc16(const char *mbstr) {
    size_t length = strlen(mbstr) + 1; // +1 for the null terminator
    char16_t *utf16str = malloc(length * sizeof(char16_t));
    if (!utf16str) {
        return NULL; // Handle allocation failure
    }

    mbstate_t state = {0};
    const char *src = mbstr;
    char16_t *dest = utf16str;

    size_t ret;
    while ((ret = mbrtoc16(dest, src, MB_CUR_MAX, &state)) > 0) {
        src += ret;
        dest++;
    }

    *dest = u'\0'; // Null-terminate the UTF-16 string
    return utf16str;
}

// Helper function to convert hexadecimal string to uint64_t
static uint64_t parse_hexadecimal(const char *value) {
    uint64_t result;
    sscanf(value, "%" SCNx64, &result);
    return result;
}

// Helper function to convert octal string to uint64_t
static uint64_t parse_octal(const char *value) {
    uint64_t result;
    sscanf(value, "%" SCNo64, &result);
    return result;
}

// Function to convert string to fossil_tofu_type_t
fossil_tofu_type_t string_to_tofu_type(const char *str) {
    for (int i = 0; i < FOSSIL_TOFU_TYPE_SIZE; ++i) {
        if (strcmp(str, tofu_type_strings[i]) == 0) {
            return (fossil_tofu_type_t)i;
        }
    }
    return FOSSIL_TOFU_TYPE_GHOST; // Default to ghost type if not found
}

// Function to create fossil_tofu_t based on type and value strings
fossil_tofu_t fossil_tofu_create(char *type, char *value) {
    fossil_tofu_type_t tofu_type = string_to_tofu_type(type);
    fossil_tofu_t tofu;
    tofu.type = tofu_type;
    tofu.is_cached = false;

    switch (tofu_type) {
        case FOSSIL_TOFU_TYPE_INT:
            tofu.value.int_val = atoll(value);
            break;
        case FOSSIL_TOFU_TYPE_UINT:
            tofu.value.uint_val = strtoull(value, NULL, 10);
            break;
        case FOSSIL_TOFU_TYPE_HEX:
            tofu.value.uint_val = parse_hexadecimal(value);
            break;
        case FOSSIL_TOFU_TYPE_OCTAL:
            tofu.value.uint_val = parse_octal(value);
            break;
        case FOSSIL_TOFU_TYPE_FLOAT:
            tofu.value.float_val = strtof(value, NULL);
            break;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            tofu.value.double_val = strtod(value, NULL);
            break;
        case FOSSIL_TOFU_TYPE_BSTR:
            tofu.value.uchar_string_val = (char16_t *)fossil_tofu_alloc((strlen(value) + 1) * sizeof(char16_t));
            strcpy((char *)tofu.value.uchar_string_val, value);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            // Assuming wide string conversion is handled appropriately
            tofu.value.wchar_string_val = (wchar_t *)fossil_tofu_alloc((wcslen((wchar_t *)value) + 1) * sizeof(wchar_t));
            wcscpy(tofu.value.wchar_string_val, (wchar_t *)value);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            tofu.value.cchar_string_val = fossil_tofu_strdup(value);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            tofu.value.uchar_val = value[0];
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            tofu.value.cchar_val = value[0];
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            tofu.value.wchar_val = ((wchar_t *)value)[0];
            break;
        case FOSSIL_TOFU_TYPE_BOOL:
            tofu.value.bool_val = (uint8_t)atoi(value);
            break;
        default:
            fprintf(stderr, "Unsupported type\n");
            tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            break;
    }

    return tofu;
}

// Memorization (caching) function for fossil_tofu_t
void fossil_tofu_memorize(fossil_tofu_t *tofu) {
    if (!tofu->is_cached) {
        tofu->cached_value = tofu->value;
        tofu->is_cached = true;
    }
}

// Utility function to print fossil_tofu_t
void fossil_tofu_print(fossil_tofu_t tofu) {
    printf("Type: %s, Value: ", fossil_tofu_type_to_string(tofu.type));
    switch (tofu.type) {
        case FOSSIL_TOFU_TYPE_INT:
            printf("%" PRId64, tofu.value.int_val);
            break;
        case FOSSIL_TOFU_TYPE_UINT:
            printf("%" PRIu64, tofu.value.uint_val);
            break;
        case FOSSIL_TOFU_TYPE_HEX:
            printf("0x%" PRIX64, tofu.value.uint_val);
            break;
        case FOSSIL_TOFU_TYPE_OCTAL:
            printf("0%" PRIo64, tofu.value.uint_val);
            break;
        case FOSSIL_TOFU_TYPE_FLOAT:
            printf("%f", tofu.value.float_val);
            break;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            printf("%f", tofu.value.double_val);
            break;
        case FOSSIL_TOFU_TYPE_BSTR:
            printf("%s", (char*)tofu.value.uchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            printf("%ls", tofu.value.wchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            printf("%s", tofu.value.cchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            printf("%c", (char)tofu.value.uchar_val);
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            printf("%c", tofu.value.cchar_val);
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            printf("%lc", tofu.value.wchar_val);
            break;
        case FOSSIL_TOFU_TYPE_SIZE:
            printf("%" PRIuPTR, (uintptr_t)tofu.value.size_val);
            break;
        case FOSSIL_TOFU_TYPE_BOOL:
            printf("%s", tofu.value.bool_val ? "true" : "false");
            break;
        default:
            printf("unknown");
            break;
    }
    printf("\n");
}

// Function to destroy fossil_tofu_t and free allocated memory
void fossil_tofu_erase(fossil_tofu_t *tofu) {
    if (!tofu) {
        return;
    }

    switch (tofu->type) {
        case FOSSIL_TOFU_TYPE_BSTR:
            fossil_tofu_free(tofu->value.uchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            fossil_tofu_free(tofu->value.wchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            fossil_tofu_free(tofu->value.cchar_string_val);
            break;
        default:
            tofu->type = FOSSIL_TOFU_TYPE_GHOST;
            tofu->is_cached = false;
            break;
    }
}

// Utility function to convert fossil_tofu_type_t to string representation
const char* fossil_tofu_type_to_string(fossil_tofu_type_t type) {
    if (type >= 0 && type < FOSSIL_TOFU_TYPE_BOOL) {
        return tofu_type_strings[type];
    } else {
        return "unknown";
    }
}

// Utility function to compare two fossil_tofu_t objects
bool fossil_tofu_compare(fossil_tofu_t *tofu1, fossil_tofu_t *tofu2) {
    if (!tofu1 || !tofu2) return false;
    if (tofu1->type != tofu2->type) return false;

    switch (tofu1->type) {
        case FOSSIL_TOFU_TYPE_INT:
            return tofu1->value.int_val == tofu2->value.int_val;
        case FOSSIL_TOFU_TYPE_UINT:
        case FOSSIL_TOFU_TYPE_HEX:
        case FOSSIL_TOFU_TYPE_OCTAL:
            return tofu1->value.uint_val == tofu2->value.uint_val;
        case FOSSIL_TOFU_TYPE_FLOAT:
            return tofu1->value.float_val == tofu2->value.float_val;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            return tofu1->value.double_val == tofu2->value.double_val;
        case FOSSIL_TOFU_TYPE_BSTR:
            return strcmp((char*)tofu1->value.uchar_string_val, (char*)tofu2->value.uchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_WSTR:
            return wcscmp(tofu1->value.wchar_string_val, tofu2->value.wchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_CSTR:
            return strcmp(tofu1->value.cchar_string_val, tofu2->value.cchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_BCHAR:
            return tofu1->value.uchar_val == tofu2->value.uchar_val;
        case FOSSIL_TOFU_TYPE_CCHAR:
            return tofu1->value.cchar_val == tofu2->value.cchar_val;
        case FOSSIL_TOFU_TYPE_WCHAR:
            return tofu1->value.wchar_val == tofu2->value.wchar_val;
        case FOSSIL_TOFU_TYPE_SIZE:
            return tofu1->value.size_val == tofu2->value.size_val;
        case FOSSIL_TOFU_TYPE_BOOL:
            return tofu1->value.bool_val == tofu2->value.bool_val;
        default:
            return false;
    }
}

// Utility function to check if two fossil_tofu_t objects are equal
bool fossil_tofu_equals(fossil_tofu_t tofu1, fossil_tofu_t tofu2) {
    if (tofu1.type != tofu2.type) {
        return false;
    }

    switch (tofu1.type) {
        case FOSSIL_TOFU_TYPE_INT:
            return tofu1.value.int_val == tofu2.value.int_val;
        case FOSSIL_TOFU_TYPE_UINT:
        case FOSSIL_TOFU_TYPE_HEX:
        case FOSSIL_TOFU_TYPE_OCTAL:
            return tofu1.value.uint_val == tofu2.value.uint_val;
        case FOSSIL_TOFU_TYPE_FLOAT:
            return tofu1.value.float_val == tofu2.value.float_val;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            return tofu1.value.double_val == tofu2.value.double_val;
        case FOSSIL_TOFU_TYPE_BSTR:
            return strcmp((char*)tofu1.value.uchar_string_val, (char*)tofu2.value.uchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_WSTR:
            return wcscmp(tofu1.value.wchar_string_val, tofu2.value.wchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_CSTR:
            return strcmp(tofu1.value.cchar_string_val, tofu2.value.cchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_BCHAR:
            return tofu1.value.uchar_val == tofu2.value.uchar_val;
        case FOSSIL_TOFU_TYPE_CCHAR:
            return tofu1.value.cchar_val == tofu2.value.cchar_val;
        case FOSSIL_TOFU_TYPE_WCHAR:
            return tofu1.value.wchar_val == tofu2.value.wchar_val;
        case FOSSIL_TOFU_TYPE_SIZE:
            return tofu1.value.size_val == tofu2.value.size_val;
        case FOSSIL_TOFU_TYPE_BOOL:
            return tofu1.value.bool_val == tofu2.value.bool_val;
        default:
            return false;
    }
}

// Utility function to copy a fossil_tofu_t object
fossil_tofu_t fossil_tofu_copy(fossil_tofu_t tofu) {
    fossil_tofu_t copy = tofu;
    copy.is_cached = false; // Reset the cached state in the copy
    
    switch (tofu.type) {
        case FOSSIL_TOFU_TYPE_BSTR:
            copy.value.uchar_string_val = mbstoc16((char*)tofu.value.uchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            copy.value.wchar_string_val = custom_wcsdup(tofu.value.wchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            copy.value.cchar_string_val = fossil_tofu_strdup(tofu.value.cchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_INT:
            copy.value.int_val = tofu.value.int_val;
            break;
        case FOSSIL_TOFU_TYPE_UINT:
        case FOSSIL_TOFU_TYPE_HEX:
        case FOSSIL_TOFU_TYPE_OCTAL:
            copy.value.uint_val = tofu.value.uint_val;
            break;
        case FOSSIL_TOFU_TYPE_FLOAT:
            copy.value.float_val = tofu.value.float_val;
            break;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            copy.value.double_val = tofu.value.double_val;
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            copy.value.uchar_val = tofu.value.uchar_val;
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            copy.value.cchar_val = tofu.value.cchar_val;
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            copy.value.wchar_val = tofu.value.wchar_val;
            break;
        case FOSSIL_TOFU_TYPE_SIZE:
            copy.value.size_val = tofu.value.size_val;
            break;
        case FOSSIL_TOFU_TYPE_BOOL:
            copy.value.bool_val = tofu.value.bool_val;
            break;
        default:
            break;
    }
    return copy;
}

// Function to transform elements in an array
void fossil_tofu_actionof_transform(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t)) {
    for (size_t i = 0; i < size; i++) {
        array[i] = func(array[i]);
    }
}

// Function to accumulate elements in an array
fossil_tofu_t fossil_tofu_actionof_accumulate(fossil_tofu_t *array, size_t size, fossil_tofu_t init, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    fossil_tofu_t result = init;
    for (size_t i = 0; i < size; i++) {
        result = func(result, array[i]);
    }
    return result;
}

// Function to filter elements in an array
size_t fossil_tofu_actionof_filter(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(array[i])) {
            array[j++] = array[i];
        }
    }
    return j;
}

// Function to search for an element in an array
fossil_tofu_t* fossil_tofu_actionof_search(fossil_tofu_t *array, size_t size, fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t)) {
    for (size_t i = 0; i < size; i++) {
        if (compare(array[i], key)) {
            return &array[i];
        }
    }
    return NULL;
}

// Function to reverse elements in an array
void fossil_tofu_actionof_reverse(fossil_tofu_t *array, size_t size) {
    for (size_t i = 0, j = size - 1; i < j; i++, j--) {
        fossil_tofu_actionof_swap(array, i, j);
    }
}

// Function to swap two elements in an array
void fossil_tofu_actionof_swap(fossil_tofu_t *array, size_t index1, size_t index2) {
    fossil_tofu_t temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

// Function to compare two elements
int fossil_tofu_actionof_compare(fossil_tofu_t a, fossil_tofu_t b) {
    // Simplified example, more comprehensive comparison logic needed for all types
    if (a.type != b.type) return a.type - b.type;
    switch (a.type) {
        case FOSSIL_TOFU_TYPE_INT:
            return a.value.int_val - b.value.int_val;
        case FOSSIL_TOFU_TYPE_UINT:
            return a.value.uint_val - b.value.uint_val;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            return (a.value.double_val > b.value.double_val) - (a.value.double_val < b.value.double_val);
        case FOSSIL_TOFU_TYPE_FLOAT:
            return (a.value.float_val > b.value.float_val) - (a.value.float_val < b.value.float_val);
        default:
            return 0;
    }
}

// Function to reduce elements in an array
fossil_tofu_t fossil_tofu_actionof_reduce(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    if (size == 0) return fossil_tofu_create("ghost", "");
    fossil_tofu_t result = array[0];
    for (size_t i = 1; i < size; i++) {
        result = func(result, array[i]);
    }
    return result;
}

// Function to shuffle elements in an array
void fossil_tofu_actionof_shuffle(fossil_tofu_t *array, size_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
        fossil_tofu_actionof_swap(array, i, j);
    }
}

// Function to apply a function to each element in an array
void fossil_tofu_actionof_for_each(fossil_tofu_t *array, size_t size, void (*func)(fossil_tofu_t)) {
    for (size_t i = 0; i < size; i++) {
        func(array[i]);
    }
}

// Function to partition elements in an array
size_t fossil_tofu_actionof_partition(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(array[i])) {
            fossil_tofu_actionof_swap(array, i, j++);
        }
    }
    return j;
}

// Function to calculate the summary of elements in an array
fossil_tofu_t fossil_tofu_actionof_summary(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    return fossil_tofu_actionof_reduce(array, size, func);
}

// Helper function for calculating the average
fossil_tofu_t fossil_tofu_actionof_average_helper(fossil_tofu_t a, fossil_tofu_t b) {
    a.value.double_val += b.value.double_val;
    return a;
}

// Function to calculate the average of elements in an array
fossil_tofu_t fossil_tofu_actionof_average(fossil_tofu_t *array, size_t size) {
    if (size == 0) return fossil_tofu_create("ghost", "ghost");
    fossil_tofu_t sum = fossil_tofu_actionof_reduce(array, size, fossil_tofu_actionof_average_helper);
    sum.value.double_val /= size;
    return sum;
}

// Function to create a new iterator for an array of tofu
fossil_tofu_iteratorof_t fossil_tofu_iteratorof_create(fossil_tofu_t *array, size_t size) {
    fossil_tofu_iteratorof_t iterator;
    iterator.array = array;
    iterator.size = size;
    iterator.current_index = 0;
    return iterator;
}

// Function to check if the iterator has more elements
bool fossil_tofu_iteratorof_has_next(fossil_tofu_iteratorof_t *iterator) {
    return iterator->current_index < iterator->size;
}

// Function to get the next element in the iterator
fossil_tofu_t fossil_tofu_iteratorof_next(fossil_tofu_iteratorof_t *iterator) {
    if (fossil_tofu_iteratorof_has_next(iterator)) {
        return iterator->array[iterator->current_index++];
    }
    return fossil_tofu_create("ghost", ""); // Return a ghost tofu if no more elements
}

// Function to reset the iterator to the beginning
void fossil_tofu_iteratorof_reset(fossil_tofu_iteratorof_t *iterator) {
    iterator->current_index = 0;
}

/**
 * @brief Allocate memory.
 * 
 * @param size Size of the memory to allocate.
 * @return Pointer to the allocated memory, or NULL if allocation fails or size is 0.
 */
tofu_memory_t fossil_tofu_alloc(size_t size) {
    if (size == 0) {
        return NULL;
    }

    tofu_memory_t ptr = malloc(size);
    if (!ptr) {
        return NULL;
    }
    return ptr;
}

/**
 * @brief Reallocate memory.
 * 
 * @param ptr Pointer to the memory to reallocate.
 * @param size Size of the memory to reallocate.
 * @return Pointer to the reallocated memory, or NULL if reallocation fails.
 */
tofu_memory_t fossil_tofu_realloc(tofu_memory_t ptr, size_t size) {
    if (size == 0) {
        fossil_tofu_free(ptr);
        return NULL;
    }

    tofu_memory_t new_ptr = realloc(ptr, size);
    if (!new_ptr) {
        return NULL; // Return NULL if reallocation fails
    }

    return new_ptr;
}

/**
 * @brief Free memory.
 * 
 * @param ptr Pointer to the memory to free.
 */
void fossil_tofu_free(tofu_memory_t ptr) {
    if (ptr) {
        free(ptr);
    } // No need to exit if ptr is NULL
} // end of fun

/**
 * @brief Duplicate a string.
 * 
 * @param str String to duplicate.
 * @return Pointer to the duplicated string, or NULL if allocation fails.
 */
char* fossil_tofu_strdup(const char* str) {
    if (!str) return NULL; // Handle NULL pointer gracefully

    size_t len = 0;
    while (str[len] != '\0') len++; // Calculate the length of the string

    char* dup = fossil_tofu_alloc((len + 1) * sizeof(char)); // Allocate memory for the duplicate string
    if (!dup) return NULL; // Return NULL if allocation fails

    for (size_t i = 0; i < len; i++) {
        dup[i] = str[i]; // Copy each character from the original string to the duplicate
    }
    dup[len] = '\0'; // Add null terminator to the end of the duplicate string

    return dup;
} // end of fun
