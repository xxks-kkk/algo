#include "bh.h"

void generate_dot(BinHeap H);
void test_initializeBinHeapFromArray(void);
void delete_heap(BinHeap H);

int
main(void)
{
  printf("///////////////////////\n");
  printf("// BINARY HEAP TEST\n");
  printf("///////////////////////\n\n");

  test_initializeBinHeapFromArray(); printf("\n");
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
  ET test_array[] = {10, 12, 1, 14, 6, 5, 8, 15,
                    3,  9,  7, 4,  11,13,2};
  BinHeap H = initializeBinHeapFromArray(test_array, 15);
  generate_dot(H);
  delete_heap(H);
}
