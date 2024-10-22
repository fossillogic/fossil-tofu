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
#include "fossil/tofu/vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

fossil_vector_t* fossil_vector_create(char* type) {
    fossil_vector_t* vector = (fossil_vector_t*)fossil_tofu_alloc(sizeof(fossil_vector_t));
    if (!vector) {
        fprintf(stderr, "Error: Memory allocation failed for vector.\n");
        return NULL;
    }

    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->type = fossil_tofu_strdup(type); // Duplicate the type string
    if (!vector->type) {
        fprintf(stderr, "Error: Memory allocation failed for type string.\n");
        fossil_tofu_free(vector);
        return NULL;
    }

    return vector;
}

void fossil_vector_destroy(fossil_vector_t* vector) {
    if (!vector) return;

    fossil_tofu_free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    fossil_tofu_free(vector);
}

void fossil_vector_push_back(fossil_vector_t* vector, fossil_tofu_t element) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to push back to a null vector.\n");
        return;
    }

    if (vector->size >= vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(vector->data, new_capacity * sizeof(fossil_tofu_t));
        if (!new_data) {
            fprintf(stderr, "Error: Memory allocation failed while pushing back.\n");
            return;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    vector->data[vector->size++] = element;
}

void fossil_vector_push_front(fossil_vector_t* vector, fossil_tofu_t element) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to push front to a null vector.\n");
        return;
    }

    if (vector->size >= vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(vector->data, new_capacity * sizeof(fossil_tofu_t));
        if (!new_data) {
            fprintf(stderr, "Error: Memory allocation failed while pushing front.\n");
            return;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    for (size_t i = vector->size; i > 0; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[0] = element;
    ++vector->size;
}

void fossil_vector_push_at(fossil_vector_t* vector, size_t index, fossil_tofu_t element) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to push at to a null vector.\n");
        return;
    }

    if (index > vector->size) {
        fprintf(stderr, "Error: Attempt to push at an out-of-bounds index.\n");
        return;
    }

    if (vector->size >= vector->capacity) {
        size_t new_capacity = vector->capacity == 0 ? 1 : vector->capacity * 2;
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_realloc(vector->data, new_capacity * sizeof(fossil_tofu_t));
        if (!new_data) {
            fprintf(stderr, "Error: Memory allocation failed while pushing at.\n");
            return;
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    for (size_t i = vector->size; i > index; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index] = element;
    ++vector->size;
}

void fossil_vector_pop_back(fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to pop back from a null vector.\n");
        return;
    }

    if (vector->size > 0) {
        --vector->size;
    } else {
        fprintf(stderr, "Error: Attempt to pop back from an empty vector.\n");
    }
}

void fossil_vector_pop_front(fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to pop front from a null vector.\n");
        return;
    }

    if (vector->size > 0) {
        for (size_t i = 0; i < vector->size - 1; ++i) {
            vector->data[i] = vector->data[i + 1];
        }
        --vector->size;
    } else {
        fprintf(stderr, "Error: Attempt to pop front from an empty vector.\n");
    }
}

void fossil_vector_pop_at(fossil_vector_t* vector, size_t index) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to pop at from a null vector.\n");
        return;
    }

    if (index >= vector->size) {
        fprintf(stderr, "Error: Attempt to pop at an out-of-bounds index.\n");
        return;
    }

    for (size_t i = index; i < vector->size - 1; ++i) {
        vector->data[i] = vector->data[i + 1];
    }
    --vector->size;
}

void fossil_vector_erase(fossil_vector_t* vector, size_t index) {
    if (!vector) {
        // Handle null vector
        fprintf(stderr, "Error: Attempt to erase from a null vector.\n");
        return;
    }

    if (index >= vector->size) {
        // Handle out-of-bounds access
        fprintf(stderr, "Error: Attempt to erase from an out-of-bounds index.\n");
        return;
    }

    for (size_t i = index; i < vector->size - 1; ++i) {
        vector->data[i] = vector->data[i + 1];
    }
    --vector->size;
}

void fossil_vector_erase_if(fossil_vector_t* vector, fossil_tofu_t target) {
    if (!vector) {
        // Handle null vector
        fprintf(stderr, "Error: Attempt to erase from a null vector.\n");
        return;
    }

    size_t i = 0;
    while (i < vector->size) {
        if (fossil_tofu_equals(vector->data[i], target)) {
            for (size_t j = i; j < vector->size - 1; ++j) {
                vector->data[j] = vector->data[j + 1];
            }
            --vector->size;
        } else {
            ++i;
        }
    }
}

int fossil_vector_search(const fossil_vector_t* vector, fossil_tofu_t target) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to search in a null vector.\n");
        return FOSSIL_TOFU_FAILURE;
    }

    for (size_t i = 0; i < vector->size; ++i) {
        if (fossil_tofu_equals(vector->data[i], target)) {
            return (int)i; // Found
        }
    }
    return FOSSIL_TOFU_FAILURE; // Not found
}

void fossil_vector_reverse(fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to reverse a null vector.\n");
        return;
    }

    for (size_t i = 0; i < vector->size / 2; ++i) {
        fossil_tofu_t temp = vector->data[i];
        vector->data[i] = vector->data[vector->size - i - 1];
        vector->data[vector->size - i - 1] = temp;
    }
}

bool fossil_vector_is_cnullptr(const fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to check if a null vector is a null pointer.\n");
        return true;
    }
    return vector == NULL;
}

bool fossil_vector_not_cnullptr(const fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to check if a null vector is not a null pointer.\n");
        return false;
    }
    return vector != NULL;
}

bool fossil_vector_is_empty(const fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to check if a null vector is empty.\n");
        return true;
    }
    return vector->size == 0;
}

bool fossil_vector_not_empty(const fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to check if a null vector is not empty.\n");
        return false;
    }
    return vector->size != 0;
}

size_t fossil_vector_size(const fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to get the size of a null vector.\n");
        return 0;
    }
    return vector->size;
}

size_t fossil_vector_capacity(const fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to get the capacity of a null vector.\n");
        return 0;
    }
    return vector->capacity;
}

void fossil_vector_peek(const fossil_vector_t* vector) {
    if (!vector) {
        fprintf(stderr, "Error: Attempt to peek into a null vector.\n");
        return;
    }

    for (size_t i = 0; i < vector->size; ++i) {
        fossil_tofu_print(vector->data[i]);
    }
}
