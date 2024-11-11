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
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <time.h>

// Lookup table for valid strings corresponding to each tofu type.
static const char *tofu_type_strings[] = {
    "ghost",
    "int", "i8", "i16", "i32", "i64", 
    "uint", "u8", "u16", "u32", "u64", 
    "hex", "octal", "float", "double",
    "bstr", "wstr", "cstr", "bchar",
    "cchar", "wchar", "bool", "size"
};

// Function to check if a string represents a valid integer
bool is_valid_int(const char *str) {
    if (*str == '-' || *str == '+') str++;
    if (!*str) return false; // Ensure there's at least one digit
    while (*str) {
        if (!isdigit(*str)) return false;
        str++;
    }
    return true;
}

// Function to check if a string represents a valid unsigned integer
bool is_valid_uint(const char *str) {
    if (!*str) return false; // Ensure there's at least one digit
    while (*str) {
        if (!isdigit(*str)) return false;
        str++;
    }
    return true;
}

// Function to check if a string represents a valid hexadecimal number
bool is_valid_hex(const char *str) {
    if (strlen(str) > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        str += 2;  // Skip "0x" or "0X"
        if (!*str) return false; // Ensure there's at least one digit
        while (*str) {
            if (!isxdigit(*str)) return false;
            str++;
        }
        return true;
    }
    return false;
}

// Function to check if a string represents a valid octal number
bool is_valid_octal(const char *str) {
    if (strlen(str) > 1 && str[0] == '0') {
        str++;  // Skip "0"
        if (!*str) return false; // Ensure there's at least one digit
        while (*str) {
            if (*str < '0' || *str > '7') return false;
            str++;
        }
        return true;
    }
    return false;
}

// Function to check if a string represents a valid float/double
bool is_valid_float(const char *str) {
    bool has_dot = false;
    if (*str == '-' || *str == '+') str++;
    if (!*str) return false; // Ensure there's at least one digit
    while (*str) {
        if (*str == '.') {
            if (has_dot) return false;  // More than one dot
            has_dot = true;
        } else if (!isdigit(*str)) {
            return false;
        }
        str++;
    }
    return has_dot;  // Ensure there was at least one dot
}

// Function to check if a string represents a valid boolean (true or false)
bool is_valid_bool(const char *str) {
    return strcmp(str, "true") == 0 || strcmp(str, "false") == 0;
}

// Function to duplicate a wide string
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
    if (!str) {
        fprintf(stderr, "Error: NULL pointer passed to string_to_tofu_type\n");
        return FOSSIL_TOFU_TYPE_GHOST;
    }

    for (int i = 0; i < FOSSIL_TOFU_TYPE_SIZE; ++i) {
        if (strcmp(str, tofu_type_strings[i]) == 0) {
            return (fossil_tofu_type_t)i;
        }
    }

    fprintf(stderr, "Error: Invalid tofu type string '%s'\n", str);
    return FOSSIL_TOFU_TYPE_GHOST; // Default to ghost type if not found
}

