#include "dict.h"

static Position find(int key, HashTable H);
static HashTable rehash(HashTable H);


enum KindOfEntry {Legitimate, Empty, Deleted};

struct data
{
  int Key;
  int Value;
};

struct HashEntry
{
  ET Element;
  enum KindOfEntry Info;
};

struct HashTbl
{
  int TableSize;
  int numElements; // keep track of number of elements we store
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
  H->numElements = 0;
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
  if (T->TheCells[tmp].Element.Key == currentPos &&
      T->TheCells[tmp].Info == Legitimate)
    return 1;
  else
    return 0;
}

static Position
find(int key,
     HashTable H)
{
  Position currentPos;
  int collisionNum;
  collisionNum = 0;

  // We use another hash table to prevent the infinite loop
  // when certain key cannot be inserted into the target hash table.
  HashTable T = initializeTable(H->TableSize); 
  currentPos = hash(key, H->TableSize);

  while(H->TheCells[currentPos].Info != Empty &&
        H->TheCells[currentPos].Element.Key != key)
  {
    currentPos += 2 * ++collisionNum - 1; // quadratic hashing
    if(currentPos >= H->TableSize)
      currentPos -= H->TableSize;
    if(isTried(currentPos, T))
    {
      printf("%d cannot be inserted into the table\n", key);
      break;
    }
    T = put(currentPos, 0, T); // we don't really care what the corresponding value is
  }
  return currentPos;
}

HashTable
put(int key,
    int value,
    HashTable H)
{
  Position currentPos;

  currentPos = find(key, H);
  H->TheCells[currentPos].Element.Key = key;
  H->TheCells[currentPos].Element.Value = value;
  H->TheCells[currentPos].Info = Legitimate;
  H->numElements++;
  if(0.1 * H->numElements / H->TableSize >= 0.5) // avoid integer division
    H = rehash(H);
  return H;
}
  
int
retrieve(int key,
         HashTable H)
{
  Position pos = find(key, H);
  return H->TheCells[pos].Element.Value;
}

static HashTable
rehash(HashTable H)
{
  HashTable newH = initializeTable(nearestPrime(2*H->TableSize));
  int i;
  for(i = 0; i < H->TableSize; i++)
  {
    put(H->TheCells[i].Element.Key, H->TheCells[i].Element.Value, newH);
  }
  DestroyTable(H);
  return newH;
}

void
printDictionary(HashTable H)
{
  int i;
  for(i = 0; i < H->TableSize; i++)
  {
    if(H->TheCells[i].Info == Legitimate)
      printf("%d|<%d,%d>\n", i,  H->TheCells[i].Element.Key, H->TheCells[i].Element.Value);
    else
      printf("%d|\n", i);
  }
}

