#include "csp.h"

struct CSPTreeNode
{
  ET Element;
  Position NextSibling;
  Position FirstChild;
};

CSPT
createNewNode(ET elem)
{
  CSPT T = malloc(sizeof(struct CSPTreeNode));
  T->Element = elem;
  T->NextSibling = T->FirstChild = NULL;
  return T;
}

CSPT
makeEmpty(CSPT T)
{
  /* if (T != NULL) */
  /* { */
  /*   makeEmpty(T->Left); */
  /*   makeEmpty(T->Right); */
  /*   free(T); */
  /* } */
  return NULL;
}

////**** We implement a simple Queue here ****////
struct QueueRecord
{
  Position Element;
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
makeEmptyQueue(QueueADT Q)
{
  while(!isEmpty(Q))
  {
    dequeue(Q);
  }
}

void
disposeQueue(QueueADT Q)
{
  makeEmptyQueue(Q);
  free(Q->Front);
  free(Q);
}
  
void
enqueue(Position elem, QueueADT Q)
{  
  PtrToNode tmpNode = malloc(sizeof(struct QueueRecord));
  tmpNode->Element = elem;
  tmpNode->Next = NULL;
  Q->Rear->Next = tmpNode;
  Q->Rear = tmpNode;
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

Position
frontAndDequeue(QueueADT Q)
{
  Position tmp = Q->Front->Next->Element;
  dequeue(Q);
  return tmp;
}
////**** End of queue implementation ****////

Position
find(ET elem, CSPT T)
{
  if (T == NULL)
    return NULL;
  Position tmp, tmp2;
  QueueADT Q = createQueue();
  enqueue(T, Q); // put the root on queue
  while (!isEmpty(Q))
  {
    tmp = frontAndDequeue(Q);
    if (tmp->Element == elem)
      return tmp;
    else
    {
      tmp2 = tmp->FirstChild;
      while(tmp2 != NULL)
      {
        enqueue(tmp2, Q);
        tmp2 = tmp2->NextSibling;
      }
    }
  }
  disposeQueue(Q);
  return NULL;
}

// When use insert, we need to specify an anchorElem 
// where we want to create a new node
// that holds elem relative to it. In addition,
// we need to specify the relation of the node
// that contains elem relative to the anchor node through
// isChild
CSPT
insert(ET elem, CSPT T, ET anchorElem, int isChild)
{
  CSPT newNode;
  Position tmp;
  Position anchorNode = find(anchorElem, T);
  if (T == NULL)
  {
    T = createNewNode(elem);
  }  
  else if (!find(elem, T))
  {
    if(isChild)
    {
      newNode = createNewNode(elem);      
      tmp = anchorNode->FirstChild;
      if(tmp == NULL)
      {
        anchorNode->FirstChild = newNode;
      }
      else
      {
        while(tmp->NextSibling != NULL)
        {
          tmp = tmp->NextSibling;
        }
        tmp->NextSibling = newNode;
      }
    }
    else
    {
      newNode = createNewNode(elem);      
      tmp = anchorNode;
      while(tmp->NextSibling != NULL)
        tmp = tmp->NextSibling;
      tmp->NextSibling = newNode;      
    }
  }
  return T;
}
  
CSPT
delete(ET elem, CSPT T)
{
  return T;
}
  
ET
retrieve(Position T)
{
  if (T != NULL)
    return T->Element;
  return 0;
}

static void
cspt_print_dot_aux(CSPT T, FILE* stream)
{
  Position tmp;
  if (T != NULL)
  {
    tmp = T->FirstChild;
    while(tmp != NULL)
    {
      fprintf(stream, "%c->%c;\n", T->Element, tmp->Element);
      cspt_print_dot_aux(tmp, stream);          
      tmp = tmp->NextSibling;
    }
  }
}

void
cspt_print_dot(CSPT T, FILE* stream)
{
  fprintf(stream, "digraph CSPT{\n");
  cspt_print_dot_aux(T, stream);
  fprintf(stream,"}\n");
}

// swap the left child and right child of node T
// again, we assume each node has only two children: left and right
void
treeSwap(CSPT T)
{
  Position tmp = T->FirstChild;
  T->FirstChild = T->FirstChild->NextSibling;
  T->FirstChild->NextSibling = tmp;
}

// We assume each node has only two children: left and right
// O(N)
int
isomorphic(CSPT T1, CSPT T2)
{
  if (T1 == NULL && T2 == NULL)
    return 0;
  if (T1->Element == T2->Element)
    return 0;
  if ((T1 != NULL && T2 == NULL) ||
      (T1 == NULL && T2 != NULL))
    return 1;
  if ((T1->FirstChild->Element == T2->FirstChild->Element) &&
      (T1->FirstChild->NextSibling->Element == T2->FirstChild->NextSibling->Element))
    return 0;
  if ((T1->FirstChild->Element != T2->FirstChild->Element) ||
      (T1->FirstChild->NextSibling->Element != T2->FirstChild->NextSibling->Element))
    treeSwap(T1);
  return isomorphic(T1->FirstChild, T2->FirstChild) && isomorphic(T1->FirstChild->NextSibling, T2->FirstChild->NextSibling);
}
  
