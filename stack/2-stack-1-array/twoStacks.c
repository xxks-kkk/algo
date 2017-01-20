#include "twoStacks.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

struct StackRecord
{
  int Capacity;
  int TopOfTopStack;
  int TopOfBottomStack;
  ET  *Array;
};
  
int
isEmpty(int stackNo, TwoStacks s)
{
  if (stackNo == TOP_STACK)
  {
    return s->TopOfTopStack == EmptyToS;
  }
  else
  {
    return s->TopOfBottomStack == s->Capacity;
  }
}

int
isFull(int stackNo, TwoStacks s)
{
  if (stackNo == TOP_STACK)
  {
    return s->TopOfTopStack == s->TopOfBottomStack - 1;
  }
  else
  {
    return s->TopOfBottomStack == s->TopOfTopStack + 1;
  }
}

TwoStacks
createTwoStacks(int maxElements)
{
  TwoStacks s = malloc(sizeof(struct StackRecord));
  s->Capacity = maxElements;
  s->TopOfTopStack = EmptyToS;
  s->TopOfBottomStack = s->Capacity;
  s->Array = calloc(s->Capacity, sizeof(ET));
  return s;
}

void
disposeTwoStacks(TwoStacks s)
{
  free(s->Array);
  free(s);
}

void
makeEmpty(int stackNo, TwoStacks s)
{
  if (stackNo == TOP_STACK)
  {
    s->TopOfTopStack = EmptyToS;
  }
  else
  {
    s->TopOfBottomStack = s->Capacity;
  }
}

void
push (ET elem, int stackNo, TwoStacks s)
{
  if (stackNo == TOP_STACK)
  {
    if (s->TopOfTopStack + 1 < s->TopOfBottomStack)
    {
      s->Array[++s->TopOfTopStack] = elem;
    }
    else
    {
      fatal("Stack is full!");
    }
  }
  else
  {
    if (s->TopOfBottomStack - 1 > s->TopOfTopStack)
    {
      s->Array[--s->TopOfBottomStack] = elem;
    }
    else
    {
      fatal("Stack is full!");
    }
  }
}

ET
top(int stackNo, TwoStacks s)
{
  if (stackNo == TOP_STACK)
  {
    return s->Array[s->TopOfTopStack];
  }
  else
  {
    return s->Array[s->TopOfBottomStack];
  }
}
  
void
pop(int stackNo, TwoStacks s)
{
  if(stackNo == TOP_STACK && !isEmpty(stackNo, s))
  {
    s->TopOfTopStack--;
  }
  else if (stackNo == BOTTOM_STACK && !isEmpty(stackNo, s))
  {
    s->TopOfBottomStack--;
  }
  else
  {
    fatal("Error in pop!");
  }
}

ET
topAndPop(int stackNo, TwoStacks s)
{
  if (stackNo == TOP_STACK && !isEmpty(stackNo, s))
  {
    return s->Array[s->TopOfTopStack--];
  }
  else if (stackNo == BOTTOM_STACK && !isEmpty(stackNo, s))
  {
    return s->Array[s->TopOfBottomStack--];
  }
  else
  {
    fatal("Error in topAndPop!");
  }
}

int
getCapacity(TwoStacks s)
{
  return s->Capacity;
}

ET*
getArray(TwoStacks s)
{
  return s->Array;
}

TwoStacks
initializeTwoStacks(int *arrayTop,
                    int lengthTop,
                    int *arrayBottom,
                    int lengthBottom,
                    int distanceBetweenTwoStacks)
{
  TwoStacks s = createTwoStacks(lengthTop + lengthBottom + distanceBetweenTwoStacks);
  int i;
  for(i = 0; i < lengthTop; i++)
  {
    push(arrayTop[i], TOP_STACK, s);
  }
  for(i = 0; i < lengthBottom; i++)
  {
    push(arrayBottom[i], BOTTOM_STACK, s);
  }
  return s;
}

void
printTwoStacks(TwoStacks s)
{
  ET* arrayS = getArray(s);
  int i;
  for(i = 0; i < s->Capacity; i++)
  {
    printf("|%d", arrayS[i]);
    if (i ==  s->TopOfTopStack && i+1 != s->TopOfBottomStack)
    {
      printf("|<TopOfTopStack>");
    }
    else if (i == s->TopOfTopStack && i + 1 == s->TopOfBottomStack)
    {
      printf("|<TopOfTopStack-TopOfBottomStack>");
    }
    else if (i + 1 == s->TopOfBottomStack)
    {
      printf("|<TopOfBottomStack>");
    }
    else if (i + 1 == s->Capacity)
    {
      printf("|");
    }
  }  
  printf("\n");
}
