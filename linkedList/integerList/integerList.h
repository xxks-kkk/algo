/* maw 3.9 Write an arbitrary-precision integer arithmetic
 * package. 
 */

#include <stdio.h>
#include <stdlib.h>

/* We use a header node in our implementation.
 * The digits in integer, implemented in linked list, 
 * is in reverse order. The least significant digit is
 * the first data node. The most significant digit is the
 * last data node.
 */
#ifndef _INTEGER_LIST_H
#define _INTEGER_LIST_H

typedef struct Node* PtrToNode;
typedef PtrToNode integerList;

struct Node
{
  int Digit;
  PtrToNode NextDigit;
};

#endif

/* Initialize an integer. The input is 
 * an array of digits in normal order
 */
integerList initializeInteger(int digits[], int numDigits);

/* Make empty integer list
 */
integerList makeEmpty();

/* Delete the whole integerList and 
 * we keep the header node.
 */
void deleteIntegerList(integerList L);

/* Delete the whole integerList plus the header node
 */
void deleteAll(integerList L);

/* Add the digit immediately after the PtrToNode
 */
void addDigit(int digit, PtrToNode P);

/* Print the integer
 */
void printIntegerList(integerList L);

/* Add two non-negative integers
 */
integerList add(integerList A, integerList B);

/* Mutiply two non-negative integers
 */
integerList multiply(integerList A, integerList B);

/* Power
 */
integerList powIntegerList(integerList A, int power);

/* Compute the distribution of the digits 0 to 9 in 2^4000.
 */
void count(integerList A);
