#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

// Order Statistic Tree: https://en.wikipedia.org/wiki/Order_statistic_tree
#ifndef _OST_H
#define _OST_H

typedef int ET;

struct TreeNode;
typedef struct TreeNode *Position;
typedef Position BST;

BST makeEmpty(BST);

/*
 * MAW 4.44 Suppose we want to add the operation FindKth to our repertoire.
 * The operation FindKth(T,i) returns the element in tree T with ith smallest key.
 * Assume all elements have distinct keys.
 */
// Implementation hints:
// http://stackoverflow.com/questions/2329171/find-kth-smallest-element-in-a-binary-search-tree-in-optimum-way?page=1
Position findKthSmallest(BST, int);

/*
 * Returns the element in tree T with ith largest key.
 */
Position findKthLargest(BST, int);
Position findMin(BST);
Position findMax(BST);
BST insert(ET, BST);
BST delete(ET, BST);
ET retrieve(Position);
BST initializeBST(ET*, int);
void bst_print_dot(BST, FILE*);

#endif
