// NOTE: 1. This implemntation is part of open addressing hashing,
//       which is linear hashing.
//       2. Routines such as delete and makeEmpty are omitted

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utility.h"
#include <string.h>

#ifndef _OA_H
#define _OA_H

typedef unsigned int Index;
typedef Index Position;

struct HashEntry;
typedef struct HashEntry Cell;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable initializeTable(int TableSize);
void DestroyTable(HashTable H);
Position find(int key, HashTable H);
void insert(int key, HashTable H);
int retrieve(Position P, HashTable H);
HashTable rehash(HashTable H);
void printHashTable(HashTable H);
HashTable initializeTableFromArray(int* array, int arrayLength, int TableSize);

/*
 * MAW 5.11.d Suppose we want to find the first occurrence of a string p1p2...pk
 * in a long input string A1A2...AN.
 * Return the start index of p1 in A1A2...AN
 */
int findPattern(char* pattern, char* input);


#endif
