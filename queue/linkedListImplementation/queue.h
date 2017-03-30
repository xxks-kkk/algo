#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/* 
 * MAW 3.25.a Write the routines to implement queues using: Linked Lists
 *
 * We use a header node at the very beginning of the linked list. 
 *
 * Front: | header node | -> | data node | -> | data node | :Rear
 */
#ifndef _QUEUE_H
#define _QUEUE_H

typedef int ET;

struct QueueRecord;
struct QueueCDT;
typedef struct QueueRecord* PtrToNode;

// CDT: concrete-type-of-a-queue
// ADT: abstract-type-of-a-queue
typedef struct QueueCDT* QueueADT; // naming convention: https://www.cs.bu.edu/teaching/c/queue/linked-list/types.html

int isEmpty(QueueADT Q);
QueueADT createQueue();
void disposeQueue(QueueADT Q);
void makeEmpty(QueueADT Q);
void enqueue(ET elem, QueueADT Q);
ET front(QueueADT Q);
void dequeue(QueueADT Q);
ET frontAndDequeue(QueueADT Q);

QueueADT initializeQueue(ET array[], int lengthArray);
void printQueue(QueueADT Q);

#endif

