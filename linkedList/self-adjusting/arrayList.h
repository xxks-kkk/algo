#include <stdio.h>

/* 3.15.a Write an array implementation
 * of self-adjusting lists. A self-adjusting
 * list is like a regular list, except that
 * all insertions are performed at the front,
 * and when an element is accessed by a Find,
 * it is moved to the front of the list without
 * changing the relative order of the other items.
 */

/* Make an empty list with length N
 */
int* makeEmptyList(int N);

/* insert an element elem
 */
void insert(int elem, int list[]);

/* fina an element elem, and return
 * the position of the first appearance of 
 * the target.
 */
int find(int elem, int list[]);
