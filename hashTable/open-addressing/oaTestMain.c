#include "oa.h"

void test_initalizeTableFromArray();
void test_rehashing();

int
main(void)
{
  printf("///////////////////////\n");
  printf("// OPEN ADDRESSING HASHING \n");
  printf("///////////////////////\n");  
  test_initalizeTableFromArray();  printf("=======================\n");
  test_rehashing();                printf("=======================\n");
  
  return 0;
}

void
test_initalizeTableFromArray()
{
  printf("TEST: initializeTableFromArray\n");
  int array[7] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
  HashTable H = initializeTableFromArray(array, 7, 10);
  printHashTable(H);
  DestroyTable(H);
}

void
test_rehashing()
{
  printf("TEST: rehashing\n");
  int array[7] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
  HashTable H = initializeTableFromArray(array, 7, 10);
  printHashTable(H);
  H = rehash(H);
  printf("----- rehashed table ---\n");
  printHashTable(H);
  DestroyTable(H);
}
