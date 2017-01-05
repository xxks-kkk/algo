#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

struct Node
{
  ET Element;
  Pos Next;
};

/**---- BASIC LIST OPERATION ----**/

void
insert(ET elem, List L, Pos position)
{
  Pos tmpNode;
  tmpNode = malloc(sizeof(struct Node));
  if (tmpNode == NULL)
  {
    exit(EXIT_FAILURE);
  }
  tmpNode->Element = elem;
  tmpNode->Next = position->Next;
  position->Next = tmpNode;
}

List
makeEmpty()
{
  List L = malloc(sizeof(struct Node));
  L->Next = NULL;
  return L;
}

void
deleteList(List L)
{
  Pos dummyL, tmp;
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
deleteAll(List L)
{
  deleteList(L);
  free(L);
}

ET
getElement(Pos loc)
{
  return loc->Element;
}

void
deleteNode(ET elem, List L)
{
  Pos dummyL = L->Next;
  Pos dummyPrev = L;

  for(; dummyL != NULL; dummyPrev = dummyL, dummyL = dummyL->Next)
  {
    if (dummyL->Element == elem)
    {
      Pos tmp = dummyL;
      dummyPrev->Next = dummyL->Next;
      free(tmp);
      return;
    }
  }
}


/**---- VARIOUS LIST PROBLEMS ----**/

static List
initializeNoHeaderList(ET A[], int arrayLen)
{
  int i = 0;
  Pos tmpNode;;

  if (arrayLen == 0)
  {
    return NULL;
  }
  tmpNode = malloc(sizeof(struct Node));
  if (tmpNode == NULL)
  {
    exit(EXIT_FAILURE);
  }
  tmpNode->Element = A[i];
  tmpNode->Next = initializeNoHeaderList(A+1, arrayLen-1);
  return tmpNode;
}

List
initializeList(ET A[], int arrayLen)
{
  Pos header;

  header = malloc(sizeof(struct Node));
  if (header == NULL)
  {
    exit(EXIT_FAILURE);
  }
  header->Next = initializeNoHeaderList(A, arrayLen);
  return header;
}

void
printList(List L)
{
  Pos dummy; // creates a dummy node to traverse the list

  dummy = L->Next;

  while (dummy != NULL)
  {
    printf("%d%s", dummy->Element, (dummy->Next) ? ("->") : (""));
    dummy = dummy->Next;
  }
}

static void
printListReverseHelper(List L)
{
  if (L == NULL)
  {
    return;
  }
  printListReverseHelper(L->Next);
  printf("%d->", L->Element);
}

void printListReverse(List L)
{
  Pos dummyL = L->Next;
  printListReverseHelper(dummyL);
}

void
printLots(List L, List P)
{
  Pos dummyP, dummyL; // creates dummy nodes to traverse the list
  int i = 0, idx, outofelement;
  
  dummyP = P->Next;
  dummyL = L->Next;

  while (dummyP != NULL)
  {
    idx = dummyP->Element;
    if (idx >= 0)
    {
      // if the idx is larger or equal to where the dummyL currently is
      // we don't want to reset the dummyL to the very beginning of
      // the list L again to redo the traverse.
      if (idx < i)
      {
        dummyL = L->Next;
        i = 0;
      }
      for(; i < idx; i++)
      {
        if (dummyL->Next != NULL)
        {
          dummyL = dummyL->Next;
        }
        else
        {
          outofelement = 1;
          break;
        }
      }
      if (outofelement == 1)
      {
        printf("No element in position %d, ", idx);
      }
      else{
        printf("%d, ", dummyL->Element);
      }
    }
    else
    {
      exit(EXIT_FAILURE);
    }
    outofelement = 0;
    dummyP = dummyP->Next;
  }
}

void
swap(List L, ET elem)
{
  Pos dummyCurrent = L->Next;
  Pos dummyPrev = L->Next;
  Pos dummyCurrentNext;
  
  while(dummyCurrent != NULL)
  {
    if (dummyCurrent->Element == elem)
    {
      dummyCurrentNext = dummyCurrent->Next;
      // let's do swap
      if (dummyCurrentNext != NULL)
      {
        dummyPrev->Next = dummyCurrentNext;
        dummyCurrent->Next = dummyCurrentNext->Next;
        dummyCurrentNext->Next = dummyCurrent;
        break;
      }
      else
      {
        printf("Cannot swap because of the %d is the last node\n", elem);
        break;
      }
    }
    else
    {
      dummyPrev = dummyCurrent;
      dummyCurrent = dummyCurrent->Next;
    }
  }
}

/* O(MN)
 */
static List
intersectionSortedLists1(List L, List P)
{
  Pos dummyL = L->Next;
  Pos dummyP = P->Next;
  List R = malloc(sizeof(struct Node));
  Pos dummyR = R;
  int bookkeeping[100]={0}; // prevent duplicate appearance in R
  
  while(dummyL != NULL)
  {
    if (dummyL->Element == dummyP->Element && bookkeeping[dummyP->Element] == 0)
    {
      bookkeeping[dummyP->Element] = 1;
      /* Pos tmpNode; */
      /* tmpNode = malloc(sizeof(struct Node)); */
      /* tmpNode->Element = dummyL->Element; */
      /* tmpNode->Next = dummyR->Next; */
      /* dummyR->Next = tmpNode; */
      insert(dummyL->Element, R, dummyR);
      dummyR = dummyR->Next;
    }
    dummyP = dummyP->Next;
    if (dummyP == NULL)
    {
      dummyL = dummyL->Next;
      dummyP = P->Next;
    }
  }
  return R;
}

/* O(M+N), utilized info that input lists are sorted
 */
static List
intersectionSortedLists2(List L, List P)
{
  Pos dummyL = L->Next;
  Pos dummyP = P->Next;
  List R = malloc(sizeof(struct Node));
  Pos dummyR = R;
  int bookkeeping[100]={0}; // prevent duplicate appearance in R
  
  while(dummyL != NULL && dummyP != NULL)
  {
    if (dummyL->Element < dummyP->Element)
    {
      dummyL = dummyL->Next;
    }
    else if (dummyL->Element > dummyP->Element)
    {
      dummyP = dummyP->Next;
    }
    else
    {
      if (bookkeeping[dummyL->Element] == 0)
      {
        bookkeeping[dummyL->Element] = 1;
        /* Pos tmpNode; */
        /* tmpNode = malloc(sizeof(struct Node)); */
        /* tmpNode->Element = dummyL->Element; */
        /* tmpNode->Next = dummyR->Next; */
        /* dummyR->Next = tmpNode; */
        insert(dummyL->Element, R, dummyR);
        dummyR = dummyR->Next;
      }
      dummyL = dummyL->Next;
      dummyP = dummyP->Next;
    }
  }
  return R;
}

List
intersectionSortedLists(List L, List P)
{
  //return intersectionSortedLists1(List L, List P);
  return intersectionSortedLists2(L, P);
}

/* understand the following logic
 * by drawing a venn graph of two sets
 */
List
unionSortedLists(List L, List P)
{
  Pos dummyL = L->Next;
  Pos dummyP = P->Next;
  List R = malloc(sizeof(struct Node));
  Pos dummyR = R;
  ET bookkeeping[100] = {0}; // prevent the duplicates
  
  while (dummyL != NULL && dummyP != NULL)
  {
    if (dummyL->Element < dummyP->Element)
    {
      if (bookkeeping[dummyL->Element] == 0)
      {
        insert(dummyL->Element, R, dummyR);
        bookkeeping[dummyL->Element] = 1;
        dummyR = dummyR->Next;
      }
      dummyL = dummyL->Next;
    }
    else if (dummyL->Element > dummyP->Element)
    {
      if (bookkeeping[dummyP->Element] == 0)
      {
        insert(dummyP->Element, R, dummyR);
        bookkeeping[dummyP->Element] = 1;
        dummyR = dummyR->Next;
      }
      dummyP = dummyP->Next;
    }
    else
    {
      if (bookkeeping[dummyP->Element] == 0)
      {
        insert(dummyP->Element, R, dummyR);
        bookkeeping[dummyP->Element] = 1;
        dummyR = dummyR->Next;
      }
      dummyP = dummyP->Next;
      dummyL = dummyL->Next;
    }
  }

  while (dummyL != NULL)
  {
    if (bookkeeping[dummyL->Element] == 0)
    {
      insert(dummyL->Element, R, dummyR);
      bookkeeping[dummyL->Element] = 1;
      dummyR = dummyR->Next;
    }
    dummyL = dummyL->Next;
  }

  while (dummyP != NULL)
  {
    if (bookkeeping[dummyP->Element] == 0)
    {
      insert(dummyP->Element, R, dummyR);
      bookkeeping[dummyP->Element] = 1;
      dummyR = dummyR->Next;
    }
    dummyP = dummyP->Next;
  }

  return R;
}

Pos
find(ET target, List L)
{
  Pos dummyL = L->Next;
  while (dummyL != NULL)
  {
    if (dummyL->Element == target)
    {
      return dummyL;
    }
    dummyL = dummyL->Next;
  }
  return NULL;
}

static Pos
findRecursiveHelper(ET target, List L)
{
  if (L->Element == target)
  {
    return L;
  }
  if (L == NULL)
  {
    return NULL;
  }
  return findRecursiveHelper(target, L->Next);
}

Pos
findRecursive(ET target, List L)
{
  return findRecursiveHelper(target, L->Next); 
}

/* The idea for this routine is quite simple:
 * We basically go through the original list, and insert node we visit
 * at the very beginning of the new list (just like a stack). Then,
 * we return the new list.
 */
List
reverseList(List L)
{
  Pos dummyL = L->Next;
  List R = malloc(sizeof(struct Node));
  
  while (dummyL != NULL)
  {
    // Remove element from old list.
    Pos tmpNode = dummyL;
    dummyL = dummyL->Next;

    // Insert element in new list.
    tmpNode->Next = R->Next;
    R->Next = tmpNode;
  }
  return R;
}

/* This routine is list here for legacy reason.
 * It works but the code itself is not as clean
 * as reverseListIterative
 *
 * dummyCurrent->Next = NULL is wrong b/c
 * instead of break the link between 3 and 2,
 * it actually breaks the link between 2 and 1,
 * which we just created. That's why
 * when we reverse 1->2->3, 3->2-> got printed 
 * instead of 3->2->1
 */ 
/* void */
/* reverseListIterative(List L) */
/* { */
/*   Pos dummyCurrent = L->Next, */
/*       dummyNext = dummyCurrent->Next, */
/*       dummyNextNext; */

/*   while(dummyCurrent != NULL) */
/*   { */
/*     dummyNextNext = dummyNext->Next; */

/*     dummyNext->Next = dummyCurrent; */
/*     L->Next->Next = NULL; //dummyCurrent->Next = NULL; // is wrong (be careful) */
/*     dummyCurrent = dummyNext; */
/*     dummyNext = dummyNextNext; */

/*     if (dummyNext == NULL) */
/*     { */
/*       L->Next = dummyCurrent; */
/*       break; */
/*     } */
/*   } */
/* } */

void
reverseListIterative(List L)
{
  Pos dummyCurrent = L->Next,
      dummyPrev = NULL,
      dummyNext;

  while (dummyCurrent != NULL)
  {
    dummyNext = dummyCurrent->Next;
    dummyCurrent->Next = dummyPrev;
    dummyPrev = dummyCurrent;
    dummyCurrent = dummyNext;
  }
  L->Next = dummyPrev;
}

static List P;
static void
reverseListRecursiveHelper(List L)
{
  if (L->Next == NULL)
  {
    P = L;
    return;
  }
  reverseListRecursiveHelper(L->Next);
  L->Next->Next = L;
  L->Next = NULL;
}

void
reverseListRecursive(List L)
{
  reverseListRecursiveHelper(L->Next);
  L->Next = P;
}

/* Returns an array of header nodes 
 */
static List
makeEmptyArrayOfNodes(numBuckets)
{
  Pos Buckets = malloc(numBuckets * sizeof(struct Node));

  int k;
  for (k = 0; k < numBuckets; k++)
  {
    Buckets[k].Next = NULL;
  }

  return Buckets;
}

int*
radixSort(int studentRecords[], int N)
{
  // NOTE: "start" and "end" value are chosen
  // based upon the fact of SSN is 9-digit number
  int* tmpArray = calloc(N, sizeof(int));
  int numBuckets = 1000;
  int numPass = 3;

  Pos dummyL, Buckets;
  int i, j, start, end, currTmp, k;
  
  for(i = 0; i < numPass; i++)
  {
    if (i == 1 || i == 2)
    {
      free(Buckets);
    }
    Buckets = makeEmptyArrayOfNodes(numBuckets);
    if (i == 0)
    {           
      // first pass
      k = 0;
      start = 6;
      end = 8;
      tmpArray = studentRecords;
    }
    if (i == 1)
    {
      // second pass
      k = 0;
      start = 3;
      end = 5;
    }
    if (i == 2)
    {
      // third pass
      k = 0;
      start = 0;
      end = 2;
    }
    for (j = 0; j < N; j++)
    {
      currTmp = chunk_number(tmpArray[j], start, end);
      dummyL = &Buckets[currTmp];
      while(dummyL->Next != NULL)
      {
        dummyL = dummyL->Next;
      }
      insert(tmpArray[j], &Buckets[currTmp], dummyL);
    }
    if (i ==  1 || i == 2)
    {
      free(tmpArray);
      tmpArray = calloc(N, sizeof(int));
    }
    for (j = 0; j < numBuckets; j++)
    {
      dummyL = (&Buckets[j])->Next;
      while(dummyL != NULL)
      {
        tmpArray[k] = dummyL->Element;
        dummyL = dummyL->Next;
        k++;
      }
    }
  }
  
  free(Buckets);
  return tmpArray;
}
