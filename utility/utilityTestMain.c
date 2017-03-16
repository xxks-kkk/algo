#include "utility.h"
#include <assert.h>

void test_chunk_number();
void test_permutations();
void test_searchElement();
void test_primeList();
void test_nearestPrime();

int main()
{
  printf("///////////////////////\n");
  printf("// UTILITY FUNCTIONS TEST\n");
  printf("///////////////////////\n\n");

  test_chunk_number();    printf("=============\n");
  test_permutations();    printf("=============\n");
  test_primeList();       printf("=============\n");  
  test_searchElement();   printf("=============\n");
  test_nearestPrime();    printf("=============\n");
  return 0;
}

void
test_chunk_number()
{
  int a = 123456789;
  printf("TEST: chunk_number\n");
  
  /* printf("original number: %d\n", a); */
  /* int first_three_digit = a / (int)pow(10,6); */
  /* printf("first three digit: %d\n", first_three_digit); */
  /* int first_six_digit = a / (int)pow(10,3); */
  /* printf("middle three digit: %d\n", first_six_digit - first_six_digit / (int)pow(10,3) * (int)pow(10,3) ); */
  /* int last_six_digit = (a - a / (int)pow(10,6) * (int)pow(10,6)); */
  /* printf("last three digit: %d\n", last_six_digit - last_six_digit / (int)pow(10,3) * (int)pow(10,3)); */

  printf("Original number: %d\n", a);
  int res;
  res = chunk_number(a, 0, 2);
  assert(res == 123);
  printf("[0:2] digits: %d\n", res);
  res = chunk_number(a, 3, 5);
  assert(res == 456);
  printf("[3:5] digits: %d\n", res);
  res = chunk_number(a, 6, 8);
  assert(res == 789);
  printf("[6:8] digits: %d\n", res);
  res = chunk_number(a, 2, 5);
  assert(res == 3456);
  printf("[2:5] digits: %d\n", res);
  res = chunk_number(a, 0, 5);
  assert(res == 123456);
  printf("[0:5] digits: %d\n", res);
  a = 17502605;
  printf("original number: %d\n", a);
  res = chunk_number(a, 0, 2);
  assert(res == 175);
  printf("[0:2] digits: %d\n", res);
  res = chunk_number(a, 3, 5);
  assert(res == 26);
  printf("[3:5] digits: %d\n", res);
  res = chunk_number(a, 6, 7);
  assert(res == 5);
  printf("[6:7] digits: %d\n", res);  
}

void
test_permutations()
{
  printf("TEST: permutations\n");
  int *array = malloc(5 * sizeof(int));
  permutation(array, 5);
  printArray(array, 5);
}

void
test_primeList()
{
  printf("TEST: primeList\n");
  int* array = primeList(30);
  printf("The list of primes below %d are: \n", 30);
  printArray(array,arrayLength(array));
  free(array);
}

void
test_nearestPrime()
{
  printf("TEST: nearestPrime\n");
  printf("Nearest Prime around 20 is: %d\n", nearestPrime(20));
}

void
test_searchElement()
{
  printf("TEST: searchElement\n");
  int array[10] = {0, 4, 5, 6, 20, 21, 50, 79, 81, 100};
  printf("array: ");
  printArray(array, 10);
  printf("Index for 2 is: %d\n", searchElement(2, array, 10));  
  printf("Index for 4 is: %d\n", searchElement(4, array, 10));
  printf("Index for 6 is: %d\n", searchElement(6, array, 10));  
  printf("Index for 20 is: %d\n", searchElement(20, array, 10));
  printf("Index for 30 is: %d\n", searchElement(30, array, 10));
  printf("Index for 90 is: %d\n", searchElement(90, array, 10));  
}
