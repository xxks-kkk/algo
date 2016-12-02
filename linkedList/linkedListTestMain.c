#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
  List L, P, Q, Q1, Q2, R; 
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  L = initializeList(test_L, 6);

  printf("TEST: printList\n");
  if(L != NULL)
  {
    /* test printList */
    printList(L);
    printf ("\n");
  }

  printf("TEST: printLots\n");
  ET test_P[] = {1,3,8,5,7,6};
  P = initializeList(test_P, 6);
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
  Q = initializeList(test_Q, 5);
  swap(Q, 3);
  printList(Q);
  printf("\n");

  printf("TEST: intersectionSortedLists\n");
  ET test_Q1[] = {1,2,3,3};
  ET test_Q2[] = {1,3,3};
  Q1 = initializeList(test_Q1, 4);
  Q2 = initializeList(test_Q2, 3);
  R = intersectionSortedLists(Q1, Q2);
  printList(R);
  printf("\n");

  printf("TEST: unionSortedLists\n");
  ET test_Q31[] = {1,3,3};
  ET test_Q32[] = {2,3,4,5};
  List Q31 = initializeList(test_Q31, 3);
  List Q32 = initializeList(test_Q32, 4);
  R = unionSortedLists(Q31, Q32);
  printList(R);
  printf("\n");
  
  printf("TEST: reverseList\n");
  reverseList(Q31);
  printList(Q31);
  printf("\n");
  
  return 0;
}
