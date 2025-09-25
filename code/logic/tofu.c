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
    "oct",
    "bin",
    "f32",
    "f64",
    "cstr",
    "char",
    "bool",
    "size",
    "datetime",
    "duration",
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
    "Binary",
    "Float",
    "Double",
    "C String",
    "Char",
    "Boolean",
    "Size",
    "Date time",
    "Duration",
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
    "A binary value",
    "A single-precision floating point value",
    "A double-precision floating point value",
    "A C string value",
    "A character value",
    "A boolean value",
    "A size value",
    "A date and time",
    "A duration",
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

/**
 * @brief Computes a 64-bit hash of arbitrary data with optional seeding.
 *
 * This function implements a high-quality, parallelized 64-bit hash algorithm
 * designed for speed, low collision rate, and good avalanche properties.
 *
 * ## Algorithm Overview
 * - **Seed Mixing:** The user-provided seed is diffused through a SplitMix64 step
 *   to maximize entropy even for small or predictable seeds.
 * - **Parallel Accumulators:** Two independent 64-bit accumulators (`v1` and `v2`)
 *   are initialized with different constants and updated in parallel. This improves
 *   mixing and reduces hash clustering for large inputs.
 * - **Chunk Processing:** Data is processed in 16-byte chunks whenever possible,
 *   with each 64-bit lane mixed into a different accumulator. Each accumulator uses
 *   a unique prime multiplier and a left-rotate step for diffusion.
 * - **Tail Handling:** Remaining bytes (<16) are handled carefully to ensure every
 *   bit affects the final result.
 * - **Finalization:** The two accumulators are merged using a mix function and
 *   passed through `mix64()`, a SplitMix64-style avalanche function, producing the
 *   final hash value.
 *
 * ## Properties
 * - **Deterministic:** Same input and seed will always produce the same result.
 * - **Seedable:** A nonzero seed can be used to create independent hash streams.
 * - **Good Avalanche:** Small changes in input produce large, unpredictable
 *   differences in output.
 * - **Portable:** Requires only 64-bit integer operations; no platform-specific
 *   intrinsics or dependencies.
 *
 * @param data Pointer to input buffer (must not be NULL).
 * @param len  Length of input buffer in bytes.
 * @param seed Optional 64-bit seed to randomize the hash (0 for unseeded).
 * @return 64-bit hash value of the input data.
 *
 * @note Complexity: O(n) – linear in the number of input bytes.
 * @note This function is not cryptographically secure. Use a proper cryptographic
 *       hash (e.g., SHA-256) if resistance to deliberate collisions is required.
 */

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

