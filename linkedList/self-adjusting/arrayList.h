#include <stdio.h>
#include <stdlib.h>

/* 3.15.a Write an array implementation
 * of self-adjusting lists. A self-adjusting
 * list is like a regular list, except that
 * all insertions are performed at the front,
 * and when an element is accessed by a Find,
 * it is moved to the front of the list without
 * changing the relative order of the other items.
 */

/* Stack array translates to the heap array
 */
int* arrayTranslate(int B[], int length);

/* Print the list 
 */
void printArrayList(int* A, int length);

/* insert an element elem at front
 */
void arrayInsert(int  elem, int** list, int length);

/* find the first appreance of the elem and return 0 if find. 
 * -1 if not found.
 */
int arrayFind(int elem, int* list, int length);
