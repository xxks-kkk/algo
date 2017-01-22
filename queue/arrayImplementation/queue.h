#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/* 
 * MAW 3.25.b Write the routines to implement queues using: Arrays
 *
 * We use a circular array implementation. 
 * Whenever Front or Rear gets to the end of the array, it is wrapped around to the
 * beginning.
 */
#ifndef _QUEUE_H
#define _QUEUE_H

typedef int ET;

struct QueueRecord;
typedef struct QueueRecord* Queue;

int isEmpty(Queue Q);
int isFull(Queue Q);
Queue createQueue(int maxElements);
void disposeQueue(Queue Q);
void makeEmpty(Queue Q);
void enqueue(ET elem, Queue Q);
ET front(Queue Q);
void dequeue(Queue Q);
ET frontAndDequeue(Queue Q);

Queue initializeQueue(ET array[], int lengthArray);
void printQueue(Queue Q);

#endif

