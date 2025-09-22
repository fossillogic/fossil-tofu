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
#ifndef FOSSIL_TOFU_FRAMEWORK_H
#define FOSSIL_TOFU_FRAMEWORK_H

// the main tofu type
#include "tofu.h"

// array family
#include "vector.h"
#include "tuple.h"
// TODO: Add array implementation when available
// TODO: Add matrix implementation when available
// TODO: Add sparse matrix implementation when available
// TODO: Add linked array implementation when available

// queue family
#include "dqueue.h"
#include "pqueue.h"
#include "cqueue.h"
#include "queue.h"

// stack family
#include "stack.h"

// key-value family
#include "setof.h"
#include "mapof.h"
// TODO: Add trie implementation when available
// TODO: Add bloom filter implementation when available

// linked list family
#include "clist.h"
#include "flist.h"
#include "dlist.h"
//
// TODO: Add cross-list implementation when available
// TODO: Add skip-list implementation when available
// TODO: Add xor-linked list implementation when available
// TODO: Add intrusive list implementation when available
// TODO: Add unrolled linked list implementation when available
//

// tree family
// TODO add tree family headers when implemented

#endif /* FOSSIL_TOFU_FRAMEWORK_H */
