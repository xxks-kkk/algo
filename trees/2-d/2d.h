#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <assert.h>
#include <string.h>

/*
 * MAW 4.46 A binary search tree presupposes that searching is based on only one 
 * key per record. Suppose we would like to be able to perform searching based on
 * either of two keys, Key1 or Key2.
 *
 * An alternative method is a 2-d tree. A 2-d tree is similar to a binary search tree, 
 * except that branching at even levels is done with respsect to Key1, and branching at
 * odd levels is done with Key2.
 */
#ifndef _TD_H_
#define _TD_H_

struct TdTreeNode;
typedef struct TdTreeNode *Position;
typedef Position TdTree;

void makeEmpty(TdTree T);
/*
 * MAW 4.16.b Write a routine to perform insertion into a 2-d tree. 
 */
TdTree insertion(char elem[], TdTree T);
/*
 * MAW 4.16.c Write an efficient procedure that prints all records in the tree that simultaneously satisfy
 * the constraints Low1 <= Key1 <= High1 and Low2 <= Key2 <= High2
 */
void tdprintRange(char* low1, char* high1, char* low2, char* high2, TdTree T);
TdTree initializeTdTree(char elem[][30], int);
void td_print_dot(TdTree T, FILE* stream);

#endif
