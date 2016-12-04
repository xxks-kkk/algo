#ifndef _POLYNOMIALL_H
#define _POLYNOMIALL_H

/* We assume the nodes sorted by exponents */
typedef struct Node *PtrToNode;

struct Node
{
  int coefficient;
  int exponent;
  PtrToNode Next;
};

typedef PtrToNode Polynomial; 

#endif

/* 3.6 Write a function to add two polynomials. Do not
 * destroy the input. Use a linked list implementation.
 */
Polynomial add(Polynomial A, Polynomial B);
