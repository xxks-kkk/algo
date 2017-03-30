#include "mm.h"

// NOTE: Implementation reference: "Min-Max Heaps and Generalized Priority Queues"
// (Atkinson, et. al)
// http://www.akira.ruc.dk/~keld/teaching/algoritmedesign_f03/Artikler/02/Atkinson86.pdf

static int getDepth(Position pos);
static void percolateUpMin(Position pos, MinMaxHeap H);
static void percolateUpMax(Position pos, MinMaxHeap H);
static void percolateDownMax(Position pos, MinMaxHeap H);
static void percolateDownMin(Position pos, MinMaxHeap H);

struct MinMaxHeapStruct
{
  int Capacity;
  int Size;
  int *Elements;
};

MinMaxHeap
initializeMMH(int maxElements)
{
  MinMaxHeap H = malloc(sizeof(struct MinMaxHeapStruct));
  assert(H);
  H->Capacity = maxElements;
  H->Size = 0;
  H->Elements = malloc((H->Capacity+1) * sizeof(struct MinMaxHeapStruct));
  H->Elements[0] = INT_MIN;

  return H;
}

int
deleteMinMHH(MinMaxHeap H)
{
  int i, child;
  int minElement, lastElement;

  if(isEmpty(H))
    fatal("Heap is empty!");

  minElement = H->Elements[1];
  lastElement = H->Elements[H->Size--];

  for(i = 1; i*4 <= H->Size; i = child)
  {
    // Find the child with min value
    child = i*4 + findMin(&H->Elements[i*4], min(4, H->Size-i*4));
    if(lastElement > H->Elements[child])
      H->Elements[i] = H->Elements[child];
    else
      break;
  }
  H->Elements[i] = lastElement;
  return minElement;
}

static int
findMaxMMHIdx(MinMaxHeap H)
{
  return H->Elements[2] > H->Elements[3] ? 2: 3;
}

int
deleteMaxMHH(MinMaxHeap H)
{
  int i, child;
  int maxElement, lastElement;

  if(isEmpty(H))
    fatal("Heap is empty!");

  maxElement = findMaxMMH(H);
  lastElement = H->Elements[H->Size--];

  for(i = findMaxMMHIdx(H); i*4 <= H->Size; i = child)
  {
    // Find the child with max value
    child = i*4 + findMax(&H->Elements[i*4], min(4, H->Size-i*4));
    if(lastElement < H->Elements[child])
      H->Elements[i] = H->Elements[child];
    else
      break;
  }
  H->Elements[i] = lastElement;
  return maxElement;
}

void
destroyMinMaxHeap(MinMaxHeap H)
{
  free(H->Elements);
  free(H);
}

void
makeEmptyMMH(MinMaxHeap H)
{
  H->Size = 0;
}

/*
 * return the depth (level) that the given node 
 * represented by pos is at.
 */
static int
getDepth(Position pos)
{
  int depth = 0;
  while((pos /= 2) > 0) depth++;
  return depth;
}

static void
percolateUpMin(Position pos, MinMaxHeap H)
{
  if (pos/4 > 0) // has grandparent
    if (H->Elements[pos] < H->Elements[pos/4])
    {
      H->Elements[pos/4] = H->Elements[pos];
      percolateUpMin(pos/4, H);
    }
}

static void
percolateUpMax(Position pos, MinMaxHeap H)
{
  if (pos/4 > 0)
    if (H->Elements[pos] > H->Elements[pos/4])
    {
      H->Elements[pos/4] = H->Elements[pos];
      percolateUpMax(pos/4, H);
    }
}

void
insertMHH(int X,
          MinMaxHeap H)
{
  if(isFull(H))
    fatal("Heap is full!");
  H->Elements[++H->Size] = X;
  if(getDepth(H->Size) % 2 == 0) // even (min) level
  {
    if (H->Size/2 > 0 && X > H->Elements[H->Size/2])
    {
      swap(&H->Elements[H->Size/2], &H->Elements[H->Size]);
      percolateUpMax(H->Size/2, H);
    }
  }
  else // odd (max) level
  {
    if (H->Size/2 > 0 && X < H->Elements[H->Size/2])
    {
      swap(&H->Elements[H->Size/2], &H->Elements[H->Size]);
      percolateUpMin(H->Size/2, H);
    }
  }
}

int
findMinMMH(MinMaxHeap H)
{
  return H->Elements[1];
}

int
findMaxMMH(MinMaxHeap H)
{
  return H->Elements[2] > H->Elements[3] ? H->Elements[2] : H->Elements[3];
}

int
isEmpty(MinMaxHeap H)
{
  return H->Size==0;
}

int
isFull(MinMaxHeap H)
{
  return H->Size == H->Capacity;
}

