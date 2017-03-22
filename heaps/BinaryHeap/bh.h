/*
 * MAW 6.4 Write the routines to do a percolate up and a percolate down in a binary heap. 
 *
 * MAW 6.5 Write and test a program that performs the operations Insert, DeleteMin, BuildHeap,
 * FindMin, DecreaseKey, Delete, and IncreaseKey in a binary heap.
 */

// NOTE: The binary heap will be represented in an array. For any element in array position i,
//       the left child is in position 2i, the right child is in the cell after the left child
//       (2i+1), and the parent is in position \lceil{i/2}\rceil
//       *Advantage*: 1. No pointers 2. tree traversal can be done extremely simple and fast
//       *Disadvantage*: 1. an estimate of maximum heap size is required in advance
//
//       I didn't use hash table as a way to store each node position as suggested by MAW p.186.

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <assert.h>
#include <limits.h>

#ifndef _BH_H
#define _BH_H

struct HeapStruct;
typedef struct HeapStruct *BinHeap;
typedef unsigned int Position;

BinHeap initializeBH(int MaxElements);
void destroyBinHeap(BinHeap H);
void makeEmptyBH(BinHeap H);
void insertBH(int X, BinHeap H);
int deleteMinBH(BinHeap H);
int findMinBH(BinHeap H);
int isEmpty(BinHeap H);
int isFull(BinHeap H);
BinHeap initializeBinHeapFromArray(int* array, int arrayLength);
void bh_print_dot(BinHeap H, FILE* stream);

BinHeap buildHeap(int* array, int arrayLength);
void decreaseKey(Position P, int delta, BinHeap H);
void increaseKey(Position P, int delta, BinHeap H);
void delete(Position P, BinHeap H);


#endif
