/* 
 * MAW 3.23 Show how to implement three stacks in one array.
 *
 *     ==== <--- top stack
 *     | |           |
 *     ----          V
 *     | | 
 *     ==== <--- middle stack
 *     | |           |
 *     ----          V
 *     | |
 *     ----          ^
 *     | |           |
 *     ==== <--- bottom stack
 */
#ifndef _THREE_STACKS_H
#define _THREE_STACKS_H

// stack that starts at the top and grows towards the bottom
#define TOP_STACK 1
// stack that starts at the bottom and grows towards the top
#define BOTTOM_STACK 0
// stack that resides in the middle and grows towards the bottom
#define MIDDLE_STACK 2
#define EmptyToS (-1)

/* ET shorts for "ElementType" 
 */
typedef int ET; 

struct StackRecord;
typedef struct StackRecord* ThreeStacks;

/* Check if the given stack is empty
 */
int isEmpty(int, ThreeStacks);

/* Check if the given stack is full 
 */
int isFull(int, ThreeStacks);

/* Creat an array that contains two empty stacks
 */
ThreeStacks createThreeStacks(int);

/* Delete the array that contains two stacks
 */
void disposeThreeStacks(ThreeStacks);

/* Make the given stack empty
 */
void makeEmpty(int, ThreeStacks);

/* Push an element onto the given stack
 */
void push (ET, int, ThreeStacks);

/* Check the top element of the given stack
 */
ET top(int, ThreeStacks);

/* Pop the top element out of the given stack
 */
void pop(int, ThreeStacks);

/* Check the top element and pop it out of stack
 */
ET topAndPop(int, ThreeStacks);

/* Return the capacity of a ThreeStacks structure
 */
int getCapacity(ThreeStacks);

/* Return the Array of a ThreeStacks structure
 */
ET* getArray(ThreeStacks);

/* initialize an array containing two stacks from the given two array
 */
ThreeStacks initializeThreeStacks(int*, int, int*, int, int*, int, int, int);

/* print out the array with two stacks with the following format:
 * |elem|elem|<TopOfTopStack><TopOfBottomStack>|elem|elem|
 */
void printThreeStacks(ThreeStacks);

#endif


