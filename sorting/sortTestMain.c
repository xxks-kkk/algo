#include "sort.h"
#include "utility.h"

void test_shellSort(void);
void test_bubbleSort(void);
void test_selectionSort(void);
void test_insertionSort(void);
void test_heapSort(void);
void test_mergeSort(void);
void test_quickSort(void);
void test_Qselect(void);
void test_mergeSortNonRecursive(void);

int
main(void)
{
  printf("///////////////////////\n");
  printf("// SORTING TEST\n");
  printf("///////////////////////\n\n");

  test_shellSort();     printf("===============\n\n");
  test_bubbleSort();    printf("===============\n\n");
  test_selectionSort(); printf("===============\n\n");
  test_insertionSort(); printf("===============\n\n");
  test_heapSort();      printf("===============\n\n");
  test_mergeSort();     printf("===============\n\n");
  test_quickSort();     printf("===============\n\n");
  test_Qselect();       printf("===============\n\n");
  test_mergeSortNonRecursive();  printf("===============\n\n");

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

  int test2[] = {34};
  printf("Befor selectionSort: ");
  printArray(test2, 1);
  selectionSort(test2, 1);
  printf("After selectionSort: ");
  printArray(test2, 1);  
}

void
test_insertionSort()
{
  printf("TEST: insertionSort\n");
  //int test[] = {34,8,64,51,32,21};
  int test[] = {64,51,34,32,21,8};  
  printf("Befor insertionSort: ");
  printArray(test, 6);
  insertionSort(test, 6);
  printf("After insertionSort: ");
  printArray(test, 6);  
}

void
test_heapSort()
{
  printf("TEST: heapSort\n");
  int test[] = {31,41,59,26,53,58,97};
  printf("Before heapSort: ");
  printArray(test, 7);
  heapSort(test, 7);
  printf("After heapSort: ");
  printArray(test, 7);
}

void
test_mergeSort()
{
  printf("TEST: mergeSort\n");
  int test[] = {31,41,59,26,53,58,97};
  printf("Before mergeSort: ");
  printArray(test, 7);
  mergeSort(test, 7);
  printf("After mergeSort: ");
  printArray(test, 7);
}

void
test_quickSort()
{
  printf("TEST: quickSort\n");
  int test[] = {8,1,4,9,0,3,5,2,7,6};
  printf("Before quickSort: ");
  printArray(test, 10);
  quickSort(test, 10);
  printf("After quickSort: ");
  printArray(test, 10);
}

void
test_Qselect()
{
  printf("TEST: Qselect\n");
  int test[] = {8,1,4,9,0,3,5,2,7,6};
  printf("test array: ");
  printArray(test, 10);
  printf("select 3rd smallest element (i.e. 2)\n");
  Qselect(test, 3, 0, 9);
  assert(test[2] == 2); 
}

void
test_mergeSortNonRecursive()
{
  printf("TEST: mergeSort (non-Recursive)\n");
  int test[] = {31,41,59,26,53,58,97};
  printf("Before mergeSort: ");
  printArray(test, 7);
  mergeSortNonRecursive(test, 7);
  printf("After mergeSort: ");
  printArray(test, 7);  
}
