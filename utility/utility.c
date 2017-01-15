#include "utility.h"
#include <string.h>

long
random_at_most(long max)
{
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
