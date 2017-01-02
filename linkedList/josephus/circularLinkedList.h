/* We use double circularly linked list to solve Josephus problem 
 */

typedef int ET; // ET shorts for "ElementType" 

/** BASIC LIST DEFINITION **/

// we always assume there is a dummy node at the very beginning
// of the list. In the double circluarly linked list, the dummy node's
// previous pointer points to the last data node. The last data node's
// next pointer points to the dummy node.
#ifndef _CIRCULAR_LINKED_LIST_H
#define _CIRCULAR_LINKED_LIST_H

struct Node;  
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Pos;

#endif

/**---- BASIC LIST OPERATION ----**/

/* Make an empty list
 */
List makeEmpty();

/* Insert (after legal position P)
 */
void insert(ET elem, List L, Pos position);

/* Delete node
 */
void deleteNode(Pos position);

/**---- VARIOUS LIST PROBLEMS ----**/

/* initialize a double circulaly linked list from a given array
 */
List initializeList(ET A[], int arrayLen);

/* print out the elements of a double circularly linked list.
 * The structure looks like: <-> ET <-> ET <-> ET <->
 */
void printList(List L);

/* 3.10 Write a program to solve the Josephus problem for general 
 * values of M and N.  
 */
ET circularDoubleLinkedListJosephus(ET N, ET M); 
