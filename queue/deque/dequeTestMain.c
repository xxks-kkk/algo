#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void test_createDeque();
void test_push();
void test_initializeDeque();
void test_pop();
void test_inject();
void test_eject();
void test_isEmpty();
void test_makeEmpty();


int main()
{
  printf("///////////////////////\n");
  printf("// DEQUE TEST\n");
  printf("///////////////////////\n\n");

  test_createDeque();      printf("\n");
  test_push();             printf("\n");
  test_initializeDeque();  printf("\n");
  test_pop();              printf("\n");
  test_inject();           printf("\n");
  test_eject();            printf("\n");
  test_isEmpty();          printf("\n");
  test_makeEmpty();        printf("\n");
  return 0;
}

void
test_createDeque()
{
  printf("TEST: createDeque\n");
  Deque D = createDeque(3);
  printDeque(D);
  disposeDeque(D);
}

void
test_push()
{
  printf("TEST: push\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Deque D = createDeque(10);
  printDeque(D);
  int i;
  for (i = 0; i < 3; i++)
  {
    printf("push: %d\n", test_Q1[i]);
    push(test_Q1[i], D);
  }
  printDeque(D);
  disposeDeque(D);  
}

void
test_initializeDeque()
{
  printf("TEST: initializeDeque\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Deque D = initializeDeque(test_Q1, 3);
  printDeque(D);
  disposeDeque(D);  
}

void
test_pop()
{
  printf("TEST: pop\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Deque D = initializeDeque(test_Q1, 3);
  printf("Pop element: %d\n", pop(D));
  printDeque(D);
  disposeDeque(D);    
}

void
test_inject()
{
  printf("TEST: inject\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Deque D = createDeque(10);
  printDeque(D);
  int i;
  for (i = 0; i < 3; i++)
  {
    printf("inject: %d\n", test_Q1[i]);
    inject(test_Q1[i], D);
  }
  printDeque(D);
  disposeDeque(D);  
}

void
test_eject()
{
  printf("TEST: eject\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Deque D = initializeDeque(test_Q1, 3);
  printDeque(D);
  printf("Eject element: %d\n", eject(D));
  printDeque(D);
  disposeDeque(D);    
}

void
test_isEmpty()
{
  printf("TEST: isEmpty\n");
  Deque D = createDeque(3);
  printDeque(D);
  printf("is Deque empty: %s\n", (isEmpty(D)) ? ("Yes") : ("No"));
  disposeDeque(D);
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  D = initializeDeque(test_Q1, 3);
  printDeque(D);
  printf("is Deque empty: %s\n", (isEmpty(D)) ? ("Yes") : ("No"));
  disposeDeque(D);
}

void
test_makeEmpty()
{
  printf("TEST: makeEmpty\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Deque D = initializeDeque(test_Q1, 3);
  printDeque(D);
  makeEmpty(D);
  printf("test_Q1 after makeEmpty: \n");
  printDeque(D);
  printf("Is test_Q1 empty?: %s\n", (isEmpty(D)) ? ("Yes") : ("False"));
}

