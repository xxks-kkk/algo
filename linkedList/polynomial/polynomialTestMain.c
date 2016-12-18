#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main()
{  
  printf("///////////////////////\n");
  printf("// POLYNOMIAL TEST\n");
  printf("///////////////////////\n\n");

  printf("TEST: initializePolynomial\n");
  int coefficient0[] = {1,2,3};
  int exponent0[] = {1,2,3};
  Polynomial A0 = initializePolynomial(coefficient0, exponent0, 3);
  printPolynomial(A0);

  printf("TEST: add two Polynomials\n");
  Polynomial B1 = initializePolynomial(coefficient0, exponent0, 3);
  int coefficient1[] = {4};
  int exponent1[] = {4};
  Polynomial D1 = initializePolynomial(coefficient1, exponent1, 1);
  Polynomial C10 = add(A0,B1);
  Polynomial C11 = add(A0,D1);
  printPolynomial(C10);
  printPolynomial(C11);

  printf("TEST: multiply two Polynomials\n");
  printf("Algorithm 1\n");
  int coefficient20[] = {3,2};
  int exponent20[] = {2,3};
  int coefficient21[] = {5,6};
  int exponent21[] = {4,5};
  Polynomial B2 = initializePolynomial(coefficient20, exponent20, 2);
  Polynomial B3 = initializePolynomial(coefficient21, exponent21, 2);
  Polynomial C20 = multiply1(B2,B3);
  printPolynomial(C20);

  printf("Algorithm 2\n");
  Polynomial C21 = multiply2(B2,B3);
  printPolynomial(C21);
  
  return 0;
}
