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
#include "fossil/tofu/array.h"

// *****************************************************************************
// Function prototypes
// *****************************************************************************

fossil_tofu_array_t* fossil_tofu_array_create_container(char* type) {
    if (type == NULL || fossil_tofu_validate_type(type) == FOSSIL_TOFU_TYPE_CNULL) {
        return NULL;
    }
    fossil_tofu_array_t* array = (fossil_tofu_array_t*)fossil_tofu_alloc(sizeof(fossil_tofu_array_t));
    if (array == NULL) {
        return NULL;
    }
    array->data = (fossil_tofu_t*)fossil_tofu_alloc(INITIAL_CAPACITY * sizeof(fossil_tofu_t));
    if (array->data == NULL) {
        fossil_tofu_free(array);
        return NULL;
    }
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    array->type = type;
    return array;
}

fossil_tofu_array_t* fossil_tofu_array_create_default(void) {
    return fossil_tofu_array_create_container("any");
}

fossil_tofu_array_t* fossil_tofu_array_create_copy(const fossil_tofu_array_t* other) {
    if (other == NULL || other->type == NULL || fossil_tofu_validate_type(other->type) == FOSSIL_TOFU_TYPE_CNULL) {
        return NULL;
    }
    fossil_tofu_array_t* array = (fossil_tofu_array_t*)fossil_tofu_alloc(sizeof(fossil_tofu_array_t));
    if (array == NULL) {
        return NULL;
    }
    array->data = (fossil_tofu_t*)fossil_tofu_alloc(other->capacity * sizeof(fossil_tofu_t));
    if (array->data == NULL) {
        fossil_tofu_free(array);
        return NULL;
    }
    array->size = other->size;
    array->capacity = other->capacity;
    array->type = other->type;
    for (size_t i = 0; i < other->size; i++) {
        if (fossil_tofu_get_type(&other->data[i]) != fossil_tofu_validate_type(other->type)) {
            // Type mismatch encountered
            fossil_tofu_free(array->data);
            fossil_tofu_free(array);
            return NULL;
        }
        array->data[i] = other->data[i];
    }
    return array;
}

fossil_tofu_array_t* fossil_tofu_array_create_move(fossil_tofu_array_t* other) {
    if (other == NULL || other->type == NULL || fossil_tofu_validate_type(other->type) == FOSSIL_TOFU_TYPE_CNULL) {
        return NULL;
    }
    fossil_tofu_array_t* array = (fossil_tofu_array_t*)fossil_tofu_alloc(sizeof(fossil_tofu_array_t));
    if (array == NULL) {
        return NULL;
    }
    array->data = other->data;
    array->size = other->size;
    array->capacity = other->capacity;
    array->type = other->type;
    other->data = NULL;
    other->size = 0;
    other->capacity = 0;
    other->type = NULL;
    return array;
}

void fossil_tofu_array_destroy(fossil_tofu_array_t* array) {
    if (array == NULL) {
        return;
    }
    fossil_tofu_free(array->data);
    fossil_tofu_free(array);
}

void fossil_tofu_array_push_back(fossil_tofu_array_t* array, char *element) {
    if (array == NULL) {
        return;
    }
    if (array->size == array->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * array->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < array->size; i++) {
            new_data[i] = array->data[i];
        }
        fossil_tofu_free(array->data);
        array->data = new_data;
        array->capacity *= 2;
    }
    array->data[array->size++] = fossil_tofu_create(array->type, element);
}

void fossil_tofu_array_push_front(fossil_tofu_array_t* array, char *element) {
    if (array == NULL) {
        return;
    }
    if (array->size == array->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * array->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < array->size; i++) {
            new_data[i + 1] = array->data[i];
        }
        fossil_tofu_free(array->data);
        array->data = new_data;
        array->capacity *= 2;
    } else {
        for (size_t i = array->size; i > 0; i--) {
            array->data[i] = array->data[i - 1];
        }
    }
    array->data[0] = fossil_tofu_create(array->type, element);
    array->size++;
}