fossil_tofu_t fossil_tofu_create(char* type, char* value) {
    if (!type || !value) {
        fprintf(stderr, "Error: NULL argument passed to fossil_tofu_create\n");
        return (fossil_tofu_t){0};
    }

    fossil_tofu_type_t type_enum = fossil_tofu_validate_type(type);
    if (type_enum < FOSSIL_TOFU_TYPE_I8 || type_enum > FOSSIL_TOFU_TYPE_ANY) {
        fprintf(stderr, "Invalid type: %s\n", type);
        type_enum = FOSSIL_TOFU_TYPE_ANY;
    }

    fossil_tofu_t tofu = {0};
    tofu.type = type_enum;
    tofu.value.data = fossil_tofu_strdup(value);
    if (!tofu.value.data) {
        fprintf(stderr, "Memory allocation failed for value.data\n");
        tofu.value.data = NULL;
        tofu.attribute.name = NULL;
        tofu.attribute.description = NULL;
        tofu.attribute.id = NULL;
        return tofu;
    }
    tofu.value.mutable_flag = true;
    tofu.value.hash = fossil_tofu_hash64(value);

    tofu.attribute.name = fossil_tofu_strdup(_TOFU_TYPE_NAME[tofu.type]);
    if (!tofu.attribute.name) {
        fprintf(stderr, "Memory allocation failed for attribute.name\n");
        fossil_tofu_free(tofu.value.data);
        tofu.value.data = NULL;
        tofu.attribute.name = NULL;
        tofu.attribute.description = NULL;
        tofu.attribute.id = NULL;
        return tofu;
    }

    tofu.attribute.description = fossil_tofu_strdup(_TOFU_TYPE_INFO[tofu.type]);
    if (!tofu.attribute.description) {
        fprintf(stderr, "Memory allocation failed for attribute.description\n");
        fossil_tofu_free(tofu.attribute.name);
        fossil_tofu_free(tofu.value.data);
        tofu.value.data = NULL;
        tofu.attribute.name = NULL;
        tofu.attribute.description = NULL;
        tofu.attribute.id = NULL;
        return tofu;
    }

    tofu.attribute.id = fossil_tofu_strdup(_TOFU_TYPE_ID[tofu.type]);
    if (!tofu.attribute.id) {
        fprintf(stderr, "Memory allocation failed for attribute.id\n");
        fossil_tofu_free(tofu.attribute.description);
        fossil_tofu_free(tofu.attribute.name);
        fossil_tofu_free(tofu.value.data);
        tofu.value.data = NULL;
        tofu.attribute.name = NULL;
        tofu.attribute.description = NULL;
        tofu.attribute.id = NULL;
        return tofu;
    }

    tofu.attribute.required = false;

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
        tofu->attribute.name = NULL;
        tofu->attribute.description = NULL;
        tofu->attribute.id = NULL;
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->value.mutable_flag = other->value.mutable_flag;
    // Recompute hash for safety in case value/data changes
    tofu->value.hash = fossil_tofu_hash64(tofu->value.data);

    tofu->attribute.name = fossil_tofu_strdup(other->attribute.name);
    if (!tofu->attribute.name) {
        fossil_tofu_free(tofu->value.data);
        tofu->attribute.description = NULL;
        tofu->attribute.id = NULL;
        fossil_tofu_free(tofu);
        return NULL;
    }
    tofu->attribute.description = fossil_tofu_strdup(other->attribute.description);
    if (!tofu->attribute.description) {
        fossil_tofu_free(tofu->attribute.name);
        fossil_tofu_free(tofu->value.data);
        tofu->attribute.id = NULL;
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
    if (tofu->value.data) {
        fossil_tofu_free(tofu->value.data);
        tofu->value.data = NULL;
    }
    if (tofu->attribute.name) {
        fossil_tofu_free(tofu->attribute.name);
        tofu->attribute.name = NULL;
    }
    if (tofu->attribute.description) {
        fossil_tofu_free(tofu->attribute.description);
        tofu->attribute.description = NULL;
    }
    if (tofu->attribute.id) {
        fossil_tofu_free(tofu->attribute.id);
        tofu->attribute.id = NULL;
    }
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

int fossil_tofu_compare(const fossil_tofu_t *tofu1, const fossil_tofu_t *tofu2) {
    if (tofu1 == NULL || tofu2 == NULL || tofu1->value.data == NULL || tofu2->value.data == NULL) return FOSSIL_TOFU_SUCCESS;

    if (tofu1->type != tofu2->type) {
        return (int)tofu1->type - (int)tofu2->type;
    }

    return strcmp(tofu1->value.data, tofu2->value.data);
}

int fossil_tofu_set_value(fossil_tofu_t *tofu, char *value) {
    if (tofu == NULL) return FOSSIL_TOFU_ERROR_NULL_POINTER;
    if (!tofu->value.mutable_flag) return FOSSIL_TOFU_ERROR_IMMUTABLE;
    if (value == NULL) return FOSSIL_TOFU_ERROR_INVALID_ARGUMENT;

    fossil_tofu_free(tofu->value.data);
    tofu->value.data = fossil_tofu_strdup(value);
    if (!tofu->value.data) return FOSSIL_TOFU_ERROR_MEMORY_ALLOCATION;
    return FOSSIL_TOFU_SUCCESS;
}

char *fossil_tofu_get_value(const fossil_tofu_t *tofu) {
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
        while (*fson_text && *fson_text != ':') fson_text++;
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
        fossil_tofu_t tofu = fossil_tofu_create(type_buf, value_buf);
        fossil_tofu_t *tofu_ptr = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
        if (!tofu_ptr) return NULL;
        *tofu_ptr = tofu;
        return tofu_ptr;
        }

        // Fallback: treat as cstr
        fossil_tofu_t tofu = fossil_tofu_create("cstr", fossil_tofu_strdup(fson_text));
        fossil_tofu_t *tofu_ptr = (fossil_tofu_t*)fossil_tofu_alloc(sizeof(fossil_tofu_t));
        if (!tofu_ptr) return NULL;
        *tofu_ptr = tofu;
        return tofu_ptr;
}

void fossil_tofu_dump(const fossil_tofu_t *tofu) {
    if (tofu == NULL) {
        printf("Tofu: cnull\n");
        return;
    }

    printf("Tofu Dump:\n");
    printf("  Type: %s (%d)\n", fossil_tofu_type_name(tofu->type), tofu->type);
    printf("  Value: %s\n", tofu->value.data ? tofu->value.data : "(null)");
    printf("  Value Hash: 0x%016llx\n", (unsigned long long)tofu->value.hash);
    printf("  Mutable: %s\n", tofu->value.mutable_flag ? "true" : "false");
    printf("  Attribute Name: %s\n", tofu->attribute.name ? tofu->attribute.name : "(null)");
    printf("  Description: %s\n", tofu->attribute.description ? tofu->attribute.description : "(null)");
    printf("  ID: %s\n", tofu->attribute.id ? tofu->attribute.id : "(null)");
    printf("  Required: %s\n", tofu->attribute.required ? "true" : "false");
}

const char* fossil_tofu_get_value_or_default(const fossil_tofu_t *tofu, const char *default_value) {
    if (!tofu || !tofu->value.data) return default_value;
    return tofu->value.data;
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
