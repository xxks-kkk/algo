#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef _SPLAY_H
#define _SPLAY_H

typedef int ET;

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
