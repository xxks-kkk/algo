#include "lazyDeleteLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/* number of the nodes for the list 
 */
static int numNodes;

/* number of nodes marked as deleted
 */
static int numDeleted;

struct Node
{
  ET Element;
  Pos Next;
  bool deleted;
};

/**---- BASIC LIST OPERATION ----**/

/* Make empty linked list
 */
List
makeEmpty()
{
  List L = malloc(sizeof(struct Node));
  L->Next = NULL;
  numNodes = 0;
  numDeleted = 0;
  return L;
}

/* Is the list empty (only contains a header node)
 */
int
IsEmpty(List L)
{
  return L->Next == NULL;
}

/* Is the given node pointed by P the last node in the list
 */
int
IsLast(Pos P, List L)
{
  return P->Next == NULL;
}

/* Find the first appearance of the elem in the list
 */
Pos
Find(ET elem, List L)
{
  Pos dummyL;
  for(dummyL = L->Next;
      dummyL != NULL;
      dummyL = dummyL->Next)
  {
    if (dummyL->Element == elem)
    {
      return dummyL;
    }
  }
  return NULL;
}

/* Find the node contains "elem" in the given list and delete it.
 */
void
deleteNode(ET elem, List L)
{
  Pos dummyL = L->Next;
  Pos dummyPrev = L;

  for(;
      dummyL != NULL;
      dummyPrev = dummyL, dummyL = dummyL->Next)
  {
    if (dummyL->Element == elem)
    {
      dummyL->deleted = true;
      numDeleted++;
    }
  }
  
  if (numDeleted == numNodes - numDeleted)
  {
    deleteMarkedNodes(L);
  }
}

void
deleteMarkedNodes(List L)
{
  Pos dummyL = L->Next;
  Pos dummyLPrev = L;
  
  while(dummyL != NULL)
  {
    if (dummyL->deleted == true)
    {
      Pos tmp = dummyL;
      dummyLPrev->Next = dummyL->Next;
      dummyL = dummyL->Next;
      free(tmp);
      numDeleted--;
      numNodes--;
    }
    else
    {
      dummyLPrev = dummyL;
      dummyL = dummyL->Next;
    }
  }
}

Pos
FindPrevious(ET elem, List L)
{
  Pos dummyLPrev = L,
      dummyL = L->Next;
  while(dummyL != NULL)
  {
    if (dummyL->Element == elem)
    {
      return dummyLPrev;
    }
    dummyLPrev = dummyL;
    dummyL = dummyL->Next;
  }
  return NULL;
}

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
  tmpNode->deleted = false;
  tmpNode->Next = position->Next;
  position->Next = tmpNode;
  numNodes++;
}

/* We don't delete the header node. 
 * In other words, the empty list contains a header node.
 */
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

  numNodes = 0;
  numDeleted = 0;
}

/* delete all: the list and the header node
 */
void
deleteAll(List L)
{
  deleteList(L);
  free(L);
}

Pos
Header(List L)
{
  return L;
}

Pos
First(List L)
{
  return L->Next;
}

Pos
Advance(Pos P)
{
  return P->Next;
}

ET
getElement(Pos loc)
{
  return loc->Element;
}

int
getNumNodes()
{
  return numNodes;
}

void
setNumNodes(int N)
{
  numNodes = N;
}

int
getNumDeleted()
{
  return numDeleted;
}

void
setNumDeleted(int N)
{
  numDeleted = N;
}

void
printList(List L)
{
  Pos dummyL = L->Next;
  while(dummyL != NULL)
  {
    printf("%d(%d)%s ",
           dummyL->Element,
           dummyL->deleted,
           (dummyL->Next == NULL) ? ("\n") : ("->"));
    dummyL = dummyL->Next;
  }
  printf("numNodes: %d\n", numNodes);
  printf("numDeleted: %d\n", numDeleted);
}

List
initializeList(ET A[], int arrayLen)
{
  List L = makeEmpty();
  Pos dummyL = L;
  int i;
  for (i = 0; i < arrayLen; i++)
  {
    insert(A[i], L, dummyL);
    dummyL = dummyL->Next;
  }
  return L;
}
    