// Helper function to check if a type is valid.
bool fossil_tofu_is_valid_type(const char *type) {
    size_t num_types = sizeof(tofu_type_strings) / sizeof(tofu_type_strings[0]);
    for (size_t i = 0; i < num_types; i++) {
        if (strcmp(type, tofu_type_strings[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to create fossil_tofu_t based on type and value strings with validation checks
fossil_tofu_t fossil_tofu_create(char *type, char *value) {
    fossil_tofu_type_t tofu_type = string_to_tofu_type(type);
    fossil_tofu_t tofu;
    tofu.type = tofu_type;

    switch (tofu_type) {
        case FOSSIL_TOFU_TYPE_INT:
            if (!is_valid_int(value)) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            } else {
                tofu.value.int_val = atoll(value);
            }
            break;
        case FOSSIL_TOFU_TYPE_UINT:
            if (!is_valid_uint(value)) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            } else {
                tofu.value.uint_val = strtoull(value, NULL, 10);
            }
            break;
        case FOSSIL_TOFU_TYPE_HEX:
            if (!is_valid_hex(value)) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            } else {
                tofu.value.uint_val = parse_hexadecimal(value);
            }
            break;
        case FOSSIL_TOFU_TYPE_OCTAL:
            if (!is_valid_octal(value)) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            } else {
                tofu.value.uint_val = parse_octal(value);
            }
            break;
        case FOSSIL_TOFU_TYPE_FLOAT:
            if (!is_valid_float(value)) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            } else {
                tofu.value.float_val = strtof(value, NULL);
            }
            break;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            if (!is_valid_float(value)) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            } else {
                tofu.value.double_val = strtod(value, NULL);
            }
            break;
        case FOSSIL_TOFU_TYPE_BSTR:
            tofu.value.uchar_string_val = (uint16_t *)fossil_tofu_alloc((strlen(value) + 1) * sizeof(uint16_t));
            if (!tofu.value.uchar_string_val) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            tofu.value.wchar_string_val = custom_wcsdup((wchar_t *)value);
            if (!tofu.value.wchar_string_val) {
            tofu.value.cchar_string_val = fossil_tofu_strdup(value);
            if (!tofu.value.cchar_string_val) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            }
            }
                strcpy((char *)tofu.value.uchar_string_val, value);
            }
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            tofu.value.wchar_string_val = custom_wcsdup((wchar_t *)value);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            tofu.value.cchar_string_val = fossil_tofu_strdup(value);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            tofu.value.uchar_val = (uint16_t)value[0];
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            tofu.value.cchar_val = value[0];
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            tofu.value.wchar_val = ((wchar_t *)value)[0];
            break;
        case FOSSIL_TOFU_TYPE_BOOL:
            if (!is_valid_bool(value)) {
                tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            } else {
                if (strcmp(value, "true") == 0) {
                    tofu.value.bool_val = true;
                } else if (strcmp(value, "false") == 0) {
                    tofu.value.bool_val = false;
                }
            }
            break;
        default:
            tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            break;
    }

    return tofu;
}

fossil_tofu_t *fossil_tofu_create_blocks(char* type, size_t size, ...) {
    fossil_tofu_t *tofu_blocks = (fossil_tofu_t *)fossil_tofu_alloc(size * sizeof(fossil_tofu_t));
    if (!tofu_blocks) {
        fprintf(stderr, "Memory allocation failed for tofu_blocks\n");
        return NULL;
    }

    va_list args;
    va_start(args, size);
    for (size_t i = 0; i < size; i++) {
        char *value = va_arg(args, char *);
        tofu_blocks[i] = fossil_tofu_create(type, value);
    }
    va_end(args);

    return tofu_blocks;
}

// Function to destroy fossil_tofu_t and free allocated memory
void fossil_tofu_destroy(fossil_tofu_t *tofu) {
    if (!tofu) {
        return;
    }

    switch (tofu->type) {
        case FOSSIL_TOFU_TYPE_BSTR:
            if (tofu->value.uchar_string_val) {
                fossil_tofu_free(tofu->value.uchar_string_val);
            }
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            if (tofu->value.wchar_string_val) {
                fossil_tofu_free(tofu->value.wchar_string_val);
            }
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            if (tofu->value.cchar_string_val) {
                fossil_tofu_free(tofu->value.cchar_string_val);
            }
            break;
        default:
            break;
    }
    tofu->type = FOSSIL_TOFU_TYPE_GHOST;
}

void fossil_tofu_destroy_blocks(fossil_tofu_t *tofu_blocks, size_t size) {
    if (!tofu_blocks) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        fossil_tofu_destroy(&tofu_blocks[i]);
    }
    fossil_tofu_free(tofu_blocks);
}

// Utility function to convert fossil_tofu_type_t to string representation
const char* fossil_tofu_type_to_string(fossil_tofu_type_t type) {
    if (type >= 0 && type < FOSSIL_TOFU_TYPE_BOOL) {
        return tofu_type_strings[type];
    } else {
        return "unknown";
    }
}

