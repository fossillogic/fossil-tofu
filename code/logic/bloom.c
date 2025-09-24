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
#include "fossil/tofu/bloom.h"
#include <math.h>

// *****************************************************************************
// Internal helpers
// *****************************************************************************

static inline void fossil_bloom_set_bit(uint8_t *array, size_t index) {
    array[index >> 3] |= (1u << (index & 7));
}

static inline bool fossil_bloom_get_bit(const uint8_t *array, size_t index) {
    return (array[index >> 3] & (1u << (index & 7))) != 0;
}

static inline size_t fossil_bloom_optimal_bit_count(size_t n, double p) {
    // m = -(n * ln(p)) / (ln(2)^2)
    return (size_t)ceil(-(double)n * log(p) / (log(2.0) * log(2.0)));
}

static inline size_t fossil_bloom_optimal_hash_count(size_t m, size_t n) {
    // k = (m / n) * ln(2)
    return (size_t)ceil(((double)m / (double)n) * log(2.0));
}

// *****************************************************************************
// Implementation
// *****************************************************************************

fossil_bloom_t* fossil_bloom_create(size_t capacity, double false_positive_rate) {
    if (capacity == 0 || false_positive_rate <= 0.0 || false_positive_rate >= 1.0)
        return NULL;

    fossil_bloom_t* bloom = (fossil_bloom_t*)calloc(1, sizeof(fossil_bloom_t));
    if (!bloom) return NULL;

    bloom->bit_count = fossil_bloom_optimal_bit_count(capacity, false_positive_rate);
    bloom->hash_count = fossil_bloom_optimal_hash_count(bloom->bit_count, capacity);
    bloom->item_count = 0;

    size_t byte_count = (bloom->bit_count + 7) / 8;
    bloom->bit_array = (uint8_t*)calloc(byte_count, 1);
    if (!bloom->bit_array) {
        free(bloom);
        return NULL;
    }

    return bloom;
}

fossil_bloom_t* fossil_bloom_create_copy(const fossil_bloom_t* other) {
    if (!other) return NULL;

    fossil_bloom_t* copy = (fossil_bloom_t*)calloc(1, sizeof(fossil_bloom_t));
    if (!copy) return NULL;

    *copy = *other;
    size_t byte_count = (other->bit_count + 7) / 8;
    copy->bit_array = (uint8_t*)malloc(byte_count);
    if (!copy->bit_array) {
        free(copy);
        return NULL;
    }
    memcpy(copy->bit_array, other->bit_array, byte_count);
    return copy;
}

fossil_bloom_t* fossil_bloom_create_move(fossil_bloom_t* other) {
    if (!other) return NULL;
    fossil_bloom_t* moved = (fossil_bloom_t*)malloc(sizeof(fossil_bloom_t));
    if (!moved) return NULL;

    *moved = *other;
    memset(other, 0, sizeof(fossil_bloom_t));  // leave source empty
    return moved;
}

void fossil_bloom_destroy(fossil_bloom_t* bloom) {
    if (!bloom) return;
    free(bloom->bit_array);
    free(bloom);
}

int32_t fossil_bloom_insert(fossil_bloom_t* bloom, const void* key, size_t key_len) {
    if (!bloom || !key || key_len == 0) return FOSSIL_BLOOM_ERROR_INVALID_ARGUMENT;

    uint64_t hash1 = fossil_tofu_hash64_seed(key, key_len, 0x12345678ULL);
    uint64_t hash2 = fossil_tofu_hash64_seed(key, key_len, 0x87654321ULL);

    for (size_t i = 0; i < bloom->hash_count; i++) {
        uint64_t combined = hash1 + i * hash2;
        size_t index = combined % bloom->bit_count;
        fossil_bloom_set_bit(bloom->bit_array, index);
    }

    bloom->item_count++;
    return FOSSIL_BLOOM_SUCCESS;
}

bool fossil_bloom_contains(const fossil_bloom_t* bloom, const void* key, size_t key_len) {
    if (!bloom || !key || key_len == 0) return false;

    uint64_t hash1 = fossil_tofu_hash64_seed(key, key_len, 0x12345678ULL);
    uint64_t hash2 = fossil_tofu_hash64_seed(key, key_len, 0x87654321ULL);

    for (size_t i = 0; i < bloom->hash_count; i++) {
        uint64_t combined = hash1 + i * hash2;
        size_t index = combined % bloom->bit_count;
        if (!fossil_bloom_get_bit(bloom->bit_array, index))
            return false;  // Definitely not present
    }

    return true;  // Probably present
}

size_t fossil_bloom_count(const fossil_bloom_t* bloom) {
    return bloom ? bloom->item_count : 0;
}

void fossil_bloom_clear(fossil_bloom_t* bloom) {
    if (!bloom) return;
    size_t byte_count = (bloom->bit_count + 7) / 8;
    memset(bloom->bit_array, 0, byte_count);
    bloom->item_count = 0;
}

void fossil_bloom_dump(const fossil_bloom_t* bloom) {
    if (!bloom) return;
    printf("Bloom Filter:\n");
    printf("  Bits: %zu\n", bloom->bit_count);
    printf("  Hash functions: %zu\n", bloom->hash_count);
    printf("  Items: %zu\n", bloom->item_count);
    printf("  Bit array (first 64 bits): ");
    for (size_t i = 0; i < (bloom->bit_count < 64 ? bloom->bit_count : 64); i++) {
        printf("%d", fossil_bloom_get_bit(bloom->bit_array, i) ? 1 : 0);
    }
    printf("\n");
}
