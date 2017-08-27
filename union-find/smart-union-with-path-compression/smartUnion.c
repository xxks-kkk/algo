#include "disjSet.h"

/*
 * smart-union is also called weighted quick-union. The goal is to modify the
 * quick-union to avoid tall trees. There are two variations
 * in this category: 1. union-by-size 2. union-by-height. 
 * 
 * In union-by-size, we keep track of size of each tree (i.e. number of objects)
 * and balance the tree by linking root of smaller tree to root of larger tree.
 * In union-by-height, we keep track of the height of each tree and perform unions
 * by making the shallow tree a subtree of the deeper tree. Since the height of a
 * tree increases only when two equally deep trees are joined (and then the height
 * goes up by one). Thus, union-by height is a trivial modification of union-by-size.
 *
 * We implement union-by-size in this source file. Union-by-height implementation
 * see MAW p.271.
 *
 * Like union-by-size as a way to imrpove union operation, path compression is 
 * a way to improve find operation. The effect of path compression is that
 * every node on the path from X to the root has its parent changed to the root.
 * Path compression is independent of the strategy used to perform Unions. In other
 * words, we can use path compression in combination with union-by-size or union-by-height.
 */

/*
 * Initialize the disjoint set in smart-union algorithm 
 *
 * We need to keep track of the size of each tee. Since we are really just using
 * an array, we can have the array entry of each root contain the negative of the size
 * of its tree. Thus, initially the array representation of the tree is all -1s.
 */
void
initialize(DisjSet S)
{
  int i;
  for(i = 0; i < NumSets; i++)
  {
    S[i] = -1; 
  }
}

/*
 * Implements find operation in path compression
 *
 * NOTE: The only change to the Find routine is that S[X] is made equal to 
 *       the value returned by Find; thus after the root of the set is found
 *       recursively, X is made to point directly to it. This occurs recursively
 *       to every node on the path to the root, so this implements path compression.
 */
SetType
find(ElementType X, DisjSet S)
{
  if (S[X] <= 0)
    return X;
  else
    return S[X] = find(S[X], S);
}

/*
 * Implements union operation in smart-union algorithm 
 *
 * NOTE: another way of impelementation is to use a separate array to keep track
 * of the size of each corresponding array entry. Sedgewick uses this implementation.
 */
void
setUnion(DisjSet S, ElementType p, ElementType q)
{
  SetType pType = find(p, S);  // get the class name for p
  SetType qType = find(q, S);  // get the class name for q
  if (S[pType] < S[qType])     // class containing p is deeper
  {
    S[pType] += S[qType];      // "+=" because array entry of each root contain the negative of the size of its tree
    S[qType] = pType;          // merge class containing q into class containing q
  }
  else if (S[qType] < S[pType] || // class containing q is deeper
           pType != qType)        // when their height are the same (i.e. S[qType] = S[pType]), we only do merge if two given elements are in different class
  {
    S[qType] += S[pType];
    S[pType] = qType;
  }
}
