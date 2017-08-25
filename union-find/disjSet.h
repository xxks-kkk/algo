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

void initialize(DisjSet);

/*
 * Replace equivalence classes containing two elements with their union
 */
void setUnion(DisjSet, ElementType, ElementType);

/*
 * Returns the name of the set (that is, the equivalence class) containing
 * a given element
 */
SetType find(ElementType, DisjSet);

#endif
