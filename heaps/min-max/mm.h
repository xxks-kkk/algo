#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <assert.h>
#include <limits.h>

/*
 * MAW 6.15 A min-max heap is a data structure that supports both
 * DeleteMin and DeleteMax in O(logN) per operation. The structure
 * is identical to a binary heap, but the heap order property is that
 * for any node, X, at even depth, the key stored at X is smaller than
 * the parent but larger than the grandparent, and for any node X at odd 
 * depth, the key stored at X is larger than the parent but smaller
 * than the grandparent.
 */


#ifndef _MM_H
#define _MM_H

struct MinMaxHeapStruct;
typedef struct MinMaxHeapStruct* MinMaxHeap;
typedef unsigned int Position;

MinMaxHeap initializeMMH(int maxElements);
void destroyMinMaxHeap(MinMaxHeap H);
void makeEmptyMMH(MinMaxHeap H);
void insertMHH(int X, MinMaxHeap H);
int deleteMinMHH(MinMaxHeap H);
int deleteMaxMHH(MinMaxHeap H);
int findMinMMH(MinMaxHeap H);
int findMaxMMH(MinMaxHeap H);
int isEmpty(MinMaxHeap H);
int isFull(MinMaxHeap H);
MinMaxHeap buildMMH(int* array, int arrayLength);
MinMaxHeap initializeMinMaxHeapFromArray(int* array, int arrayLength);
void mmh_print_dot(MinMaxHeap H, FILE* stream);


#endif
