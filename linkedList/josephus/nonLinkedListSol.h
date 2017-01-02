/* Contains the non linked List solutions to Josephus problem 
 */
typedef unsigned long long xint;
typedef long long xint2;

/* We use the cyclic shift property
 * WARNING: only applies to M = 2
 */
int cyclicShiftJosephus(int N, int M);

/* We use the general recurrence equation
 * WARNING: This routine applies to arbitrary M; we use one-index.
 */
int recurrenceJosephus(int N, int M);

/* We use the general recurrence equation
 * WARNING: This routine applies to arbitrary M; we use zero-index.
 */
int recurrenceJosephusZero(int N, int M);

/* We use an improved recurrence solution to handle large N and large M
 * find here: http://stackoverflow.com/questions/4845260/josephus-for-large-n-facebook-hacker-cup
 * TODO: this algorithm cannot use xint, will return incorrect result.
 *       cannot calculate J(10^12, 10^4)
 */
xint2 recurrenceImproved(xint2 N, xint2 M);

/* TODO: Found here: https://www.reddit.com/r/dailyprogrammer/comments/12qicm/1162012_challenge_111_difficult_the_josephus/
 * not sure how the algorithm works. Need to revisit. In addition, there is similar but more succint algorithm through the link
 * You may also want to check out: https://rosettacode.org/wiki/Josephus_problem#C
 */ 
xint josephus(xint people, xint skip);
