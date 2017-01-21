#include "stack322.h"
#include "utility.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_initalizeStack();
void test_push();
void test_top();
void test_pop();
void test_topAndPop();
void test_findMin();

int main(int argc, char** argv)
{
  printf("///////////////////////\n");
  printf("// STACK 3-22 TEST\n");
  printf("///////////////////////\n\n");
  test_initalizeStack(); printf("\n");
  test_push();           printf("\n");
  test_top();            printf("\n");
  test_pop();            printf("\n");
  test_topAndPop();      printf("\n");
  test_findMin();        printf("\n");
  exit(0);  
}

void
test_initalizeStack()
{
  printf("TEST: initializeStack\n");

  ET test_Q1[3] = {1,2,3};
  Stack Q1 = initializeStack(test_Q1, 3);
  printStack(Q1);
  disposeStack(Q1);
}

void
test_push()
{
  printf("TEST: push\n");

  ET test_Q1[1] = {1};
  Stack Q1 = initializeStack(test_Q1, 1);
  printStack(Q1);
  push(2, Q1);
  printf("After push 2:\n");
  printStack(Q1);
  disposeStack(Q1);
}

void
test_top()
{
  printf("TEST: top\n");
  ET test_Q1[1] = {1};
  Stack Q1 = initializeStack(test_Q1, 1);
  printStack(Q1);
  printf("Top element of Stack: %d\n", top(Q1));
  disposeStack(Q1);
}

void
test_pop()
{
  printf("TEST: pop\n");
  ET test_Q1[3] = {1,2,3};
  Stack Q1 = initializeStack(test_Q1, 3);
  printStack(Q1);
  printf("After pop the element:\n");
  pop(Q1);
  printStack(Q1);
  push(2, Q1);
  printf("After push 2:\n");
  printStack(Q1);
  disposeStack(Q1);
}

void
test_topAndPop()
{
  printf("TEST: topAndPop\n");
  ET test_Q1[3] = {1,2,3};
  Stack Q1 = initializeStack(test_Q1, 3);
  printStack(Q1);
  printf("Pop the element: %d\n", topAndPop(Q1));
  printf("After pop the element:\n");
  printStack(Q1);
  disposeStack(Q1);
}

void
test_findMin()
{
  printf("TEST: findMin\n");
  ET test_Q1[4] = {1,10,1,100};
  Stack Q1 = initializeStack(test_Q1, 4);
  printStack(Q1);
  printf("The smallest element in the stack: %d\n", findMin(Q1));
  disposeStack(Q1);
}
