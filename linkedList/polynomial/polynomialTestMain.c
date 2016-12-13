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
  
  return 0;
}
