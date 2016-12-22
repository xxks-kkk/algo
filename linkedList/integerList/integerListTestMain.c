#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main()
{  
  printf("///////////////////////\n");
  printf("// POLYNOMIAL TEST\n");
  printf("///////////////////////\n\n");

  printf("TEST: initializePolynomial\n");
  int coefficient0[] = {3,2,1};
  int exponent0[] = {3,2,1};
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
  int exponent20[] = {3,2};
  int coefficient21[] = {5,6};
  int exponent21[] = {5,4};
  Polynomial B2 = initializePolynomial(coefficient20, exponent20, 2);
  Polynomial B3 = initializePolynomial(coefficient21, exponent21, 2);
  Polynomial C20 = multiply1(B2,B3);
  printPolynomial(C20);

  printf("Algorithm 2\n");
  Polynomial C21 = multiply2(B2,B3);
  printPolynomial(C21);

  printf("TEST: power of Polynomials\n");
  int coefficient30[] = {1,1};
  int exponent30[] = {1,0};
  Polynomial B4 = initializePolynomial(coefficient30, exponent30, 2);
  Polynomial C3 = powPolynomial(B4, 2);
  printPolynomial(C3);
  
  
  return 0;
}
