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
  printArray(S, NumSets);  // with union-by-size only: 6, 2, 8, 4, -2, 6, -3, 8, -5, 8,
                           // union-by-size with path compression: 6, 8, 8, 4, -2, 6, -3, 8, -5, 8,
  /*
   * Visualization of the result of union operations above 
   * with union-by-size only:
   *
   *     4     6          8
   *    /     /          / |\
   *   3     5          7  9 2
   *        /                 \
   *       0                   1
   * with union-by-size and path compression:
   * 
   *    4        6          8
   *   /        /          /|\ \
   *  3        5          7 9 2 1
   *          /
   *         0
   */
  return 0;
}
