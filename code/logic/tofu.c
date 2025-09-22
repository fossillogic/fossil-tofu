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
    "cstr",
    "cchar",
    "bool",
    "size",
    "blob",
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
    "C String",
    "Char",
    "Boolean",
    "Size",
    "Blob",
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
    "A C string value",
    "A character value",
    "A boolean value",
    "A size value",
    "Arbitrary binary data",
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

static inline uint64_t mix64(uint64_t x) {
    x ^= x >> 30;
    x *= 0xbf58476d1ce4e5b9ULL;
    x ^= x >> 27;
    x *= 0x94d049bb133111ebULL;
    x ^= x >> 31;
    return x;
}

uint64_t fossil_tofu_hash64_seed(const void *data, size_t len, uint64_t seed) {
    if (!data) return 0;
    const uint8_t *ptr = (const uint8_t *)data;

    // FNV-1a base but seeded
    uint64_t hash = seed ^ 14695981039346656037ULL;

    for (size_t i = 0; i < len; i++) {
        hash ^= ptr[i];
        hash *= 1099511628211ULL;
        hash ^= (hash >> 47);
        hash += (hash << 13);
        hash ^= (hash >> 31);
    }

    // Stronger finalization (SplitMix64)
    return mix64(hash);
}

uint64_t fossil_tofu_hash64(const char *data) {
    if (!data) return 0;
    size_t len = 0;
    while (data[len]) len++;
    return fossil_tofu_hash64_seed(data, len, 0);
}

// *****************************************************************************
// Managment functions
// *****************************************************************************

