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
#include "fossil/tofu/tofu.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <time.h>


// Lookup table for valid strings corresponding to each tofu type.
static char *_TOFU_TYPE_ID[] = {
    "i8",
    "i16",
    "i32",
    "i64",
    "u8",
    "u16",
    "u32",
    "u64",
    "hex",
    "octal",
    "float",
    "double",
    "wstr",
    "cstr",
    "cchar",
    "bool",
    "size",
    "any"
};

static char *_TOFU_TYPE_NAME[] = {
    "Signed 8-bit Integer",
    "Signed 16-bit Integer",
    "Signed 32-bit Integer",
    "Signed 64-bit Integer",
    "Unsigned 8-bit Integer",
    "Unsigned 16-bit Integer",
    "Unsigned 32-bit Integer",
    "Unsigned 64-bit Integer",
    "Hexadecimal",
    "Octal",
    "Float",
    "Double",
    "Wide String",
    "C String",
    "Byte",
    "Char",
    "Boolean",
    "Size",
    "Any"
};

static char *_TOFU_TYPE_INFO[] = {
    "An 8-bit signed integer value",
    "A 16-bit signed integer value",
    "A 32-bit signed integer value",
    "A 64-bit signed integer value",
    "An 8-bit unsigned integer value",
    "A 16-bit unsigned integer value",
    "A 32-bit unsigned integer value",
    "A 64-bit unsigned integer value",
    "A hexadecimal value",
    "An octal value",
    "A single-precision floating point value",
    "A double-precision floating point value",
    "A wide string value",
    "A C string value",
    "A byte value",
    "A character value",
    "A boolean value",
    "A size value",
    "A generic value"
};

fossil_tofu_type_t fossil_tofu_validate_type(const char *type_str) {
    if (type_str == NULL) return FOSSIL_TOFU_TYPE_ANY;

    for (size_t i = 0; i < sizeof(_TOFU_TYPE_ID) / sizeof(_TOFU_TYPE_ID[0]); i++) {
        if (strcmp(type_str, _TOFU_TYPE_ID[i]) == 0) {
            return (fossil_tofu_type_t)i;
        }
    }

    return FOSSIL_TOFU_TYPE_ANY;
}


// *****************************************************************************
// Managment functions
// *****************************************************************************

fossil_tofu_t fossil_tofu_create(char* type, char* value) {
    fossil_tofu_t tofu;
    fossil_tofu_type_t type_enum = fossil_tofu_validate_type(type);

    // Validate type and handle failure
    if (type_enum < FOSSIL_TOFU_TYPE_I8 || type_enum > FOSSIL_TOFU_TYPE_ANY) {
        fprintf(stderr, "Invalid type: %s\n", type);
        tofu.type = FOSSIL_TOFU_TYPE_ANY;
    } else {
        tofu.type = type_enum;
    }

    // Initialize data and check for memory allocation failure
    tofu.value.data = fossil_tofu_strdup(value);
    if (tofu.value.data == NULL) {
        fprintf(stderr, "Memory allocation failed for value.data\n");
        tofu.type = FOSSIL_TOFU_TYPE_ANY; // Set to a safe state if allocation fails
    } else {
        tofu.value.mutable_flag = true;
    }

    // Allocate memory for attributes and check for failures
    tofu.attribute.name = fossil_tofu_strdup(_TOFU_TYPE_NAME[tofu.type]);
    if (tofu.attribute.name == NULL) {
        fprintf(stderr, "Memory allocation failed for attribute.name\n");
        tofu.type = FOSSIL_TOFU_TYPE_ANY; // Set to a safe state if allocation fails
    }

    tofu.attribute.description = fossil_tofu_strdup(_TOFU_TYPE_INFO[tofu.type]);
    if (tofu.attribute.description == NULL) {
        fprintf(stderr, "Memory allocation failed for attribute.description\n");
        tofu.type = FOSSIL_TOFU_TYPE_ANY; // Set to a safe state if allocation fails
    }

    tofu.attribute.id = fossil_tofu_strdup(_TOFU_TYPE_ID[tofu.type]);
    if (tofu.attribute.id == NULL) {
        fprintf(stderr, "Memory allocation failed for attribute.id\n");
        tofu.type = FOSSIL_TOFU_TYPE_ANY; // Set to a safe state if allocation fails
    }

    return tofu;
}

fossil_tofu_t* fossil_tofu_create_default(void) {
    fossil_tofu_t *tofu = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (tofu == NULL) return NULL;

    tofu->type = FOSSIL_TOFU_TYPE_ANY;
    tofu->value.data = fossil_tofu_strdup("");
    tofu->value.mutable_flag = true;

    tofu->attribute.name = fossil_tofu_strdup("Any");
    tofu->attribute.description = fossil_tofu_strdup("A generic value");
    tofu->attribute.id = fossil_tofu_strdup("any");

    return tofu;
}

fossil_tofu_t* fossil_tofu_create_copy(const fossil_tofu_t* other) {
    if (other == NULL) return NULL;

    fossil_tofu_t *tofu = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (tofu == NULL) return NULL;

    tofu->type = other->type;
    tofu->value.data = fossil_tofu_strdup(other->value.data);
    tofu->value.mutable_flag = other->value.mutable_flag;

    tofu->attribute.name = fossil_tofu_strdup(other->attribute.name);
    tofu->attribute.description = fossil_tofu_strdup(other->attribute.description);
    tofu->attribute.id = fossil_tofu_strdup(other->attribute.id);

    return tofu;
}

