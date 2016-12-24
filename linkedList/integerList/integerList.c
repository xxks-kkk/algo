#include "integerList.h"

integerList
initializeInteger(int digits[], int numDigits)
{
  int i;
  integerList R = malloc(sizeof(struct Node));
  PtrToNode P = R;
  
  for(i=numDigits-1 ; i >= 0; i--)
  {
    addDigit(digits[i], P);
    P = P->NextDigit;
  }

  return R;
}

void
addDigit(int digit, PtrToNode P)
{
  PtrToNode tmp = malloc(sizeof(struct Node));
  tmp->Digit = digit;
  tmp->NextDigit = P->NextDigit;
  P->NextDigit = tmp;
}

static void
printIntegerListHelper(integerList L)
{
  if(L == NULL)
  {
    return;
  }
  printIntegerListHelper(L->NextDigit);
  printf("%d", L->Digit);
}

void
printIntegerList(integerList L)
{
  printIntegerListHelper(L->NextDigit);
}

integerList
add(integerList A, integerList B)
{
  PtrToNode dummyA = A->NextDigit;
  PtrToNode dummyB = B->NextDigit;
  integerList R = malloc(sizeof(struct Node));
  PtrToNode dummyR = R;
  int digitSum = 0;
  int carry = 0;
  
  while (dummyA != NULL && dummyB != NULL)
  {
    digitSum = dummyA->Digit + dummyB->Digit + carry;
    if (digitSum < 10)
    {
      addDigit(digitSum, dummyR);
      carry = 0;
    }
    else
    {
      carry = 1;
      addDigit(digitSum-10, dummyR);
    }
    dummyA = dummyA -> NextDigit;
    dummyB = dummyB -> NextDigit;
    dummyR = dummyR -> NextDigit;
  }

  // example case: 342 + 706
  if (carry == 1 && dummyA == NULL && dummyB == NULL)
  {
    addDigit(carry, dummyR);
    dummyR = dummyR->NextDigit;
  }

  while(dummyA != NULL)
  {
    addDigit(dummyA->Digit + carry, dummyR);
    carry = 0;
    dummyA = dummyA->NextDigit;
    dummyR = dummyR->NextDigit;
  }

  while(dummyB != NULL)
  {
    addDigit(dummyB->Digit + carry, dummyR);
    carry = 0;
    dummyB = dummyB->NextDigit;
    dummyR = dummyR->NextDigit;
  }

  return R;
}
