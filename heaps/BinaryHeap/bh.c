#include "bh.h"

struct HeapStruct
{
  int Capacity; // maximum heap size
  int Size;     // current heap size
  int *Elements; // an array of element
};

BinHeap
initializeBH(
  int MaxElements)
{
  BinHeap H;

  H = malloc(sizeof(struct HeapStruct));
  assert(H);

  // Allocate the array plus one extra for sentinel
  H->Elements = malloc(sizeof(int) * (MaxElements + 1));
  assert(H->Elements);
  H->Capacity = MaxElements;
  H->Size = 0;
  H->Elements[0] = INT_MIN; //Use this to break the while loop in insertion routine. Detailed see MAW p.183
    
  return H;
}

void
destroyBinHeap(
  BinHeap H)
{
  free(H->Elements); // array implementation. can be directly freed
  free(H);
}

// We assume the array implementation. We don't touch sentinel.
void
makeEmptyBH(
  BinHeap H)
{
  int i;
  for(i = 1; i < H->Capacity; i++)
    H->Elements[i] = 0;
  H->Size = 0;
}

// H->Element[0] is a sentinel. The usage of sentinel explanation
// see MAW p.183
// percolate up strategy is contained inside the routine
void
insertBH(int X,
       BinHeap H)
{
  int i;

  if(isFull(H))
    fatal("Heap is full!");

  for(i = ++H->Size; H->Elements[i/2] > X; i/=2)
    H->Elements[i] = H->Elements[i/2];
  H->Elements[i] = X;
}

// percolate down strategy is contained inside the routine
int
deleteMinBH(BinHeap H)
{
  int i, child;
  int minElement, lastElement;

  if(isEmpty(H))
  {
    fatal("Heap is empty!");
    return H->Elements[0];
  }

  minElement = H->Elements[1];
  lastElement = H->Elements[H->Size--];

  for(i = 1; i*2 <= H->Size; i = child)
  {
    // Find smaller child
    child = i * 2;
    if( child != H->Size &&
        H->Elements[child + 1] < H->Elements[child])
      child++;

    // percolate one level
    // if lastElement is smaller than the smaller child,
    // then "X can be placed in the hole, then we are done." -- MAW p.183
    if (lastElement > H->Elements[child]) 
      H->Elements[i] = H->Elements[child];
    else
      break;
  }
  H->Elements[i] = lastElement;
  return minElement;
}

int
findMinBH(BinHeap H)
{
  return H->Elements[1];
}

int
isEmpty(BinHeap H)
{
  return (H->Size == 0);
}

int
isFull(BinHeap H)
{
  return (H->Size == H->Capacity);
}

// Here, we use insert to build Binary Heap
BinHeap
initializeBinHeapFromArray(
  int* array,
  int arrayLength)
{
  int i;
  BinHeap H = initializeBH(100);
  for(i = 0; i < arrayLength; i++)
    insertBH(array[i], H);
  return H;
}

static void
bh_print_dot_aux(BinHeap H,
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
bh_print_dot(BinHeap H,
             FILE* stream)
{
  fprintf(stream, "digraph BinaryHeap {\n");
  bh_print_dot_aux(H, stream);
  fprintf(stream, "}\n");
}

static void
percolateUp(Position pos,
            BinHeap H)
{
  int i;
  int target = H->Elements[pos];
  for(i = pos; H->Elements[i/2] > target; i/=2)
  {
    H->Elements[i] = H->Elements[i/2];
  }
  H->Elements[i] = target;
}
  
static void
percolateDown(Position pos,
              BinHeap H)
{
  int target = H->Elements[pos];
  int i, child;
  for(i = pos; 2*i <= H->Size; i = child)
  {
    child = 2*i;
    if (child < H->Size && H->Elements[child] > H->Elements[child+1])
      child++;
    if (target > H->Elements[child])
      H->Elements[i] = H->Elements[child];
    else
      break;
  }
  H->Elements[i] = target;
}

BinHeap
buildHeap(int* array,
          int arrayLength)
{
  BinHeap H = initializeBH(2*arrayLength);
  
  // We first construct a complete binary tree
  int i;
  for(i = 1; i < arrayLength + 1; i++)
    H->Elements[i] = array[i-1];
  H->Size = arrayLength;

#ifdef DEBUG  
  printf("H->Size: %d\n", H->Size);
  printArray(H->Elements, H->Size+1);
#endif
  
  // Then we carry out figure 6.14 (p.187) to restore the
  // binary heap property
  for( i = H->Size / 2; i > 0; i--)
  {
    percolateDown(i, H);
#ifdef DEBUG
    printf("After percolateDown(%d):", i);
    printArray(H->Elements, H->Size+1);
#endif    
  }
  return H;
}

void
decreaseKey(Position P,
            int delta,
            BinHeap H)
{
  if(delta < 0)
    fatal("delta cannot be negative!");
#ifdef DEBUG
  printf("Value at %d: %d\n", P, retrieve(P,T));
#endif  
  H->Elements[P] -= delta;
  percolateUp(P, H);
}

void
increaseKey(Position P,
            int delta,
            BinHeap H)
{
  if (delta < 0)
    fatal("delta cannot be negative!");
  H->Elements[P] += delta;
  percolateDown(P, H);
}

void
delete(Position P,
       BinHeap H)
{
  decreaseKey(P, INT_MAX-10, H);
  deleteMinBH(H);
}
