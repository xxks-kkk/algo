#include "linkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void test_printList();
void test_printListReverse();
void test_printLots();
void test_intersectionSortedLists();
void test_unionSortedLists();
void test_reverseList();
void test_swapLL();
void test_find();
void test_deleteNode();
void test_radixSort();
int* construct_ssn(int N);
void test_selfAdjustInsert();
void test_selfAdjustFind();

int main()
{
  printf("///////////////////////\n");
  printf("// LINKED LIST TEST\n");
  printf("///////////////////////\n\n");
  
  test_intersectionSortedLists(); printf("\n");

  test_unionSortedLists();        printf("\n");
  
  test_printList();               printf("\n");

  test_printListReverse();        printf("\n");

  test_printLots();               printf("\n");

  test_reverseList();             printf("\n");

  test_swapLL();                  printf("\n");

  test_find();                    printf("\n");

  test_deleteNode();              printf("\n");

  test_radixSort();               printf("\n");

  test_selfAdjustInsert();        printf("\n");

  test_selfAdjustFind();          printf("\n");
  
  return 0;
}

void
test_printList()
{
  printf("TEST: printList\n");
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printList(L);
  deleteAll(L);
}

void
test_printListReverse()
{
  printf("TEST: printListReverse\n");
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printf("Original:\n");
  printList(L);
  printf("Reverse:\n");
  printListReverse(L);
  deleteAll(L);
  printf("\n");
}

void
test_printLots()
{
  printf("TEST: printLots\n");
  ET test_P[] = {1,3,8,5,7,6};
  List P = initializeList(test_P, 6);
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printLots(L, P);
  printf("\n");
  deleteAll(P);
  deleteAll(L);
}

void
test_intersectionSortedLists()
{
  printf("TEST: intersectionSortedLists\n");
  ET test_Q1[] = {1,2,3,3};
  ET test_Q2[] = {1,3,3};
  printf("List 1 to intersect:");
  List Q1 = initializeList(test_Q1, 4);
  printList(Q1);
  List Q2 = initializeList(test_Q2, 3);
  printf("List 2 to intersect:");
  printList(Q2);
  printf("Intersection result:");
  List R = intersectionSortedLists(Q1, Q2);
  printList(R);
}

void
test_unionSortedLists()
{
  printf("TEST: unionSortedLists\n");
  ET test_Q31[] = {1,3,3};
  ET test_Q32[] = {2,3,4,5};
  List Q31 = initializeList(test_Q31, 3);
  printf("List 1 to union:");
  printList(Q31);
  List Q32 = initializeList(test_Q32, 4);
  printf("List 2 to union:");
  printList(Q32);
  printf("Union result:");
  List R = unionSortedLists(Q31, Q32);
  printList(R);
}


void
test_reverseList()
{
  printf("TEST: reverseList\n");
  ET test_Q33[] = {1,2,3};
  List Q33 = initializeList(test_Q33, 3);
  printf("Original:\n");
  printList(Q33);
  printf("1st Reverse:\n");
  Q33 = reverseList(Q33);
  printList(Q33);
  printf("2nd Reverse:\n");
  reverseListIterative(Q33);
  printList(Q33);
  printf("3rd Reverse:\n");
  reverseListRecursive(Q33);
  printList(Q33);
}

void
test_swapLL()
{
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printf("TEST: swap\n");
  swapLL(L, 44);
  printList(L);
  swapLL(L, -1);
  printList(L);
  swapLL(L, 45);
  printList(L);
  ET test_Q[] = {1,3,2,3,4};
  List Q = initializeList(test_Q, 5);
  swapLL(Q, 3);
  printList(Q);
  deleteAll(L);
  deleteAll(Q);
}

void
test_find()
{
  printf("TEST: find\n");
  Pos loc;
  ET test_Q1[] = {1,2,3};
  List Q1 = initializeList(test_Q1, 3);
  loc = find(3, Q1);
  assert(getElement(loc) == 3);
  loc = findRecursive(3,Q1);
  assert(getElement(loc) == 3);
  printf("Pass all\n");
  deleteAll(Q1);
}

void
test_deleteNode()
{
  printf("TEST: deleteNode\n");
  ET test_Q1[] = {1,2,3};
  List Q1 = initializeList(test_Q1, 3);
  printf("Original list: ");
  printList(Q1);
  deleteNode(2, Q1);
  printf("After deletion: ");
  printList(Q1);
  deleteAll(Q1);
}

void
test_radixSort()
{
  printf("TEST: radixSort\n");
  int N = 100;
  int* ssn = construct_ssn(N);
  printf("Original:\n");
  printArray(ssn,N);
  int* res = radixSort(ssn, N);
  printf("After sort:\n");
  printArray(res, N);
  free(ssn);
}


/* Construct an array of social security number
 * to be used for radix sort test
 */
int* construct_ssn(int N)
{
  int* res = calloc(N, sizeof(int));

  int i;
  for (i = 0; i < N; i++)
  {
    res[i] = random_at_most(999999999);
    while(countDigits(res[i]) != 9)
    {
      res[i] = random_at_most(999999999);
    }
  }
  
  return res;
}

void
test_selfAdjustInsert()
{
  printf("TEST: selfAdjustInsert\n");
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printf("Before self-adjust insert:");
  printList(L);
  selfAdjustInsert(10, L);
  printf("After self-adjust insert:");
  printList(L);
  deleteAll(L);
}

void
test_selfAdjustFind()
{
  printf("TEST: selfAdjustFind\n");
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printf("Before self-adjust find:");
  printList(L);
  selfAdjustFind(45, L);
  printf("After self-adjust find:");
  printList(L);
  deleteAll(L);
}
