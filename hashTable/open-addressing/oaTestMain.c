#include "oa.h"

void test_initalizeTableFromArray();
void test_rehashing();
void test_findPattern();

int
main(void)
{
  printf("///////////////////////\n");
  printf("// OPEN ADDRESSING HASHING \n");
  printf("///////////////////////\n");  
  test_initalizeTableFromArray();  printf("=======================\n");
  test_rehashing();                printf("=======================\n");
  test_findPattern();              printf("=======================\n");
  
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

void
test_findPattern()
{
  printf("TEST: findPattern\n");
  char input[] = "This is a test!\n";
  char pattern[] = "es";
  printf("The position of pattern \"%s\" in input \"%s\" is: %d\n", pattern, input, findPattern(pattern, input));
}
