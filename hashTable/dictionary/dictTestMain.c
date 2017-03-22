#include "dict.h"

void test_dictionary();

int
main(void)
{
  printf("///////////////////////\n");
  printf("// DICTIONARY \n");
  printf("///////////////////////\n");  

  test_dictionary();
  return 0;
}

void
test_dictionary()
{
  printf("TEST: dictionary\n");
  HashTable H = initializeTable(10);
  H = put(1,2, H);
  H = put(10,1,H);
  printDictionary(H);
  printf("\n");
  H = put(10,3,H);
  printDictionary(H);
  DestroyTable(H);
}