fossil_tofu_t* fossil_tofu_create(const char* type, const char* value) {
    if (!type || !value) {
        fprintf(stderr, "Error: NULL argument passed to fossil_tofu_create\n");
        return NULL;
    }

    fossil_tofu_type_t type_enum = fossil_tofu_validate_type(type);
    if (type_enum < FOSSIL_TOFU_TYPE_I8 || type_enum > FOSSIL_TOFU_TYPE_ANY) {
        fprintf(stderr, "Invalid type: %s\n", type);
        type_enum = FOSSIL_TOFU_TYPE_ANY;
    }

    fossil_tofu_t* tofu = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (!tofu) {
        fprintf(stderr, "Memory allocation failed for tofu\n");
        return NULL;
    }

    tofu->type = type_enum;
    tofu->value.data = fossil_tofu_strdup(value);
    if (!tofu->value.data) {
        fprintf(stderr, "Memory allocation failed for value.data\n");
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->value.mutable_flag = true;
    tofu->value.hash = fossil_tofu_hash64(value);

    tofu->attribute.name = fossil_tofu_strdup(_TOFU_TYPE_NAME[tofu->type]);
    if (!tofu->attribute.name) {
        fprintf(stderr, "Memory allocation failed for attribute.name\n");
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }

    tofu->attribute.description = fossil_tofu_strdup(_TOFU_TYPE_INFO[tofu->type]);
    if (!tofu->attribute.description) {
        fprintf(stderr, "Memory allocation failed for attribute.description\n");
        fossil_tofu_free(tofu->attribute.name);
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }

    tofu->attribute.id = fossil_tofu_strdup(_TOFU_TYPE_ID[tofu->type]);
    if (!tofu->attribute.id) {
        fprintf(stderr, "Memory allocation failed for attribute.id\n");
        fossil_tofu_free(tofu->attribute.description);
        fossil_tofu_free(tofu->attribute.name);
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }

    tofu->attribute.required = false;

    return tofu;
}

fossil_tofu_t* fossil_tofu_create_default(void) {
    fossil_tofu_t *tofu = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (tofu == NULL) return NULL;

    tofu->type = FOSSIL_TOFU_TYPE_ANY;
    tofu->value.data = fossil_tofu_strdup("");
    if (!tofu->value.data) {
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->value.mutable_flag = true;
    tofu->value.hash = fossil_tofu_hash64(tofu->value.data);

    tofu->attribute.name = fossil_tofu_strdup(_TOFU_TYPE_NAME[FOSSIL_TOFU_TYPE_ANY]);
    if (!tofu->attribute.name) {
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->attribute.description = fossil_tofu_strdup(_TOFU_TYPE_INFO[FOSSIL_TOFU_TYPE_ANY]);
    if (!tofu->attribute.description) {
        fossil_tofu_free(tofu->attribute.name);
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->attribute.id = fossil_tofu_strdup(_TOFU_TYPE_ID[FOSSIL_TOFU_TYPE_ANY]);
    if (!tofu->attribute.id) {
        fossil_tofu_free(tofu->attribute.description);
        fossil_tofu_free(tofu->attribute.name);
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->attribute.required = false;

    return tofu;
}

fossil_tofu_t* fossil_tofu_create_copy(const fossil_tofu_t* other) {
    if (other == NULL) return NULL;

    fossil_tofu_t *tofu = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (tofu == NULL) return NULL;

    tofu->type = other->type;
    tofu->value.data = fossil_tofu_strdup(other->value.data);
    if (!tofu->value.data) {
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->value.mutable_flag = other->value.mutable_flag;
    // Recompute hash for safety in case value/data changes
    tofu->value.hash = fossil_tofu_hash64(tofu->value.data);

    tofu->attribute.name = fossil_tofu_strdup(other->attribute.name);
    if (!tofu->attribute.name) {
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->attribute.description = fossil_tofu_strdup(other->attribute.description);
    if (!tofu->attribute.description) {
        fossil_tofu_free(tofu->attribute.name);
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->attribute.id = fossil_tofu_strdup(other->attribute.id);
    if (!tofu->attribute.id) {
        fossil_tofu_free(tofu->attribute.description);
        fossil_tofu_free(tofu->attribute.name);
        fossil_tofu_free(tofu->value.data);
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->attribute.required = other->attribute.required;

    return tofu;
}

fossil_tofu_t* fossil_tofu_create_move(fossil_tofu_t* other) {
    if (other == NULL) return NULL;

    fossil_tofu_t *tofu = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (tofu == NULL) return NULL;

    // Move value fields
    tofu->type = other->type;
    tofu->value.data = other->value.data;
    tofu->value.mutable_flag = other->value.mutable_flag;
    tofu->value.hash = other->value.hash;

    // Move attribute fields
    tofu->attribute.name = other->attribute.name;
    tofu->attribute.description = other->attribute.description;
    tofu->attribute.id = other->attribute.id;
    tofu->attribute.required = other->attribute.required;

    // Invalidate the source object (zero out pointers and fields)
    other->type = FOSSIL_TOFU_TYPE_ANY;
    other->value.data = NULL;
    other->value.mutable_flag = false;
    other->value.hash = 0;

    other->attribute.name = NULL;
    other->attribute.description = NULL;
    other->attribute.id = NULL;
    other->attribute.required = false;

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

int fossil_tofu_set_value(fossil_tofu_t *tofu, const char *value) {
    if (tofu == NULL) return FOSSIL_TOFU_ERROR_NULL_POINTER;
    if (!tofu->value.mutable_flag) return FOSSIL_TOFU_ERROR_IMMUTABLE;
    if (value == NULL) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;

    fossil_tofu_free(tofu->value.data);
    tofu->value.data = fossil_tofu_strdup(value);
    if (!tofu->value.data) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    return FOSSIL_TOFU_SUCCESS;
}

const char* fossil_tofu_get_value(const fossil_tofu_t *tofu) {
    if (tofu == NULL) return NULL;
    return tofu->value.data;
}

bool fossil_tofu_is_mutable(const fossil_tofu_t *tofu) {
    return tofu != NULL && tofu->value.mutable_flag;
}

int fossil_tofu_set_mutable(fossil_tofu_t *tofu, bool mutable_flag) {
    if (tofu == NULL) return FOSSIL_TOFU_ERROR_NULL_POINTER;
    tofu->value.mutable_flag = mutable_flag;
    return FOSSIL_TOFU_SUCCESS;
}

fossil_tofu_type_t fossil_tofu_get_type(const fossil_tofu_t *tofu) {
    return tofu != NULL ? tofu->type : FOSSIL_TOFU_TYPE_ANY;
}

const char* fossil_tofu_type_name(fossil_tofu_type_t type) {
    if (type >= 0 && type < (sizeof(_TOFU_TYPE_NAME) / sizeof(_TOFU_TYPE_NAME[0]))) {
        return _TOFU_TYPE_NAME[type];
    }
    return "Unknown Type";
}

const char* fossil_tofu_type_info(fossil_tofu_type_t type) {
    if (type >= 0 && type < (sizeof(_TOFU_TYPE_INFO) / sizeof(_TOFU_TYPE_INFO[0]))) {
        return _TOFU_TYPE_INFO[type];
    }
    return "No type info available.";
}

void fossil_tofu_display(const fossil_tofu_t *tofu) {
    if (tofu == NULL) return;

    printf("Type: %s\n", fossil_tofu_type_name(tofu->type));
    printf("Value: %s\n", tofu->value.data ? tofu->value.data : "(null)");
    printf("Attribute Name: %s\n", tofu->attribute.name ? tofu->attribute.name : "(null)");
    printf("Description: %s\n", tofu->attribute.description ? tofu->attribute.description : "(null)");
    printf("ID: %s\n", tofu->attribute.id ? tofu->attribute.id : "(null)");
}

int fossil_tofu_set_attribute(fossil_tofu_t *tofu, const char *name, const char *description, const char *id) {
    if (tofu == NULL) return FOSSIL_TOFU_ERROR_NULL_POINTER;

    fossil_tofu_free(tofu->attribute.name);
    fossil_tofu_free(tofu->attribute.description);
    fossil_tofu_free(tofu->attribute.id);

    tofu->attribute.name = fossil_tofu_strdup(name);
    if (!tofu->attribute.name) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    tofu->attribute.description = fossil_tofu_strdup(description);
    if (!tofu->attribute.description) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    tofu->attribute.id = fossil_tofu_strdup(id);
    if (!tofu->attribute.id) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;

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
    if (dest == NULL || src == NULL) return FOSSIL_TOFU_ERROR_NULL_POINTER;

    // Free existing strings in dest to avoid memory leaks
    fossil_tofu_free(dest->value.data);
    fossil_tofu_free(dest->attribute.name);
    fossil_tofu_free(dest->attribute.description);
    fossil_tofu_free(dest->attribute.id);

    dest->type = src->type;

    dest->value.data = fossil_tofu_strdup(src->value.data);
    if (!dest->value.data && src->value.data)
        return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    dest->value.mutable_flag = src->value.mutable_flag;
    // Recompute hash for safety in case value/data changes
    dest->value.hash = fossil_tofu_hash64(dest->value.data);

    dest->attribute.name = fossil_tofu_strdup(src->attribute.name);
    if (!dest->attribute.name && src->attribute.name)
        return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    dest->attribute.description = fossil_tofu_strdup(src->attribute.description);
    if (!dest->attribute.description && src->attribute.description)
        return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    dest->attribute.id = fossil_tofu_strdup(src->attribute.id);
    if (!dest->attribute.id && src->attribute.id)
        return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    dest->attribute.required = src->attribute.required;

    return FOSSIL_TOFU_SUCCESS;
}

// *****************************************************************************
// Extended API
// *****************************************************************************

bool fossil_tofu_hash_equals(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2) {
    if (!tofu1 || !tofu2) return false;
    return fossil_tofu_hash(tofu1) == fossil_tofu_hash(tofu2);
}

char* fossil_tofu_serialize(const fossil_tofu_t *tofu) {
    if (!tofu) return NULL;

    // FSON format: key: type: value, plus attributes as subkeys
    // Example:
    // {
    //   value: TYPE: VALUE,
    //   attr: object: {
    //     name: cstr: "NAME",
    //     description: cstr: "DESC",
    //     id: cstr: "ID",
    //     mutable: bool: true
    //   }
    // }
    const char *type_id = fossil_tofu_type_name(tofu->type);
    if (!type_id) type_id = "any";

    const char *val = tofu->value.data ? tofu->value.data : "";
    const char *name = tofu->attribute.name ? tofu->attribute.name : "";
    const char *desc = tofu->attribute.description ? tofu->attribute.description : "";
    const char *id = tofu->attribute.id ? tofu->attribute.id : "";

    // Estimate buffer size
    size_t buf_size = strlen(type_id) + strlen(val) + strlen(name) + strlen(desc) + strlen(id) + 256;
    char *fson = (char *)malloc(buf_size);
    if (!fson) return NULL;

    snprintf(fson, buf_size,
        "{\n"
        "  value: %s: \"%s\",\n"
        "  attr: object: {\n"
        "    name: cstr: \"%s\",\n"
        "    description: cstr: \"%s\",\n"
        "    id: cstr: \"%s\",\n"
        "    mutable: bool: %s\n"
        "  }\n"
        "}",
        type_id, val, name, desc, id, tofu->value.mutable_flag ? "true" : "false"
    );

    return fson;
}

fossil_tofu_t* fossil_tofu_parse(const char *fson_text) {
    if (!fson_text) return NULL;

    // Skip whitespace
    while (isspace((unsigned char)*fson_text)) fson_text++;

    // Only support simple FSON object: { key: type: value, ... }
    if (*fson_text == '{') {
        fson_text++;
        while (isspace((unsigned char)*fson_text)) fson_text++;

        // Parse first key: type: value
        const char *key_start = fson_text;
        while (*fson_text && *fson_text != ':') fson_text++;
        size_t key_len = fson_text - key_start;
        if (*fson_text != ':') return NULL;
        fson_text++; // skip ':'

        while (isspace((unsigned char)*fson_text)) fson_text++;
        const char *type_start = fson_text;
        while (*fson_text && *fson_text != ':') fson_text++;
        size_t type_len = fson_text - type_start;
        if (*fson_text != ':') return NULL;
        fson_text++; // skip ':'

        while (isspace((unsigned char)*fson_text)) fson_text++;
        const char *value_start = fson_text;
        char value_buf[128] = {0};
        char type_buf[32] = {0};

        // If value is quoted string
        if (*fson_text == '"') {
            fson_text++;
            const char *str_start = fson_text;
            while (*fson_text && *fson_text != '"') fson_text++;
            size_t str_len = fson_text - str_start;
            if (str_len >= sizeof(value_buf)) str_len = sizeof(value_buf) - 1;
            strncpy(value_buf, str_start, str_len);
            value_buf[str_len] = '\0';
            if (*fson_text == '"') fson_text++;
        } else {
            // Read until ',' or '}'
            const char *val_end = fson_text;
            while (*val_end && *val_end != ',' && *val_end != '}') val_end++;
            size_t val_len = val_end - value_start;
            if (val_len >= sizeof(value_buf)) val_len = sizeof(value_buf) - 1;
            strncpy(value_buf, value_start, val_len);
            value_buf[val_len] = '\0';
            fson_text = val_end;
        }

        // Copy type
        if (type_len >= sizeof(type_buf)) type_len = sizeof(type_buf) - 1;
        strncpy(type_buf, type_start, type_len);
        type_buf[type_len] = '\0';

        // Create tofu object
        fossil_tofu_t *tofu = fossil_tofu_create(type_buf, value_buf);
        return tofu;
    }

    // Fallback: treat as cstr
    fossil_tofu_t *tofu = fossil_tofu_create("cstr", fson_text);
    return tofu;
}

int fossil_tofu_convert_type(fossil_tofu_t *tofu, fossil_tofu_type_t new_type) {
    if (!tofu || !tofu->value.data) return FOSSIL_TOFU_ERROR_NULL_POINTER;

    char *endptr = NULL;
    char buf[64];
    switch (new_type) {
        case FOSSIL_TOFU_TYPE_I8: {
            long v = strtol(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v < INT8_MIN) return FOSSIL_TOFU_ERROR_UNDERFLOW;
            if (v > INT8_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            snprintf(buf, sizeof(buf), "%d", (int8_t)v);
            break;
        }
        case FOSSIL_TOFU_TYPE_I16: {
            long v = strtol(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v < INT16_MIN) return FOSSIL_TOFU_ERROR_UNDERFLOW;
            if (v > INT16_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            snprintf(buf, sizeof(buf), "%d", (int16_t)v);
            break;
        }
        case FOSSIL_TOFU_TYPE_I32: {
            long v = strtol(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v < INT32_MIN) return FOSSIL_TOFU_ERROR_UNDERFLOW;
            if (v > INT32_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            snprintf(buf, sizeof(buf), "%d", (int32_t)v);
            break;
        }
        case FOSSIL_TOFU_TYPE_I64: {
            long long v = strtoll(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            snprintf(buf, sizeof(buf), "%lld", v);
            break;
        }
        case FOSSIL_TOFU_TYPE_U8: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v > UINT8_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            snprintf(buf, sizeof(buf), "%u", (uint8_t)v);
            break;
        }
        case FOSSIL_TOFU_TYPE_U16: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v > UINT16_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            snprintf(buf, sizeof(buf), "%u", (uint16_t)v);
            break;
        }
        case FOSSIL_TOFU_TYPE_U32: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v > UINT32_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            snprintf(buf, sizeof(buf), "%u", (uint32_t)v);
            break;
        }
        case FOSSIL_TOFU_TYPE_U64: {
            unsigned long long v = strtoull(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            snprintf(buf, sizeof(buf), "%llu", v);
            break;
        }
        case FOSSIL_TOFU_TYPE_HEX: {
            unsigned long long v = strtoull(tofu->value.data, &endptr, 16);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            snprintf(buf, sizeof(buf), "%llx", v);
            break;
        }
        case FOSSIL_TOFU_TYPE_OCTAL: {
            unsigned long long v = strtoull(tofu->value.data, &endptr, 8);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            snprintf(buf, sizeof(buf), "%llo", v);
            break;
        }
        case FOSSIL_TOFU_TYPE_FLOAT: {
            float f = strtof(tofu->value.data, &endptr);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            snprintf(buf, sizeof(buf), "%.7g", f);
            break;
        }
        case FOSSIL_TOFU_TYPE_DOUBLE: {
            double d = strtod(tofu->value.data, &endptr);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            snprintf(buf, sizeof(buf), "%.17g", d);
            break;
        }
        case FOSSIL_TOFU_TYPE_BOOL: {
            if (strcmp(tofu->value.data, "true") == 0 || strcmp(tofu->value.data, "1") == 0)
                strcpy(buf, "true");
            else if (strcmp(tofu->value.data, "false") == 0 || strcmp(tofu->value.data, "0") == 0)
                strcpy(buf, "false");
            else return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_CSTR: {
            strncpy(buf, tofu->value.data, sizeof(buf) - 1);
            buf[sizeof(buf) - 1] = '\0';
            break;
        }
        case FOSSIL_TOFU_TYPE_CCHAR: {
            if (strlen(tofu->value.data) != 1) return FOSSIL_TOFU_ERROR_TYPE_MISMATCH;
            buf[0] = tofu->value.data[0];
            buf[1] = '\0';
            break;
        }
        case FOSSIL_TOFU_TYPE_SIZE: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            snprintf(buf, sizeof(buf), "%zu", (size_t)v);
            break;
        }
        default:
            return FOSSIL_TOFU_ERROR_UNSUPPORTED;
    }

    fossil_tofu_free(tofu->value.data);
    tofu->value.data = fossil_tofu_strdup(buf);
    if (!tofu->value.data) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    tofu->type = new_type;
    tofu->value.hash = fossil_tofu_hash(tofu);
    return FOSSIL_TOFU_SUCCESS;
}

const char* fossil_tofu_get_value_or_default(const fossil_tofu_t *tofu, const char *default_value) {
    if (!tofu || !tofu->value.data) return default_value;
    return tofu->value.data;
}

int fossil_tofu_validate(const fossil_tofu_t *tofu) {
    if (!tofu) return FOSSIL_TOFU_ERROR_NULL_POINTER;
    if (!tofu->value.data) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;

    char *endptr = NULL;

    switch (tofu->type) {
        case FOSSIL_TOFU_TYPE_I8: {
            long v = strtol(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v < INT8_MIN) return FOSSIL_TOFU_ERROR_UNDERFLOW;
            if (v > INT8_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            break;
        }
        case FOSSIL_TOFU_TYPE_I16: {
            long v = strtol(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v < INT16_MIN) return FOSSIL_TOFU_ERROR_UNDERFLOW;
            if (v > INT16_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            break;
        }
        case FOSSIL_TOFU_TYPE_I32: {
            long v = strtol(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v < INT32_MIN) return FOSSIL_TOFU_ERROR_UNDERFLOW;
            if (v > INT32_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            break;
        }
        case FOSSIL_TOFU_TYPE_I64: {
            long long v = strtoll(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_U8: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v > UINT8_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            break;
        }
        case FOSSIL_TOFU_TYPE_U16: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v > UINT16_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            break;
        }
        case FOSSIL_TOFU_TYPE_U32: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            if (v > UINT32_MAX) return FOSSIL_TOFU_ERROR_OVERFLOW;
            break;
        }
        case FOSSIL_TOFU_TYPE_U64: {
            unsigned long long v = strtoull(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_HEX: {
            unsigned long long v = strtoull(tofu->value.data, &endptr, 16);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_OCTAL: {
            unsigned long long v = strtoull(tofu->value.data, &endptr, 8);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_FLOAT: {
            float f = strtof(tofu->value.data, &endptr);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_DOUBLE: {
            double d = strtod(tofu->value.data, &endptr);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_BOOL: {
            if (strcmp(tofu->value.data, "true") != 0 &&
                strcmp(tofu->value.data, "false") != 0)
                return FOSSIL_TOFU_ERROR_TYPE_MISMATCH;
            break;
        }
        case FOSSIL_TOFU_TYPE_CSTR: {
            // Always valid for CSTR
            break;
        }
        case FOSSIL_TOFU_TYPE_CCHAR: {
            if (strlen(tofu->value.data) != 1)
                return FOSSIL_TOFU_ERROR_TYPE_MISMATCH;
            break;
        }
        case FOSSIL_TOFU_TYPE_SIZE: {
            unsigned long v = strtoul(tofu->value.data, &endptr, 10);
            if (*endptr != '\0') return FOSSIL_TOFU_ERROR_PARSE;
            break;
        }
        case FOSSIL_TOFU_TYPE_BLOB:
        case FOSSIL_TOFU_TYPE_ANY:
            // No validation for blob/any
            break;
        default:
            return FOSSIL_TOFU_ERROR_UNSUPPORTED;
    }

    return FOSSIL_TOFU_SUCCESS;
}

bool fossil_tofu_is_empty(const fossil_tofu_t *tofu) {
    return (!tofu || !tofu->value.data || tofu->value.data[0] == '\0');
}

fossil_tofu_t* fossil_tofu_clone(const fossil_tofu_t *tofu) {
    if (!tofu) return NULL;

    fossil_tofu_t *clone = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
    if (!clone) return NULL;

    clone->type = tofu->type;
    clone->value.data = tofu->value.data ? fossil_tofu_strdup(tofu->value.data) : NULL;
    clone->value.mutable_flag = tofu->value.mutable_flag;
    clone->value.hash = tofu->value.hash;

    clone->attribute.name = tofu->attribute.name ? fossil_tofu_strdup(tofu->attribute.name) : NULL;
    clone->attribute.description = tofu->attribute.description ? fossil_tofu_strdup(tofu->attribute.description) : NULL;
    clone->attribute.id = tofu->attribute.id ? fossil_tofu_strdup(tofu->attribute.id) : NULL;
    clone->attribute.required = tofu->attribute.required;

    return clone;
}

int fossil_tofu_lock(fossil_tofu_t *tofu) {
    if (!tofu) return FOSSIL_TOFU_ERROR_NULL_POINTER;
    tofu->value.mutable_flag = false;
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
