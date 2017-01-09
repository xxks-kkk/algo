#include "lazyDeleteLinkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void test_printList();
void test_find();
void test_deleteNode();
void test_deleteMarkedNodes();
void test_list_independence();

int main()
{
  printf("///////////////////////\n");
  printf("// LAZY DELETION LINKED LIST TEST\n");
  printf("///////////////////////\n\n");
  
  test_printList();               printf("\n");

  test_find();                    printf("\n");
  
  test_deleteNode();              printf("\n");

  test_deleteMarkedNodes();       printf("\n");
  
  test_list_independence();       printf("\n");
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
test_find()
{
  printf("TEST: find\n");
  Pos loc;
  ET test_Q1[] = {1,2,3};
  List Q1 = initializeList(test_Q1, 3);
  loc = Find(3, Q1);
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

  ET test_Q2[] = {1,2,3,4};
  List Q2 = initializeList(test_Q2, 4);
  printf("Original list: ");
  printList(Q2);
  deleteNode(1, Q1);
  deleteNode(2, Q1);
  printf("After deletion: ");
  printList(Q2);
  deleteAll(Q2);  
}

void
test_deleteMarkedNodes()
{
  printf("TEST: deleteMarkedNodes\n");
  ET test_Q1[] = {1,2,3};
  List Q1 = initializeList(test_Q1, 3);
  printf("Original list: ");
  printList(Q1);
  deleteNode(2, Q1);
  printf("After deletion: ");
  printList(Q1);
  deleteMarkedNodes(Q1);
  printf("After deleteMarkedNodes: ");
  printList(Q1);
  deleteAll(Q1);
}


void
test_list_independence()
{
  /* Test out whether static global variables
   * will stay independence (i.e. numNodes, numDeleted)
   * for different instantiation. The answer is YES!
   */
  printf("TEST: list_independence\n");
  ET test_Q1[] = {1,2,3};
  List Q1 = initializeList(test_Q1, 3);
  printf("Original list: ");
  printList(Q1);
  deleteNode(2, Q1);
  printf("After deletion: ");
  printList(Q1);
  deleteAll(Q1);
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printList(L);
  deleteNode(45,L);
  printf("After deletion: ");
  printList(L);
  deleteAll(L);
}

