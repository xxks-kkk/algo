#include "bh.h"

struct HeapStruct
{
  int Capacity; // maximum heap size
  int Size;     // current heap size
  ET *Elements; // an array of element
};

BinHeap
initialize(
  int MaxElements)
{
  BinHeap H;

  H = malloc(sizeof(struct HeapStruct));
  assert(H);

  // Allocate the array plus one extra for sentinel
  H->Elements = malloc(sizeof(ET) * (MaxElements + 1));
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
makeEmpty(
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
insert(ET X,
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
ET
deleteMin(BinHeap H)
{
  int i, child;
  ET minElement, lastElement;

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

ET
findMin(BinHeap H)
{
  return H->Elements[0];
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
// TODO: Add O(N) buildHeap routine here as the second option.
BinHeap
initializeBinHeapFromArray(
  ET* array,
  int arrayLength)
{
  int i;
  BinHeap H = initialize(100);
  for(i = 0; i < arrayLength; i++)
    insert(array[i], H);
  return H;
}

static void
bh_print_dot_aux(BinHeap H,
                 FILE* stream)
{
  int i;
  for(i=1; i*2 <= H->Size; i++)
  {
    fprintf(stream, "%d->%d;\n", H->Elements[i], H->Elements[2*i]);
    if (i*2 != H->Size)
      fprintf(stream, "%d->%d\n", H->Elements[i], H->Elements[2*i+1]);
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
  
