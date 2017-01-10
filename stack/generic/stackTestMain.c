#include "stack.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void test_initalizeStack();
void test_createStack();
void test_push();
void test_top();
void test_pop();
void test_topAndPop();

int main()
{
  printf("///////////////////////\n");
  printf("// STACK TEST\n");
  printf("///////////////////////\n\n");

  test_initalizeStack(); printf("\n");
  test_createStack();    printf("\n");
  test_push();           printf("\n");
  test_top();            printf("\n");
  test_pop();            printf("\n");
  test_topAndPop();      printf("\n");

  return 0;
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
test_createStack()
{
  printf("TEST: createStack\n");

  Stack s = createStack(3);
  printStack(s);
  disposeStack(s);
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
}
