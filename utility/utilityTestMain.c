#include "utility.h"
#include "assert.h"

void test_chunk_number();

int main()
{
  printf("///////////////////////\n");
  printf("// UTILITY FUNCTIONS TEST\n");
  printf("///////////////////////\n\n");

  test_chunk_number();
  return 0;
}

void
test_chunk_number()
{
  int a = 123456789;
  printf("TEST: chunk_number\n");
  
  printf("original number: %d\n", a);
  int first_three_digit = a / (int)pow(10,6);
  printf("first three digit: %d\n", first_three_digit);
  int first_six_digit = a / (int)pow(10,3);
  printf("middle three digit: %d\n", first_six_digit - first_six_digit / (int)pow(10,3) * (int)pow(10,3) );
  int last_six_digit = (a - a / (int)pow(10,6) * (int)pow(10,6));
  printf("last three digit: %d\n", last_six_digit - last_six_digit / (int)pow(10,3) * (int)pow(10,3));

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
}

