/*
 * MAW 5.3 Write a program to compute the number of collisions required in a long random
 * sequence of insertions using linear probing, quadratic probing, and double hashing
 */

//NOTE: 1. I don't really care to run the actual experimentation. The result is the quadratic
//      probing is the best one among three. More details see Gonnet and Baeza-Yates [8]
//      2. Routines such as delete and makeEmpty are omitted
//      3. Ideally, TableSize is picked to be the prime with the lambda = 1
//         for separate chaining hashing. This task is left to caller.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef _SC_H
#define _SC_H

struct ListNode;
typedef struct ListNode *Position;
typedef Position List;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable initializeTable(int TableSize);
void destroyTable(HashTable H);
Position find(int key, HashTable H);
void insert(int key, HashTable H);
int retrieve(Position P);
void printHashTable(HashTable H);
HashTable initializeTableFromArray(int* array, int arrayLength, int TableSize);

#endif
