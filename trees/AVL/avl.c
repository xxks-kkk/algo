#include "avl.h"
0;136;0c
struct AVLTreeNode
{
  ET Element;
  AVL Left;
  AVL Right;
  int Height;
};

static int
Height(Position P)
{
  if (P == NULL)
    return -1;
  else
    return P->Height;
}

AVL
makeEmpty(AVL T)
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
find(ET elem, AVL T)
{
  if (T == NULL)
    return NULL;
  if (elem < T->Element)
    return find(elem, T->Left);
  else if (elem > T->Element)
    return find(elem, T->Right);
  else
    return T;
}

Position
findMin(AVL T)
{
  if (T == NULL)
    return NULL;
  else if (T->Left == NULL)
    return T;
  else
    return findMin(T->Left);
}

Position
findMax(AVL T)
{
  if (T != NULL)
    while (T->Right != NULL)
      T = T->Right;
  return T;
}

/*
 * MAW 4.22 Write the functions to perform the double rotation without the inefficiency of doing 
 * two single rotations.
 * Naming convention follows the figure 4.42 on P.122 of MAW
 */
static AVL
doubleRotateWithLeft2(Position K3)
{
  Position K1 = K3->Left;
  Position K2 = K3->Left->Right;
  K1->Right = K2->Left;
  K3->Left = K2->Right;
  K2->Left = K1;
  K2->Right = K3;

  K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
  K3->Height = max(Height(K3->Left), Height(K3->Right)) + 1;
  K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;

  return K2;
}

/*
 * This function can be called only if K2 has a left child
 * Peform a rotate between a node (K2) and its left child
 * Update heights, then return new root
 */
static AVL
singleRotateWithLeft(Position K2)
{
  Position K1;
  K1 = K2->Left;
  K2->Left = K1->Right;  
  K1->Right = K2;

  K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
  K2->Height = max(Height(K2->Right), Height(K2->Right)) + 1;
  
  return K1; // new root
}

/*
 * This function can be called only if K3 has a left
 * child and K3's left child has a right child
 * Do the left-right double rotation
 * Update heights, then return new root
 */
static AVL
doubleRotateWithLeft(Position K3)
{
  K3->Left = singleRotateWithLeft(K3->Left); // Rotate between K1 and K2
  return singleRotateWithLeft(K3); // Rotate between K3 and K2
}

/*
 * This function can be called only if K1 has a right child
 * Peform a rotate between a node (K1) and its right child
 * Update heights, then return new root
 */
static AVL
singleRotateWithRight(Position K2)
{
  Position K1;
  K1 = K2->Right;
  K2->Right = K1->Left;
  K1->Left = K2;

  K2->Height = max(Height(K2->Left), Height(K2->Right)) + 1;  
  K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
  return K1;
}

/*
 * This function can be called only if K3 has a right
 * child and K3's right child has a left child
 * Do the right-left double rotation
 * Update heights, then return new root
 */
static AVL
doubleRotateWithRight(Position K3)
{
  K3->Right = singleRotateWithLeft(K3->Right);
  return singleRotateWithRight(K3);
}

AVL
insert(ET elem, AVL T)
{
  if (T == NULL)
  {
    T = malloc(sizeof(struct AVLTreeNode));
    T->Element = elem;
    T->Left = T->Right = NULL;
    T->Height = 0;
  }
  else if (elem < T->Element)
  {
    T->Left = insert(elem, T->Left);
    if (Height(T->Left) - Height(T->Right) == 2)
    {
      if(elem < T->Left->Element)
      {
        T = singleRotateWithLeft(T);
      }
      else
      {
        T = doubleRotateWithLeft2(T);  //Use MAW 4.22 version
//        T = doubleRotateWithLeft(T);         
      }
    }
  }
  else if (elem > T->Element)
  {
    T->Right = insert(elem, T->Right);
    if (Height(T->Right) - Height(T->Left) == 2)
    {
      if (elem > T->Right->Element)
      {
        T = singleRotateWithRight(T);
      }
      else
      {
        T = doubleRotateWithRight(T);
      }
    }
  }
  // else elem is in the tree already; we'll do nothing
  T->Height = max(Height(T->Left), Height(T->Right)) + 1;
  return T;
}

static Position
makeNode(ET elem)
{
  Position T = malloc(sizeof(struct AVLTreeNode));
  T->Element = elem;
  T->Left = NULL;
  T->Right = NULL;
  T->Height = 0;
  return T;
}

/* To understand this function, I would suggest to try the following insertion to an empty AVL tree:
 * 2,1,4,5,9,3,6,7
 * and follow the illustration: https://cseweb.ucsd.edu/classes/su05/cse100/cse100hw1.pdf p.5
 * a copy is also included in this repo
 */ 
