#include "sc.h"

void test_initalizeTableFromArray();

int
main(void)
{
  printf("///////////////////////\n");
  printf("// SEPARATE CHAINING HASHING \n");
  printf("///////////////////////\n");  
  test_initalizeTableFromArray();  printf("\n");

  return 0;
}

void
test_initalizeTableFromArray()
{
  printf("TEST: initializeTableFromArray\n");
  int array[7] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
  HashTable H = initializeTableFromArray(array, 7, 10);
  printHashTable(H);
  destroyTable(H);
}
