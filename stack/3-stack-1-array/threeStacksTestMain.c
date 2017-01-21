#include "threeStacks.h"
#include "utility.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_createThreeStacks();
void test_initalizeThreeStacks();
void test_push();
void test_top();
void test_pop();
void test_topAndPop();

int
main(int argc, char** argv)
{
  printf("/////////////////////////////////\n");
  printf("// THREE STACKS IN ONE ARRAY TEST\n");
  printf("/////////////////////////////////\n\n");
  test_createThreeStacks();   printf("\n");
  test_initalizeThreeStacks(); printf("\n");
  test_push();               printf("\n");
  test_top();                printf("\n");
  test_pop();                printf("\n");
  test_topAndPop();          printf("\n");        
  exit(0);  
}

void
test_createThreeStacks()
{
 printf("TEST: createThreeStacks\n");
 ThreeStacks Q1 = createThreeStacks(10);
 printThreeStacks(Q1);
 disposeThreeStacks(Q1);
}

void
test_initalizeThreeStacks()
{
  printf("TEST: initializeThreeStacks\n");

  ET test_Q1[3] = {1,2,3};
  ET test_Q2[3] = {5,4,3};
  ET test_Q3[2] = {1,2};
  ThreeStacks Q1 = initializeThreeStacks(test_Q1, 3, test_Q2, 3, test_Q3, 2, 1, 1);
  printThreeStacks(Q1);
  disposeThreeStacks(Q1);
}

void
test_push()
{
  printf("TEST: push\n");
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[3] = {5,4,3};
  ET test_Q3[2] = {1,2};
  ThreeStacks Q1 = initializeThreeStacks(test_Q1, 3, test_Q2, 3, test_Q3, 2, 1, 1);
  printThreeStacks(Q1);
  ET elem1 = 99;
  ET elem2 = 10;
  printf("Push: %d to bottom stack\n", elem1);
  push(elem1, BOTTOM_STACK, Q1);
  printThreeStacks(Q1);
  printf("Push: %d to top stack\n", elem2);
  push(elem2, TOP_STACK, Q1);
  printThreeStacks(Q1);
  /* printf("Push: %d to top stack\n", elem2); */
  /* push(elem2, TOP_STACK, Q1);   */ 
  disposeThreeStacks(Q1);  
}

void
test_top()
{
  printf("TEST: top\n");
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[3] = {5,4,3};
  ET test_Q3[2] = {1,2};
  ThreeStacks Q1 = initializeThreeStacks(test_Q1, 3, test_Q2, 3, test_Q3, 2, 1, 1);
  printThreeStacks(Q1);
  printf("Top element of TOP_STACK: %d\n", top(TOP_STACK, Q1));
  printf("Top element of BOTTOM_STACK: %d\n", top(BOTTOM_STACK, Q1));
  printf("Top element of MIDDLE_STACK: %d\n", top(MIDDLE_STACK, Q1));
  disposeThreeStacks(Q1);    
}

void
test_pop()
{
  printf("TEST: pop\n");
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[3] = {5,4,3};
  ET test_Q3[2] = {1,2};
  ThreeStacks Q1 = initializeThreeStacks(test_Q1, 3, test_Q2, 3, test_Q3, 2, 1, 1);
  printThreeStacks(Q1);
  printf("Remove the top element of TOP_STACK Q1\n");
  pop(TOP_STACK, Q1);
  printThreeStacks(Q1);
  disposeThreeStacks(Q1);      
 }

void
test_topAndPop()
{
  printf("TEST: topAndPop\n");
  ET test_Q1[3] = {1,2,3};
  ET test_Q2[3] = {5,4,3};
  ET test_Q3[2] = {1,2};
  ThreeStacks Q1 = initializeThreeStacks(test_Q1, 3, test_Q2, 3, test_Q3, 2, 1, 1);
  printThreeStacks(Q1);
  printf("Top and pop the TOP_STACK Q1 and the element is: %d\n", topAndPop(TOP_STACK, Q1));
  printThreeStacks(Q1);
  disposeThreeStacks(Q1);        
}
