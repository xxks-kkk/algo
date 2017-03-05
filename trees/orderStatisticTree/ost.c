#include "ost.h"

struct TreeNode
{
  ET Element;
  BST Left;
  BST Right;
  int NumElementsOfLeftSubtree; // number of elements in the left subtree of the current node (including the node itself)
  int NumElementsOfRightSubtree; // number of elements in the right subtree of the current node (not including the node itself)
};

BST
makeEmpty(BST T)
{
  if (T != NULL)
  {
    makeEmpty(T->Left);
    makeEmpty(T->Right);
    free(T);
  }
  return NULL;
}

Position
findKthSmallest(BST T, int i)
{
  if (T == NULL)
    return T;
  if (T->NumElementsOfLeftSubtree == i)
    return T;
  else if (T->NumElementsOfLeftSubtree > i)
    return findKthSmallest(T->Left, i);
  else
    return findKthSmallest(T->Right, i - T->NumElementsOfLeftSubtree);
}
  
Position
findKthLargest(BST T, int i)
{
  int totalElements = T->NumElementsOfLeftSubtree + T->NumElementsOfRightSubtree;
  return findKthSmallest(T, 1 + totalElements-i);
}

Position
findMin(BST T)
{
  if (T == NULL)
    return NULL;
  else if (T->Left == NULL)
    return T;
  else
    return findMin(T->Left);
}

Position
findMax(BST T)
{
  if (T != NULL)
    while (T->Right != NULL)
      T = T->Right;
  return T;
}

BST
insert(ET elem, BST T)
{
  if (T == NULL)
  {
    T = malloc(sizeof(struct TreeNode));
    T->Element = elem;
    T->Left = T->Right = NULL;
    T->NumElementsOfLeftSubtree = 1;
    T->NumElementsOfRightSubtree = 0;
  }
  else if (elem < T->Element)
  {
    T->NumElementsOfLeftSubtree++;
    T->Left = insert(elem, T->Left);
  }
  else if (elem > T->Element)
  {
    T->NumElementsOfRightSubtree++;
    T->Right = insert(elem, T->Right);
  }
  // else elem is in the tree already; we'll do nothing 
  return T;
}
  
BST
delete(ET elem, BST T)
{
  Position tmpCell;
  
  if (T == NULL)
    fatal("Element not found");
  else if (elem < T->Element)
    T->Left = delete(elem, T->Left);
  else if (elem > T->Element)
    T->Right = delete(elem, T->Right);
  else // we found the element to be deleted
  if (T->Left != NULL && T->Right != NULL) // two children
  {
      tmpCell = findMin(T->Right);
      T->Element = tmpCell->Element;
      T->Right = delete(T->Element, T->Right);
  }
  else // one or two children
  {
    tmpCell = T;
    if (T->Right == NULL)
      T = T->Left;
    else if (T->Left == NULL)
      T = T->Right;
    free(tmpCell);
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

BST
initializeBST(ET* array, int arrayLength)
{
  BST T = NULL;
  int i;
  for(i = 0; i < arrayLength; i++)
    T = insert(array[i], T);
  return T;
}

static void
bst_print_dot_aux(BST T, FILE* stream)
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
bst_print_dot(BST T, FILE* stream)
{
  fprintf(stream, "digraph BinarySearchTree \{\n");
  bst_print_dot_aux(T, stream);
  fprintf(stream,"}\n");
}
