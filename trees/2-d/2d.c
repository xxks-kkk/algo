#include "2d.h"

// WARNING: DON'T CHANGE THE NUMKEYS VALUE
#define NUMKEYS (2)      // Number of keys in a 2-d tree node

struct
TdTreeNode
{
  char* Keys[NUMKEYS];
  Position Child[NUMKEYS];
  int Level; // which level the node is on: even or odd?                       
};

void
makeEmpty(TdTree T)
{
  int i;
  if(T != NULL)
  {
    for(i=0; i < NUMKEYS; i++)
      makeEmpty(T->Child[i]);
    free(T);
  }
}

static TdTree
insertionInternal(char elem[], TdTree T, int level)
{
  char elemDup[30];
  strcpy(elemDup, elem); //strtok directly alter elem but we want to keep them intact when we do recursive call
  char* pch1; char* pch2;
  pch1 = strtok(elemDup, " ");
  pch2 = strtok(NULL, " ");  
  if (T == NULL)
  {
    T = malloc(sizeof(*T));
    T->Keys[0] = strtok(elem, " ");
    T->Keys[1] = strtok(NULL, " ");
    T->Child[0] = T->Child[1] = NULL;
    T->Level = ++level;
  }
  else if(T->Level % 2 != 0) // odd levels
  {
    if (strcmp(pch2, T->Keys[1]) < 0) // we insert into the left subtree
      T->Child[0] = insertionInternal(elem, T->Child[0], T->Level);
    else if (strcmp(pch2, T->Keys[1]) > 0) // we insert into the right subtree
      T->Child[1] = insertionInternal(elem, T->Child[1], T->Level);
  }
  else // even levels
  {
    if (strcmp(pch1, T->Keys[0]) < 0) // we insert into the left subtree
      T->Child[0] = insertionInternal(elem, T->Child[0], T->Level);
    else if (strcmp(pch1, T->Keys[0]) > 0) // we insert into the right subtree
      T->Child[1] = insertionInternal(elem, T->Child[1], T->Level);
  }
  return T;
}

TdTree
insertion(char elem[], TdTree T)
{
  T = insertionInternal(elem, T, -1);
  return T;
}

void
tdprintRange(char* low1, char* high1, char* low2, char* high2, TdTree T)
{
  if(T != NULL)
  {
    if(T->Level % 2 == 0) // even levels
    {
      if(strcmp(low1, T->Keys[0]) <= 0)
        tdprintRange(low1, high1, low2, high2, T->Child[0]);
      if(strcmp(low1, T->Keys[0]) <= 0 && strcmp(high1, T->Keys[0]) >= 0)
        if (strcmp(low2, T->Keys[1]) <= 0 && strcmp(high2, T->Keys[1]) >= 0)
          printf("%s %s\n", T->Keys[0], T->Keys[1]);
      if(strcmp(high1, T->Keys[0]) >= 0)
        tdprintRange(low1, high1, low2, high2, T->Child[1]);
    }
    else // odd levels
    {
      if(strcmp(low2, T->Keys[1]) <= 0)
        tdprintRange(low1, high1, low2, high2, T->Child[0]);
      if(strcmp(low2, T->Keys[1]) <= 0 && strcmp(high2, T->Keys[1]) >= 0)
        if (strcmp(low1, T->Keys[0]) <= 0 && strcmp(high1, T->Keys[0]) >= 0)
          printf("%s %s\n", T->Keys[0], T->Keys[1]);
      if(strcmp(high2, T->Keys[1]) >= 0)
        tdprintRange(low1, high1, low2, high2, T->Child[1]);
    }
  }
}

static void
td_print_dot_aux(TdTree T, FILE* stream)
{
  if(T != NULL)
  {
    int i;
    for(i=0;i < NUMKEYS; i++)
    {
      if (T->Child[i] != NULL)
      {
        fprintf(stream, "\"%s %s\"->\"%s %s\";\n", T->Keys[0], T->Keys[1],
                T->Child[i]->Keys[0], T->Child[i]->Keys[1]);
        td_print_dot_aux(T->Child[i], stream);
      }
    }
  }
}

void
td_print_dot(TdTree T, FILE* stream)
{
  fprintf(stream, "digraph TdTree{\n");
  td_print_dot_aux(T, stream);
  fprintf(stream, "}\n");
}

TdTree
initializeTdTree(char array[][30], int arrayLength)
{
  TdTree T = NULL;
  int i;
  for(i = 0; i < arrayLength; i++)
    T = insertion(array[i], T);
  return T;
}
