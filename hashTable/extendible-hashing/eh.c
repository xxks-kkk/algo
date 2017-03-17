#include "eh.h"

enum KindOfEntry {Legitimate, Empty, Deleted};

struct LeafNode
{
  int dL; // the number of leading bits that all the elements of some Leaf L have in common
  int numElement; // keep track of the current number of element in LeafNode
  Position Element;
};

struct extendHashTbl
{
  int M; // the maximum number of elements for a leaf
  int D; // the number of bits used by the root (i.e. directory)
  LeafPtr *Root; 
};

struct LeafEntry
{
  char* Data;
  enum KindOfEntry Info;
};

ExtendHashTable
initializeExtendHashTable(int M,
                          int D)
{
  int numCells, i, j;
  ExtendHashTable H = malloc(sizeof(struct extendHashTbl));
  assert(H);
  H->M = M;
  H->D = D;
  numCells = pow(2, D);
  H->Root = malloc(numCells * sizeof(LeafPtr));
  assert(H->Root);
  for(i = 0; i < numCells; i++)
  {
    H->Root[i] = malloc(sizeof(struct LeafNode));
    assert(H->Root[i]);
    H->Root[i]->dL = D;
    H->Root[i]->Element = malloc(M * sizeof(struct LeafEntry));
    assert(H->Root[i]->Element);
    H->Root[i]->numElement = 0;    
    for(j = 0; j < H->M; j++)
      H->Root[i]->Element[j].Info = Empty;
  }
  return H;
}

void
destroyTable(ExtendHashTable H)
{
  int i;
  for(i = 0; i < H->M; i++)
    free(H->Root[i]->Element);
  free(H->Root);
  free(H);
}

// We use this hash to decide which
// leaf we go to
static int
hash(char *key,
     ExtendHashTable H)
{
  int idx, i;
  for(i = D-1; i >= 0; i--)
    idx += pow(2,i) * (key[i]-'0');
  return idx;
}

// We use this hash to decide which position
// of leaf we can insert/find the target
staic int
hash2(char *key,
      ExtendHashTable H)
{
  int idx, i, length, val;
  length = strlen(key);
  val = 0;
  for(i = length-1; i >= 0; i--)
    val += pow(2,i) * (key[i]-'0');
  return val % H->M;
}

Position
find(char* key,
     ExtendHashTable H)
{
  return H->Root[hash(key, H)]->Element[hash2(key, H)];
}

// This function handles the case when
// insertion for a leaf node is failed
// due to the leaf node is full.
static void
splitAndInsert(char* key, ExtendHashTable H)
{
  int numCells, i, idx, tmp, j;
  H->D++;
  numCells = pow(2, H->D);
  H->Root = realloc(H->Root, numCells * sizeof(LeafPtr));
  assert(H->Root);
  idx = find(key, H); // idx where to insert
  for(i = 0; i < numCells; i++)
  {
    if (i != idx && i%2 == 0)
      tmp = i;
    if (i != idx && i%2 == 1) 
      H->Root[i]->Element = H->Root[tmp]->Element;
    if (i == idx)
    {
      H->Root[i]->Element = malloc(M * sizeof(struct LeafEntry));
      assert(H->Root[i]->Element);
      H->Root[i]->dL = H->D; // update dL      
      for(j = 0; j < H->M; j++) // since directory size increases, we may need to move value from old leaf to new leaf
      {
        if(H->Root[i-1]->Element[j].Info == Legitimate)
          insert(H->Root[i-1]->Element[j].Data, H);
      }
      insert(key, H); // actually insert new value
    }
  }
}

void
insert(char* key,
       ExtendHashTable H)
{
  Position loc = find(key, H);
  int hasVal = hash(key, H);
  if(loc.Info != Legitimate)
  {
    loc.Data = key;
    loc.Info = Legitimate;
    H->Root[hashVal]->numElement++;
  }
  else if (H->Root[hashVal]->numElement == M)
    splitAndInsert(key, H);
}

void
printExtendHashTable(ExtendHashTable H)
{

}
