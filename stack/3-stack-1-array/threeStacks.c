#include "threeStacks.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

struct StackRecord
{
  int Capacity;
  int TopOfTopStack;
  int TopOfBottomStack;
  int TopOfMiddleStack;
  int BottomOfMiddleStack;
  ET  *Array;
};

/*
 * relocate the middle stack when collision of the middle stack with
 * the either of the rest stacks happens. 
 * Return -1 indicates the middle stack cannot relocate.
 * Return 0 indicates relocation successfully.
 */
static int relocateMiddleStack(ThreeStacks);

int
isEmpty(int stackNo, ThreeStacks s)
{
  if (stackNo == TOP_STACK)
  {
    return s->TopOfTopStack == EmptyToS;
  }
  else if (stackNo == BOTTOM_STACK)
  {
    return s->TopOfBottomStack == s->Capacity;
  }
  else
  {
    return s->TopOfMiddleStack == s->BottomOfMiddleStack;
  }
}

int
isFull(int stackNo, ThreeStacks s)
{
  if (stackNo == TOP_STACK)
  {
    return s->TopOfTopStack == s->BottomOfMiddleStack - 1;
  }
  else if (stackNo == BOTTOM_STACK)
  {
    return s->TopOfBottomStack == s->TopOfMiddleStack + 1;
  }
  else
  {
    return s->TopOfMiddleStack == s->TopOfBottomStack - 1; 
  }
}

ThreeStacks
createThreeStacks(int maxElements)
{
  ThreeStacks s = malloc(sizeof(struct StackRecord));
  s->Capacity = maxElements;
  s->TopOfTopStack = EmptyToS;
  s->TopOfBottomStack = s->Capacity;
  s->BottomOfMiddleStack = s->Capacity / 2;
  s->TopOfMiddleStack = s->BottomOfMiddleStack - 1;
  s->Array = calloc(s->Capacity, sizeof(ET));
  return s;
}

void
disposeThreeStacks(ThreeStacks s)
{
  free(s->Array);
  free(s);
}

void
makeEmpty(int stackNo, ThreeStacks s)
{
  if (stackNo == TOP_STACK)
  {
    s->TopOfTopStack = EmptyToS;
  }
  else if (stackNo == BOTTOM_STACK)
  {
    s->TopOfBottomStack = s->Capacity;
  }
  else
  {
    s->TopOfMiddleStack = s->BottomOfMiddleStack;
  }
}

static int
relocateMiddleStack(ThreeStacks s)
{
  /* printf("TopOfMiddleStack: %d\n", s->TopOfMiddleStack); */
  /* printf("BottomOfMiddleStack: %d\n", s->BottomOfMiddleStack); */
  int numElementsMiddleStack = s->TopOfMiddleStack - s->BottomOfMiddleStack + 1;
  /* printf("numElementsMiddleStack: %d\n", numElementsMiddleStack); */
  int spaceBetweenTopOfTopStackAndTopOfBottomStack = s->TopOfBottomStack - s->TopOfTopStack - 1;
  /* printf("spaceBetweenTopOfTopStackAndTopOfBottomStack: %d\n", spaceBetweenTopOfTopStackAndTopOfBottomStack); */
  if (numElementsMiddleStack >= spaceBetweenTopOfTopStackAndTopOfBottomStack)
    return -1; // we don't have enough space to relocate middle stack;
  else
  {
    // the strategy we use is to move the middle stack so that its center is halfway
    // between the tops of the other two stacks.
    int centerOfMiddleStack = s->BottomOfMiddleStack + numElementsMiddleStack / 2;
    /* printf("centerOfMiddleStack: %d\n", centerOfMiddleStack); */
    int newCenterOfMiddleStack = s->TopOfTopStack + (spaceBetweenTopOfTopStackAndTopOfBottomStack + 1) / 2;
    /* printf("newCenterOfMiddleStack: %d\n", newCenterOfMiddleStack); */
    int numShifts = newCenterOfMiddleStack - centerOfMiddleStack;
    /* printf("numShifts: %d\n", numShifts); */

    // We save the elements of middle stack in an array in order to prevent element
    // overriding when we shift elements of middle stack left/right.
    int i;
    ET *arrayTmp = calloc(numElementsMiddleStack, sizeof(ET));
    for (i = 0; i < numElementsMiddleStack; i++)
    {
      arrayTmp[i] = s->Array[i + s->BottomOfMiddleStack];
    }
    /* printArray(arrayTmp, numElementsMiddleStack); */

    s->BottomOfMiddleStack = s->BottomOfMiddleStack + numShifts;
    /* printf("BottomOfMiddleStack: %d\n", s->BottomOfMiddleStack); */
    s->TopOfMiddleStack = s->BottomOfMiddleStack - 1;
    for (i = 0; i < numElementsMiddleStack; i++)
    {
      push(arrayTmp[i], MIDDLE_STACK, s);
    }
    /* printThreeStacks(s); */
    free(arrayTmp);
    return 0;
  }
}

