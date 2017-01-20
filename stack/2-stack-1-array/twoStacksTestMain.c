#include "twoStacks.h"
#include "utility.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_initalizeTwoStacks();
void test_push();
void test_top();
void test_pop();
void test_topAndPop();

int
main(int argc, char** argv)
{
  printf("/////////////////////////////////\n");
  printf("// TWO STACKS IN ONE ARRAY TEST\n");
  printf("/////////////////////////////////\n\n");
  test_initalizeTwoStacks(); printf("\n");
  test_push();               printf("\n");
  test_top();                printf("\n");
  test_pop();                printf("\n");
  test_topAndPop();          printf("\n");        
  exit(0);  
}

void
test_initalizeTwoStacks()
{
  printf("TEST: initializeTwoStacks\n");

  ET test_Q1[3] = {1,2,3};
  ET test_Q2[4] = {78,99,85,40};
  TwoStacks Q1 = initializeTwoStacks(test_Q1, 3, test_Q2, 4, 4);
  printTwoStacks(Q1);
  disposeTwoStacks(Q1);
}

void
test_push()
{
  printf("TEST: push\n");
  ET elem1 = 14;
  ET elem2 = 30;
  ET elem3 = 20;
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[4] = {78,99,85,40};
  TwoStacks Q1 = initializeTwoStacks(test_Q1, 3, test_Q2, 4, 4);
  printTwoStacks(Q1);
  printf("Push elem1: %d to TOP_STACK: Q1\n", elem1);
  push(elem1, TOP_STACK, Q1);
  printTwoStacks(Q1);
  printf("Push elem1: %d to BOTTOM_STACK: Q2\n", elem1);
  push(elem1, BOTTOM_STACK, Q1);
  printf("Push elem2: %d to BOTTOM_STACK: Q2\n", elem2);  
  push(elem2, BOTTOM_STACK, Q1);
  printTwoStacks(Q1);
  printf("Push elem3: %d to TOP_STACK: Q1\n", elem2);
  push(elem3, TOP_STACK, Q1);
  printTwoStacks(Q1);
  /* printf("Push elem1: %d to TOP_STACK: Q1\n", elem1); */
  /* push(elem1, TOP_STACK, Q1); */
  /* printTwoStacks(Q1);   */
  disposeTwoStacks(Q1);
}

void
test_top()
{
  printf("TEST: top\n");
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[4] = {78,99,85,40};
  TwoStacks Q1 = initializeTwoStacks(test_Q1, 3, test_Q2, 4, 4);
  printTwoStacks(Q1);
  printf("Top element of TOP_STACK Q1: %d\n", top(TOP_STACK, Q1));
  printf("Top element of BOTTOM_STACK Q2: %d\n", top(BOTTOM_STACK, Q1));  
  disposeTwoStacks(Q1);  
}

void
test_pop()
{
  printf("TEST: pop\n");
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[4] = {78,99,85,40};
  TwoStacks Q1 = initializeTwoStacks(test_Q1, 3, test_Q2, 4, 4);
  printTwoStacks(Q1);
  printf("Remove the top element of TOP_STACK Q1\n");
  pop(TOP_STACK, Q1);
  printTwoStacks(Q1);
  disposeTwoStacks(Q1);    
}

void
test_topAndPop()
{
  printf("TEST: topAndPop\n");
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[4] = {78,99,85,40};
  TwoStacks Q1 = initializeTwoStacks(test_Q1, 3, test_Q2, 4, 4);
  printTwoStacks(Q1);
  printf("Top and pop the TOP_STACK Q1 and the element is: %d\n", topAndPop(TOP_STACK, Q1));
  printTwoStacks(Q1);
  disposeTwoStacks(Q1);      
}
