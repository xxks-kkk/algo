#include "splay.h"

struct SplayTreeNode
{
  ET Element;
  Splay Left;
  Splay Right;
};

Splay
makeEmpty(Splay T)
{
  if (T != NULL)
  {
    makeEmpty(T->Left);
    makeEmpty(T->Right);
    free(T);
  }
  numRotations = 0;
  return NULL;
}

static Position
zigLeft(Splay T)
{
  Position tmp = T->Left->Right;
  Position elem = T->Left;
  elem->Right = T;
  T->Left = tmp;
  numRotations++;
  return elem;
}

static Position
zigRight(Splay T)
{
  Position tmp = T->Right->Left;
  Position elem = T->Right;
  elem->Left = T;
  T->Right = tmp;
  numRotations++;
  return elem;
}

static Position
zigzigLeft(Splay T)
{
  T = zigLeft(T);
  T = zigLeft(T);
  return T;
}

static Position
zigzigRight(Splay T)
{
  T = zigRight(T);
  T = zigRight(T);
  return T;
}

static Position
zigzagLeft(Splay T)
{
  T->Left = zigRight(T->Left);
  T = zigLeft(T);
  return T;
}

static Position
zigzagRight(Splay T)
{
  T->Right = zigLeft(T->Right);
  T = zigRight(T);
  return T;
}

/*
 * This routine brings the elem to the root if find. If the elem is not in the tree, 
 * bring the last accessed item to the root. Returns the root of the newly modified tree.
 */
// Case refers to: http://www.cs.cmu.edu/afs/cs/academic/class/15859-f05/www/documents/splay-trees.txt
static Position
splaying(ET elem, Splay T)
{
  if (T == NULL || T->Element == elem)
    return T;
  if (elem < T->Element) // elem in the left subtree
  {
    if (T->Left == NULL) // elem is not in the tree
      return T;
    if (elem < T->Left->Element) // Zig-Zig case (left)
    {
      T->Left->Left = find(elem, T->Left->Left); // recursively bring the key as root of left-left
      T = zigzigLeft(T);
    }
    else if (elem > T->Left->Element) // Zig-Zag case (left)
    {
      T->Left->Right = find(elem, T->Left->Right);
      T = zigzagLeft(T);
    }
    else // Zig case (left)
    {
      T->Left = find(elem, T->Left);
      T = zigLeft(T);
    }
    return T;
  }
  else // elem in the right subtree
  {
    if (T->Right == NULL)
      return T;
    if (elem > T->Right->Element) // Zig-Zig case (right)
    {
      T->Right->Right = find(elem, T->Right->Right);
      T = zigzigRight(T);
    }
    else if (elem < T->Right->Element) // Zig-Zag case (right)
    {
      T->Right->Left = find(elem, T->Right->Left);
      T = zigzagRight(T);
    }
    else // Zig case (right)
    {
      T->Right = find(elem, T->Right);
      T = zigRight(T);
    }
    return T;
  }
}

Position
find(ET elem, Splay T)
{
  return splaying(elem, T);
}

Position
findMin(Splay T)
{
  if (T == NULL)
    return NULL;
  else if (T->Left == NULL)
  {
    T = find(T->Element, T);
    return T;
  }
  else
    return findMin(T->Left);
}

Position
findMax(Splay T)
{
  if (T != NULL)
    while (T->Right != NULL)
      T = T->Right;
  T = splaying(T->Element, T);
  return T;
}

static Position
newNode(ET elem)
{
  Position  T = malloc(sizeof(struct SplayTreeNode));
  T->Left = T->Right = NULL;
  T->Element = elem;
  return T;
}

// Split way to implement: http://courses.cs.washington.edu/courses/cse326/01au/lectures/SplayTrees.ppt
Splay
insert(ET elem, Splay T)
{
  if (T == NULL) // If tree is empty
  {
    T = newNode(elem);
    return T;
  }
  T = splaying(elem, T);
  if (T->Element == elem) // if elem is already present, then return
    return T;
  Position newT = newNode(elem);
  if (elem < T->Element)
  {
    newT->Right = T;
    newT->Left = T->Left; // we can do this b/c the result of splaying is the parent node of where we should insert.
    T->Left = NULL;
  }
  else
  {
    newT->Left = T;
    newT->Right = T->Right;
    T->Right = NULL;
  }
  return newT;
}

static Splay
BSTinsert(ET elem, Splay T)
{
  if (T == NULL)
  {
    T = malloc(sizeof(struct SplayTreeNode));
    T->Left = T->Right = NULL;
    T->Element = elem;
  }
  else if (elem < T->Element)
    T->Left = BSTinsert(elem, T->Left);
  else if (elem > T->Element)
    T->Right = BSTinsert(elem, T->Right);
  return T;
}

// do ordinary binary tree insertion, and then simply splay the item to the root.
Splay
insert2(ET elem, Splay T)
{
  T = BSTinsert(elem, T);
  return splaying(elem, T);
}
  
// We can perform deletion by accessing the node to be deleted.
// This put the node at the root. If it is deleted, we get two
// subtrees T_L and T_R (left and right). If we find the largest
// element in T_L (which is easy), then this element is rotated to
// the root of T_L and T_L will now have a root with no right child.
// We can finish the deletion by making T_R the right child.
Splay
delete(ET elem, Splay T)
{
  T = find(elem, T);
  Position LeftSubTree = T->Left;
  Position RightSubTree = T->Right;
  free(T);
  T = findMax(LeftSubTree);
  T->Right = RightSubTree;
  return T;
}

static Position
BSTfindMin(Splay T)
{
  if (T != NULL)
    while(T->Left != NULL)
      T = T->Left;
  return T;
}

// We do normal deletion as BST, then we
// splay the parent node of the deletion point to the root
Splay
delete2(ET elem, Splay T)
{
  Position tmp;
  
  if (T == NULL)
    fatal("No such element in splay tree");
  if (elem < T->Element)
  {
    T->Left = delete2(elem, T->Left);
    T = zigLeft(T);
  }
  else if (elem > T->Element)
  {
    T->Right = delete2(elem, T->Right);
    T = zigRight(T);
  }
  else if (T->Left != NULL && T->Right != NULL)
  {
      tmp = BSTfindMin(T->Right);
      T->Element = tmp->Element;
      T->Right = delete2(T->Element, T->Right);
  }
  else
  {
    tmp = T;
    if (T->Left == NULL)
      T = T->Right;
    else if (T->Right == NULL)
      T = T->Left;
    free(tmp);
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

int
getNumRotations()
{
  return numRotations;
}

Splay
initializeBST(ET* array, int arrayLength)
{
  Splay T = NULL;
  int i;
  for(i = 0; i < arrayLength; i++)
    T = BSTinsert(array[i], T);
  return T;
}

static void
bst_print_dot_aux(Splay T, FILE* stream)
{
  if (T != NULL)
  {
    if (T->Left != NULL)
    {
      fprintf(stream, "%d->%d;\n", T->Element, T->Left->Element);
      bst_print_dot_aux(T->Left, stream);
    }
    if (T->Right != NULL)
    {
      fprintf(stream, "%d->%d;\n", T->Element, T->Right->Element);      
      bst_print_dot_aux(T->Right, stream);
    }
  }
}

void
bst_print_dot(Splay T, FILE* stream)
{
  fprintf(stream, "digraph SplayTree \{\n");
  bst_print_dot_aux(T, stream);
  fprintf(stream,"}\n");
}
