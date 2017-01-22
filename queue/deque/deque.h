#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/* 
 * MAW 3.26 A deque is a data structure consisting of a list of items,
 * on which the following operations are possible:
 *
 * Push(X,D):   Insert item X on the front end of deque D.
 * Pop(D):      Remove the front item fron deque D and return it.
 * Inject(X,D): Insert item X on the rear end of deque D.
 * Reject(D):   Remove the rear item from deque D and return it.
 *
 * Write routines to support the deque that take O(1) time per operation.
 * 
 * We use a circular array implementation. 
 * Whenever Rear gets to the end of the array, it is wrapped around to the
 * beginning. Whenever Front gets to the beginning of the array, it is wrapped around to the
 * end.  
 * 
 * For a linked list version, we can have a single linked list with two
 * header nodes: one at the beginning and one at the end of the list.
 */
#ifndef _DEQUE_H
#define _DEQUE_H

typedef int ET;

struct DequeRecord;
typedef struct DequeRecord* Deque;

int isEmpty(Deque D);
int isFull(Deque D);
Deque createDeque(int maxElements);
void disposeDeque(Deque D);
void makeEmpty(Deque D);
void push(ET elem, Deque D);
ET pop(Deque D);
void inject(ET elem, Deque D);
ET eject(Deque D);

Deque initializeDeque(ET array[], int lengthArray);
void printDeque(Deque D);

#endif

