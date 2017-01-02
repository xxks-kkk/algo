#include "circularLinkedList.h"
#include "nonLinkedListSol.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void test_circularDoubleLinkedList();
void test_initializeList();
void test_circularDoubleLinkedListJosephus();
void test_cyclicShiftJosephus();
void test_reccurenceJosephus();
void test_reccurenceJosephusZero();
void test_recurrenceImproved();
void test_josephus();

int main()
{
  printf("///////////////////////\n");
  printf("// CIRCULAR DOUBLE LINKED LIST TEST\n");
  printf("///////////////////////\n");
  test_circularDoubleLinkedList();
  printf("\n");
  
  printf("///////////////////////\n");
  printf("// JOSEPHUS PROBLEM SOLUTIONS TEST\n");
  printf("///////////////////////\n");
  test_circularDoubleLinkedListJosephus();
  test_cyclicShiftJosephus();
  test_reccurenceJosephus();
  test_reccurenceJosephusZero();
  test_recurrenceImproved();
  test_josephus();
  
  return 0;
}

void
test_circularDoubleLinkedList()
{
  test_initializeList();
}

void
test_initializeList()
{
  printf("TEST: initializeList\n");
  ET test_L[] = {23, 44, 45, 57, 89, -1};
  List L = initializeList(test_L, 6);
  printList(L);
  printf("\n");
}

void
test_circularDoubleLinkedListJosephus()
{
  ET res;
  printf("TEST: circularDoubleLinkedListJosephus\n");
  res = circularDoubleLinkedListJosephus(6, 2);
  assert(res == 5);
  printf("J(6,2) = %d\n", res);
  res = circularDoubleLinkedListJosephus(5, 2);
  assert(res == 3);
  printf("J(5,2) = %d\n", res);
  res = circularDoubleLinkedListJosephus(4, 2);
  assert(res == 1);
  printf("J(4,2) = %d\n", res);
  res = circularDoubleLinkedListJosephus(5, 3);
  assert(res == 4);
  printf("J(5,3) = %d\n", res);
  res = circularDoubleLinkedListJosephus(15, 2);
  assert(res == 15);
  printf("J(15,2) = %d\n", res);
  res = circularDoubleLinkedListJosephus(16, 2);
  assert(res == 1);
  printf("J(16,2) = %d\n", res);
}

void
test_cyclicShiftJosephus()
{
  ET res;
  printf("TEST: cyclicShiftJosephus\n");
  res = cyclicShiftJosephus(6,2);
  assert(res == 5);
  printf("J(6,2) = %d\n", res);
  res = cyclicShiftJosephus(5,2);
  assert(res == 3);
  printf("J(5,2) = %d\n", res);
  res = cyclicShiftJosephus(4,2);
  assert(res == 1);
  printf("J(4,2) = %d\n", res);
  res = cyclicShiftJosephus(15, 2);
  assert(res == 15);
  printf("J(15,2) = %d\n", res);
  res = cyclicShiftJosephus(16, 2);
  assert(res == 1);
  printf("J(16,2) = %d\n", res);
}

void
test_reccurenceJosephus()
{
  ET res;
  printf("TEST: recurrenceJosephus\n");
  res = recurrenceJosephus(6,2);
  assert(res == 5);
  printf("J(6,2) = %d\n", res);
  res = recurrenceJosephus(5,2);
  assert(res == 3);
  printf("J(5,2) = %d\n", res);
  res = recurrenceJosephus(4,2);
  assert(res == 1);
  printf("J(4,2) = %d\n", res);
  res = recurrenceJosephus(15, 2);
  assert(res == 15);
  printf("J(15,2) = %d\n", res);
  res = recurrenceJosephus(16, 2);
  assert(res == 1);
  printf("J(16,2) = %d\n", res);
}

void
test_reccurenceJosephusZero()
{
  ET res;
  printf("TEST: recurrenceJosephusZero\n");
  res = recurrenceJosephusZero(6,2);
  assert(res == 5);
  printf("J(6,2) = %d\n", res);
  res = recurrenceJosephusZero(5,2);
  assert(res == 3);
  printf("J(5,2) = %d\n", res);
  res = recurrenceJosephusZero(5,1);
  assert(res == 5);
  printf("J(5,1) = %d\n", res);
  res = recurrenceJosephusZero(4,2);
  assert(res == 1);
  printf("J(4,2) = %d\n", res);
  res = recurrenceJosephusZero(15, 2);
  assert(res == 15);
  printf("J(15,2) = %d\n", res);
  res = recurrenceJosephusZero(16, 2);
  assert(res == 1);
  printf("J(16,2) = %d\n", res);
}

void
test_recurrenceImproved()
{
  xint2 res;
  printf("TEST: recurrenceImproved\n");
  res = recurrenceImproved(6,2);
  assert(res == 5);
  printf("J(6,2) = %llu\n", res);

  res = recurrenceImproved(5,2);
  assert(res == 3);
  printf("J(5,2) = %llu\n", res);

  res = recurrenceImproved(4,2);
  assert(res == 1);
  printf("J(4,2) = %llu\n", res);

  res = recurrenceImproved(15, 2);
  assert(res == 15);
  printf("J(15,2) = %llu\n", res);
  
  res = recurrenceImproved(16, 2);
  assert(res == 1);
  printf("J(16,2) = %llu\n", res);
  
  res = recurrenceImproved(pow(10,10), pow(10,4));
  printf("J(10^10,10^4) = %llu\n", res);
}

void
test_josephus()
{
  xint res;
  printf("TEST: josephus\n");

  res = josephus(6, 2);
  assert(res == 5);
  printf("J(6,2) = %llu\n", res);

  res = josephus(5, 2);
  assert(res == 3);
  printf("J(5,2) = %llu\n", res);

  res = josephus(4, 2);
  assert(res == 1);
  printf("J(4,2) = %llu\n", res);

  res = josephus(15, 2);
  assert(res == 15);
  printf("J(15,2) = %llu\n", res);
  
  res = josephus(16, 2);
  assert(res == 1);
  printf("J(16,2) = %llu\n", res);
  
  res = josephus(pow(10,12), pow(10,4));
  printf("J(10^12,10^4) = %llu\n", res);
}
