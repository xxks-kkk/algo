/* We use a linked list implementation. 
 * The top of the stack is the first data node.
 */
#ifndef _STACK_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

/* Check if stack is empty
 */
int isEmpty(Stack S);

/* Creat a stack
 */
Stack createStack(void);

/* Delete the stack
 */
void disposeStack(Stack S);

/* Make the stack empty
 */
void makeEmpty(Stack S);

/* Push an element on the stack
 */
void push (char* symbol, int lineNo, Stack S);

/* Check the top element's symbol of the stack
 */
char* topSymbol(Stack S);

/* Check the top element's line number of the stack
 */
int topLineNo(Stack S);

/* Pop the top element out of the stack
 */
void pop(Stack S);

#endif

/* print out the stack with the following format:
 * |elem|elem|elem| <-top
 */
void printStack(Stack S);
