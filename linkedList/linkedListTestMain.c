#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

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

  printf("TEST: intersectionSortedLists\n");
  ET test_Q1[] = {1,2,3,3};
  ET test_Q2[] = {1,3,3};
  List Q1 = initializeList(test_Q1, 4);
  List Q2 = initializeList(test_Q2, 3);
  List R = intersectionSortedLists(Q1, Q2);
  printList(R);
  return 0;
}
