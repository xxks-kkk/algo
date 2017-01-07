#include "arrayList.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

void test_insert();
void test_findArray();

int
main()
{
  test_insert(); printf("\n");
  test_findArray(); printf("\n");
  return 0;
}

void test_insert()
{
  printf("TEST: arrayInsert\n");
  int test[] = {1,2,3};
  int* list = arrayTranslate(test, 3);
  printf("Before arrayInsert: \n");
  printArrayList(list,3);
  arrayInsert(5, &list, 3);
  printf("After arrayInsert: \n");
  printArrayList(list,4);
}

void
test_findArray()
{
  printf("TEST: arrayInsert\n");
  int test[] = {1,2,3};
  int* list = arrayTranslate(test, 3);
  printf("Before arrayFind: \n");
  printArrayList(list,3);
  int index = arrayFind(3, list, 3);
  printf("target location: %d\n", index);
  printArrayList(list,3);
}
