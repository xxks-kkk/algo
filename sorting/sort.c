#include "sort.h"

// Implement using Shell's increments
void
shellSort(int A[], int N)
{
  int i, j, increment, tmp;

  for (increment = N/2; increment > 0; increment /= 2)
  {
    printf("Increment: %d\n", increment);
    for(i = increment; i < N; i++)
    {
      printf("i: %d\n", i);
      tmp = A[i];
      printf("tmp: %d\n", tmp);
      for(j = i; j >= increment; j -= increment)
      {
        printf("j: %d\n", j);
        if (tmp < A[j-increment])
          A[j] = A[j-increment];
        else
          break;
      }
      A[j] = tmp;
      printf("%d-sort:", increment);
      printArray(A, N);
    }
    printf("after %d-sort:", increment);
    printArray(A, N);
  }
}

void
bubbleSort(int A[], int N)
{
  int i,j;
  for(i = 0; i < N; i++)         // n passes thru the array
  {
    printf("i: %d\n", i);
    for(j=1; j < (N-i); j++)     // From start to the end of unsorted part
    {
      printf("j: %d\n", j);
      if (A[j-1] > A[j])
        printf("A[j-1]: %d\t A[j]: %d\n", A[j-1], A[j]);
        swap(&A[j-1], &A[j]);    // if adjacent items out of order, swap
    }
  }
}

void
selectionSort(int A[], int N)
{
  int i, j, min;
  j = min = i = 0;
  for(; i < N-1; i++)
  {
    for(j = i; j < N; j++)
      if(A[j] < A[min])
        min = j;
    swap(&A[min], &A[i]);
  } 
}

void
insertionSort(int A[], int N)
{
  int j, P;
  int tmp;
  for(P = 1; P < N; P++)
  {
    tmp = A[P];
    for(j = P; j > 0 && tmp < A[j-1]; j--)
      A[j] = A[j-1];
    A[j] = tmp;
  }
}
