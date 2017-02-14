#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _AVL_H
#define _AVL_H

typedef int ET;

struct AVLTreeNode;
typedef struct AVLTreeNode *Position;
typedef Position AVL;

AVL makeEmpty(AVL);
Position find(ET, AVL);
Position findMin(AVL);
Position findMax(AVL);

/*
 * MAW 4.18 Write the remaining procedures to implement AVL single and double rotations.
 */
AVL insert(ET, AVL);

/*
 * MAW 4.19 Write a nonrecursive function to insert into an AVL tree.
 */
AVL insert2(ET, AVL);

/* 
 * MAW 4.20 How can you implement (nonlazy) deletion in AVL trees?
 */
AVL delete(ET, AVL);
ET retrieve(Position);

/*
 * Create a AVL tree based upon the given array
 */
AVL initializeAVL(ET*, int);

/* 
 * Generate a dot file to be fed into Graphviz to display tree
 */
void bst_print_dot(AVL, FILE*);

/*
 * MAW 4.30 Write a function to generate the AVL tree of height H with fewest nodes. 
 */
AVL minAVL(int H);

#endif
