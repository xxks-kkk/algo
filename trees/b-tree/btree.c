#include "btree.h"
#include "utility.h"
#include <assert.h>

// Implementation reference:
// 1. http://www.cs.yale.edu/homes/aspnes/pinewiki/BTrees.html
// 2. http://ilpubs.stanford.edu:8090/85/1/1995-19.pdf

#define MAX_KEYS (3) // Order of the B-tree

struct TreeNode
{
  int IsLeaf;                  // is this a leaf node?
  int NumKeys;                 // how many keys does this node contain?
  ET Keys[MAX_KEYS];
  Position Child[MAX_KEYS+1];  // child[i] holds nodes < keys[i] [child[0], 0, child[1], 1, ...]
};

static BT
btCreate(void)
{
  BT T;

  T = malloc(sizeof(*T));
  assert(T);

  T->IsLeaf = 1;
  T->NumKeys = 0;

  return T;
}

void 
makeEmpty(BT T)
{
  int i;
  if(!T->IsLeaf)
  {
    for(i = 0; i < T->NumKeys + 1; i++)
      makeEmpty(T->Child[i]);
  }
  free(T);
}

Position
find(ET elem, BT T)
{
  int pos;

  if (T->NumKeys == 0) // check for empty tree
    return 0;
  pos = searchElement(T->NumKeys, T->Keys, elem);

  if (pos < T->NumKeys && T->Keys[pos] == elem && T->IsLeaf) // we find the elem
    return T;
  else
    return find(elem, T->Child[pos]);
}

/* insert a new element into a tree
 * returns new right sibling if the node splits
 * and puts the median in *median
 * else returns 0
 */
static BT
btInsertInternal(BT T, int elem, int* minValRight)
{
  int pos;
  int mid;
  BT b2;

  pos = searchElement(elem, T->Keys, T->NumKeys);

  if (pos < T->NumKeys && T->Keys[pos] == elem)
    return 0; // the element is already in the tree. Nothing to do here.

  if (T->IsLeaf)
  {
    memmove(&T->Keys[pos+1], &T->Keys[pos], sizeof(*(T->Keys)) * (T->NumKeys - pos)); // everybody above pos moves up one space
    T->Keys[pos] = elem;
    T->NumKeys++;
  }
  else
  {
    b2 = btInsertInternal(T->Child[pos], elem, minValRight); // insert in child

    if (b2) // node splits and we need to update the key value in T
    {
      memmove(&T->Keys[pos+1], &T->Keys[pos], sizeof(*(T->Keys)) * (T->NumKeys - pos)); // every key above pos moves up one space
      memmove(&T->Child[pos+2], &T->Child[pos+1], sizeof(*(T->Keys)) * (T->NumKeys - pos + 1));  // new child goes in pos + 1
      T->Keys[pos] = *minValRight;    
      T->Child[pos+1] = b2;
      T->NumKeys++;      
    }
  }

  if (T->NumKeys >= MAX_KEYS)    
  {
    mid = T->NumKeys / 2;

    /* make a new node for keys > median */
    b2 = malloc(sizeof(*b2));
    b2->NumKeys = T->NumKeys - mid - 1;
    b2->IsLeaf = T->IsLeaf;

    if (T->IsLeaf) // here, we want to make distinguish betweens splitting leaves and splitting internal nodes
    {
      *minValRight = T->Keys[mid+1];
      T->NumKeys = mid + 1;      
    }
    else
    {
      *minValRight = T->Keys[mid];
      memmove(b2->Child, &T->Child[mid+1], sizeof(*(T->Child)) * (b2->NumKeys + 1));
      T->NumKeys = mid;
    }
    memmove(b2->Keys, &T->Keys[mid+1], sizeof(*(T->Keys)) * b2->NumKeys);          

    return b2;
  }
  else
  {
    return 0;
  }
}

void
insert(ET elem, BT T)
{
  BT b1; // new left child
  BT b2; // new right child
  int minValRight; // the minimum value in the right subtree of the root, which will be updated into the root

  if (T == NULL)
    T = btCreate();

  b2 = btInsertInternal(T, elem, &minValRight);
  
  if (b2)
  {
    // basic issue here is that we are at the root
    // so if we split, we have to make a new root
    b1 = malloc(sizeof(*b1));
    assert(b1);

    memmove(b1, T, sizeof(*T)); // copy root to b1

    T->NumKeys = 1;
    T->IsLeaf = 0;
    T->Keys[0] = minValRight;
    T->Child[0] = b1;
    T->Child[1] = b2;
  }
}
  
void
delete(ET elem, BT T)
{
  return NULL;
}
  
BT
initializeBT(ET* array, int arrayLength)
{
  BT T = btCreate();
  int i;
  for(i = 0; i < arrayLength; i++)
    insert(array[i], T);
  return T;
}

/*
 * This is the debug function. It prints all the key values
 * in the node. Careful to use when MAX_KEYS value is relatively
 * large.
 */
static void
bt_print_dot_aux_debug(BT T, FILE* stream, int *LastNode)
{
  int curnode = (*LastNode)++;
  int i;
  if (T != NULL)
  {
    fprintf(stream, "node%d[label=\"", curnode);
    for(i=0; i < MAX_KEYS; i++)
    {
      fprintf(stream, "%d%s", T->Keys[i], (i+1 == MAX_KEYS) ? ("") : ("|"));
    }
    fprintf(stream,"\"];\n");
    for(i=0; i < MAX_KEYS+1; i++)
    {
      if (T->Child[i] != NULL)
      {
        fprintf(stream, "node%d->node%d;\n", curnode, *LastNode);
        bt_print_dot_aux_debug(T->Child[i], stream, LastNode);
      }
    }
  }
}

static void
bt_print_dot_aux(BT T, FILE* stream, int *LastNode)
{
  int curnode = (*LastNode)++;
  int i;
  if (T != NULL)
  {
    fprintf(stream, "node%d[label=\"", curnode);
    for(i=0; i < MAX_KEYS; i++)
    {
      if (i < T->NumKeys)        
        fprintf(stream, "%d%s", T->Keys[i], "|");
      else
        fprintf(stream, "-%s", (i+1 == MAX_KEYS) ? ("") : ("|"));        
    }
    fprintf(stream,"\"];\n");    
    for(i=0; i < T->NumKeys+1; i++)
    {
      if (T->Child[i] != NULL)
      {
        fprintf(stream, "node%d->node%d;\n", curnode, *LastNode);
        bt_print_dot_aux(T->Child[i], stream, LastNode);
      }
    }
  }
}

void
bt_print_dot(BT T, FILE* stream)
{
  fprintf(stream, "digraph BTree {\n");
  fprintf(stream, "node [shape = record, height = 0.1];\n");
  int LastNodeAssigned = 0;
#ifdef DEBUG
  bt_print_dot_aux_debug(T, stream, &LastNodeAssigned);
#else
  bt_print_dot_aux(T, stream, &LastNodeAssigned);
#endif
  fprintf(stream,"}\n");
}


