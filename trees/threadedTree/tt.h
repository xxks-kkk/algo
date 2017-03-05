#include "utility.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// threaded binary tree: https://en.wikipedia.org/wiki/Threaded_binary_tree
// Technically speaking, this is a double threaded BST implementation.

/*
 * MAW 4.45 Since a binary search tree with N nodes has N+1 NULL pointers,
 * half the space allocated in a binary search tree for pointer information is wasted.
 * Suppose that if a node has a NULL left child, we make its left child point to 
 * its inorder predecessor, and if a node has a NULL right child, we make its right child
 * point to its inorder successor. This is known as a threaded tree and the extra pointers
 * are called threads.
 *
 * The advantage of threaded tree is you can do tree traversals somewhat easier and without recursion. 
 * The disadvantage is that it reeks of old-style hacking.
 */

#ifndef _TT_H
#define _TT_H

typedef int ET;
struct TreeNode;
typedef struct TreeNode *Position;
typedef Position TT;

TT createEmptyTT();
TT makeEmpty(TT);
Position findMin(TT);
Position findMax(TT);
TT insert(ET, TT);
TT delete(ET, TT);
ET retrieve(Position);
TT initializeTT(ET*, int);
void tt_print_dot(TT, FILE*);

#endif