AVL
insert2(ET elem, AVL T)
{
  // We want to implement a simple stack to store the path from the root to the insertion location.
  // This stack is used when we move backward from the insertion location to
  // the root while we updating the height and do the rotation along the way.
  struct StackRecord
  {
    int Capacity;
    int TopOfStack;
    Position *Array;
  };
  typedef struct StackRecord* NodeStack;
  NodeStack s = malloc(sizeof(struct StackRecord));
  s->Capacity = 10;
  s->TopOfStack = -1;
  s->Array = malloc(s->Capacity *  sizeof(Position)); 
  if (T == NULL) // if T is an empty AVL tree, we create root and done.
  {
    T = makeNode(elem);
    free(s->Array);
    free(s);
    return T;
  }
  // LastS comes from https://courses.cs.washington.edu/courses/cse373/06sp/handouts/lecture12.pdf p.39 (a copy included)
  // It is the node where the rotation can occur.
  Position LastS = NULL; 
  Position K = T;
  while(K != NULL) // We find the insertion location, insert the node, and save the path from root to that location along the way
  {
    s->Array[++s->TopOfStack] = K; // push the node to stack
    if (Height(K->Left) - Height(K->Right) != 0)
      LastS = K;
    if (elem < K->Element)
    {
      if (K->Left == NULL)
      {
        K->Left = makeNode(elem);
        s->Array[++s->TopOfStack] = K->Left; // push the node to stack
        break;
      }
      else
        K = K->Left;
    }
    else if (elem > K->Element)
    {
      if (K->Right == NULL)
      {
        K->Right = makeNode(elem);
        s->Array[++s->TopOfStack] = K->Right; // push the node to stack
        break;
      }
      else
        K = K->Right;
    }
    else
      break;
  }
  Position M = NULL;
  while(s->TopOfStack != -1) // We pop the element from the stack, do the rotation when we meet LastS node, and update height of each node.
  {
    M = s->Array[s->TopOfStack--];
    if (M == LastS)
    {
      if (elem > T->Element) // the path is in the right subtree of the root. We relies on this info to determine what rotation methods to call
      {
        if (Height(M->Right) - Height(M->Left) == 2)
        {
          if (elem < M->Right->Element)
          {
            if (M == T) // handles the case when insert 3 after 2,1,4,5,9 (do the double rotation at the root)
            {
              T = doubleRotateWithRight(M);
            }
            else
            {
              s->Array[s->TopOfStack]->Right = doubleRotateWithRight(M);
            }
          }
          else
          {
            s->Array[s->TopOfStack]->Right = singleRotateWithRight(M);
          }
        }
      }
      else // the path is in the left subtree of the root
      {
        if (Height(M->Right) - Height(M->Left) == 2)
        {
          if (elem < M->Left->Element)
          {
            s->Array[s->TopOfStack]->Left = singleRotateWithLeft(M);
          }
          else
          {
            if (M == T)
            {
              T = doubleRotateWithLeft(M);
            }
            else
            {
              s->Array[s->TopOfStack]->Left = doubleRotateWithLeft(M);
            }
          }
        }
      }
    }
    else
    {
      M->Height = max(Height(M->Left), Height(M->Right)) + 1;
    }
  }
  if (s != NULL) // dispose the stack
  {
    free(s->Array);
    free(s);
  }
  return T;
}

AVL
delete(ET elem, AVL T)
{
  // Perform a normal BST deletion
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

  // Peform AVL deletion specific part
  if (T == NULL) // No node left, simply return
    return T;
  T->Height = max(Height(T->Left), Height(T->Right)) + 1; // update the height for the current node
  if (Height(T->Left) - Height(T->Right) == 2)
  {
    if (Height(T->Left->Left) - Height(T->Left->Right) >= 0) 
      T = singleRotateWithLeft(T); //Left Left case
    else
      T = doubleRotateWithLeft(T); //Left Right case
  }
  else if (Height(T->Right) - Height(T->Left) == 2)
  {
    if (Height(T->Right->Right) - Height(T->Right->Left) >= 0)
      T = singleRotateWithRight(T); //Right Right case
    else
      T = doubleRotateWithRight(T); //Right Left case
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

AVL
initializeAVL(ET* array, int arrayLength)
{
  AVL T = NULL;
  int i;
  for(i = 0; i < arrayLength; i++)
    T = insert(array[i], T);
  return T;
}

static void
bst_print_dot_aux(AVL T, FILE* stream)
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
bst_print_dot(AVL T, FILE* stream)
{
  fprintf(stream, "digraph AVLSearchTree \{\n");
  bst_print_dot_aux(T, stream);
  fprintf(stream,"}\n");
}

// LastNode is the address containing last value that was assigned to a node
// This function has some nice trick:
// - "*T" is same as "struct AVLTreeNode"
// - we use "*LastNode" to assign value to the tree nodes. In this case, we don't really care about the actual
//   values as long as we satisfy BST property.
static AVL
genTree(int H, int *LastNode)
{
  AVL T;

  if (H >= 0)
  {
    T = malloc(sizeof(*T));
    T->Left = genTree(H-1, LastNode);
    // *LastNode++ will first do "LastNode++" (increamenting the address) then try to access the element using *.
    // We want to access the element first then incrementing. Remember associativity is "right to left" for ++ and *
    T->Element = ++*LastNode; 
    T->Right = genTree(H-2, LastNode);
    return T;
  }
  else
    return NULL;
}

// O(log N)
AVL
minAVL(int H)
{
  int LastNodeAssigned = 0;
  return genTree(H, &LastNodeAssigned);
}
