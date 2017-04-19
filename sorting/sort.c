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
