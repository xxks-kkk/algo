#include "tt.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void generate_dot(TT);
void delete_tree(TT);
void test_initializeTT();
void test_delete();

int
main()
{
  printf("///////////////////////\n");
  printf("// THREADED TREE TEST\n");
  printf("///////////////////////\n\n");

  test_initializeTT();  printf("\n");
  test_delete();        printf("\n");
  
  return 0;
}

void
generate_dot(TT T)
{
  char* dotFilename = "tt.dot";
  FILE *fp = fopen(dotFilename,"w");
  tt_print_dot(T,fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_tree(TT T)
{
  T = makeEmpty(T);
  free(T);
}  

void
test_initializeTT()
{
  printf("TEST: initializeTT\n");
  ET test_array[] = {20,1,9,8,7,5,6};
  TT T = initializeTT(test_array, 7);
  generate_dot(T);
  delete_tree(T);  
}

void
test_delete()
{
  printf("TEST: delete\n");
  ET test_array[] = {20,1,9,8,7,5,6};
  TT T = initializeTT(test_array, 7);
  T = delete(20, T);
  generate_dot(T);
  delete_tree(T);  
}
