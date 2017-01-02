#include "circularLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  ET  Element;
  Pos Prev;
  Pos Next;
};

/**---- BASIC LIST OPERATION ----**/

List
makeEmpty()
{
  List L = malloc(sizeof(struct Node));
  L->Next = NULL;
  L->Prev = NULL;
  return L;
}

void
insert(ET elem, List L, Pos position)
{
  Pos tmpNode;
  tmpNode = malloc(sizeof(struct Node));
  tmpNode->Element = elem;
  tmpNode->Next = position->Next;
  if (position->Next != NULL)
  {
    position->Next->Prev = tmpNode;
  }
  tmpNode->Prev = position;
  position->Next = tmpNode;
}

void
deleteNode(Pos position)
{
  Pos tmp = position;
  tmp->Prev->Next = tmp->Next;
  tmp->Next->Prev = tmp->Prev;
  free(tmp);
}


/**---- VARIOUS LIST PROBLEMS ----**/

List
initializeList(ET A[], int arrayLen)
{
  List L = makeEmpty();
  Pos dummyL = L;
  int i;
  
  for(i = 0; i < arrayLen; i++)
  {
    insert(A[i], L, dummyL);
    dummyL = dummyL->Next;
  }
  dummyL->Next = L;
  L->Prev = dummyL;
  return L;
}

void
printList(List L)
{
  Pos dummyL;
  dummyL = L->Next;

  while(dummyL != NULL && dummyL != L)
  {
    printf("%s %d <->", (dummyL->Prev == L) ? ("<->") : (""), dummyL->Element);
    dummyL = dummyL->Next;
  }
}

/* Runtime analysis: O(MN)
 */
ET
circularDoubleLinkedListJosephus(ET N, ET M)
{
  /* int i; */
  /* ET people[N] = {0}; */
  /* for (i = 0; i < N; i++) */
  /* { */
  /*   people[i] = i + 1; */
  /* } */

  int counter = N; // count how many elements left
  int j = 1;       // count how many element we have traversed for each round
  
  // initialize the arr
  int i;
  int* people;

  people = calloc(N, sizeof(int));
  //people = malloc(N*sizeof(int)); // can use either 'malloc' or 'calloc' in this case

  for ( i = 0; i < N; i++)
  {
    *(people + i) = i + 1;
  }
  
  // construct the list
  List L = initializeList(people, N);
  Pos dummyL = L->Next;

  // start to work on the problem
  ET M_prime = M % N;

  while (counter > 1)
  {
    while (j < M_prime)
    {
      dummyL = dummyL->Next;
      // handle the case when a data node is followed by a header.
      // in that case, we don't want to remove the header node and we
      // want to move on to the actual data node.
      if (dummyL != L)
      {
        j++;
      }
    }
    Pos tmp = dummyL->Next;
    deleteNode(dummyL);
    dummyL = tmp;

    counter--;
    j = 1;
    // we should start to count M when we on a data node, not a header node.
    if (dummyL == L)
    {
      dummyL = dummyL->Next;
    }
  }

  return dummyL->Element;  
}
