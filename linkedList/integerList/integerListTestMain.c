#include <stdio.h>
#include <stdlib.h>
#include "integerList.h"

int main()
{  
  printf("///////////////////////\n");
  printf("// INTEGERLIST TEST\n");
  printf("///////////////////////\n\n");

  printf("TEST: initializeInteger\n");
  int digits0[] = {3,4,2};
  integerList int0 = initializeInteger(digits0, 3);
  printIntegerList(int0);
  printf("\n");

  printf("TEST: add\n");
  int digits1[] = {4,6,5};
  int digits2[] = {9,7};
  int digits3[] = {7,0,6};
  int digits4[] = {1,1,7,7,7};
  integerList int1 = initializeInteger(digits1, 3);
  integerList int2 = initializeInteger(digits2, 2);
  integerList int3 = initializeInteger(digits3, 3);
  integerList int4 = initializeInteger(digits4, 5);
  printIntegerList(add(int0, int1));
  printf("\n");
  printIntegerList(add(int0, int2));
  printf("\n");
  printIntegerList(add(int0, int3));
  printf("\n");
  printIntegerList(add(int0, int4));
  printf("\n");

  printf("TEST: multiply\n");
  printIntegerList(multiply(int0, int1));
  printf("\n");

  printf("TEST: power\n");
  int digits5[] = {1};
  integerList int5 = initializeInteger(digits5, 1);
  printIntegerList(int5);
  //printIntegerList(multiply(int5, int5));
  
  printf("\n");
  //printIntegerList(powIntegerList(int5, 2));
  printf("\n");
  
  return 0;
}
