#include "assert.h"
#include "nonLinkedListSol.h"
#include "strings.h"
#include <stdio.h>

#ifndef fls
/*
 * Find Last Set bit. This is exactly opposite of "ffs".
 * The reason I include this routine here is that not every system
 * has "fls" by default.
 */
int
fls(int mask)
{
  int bit;
  if (mask == 0)
  {
    return (0);
  }
  for (bit = 1; mask != 1; bit++)
  {
    mask = (unsigned int) mask >> 1;
  }
  return (bit);
}
#endif

int
cyclicShiftJosephus(int N, int M)
{
  assert(M == 2);
  return 2 * (N - (1 << ((fls(N)) - 1))) + 1;
}

int
recurrenceJosephus(int N, int M)
{
  if (N == 1)
  {
    return 1;
  }
  return (M - 1 + recurrenceJosephus(N-1, M)) % N + 1;
}

static int
recurrenceJosephusZeroHelper(int N, int M)
{
  if (N == 1)
  {
    return 0;
  }
  return (M + recurrenceJosephusZeroHelper(N-1, M)) % N;
}

int
recurrenceJosephusZero(int N, int M)
{
  return recurrenceJosephusZeroHelper(N, M) + 1;
}

static xint2
recurrenceImprovedHelper(xint2 N, xint2 M)
{
  if (N == 1LL)
  {
    return 0LL;
  }
  if (M == 1LL)
  {
    return N-1LL;
  }
  if (M > N)
  {
    return (M + recurrenceImprovedHelper(N-1LL, M)) % N;
  }
  xint2 cnt = N / M;
  xint2 res = recurrenceImprovedHelper(N - cnt, M);
  res -= N % M;
  if (res < 0LL)
  {
    res += N;
  }
  else
  {
    res += res/(M - 1LL);
  }
  return res;
}

xint2
recurrenceImproved(xint2 N, xint2 M)
{
  return recurrenceImprovedHelper(N, M) + 1;
}

xint josephus(xint people, xint skip )
{
  if( people <= 1 ) return 1;
  //people = 0 is actually invalid, and people = 1 is trivial

  //Imagine an array that can contain two values, "not josephus" and "josephus"
  //rather than actually have the array, we will only save the index
  //that contains josephus and the size of the array
  //We are going to kill the first person in line, and then "rotate" the array
  //to set our sights on the next guy
  //only we are doing it backwards, starting with 2 people,
  //Josephus is smartly not the first in line.

  //josephus' position, 0 based position
  xint result = 1;

  //number of people remaining, including josephus
  xint n=2;

  if( skip <= 1 )
  {
    //simple case, separated out to avoid a divide by zero
    result = people-1;
  }
  else while (n<people)
  {
    //I'm going to kill the first person in line
    //At the end, I will account for the first person killed in the skip'th in line

    //How many times can I skip before I have to do the modulo
    //to keep josephus within the bounds of the line?
    xint iterations = (n-1-result)/(skip-1)+1;
    if( n+iterations > people )
    {
      iterations = people - n;
    }
    //skip people and set sights on the next victim
    //by "rotating" the "array"
    result += skip*iterations;
    n+=iterations;
    //don't let josephus past the end of the line
    while( result >= n )
    {
      result-=(n-1) ;
    }
  }
  //person 0 (the next to be killed) is really in position "skip"
  return ( ( result + skip - 1  ) % people ) + 1;
}
