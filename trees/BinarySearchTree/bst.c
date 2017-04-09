#include "bst.h"

struct TreeNode
{
  ET Element;
  BST Left;
  BST Right;
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
find(ET elem, BST T)
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
findMinBST(BST T)
{
  if (T == NULL)
    return NULL;
  else if (T->Left == NULL)
    return T;
  else
    return findMinBST(T->Left);
}

Position
findMaxBST(BST T)
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
  }
  else if (elem < T->Element)
  {
    T->Left = insert(elem, T->Left);
  }
  else if (elem > T->Element)
  {
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
      tmpCell = findMinBST(T->Right);
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

// O(N)
int
numNodes(BST T)
{
  int count = 0;
  if (T == NULL)
    return 0;
  else
  {
    count += numNodes(T->Left);
    count += numNodes(T->Right);
    count += 1;
  }
  return count;
}

// O(N)
int
numLeaves(BST T)
{
  int count = 0;
  if (T == NULL)
    return 0;
  else if (T->Left == NULL && T->Right == NULL)
    count ++;
  else
  {
    count += numLeaves(T->Left);
    count += numLeaves(T->Right);
  }
  return count;
}

// O(N)
int
numFullNodes(BST T)
{
  int count = 0;
  if (T == NULL)
    return 0;
  if (T->Left != NULL && T->Right != NULL)
  {
    count ++;
    count += numFullNodes(T->Right);
    count += numFullNodes(T->Left);
  }
  else if (T->Left == NULL)
    count += numFullNodes(T->Right);
  else if (T->Right == NULL)
    count += numFullNodes(T->Left);
  return count;
}

// O(N + NH) = O(NH), where H is the height of BST
BST
randBST(int N)
{
  int *array = malloc(N * sizeof(int));
  permutation(array, N); // O(N)
  return initializeBST(array, N);
}

// O(log N)
// The other solution: https://cseweb.ucsd.edu/classes/su05/cse100/cse100hw1.pdf
static BST
genTrees(int H, int* LastNode)
{
  BST T = NULL;

  if (H >= 0)
  {
    T = malloc(sizeof(*T));
    T->Left = genTrees(H-1, LastNode);
    T->Element = ++*LastNode;
    T->Right = genTrees(H-1, LastNode);
  }
  return T;
}

BST
perfectBST(int H)
{
  int LastNodeAssigned = 0;
  return genTrees(H, &LastNodeAssigned);
}

// This is known as one-dimensional range searching. The time is O(K) (K
// is the number of keys printed.) to perform the inorder traversal, if
// a significant number of nodes are found, and also proportional to the depth of the tree,
// if we get to some leaves (for instance, if no nodes are found). Since the average depth is
// O(log N), this gives an O(K + log N) average bound.
void
printRangeKeys(BST T, int k1, int k2)
{
  if (T != NULL)
  {
    /* if (T->Element >= k1 && T->Element <= k2) */
    /* { */
    /*   printf("%d,", T->Element); */
    /*   printRangeKeys(T->Left, k1, k2); */
    /*   printRangeKeys(T->Right, k1, k2); */
    /* } */
    /* else if (T->Element < k1) */
    /*   printRangeKeys(T->Right, k1, k2); */
    /* else if (T->Element > k2) */
    /*   printRangeKeys(T->Left, k1, k2);       */

    // advantage compared with the above commented one:
    // 1. shorter lines of code
    // 2. values are printed in sorted order
    if (k1 <= T->Element)
      printRangeKeys(T->Left, k1, k2);
    if (k1 <= T->Element && T->Element <= k2)
      printf("%d,", T->Element);
    if (T->Element <= k2)
      printRangeKeys(T->Right, k1, k2);
  }
}

////**** We implement a simple Queue here ****////
struct QueueRecord
{
  Position Element;
  PtrToNode Next;
};

struct QueueCDT
{
  PtrToNode Front;
  PtrToNode Rear;
};

int
isEmpty(QueueADT Q)
{
  return Q->Front == Q->Rear;
}

QueueADT
createQueue()
{
  QueueADT Q = malloc(sizeof(struct QueueCDT));
  Q->Front = malloc(sizeof(struct QueueRecord));
  Q->Front->Next = NULL;
  Q->Rear = Q->Front;
  return Q;
}

void
makeEmptyQueue(QueueADT Q)
{
  while(!isEmpty(Q))
  {
    dequeue(Q);
  }
}

void
disposeQueue(QueueADT Q)
{
  makeEmptyQueue(Q);
  free(Q->Front);
  free(Q);
}
  
void
enqueue(Position elem, QueueADT Q)
{  
  PtrToNode tmpNode = malloc(sizeof(struct QueueRecord));
  tmpNode->Element = elem;
  tmpNode->Next = NULL;
  Q->Rear->Next = tmpNode;
  Q->Rear = tmpNode;
}

void
dequeue(QueueADT Q)
{
  PtrToNode dummyQ;
  dummyQ = Q->Front->Next;
  Q->Front->Next = dummyQ->Next;
  // we don't want to accidentally delete Q->Rear when there is only one data node left
  if (dummyQ->Next == NULL) 
  {
    Q->Rear = Q->Front;
  }
  free(dummyQ);
}

Position
frontAndDequeue(QueueADT Q)
{
  Position tmp = Q->Front->Next->Element;
  dequeue(Q);
  return tmp;
}
////**** End of queue implementation ****////

void
levelOrder(BST T)
{
  Position tmp;
  QueueADT Q = createQueue();
  enqueue(T, Q); // put the root on queue
  while (!isEmpty(Q))
  {
    tmp = frontAndDequeue(Q);
    printf("%d,", tmp->Element);
    if (tmp->Left != NULL)
      enqueue(tmp->Left, Q);
    if (tmp->Right != NULL)
      enqueue(tmp->Right, Q);
  }
  disposeQueue(Q);
}

int
similar(BST T1, BST T2)
{
  if (T1 == NULL && T2 == NULL)
    return 0;
  if ((T1 == NULL && T2 != NULL) || (T1 != NULL && T2 == NULL))
    return 1;
  return (similar(T1->Left, T2->Left) && similar(T1->Right, T2->Right));
}

// Determine if the given two trees are identical
int
same(BST T1, BST T2)
{
  if (T1 == NULL && T2 == NULL)
    return 0;
  if ((T1 != NULL && T2 == NULL) ||
      (T1 == NULL && T2 != NULL))
    return 1;
  if (T1->Element == T2->Element)
    return 0;
  if (T1->Element != T2->Element)
    return 1;
  return same(T1->Left, T2->Left) && same(T1->Right, T2->Right);
}

BST
transform(BST T1, BST T2)
{
  return T1;
}

static void
inorderTraversalHelper(BST root, int** array, int *i)
{
  if (root != NULL)
  {
    inorderTraversalHelper(root->Left, array, i);
    *(*array+(*i)++) = root->Element;
    inorderTraversalHelper(root->Right, array, i);
  }
}

int*
inorderTraversal(BST root,
                 int* returnSize)
{
  *returnSize = numNodes(root);
  int *array = malloc(*returnSize * sizeof(int));
  int i = 0;
  inorderTraversalHelper(root, &array, &i);
  return array;
}

static int
diameterOfBSTHelper(BST root, int *maxDiaDepth)
{
  if(!root) return 0;
  int leftDepth = diameterOfBSTHelper(root->Left, maxDiaDepth);
  int rightDepth = diameterOfBSTHelper(root->Right, maxDiaDepth);
  int cand = leftDepth + rightDepth;
  if (cand > *maxDiaDepth) *maxDiaDepth = cand;
  return max(leftDepth+1, rightDepth+1);
}

/*
 * Given a binary tree 
 *
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 */
int
diameterOfBST(BST root)
{
  int maxDiaDepth = 0;
  diameterOfBSTHelper(root, &maxDiaDepth);
  return maxDiaDepth;
}
