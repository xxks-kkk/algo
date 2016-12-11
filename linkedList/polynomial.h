#ifndef _POLYNOMIALL_H
#define _POLYNOMIALL_H

/* We assume the nodes sorted by exponents 
 * and again, our linked list implementation
 * uses sentinel node 
 */
typedef struct Node *PtrToNode;

struct Node
{
  int coefficient;
  int exponent;
  PtrToNode Next;
};

typedef PtrToNode Polynomial; 

#endif

/* Create a polynomial from given arrays.
 * The first input array represents all the coefficients of the polynomial.
 * The second input array represents all the corresponding exponents.
 */
Polynomial initializePolynomial(int coefficient[], int exponent[]);


/* 3.6 Write a function to add two polynomials. Do not
 * destroy the input. Use a linked list implementation.
 */
Polynomial add(Polynomial A, Polynomial B);
