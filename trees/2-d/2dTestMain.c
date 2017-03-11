#include "2d.h"

void generate_dot(TdTree);
void delete_tree(TdTree);
void test_initializeTdTree();
void test_tdprintRange();

int main()
{
  printf("////////////////////\n");
  printf("/// 2D TREE TEST\n");
  printf("////////////////////\n");

  test_initializeTdTree();   printf("\n");
  test_tdprintRange();       printf("\n");

  return 0;
}

void
generate_dot(TdTree T)
{
  char* dotFilename = "2d.dot";
  FILE *fp = fopen(dotFilename, "w");
  td_print_dot(T, fp);
  fclose(fp);
  printFile(dotFilename);
}

void
delete_tree(TdTree T)
{
  makeEmpty(T);
}
   
void
test_initializeTdTree()
{
  printf("TEST: initializeTdTree\n");
  char test_array[][30] = { // array of char array: K&R p.114
    "Harry Truman",
    "Dwight Eisenhower",
    "John Kennedy",
    "Lyndon Johnson",
    "Richard Nixon",
    "Gerald Ford",
    "Jimmy Carter",
    "Ronald Reagan",
    "George Bush",
    "Bill Clinton"
  };
  TdTree T = initializeTdTree(test_array, 10);
  generate_dot(T);
  delete_tree(T);
}

void
test_tdprintRange()
{
  printf("TEST: tdprintRange\n");
  char test_array[][30] = { // array of char array: K&R p.114. strtok cannot work on constant string
    "Harry Truman",
    "Dwight Eisenhower",
    "John Kennedy",
    "Lyndon Johnson",
    "Richard Nixon",
    "Gerald Ford",
    "Jimmy Carter",
    "Ronald Reagan",
    "George Bush",
    "Bill Clinton"
  };
  TdTree T = initializeTdTree(test_array, 10);
  tdprintRange("A", "Z", "A", "Z", T);
  delete_tree(T);
}
