#include "sort.h"
#include "utility.h"

void test_shellSort(void);
void test_bubbleSort(void);
void test_selectionSort(void);

int
main(void)
{
  printf("///////////////////////\n");
  printf("// SORTING TEST\n");
  printf("///////////////////////\n\n");

  test_shellSort();     printf("===============\n\n");
  test_bubbleSort();    printf("===============\n\n");
  test_selectionSort(); printf("===============\n\n");

  return 0;
}

void
test_shellSort(void)
{
  printf("TEST: shellSort\n");
  int test[] = {81,94,11,96,12,35,17,95,28,58,41,75,15};
  printf("Befor shellSort: ");
  printArray(test, 13);
  shellSort(test, 13);
  printf("After shellSort: ");
  printArray(test, 13);
}

void
test_bubbleSort(void)
{
  printf("TEST: bubbleSort\n");
  int test[] = {34,8,64,51,32,21};
  printf("Befor bubbleSort: ");
  printArray(test, 6);
  bubbleSort(test, 6);
  printf("After bubbleSort: ");
  printArray(test, 6);
}

void
test_selectionSort(void)
{
  printf("TEST: selectionSort\n");
  int test[] = {34,8,64,51,32,21};
  printf("Befor selectionSort: ");
  printArray(test, 6);
  selectionSort(test, 6);
  printf("After selectionSort: ");
  printArray(test, 6);
}
