#include "disjSet.h"


/*
 * Initialize the disjoint set in quick-union algorithm 
 *
 * NOTE: The implementation is different from MAW's. In MAW, the equivalence
 * class name is indicated by 0 and thus, during the initialization, all the
 * S[i] are initialized to 0. However, in this implementation, the equivalence
 * class name is indicated by the element position. That's why we initialize
 * S[i] = i.
 */
void
initialize(DisjSet S)
{
  int i;
  for(i = 0; i < NumSets; i++)
  {
    S[i] = i;
  }
}

/*
 * Implements find operation in quick-union algorithm
 */
SetType
find(ElementType X, DisjSet S)
{
  if (S[X] == X)
    return X;
  else
    return find(S[X], S);
}

/*
 * Implements union operation in quick-union algorithm
 * 
 * NOTE: we merge the equivalence class containing p into q
 */
void
setUnion(DisjSet S, ElementType p, ElementType q)
{
  SetType pType = find(p, S);  // get the class name for p
  SetType qType = find(q, S);  // get the class name for q
  S[pType] = qType;
}
