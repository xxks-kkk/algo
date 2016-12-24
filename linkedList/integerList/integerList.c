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

void deleteIntegerList(integerList L)
{
  PtrToNode dummyL = L->NextDigit;
  L->NextDigit = NULL;

  while(dummyL != NULL)
  {
    PtrToNode tmp = dummyL->NextDigit;
    free(dummyL);
    dummyL = tmp;
  }
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

/* integerList */
/* add(integerList A, integerList B) */
/* { */
/*   PtrToNode dummyA = A->NextDigit; */
/*   PtrToNode dummyB = B->NextDigit; */
/*   integerList R = malloc(sizeof(struct Node)); */
/*   PtrToNode dummyR = R; */
/*   int digitSum = 0; */
/*   int carry = 0; */
  
/*   while (dummyA != NULL && dummyB != NULL) */
/*   { */
/*     digitSum = dummyA->Digit + dummyB->Digit + carry; */
/*     if (digitSum < 10) */
/*     { */
/*       addDigit(digitSum, dummyR); */
/*       carry = 0; */
/*     } */
/*     else */
/*     { */
/*       carry = 1; */
/*       addDigit(digitSum-10, dummyR); */
/*     } */
/*     dummyA = dummyA -> NextDigit; */
/*     dummyB = dummyB -> NextDigit; */
/*     dummyR = dummyR -> NextDigit; */
/*   } */

/*   // example case: 342 + 706 */
/*   if (carry == 1 && dummyA == NULL && dummyB == NULL) */
/*   { */
/*     addDigit(carry, dummyR); */
/*     dummyR = dummyR->NextDigit; */
/*   } */

/*   while(dummyA != NULL) */
/*   { */
/*     addDigit(dummyA->Digit + carry, dummyR); */
/*     carry = 0; */
/*     dummyA = dummyA->NextDigit; */
/*     dummyR = dummyR->NextDigit; */
/*   } */

/*   while(dummyB != NULL) */
/*   { */
/*     addDigit(dummyB->Digit + carry, dummyR); */
/*     carry = 0; */
/*     dummyB = dummyB->NextDigit; */
/*     dummyR = dummyR->NextDigit; */
/*   } */

/*   return R; */
/* } */

integerList
add(integerList A, integerList B)
{
  PtrToNode dummyA = A->NextDigit;
  PtrToNode dummyB = B->NextDigit;
  integerList R = malloc(sizeof(struct Node));
  PtrToNode dummyR = R;
  int digitSum = 0;
  int carry = 0;
  int x, y;
  
  while (dummyA != NULL || dummyB != NULL)
  {
    (dummyA != NULL) ? (x = dummyA->Digit) : (x = 0);
    (dummyB != NULL) ? (y = dummyB->Digit) : (y = 0);

    digitSum = x + y + carry;
    carry = digitSum / 10;
    addDigit(digitSum % 10, dummyR);

    if (dummyA != NULL) dummyA = dummyA -> NextDigit;
    if (dummyB != NULL) dummyB = dummyB -> NextDigit;
    dummyR = dummyR -> NextDigit;
  }

  // example case: 342 + 706
  if (carry == 1)
  {
    addDigit(carry, dummyR);
    dummyR = dummyR->NextDigit;
  }
  
  return R;
}

integerList
multiply(integerList A, integerList B)
{
  PtrToNode dummyA = A->NextDigit;
  PtrToNode dummyB = B->NextDigit;

  integerList tmpR = malloc(sizeof(struct Node));
  PtrToNode dummyTmpR = tmpR;

  integerList R = malloc(sizeof(struct Node));

  int product, carry = 0;
  int i, indent = 0;
  
  while (dummyA != NULL)
  {
    while (dummyB != NULL)
    {
      product = dummyA->Digit * dummyB->Digit + carry;
      carry = product / 10;
      addDigit(product % 10, dummyTmpR);
      dummyTmpR = dummyTmpR->NextDigit;
      dummyB = dummyB->NextDigit;
    }

    if (carry > 0)
    {
      addDigit(carry, dummyTmpR);
      dummyTmpR = dummyTmpR->NextDigit;
    }

    for(i = 0; i < indent; i++)
    {
      addDigit(0,tmpR);
    }    
    R = add(R, tmpR);
    indent ++;
    carry = 0;
    deleteIntegerList(tmpR);
    dummyTmpR = tmpR;
    dummyA = dummyA->NextDigit;
    dummyB = B->NextDigit;
  }
  
  return R;
 }
