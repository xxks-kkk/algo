#include "postfix2.h"

/* The algorithm used is called "Shunting-yard" algorithm
 * see more: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
 * Operator precedence assumed (from highest to lowest):
 *  () 
 *  ^
 *  *, /
 *  +, -
 */
void
infixTopostfix(char* filename)
{
  int maxElements = 20;
  Stack s = createStack(maxElements);
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "can't open %s\n", filename);
    exit(1);
  }
  int c;
  char* tmp = malloc(sizeof(char));
  while((c=getc(fp)) != EOF)
  {
    /* printf("character c read: "); */
    /* putc(c, stdout); */
    /* printf("\n"); */
    if(isalpha(c) || isdigit(c))
    {
      putchar(c);
    }
    else
    {
      switch(c)
      {
        case ' ':
          break;
        case '-':
        case '+':
          while(!isEmpty(s) && strcmp(top(s),"("))
          {
            putchar(topAndPop(s)[0]);
          }
          tmp[0] = c;
          push(tmp, s);
          break;
        case '/':
        case '*':
          if (isEmpty(s) ||
              !strcmp(top(s),"+") ||
              !strcmp(top(s),"-") ||
              !strcmp(top(s),"(") 
              )
          {
            tmp[0] = c;
            push(tmp, s);
          }
          else
          {
            while (strcmp(top(s),"(") && !isEmpty(s))
            {
              putchar(topAndPop(s)[0]);
            }
            tmp[0] = c;
            push(tmp, s);
          }
          break;
        case '(':
          tmp[0] = c;
          push(tmp, s);    
          break;
        case ')':
          while(strcmp(top(s),"("))
          {
            putchar(topAndPop(s)[0]);
          }
          pop(s); //remove '('
          break;
        case '^':
          tmp[0] = c;
          push(tmp, s); // by assumption, there is no operator has higher precedence than '^', so we push directly
          break;
        default:
          fprintf(stderr, "Invalid operator %c in expression\n", c);
          exit(1);
      }
    }
    //printStack(s);
    //printf("TopOfStack: %d\n", getTopOfStack(s));
  }
  while(!isEmpty(s))
  {
    putchar(topAndPop(s)[0]);
  }
  disposeStack(s);
  free(tmp);
  printf("\n");
}

void
postfixToinfix(char* filename)
{
  int maxElements = 20;
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "can't open %s\n", filename);
    exit(1);
  }
  int c, lenA, lenB;
  char* tmp = malloc(sizeof(char));
  char* tmp2;
  char* a;
  char* b;
  Stack s = createStack(maxElements);
  while((c=getc(fp)) != EOF)
  {
    /* printf("character c read: "); */
    /* putc(c, stdout); */
    /* printf("\n"); */
    if(isdigit(c) || isalpha(c))
    {
      tmp[0] = c;
      push(tmp, s);
    }
    else
    {
      switch(c)
      {
        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
          a = topAndPop(s);
          lenA = strlen(a);
          //printf("a: %s with length: %d\n", a, lenA);
          b = topAndPop(s);
          lenB = strlen(b);
          //printf("b: %s with length: %d\n", b, lenB);
          tmp2 = malloc((lenA+lenB+3)*sizeof(char)); // 1 for c, 2 for '(' and ')', so total is 3
          strcpy(tmp2, "(");
          strcat(tmp2, b);
          //printf("tmp2: %s\n", tmp2);
          tmp[0] = c;
          strcat(tmp2,tmp);
          //printf("tmp2: %s\n", tmp2);
          strcat(tmp2,a);
          //printf("tmp2: %s\n", tmp2);
          strcat(tmp2, ")");
          push(tmp2, s);
          free(tmp2);
          break;
        case ' ':
          break;
        default:
          fprintf(stderr, "Invalid operator in the file\n");
          exit(1);
      }
    }
    //printStack(s);
  }
  printf(topAndPop(s));
  disposeStack(s);
  fclose(fp);
}
