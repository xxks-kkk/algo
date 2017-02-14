#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

void generate_dot(AVL);
void delete_tree(AVL);
void test_initializeAVL();
/* void test_find(); */
/* void test_findMin(); */
/* void test_findMax(); */
void test_insert2();
void test_delete();
void test_minAVL();

int
main()
{
  printf("///////////////////////\n");
  printf("// AVL SEARCH TREE TEST\n");
  printf("///////////////////////\n\n");
  
  test_initializeAVL();
  /* test_find();              printf("\n"); */
  /* test_findMin();           printf("\n"); */
  /* test_findMax();          printf("\n"); */
  test_insert2();
  test_delete();
  test_minAVL();
  return 0;
}

void
generate_dot(AVL T)
{
  char* dotFilename = "avl.dot";
  FILE *fp = fopen(dotFilename,"w");
  bst_print_dot(T,fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_tree(AVL T)
{
  T = makeEmpty(T);
  free(T);
}  

void
test_initializeAVL()
{
  printf("TEST: initializeAVL\n");
  ET test_array[] = {2,1,4,5,9,3,6,7};
  AVL T = initializeAVL(test_array, 8);
  generate_dot(T);
  delete_tree(T);
}

/* void */
/* test_find() */
/* { */
/*   printf("TEST: find\n"); */
/*   ET test_array[] = {2,1,3}; */
/*   BST T = initializeBST(test_array, 3); */
/*   int target = 1; */
/*   printf("want to find the element: %d\n", target); */
/*   Position pos = find(target, T); */
/*   printf("Found the element: %d\n", retrieve(pos)); */
/*   delete_tree(T); */
/* } */

/* void */
/* test_findMin() */
/* { */
/*   printf("TEST: findMin\n"); */
/*   ET test_array[] = {2,1,3}; */
/*   BST T = initializeBST(test_array, 3); */
/*   Position pos = findMin(T); */
/*   printf("The min element in the tree: %d\n", retrieve(pos)); */
/*   delete_tree(T); */
/* }   */

/* void */
/* test_findMax() */
/* { */
/*   printf("TEST: findMax\n"); */
/*   ET test_array[] = {2,1,3}; */
/*   BST T = initializeBST(test_array, 3); */
/*   Position pos = findMax(T); */
/*   printf("The max element in the tree: %d\n", retrieve(pos)); */
/*   delete_tree(T); */
/* }   */
  
void
test_insert2()
{
  printf("TEST: insert2\n");
  ET test_array[] = {2,1,4,5,9,3,6,7};
  AVL T = NULL;
  int i;
  for(i = 0; i < 8; i++)
    T = insert2(test_array[i], T);
  generate_dot(T);
  delete_tree(T);
}

void
test_delete()
{
  printf("TEST: delete\n");
  /*
   *     6                  3
   *    / \   delete 7     / \
   *   3   7  -------->   1   6
   *  /
   * 1
   */
  ET test_array[] = {6,3,7,1};
  AVL T = initializeAVL(test_array, 4);
  printf("deleting the root: %d\n", 7);
  T = delete(7, T);
  generate_dot(T);
  delete_tree(T);
}

void
test_minAVL()
{
  printf("TEST: minimum AVL tree with H\n");
  AVL T = minAVL(2);
  generate_dot(T);
  delete_tree(T);
}
