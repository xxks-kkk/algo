typedef int ET; // ET shorts for "ElementType" 

/** BASIC LIST DEFINITION **/

// we always assume there is a dummy node at the very beginning
// of the list.
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Pos;

#endif

/** BASIC LIST OPERATION **/



/** VARIOUS LIST PROBLEMS **/

/* initialize a singly linked list from a given array
 */
List initializeList(ET A[], int arrayLen);

/* print out the elements of a singly linked list 
 */
void printList(List L);

/* You are given a linked list, L, and another linked list, P,
 * containing integers sorted in acending order. The operation
 * printLots(L,P) will print the elements in L that are in positions
 * specified by P. For instance, if P = 1, 3, 4, 6, the first, third,
 * fourth, and sixth elements in L are printed.
 */
void printLots(List L, List P);
