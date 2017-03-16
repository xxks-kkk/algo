#include "utility.h"

long
random_at_most(long max)
{
  time_t t;

  // Intializes random number generator
  // (we want to have different random number each time,
  // without this code, random() will take default seed 1.)
  srand((unsigned) time(&t));
  
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  do
  {
    x = random();
  }

  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x/bin_size;
}

int countDigits(int number)
{
  int numDigits = 0;
  while(number != 0)
  {
    number /= 10;
    ++numDigits;
  }
  return numDigits;
}

int chunk_number(int number, int start, int end)
{
  int numDigits = countDigits(number);
  
  if (start == 0)
  {
    return number / (int)pow(10, numDigits - 1 - end);
  }
  else
  {
    int a = number / (int)pow(10, numDigits - 1 - end);
    int newLength = numDigits - (numDigits - 1 - end);
    int newPower = newLength - start;
    return a - a / (int)pow(10, newPower) * (int)pow(10, newPower) ;
  }
}

int
max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

// swap the values hold by a and b respectively
// http://www.cs.utsa.edu/~wagner/CS2213/swap/swap.html
static void
swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void
permutation(int* array, int length)
{
  // Fill the list such that a[i] = i + 1
  int i;
  for (i = 0; i < length; i++)
    array[i] = i + 1;
  // Do the swap trick
  for (i = 1; i < length; i++)
    swap(&array[i], &array[random_at_most(i)]);
}

int*
primeList(int n)
{
  int p, i, j, k, l;
  int* N = calloc(n, sizeof(int)); //each cell indicates whether the index number is marked (1) or not (0)
  j = 0; //keep track of the final result list length
  for(p = 1; p < n; p++)
  {
    while(N[p] != 0 && p < n)
      p++;
    if (p >= n)
      break;
    j++;
    for(i = p; i < n; i = i + p + 1)
    {
      if(i == p)
        N[i] = 0;
      else
        N[i] = 1;
    }
  }
  int* result = calloc(j+1, sizeof(int));
  l = 1;
  for(k = 0; k < j; k++)
  {
    result[k] = l+1;
    l++;
    while(N[l] != 0)
      l++;
  }
  result[j] = INT_MAX;
  free(N);
  return result;
}

int
nearestPrime(int n)
{
  int* array = primeList(n+10);
  int result = array[searchElement(n, array, arrayLength(array))];
  free(array);
  return result;
}

int
searchElement(int elem, int *a, int n)
{
  int low, mid, high;

  // invariant: a[lo] < elem <= a[hi]
  low = -1;
  high = n;

  while(low + 1 < high)
  {
    mid = (low + high) / 2;
    if (a[mid] == elem)
      return mid;
    else if (a[mid] < elem)
      low = mid;
    else
      high = mid;
  }
  return high; // we return the index where elem <= a[i]
}

void
printArray(int array[], int length)
{
  int i;
  for (i = 0; i < length; i++)
  {
    printf("%d, %s", array[i], (i == length-1) ? ("\n") : (""));
  }
}

void
printFile(char* filename)
{
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "can't open %s\n", filename);
    exit(1);
  }
  int c;
  while((c=getc(fp)) != EOF)
  {
    putchar(c);
  }
  printf("\n");
  fclose(fp);
}

void
fatal(char *message)
{
  char error_message[100];

  strcpy(error_message, "[!!] Fatal Error ");
  strncat(error_message, message, 83);
  perror(error_message);
  exit(-1);
}

int
arrayLength(int * array)
{
  int i;
  for(i = 0; array[i] != INT_MAX; i++);
  return i;
}

char*
get_filename_ext(char *filename)
{
  char *dot = strrchr(filename, '.'); // `strrchr` function searches for the last occurrence of a character in a string
  if (!dot || dot == filename)
  {
    return "";
  }
  return dot+1;
}
