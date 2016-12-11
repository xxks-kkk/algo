#include "polynomial.h"

Polynomial
initializePolynomial(int coefficient[], int exponent[])
{



}

Polynomial
add(Polynomial A, Polynomial B)
{
  PtrToNode dummyA = A->Next;
  PtrToNode dummyB = B->Next;
  Polynomial C = malloc(sizeof(struct Node));
  PtrToNode dummyC = C->Next;

  while (dummyA != NULL && dummyB != NULL)
  {
    if (dummyA->exponent < dummyB->exponent)
    {
      PtrToNode tmpNode = malloc(sizeof(struct Node));
      tmpNode->coefficient = dummyA->coefficient;
      tmpNode->exponent = dummyA->exponent;
      tmpNode->Next = dummyC->Next;
      dummyC->Next = tmpNode;
      dummyC = dummyC->Next;
      dummyA = dummyA->Next;
    }
    else if (dummyA->exponent > dummyB->exponent)
    {
      PtrToNode tmpNode = malloc(sizeof(struct Node));
      tmpNode->coefficient = dummyB->coefficient;
      tmpNode->exponent = dummyB->exponent;
      tmpNode->Next = dummyC->Next;
      dummyC->Next = tmpNode;
      dummyC = dummyC->Next;
      dummyB = dummyB->Next;
    }
    else
    {
      PtrToNode tmpNode = malloc(sizeof(struct Node));
      tmpNode->coefficient = dummyB->coefficient;
      tmpNode->exponent = dummyB->exponent;
      tmpNode->Next = dummyC->Next;
      dummyC->Next = tmpNode;
      dummyC = dummyC->Next;
      dummyA = dummyA->Next;
      dummyB = dummyB->Next;
    }

    while(dummyA != NULL)
    {
      PtrToNode tmpNode = malloc(sizeof(struct Node));
      tmpNode->coefficient = dummyA->coefficient;
      tmpNode->exponent = dummyA->exponent;
      tmpNode->Next = dummyC->Next;
      dummyC->Next = tmpNode;
      dummyC = dummyC->Next;
      dummyA = dummyA->Next;
    }

    while(dummyB != NULL)
    {
      PtrToNode tmpNode = malloc(sizeof(struct Node));
      tmpNode->coefficient = dummyB->coefficient;
      tmpNode->exponent = dummyB->exponent;
      tmpNode->Next = dummyC->Next;
      dummyC->Next = tmpNode;
      dummyC = dummyC->Next;
      dummyB = dummyB->Next;
    }

    return C;
}
