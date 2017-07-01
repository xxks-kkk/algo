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
  //int count = 0;
  for(P = 1; P < N; P++)
  {
    //printf("P:%d\n", P);
    tmp = A[P];
    for(j = P; j > 0 && tmp < A[j-1]; j--)
    {
      A[j] = A[j-1];
      //count++;
    }
    A[j] = tmp;
    //printf("count: %d\n", count);
    //count = 0;
  }
}

#define LeftChild(i) (2*(i) + 1)

void
PercDown(int A[], int i, int N)
{
  int child;
  int tmp;

  for(tmp = A[i]; LeftChild(i) < N; i = child)
  {
    child = LeftChild(i);
    if(child != N-1 && A[child + 1] > A[child])
      child++;
    if(tmp < A[child])
      A[i] = A[child];
    else
      break;
  }
  A[i] = tmp;
}

void
heapSort(int A[], int N)
{
  int i;

  for(i = N/2; i >= 0;  i--) // BuildHeap
    PercDown(A, i, N);
  for(i = N-1; i > 0; i--)
  {
    swap(&A[0], &A[i]); // DeleteMax and move it to the end of array
    PercDown(A, 0, i);
  }
}


void
merge(int A[],
      int tmpArray[],
      int lpos, // start of left half
      int rpos, // start of right half
      int rightEnd)
{
  int i, leftEnd, numElements, tmpPos;

  leftEnd = rpos - 1;
  tmpPos = lpos;
  numElements = rightEnd - lpos + 1;

  // main loop
  while(lpos <= leftEnd && rpos <= rightEnd)
    if(A[lpos] <= A[rpos])
      tmpArray[tmpPos++] = A[lpos++];
    else
      tmpArray[tmpPos++] = A[rpos++];

  while(lpos <= leftEnd) // Copy rest of first half
    tmpArray[tmpPos++] = A[lpos++];
  while(rpos <= rightEnd) // Copy rest of second half
    tmpArray[tmpPos++] = A[rpos++];

  for(i = 0; i < numElements; i++, rightEnd--) // copy tmpArray back
    A[rightEnd] = tmpArray[rightEnd];
}

void
msort(int A[],
      int tmpArray[],
      int left,
      int right)
{
  int center;

  if(left < right)
  {
    center = (left + right)/2;
    msort(A, tmpArray, left, center);
    msort(A, tmpArray, center+1, right);
    merge(A, tmpArray, left, center+1, right);
  }
}

void
mergeSort(int A[], int N)
{
  int *tmpArray;
  tmpArray = malloc(N*sizeof(int));
  assert(tmpArray);
  msort(A, tmpArray, 0, N-1);
  free(tmpArray);
}

int
median3(int A[], int Left, int Right)
{
  int Center = (Left + Right) / 2;

  if (A[Left] > A[Center])
    swap(&A[Left], &A[Center]);
  if (A[Left] > A[Right])
    swap(&A[Left], &A[Right]);
  if (A[Center] > A[Right])
    swap(&A[Center], &A[Right]);

  // Invariant: A[Left] <= A[Center] <= A[Right]
  swap(&A[Center], &A[Right-1]); // Hide pivot
  return A[Right-1];             // Return pivot
}

void
Qsort(int A[], int Left, int Right)
{
  int i, j;
  int Pivot;

  if (Left + Cutoff <= Right)
  {
    Pivot = median3(A, Left, Right);
    i = Left;
    j = Right - 1;
    for(;;)
    {
      while( A[++i] < Pivot){}
      while( A[--j] > Pivot){}
      if (i < j)
        swap(&A[i], &A[j]);
      else
        break;
    }
    swap( &A[i], &A[Right-1]); // Restore pivot
    
    Qsort(A, Left, i-1);
    Qsort(A, i+1, Right);
  }
  else // Do an insertion sort on the subarray
    insertionSort(A+Left, Right-Left+1);
}

void
quickSort(int A[], int N)
{
  Qsort(A, 0, N-1);
}

void
Qselect(int A[],
        int k,
        int Left,
        int Right)
{
  int i, j;
  int Pivot;

  if(Left + Cutoff <= Right)
  {
    Pivot = median3(A, Left, Right);
    i = Left;
    j = Right - 1;
    for(;;)
    {
      while(A[++i] < Pivot){}
      while(A[--j] > Pivot){}
      if(i < j)
        swap(&A[i], &A[j]);
      else
        break;
    }
    swap(&A[i], &A[Right-1]); // Restore pivot

    if (k <= i)
      Qselect(A, k, Left, i-1);
    else if (k > i+1)
      Qselect(A, k, i+1, Right);
  }
  else // Do an insertion sort on the subarray
    insertionSort(A+Left, Right-Left+1);
}

void
mergeSortNonRecursive(int A[], int N)
{
  int *tmpArray;
  int subListSize, part1Start, part2Start, part2End;

  tmpArray = malloc(sizeof(int) * N);
  for(subListSize = 1; subListSize < N; subListSize *= 2)
  {
    part1Start = 0;
    while(part1Start + subListSize < N - 1)
    {
      part2Start = part1Start + subListSize;
      part2End = min(N - 1, part2Start + subListSize - 1);

      /* printf("part1Start: %d\n", part1Start); */
      /* printf("part2Start: %d\n", part2Start); */
      /* printf("part2End: %d\n", part2End); */

      merge(A, tmpArray, part1Start, part2Start, part2End);
      part1Start = part2End + 1;
    }
  }
}
