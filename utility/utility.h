#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <limits.h>


#ifndef BOOLEAN
#define BOOLEAN
typedef enum { false, true } bool;
#endif

/////////////////////////////////
// MATHEMATICS RELATED
////////////////////////////////

/* Assumes 0 <= max <= RAND_MAX
 * Returns in the closed interval [0, max]
 */
//from: http://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range
long random_at_most(long max);

/* count number of digits for a number 
 */
int countDigits(int number);

/* chunk a number based upon the "start" position and "end" position and return the number in between (inclusive)
 * Start position begins from "0" from the most significant bit.
 * For example: number = 123456789, 
 *              start = 0, end = 2, will give 123 in return.
 *              start = 3, end = 5, will give 456 in return.
 *              start = 6, end = 8, will give 789 in return.
 */
int chunk_number(int number, int start, int end);

/*
 * return the bigger value of two input
 */
int max(int a, int b);

/*
 * generate a permutation of the given array
 */
// The algorithm is from MAW 2.7, which references
// J. Bentley, "Programming Pearls," Communications of the ACM 30 (1987), 754-757.
void permutation(int* array, int length);

/*
 * generate a list of prime numbers that is below given integer n
 */
// Algorithm: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// Illustration: http://www.geeksforgeeks.org/sieve-of-eratosthenes/
// Another algorithm: http://www.geeksforgeeks.org/sieve-sundaram-print-primes-smaller-n/ (not used)
int* primeList(int n);

/* 
 * Find the nearest Prime greater than the given number n. 
 */
// http://www.geeksforgeeks.org/nearest-prime-less-given-number-n/
int nearestPrime(int n);

/////////////////////////////////
// MISC RELATED
////////////////////////////////

/* We perform the binary search and 
 * return the smallest index i in the sorted array such that elem <= a[i]
 * (or n if there is no such index)
 */
int searchElement(int elem, int *a, int n);

/* print array
 */
void printArray(int array[], int length);

/*
 * Print out the content reading from file 
 */
void printFile(char*);

/* A function for fatal errors
 */
void fatal(char *);

/*
 * Calculate the array Length; check INT_MAX as the end of array marker.
 */
int arrayLength(int *);

////////////////////////////////
// I/O RELATED
////////////////////////////////

/* get the file extension for the given filename
 */
char *get_filename_ext(char *filename);
