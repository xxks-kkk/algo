#include "bh.h"

void generate_dot(BinHeap H);
void test_initializeBinHeapFromArray(void);
void test_buildHeap(void);
void test_decreaseKey(void);
void test_increaseKey(void);
void test_delete(void);
void delete_heap(BinHeap H);

int
main(void)
{
  printf("///////////////////////\n");
  printf("// BINARY HEAP TEST\n");
  printf("///////////////////////\n\n");

  test_initializeBinHeapFromArray(); printf("\n");
  test_buildHeap();                  printf("\n");
  test_decreaseKey();                printf("\n");
  test_increaseKey();                printf("\n");
  test_delete();                     printf("\n");
  return 0;
}

void
generate_dot(BinHeap H)
{
  char* dotFilename = "bh.dot";
  FILE *fp = fopen(dotFilename, "w");
  bh_print_dot(H, fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_heap(BinHeap H)
{
  destroyBinHeap(H);  
}

void
test_initializeBinHeapFromArray(void)
{
  printf("TEST: intializeBinHeapFromArray\n");
  int test_array[] = {10, 12, 1, 14, 6, 5, 8, 15,
                    3,  9,  7, 4,  11,13,2};
  BinHeap H = initializeBinHeapFromArray(test_array, 15);
  generate_dot(H);
  delete_heap(H);
}

void
test_buildHeap(void)
{
  printf("TEST: buildHeap\n");
  /* int test_array[] = {10, 12, 1, 14, 6, 5, 8, 15, */
  /*                   3,  9,  7, 4,  11,13,2}; */
  int test_array[] = {150, 80, 40, 30, 10, 70, 110, 100,
                     20,  90, 60, 50, 120,140,130};    
  BinHeap H = buildHeap(test_array, 15);
  generate_dot(H);
  delete_heap(H);
}

void
test_decreaseKey()
{
  printf("TEST: decreaseKey\n");
  int test_array[] = {150, 80, 40, 30, 10, 70, 110, 100,
                     20,  90, 60, 50, 120,140,130};    
  BinHeap H = buildHeap(test_array, 15);
  generate_dot(H);  
//  decreaseKey(15, 129, H);
  decreaseKey(10, 40, H);
  generate_dot(H);
  delete_heap(H);  
}

void
test_increaseKey()
{
  printf("TEST: increaseKey\n");
  int test_array[] = {150, 80, 40, 30, 10, 70, 110, 100,
                     20,  90, 60, 50, 120,140,130};    
  BinHeap H = buildHeap(test_array, 15);
  generate_dot(H);  
  increaseKey(1, 1000, H);
  generate_dot(H);
  delete_heap(H);  
}

void
test_delete()
{
  printf("TEST: delete\n");
  int test_array[] = {150, 80, 40, 30, 10, 70, 110, 100,
                     20,  90, 60, 50, 120,140,130};    
  BinHeap H = buildHeap(test_array, 15);
  generate_dot(H);
  delete(1, H);
  generate_dot(H);
  delete_heap(H);    
}
