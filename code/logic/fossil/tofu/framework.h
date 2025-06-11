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
#ifndef FOSSIL_TOFU_FRAMEWORK_H
#define FOSSIL_TOFU_FRAMEWORK_H

// the main tofu type
#include "tofu.h"

// the algorithm functions
#include "algorithm.h"

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
