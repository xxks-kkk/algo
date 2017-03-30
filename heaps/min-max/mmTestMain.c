#include "mm.h"

void generate_dot(MinMaxHeap H);
void test_initializeMinMaxHeapFromArray(void);
void test_deleteMinMHH(void);
void test_deleteMaxMHH(void);
void test_buildMMH(void);

int
main(void)
{
  printf("///////////////////////\n");
  printf("// MIN MAX HEAP TEST\n");
  printf("///////////////////////\n\n");

  test_initializeMinMaxHeapFromArray(); printf("\n");
  test_deleteMinMHH();                  printf("\n");
  test_deleteMaxMHH();                  printf("\n");
  test_buildMMH();                      printf("\n");
  
  return 0;
}

void
generate_dot(MinMaxHeap H)
{
  char* dotFilename = "mm.dot";
  FILE *fp = fopen(dotFilename, "w");
  mmh_print_dot(H, fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_heap(MinMaxHeap H)
{
  destroyMinMaxHeap(H);  
}

void
test_initializeMinMaxHeapFromArray(void)
{
  printf("TEST: intializeMinMaxHeapFromArray\n");
  int test_array[] = {81,6,87,14,17,12,28,71,25,
                      80,20,52,78,31,42,31,59,16,
                      24,79,63,18,19,32,13,15,48};
  MinMaxHeap H = initializeMinMaxHeapFromArray(test_array, 27);
  generate_dot(H);
  delete_heap(H);
}

void
test_deleteMinMHH(void)
{
  printf("TEST: deleteMinMHH\n");
  int test_array[] = {81,6,87,14,17,12,28,71,25,
                      80,20,52,78,31,42,31,59,16,
                      24,79,63,18,19,32,13,15,48};
  MinMaxHeap H = initializeMinMaxHeapFromArray(test_array, 27);
  deleteMinMHH(H);
  generate_dot(H);
  delete_heap(H);
}

void
test_deleteMaxMHH(void)
{
  printf("TEST: deleteMaxMHH\n");
  int test_array[] = {81,6,87,14,17,12,28,71,25,
                      80,20,52,78,31,42,31,59,16,
                      24,79,63,18,19,32,13,15,48};
  MinMaxHeap H = initializeMinMaxHeapFromArray(test_array, 27);
  deleteMaxMHH(H);
  generate_dot(H);
  delete_heap(H);
}

void
test_buildMMH()
{
  printf("TEST: buildMMH\n");
  int test_array[] = {48,15,78,20,32,11,80};
  MinMaxHeap H = buildMMH(test_array, 7);
  generate_dot(H);
  delete_heap(H);
}
