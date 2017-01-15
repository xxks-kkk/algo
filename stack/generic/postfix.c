#include "postfix.h"

/* 
 * Algorithm: when a number is seen, it is pushed
 * onto the stack; when an operator is seen, the 
 * operator is applied to the two numbers (symbols)
 * that are popped from the stack, and the result
 * is pushed onto the stack.
 *
 * Limitation: can handle postfix expression
 * with integer only.
 */
ET
evaluate_postfix(char* filename)
{
  int maxElements = 20;
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "can't open %s\n", filename);
    exit(1);
  }
  int c;
  int res, a, b;
  Stack s = createStack(maxElements);
  while((c=getc(fp)) != EOF)
  {
    /* printf("character c read: "); */
    /* putc(c, stdout); */
    /* printf("\n"); */
    if(isdigit(c))
    {
      push(c-'0', s);
    }
    else
    {
      switch(c)
      {
        case '/':
          a = topAndPop(s);
          b = topAndPop(s);
          push(b/a, s);
          break;
        case '*':
          a = topAndPop(s);
          b = topAndPop(s);
          push(b*a, s);          
          break;
        case '+':
          a = topAndPop(s);
          b = topAndPop(s);
          push(b+a, s);          
          break;
        case '-':
          a = topAndPop(s);
          b = topAndPop(s);
          push(b-a, s);          
          break;
        case ' ':
          break;
        default:
          fprintf(stderr, "Invalid operator in the file\n");
          exit(1);
      }
    }
  }
  res = topAndPop(s);
  disposeStack(s);
  fclose(fp);
  return res;
}
