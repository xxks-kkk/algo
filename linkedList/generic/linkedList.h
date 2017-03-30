/* ET shorts for "ElementType" 
 */
typedef int ET; 

////////////////////////////
// BASIC LIST DEFINITION 
////////////////////////////

/* we always assume there is a dummy node at the very beginning
 * of the list.
 */
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Pos;

#endif

//////////////////////////
// BASIC LIST OPERATION 
//////////////////////////

/* Insert (after legal position P)
 */
void insert(ET elem, List L, Pos position);

/* Make empty linked list
 */
List makeEmpty();

/* We don't delete the header node. 
 * In other words, the empty list contains a header node.
 */
void deleteList(List L);

/* delete all: the list and the header node
 */
void deleteAll(List L);

/* Give the element of the specified node 
 */
ET getElement(Pos loc);

/* Find the node contains "elem" in the given list and delete it.
 */
void deleteNode(ET elem, List L);

/* 3.15.b self-adjusting lists insert. All the insertions
 * are performed at the front of the list.
 */
void selfAdjustInsert(ET elem, List L);

/* 3.15.b self-adjusting lists find. When an element is accessed by a Find,
 * it is moved to the front of the list without changing the relative order of the
 * other items. Return the pointer to the element.
 */
Pos selfAdjustFind(ET elem, List L);

///////////////////////////
// VARIOUS LIST PROBLEMS 
///////////////////////////

/* initialize a singly linked list from a given array
 */
List initializeList(ET A[], int arrayLen);

/* 3.1 print out the elements of a singly linked list 
 */
void printList(List L);

/* print out the elements of a singly linked list 
 * in reverse order
 */
void printListReverse(List L);

/* 3.2 You are given a linked list, L, and another linked list, P,
 * containing integers sorted in acending order. The operation
 * printLots(L,P) will print the elements in L that are in positions
 * specified by P. For instance, if P = 1, 3, 4, 6, the first, third,
 * fourth, and sixth elements in L are printed.
 */
void printLots(List L, List P);

/* 3.3.a Swap the node that contains the first appearance of the ET elem 
 * with the following node. If node contains first appearance of the ET elem
 * is the last node, then print "Cannot swap because of the elem is the last node"
 */
void swapLL(List L, ET elem);

/* 3.4 Given two sorted lists, L and P, write a procedure to compute the
 * intersection of two lists using only the basic list operations.
 */
List intersectionSortedLists(List L, List P);

/* 3.5 Given two sorted lists, L and P, write a procedure to compute L1 union L2
 * using only the basic list operations.
 */
List unionSortedLists(List L, List P);

/* 3.11 write a program to find a particular element in a singly linked list. "find" is nonrecursive.
 * "findRecursive" is recursive.
 */
Pos find(ET target, List L);
Pos findRecursive(ET target, List L);

/* 3.12.a write a nonrecursive procedure to reverse a singly linked list in O(N) time.
 */
List reverseList(List L);

/* 3.12.b write a nonrecursive procedure to reverse a singly linked list in O(N) time
 * using constant extra space.
 */
void reverseListIterative(List L);
void reverseListRecursive(List L);

/* 3.13 You have to sort an array of student records by social security number. Write a program
 * to do this, using radix sort with 1000 buckets and three passes.
 */
int* radixSort(int studentRecords[], int N);
