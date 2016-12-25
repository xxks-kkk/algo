#include "integerList.h"

integerList
initializeInteger(int digits[], int numDigits)
{
  int i;
  integerList R = makeEmpty();
  PtrToNode P = R;
  
  for(i=numDigits-1 ; i >= 0; i--)
  {
    addDigit(digits[i], P);
    P = P->NextDigit;
  }

  return R;
}

integerList
makeEmpty()
{
  integerList R = malloc(sizeof(struct Node));
  R->NextDigit = NULL; // super important step
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

void deleteAll(integerList L)
{
  deleteIntegerList(L);
  free(L);
}

void
addDigit(int digit, PtrToNode P)
{
  PtrToNode tmp = makeEmpty();
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
  integerList R = makeEmpty();
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

  integerList tmpR = makeEmpty();
  PtrToNode dummyTmpR = tmpR;

  integerList R = makeEmpty();
  
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

    integerList tmp = R; // prevent memory leak
    R = add(R, tmpR);
    deleteAll(tmp);

    indent ++;
    carry = 0;
    deleteIntegerList(tmpR);
    dummyTmpR = tmpR;
    dummyA = dummyA->NextDigit;
    dummyB = B->NextDigit;
  }

  deleteAll(tmpR);
  return R;
 }

integerList powIntegerList(integerList A, int power)
{
  if (power == 0)
  {
    integerList R = makeEmpty();
    addDigit(1, R);
    return R;
  }
  if (power == 1)
  {
    return A;
  }
  if (power % 2 == 0)
  {
    return powIntegerList(multiply(A, A), power/2);
  }
  else
  {
    return multiply(powIntegerList(multiply(A, A), power/2), A);
  }
}

void count(integerList A)
{
  PtrToNode dummyA = A->NextDigit;
  int distribution[10] = {0};

  while (dummyA != NULL)
  {
    switch(dummyA->Digit)
    {
      case 0:
        distribution[0]++;
        break;
      case 1:
        distribution[1]++;
        break;
      case 2:
        distribution[2]++;
        break;
      case 3:
        distribution[3]++;
        break;
      case 4:
        distribution[4]++;
        break;
      case 5:
        distribution[5]++;
        break;
      case 6:
        distribution[6]++;
        break;
      case 7:
        distribution[7]++;
        break;
      case 8:
        distribution[8]++;
        break;
      case 9:
        distribution[9]++;
        break;
    }
    dummyA = dummyA->NextDigit;
  }

  int i;
  for(i = 0; i < 10; i++)
  {
    printf("The number of %d digit: %d\n", i, distribution[i]);
  }
}
  
