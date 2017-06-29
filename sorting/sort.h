#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utility.h"

#define Cutoff (3) // Used in quickSort, Qselect

void shellSort(int A[], int N);
void bubbleSort(int A[], int N);
void selectionSort(int A[], int N);
void insertionSort(int A[], int N);
void heapSort(int A[], int N);
void mergeSort(int A[], int N);
void quickSort(int A[], int N);

/* Select the kth smallest element from the given array.
 * Place the kth smallest element in the kth position. 
 * Because arrays start at 0, this will be index k-1.
 * NOTE: the original ordering will be destroyed.
 */
void Qselect(int A[], int k, int Left, int Right);

/*
 * 7.14 How would you implement mergesort without 
 * using recursion?
 */
void mergeSortNonRecursive(int A[], int N);