fossil_tofu_t* fossil_tofu_create_move(fossil_tofu_t* other) {
    if (other == NULL) return NULL;

    fossil_tofu_t *tofu = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (tofu == NULL) return NULL;

    tofu->type = other->type;
    tofu->value.data = other->value.data;
    tofu->value.mutable_flag = other->value.mutable_flag;

    tofu->attribute.name = other->attribute.name;
    tofu->attribute.description = other->attribute.description;
    tofu->attribute.id = other->attribute.id;

    other->type = FOSSIL_TOFU_TYPE_ANY;
    other->value.data = NULL;
    other->value.mutable_flag = false;

    other->attribute.name = NULL;
    other->attribute.description = NULL;
    other->attribute.id = NULL;

    return tofu;
}

void fossil_tofu_destroy(fossil_tofu_t *tofu) {
    if (tofu == NULL) return;
    fossil_tofu_free(tofu->value.data);
    fossil_tofu_free(tofu->attribute.name);
    fossil_tofu_free(tofu->attribute.description);
    fossil_tofu_free(tofu->attribute.id);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int fossil_tofu_set_value(fossil_tofu_t *tofu, char *value) {
    if (tofu == NULL || !tofu->value.mutable_flag) return FOSSIL_TOFU_FAILURE;

    fossil_tofu_free(tofu->value.data);
    tofu->value.data = fossil_tofu_strdup(value);
    return FOSSIL_TOFU_SUCCESS;
}

char* fossil_tofu_get_value(const fossil_tofu_t *tofu) {
    return tofu != NULL ? tofu->value.data : NULL;
}

bool fossil_tofu_is_mutable(const fossil_tofu_t *tofu) {
    return tofu != NULL && tofu->value.mutable_flag;
}

int fossil_tofu_set_mutable(fossil_tofu_t *tofu, bool mutable_flag) {
    if (tofu == NULL) return FOSSIL_TOFU_FAILURE;

    tofu->value.mutable_flag = mutable_flag;
    return FOSSIL_TOFU_SUCCESS;
}

fossil_tofu_type_t fossil_tofu_get_type(const fossil_tofu_t *tofu) {
    return tofu != NULL ? tofu->type : FOSSIL_TOFU_TYPE_ANY;
}

const char* fossil_tofu_type_name(fossil_tofu_type_t type) {
    if (type >= 0 && type < sizeof(_TOFU_TYPE_NAME) / sizeof(_TOFU_TYPE_NAME[0])) {
        return _TOFU_TYPE_NAME[type];
    }
    return "Unknown Type";
}

const char* fossil_tofu_type_info(fossil_tofu_type_t type) {
    if (type >= 0 && type < sizeof(_TOFU_TYPE_INFO) / sizeof(_TOFU_TYPE_INFO[0])) {
        return _TOFU_TYPE_INFO[type];
    }
    return "No type info available.";
}

void fossil_tofu_display(const fossil_tofu_t *tofu) {
    if (tofu == NULL) return;

    printf("Type: %s\n", fossil_tofu_type_name(tofu->type));
    printf("Value: %s\n", tofu->value.data);
    printf("Attribute Name: %s\n", tofu->attribute.name);
    printf("Description: %s\n", tofu->attribute.description);
    printf("ID: %s\n", tofu->attribute.id);
}

int fossil_tofu_set_attribute(fossil_tofu_t *tofu, const char *name, const char *description, const char *id) {
    if (tofu == NULL) return FOSSIL_TOFU_FAILURE;

    fossil_tofu_free(tofu->attribute.name);
    fossil_tofu_free(tofu->attribute.description);
    fossil_tofu_free(tofu->attribute.id);

    tofu->attribute.name = fossil_tofu_strdup(name);
    tofu->attribute.description = fossil_tofu_strdup(description);
    tofu->attribute.id = fossil_tofu_strdup(id);

    return FOSSIL_TOFU_SUCCESS;
}

const fossil_tofu_attribute_t* fossil_tofu_get_attribute(const fossil_tofu_t *tofu) {
    return tofu != NULL ? &tofu->attribute : NULL;
}

bool fossil_tofu_equals(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2) {
    if (tofu1 == NULL || tofu2 == NULL) return false;

    return tofu1->type == tofu2->type &&
           strcmp(tofu1->value.data, tofu2->value.data) == 0;
}

int fossil_tofu_copy(fossil_tofu_t *dest, const fossil_tofu_t *src) {
    if (dest == NULL || src == NULL) return FOSSIL_TOFU_FAILURE;

    dest->type = src->type;
    dest->value.data = fossil_tofu_strdup(src->value.data);
    dest->value.mutable_flag = src->value.mutable_flag;

    dest->attribute.name = fossil_tofu_strdup(src->attribute.name);
    dest->attribute.description = fossil_tofu_strdup(src->attribute.description);
    dest->attribute.id = fossil_tofu_strdup(src->attribute.id);

    return FOSSIL_TOFU_SUCCESS;
}

// *****************************************************************************
// Memory management functions
// *****************************************************************************

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

void fossil_tofu_free(tofu_memory_t ptr) {
    if (ptr) {
        free(ptr);
    }
} // end of fun

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
