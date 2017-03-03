#include "csp.h"
#include <stdio.h>
#include <stdlib.h>

void generate_dot(CSPT);
//void delete_tree(CSPT);
void test_insert();
//void test_delete();

int
main()
{
  printf("////////////////////////////////////////////\n");
  printf("// CHILD/SIBLING IMPLEMENTATION TREE TEST\n");
  printf("////////////////////////////////////////////\n\n");
  
  test_insert();
  //test_delete();
  
  return 0;
}

void
generate_dot(CSPT T)
{
  char* dotFilename = "cspt.dot";
  FILE *fp = fopen(dotFilename,"w");
  cspt_print_dot(T,fp);
  fclose(fp);
  printFile(dotFilename);
}

/* void */
/* delete_tree(BST T) */
/* { */
/*   T = makeEmpty(T); */
/*   free(T); */
/* }   */
  
void
test_insert()
{
  printf("TEST: insert\n");
  CSPT T = NULL;
  T = insert('A', T, 'A', 0);
  T = insert('B', T, 'A', 1);
  T = insert('C', T, 'A', 1);
  T = insert('G', T, 'A', 1);
  T = insert('D', T, 'B', 1);
  T = insert('H', T, 'D', 1);
  T = insert('I', T, 'H', 0);
  T = insert('E', T, 'B', 1);
  T = insert('J', T, 'E', 1);
  T = insert('F', T, 'C', 1);
  T = insert('K', T, 'F', 1);
  T = insert('L', T, 'F', 1);
  T = insert('O', T, 'L', 1);
  T = insert('M', T, 'F', 1);
  T = insert('P', T, 'M', 1);
  T = insert('Q', T, 'P', 0);
  T = insert('R', T, 'P', 0);
  T = insert('N', T, 'G', 1);
  generate_dot(T);
  //delete_tree(T);  
}

/* void */
/* test_delete() */
/* { */
/*   printf("TEST: delete\n"); */
/*   ET test_array[] = {3,1,4,6,9,2,5,7}; */
/*   BST T = initializeBST(test_array, 8); */
/*   printf("deleting the root: %d\n", 3); */
/*   T = delete(3, T); */
/*   generate_dot(T); */
/*   delete_tree(T);   */
/* } */
