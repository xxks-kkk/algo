#include "queue.h"

struct QueueRecord
{
  int Capacity;
  int Front;
  int Rear;
  int Size;
  ET *Array;
};

int
isEmpty(Queue Q)
{
  return Q->Size == 0;
}

int
isFull(Queue Q)
{
  return Q->Capacity == Q->Size;
}

Queue
createQueue(int maxElements)
{
  Queue Q = malloc(sizeof(struct QueueRecord));
  Q->Capacity = maxElements;
  Q->Front = Q->Capacity / 2;
  Q->Rear = Q->Front;
  Q->Size = 0;
  Q->Array = calloc(Q->Capacity, sizeof(ET));
  return Q;
}
  
void
disposeQueue(Queue Q)
{
  free(Q->Array);
  free(Q);
}

void
makeEmpty(Queue Q)
{
  while(!isEmpty(Q))
  {
    dequeue(Q);
  }
}
  
void
enqueue(ET elem, Queue Q)
{
  if (Q->Size == Q->Capacity)
  {
    fatal("Queue is full!");
  }
  // there is enough space
  if (Q->Rear < Q->Capacity - 1)
  {
    Q->Array[Q->Rear++] = elem;
    Q->Size++;
  }
  // We wrap around the array
  else if (Q->Rear == Q->Capacity - 1)
  {
    Q->Array[Q->Rear] = elem;
    Q->Size++;
    Q->Rear = 0;
  }
}

ET
front(Queue Q)
{
  return Q->Array[Q->Front];
}
  
void
dequeue(Queue Q)
{
  Q->Size--;
  Q->Array[Q->Front] = 0;
  Q->Front++;
  if (Q->Front >= Q->Capacity)
  {
    Q->Front = 0;
  }
}

ET
frontAndDequeue(Queue  Q)
{
  int res = Q->Array[Q->Front];
  dequeue(Q);
  return res;
}

Queue
initializeQueue(ET array[], int lengthArray)
{
  Queue Q = createQueue(lengthArray);
  int i;
  for (i = 0; i < lengthArray; i++)
  {
    enqueue(array[i], Q);
  }
  return Q;
}

void
printQueue(Queue Q)
{
  int i;
  for(i = 0; i < Q->Capacity; i++)
  {
    printf("|%s%d%s|",
           (i == Q->Front) ? ("Front:") : (""),
           Q->Array[i],
           (i == Q->Rear) ? (":Rear") : (""));
  }
  printf("\n");
}

