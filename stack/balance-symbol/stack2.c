#include "stack2.h"
#include "utility.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char* Symbol;
  int  LineNo;
  PtrToNode Next;
};

int
isEmpty(Stack S)
{
  return S->Next == NULL;
}

Stack
createStack()
{
  PtrToNode tmp = malloc(sizeof(struct Node));
  tmp->Next = NULL;
  return tmp;
}

void
disposeStack(Stack S)
{
  makeEmpty(S);
  free(S);
}

void
makeEmpty(Stack S)
{
  while(!isEmpty(S))
  {
    pop(S);
  }
}

void
push (char* symbol, int lineNo, Stack S)
{
  PtrToNode tmp = malloc(sizeof(struct Node));
  char* dupSymbol = malloc(strlen(symbol) * sizeof(char));
  strcpy(dupSymbol, symbol);
  tmp->Symbol = dupSymbol;
  tmp->LineNo = lineNo;
  tmp->Next = S->Next;
  S->Next = tmp;
}

char*
topSymbol(Stack S)
{
  return S->Next->Symbol;
}

int
topLineNo(Stack S)
{
  return S->Next->LineNo;
}

void
pop(Stack S)
{
  PtrToNode tmp = S->Next;
  S->Next = tmp->Next;
  free(tmp);
}

static void
printStackHelper(Stack S)
{
  if (S == NULL)
    return;
  else
    printStackHelper(S->Next);
    printf("[ '%s' %d %s",
           S->Symbol,
           S->LineNo,
           "]");
}
  
void
printStack(Stack S)
{
  PtrToNode tmp = S->Next;
  printStackHelper(tmp);
  printf("<-top");
  printf("\n");  
}

