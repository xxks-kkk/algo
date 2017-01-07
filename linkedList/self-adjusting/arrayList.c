#include "arrayList.h"

int*
arrayTranslate(int B[], int length)
{
  int* res = calloc(length, sizeof(int));
  int i;
  for (i = 0; i < length; i++)
  {
    *(res+i) = B[i];
  }
  return res;
}

void
printArrayList(int* A, int length)
{
  int i;
  for (i = 0; i < length; i++)
  {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

void
arrayInsert(int elem, int** list, int length)
{
  *list = realloc(*list, sizeof(int) * (length+1));
  int i;
  for (i = 0; i < length; i++)
  {
    (*list)[length - i] = (*list)[length-i-1];
  }
  *((*list)) = elem;
}

int
arrayFind(int elem, int* list, int length)
{
  int i, j;
  for( i = 0; i < length; i++)
  {
    if (list[i] == elem)
    {
      for( j = 0; j < i; j++)
      {
        list[i - j] = list[i - j -1];
      }
      list[0] = elem;
      return 0;
    }
  }
  return -1;
}