void
push (ET elem, int stackNo, ThreeStacks s)
{
  if (stackNo == TOP_STACK)
  {
    if (s->TopOfTopStack + 1 < s->BottomOfMiddleStack || relocateMiddleStack(s) == 0)
      s->Array[++s->TopOfTopStack] = elem;
    else
      fatal("Stack is full!");
  }
  else if (stackNo == BOTTOM_STACK)
  {
    if (s->TopOfBottomStack - 1 > s->TopOfMiddleStack || relocateMiddleStack(s) == 0)
      s->Array[--s->TopOfBottomStack] = elem;
    else
      fatal("Stack is full!");
  }
  else
  {
    if (s->TopOfMiddleStack + 1 < s->TopOfBottomStack || relocateMiddleStack(s) == 0)
      s->Array[++s->TopOfMiddleStack] = elem;
    else
      fatal("Stack is full!");
  }
}

ET
top(int stackNo, ThreeStacks s)
{
  if (stackNo == TOP_STACK)
  {
    return s->Array[s->TopOfTopStack];
  }
  else if (stackNo == BOTTOM_STACK)
  {
    return s->Array[s->TopOfBottomStack];
  }
  else
  {
    return s->Array[s->TopOfMiddleStack];
  }
}
  
void
pop(int stackNo, ThreeStacks s)
{
  if(stackNo == TOP_STACK && !isEmpty(stackNo, s))
  {
    s->TopOfTopStack--;
  }
  else if (stackNo == BOTTOM_STACK && !isEmpty(stackNo, s))
  {
    s->TopOfBottomStack--;
  }
  else if (stackNo == MIDDLE_STACK && !isEmpty(stackNo, s))
  {
    s->TopOfMiddleStack--;
  }
  else
  {
    fatal("Error in pop!");
  }
}

ET
topAndPop(int stackNo, ThreeStacks s)
{
  if (stackNo == TOP_STACK && !isEmpty(stackNo, s))
  {
    return s->Array[s->TopOfTopStack--];
  }
  else if (stackNo == BOTTOM_STACK && !isEmpty(stackNo, s))
  {
    return s->Array[s->TopOfBottomStack--];
  }
  else if (stackNo == MIDDLE_STACK && !isEmpty(stackNo, s))
  {
    return s->Array[s->TopOfMiddleStack--];
  }
  else
  {
    fatal("Error in topAndPop!");
  }
  return 0;
}

int
getCapacity(ThreeStacks s)
{
  return s->Capacity;
}

ET*
getArray(ThreeStacks s)
{
  return s->Array;
}

ThreeStacks
initializeThreeStacks(int *arrayTop,
                      int lengthTop,
                      int *arrayMiddle,
                      int lengthMiddle,
                      int *arrayBottom,
                      int lengthBottom,  
                      int distanceBetweenTopNMiddle,
                      int distanceBetweenMiddleNBottom)
{
  ThreeStacks s = createThreeStacks(lengthTop + lengthBottom + lengthMiddle + distanceBetweenTopNMiddle + distanceBetweenMiddleNBottom);
  /* printThreeStacks(s); */
  int i;
  for(i = 0; i < lengthTop; i++)
  {
    push(arrayTop[i], TOP_STACK, s);
  }
  /* printThreeStacks(s); */
  for(i = 0; i < lengthBottom; i++)
  {
    push(arrayBottom[i], BOTTOM_STACK, s);
  }
  /* printThreeStacks(s); */
  for(i = 0; i < lengthMiddle; i++)
  {
    push(arrayMiddle[i], MIDDLE_STACK, s);
    /* printThreeStacks(s); */
  }
  return s;
}

void
printThreeStacks(ThreeStacks s)
{
  ET* arrayS = getArray(s);
  int i;
  for(i = 0; i < s->Capacity; i++)
  {
    printf("|%d", arrayS[i]);
    if (i ==  s->TopOfTopStack && i+1 != s->BottomOfMiddleStack)
    {
      printf("|<TopOfTopStack>");
    }
    else if (i == s->TopOfTopStack && i+1 == s->BottomOfMiddleStack)
    {
      printf("|<TopOfTopStack-BottomOfMiddleStack>");
    }
    else if (i + 1 == s->BottomOfMiddleStack)
    {
      printf("|<BottomOfMiddleStack>");
    }
    else if (i == s->TopOfMiddleStack && !isEmpty(MIDDLE_STACK, s)  && i + 1 != s->TopOfBottomStack)
    {
      printf("|<TopOfMiddleStack>");
    }
    else if (i == s->TopOfMiddleStack && i + 1 == s->TopOfBottomStack)
    {
      printf("|<TopOfMiddleStack-TopOfBottomStack>");
    }
    else if (i + 1 == s->TopOfBottomStack && !isEmpty(BOTTOM_STACK, s))
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
