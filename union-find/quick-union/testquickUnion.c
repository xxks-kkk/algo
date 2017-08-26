#include "disjSet.h"

int
main(void)
{
  DisjSet S;

  printf("Initialize a disjoint set with 10 items\n");
  initialize( S );
  printf("Union 1-2\n"); setUnion(S, 1, 2);
  printf("Union 3-4\n"); setUnion(S, 3, 4);
  printf("Union 5-6\n"); setUnion(S, 5, 6);
  printf("Union 7-8\n"); setUnion(S, 7, 8);
  printf("Union 7-9\n"); setUnion(S, 7, 9);
  printf("Union 2-8\n"); setUnion(S, 2, 8);
  printf("Union 0-5\n"); setUnion(S, 0, 5);
  printf("Union 1-9\n"); setUnion(S, 1, 9);
  printf("the connected components are: \n");
  printArray(S, NumSets); // 6, 2, 9, 4, 4, 6, 6, 8, 9, 9
  /*
   * The visualization of the result of  operations above:
   *     4    6       9
   *    /    / \     / \
   *   3    5   0   8   2
   *               /   /
   *              7   1
   */
  return 0;
}
