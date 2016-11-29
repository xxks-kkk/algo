#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  ET Element;
  Pos Next;
};

int main()
{
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);

  printf("TEST: printList\n");
  if(L != NULL)
  {
    /* test printList */
    printList(L);
    printf ("\n");
  }

  printf("TEST: printLots\n");
  ET test_P[] = {1,3,8,5,7,6};
  List P = initializeList(test_P, 6);
  printLots(L, P);
  printf("\n");

  printf("TEST: swap\n");
  swap(L, 44);
  printList(L);
  printf("\n");
  swap(L, -1);
  printList(L);
  printf("\n");
  swap(L, 45);
  printList(L);
  printf("\n");
  ET test_Q[] = {1,3,2,3,4};
  List Q = initializeList(test_Q, 5);
  swap(Q, 3);
  printList(Q);
  printf("\n");
  
  return 0;
}

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
    printf("%d->", dummy->Element);
    dummy = dummy->Next;
  }
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

void swap(List L, ET elem)
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
