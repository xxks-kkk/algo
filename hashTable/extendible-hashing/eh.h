/*
 * MAW 5.15 Write a program to implement extendible hashing
 */

#include <assert.h>
#include <math.h>

// We assume data in leaf are all with the same length
struct LeafNode;
typedef struct LeafNode *LeafPtr;
struct extendHashTbl;
typedef struct extendHashTbl *ExtendHashTable;
struct LeafEntry;
typedef LeafEntry *Position;

ExtendHashTable initializeExtendHashTable(int M, int D);
void destroyTable(ExtendHashTable H);
Position find(char* key, ExtendHashTable H);
void insert(char* key, ExtendHashTable H);
