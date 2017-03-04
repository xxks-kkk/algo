#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * MAW 4.40 Write a procedure to traverse a tree stored with child/sibling links.
 */

#ifndef _CSP_H
#define _CSP_H

typedef char ET;

struct CSPTreeNode;
typedef struct CSPTreeNode *Position;
typedef Position CSPT;

CSPT makeEmpty(CSPT); //TODO: not implemented
Position find(ET, CSPT);
CSPT insert(ET, CSPT, ET, int);
CSPT delete(ET, CSPT); //TODO: not implemented
ET retrieve(Position);
void cspt_print_dot(CSPT, FILE*);

/*
 * MAW 4.42 Give a polynomial time algorithm to decide if two trees are isomorphic.
 * Return 1 if not isomorphic; 0 if isomorphic
 */
int isomorphic(CSPT, CSPT);

#endif

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

struct QueueRecord;
typedef struct QueueRecord* PtrToNode;
typedef struct QueueCDT* QueueADT; 

int isEmpty(QueueADT Q);
QueueADT createQueue();
void makeEmptyQueue(QueueADT Q);
void disposeQueue(QueueADT Q);
void enqueue(Position elem, QueueADT Q);
void dequeue(QueueADT Q);
Position frontAndDequeue(QueueADT Q);

#endif
