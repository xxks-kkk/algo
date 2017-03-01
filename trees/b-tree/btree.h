#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * MAW 4.37.a Write a routine to perform insertion into a B-tree.
 *          b Write a routine to perform deletion from a B-tree. 
 *          c Modify your insertion routine so that if an attempt is made 
 *            to add into a node that already has M entries, a search is performed
 *            for a sibling with less than M children before the node is split.
 */
// Here we implement B+-tree. We follow the notation from MAW to call B-tree.
#ifndef _BTREE_H
#define _BTREE_H

typedef int ET;

struct TreeNode;
typedef struct TreeNode *Position;
typedef Position BT;

/* We destroy the BT 
 */
void makeEmpty(BT);

/* We find the leaf that contains the target element.
 */
Position find(ET, BT);

/* Insert the element into the b-tree and return the newly formed b-tree.
 */
void insert(ET, BT);
void delete(ET, BT);
BT initializeBT(ET*, int);
void bt_print_dot(BT, FILE*);

#endif

