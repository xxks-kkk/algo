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
  ET test_arr[] = {23, 44, 45, 57, 89, -1};
  List a = initializeList(test_arr, 6);
  if(a != NULL)
  {
    printList(a);
    printf ("\n");
  }
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
  // creates a dummy node to traverse the list
  List dummy;

  dummy = L->Next;

  while (dummy != NULL)
  {
    printf("%d->", dummy->Element);
    dummy = dummy->Next;
  }
}
