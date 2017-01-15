/* We use array implementation of stacks
 */
#ifndef _STACK_H
#define _STACK_H

/* ET shorts for "ElementType" 
 */
typedef char* ET; 

struct StackRecord;
typedef struct StackRecord* Stack;

/* Check if stack is empty
 */
int isEmpty(Stack S);

/* Check if stack is full
 */
int isFull(Stack S);

/* Creat a stack
 */
Stack createStack(int maxElements);

/* Delete the stack
 */
void disposeStack(Stack S);

/* Make the stack empty
 */
void makeEmpty(Stack S);

/* Push an element on the stack
 */
void push (ET elem, Stack S);

/* Check the top element of the stack
 */
ET top(Stack S);

/* Pop the top element out of the stack
 */
void pop(Stack S);

/* Check the top element and pop it out of stack
 */
ET topAndPop(Stack S);

#endif

/* print out the stack with the following format:
 * |elem|elem|elem| <-top
 */
void printStack(Stack S);

int getTopOfStack(Stack S);
