#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void generate_dot(BST);
void delete_tree(BST);
void test_initializeBST();
void test_find();
void test_findMin();
void test_findMax();
void test_insert();
void test_delete();
void test_numNodes();
void test_numLeaves();
void test_numFullNodes();
void test_randBST();

int
main()
{
  printf("///////////////////////\n");
  printf("// BINARY SEARCH TREE TEST\n");
  printf("///////////////////////\n\n");
  
  test_initializeBST();
  test_find();              printf("\n");
  test_findMin();           printf("\n");
  test_findMax();           printf("\n");
  test_insert();
  test_delete();
  test_numNodes();          printf("\n");
  test_numLeaves();         printf("\n");
  test_numFullNodes();      printf("\n");
  test_randBST();           printf("\n");
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
test_initializeBST()
{
  printf("TEST: initializeBST\n");
  ET test_array[] = {2,1,3};
  BST T = initializeBST(test_array, 3);
  generate_dot(T);
  delete_tree(T);
}

void
test_find()
{
  printf("TEST: find\n");
  ET test_array[] = {2,1,3};
  BST T = initializeBST(test_array, 3);
  int target = 1;
  printf("want to find the element: %d\n", target);
  Position pos = find(target, T);
  printf("Found the element: %d\n", retrieve(pos));
  delete_tree(T);
}

void
test_findMin()
{
  printf("TEST: findMin\n");
  ET test_array[] = {2,1,3};
  BST T = initializeBST(test_array, 3);
  Position pos = findMin(T);
  printf("The min element in the tree: %d\n", retrieve(pos));
  delete_tree(T);
}  

void
test_findMax()
{
  printf("TEST: findMax\n");
  ET test_array[] = {2,1,3};
  BST T = initializeBST(test_array, 3);
  Position pos = findMax(T);
  printf("The max element in the tree: %d\n", retrieve(pos));
  delete_tree(T);
}  
  
void
test_insert()
{
  printf("TEST: insert\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  generate_dot(T);
  delete_tree(T);  
}

void
test_delete()
{
  printf("TEST: delete\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  printf("deleting the root: %d\n", 3);
  T = delete(3, T);
  generate_dot(T);
  delete_tree(T);  
}

void
test_numNodes()
{
  printf("TEST: numNodes\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  printf("num of nodes in the tree: %d\n", numNodes(T));
  delete_tree(T);
}

void
test_numLeaves()
{
  printf("TEST: numLeaves\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  generate_dot(T);
  printf("num of leaves in the tree: %d\n", numLeaves(T));
  delete_tree(T);
}

void
test_numFullNodes()
{
  printf("TEST: numFullNodes\n");
  ET test_array[] = {3,1,4,6,9,2,5,7};
  BST T = initializeBST(test_array, 8);
  generate_dot(T);
  printf("num of full nodes in the tree: %d\n", numFullNodes(T));
  delete_tree(T);
}

void
test_randBST()
{
  printf("TEST: randBST\n");
  BST T = randBST(10);
  generate_dot(T);
  delete_tree(T);
}
