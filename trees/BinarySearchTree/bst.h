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

/*
 * MAW 4.29 Write a function to generate an N-node random binary search tree with distinct keys 1 through N.
 */
BST randBST(int);

/*
 * MAW 4.31 Write a function to generate a perfectly balanced binary search tree of height H with keys 1 through 2^{H+1}-1.
 */
BST perfectBST(int H);

/*
 * MAW 4.32 Write a function that takes as input a binary search tree, T, and two keys k_1 and k_2, which are ordered
 * so that k_1 <= k_2, and prints all elements X in the tree such that k_1 <= Key(X) <= k_2. Do not assume any
 * information about the type of keys except that they can be ordered (consistently). 
 */
void printRangeKeys(BST T, int k1, int k2);

#endif
