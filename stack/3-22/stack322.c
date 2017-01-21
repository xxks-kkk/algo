#include "stack322.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

static void resizeStack(Stack);
static int isEmptyArrayMin(Stack);
static ET topArrayMin(Stack);
static void popArrayMin(Stack);
static void pushArrayMin(ET, Stack);

struct StackRecord
{
  int Capacity;
  int TopOfStack;
  int TopOfStackMin;
  ET *Array;
  ET *ArrayMin;
};

int
isEmptyArrayMin(Stack S)
{
  return S->TopOfStackMin == EmptyToS;
}

int
isEmpty(Stack S)
{
  return S->TopOfStack == EmptyToS;
}

int
isFull(Stack S)
{
  return S->TopOfStack == S->Capacity - 1;
}

Stack
createStack(int maxElements)
{
  Stack s = malloc(sizeof(struct StackRecord));
  s->Capacity = maxElements;
  s->TopOfStack = EmptyToS;
  s->TopOfStackMin = EmptyToS;
  s->Array = calloc(s->Capacity, sizeof(ET));
  s->ArrayMin = calloc(MinStackSize, sizeof(ET));
  return s;
}

void
disposeStack(Stack S)
{
  if (S != NULL)
  {
    free(S->Array);
    free(S->ArrayMin);
    free(S);
  }
}

void
makeEmpty(Stack S)
{
  S->TopOfStack = EmptyToS;
  S->TopOfStackMin = EmptyToS;
}

static void
pushArrayMin(ET elem, Stack S)
{
  S->ArrayMin[++S->TopOfStackMin] = elem;
}

void
push (ET elem, Stack S)
{
  if (isFull(S))
  {
    resizeStack(S);
  }
  if (isEmptyArrayMin(S))
  {
    pushArrayMin(elem, S);
  }
  if (elem < topArrayMin(S))
  {
    popArrayMin(S);
    pushArrayMin(elem, S);
  }
  S->Array[++S->TopOfStack] = elem;
}

static ET
topArrayMin(Stack S)
{
  if (!isEmptyArrayMin(S))
    return S->ArrayMin[S->TopOfStackMin];
  fatal("Empty stack!");
  return 0;
}

ET
top(Stack S)
{
  if (!isEmpty(S))
    return S->Array[S->TopOfStack];
  fatal("Empty stack!");
  return 0;
}

static void
popArrayMin(Stack S)
{
  S->TopOfStackMin--;
}

void
pop(Stack S)
{
  if (top(S) == topArrayMin(S))
    popArrayMin(S);
  S->TopOfStack--;
}

ET
topAndPop(Stack S)
{
  if (top(S) == topArrayMin(S))
    popArrayMin(S);
  return S->Array[S->TopOfStack--];
}

ET
findMin(Stack S)
{
  return S->ArrayMin[S->TopOfStackMin];
}

Stack
initializeStack(int array[], int length)
{
  Stack s = createStack(length);
  int i;
  for ( i = 0; i < length; i++)
  {
    push(array[i], s);
  }
  s->TopOfStack = s->Capacity - 1;
  return s;
}

void
printStack(Stack S)
{
  ET* arrayS = S->Array;
  ET* arrayMin = S->ArrayMin;
  int i;
  for (i = 0; i <= S->TopOfStack; i++)
  {
    printf("%s%d%s",
           "|",
           arrayS[i],
           (i == S->TopOfStack) ? ("| <-topOfStack") : (""));
  }
  printf("\n");
  for (i = 0; i <= S->TopOfStackMin; i++)
  {
    printf("%s%d%s",
           "|",
           arrayMin[i],
           (i == S->TopOfStackMin) ? ("| <-topOfStackMin") : (""));    
  }
  printf("\n");
}

static void
resizeStackArray(ET** array, int length)
{
  *array = realloc(*array, sizeof(ET) * length);
}

static void
resizeStack(Stack S)
{
  S->Capacity *= 2;
  resizeStackArray(&(S->Array), S->Capacity);
}
