#include "splay.h"
#include <stdio.h>
#include <stdlib.h>

void generate_dot(Splay);
void delete_tree(Splay);
void test_find();
void test_insertion();
void test_insertion2();
void test_findMin();
void test_findMax();
void test_delete();
void test_delete2();

int
main()
{
  printf("///////////////////////\n");
  printf("// SPLAY TREE TEST\n");
  printf("///////////////////////\n\n");
  
  test_find();              printf("==================\n");
  test_insertion();         printf("==================\n");
  test_insertion2();        printf("==================\n");  
  test_findMin();           printf("==================\n");  
  test_findMax();           printf("==================\n");  
  test_delete();            printf("==================\n");
  test_delete2();           printf("==================\n");
  return 0;
}

void
generate_dot(Splay T)
{
  char* dotFilename = "splay.dot";
  FILE *fp = fopen(dotFilename,"w");
  bst_print_dot(T,fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_tree(Splay T)
{
  T = makeEmpty(T);
  free(T);
}  

void
test_find()
{
  printf("TEST: find (element inside tree)\n");
  ET test_array[] = {7,6,5,4,3,2,1};
  Splay T = initializeBST(test_array, 7);
  int target = 1;  
  printf("Before find: %d\n", target);
  generate_dot(T);
  printf("Number of rotations: %d\n", getNumRotations());  
  T = find(target, T);
  printf("Find the element: %d\n", retrieve(T));
  printf("Number of rotations: %d\n", getNumRotations());
  generate_dot(T);
  delete_tree(T);

  printf("TEST: find (element NOT inside tree)\n");
  T = initializeBST(test_array, 7);  
  target = 0;  
  printf("Before find: %d\n", target);
  printf("Number of rotations: %d\n", getNumRotations());  
  generate_dot(T);
  T = find(target, T);
  printf("Find the element: %d\n", retrieve(T));
  printf("Number of rotations: %d\n", getNumRotations());  
  generate_dot(T);
  delete_tree(T);  
}

void
test_insertion()
{
  printf("TEST: insertion (same element)\n");
  ET test_array[] = {7,6,5,4,3,2,1};
  Splay T = initializeBST(test_array, 7);
  printf("Before insertion\n");
  generate_dot(T);  
  int target = 1;
  printf("Number of rotations: %d\n", getNumRotations());  
  printf("Insert: %d\n", target);
  T = insert(target, T);
  printf("Number of rotations: %d\n", getNumRotations());  
  generate_dot(T);
  delete_tree(T);

  printf("TEST: insertion (new element)\n");
  T = initializeBST(test_array, 7);
  printf("Before insertion\n");
  generate_dot(T);  
  target = 0;
  printf("Insert: %d\n", target);
  T = insert(target, T);
  generate_dot(T);
  delete_tree(T);
}

void
test_insertion2()
{
  printf("TEST: insertion2 (same element)\n");
  ET test_array[] = {7,6,5,4,3,2,1};
  Splay T = initializeBST(test_array, 7);
  printf("Before insertion2\n");
  generate_dot(T);  
  int target = 1;
  printf("Insert2: %d\n", target);
  T = insert2(target, T);
  generate_dot(T);
  delete_tree(T);

  printf("TEST: insertion2 (new element)\n");
  T = initializeBST(test_array, 7);
  printf("Before insertion\n");
  generate_dot(T);  
  target = 0;
  printf("Insert2: %d\n", target);
  T = insert2(target, T);
  generate_dot(T);
  delete_tree(T);
}

void
test_findMin()
{
  printf("TEST: findMin\n");
  ET test_array[] = {2,1,3};
  Splay T = initializeBST(test_array, 3);
  generate_dot(T);
  T = findMin(T);
  printf("The min element in the tree: %d\n", retrieve(T));
  generate_dot(T);
  delete_tree(T);
}

void
test_findMax()
{
  printf("TEST: findMax\n");
  ET test_array[] = {2,1,3};
  Splay T = initializeBST(test_array, 3);
  generate_dot(T);
  T = findMax(T);
  printf("The max element in the tree: %d\n", retrieve(T));
  generate_dot(T);
  delete_tree(T);
}
  
void
test_delete()
{
  printf("TEST: delete\n");
  ET test_array[] = {10,5,15,2,8,13,20,6,9};
  Splay T = initializeBST(test_array, 9);
  printf("Number of rotations: %d\n", getNumRotations());  
  generate_dot(T);
  printf("deleting the root: %d\n", 8);
  T = delete(8, T);
  printf("Number of rotations: %d\n", getNumRotations());  
  generate_dot(T);
  delete_tree(T);
}

void
test_delete2()
{
  printf("TEST: delete2\n");
  ET test_array[] = {10,5,15,2,8,13,20,6,9};
  Splay T = initializeBST(test_array, 9);
  printf("Number of rotations: %d\n", getNumRotations());  
  generate_dot(T);
  printf("deleting the root: %d\n", 8);
  T = delete2(8, T);
  printf("Number of rotations: %d\n", getNumRotations());  
  generate_dot(T);
  delete_tree(T);
}