void fossil_tofu_array_push_at(fossil_tofu_array_t* array, size_t index, char *element) {
    if (array == NULL || index > array->size) {
        return;
    }
    if (array->size == array->capacity) {
        fossil_tofu_t* new_data = (fossil_tofu_t*)fossil_tofu_alloc(2 * array->capacity * sizeof(fossil_tofu_t));
        if (new_data == NULL) {
            return;
        }
        for (size_t i = 0; i < index; i++) {
            new_data[i] = array->data[i];
        }
        for (size_t i = index; i < array->size; i++) {
            new_data[i + 1] = array->data[i];
        }
        fossil_tofu_free(array->data);
        array->data = new_data;
        array->capacity *= 2;
    } else {
        for (size_t i = array->size; i > index; i--) {
            array->data[i] = array->data[i - 1];
        }
    }
    array->data[index] = fossil_tofu_create(array->type, element);
    array->size++;
}

void fossil_tofu_array_pop_back(fossil_tofu_array_t* array) {
    if (array == NULL || array->size == 0) {
        return;
    }
    fossil_tofu_destroy(&array->data[--array->size]);
}

void fossil_tofu_array_pop_front(fossil_tofu_array_t* array) {
    if (array == NULL || array->size == 0) {
        return;
    }
    fossil_tofu_destroy(&array->data[0]);
    for (size_t i = 0; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

void fossil_tofu_array_pop_at(fossil_tofu_array_t* array, size_t index) {
    if (array == NULL || index >= array->size) {
        return;
    }
    fossil_tofu_destroy(&array->data[index]);
    for (size_t i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

void fossil_tofu_array_erase(fossil_tofu_array_t* array) {
    if (array == NULL) {
        return;
    }
    for (size_t i = 0; i < array->size; i++) {
        fossil_tofu_destroy(&array->data[i]);
    }
    array->size = 0;
}

bool fossil_tofu_array_is_cnullptr(const fossil_tofu_array_t* array) {
    return array == NULL;
}

bool fossil_tofu_array_not_cnullptr(const fossil_tofu_array_t* array) {
    return array != NULL;
}

bool fossil_tofu_array_is_empty(const fossil_tofu_array_t* array) {
    return array == NULL || array->size == 0;
}

bool fossil_tofu_array_not_empty(const fossil_tofu_array_t* array) {
    return array != NULL && array->size > 0;
}

size_t fossil_tofu_array_size(const fossil_tofu_array_t* array) {
    return array == NULL ? 0 : array->size;
}

size_t fossil_tofu_array_capacity(const fossil_tofu_array_t* array) {
    return array == NULL ? 0 : array->capacity;
}

char *fossil_tofu_array_get(const fossil_tofu_array_t* array, size_t index) {
    return array == NULL || index >= array->size ? NULL : fossil_tofu_get_value(&array->data[index]);
}

char *fossil_tofu_array_get_front(const fossil_tofu_array_t* array) {
    return array == NULL || array->size == 0 ? NULL : fossil_tofu_get_value(&array->data[0]);
}

char *fossil_tofu_array_get_back(const fossil_tofu_array_t* array) {
    return array == NULL || array->size == 0 ? NULL : fossil_tofu_get_value(&array->data[array->size - 1]);
}

char *fossil_tofu_array_get_at(const fossil_tofu_array_t* array, size_t index) {
    return array == NULL || index >= array->size ? NULL : fossil_tofu_get_value(&array->data[index]);
}

void fossil_tofu_array_set(fossil_tofu_array_t* array, size_t index, char *element) {
    if (array == NULL || index >= array->size) {
        return;
    }
    fossil_tofu_set_value(&array->data[index], element);
}

void fossil_tofu_array_set_front(fossil_tofu_array_t* array, char *element) {
    if (array == NULL || array->size == 0) {
        return;
    }
    fossil_tofu_set_value(&array->data[0], element);
}

void fossil_tofu_array_set_back(fossil_tofu_array_t* array, char *element) {
    if (array == NULL || array->size == 0) {
        return;
    }
    fossil_tofu_set_value(&array->data[array->size - 1], element);
}

void fossil_tofu_array_set_at(fossil_tofu_array_t* array, size_t index, char *element) {
    if (array == NULL || index >= array->size) {
        return;
    }
    fossil_tofu_set_value(&array->data[index], element);
}
