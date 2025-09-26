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
#include "fossil/tofu/vector.h"


// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tofu_vector_t* fossil_tofu_vector_create_container(char* type) {
    fossil_tofu_vector_t* vector = (fossil_tofu_vector_t*)fossil_tofu_alloc(sizeof(fossil_tofu_vector_t));
    if (vector == NULL) {
        return NULL;
    }
    vector->data = (fossil_tofu_t*)fossil_tofu_alloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    if (vector->data == NULL) {
        fossil_tofu_free(vector);
        return NULL;
    }
    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;
    vector->type = type;
    return vector;
}

fossil_tofu_vector_t* fossil_tofu_vector_create_default(void) {
    return fossil_tofu_vector_create_container("any");
}

fossil_tofu_vector_t* fossil_tofu_vector_create_copy(const fossil_tofu_vector_t* other) {
    fossil_tofu_vector_t* vector = (fossil_tofu_vector_t*)fossil_tofu_alloc(sizeof(fossil_tofu_vector_t));
    if (vector == NULL) {
        return NULL;
    }
    vector->data = (fossil_tofu_t*)fossil_tofu_alloc(other->capacity * sizeof(fossil_tofu_t));
    if (vector->data == NULL) {
        fossil_tofu_free(vector);
        return NULL;
    }
    vector->size = other->size;
    vector->capacity = other->capacity;
    vector->type = other->type;
    for (size_t i = 0; i < other->size; i++) {
        vector->data[i] = other->data[i];
    }
    return vector;
}

fossil_tofu_vector_t* fossil_tofu_vector_create_move(fossil_tofu_vector_t* other) {
    fossil_tofu_vector_t* vector = (fossil_tofu_vector_t*)fossil_tofu_alloc(sizeof(fossil_tofu_vector_t));
    if (vector == NULL) {
        return NULL;
    }
    vector->data = other->data;
    vector->size = other->size;
    vector->capacity = other->capacity;
    vector->type = other->type;
    other->data = NULL;
    other->size = 0;
    other->capacity = 0;
    other->type = NULL;
    return vector;
}

void fossil_tofu_vector_destroy(fossil_tofu_vector_t* vector) {
    if (vector == NULL) {
        return;
    }
    fossil_tofu_free(vector->data);
    fossil_tofu_free(vector);
}

// *****************************************************************************
// Utility functions
// *****************************************************************************

void fossil_tofu_vector_push_back(fossil_tofu_vector_t* vector, char *element) {
    if (vector == NULL) {
        return;
    }
    if (fossil_tofu_validate_type(vector->type) == FOSSIL_TOFU_TYPE_ANY) {
        return;
    }
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * vector->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < vector->size; i++) {
            new_data[i] = vector->data[i];
        }
        fossil_tofu_free(vector->data);
        vector->data = new_data;
        vector->capacity *= 2;
    }
    vector->data[vector->size++] = fossil_tofu_create(vector->type, element);
}

void fossil_tofu_vector_push_front(fossil_tofu_vector_t* vector, char *element) {
    if (vector == NULL) {
        return;
    }
    if (fossil_tofu_validate_type(vector->type) == FOSSIL_TOFU_TYPE_ANY) {
        return;
    }
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * vector->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < vector->size; i++) {
            new_data[i + 1] = vector->data[i];
        }
        fossil_tofu_free(vector->data);
        vector->data = new_data;
        vector->capacity *= 2;
    } else {
        for (size_t i = vector->size; i > 0; i--) {
            vector->data[i] = vector->data[i - 1];
        }
    }
    vector->data[0] = fossil_tofu_create(vector->type, element);
    vector->size++;
}

void fossil_tofu_vector_push_at(fossil_tofu_vector_t* vector, size_t index, char *element) {
    if (vector == NULL || index > vector->size) {
        return;
    }
    if (fossil_tofu_validate_type(vector->type) == FOSSIL_TOFU_TYPE_ANY) {
        return;
    }
    if (vector->size == vector->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * vector->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < index; i++) {
            new_data[i] = vector->data[i];
        }
        for (size_t i = index; i < vector->size; i++) {
            new_data[i + 1] = vector->data[i];
        }
        fossil_tofu_free(vector->data);
        vector->data = new_data;
        vector->capacity *= 2;
    } else {
        for (size_t i = vector->size; i > index; i--) {
            vector->data[i] = vector->data[i - 1];
        }
    }
    vector->data[index] = fossil_tofu_create(vector->type, element);
    vector->size++;
}

