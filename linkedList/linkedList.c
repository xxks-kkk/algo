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
