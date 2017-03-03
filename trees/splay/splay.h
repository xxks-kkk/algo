#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _SPLAY_H
#define _SPLAY_H

typedef int ET;

/*
 * MAW 4.27 Write a program to perform random operations on splay trees.
 * Count the total number of rotations performed over the sequence. How
 * does the running time compare to AVL trees and unbalanced binary
 * search trees?
 *
 * NOTE: Implement Splay operations and numRotations counter and 
 * don't bother to run the actual experimentation
 */

int numRotations; //count the number of rotations happened to a specific tree.

struct SplayTreeNode;
typedef struct SplayTreeNode *Position;
typedef Position Splay;

Splay makeEmpty(Splay);
Position find(ET, Splay);
Position findMin(Splay);
Position findMax(Splay);
Splay insert(ET, Splay);
Splay insert2(ET, Splay);
Splay delete(ET, Splay);
Splay delete2(ET, Splay);
ET retrieve(Position);
int getNumRotations();
Splay initializeBST(ET*, int);
void bst_print_dot(Splay, FILE*);

#endif
