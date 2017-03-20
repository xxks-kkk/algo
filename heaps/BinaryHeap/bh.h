/*
 * MAW 6.4 Write the routines to do a percolate up and a percolate down in a binary heap. 
 */

// NOTE: The binary heap will be represented in an array. For any element in array position i,
//       the left child is in position 2i, the right child is in the cell after the left child
//       (2i+1), and the parent is in position \lceil{i/2}\rceil
//       *Advantage*: 1. No pointers 2. tree traversal can be done extremely simple and fast
//       *Disadvantage*: 1. an estimate of maximum heap size is required in advance

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <assert.h>
#include <limits.h>

#ifndef _BH_H
#define _BH_H

typedef int ET;

struct HeapStruct;
typedef struct HeapStruct *BinHeap;

BinHeap initialize(int MaxElements);
void destroyBinHeap(BinHeap H);
void makeEmpty(BinHeap H);
void insert(ET X, BinHeap H);
ET deleteMin(BinHeap H);
ET findMin(BinHeap H);
int isEmpty(BinHeap H);
int isFull(BinHeap H);
BinHeap initializeBinHeapFromArray(ET* array, int arrayLength);
void bh_print_dot(BinHeap H, FILE* stream);

#endif