void fossil_tofu_vector_pop_back(fossil_tofu_vector_t* vector) {
    if (vector == NULL || vector->size == 0) {
        return;
    }
    fossil_tofu_destroy(&vector->data[--vector->size]);
}

void fossil_tofu_vector_pop_front(fossil_tofu_vector_t* vector) {
    if (vector == NULL || vector->size == 0) {
        return;
    }
    fossil_tofu_destroy(&vector->data[0]);
    for (size_t i = 0; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

void fossil_tofu_vector_pop_at(fossil_tofu_vector_t* vector, size_t index) {
    if (vector == NULL || index >= vector->size) {
        return;
    }
    fossil_tofu_destroy(&vector->data[index]);
    for (size_t i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->size--;
}

void fossil_tofu_vector_erase(fossil_tofu_vector_t* vector) {
    if (vector == NULL) {
        return;
    }
    for (size_t i = 0; i < vector->size; i++) {
        fossil_tofu_destroy(&vector->data[i]);
    }
    vector->size = 0;
}

bool fossil_tofu_vector_is_cnullptr(const fossil_tofu_vector_t* vector) {
    return vector == NULL;
}

bool fossil_tofu_vector_not_cnullptr(const fossil_tofu_vector_t* vector) {
    return vector != NULL;
}

bool fossil_tofu_vector_is_empty(const fossil_tofu_vector_t* vector) {
    return vector == NULL || vector->size == 0;
}

bool fossil_tofu_vector_not_empty(const fossil_tofu_vector_t* vector) {
    return vector != NULL && vector->size > 0;
}

size_t fossil_tofu_vector_size(const fossil_tofu_vector_t* vector) {
    return vector == NULL ? 0 : vector->size;
}

size_t fossil_tofu_vector_capacity(const fossil_tofu_vector_t* vector) {
    return vector == NULL ? 0 : vector->capacity;
}

// *****************************************************************************
// Getter and setter functions
// *****************************************************************************

char *fossil_tofu_vector_get(const fossil_tofu_vector_t* vector, size_t index) {
    return vector == NULL || index >= vector->size ? NULL : fossil_tofu_get_value(&vector->data[index]);
}

char *fossil_tofu_vector_get_front(const fossil_tofu_vector_t* vector) {
    return vector == NULL || vector->size == 0 ? NULL : fossil_tofu_get_value(&vector->data[0]);
}

char *fossil_tofu_vector_get_back(const fossil_tofu_vector_t* vector) {
    return vector == NULL || vector->size == 0 ? NULL : fossil_tofu_get_value(&vector->data[vector->size - 1]);
}

char *fossil_tofu_vector_get_at(const fossil_tofu_vector_t* vector, size_t index) {
    return vector == NULL || index >= vector->size ? NULL : fossil_tofu_get_value(&vector->data[index]);
}

void fossil_tofu_vector_set(fossil_tofu_vector_t* vector, size_t index, char *element) {
    if (vector == NULL || index >= vector->size) {
        return;
    }
    fossil_tofu_set_value(&vector->data[index], element);
}

void fossil_tofu_vector_set_front(fossil_tofu_vector_t* vector, char *element) {
    if (vector == NULL || vector->size == 0) {
        return;
    }
    fossil_tofu_set_value(&vector->data[0], element);
}

void fossil_tofu_vector_set_back(fossil_tofu_vector_t* vector, char *element) {
    if (vector == NULL || vector->size == 0) {
        return;
    }
    fossil_tofu_set_value(&vector->data[vector->size - 1], element);
}

void fossil_tofu_vector_set_at(fossil_tofu_vector_t* vector, size_t index, char *element) {
    if (vector == NULL || index >= vector->size) {
        return;
    }
    fossil_tofu_set_value(&vector->data[index], element);
}