// Utility function to print fossil_tofu_t
void fossil_tofu_print(fossil_tofu_t tofu) {
    const char *type_str = fossil_tofu_type_to_string(tofu.type);
    if (!type_str) {
        fprintf(stderr, "Error: Invalid tofu type\n");
        return;
    }

    printf("Type: %s, Value: ", type_str);
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
            if (!tofu.value.uchar_string_val) {
                fprintf(stderr, "Error: Null BSTR value\n");
                return;
            }
            printf("%s", (char*)tofu.value.uchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            if (!tofu.value.wchar_string_val) {
                fprintf(stderr, "Error: Null WSTR value\n");
                return;
            }
            printf("%ls", tofu.value.wchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            if (!tofu.value.cchar_string_val) {
                fprintf(stderr, "Error: Null CSTR value\n");
                return;
            }
            printf("%s", tofu.value.cchar_string_val);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            printf("%c", (char)tofu.value.uchar_val);
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            printf("%c", tofu.value.cchar_val);
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            printf("%c", (char)tofu.value.wchar_val);
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

// Utility function to compare two fossil_tofu_t objects
bool fossil_tofu_compare(fossil_tofu_t *tofu1, fossil_tofu_t *tofu2) {
    if (!tofu1 || !tofu2) {
        fprintf(stderr, "Error: Null pointer passed to fossil_tofu_compare\n");
        return false;
    }
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
            if (!tofu1->value.uchar_string_val || !tofu2->value.uchar_string_val) {
                return false;
            }
            return strcmp((char*)tofu1->value.uchar_string_val, (char*)tofu2->value.uchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_WSTR:
            if (!tofu1->value.wchar_string_val || !tofu2->value.wchar_string_val) {
                return false;
            }
            return wcscmp(tofu1->value.wchar_string_val, tofu2->value.wchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_CSTR:
            if (!tofu1->value.cchar_string_val || !tofu2->value.cchar_string_val) {
                return false;
            }
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
            if (!tofu1.value.uchar_string_val || !tofu2.value.uchar_string_val) {
                return false;
            }
            return strcmp((char*)tofu1.value.uchar_string_val, (char*)tofu2.value.uchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_WSTR:
            if (!tofu1.value.wchar_string_val || !tofu2.value.wchar_string_val) {
                return false;
            }
            return wcscmp(tofu1.value.wchar_string_val, tofu2.value.wchar_string_val) == 0;
        case FOSSIL_TOFU_TYPE_CSTR:
            if (!tofu1.value.cchar_string_val || !tofu2.value.cchar_string_val) {
                return false;
            }
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
    
    switch (tofu.type) {
        case FOSSIL_TOFU_TYPE_BSTR:
            copy.value.uchar_string_val = (uint16_t *)fossil_tofu_strdup((char*)tofu.value.uchar_string_val);
            if (!copy.value.uchar_string_val) {
                copy.type = FOSSIL_TOFU_TYPE_GHOST;
            }
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            copy.value.wchar_string_val = custom_wcsdup(tofu.value.wchar_string_val);
            if (!copy.value.wchar_string_val) {
                copy.type = FOSSIL_TOFU_TYPE_GHOST;
            }
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            copy.value.cchar_string_val = fossil_tofu_strdup(tofu.value.cchar_string_val);
            if (!copy.value.cchar_string_val) {
                copy.type = FOSSIL_TOFU_TYPE_GHOST;
            }
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

fossil_tofu_t fossil_tofu_move(fossil_tofu_t tofu) {
    fossil_tofu_t moved = tofu;
    tofu.type = FOSSIL_TOFU_TYPE_GHOST;
    return moved;
}

// Function to transform elements in an array
void fossil_tofu_algorithm_transform(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t)) {
    if (!array || !func) return;
    for (size_t i = 0; i < size; i++) {
        array[i] = func(array[i]);
    }
}

// Function to accumulate elements in an array
fossil_tofu_t fossil_tofu_algorithm_accumulate(fossil_tofu_t *array, size_t size, fossil_tofu_t init, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    if (!array || !func) return init;
    fossil_tofu_t result = init;
    for (size_t i = 0; i < size; i++) {
        result = func(result, array[i]);
    }
    return result;
}

// Function to filter elements in an array
size_t fossil_tofu_algorithm_filter(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
    if (!array || !pred) return 0;
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(array[i])) {
            array[j++] = array[i];
        }
    }
    return j;
}

// Function to search for an element in an array
fossil_tofu_t* fossil_tofu_algorithm_search(fossil_tofu_t *array, size_t size, fossil_tofu_t key, bool (*compare)(fossil_tofu_t, fossil_tofu_t)) {
    if (!array || !compare) return NULL;
    for (size_t i = 0; i < size; i++) {
        if (compare(array[i], key)) {
            return &array[i];
        }
    }
    return NULL;
}

// Function to reverse elements in an array
void fossil_tofu_algorithm_reverse(fossil_tofu_t *array, size_t size) {
    if (!array) return;
    for (size_t i = 0, j = size - 1; i < j; i++, j--) {
        fossil_tofu_algorithm_swap(array, i, j);
    }
}

// Function to swap two elements in an array
void fossil_tofu_algorithm_swap(fossil_tofu_t *array, size_t index1, size_t index2) {
    if (!array) return;
    fossil_tofu_t temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

// Function to compare two elements
int fossil_tofu_algorithm_compare(fossil_tofu_t a, fossil_tofu_t b) {
    if (a.type != b.type) return a.type - b.type;

    switch (a.type) {
        case FOSSIL_TOFU_TYPE_INT:
            return (a.value.int_val > b.value.int_val) - (a.value.int_val < b.value.int_val);
        case FOSSIL_TOFU_TYPE_UINT:
        case FOSSIL_TOFU_TYPE_HEX:
        case FOSSIL_TOFU_TYPE_OCTAL:
            return (a.value.uint_val > b.value.uint_val) - (a.value.uint_val < b.value.uint_val);
        case FOSSIL_TOFU_TYPE_DOUBLE:
            return (a.value.double_val > b.value.double_val) - (a.value.double_val < b.value.double_val);
        case FOSSIL_TOFU_TYPE_FLOAT:
            return (a.value.float_val > b.value.float_val) - (a.value.float_val < b.value.float_val);
        case FOSSIL_TOFU_TYPE_BSTR:
            return strcmp((char*)a.value.uchar_string_val, (char*)b.value.uchar_string_val);
        case FOSSIL_TOFU_TYPE_WSTR:
            return wcscmp(a.value.wchar_string_val, b.value.wchar_string_val);
        case FOSSIL_TOFU_TYPE_CSTR:
            return strcmp(a.value.cchar_string_val, b.value.cchar_string_val);
        case FOSSIL_TOFU_TYPE_BCHAR:
            return (a.value.uchar_val > b.value.uchar_val) - (a.value.uchar_val < b.value.uchar_val);
        case FOSSIL_TOFU_TYPE_CCHAR:
            return (a.value.cchar_val > b.value.cchar_val) - (a.value.cchar_val < b.value.cchar_val);
        case FOSSIL_TOFU_TYPE_WCHAR:
            return (a.value.wchar_val > b.value.wchar_val) - (a.value.wchar_val < b.value.wchar_val);
        case FOSSIL_TOFU_TYPE_SIZE:
            return (a.value.size_val > b.value.size_val) - (a.value.size_val < b.value.size_val);
        case FOSSIL_TOFU_TYPE_BOOL:
            return (a.value.bool_val > b.value.bool_val) - (a.value.bool_val < b.value.bool_val);
        default:
            return 0; // Consider equal for unknown types
    }
}

// Function to reduce elements in an array
fossil_tofu_t fossil_tofu_algorithm_reduce(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    if (!array || !func || size == 0) return fossil_tofu_create("ghost", "");
    fossil_tofu_t result = array[0];
    for (size_t i = 1; i < size; i++) {
        result = func(result, array[i]);
    }
    return result;
}

// Function to shuffle elements in an array
void fossil_tofu_algorithm_shuffle(fossil_tofu_t *array, size_t size) {
    if (!array) return;
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
        fossil_tofu_algorithm_swap(array, i, j);
    }
}

// Function to apply a function to each element in an array
void fossil_tofu_algorithm_for_each(fossil_tofu_t *array, size_t size, void (*func)(fossil_tofu_t)) {
    if (!array || !func) return;
    for (size_t i = 0; i < size; i++) {
        func(array[i]);
    }
}

// Function to partition elements in an array
size_t fossil_tofu_algorithm_partition(fossil_tofu_t *array, size_t size, bool (*pred)(fossil_tofu_t)) {
    if (!array || !pred) return 0;
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (pred(array[i])) {
            fossil_tofu_algorithm_swap(array, i, j++);
        }
    }
    return j;
}

// Function to calculate the summary of elements in an array
fossil_tofu_t fossil_tofu_algorithm_summary(fossil_tofu_t *array, size_t size, fossil_tofu_t (*func)(fossil_tofu_t, fossil_tofu_t)) {
    if (!array || !func) return fossil_tofu_create("ghost", "");
    return fossil_tofu_algorithm_reduce(array, size, func);
}

// Helper function for calculating the average
fossil_tofu_t fossil_tofu_algorithm_average_helper(fossil_tofu_t a, fossil_tofu_t b) {
    a.value.double_val += b.value.double_val;
    return a;
}

// Function to calculate the average of elements in an array
fossil_tofu_t fossil_tofu_algorithm_average(fossil_tofu_t *array, size_t size) {
    if (!array || size == 0) return fossil_tofu_create("ghost", "ghost");
    fossil_tofu_t sum = fossil_tofu_algorithm_reduce(array, size, fossil_tofu_algorithm_average_helper);
    sum.value.double_val /= size;
    return sum;
}

// Function to create a new iterator for an array of tofu
fossil_tofu_iterator_t fossil_tofu_iteratorof_create(fossil_tofu_t *array, size_t size) {
    fossil_tofu_iterator_t iterator;
    if (!array || size == 0) {
        fprintf(stderr, "Error: Invalid array or size\n");
        iterator.array = NULL;
        iterator.size = 0;
        iterator.current_index = 0;
    } else {
        iterator.array = array;
        iterator.size = size;
        iterator.current_index = 0;
    }
    return iterator;
}

// Function to check if the iterator has more elements
bool fossil_tofu_iteratorof_has_next(fossil_tofu_iterator_t *iterator) {
    if (!iterator || !iterator->array) {
        fprintf(stderr, "Error: Invalid iterator\n");
        return false;
    }
    return iterator->current_index < iterator->size;
}

// Function to get the next element in the iterator
fossil_tofu_t fossil_tofu_iteratorof_next(fossil_tofu_iterator_t *iterator) {
    if (!iterator || !iterator->array) {
        fprintf(stderr, "Error: Invalid iterator\n");
        return fossil_tofu_create("ghost", ""); // Return a ghost tofu if iterator is invalid
    }
    if (fossil_tofu_iteratorof_has_next(iterator)) {
        return iterator->array[iterator->current_index++];
    }
    fprintf(stderr, "Error: No more elements in iterator\n");
    return fossil_tofu_create("ghost", ""); // Return a ghost tofu if no more elements
}

// Function to reset the iterator to the beginning
void fossil_tofu_iteratorof_reset(fossil_tofu_iterator_t *iterator) {
    if (!iterator) {
        fprintf(stderr, "Error: Invalid iterator\n");
        return;
    }
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
        fprintf(stderr, "Error: Cannot allocate zero bytes\n");
        return NULL;
    }

    tofu_memory_t ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Error: Memory allocation failed\n");
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
        fprintf(stderr, "Error: Cannot reallocate to zero bytes\n");
        fossil_tofu_free(ptr);
        return NULL;
    }

    tofu_memory_t new_ptr = realloc(ptr, size);
    if (!new_ptr) {
        fprintf(stderr, "Error: Memory reallocation failed\n");
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
    } else {
        fprintf(stderr, "Warning: Attempted to free a NULL pointer\n");
    }
} // end of fun

/**
 * @brief Duplicate a string.
 * 
 * @param str String to duplicate.
 * @return Pointer to the duplicated string, or NULL if allocation fails.
 */
char* fossil_tofu_strdup(const char* str) {
    if (!str) {
        fprintf(stderr, "Error: NULL pointer passed to fossil_tofu_strdup\n");
        return NULL; // Handle NULL pointer gracefully
    }

    size_t len = 0;
    while (str[len] != '\0') len++; // Calculate the length of the string

    char* dup = fossil_tofu_alloc((len + 1) * sizeof(char)); // Allocate memory for the duplicate string
    if (!dup) {
        fprintf(stderr, "Error: Memory allocation failed in fossil_tofu_strdup\n");
        return NULL; // Return NULL if allocation fails
    }

    for (size_t i = 0; i < len; i++) {
        dup[i] = str[i]; // Copy each character from the original string to the duplicate
    }
    dup[len] = '\0'; // Add null terminator to the end of the duplicate string

    return dup;
} // end of fun
