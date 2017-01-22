#include "deque.h"

struct DequeRecord
{
  int Capacity;
  int Front;
  int Rear;
  int Size;
  ET *Array;
};

int
isEmpty(Deque D)
{
  return D->Size == 0;
}

int
isFull(Deque D)
{
  return D->Capacity == D->Size;
}

Deque
createDeque(int maxElements)
{
  Deque D = malloc(sizeof(struct DequeRecord));
  D->Capacity = maxElements;
  D->Front = D->Capacity / 2;
  D->Rear = D->Front;
  D->Size = 0;
  D->Array = calloc(D->Capacity, sizeof(ET));
  return D;
}
  
void
disposeDeque(Deque D)
{
  free(D->Array);
  free(D);
}

void
makeEmpty(Deque D)
{
  while(!isEmpty(D))
  {
    pop(D);
  }
}
  
void
inject(ET elem, Deque D)
{
  if (D->Size == D->Capacity)
  {
    fatal("Deque is full!");
  }
  // there is enough space
  if (D->Rear < D->Capacity - 1)
  {
    D->Array[D->Rear++] = elem;
    D->Size++;
  }
  // We wrap around the array
  else if (D->Rear == D->Capacity - 1)
  {
    D->Array[D->Rear] = elem;
    D->Size++;
    D->Rear = 0;
  }
}

ET
pop(Deque D)
{
  int res = D->Array[D->Front];
  D->Size--;
  D->Array[D->Front] = 0;
  D->Front++;
  if (D->Front >= D->Capacity)
  {
    D->Front = 0;
  }
  return res;
}

void
push(ET elem, Deque D)
{
  if(D->Size == D->Capacity)
  {
    fatal("Deque is full!");
  }
  // if there is enough space
  if (D->Front > 0)
  {
    D->Array[D->Front--] = elem;
    D->Size++;
  }
  // wrap around
  else if (D->Front == 0)
  {
    D->Array[D->Front] = elem;    
    D->Front = D->Capacity - 1;
    D->Size++;
  }
}

ET
eject(Deque D)
{
  int res = D->Array[D->Rear];
  D->Size--;
  D->Array[D->Rear] = 0;
  D->Rear--;
  if (D->Rear <= 0)
  {
    D->Rear = D->Capacity - 1;
  }
  return res;
}

Deque
initializeDeque(ET array[], int lengthArray)
{
  Deque D = createDeque(lengthArray);
  int i;
  for (i = 0; i < lengthArray; i++)
  {
    inject(array[i], D);
  }
  return D;
}

void
printDeque(Deque D)
{
  int i;
  for(i = 0; i < D->Capacity; i++)
  {
    printf("|%s%d%s|",
           (i == D->Front) ? ("Front:") : (""),
           D->Array[i],
           (i == D->Rear) ? (":Rear") : (""));
  }
  printf("\n");
}

