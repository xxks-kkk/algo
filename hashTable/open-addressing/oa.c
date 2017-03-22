#include "oa.h"

enum KindOfEntry {Legitimate, Empty, Deleted};

struct HashEntry
{
  int Element;
  enum KindOfEntry Info;
};

struct HashTbl
{
  int TableSize;
  Cell *TheCells;
};

HashTable
initializeTable(int TableSize)
{
  HashTable H;
  int i;

  H = malloc(sizeof(struct HashTbl));
  assert(H);

  H->TableSize = TableSize;
  H->TheCells = malloc(sizeof(Cell) * H->TableSize);
  assert(H->TheCells);

  for(i = 0; i < H->TableSize; i++)
    H->TheCells[i].Info = Empty;

  return H;
}

void
DestroyTable(HashTable H)
{
  free(H->TheCells);
  free(H);
}

static Position
hash(int key,
     int TableSize)
{
  return key % TableSize;
}

/* indicates whehter the currentPos is already tried before or not 
 */
static int
isTried(Position currentPos, HashTable T)
{
  Position tmp = find(currentPos, T);
  if (T->TheCells[tmp].Element == currentPos &&
      T->TheCells[tmp].Info == Legitimate)
    return 1;
  else
    return 0;
}

Position
find(int key,
     HashTable H)
{
  Position currentPos;
#ifdef QUADH
  int collisionNum;
  collisionNum = 0;
#endif

  // We use another hash table to prevent the infinite loop
  // when certain key cannot be inserted into the target hash table.
  HashTable T = initializeTable(H->TableSize); 
  currentPos = hash(key, H->TableSize);

  while(H->TheCells[currentPos].Info != Empty &&
        H->TheCells[currentPos].Element != key)
  {
#ifdef LINEARH
    currentPos += 1; // linear hashing
#elif QUADH
    currentPos += 2 * ++collisionNum - 1; // quadratic hashing
#elif DH
    currentPos += 7 - hash(key, 7); // double hashing    
#endif    
    if(currentPos >= H->TableSize)
      currentPos -= H->TableSize;
    if(isTried(currentPos, T))
    {
      printf("%d cannot be inserted into the table\n", key);
      break;
    }
    insert(currentPos, T);
  }
  return currentPos;
}

void
insert(int key,
       HashTable H)
{
  Position currentPos;

  currentPos = find(key, H);
  if (H->TheCells[currentPos].Info != Legitimate)
  {
    H->TheCells[currentPos].Element = key;
    H->TheCells[currentPos].Info = Legitimate;
  }
}
  
int
retrieve(Position P, HashTable H)
{
  return H->TheCells[P].Element;
}

HashTable
rehash(HashTable H)
{
  HashTable newH = initializeTable(nearestPrime(2*H->TableSize));
  int i;
  for(i = 0; i < H->TableSize; i++)
  {
    insert(H->TheCells[i].Element, newH);
  }
  DestroyTable(H);
  return newH;
}

void
printHashTable(HashTable H)
{
  int i;
  for(i = 0; i < H->TableSize; i++)
  {
    if(H->TheCells[i].Info == Legitimate)
      printf("%d|%d\n", i,  H->TheCells[i].Element);
    else
      printf("%d|\n", i);
  }
}

HashTable
initializeTableFromArray(int* array,
                         int arrayLength,
                         int TableSize)
{
  HashTable H = initializeTable(TableSize);
  int i;
  for(i = 0; i < arrayLength; i++)
    insert(array[i], H);
  return H;
}

// We implement the hash function
// described in MAW p.151
static int
characterHash(char* pattern, int patternLen)
{
  int power = 0;
  int hashVal = 0;
  for(power = 0; power < patternLen; power++)
    hashVal += pow(32, power) * (pattern[power] - '\0');
  return hashVal;
}

// hashing the pattern string, obtaining a hash value
// Hp, and comparing this value with the hash value formed
// from A1A2...Ak, A2A3...Ak+1,A3A4...Ak+2, and so on
// until AN-k+1AN-k+2...AN. If we have a match of hash values,
// we compare the strings character by character to verify the match.
// We return the position (in A) if the string actually do match, and
// we continue in the unlikely event that the match is false.
int
findPattern(char* pattern, char* input)
{
  int k = strlen(pattern);  
  int patternHashValue = characterHash(pattern, k);
  int tmpHashValue;
  int n = strlen(input);
  char tmp[k+1];
  int i;
  for(i = 0; i + k <= n; i++)
  {
    strncpy(tmp, input+i, k);
    tmp[k] = '\0';
    tmpHashValue = characterHash(tmp, k);
    if (tmpHashValue == patternHashValue && !strcmp(tmp, pattern))
      return i;
  }
  return -1;
}
