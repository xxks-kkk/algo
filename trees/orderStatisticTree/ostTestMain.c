#include "ost.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void generate_dot(BST);
void delete_tree(BST);
void test_findKthSmallest();
void test_findKthLargest();

int
main()
{
  printf("///////////////////////\n");
  printf("// ORDER STATISTIC TREE TEST\n");
  printf("///////////////////////\n\n");
  
  test_findKthSmallest();   printf("\n");
  test_findKthLargest();    printf("\n");
  
  return 0;
}

void
generate_dot(BST T)
{
  char* dotFilename = "bst.dot";
  FILE *fp = fopen(dotFilename,"w");
  bst_print_dot(T,fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_tree(BST T)
{
  T = makeEmpty(T);
  free(T);
}  

void
test_findKthSmallest()
{
  printf("TEST: findKthSmallest");
  ET test_array[] = {5,1,2,3,4,8,7};
  BST T = initializeBST(test_array, 7);
  generate_dot(T);
  assert(retrieve(findKthSmallest(T,3)) == 3);
  assert(retrieve(findKthSmallest(T,5)) == 5);
  assert(retrieve(findKthSmallest(T,7)) == 8);
  printf("Pass all\n");
}

void
test_findKthLargest()
{
  printf("TEST: findKthLargest");
  ET test_array[] = {5,1,2,3,4,8,7};
  BST T = initializeBST(test_array, 7);
  generate_dot(T);
  assert(retrieve(findKthLargest(T,5)) == 3);
  assert(retrieve(findKthLargest(T,3)) == 5);
  assert(retrieve(findKthLargest(T,1)) == 8);
  printf("Pass all\n");
}
