#include "csp.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void generate_dot(CSPT);
//void delete_tree(CSPT);
void test_insert();
//void test_delete();
void test_isomorphic();

int
main()
{
  printf("////////////////////////////////////////////\n");
  printf("// CHILD/SIBLING IMPLEMENTATION TREE TEST\n");
  printf("////////////////////////////////////////////\n\n");
  
  test_insert();       printf("\n");
  test_isomorphic();   printf("\n");
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

void
test_isomorphic()
{
  printf("TEST: isomorphic\n");
  CSPT T1 = NULL;
  CSPT T2 = NULL;
  printf("Graph T1:\n");
  T1 = insert('A', T1, 'A', 0);
  T1 = insert('B', T1, 'A', 1);
  T1 = insert('C', T1, 'A', 1);
  T1 = insert('D', T1, 'B', 1);
  T1 = insert('E', T1, 'B', 1);
  T1 = insert('F', T1, 'E', 1);
  T1 = insert('G', T1, 'C', 1);
  T1 = insert('H', T1, 'G', 1);
  generate_dot(T1);
  printf("Graph T2:\n");
  T2 = insert('A', T2, 'A', 0);
  T2 = insert('C', T2, 'A', 1);
  T2 = insert('B', T2, 'C', 0);
  T2 = insert('G', T2, 'C', 1);
  T2 = insert('H', T2, 'G', 1);
  T2 = insert('E', T2, 'B', 1);
  T2 = insert('D', T2, 'E', 0);
  T2 = insert('F', T2, 'E', 1);
  generate_dot(T2);
  assert(isomorphic(T1,T2) == 0);
  printf("All pass!\n");
}
