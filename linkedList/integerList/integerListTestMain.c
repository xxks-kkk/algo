#include <stdio.h>
#include <stdlib.h>
#include "integerList.h"

void test_intializeInteger();
void test_add();
void test_multiply();
void test_powIntegerList();
void test_count();

int main()
{  
  printf("///////////////////////\n");
  printf("// INTEGERLIST TEST\n");
  printf("///////////////////////\n\n");

  test_intializeInteger();
  test_add();
  test_multiply();
  test_powIntegerList();
  test_count();
  
  return 0;
}

void
test_intializeInteger()
{
  printf("TEST: initializeInteger\n");
  int digits0[] = {3,4,2};
  integerList int0 = initializeInteger(digits0, 3);
  printIntegerList(int0);
  deleteAll(int0);
  printf("\n");
}

void
test_add()
{
  printf("TEST: add\n");
  int digits0[] = {3,4,2};
  int digits1[] = {4,6,5};
  int digits2[] = {9,7};
  int digits3[] = {7,0,6};
  int digits4[] = {1,1,7,7,7};
  integerList int0 = initializeInteger(digits0, 3);
  integerList int1 = initializeInteger(digits1, 3);
  integerList int2 = initializeInteger(digits2, 2);
  integerList int3 = initializeInteger(digits3, 3);
  integerList int4 = initializeInteger(digits4, 5);
  integerList test1 = add(int0, int1);
  integerList test2 = add(int0, int2);
  integerList test3 = add(int0, int3);
  integerList test4 = add(int0, int4);
  printIntegerList(test1);
  printf("\n");
  printIntegerList(test2);
  printf("\n");
  printIntegerList(test3);
  printf("\n");
  printIntegerList(test4);
  printf("\n");
  deleteAll(int0);
  deleteAll(int1);
  deleteAll(int2);
  deleteAll(int3);
  deleteAll(int4);
  deleteAll(test1);
  deleteAll(test2);
  deleteAll(test3);
  deleteAll(test4);
}

void
test_multiply()
{
  printf("TEST: multiply\n");
  int digits0[] = {3,4,2};
  int digits1[] = {4,6,5};
  integerList int0 = initializeInteger(digits0, 3);
  printIntegerList(int0);
  printf("\n");
  integerList int1 = initializeInteger(digits1, 3);
  printIntegerList(int1);
  printf("\n");
  integerList test1 = multiply(int0, int1);
  printIntegerList(test1);
  printf("\n");
  deleteAll(int0);
  deleteAll(int1);
  deleteAll(test1);
}

void
test_powIntegerList()
{
  printf("TEST: power\n");
  int digits5[] = {2};
  integerList int5 = initializeInteger(digits5, 1);
  integerList test0 = powIntegerList(int5, 2);
  printIntegerList(test0);
  printf("\n");
  deleteAll(int5);
  deleteAll(test0);
}

void
test_count()
{
  printf("TEST: distribution of digits 0 to 9 in 2^4000\n");
  int digits0[] = {2};
  integerList int0 = initializeInteger(digits0, 1);
  integerList test0 = powIntegerList(int0, 4000);
  printIntegerList(test0);
  printf("\n");
  count(test0);
}
