#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/* 
 * Disjoint set data structure interface
 */
#define NumSets 10

#ifndef _DisjSet_H

typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

/*
 * Initialize the disjoint set
 */
void initialize(DisjSet);

/*
 * Replace equivalence classes containing two elements with their union
 *
 * NOTE: there are some minor changes compared to MAW:
 * 1. Unlike MAW implementation, we pass in two elements instead of the
 *    actual class name (i.e., root if we use quick-union implementation)
 * 2. Unlike MAW, we merge the equvalience class containing 1st element into
 *    equivalence class containing 2nd element. This statement holds for 
 *    quick-find, quick-union and not true for smart-union (union-by-size)
 *    and path compression.
 */
void setUnion(DisjSet, ElementType, ElementType);

/*
 * Returns the name of the set (that is, the equivalence class) containing
 * a given element
 */
SetType find(ElementType, DisjSet);

#endif
