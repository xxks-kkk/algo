#include "tt.h"

// Implementation reference:
// 1. http://algorithms.tutorialhorizon.com/double-threaded-binary-tree-complete-implementation/
// 2. http://programming.im.ncnu.edu.tw/ThreadedTree.java

struct TreeNode
{
  ET Element;
  TT Left;
  TT Right;
  // Used to indicate whether the left pointer is a normal left
  // pointer or a pointer to in-order predecessor.
  // 0: is a normal left pointer; 1: is a pointer to in-order predecessor
  int IsLeftThreaded;
  // Used to indicate whether the right pointer is a normal right
  // pointer or a pointer to in-order successor.
  // 0: is a normal right pointer; 1: is a pointer to in-order successor
  int IsRightThreaded;
  int Visited; // auxiliary variable to mark visited node when we print the tree. Not part of the TT structure definition.
};

// We create the dummy node to handle
// the left most node's left NULL pointer and
// the right most node's right NULL pointer have nowhere to point to.
// This node will always present even when tree is empty.
TT
createEmptyTT()
{
  TT dummyT;
  dummyT = malloc(sizeof(struct TreeNode));
  dummyT->Element = INT_MAX;
  dummyT->Left = dummyT->Right = dummyT;
  dummyT->IsLeftThreaded = 1;
  dummyT->IsRightThreaded = 1;
  dummyT->Visited = 0;
  return dummyT;
}

TT
makeEmpty(TT T)
{
  if (T != NULL)
  {
    if(!T->IsLeftThreaded)
      makeEmpty(T->Left);
    if(!T->IsRightThreaded)
      makeEmpty(T->Right);
    free(T);
  } 
  return NULL;
}

TT
insert(ET elem, TT T)
{
  Position p = T;
  for(;;) // We first want to find the position to insert
  {
    if (p->Element < elem)
    {
      if (p->IsRightThreaded) break;
      p = p->Right;
    }
    else if (p->Element > elem)
    {
      if (p->IsLeftThreaded) break;
      p = p->Left;
    }
    else
    {
      return T; // duplicate elem
    }
  }
  Position tmp = malloc(sizeof(*tmp));
  tmp->Element = elem;
  tmp->IsLeftThreaded = tmp->IsRightThreaded = true;
  if (p->Element < elem) // insert to the right side
  {
    /* For example: we want to insert 10 to the following tree. 9's right pointer is originally pointing to 20.
     *    20
     *    /
     *   1
     *    \ 
     *     9
     *    /
     *   5
     */
    tmp->Right = p->Right;
    tmp->Left = p;
    p->Right = tmp;
    p->IsRightThreaded = 0;
  }
  else
  {
    // same tree as above, but this time we want to insert 4. 5's left pointer is originally pointing to 1 and
    /// right pointer is originally pointing to 9.
    tmp->Right = p;
    tmp->Left = p->Left;
    p->Left = tmp;
    p->IsLeftThreaded = 0;
  }
  return T;
}
  
TT
delete(ET elem, TT T)
{
  Position
    dest = T->Left,
    p = T;

  for(;;)
  {
    if (elem > dest->Element)
    {
      if (dest->IsRightThreaded) return NULL; // not found
      p = dest;
      dest = dest->Right;
    }
    else if (elem < dest->Element)
    {
      if (dest->IsLeftThreaded) return NULL; // not found
      p = dest;
      dest = dest->Left;
    }
    else
      break; // we find the to be deleted node
  }
  Position target = dest;
  if(!dest->IsRightThreaded && !dest->IsLeftThreaded) // dest has two children
  {
    p = dest;
    // find largest node at left child
    target = dest->Left;
    while (!target->IsRightThreaded)
    {
      p = target;
      target = target->Right;
    }
    dest->Element = target->Element; // using replace mode
  }
  if (p->Element >= target->Element)
  {
    if (target->IsRightThreaded && target->IsLeftThreaded)
    {
      /*   p
       *  /
       * t 
       */
      p->Left = target->Left;
      p->IsLeftThreaded = 1;
    }
    else if (target->IsRightThreaded)
    {
      /*     P
       *    /
       *   t
       *  /
       * t->Left
       */
      Position largest = target->Left;
      while (!largest->IsRightThreaded)
        largest = largest->Right;
      largest->Right = p;
      p->Left = target->Left;
    }
    else
    {
      /*     p
       *    /
       *   t
       *    \
       *    t->Right
       */
      Position smallest = target->Right;
      while(!smallest->IsLeftThreaded)
        smallest = smallest->Left;
      smallest->Left = target->Left;
      p->Left = target->Left;
    }
  }
  else
  {
    if (target->IsRightThreaded && target->IsRightThreaded)
    {
      /* 
       * p
       *  \
       *   t
       */
      p->Right = target->Right;
      p->IsRightThreaded = 1;
    }
    else if (target->IsRightThreaded)
    {
      /* 
       * p
       *  \
       *   t
       *   / 
       * t->Left
       */
      Position largest = target->Left;
      while(!largest->IsRightThreaded)
        largest = largest->Right;
      largest->Right = target->Right;
      p->Right = target->Left;
    }
    else
    {
      /*  p
       *   \
       *    t
       *     \
       *     t->Right
       */
      Position smallest = target->Right;
      while (!smallest->IsLeftThreaded)
        smallest = smallest->Left;
      smallest->Left = p;
      p->Right = target->Right;
    }
  }
  return T;
}
  
ET
retrieve(Position T)
{
  if (T != NULL)
    return T->Element;
  return 0;
}

TT
initializeTT(ET* array, int arrayLength)
{
  TT T = createEmptyTT();
  int i;
  for(i = 0; i < arrayLength; i++)
    T = insert(array[i], T);
  return T;
}

static void
tt_print_dot_aux(TT T, FILE* stream)
{
  if (T != NULL && !T->Visited)
  {
    if (T->Left != NULL)
    {
      fprintf(stream, "%d->%d;\n", T->Element, T->Left->Element);
      T->Visited = 1;
      tt_print_dot_aux(T->Left, stream);
    }
    if (T->Right != NULL)
    {
      fprintf(stream, "%d->%d;\n", T->Element, T->Right->Element);      
      tt_print_dot_aux(T->Right, stream);
    }
  }
}

static void
reset_visited(TT T)
{
  if (T != NULL && T->Visited)
  {
    if (T->Left != NULL)
    {
      T->Visited = 0;
      reset_visited(T->Left);
    }    
    if (T->Right != NULL)
    {
      T->Visited = 0;
      reset_visited(T->Right);
    }
  }
}

void
tt_print_dot(TT T, FILE* stream)
{
  fprintf(stream, "digraph ThreadedTree{\n");
  tt_print_dot_aux(T, stream);
  fprintf(stream,"}\n");
  reset_visited(T);
}
