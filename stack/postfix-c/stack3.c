#include "stack3.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EmptyToS (-1)
#define MinStackSize (5)

static void resizeStack(Stack);

struct StackRecord
{
  int Capacity;
  int TopOfStack;
  ET *Array;
};
  
/* Check if Stack is empty
 */
int isEmpty(Stack S)
{
  return S->TopOfStack == EmptyToS;
}

/* Check if Stack is full
 */
int isFull(Stack S)
{
  return S->TopOfStack == S->Capacity - 1;
}

/* Creat a Stack
 */
Stack createStack(int maxElements)
{
  Stack s = malloc(sizeof(struct StackRecord));
  s->Capacity = maxElements;
  s->TopOfStack = EmptyToS;
  s->Array = calloc(s->Capacity, sizeof(ET));
  return s;
}

/* Delete the Stack
 */
void
disposeStack(Stack S)
{
  if (S != NULL)
  {
    free(S->Array);
    free(S);
  }
}

/* Make the Stack empty
 */
void
makeEmpty(Stack S)
{
  S->TopOfStack = EmptyToS;
}

/* Push an element on the Stack
 */
void
push (ET elem, Stack S)
{
  if (isFull(S))
  {
    resizeStack(S);
  }
  char* dupSymbol = malloc(strlen(elem) * sizeof(char));
  strcpy(dupSymbol, elem);
  S->Array[++S->TopOfStack] = dupSymbol;
}

/* Check the top element of the Stack
 */
ET
top(Stack S)
{
  if (!isEmpty(S))
  {
    return S->Array[S->TopOfStack];
  }
  return "";
}
  
/* Pop the top element out of the Stack
 */
void
pop(Stack S)
{
  S->TopOfStack--;
}

/* Check the top element and pop it out of Stack
 */
ET
topAndPop(Stack S)
{
  return S->Array[S->TopOfStack--];
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

void
printStack(Stack S)
{
  ET* arrayS = S->Array;
  int i;
  for (i = 0; i <= S->TopOfStack; i++)
  {
    printf("%s%s%s",
           "|",
           arrayS[i],
           (i == S->TopOfStack) ? ("| <-top") : (""));
  }
  printf("\n");
}

int
getTopOfStack(Stack S)
{
  return S->TopOfStack;
}
