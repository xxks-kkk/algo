#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

void
insert(int coefficent, int exponent, PtrToNode p)
{
  PtrToNode tmpNode = malloc(sizeof(struct Node));
  tmpNode->coefficient = coefficent;
  tmpNode->exponent = exponent;
  tmpNode->Next = p->Next;
  p->Next = tmpNode;
}

Polynomial
initializePolynomial(int coefficient[], int exponent[], int numterms)
{
  Polynomial R = malloc(sizeof(struct Node));
  PtrToNode dummyR = R;
  int i;

  for (i=0; i < numterms; i++)
  {
    insert(coefficient[i], exponent[i], dummyR);
    dummyR = dummyR->Next;
  }
  return R;
}

void
printPolynomial(Polynomial A)
{
  PtrToNode dummyA = A->Next;

  while (dummyA != NULL)
  {
    printf("%d * X^%d + ", dummyA->coefficient, dummyA->exponent);
    dummyA = dummyA->Next;
  }
  printf("\n");
}

/* Runtime analysis: The first while loop iterates min{M,N}
 * times, with a constant amount of work being done at each
 * iteration. Whichever of the last two while loops iterates
 * max{M,N} - min{M,N} times, and again a constant amount of 
 * work gets done at each iteration. Therefore the program
 * has O(min{M,N}+(max{M,N}-min{M,N})) = O(max{M,N}) running
 * time.
 */
Polynomial
add(Polynomial A, Polynomial B)
{
  PtrToNode dummyA = A->Next;
  PtrToNode dummyB = B->Next;
  Polynomial C = malloc(sizeof(struct Node));
  PtrToNode dummyC = C;

  while (dummyA != NULL && dummyB != NULL)
  {
    if (dummyA->exponent < dummyB->exponent)
    {
      insert(dummyA->coefficient, dummyA->exponent, dummyC);
      dummyC = dummyC->Next;
      dummyA = dummyA->Next;
    }
    else if (dummyA->exponent > dummyB->exponent)
    {
      insert(dummyB->coefficient, dummyB->exponent, dummyC);
      dummyC = dummyC->Next;
      dummyB = dummyB->Next;
    }
    else
    {
      insert(dummyA->coefficient + dummyB->coefficient, dummyB->exponent, dummyC);
      dummyC = dummyC->Next;
      dummyA = dummyA->Next;
      dummyB = dummyB->Next;
    }
  }
  
  while(dummyA != NULL)
  {
    insert(dummyA->coefficient, dummyA->exponent, dummyC);
    dummyC = dummyC->Next;
    dummyA = dummyA->Next;
  }

  while(dummyB != NULL)
  {
    insert(dummyB->coefficient, dummyB->exponent, dummyC);
    dummyC = dummyC->Next;
    dummyB = dummyB->Next;
  }

  return C;
}

/* Runtime analysis: we start from the inner most two while loops.
 * Since R is initially empty, the loop only carry out once.
 * As we do the multiplication of two terms from A and B, the
 * output polynomial grows to maximum M*N terms. So, we have
 * (1 + 2 + ... + M*N). Then, we will repeat for M times due to the
 * outer most while loop. So, the runtime is O(M(1+2+3+ ... + M*N)), 
 * which is O(M^2 N^2).
 */
Polynomial
multiply1(Polynomial A, Polynomial B)
{
  Polynomial R = malloc(sizeof(struct Node));
  PtrToNode dummyRPrev = R;
  PtrToNode dummyR = R;
  PtrToNode dummyA = A->Next;
  PtrToNode dummyB = B->Next;

  int tmpExponent, tmpCoefficient;
  
  while (dummyA != NULL)
  {
    while (dummyB != NULL)
    {
      tmpExponent = dummyA->exponent + dummyB->exponent;
      tmpCoefficient = dummyA->coefficient * dummyB->coefficient;

      // we go through the output polynomial to see if there is
      // a term with the same exponent as our tmpExponent.
      while (dummyR != NULL)
      {
        if (dummyR->exponent == tmpExponent)
        {
          dummyR->coefficient = dummyR->coefficient + tmpCoefficient;
          break;
        }
        else
        {
          dummyRPrev = dummyR;
          dummyR = dummyR->Next;
        }
      }

      // We couldn't find the term with the same exponent, so we create
      // a new term in our output polynomial.
      if (dummyR == NULL)
      {
        insert(tmpCoefficient, tmpExponent, dummyRPrev);
      }
      
      dummyR = R;
      dummyB = dummyB->Next;
    }
    dummyB = B->Next;
    dummyA = dummyA->Next;
  }

  return R;
}
