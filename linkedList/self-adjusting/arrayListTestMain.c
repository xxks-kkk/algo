#include "arrayList.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

void test_insert();

int
main()
{
  test_insert(); printf("\n");
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
