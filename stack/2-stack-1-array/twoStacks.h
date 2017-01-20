/* 
 * MAW 3.21 Write routines to implement two stacks using only
 * one array. Your stack routines should not declare an overflow
 * unless every slot in the array is used. 
 *
 *     ==== <--- top stack
 *     | |           |
 *     ----          V
 *     | |
 *     ----          ^
 *     | |           |
 *     ==== <--- bottom stack
 */
#ifndef _TWO_STACKS_H
#define _TWO_STACKS_H

// stack that starts at the top and grows towards the bottom
#define TOP_STACK 1
// stack that starts at the bottom and grows towards the top
#define BOTTOM_STACK 0
#define EmptyToS (-1)

/* ET shorts for "ElementType" 
 */
typedef int ET; 

struct StackRecord;
typedef struct StackRecord* TwoStacks;

/* Check if the given stack is empty
 */
int isEmpty(int, TwoStacks);

/* Check if the given stack is full 
 */
int isFull(int, TwoStacks);

/* Creat an array that contains two empty stacks
 */
TwoStacks createTwoStacks(int);

/* Delete the array that contains two stacks
 */
void disposeTwoStacks(TwoStacks);

/* Make the given stack empty
 */
void makeEmpty(int, TwoStacks);

/* Push an element onto the given stack
 */
void push (ET, int, TwoStacks);

/* Check the top element of the given stack
 */
ET top(int, TwoStacks);

/* Pop the top element out of the given stack
 */
void pop(int, TwoStacks);

/* Check the top element and pop it out of stack
 */
ET topAndPop(int, TwoStacks);

/* Return the capacity of a TwoStacks structure
 */
int getCapacity(TwoStacks);

/* Return the Array of a TwoStacks structure
 */
ET* getArray(TwoStacks);

/* initialize an array containing two stacks from the given two array
 */
TwoStacks initializeTwoStacks(int*, int, int*, int, int);

/* print out the array with two stacks with the following format:
 * |elem|elem|<TopOfTopStack><TopOfBottomStack>|elem|elem|
 */
void printTwoStacks(TwoStacks);

#endif


