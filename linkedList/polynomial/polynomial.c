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

void
deletePolynomial(Polynomial A)
{
  PtrToNode dummyA = A->Next, tmp;
  A->Next = NULL;
  
  while(dummyA != NULL)
  {
    tmp = dummyA->Next;
    free(dummyA);
    dummyA = tmp;
  }
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
// This version we assume the input polynomials exponent are in
// ascending order.
/* Polynomial */
/* add(Polynomial A, Polynomial B) */
/* { */
/*   PtrToNode dummyA = A->Next; */
/*   PtrToNode dummyB = B->Next; */
/*   Polynomial C = malloc(sizeof(struct Node)); */
/*   PtrToNode dummyC = C; */

/*   while (dummyA != NULL && dummyB != NULL) */
/*   { */
/*     if (dummyA->exponent < dummyB->exponent) */
/*     { */
/*       insert(dummyA->coefficient, dummyA->exponent, dummyC); */
/*       dummyC = dummyC->Next; */
/*       dummyA = dummyA->Next; */
/*     } */
/*     else if (dummyA->exponent > dummyB->exponent) */
/*     { */
/*       insert(dummyB->coefficient, dummyB->exponent, dummyC); */
/*       dummyC = dummyC->Next; */
/*       dummyB = dummyB->Next; */
/*     } */
/*     else */
/*     { */
/*       insert(dummyA->coefficient + dummyB->coefficient, dummyB->exponent, dummyC); */
/*       dummyC = dummyC->Next; */
/*       dummyA = dummyA->Next; */
/*       dummyB = dummyB->Next; */
/*     } */
/*   } */
  
/*   while(dummyA != NULL) */
/*   { */
/*     insert(dummyA->coefficient, dummyA->exponent, dummyC); */
/*     dummyC = dummyC->Next; */
/*     dummyA = dummyA->Next; */
/*   } */

/*   while(dummyB != NULL) */
/*   { */
/*     insert(dummyB->coefficient, dummyB->exponent, dummyC); */
/*     dummyC = dummyC->Next; */
/*     dummyB = dummyB->Next; */
/*   } */

/*   return C; */
/* } */

// This version we assume that the input polynomials exponent are in descending order
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
      insert(dummyB->coefficient, dummyB->exponent, dummyC);
      dummyC = dummyC->Next;
      dummyB = dummyB->Next;
    }
    else if (dummyA->exponent > dummyB->exponent)
    {
      insert(dummyA->coefficient, dummyA->exponent, dummyC);
      dummyC = dummyC->Next;
      dummyA = dummyA->Next;
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


/* Runtime analysis: we start from the inner most while loops.
 * We traverse through the output polynomials to see if there is 
 * a term with the same exponent. The output polynomial has at most
 * M*N terms. Then for the middle loop, we iterate through N times.
 * And for outer most loop, we iterate through M times. So, the
 * total run time is O(M*N*MN) = O(M^2 N^2)
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

/* Runtime analysis: suppose polynomials A has M terms, and polynomials
 * B has N terms. M < N.
 * We instead of updating the result after each multiply, 
 * multiply one term from A (the polynomials
 * with fewer terms) by all the terms from B (the polynomials with 
 * more terms) giving a sorted linked list of terms with length N.  
 * Then we add this with the result linkedList using "add(...)".
 * So, we have the following runtime:
 * O(max(N,0)) + O(max(N,N)) + O(max(N,2N)) + ... + O(max(N, N(M-1))) = O(M^2 N)
 * Also, we caluate the length of A taking O(M); we calculate the length of B taking
 * O(N); we deleteList during the while loop taking O(MN). So, the total runtime is:
 * O(M^2 N) + O(M) + O(N) + O(MN) = O(M^2 N) 
 */
Polynomial
multiply2(Polynomial A, Polynomial B)
{
  int lenA = 0, lenB = 0;
  PtrToNode dummyA = A->Next;
  PtrToNode dummyB = B->Next;
  Polynomial R = malloc(sizeof(struct Node));
  PtrToNode dummyTmp, dummyShort, dummyLong, Long;
  Polynomial Tmp = malloc(sizeof(struct Node));  

  while(dummyA != NULL)
  {
    lenA++;
    dummyA = dummyA->Next;
  }

  while(dummyB != NULL)
  {
    lenB++;
    dummyB = dummyB->Next;
  }

  if (lenA < lenB)
  {
    dummyShort = A->Next;
    dummyLong = B->Next;
    Long = B;
  }
  else
  {
    dummyShort = B->Next;
    dummyLong = A->Next;
    Long = A;
  }

  while(dummyShort != NULL)
  {
    dummyTmp = Tmp;
    while(dummyLong != NULL)
    {
      int coefficient = dummyShort->coefficient * dummyLong->coefficient;
      int exponent = dummyShort->exponent + dummyLong->exponent;
      insert(coefficient, exponent, dummyTmp);
      dummyTmp = dummyTmp->Next;
      dummyLong = dummyLong->Next;
    }
    R = add(R, Tmp);
    dummyLong = Long->Next;
    deletePolynomial(Tmp);
    dummyShort = dummyShort->Next;
  }

  return R; 
}
