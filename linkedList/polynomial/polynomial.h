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

/**---- BASIC LIST OPERATION POLYNOMIAL VERSION ----**/

/* Insert (after legal term P)
 */
void insert(int coefficent, int exponent, PtrToNode p);


/**---- VARIOUS POLYNOMIAL PROBLEMS ----**/

/* Create a polynomial from given arrays.
 * The first input array represents all the coefficients of the polynomial.
 * The second input array represents all the corresponding exponents.
 */
Polynomial initializePolynomial(int coefficient[], int exponent[], int numterms);

/* Print out a polynomial
 * The format looks like {coefficient, exponent}->{coefficient, exponent}->...
 */
void printPolynomial(Polynomial A);


/* 3.6 Write a function to add two polynomials. Do not
 * destroy the input. Use a linked list implementation.
 * We assume the input polynomials are sorted in ascending order.
 */
Polynomial add(Polynomial A, Polynomial B);

/* 3.7 Write a function to multiply two polynomials, using a linked list 
 * implementation. You must make sure that the output polynomial is sorted
 * by exponent and has at most one term of any power.
 * We assume the output is sorted in descending order.
 */
Polynomial multiply1(Polynomial A, Polynomial B);
