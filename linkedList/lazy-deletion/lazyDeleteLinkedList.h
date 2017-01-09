/* ET shorts for "ElementType" 
 */
typedef int ET; 

/* 3.17 An alternative to the deletion strategy
 * we have given is to use lazy deletion. To delete
 * an element, we merely mark it deleted (using an extra bit field).
 * The number of deleted and nondeleted elements in the list
 * is kept as part of the data structure. If there are as many
 * deleted element as nondeleted elements, we traverse the entire list,
 * performing the standard deletion algorithm on all marked nodes.
 * 
 * ADVANTAGE    : It takes less time to mark a node as deleted than to change pointers. In addition, it is simpler to code,
 *                and there is a possible savings if deleted keys are subsequently reinserted (in the same place).
 * DISADVANTAGE : Once a node has been "lazily deleted" it still needs to be traversed in a search for another node.
 *                Also, you then use up a lump amount of time to delete all the "lazily deleted elements". Use more space,
 *                because each cell needs an extra bit (which is typically a byte), and unused cells are not freed.
 */

////////////////////////////
// BASIC LIST DEFINITION 
////////////////////////////

/* we always assume there is a dummy node at the very beginning
 * of the list.
 */
#ifndef _LAZY_DELETE_LINKED_LIST_H
#define _LAZY_DELETE_LINKED_LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Pos;

#endif

//////////////////////////
// BASIC LIST OPERATION 
//////////////////////////

/* Make empty linked list
 */
List makeEmpty();

int IsEmpty(List L);

int IsLast(Pos P, List L);

Pos Find(ET elem, List L);

/* Find the node contains "elem" in the given list and delete it.
 */
void deleteNode(ET elem, List L);

Pos FindPrevious(ET elem, List L);

/* Insert (after legal position P)
 */
void insert(ET elem, List L, Pos position);

/* Delete all the nodes with deleted == true
 */
void deleteMarkedNodes(List L);

/* We don't delete the header node. 
 * In other words, the empty list contains a header node.
 */
void deleteList(List L);

/* delete all: the list and the header node
 */
void deleteAll(List L);

Pos Header(List L);

Pos First(List L);

Pos Advance(Pos P);

/* Give the element of the specified node 
 */
ET getElement(Pos loc);

/* Get the number of nodes
 */
int getNumNodes();

/* Set the number of nodes
 */
void setNumNodes(int N);

/* Get the number of nodes marked as deleted
 */
int getNumDeleted();

/* Set the number of nodes marked as deleted
 */
void setNumDeleted(int N);

/* print out the elements of a singly linked list 
 */
void printList(List L);

/* initialize a singly linked list from a given array
 */
List initializeList(ET A[], int arrayLen);
