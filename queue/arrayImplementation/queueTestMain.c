#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

void test_isEmpty();
void test_createQueue();
void test_makeEmpty();
void test_enqueue();
void test_front();
void test_dequeue();
void test_frontAndDequeue();
void test_initializeQueue();

int main()
{
  printf("///////////////////////\n");
  printf("// QUEUE TEST\n");
  printf("///////////////////////\n\n");

  test_createQueue();      printf("\n");
  test_initializeQueue();  printf("\n");
  test_isEmpty();          printf("\n");
  test_makeEmpty();        printf("\n");
  test_enqueue();          printf("\n");
  test_front();            printf("\n");
  test_dequeue();          printf("\n");
  test_frontAndDequeue();  printf("\n");
  return 0;
}

void
test_isEmpty()
{
  printf("TEST: isEmpty\n");
  Queue Q = createQueue(3);
  printQueue(Q);
  printf("is Queue empty: %s\n", (isEmpty(Q)) ? ("Yes") : ("No"));
  disposeQueue(Q);
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Q = initializeQueue(test_Q1, 3);
  printQueue(Q);
  printf("is Queue empty: %s\n", (isEmpty(Q)) ? ("Yes") : ("No"));  
  disposeQueue(Q);
}
  
void
test_createQueue()
{
  printf("TEST: createQueue\n");
  Queue Q = createQueue(3);
  printQueue(Q);
  disposeQueue(Q);
}

void
test_makeEmpty()
{
  printf("TEST: makeEmpty\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Queue Q = initializeQueue(test_Q1, 3);
  printQueue(Q);
  makeEmpty(Q);
  printf("test_Q1 after makeEmpty: \n");
  printQueue(Q);
  printf("Is test_Q1 empty?: %s\n", (isEmpty(Q)) ? ("Yes") : ("False"));
}

void
test_enqueue()
{
  printf("TEST: enqueue\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Queue Q = createQueue(10);
  printQueue(Q);
  int i;
  for (i = 0; i < 3; i++)
  {
    printf("enqueue: %d\n", test_Q1[i]);
    enqueue(test_Q1[i], Q);
  }
  printQueue(Q);
  disposeQueue(Q);  
}

void
test_front()
{
  printf("TEST: front\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Queue Q = initializeQueue(test_Q1, 3);
  printQueue(Q);
  printf("front: %d\n", front(Q));
  disposeQueue(Q);  
}

void
test_dequeue()
{
  printf("TEST: dequeue\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Queue Q = initializeQueue(test_Q1, 3);
  printQueue(Q);
  printf("After dequeue once: \n");
  dequeue(Q);
  printQueue(Q);
  disposeQueue(Q);  
}

void
test_frontAndDequeue()
{
  printf("TEST: frontAndDequeue\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Queue Q = initializeQueue(test_Q1, 3);
  printQueue(Q);
  printf("After dequeue the element: %d\n", frontAndDequeue(Q));
  printQueue(Q);
  disposeQueue(Q);  
}

void
test_initializeQueue()
{
  printf("TEST: createQueue\n");
  ET test_Q1[3] = {99, 1, 20};
  printf("test_Q1: ");
  printArray(test_Q1, 3);
  Queue Q = initializeQueue(test_Q1, 3);
  printQueue(Q);
  disposeQueue(Q);
}
