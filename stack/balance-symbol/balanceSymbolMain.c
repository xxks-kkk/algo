#include "stack2.h"
#include "utility.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // use 'getopt'

/* 3.18 Write a program to check for balancing symbols in the following languages:
 * a. Pascal (begin/end, (), [], {})
 * b. C      (C-comments, (), []. {})
 */
void balance_symbols_pascal(char*);
void balance_symbols_c(char*);
void balance_symbols(char*);
void test_createStack();
void test_push();
void test_top();
void test_pop();

/* Usage of the program:
 * - b filename :: symbol check for the given source file
 * - s          :: basic test for the stack operations
 */
int
main(int argc, char* argv[])
{
  extern char *optarg;
  int c, err = 0;
  char *filename;
  static char usage[] = "usage: %s [-b filename] [-s]\n";

  while ((c = getopt(argc, argv, "b:s")) != -1)
  {
    switch(c)
    {
      case 'b':
        filename = optarg;
        balance_symbols(filename);
        break;
      case 's':
        printf("///////////////////////\n");
        printf("// STACK2 TEST\n");
        printf("///////////////////////\n\n");
        test_createStack();    printf("\n");
        test_push();           printf("\n"); 
        test_top();            printf("\n");
        test_pop();            printf("\n");
        break;
      case '?':
        err = 1;
        break;
    }
  }
  if (err)
  {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }
  exit(0);
} 

/* Algorithm:
 * Make an empty stack. Read characters until end of file. If the character is an opening
 * symbol, push it onto the stack. If it is a closing symbol, then if the stack is empty
 * report an error. Otherwise, pop the stack. If the symbol popped is not the corresponding
 * opening symbol, then report an error. At end of file, if the stack is not empty report an
 * error.
 */
void
balance_symbols(char* filename)
{
  char *ext = get_filename_ext(filename);
  if (!strcmp(ext,"pas"))
    balance_symbols_pascal(filename);
  if (!strcmp(ext, "c"))
    balance_symbols_c(filename);
}

/* Check for balancing symbols for Pascal
 */
void
balance_symbols_pascal(char* filename)
{
  printf("Probably implement in the near future");
}

/* Check for balancing symbols for C
 */
void
balance_symbols_c(char* filename)
{
  int MAXLINE = 2;
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "Cannot open %s\n", filename);
    exit(1);
  }
  int lineno = 1;
  int noError = 1;
  Stack s = createStack();
  char* line = malloc(MAXLINE * sizeof(char));
  int c;
  while ((c = getc(fp)) != EOF)
  {
    /* printf("character c read: "); */
    /* putc(c, stdout); */
    /* printf("\n"); */
    switch(c)
    {
      case '\n':
        lineno++;
        break;
      case '/':
        if (line[0] == '*')
        {
          line[1] = '/';
          if (isEmpty(s))
          {
            fprintf(stderr,"Extra */ in Line %d\n", lineno);
            exit(1);
          }
          if(strcmp(topSymbol(s),"/*"))
          {
            fprintf(stderr,"Missing /* symbol in Line %d\n", topLineNo(s));
            exit(1);
          }
          pop(s);
        }
        else
        {
          line[0] = c;
        }
        break;
      case '*':
        if (line[0] == '/')
        {
          line[1] = c;
          push(line, lineno, s);
          memset(line, 0, MAXLINE); // empty the char array
        }
        else
        {
          line[0] = c;
        }
        break;
      case '(':
        push("(", lineno, s);
        break;
      case '[':
        push("[", lineno, s);
        break;
      case '{':
        push("{", lineno, s);
        break;
      case ')':
        if (isEmpty(s))
        {
          fprintf(stderr,"Extra %c in Line %d \n", c, lineno);
          exit(1);
        }
        if(strcmp(topSymbol(s),"("))
        {
          fprintf(stderr,"Missing ( symbol in Line %d\n", topLineNo(s));
          exit(1);
        }
        pop(s);
        break;
      case ']':
        if (isEmpty(s))
        {
          fprintf(stderr,"Extra %c in Line %d\n", c,lineno);
          exit(1);
        }
        if(strcmp(topSymbol(s),"["))
        {
          fprintf(stderr,"Missing [ symbol in Line %d\n", topLineNo(s));
          exit(1);
        }
        pop(s);
        break;
      case '}':
        if (isEmpty(s))
        {
          fprintf(stderr,"Extra %c in Line %d\n", c, lineno);
          exit(1);
        }
        if(strcmp(topSymbol(s),"{"))
        {
          fprintf(stderr,"Missing { symbol in Line %d\n", topLineNo(s));
          exit(1);
        }
        pop(s);
        break;
    }
  }
  while (!isEmpty(s))
  {
    printf("Missing corresponding symbol of %s in Line %d\n", topSymbol(s), topLineNo(s));
    pop(s);
    noError = 0;
  }
  if (noError)
  {
    printf("All symbols are balanced! Good job!\n");
  }
  disposeStack(s);
  free(line);
}

void
test_createStack()
{
  printf("TEST: createStack\n");

  Stack s = createStack();
  push("(", 1, s);
  push(")", 20, s);
  printStack(s);
  disposeStack(s);
}

void
test_push()
{
  printf("TEST: push\n");
  Stack s = createStack();
  push("begin", 1, s);
  printStack(s);
  disposeStack(s);  
}

void
test_top()
{
  printf("TEST: tops\n");
  Stack s = createStack();
  push("begin", 1, s);
  printStack(s);
  printf("Top element symbol: %s\n", topSymbol(s));
  printf("Top element line number: %d\n", topLineNo(s));
  pop(s);
  printStack(s);  
  disposeStack(s);  
}

void
test_pop()
{
  printf("TEST: pop\n");
  Stack s = createStack();
  push("begin", 1, s);
  printStack(s);
  printf("Pop the element\n");
  pop(s);
  printStack(s);
  disposeStack(s);
}