MinMaxHeap
initializeMinMaxHeapFromArray(int* array,
                              int arrayLength)
{
  MinMaxHeap H = initializeMMH(arrayLength);
  int i;
  for(i = 0; i < arrayLength; i++)
    insertMHH(array[i], H);
  return H;
}

/*
 * return the index of the smallest of children and 
 * grandchildren (if any) of i
 */
static int
idxOfSmallestChildrenAndGrandChildren(Position pos,
                                      MinMaxHeap H)
{
  int idx1, idx2;
  idx1 = findMin(&H->Elements[pos*2],2);
  if (pos*4 <= H->Size)
  {
    idx2 = findMin(&H->Elements[pos*4],min(4, H->Size-pos*4));
    return H->Elements[pos*2 + idx1] > H->Elements[pos*4 + idx2] ?
      pos*4 + idx2 : pos*2 + idx1;
  }
  else
    return idx1;
}

/*
 * return the index of the biggest of children and 
 * grandchildren (if any) of i
 */
static int
idxOfBiggestChildrenAndGrandChildren(Position pos,
                                      MinMaxHeap H)
{
  int idx1, idx2;
  idx1 = pos*2 + findMax(&H->Elements[pos*2],2);
  if (pos*4 <= H->Size)
  {
    idx2 = pos*4 + findMax(&H->Elements[pos*4],min(4, H->Size-pos*4));
    return H->Elements[idx1] > H->Elements[idx2] ? idx1 : idx2;
  }
  else
    return idx1;
}

static void
percolateDownMax(Position pos,
                 MinMaxHeap H)
{
  int m, i = pos;
  if(i*2 <= H->Size) // has children
  {
    m = idxOfBiggestChildrenAndGrandChildren(pos, H);
#ifdef DEBUG
    printf("m: %d\t H->Elements[m]:%d\n", m, H->Elements[m]);
#endif
    if (m/2 != i) // m is a grandchild of i
    {
      if(H->Elements[m] > H->Elements[i])
      {
        swap(&H->Elements[m], &H->Elements[i]);
      }
      percolateDownMax(m, H);
    }
    else // m is a child of i
    {
      if(H->Elements[m] > H->Elements[i])
        swap(&H->Elements[m], &H->Elements[i]);
    }
  }  
}

static void
percolateDownMin(Position pos,
                 MinMaxHeap H)
{
  int m, i = pos;
  if(i*2 <= H->Size) // has children
  {
    m = idxOfSmallestChildrenAndGrandChildren(pos, H);
#ifdef DEBUG    
    printf("m: %d\t H->Elements[m]:%d\n", m, H->Elements[m]);
#endif    
    if (m/2 != i) // m is a grandchild of i
    {
      if(H->Elements[m] < H->Elements[i])
      {
        swap(&H->Elements[m], &H->Elements[i]);
      }
      percolateDownMin(m, H);
    }
    else // m is a child of i
    {
      if(H->Elements[m] < H->Elements[i])
        swap(&H->Elements[m], &H->Elements[i]);
    }
  }
}

MinMaxHeap
buildMMH(int* array,
         int arrayLength)
{
  MinMaxHeap H = initializeMMH(2*arrayLength);

  // We first construct a complete binary tree
  int i;
  for (i = 1; i < arrayLength + 1; i++)
    H->Elements[i] = array[i-1];
  H->Size = arrayLength;

#ifdef DEBUG
  printf("H->Size: %d\n", H->Size);
  printArray(&H->Elements[1], H->Size);
#endif
  
  // Restore the min-max binary heap property
  for(i = H->Size / 2; i > 0; i--)
  {
    if(getDepth(i) % 2 == 0) // even (min) level
    {
      percolateDownMin(i, H);
#ifdef DEBUG      
      printf("After percolateDownMin:\n");
      printArray(&H->Elements[1], H->Size);
#endif
    }
    else // odd (max) level
    {
      percolateDownMax(i, H);
#ifdef DEBUG      
      printf("After percolateDownMax:\n");
      printArray(&H->Elements[1], H->Size);
#endif      
    }
  }
  return H;
}

static void
mmh_print_dot_aux(MinMaxHeap H,
                 FILE* stream)
{
  int i;
  for(i=1; i*2 <= H->Size; i++)
  {
    fprintf(stream, "node%d [label=%d];\n", i, H->Elements[i]);
    fprintf(stream, "node%d [label=%d];\n", 2*i, H->Elements[2*i]);
    fprintf(stream, "node%d->node%d;\n", i, 2*i);
    if (i*2 != H->Size)
    {
      fprintf(stream, "node%d [label=%d];\n", 2*i+1, H->Elements[2*i+1]);      
      fprintf(stream, "node%d->node%d;\n", i, 2*i+1);
    }
  }
}

void
mmh_print_dot(MinMaxHeap H,
             FILE* stream)
{
  fprintf(stream, "digraph MinMaxHeap {\n");
  mmh_print_dot_aux(H, stream);
  fprintf(stream, "}\n");
}

