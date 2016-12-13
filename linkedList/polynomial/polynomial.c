#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

void insert(int coefficent, int exponent, PtrToNode p)
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
    printf("{%d, %d}->", dummyA->coefficient, dummyA->exponent);
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
