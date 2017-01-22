#include "queue.h"

struct QueueRecord
{
  ET Element;
  PtrToNode Next;
};

struct QueueCDT
{
  PtrToNode Front;
  PtrToNode Rear;
};

int
isEmpty(QueueADT Q)
{
  return Q->Front == Q->Rear;
}

QueueADT
createQueue()
{
  QueueADT Q = malloc(sizeof(struct QueueCDT));
  Q->Front = malloc(sizeof(struct QueueRecord));
  Q->Front->Next = NULL;
  Q->Rear = Q->Front;
  return Q;
}
  
void
disposeQueue(QueueADT Q)
{
  makeEmpty(Q);
  free(Q->Front);
  free(Q);
}

void
makeEmpty(QueueADT Q)
{
  while(!isEmpty(Q))
  {
    dequeue(Q);
  }
}
  
void
enqueue(ET elem, QueueADT Q)
{  
  PtrToNode tmpNode = malloc(sizeof(struct QueueRecord));
  tmpNode->Element = elem;
  tmpNode->Next = NULL;
  Q->Rear->Next = tmpNode;
  Q->Rear = tmpNode;
}

ET
front(QueueADT Q)
{
  return Q->Front->Next->Element;
}
  
void
dequeue(QueueADT Q)
{
  PtrToNode dummyQ;
  dummyQ = Q->Front->Next;
  Q->Front->Next = dummyQ->Next;
  // we don't want to accidentally delete Q->Rear when there is only one data node left
  if (dummyQ->Next == NULL) 
  {
    Q->Rear = Q->Front;
  }
  free(dummyQ);
}

ET
frontAndDequeue(QueueADT Q)
{
  ET tmp = Q->Front->Next->Element;
  dequeue(Q);
  return tmp;
}

QueueADT
initializeQueue(ET array[], int lengthArray)
{
  QueueADT Q = createQueue();
  int i;
  for (i = 0; i < lengthArray; i++)
  {
    enqueue(array[i], Q);
  }
  return Q;
}

void
printQueue(QueueADT Q)
{
  PtrToNode dummyQ = Q->Front->Next;
  printf("Front:");
  while(dummyQ != NULL)
  {
    printf("|%d|%s", dummyQ->Element, (dummyQ->Next == NULL) ? (""): ("->"));
    dummyQ = dummyQ->Next;
  }
  printf(":Rear\n");
}

