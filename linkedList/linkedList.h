typedef int ET; // ET shorts for "ElementType" 

// we always assume there is a dummy node at the very beginning
// of the list.
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Pos;

#endif

/* initialize a singly linked list from a given array
 */
List initializeList(ET A[], int arrayLen);

/* print out the elements of a singly linked list 
 */
void printList(List L);
