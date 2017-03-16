#include "sc.h"

struct ListNode
{
  int Element;
  Position Next;
};

struct HashTbl
{
  int TableSize;
  List *TheLists; // an array of lists, allocated later
};

HashTable
initializeTable(
  int TableSize)
{
  HashTable H;
  int i;

  H = malloc(sizeof(struct HashTbl));
  assert(H);

  H->TableSize = TableSize;

  H->TheLists = malloc(H->TableSize * sizeof(List));
  assert(H->TheLists);
  
  for(i = 0; i < TableSize; i++)
  {
    H->TheLists[i] = malloc(sizeof(struct ListNode));
    assert(H->TheLists[i]);
    H->TheLists[i]->Next = NULL;
  }
  return H;
}

// We assume dummy node
static void
deleteList(Position L)
{
  Position dummyL, tmp;
  dummyL = L->Next;
  L->Next = NULL;

  while(dummyL != NULL)
  {
    tmp = dummyL->Next;
    free(dummyL);
    dummyL = tmp;
  }
}

void
destroyTable(HashTable H)
{
  int i;

  for(i = 0; i < H->TableSize; i++)
  {
    deleteList(H->TheLists[i]);
    free(H->TheLists[i]); //free the dummy node
  }
  free(H);
}

static int
hash(int key, int TableSize)
{
  return key % TableSize;
}

Position
find(int key, HashTable H)
{
  List L;
  Position P;
  L = H->TheLists[hash(key, H->TableSize)];
  P = L->Next;
  while(P != NULL && P->Element != key)
  {
    P = P->Next;
  }
  return P;
}

void
insert(int key, HashTable H)
{
  Position tmp;
  List L;
  L = H->TheLists[hash(key, H->TableSize)];  
  tmp = malloc(sizeof(struct ListNode));
  tmp->Element = key;
  tmp->Next = L->Next;
  L->Next = tmp;
}

int
retrieve(Position P)
{
  return P->Element;
}

static void
printList(List L)
{
  Position tmp;
  tmp = L->Next;
  while(tmp != NULL)
  {
    printf("%d%s", tmp->Element, (tmp->Next) ? ("->") : (""));
    tmp = tmp->Next;
  }
  printf("\n");
}

void
printHashTable(HashTable H)
{
  int i;
  for(i = 0; i < H->TableSize; i++)
  {
    printf("%d|", i);
    printList(H->TheLists[i]);
  }
}

HashTable
initializeTableFromArray(int* array, int arrayLength, int TableSize)
{
  int i;
  HashTable H;
  H = initializeTable(TableSize);
  for(i = 0; i < arrayLength; i++)
  {
    insert(array[i], H);
  }
  return H;
}
