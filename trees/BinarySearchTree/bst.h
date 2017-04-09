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
Position findMinBST(BST);
Position findMaxBST(BST);
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

/*
 * MAW 4.35 Write a routine to list our the nodes of a binary tree in level-order. List the root, then nodes at depth 1,
 * followed by nodes at depth 2, and so on. You must do this in linear time.
 */
void levelOrder(BST);

/*
 * MAW 4.41 Two binary trees are similar if they are both empty or both nonempty and have similar left and right subtrees.
 * Write a function to decide whether two binary trees are similar. 
 * Return 1 if not similar; 0 if similar
 */
int similar(BST, BST);

/*
 * Check if two binary search tree are the same in terms of structure and elements
 */
int same(BST T1, BST T2);

/*
 * MAW 4.43 Show that via AVL single rotations, any binary search tree T_1 can be transformed into 
 * another search tree T_2 (with the same keys)
 * Return newly transformed T1
 */
BST transform(BST T1, BST T2);

/*
 * Given a binary search tree, return the inorder traversal of its nodes' values
 * as an array.
 */
int* inorderTraversal(BST root, int* returnSize);

/*
 * Given a binary tree, you need to compute the length of the diameter of the tree. 
 * The diameter of a binary tree is the length of the longest path between 
 * any two nodes in a tree. This path may or may not pass through the root.
 *
 * NOTE: we use BST instead of binary tree.
 */
int diameterOfBST(BST root);

#endif


/*
 * A simple queue for BST functions
 */
#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

struct QueueRecord;
typedef struct QueueRecord* PtrToNode;
typedef struct QueueCDT* QueueADT; // naming convention: https://www.cs.bu.edu/teaching/c/queue/linked-list/types.html

int isEmpty(QueueADT Q);
QueueADT createQueue();
void makeEmptyQueue(QueueADT Q);
void disposeQueue(QueueADT Q);
void enqueue(Position elem, QueueADT Q);
void dequeue(QueueADT Q);
Position frontAndDequeue(QueueADT Q);

#endif
