#include "postfix2.h"
#include "stack3.h"
#include "utility.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // use 'getopt'

int main(int argc, char** argv)
{
  extern char *optarg;
  int c, err = 0;
  char *filename;
  static char usage[] = "usage: %s [-b filename]\n";

  while ((c = getopt(argc, argv, "b:c:")) != -1)
  {
    switch(c)
    {
      case 'b':
        /* post2infix1:
         * infix expression: a+b*c+(d*e+f)*g
         * postfix expression: abc*+de*f+g*+
         * post2infix2:
         * infix expression: (a+b)/c*d-e
         * postfix expression: ab+c/d*e-
         * post2infix3:
         * infix expression: 2^3^2
         * postfix expression: 232^^
         */
        filename = optarg;
        printf("postfix expression: ");
        printFile(filename);
        printf("infix expression: ");
        postfixToinfix(filename); 
        break;
      case 'c':
       /* expr1:
        * infix expression: a+b*c+(d*e+f)*g
        * postfix expression: abc*+de*f+g*+
        * expr2:
        * infix expression: (a+b)/c*d-e
        * postfix expression: ab+c/d*e-
        * expr3:
        * infix expression: 2^3^2
        * postfix expression: 232^^
        */
        filename = optarg;
        printf("infix expression: ");
        printFile(filename);
        printf("postfix expression: ");
        infixTopostfix(filename); 
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
