#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * MAW 4.10 Write routines to implement the basic binary search tree operations.
 */

#ifndef _BST_H
#define _BST_H

typedef int ET;

struct TreeNode;
typedef struct TreeNode *Position;
typedef Position BST;

BST makeEmpty(BST);
Position find(ET, BST);
Position findMin(BST);
Position findMax(BST);
BST insert(ET, BST);
BST delete(ET, BST);
ET retrieve(Position);

/*
 * Create a BST based upon the given array
 */
BST initializeBST(ET*, int);

/* 
 * Generate a dot file to be fed into Graphviz to display tree
 */
void bst_print_dot(BST, FILE*);

/*
 * MAW 4.28 Write efficient functions that take only a pointer to the root of a binary tree T,
 * and compute:
 * a. The number of nodes in T.
 * b. The number of leaves in T.
 * c. The number of full nodes in T.
 */
int numNodes(BST);
int numLeaves(BST);
int numFullNodes(BST);

#endif
