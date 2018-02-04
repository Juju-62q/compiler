#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

enum kindOfItem{
  local,
  global,
  func,
  forward,
  sentinel
};

struct item{
  char *name;
  unsigned int addr;
  enum kindOfItem kind;
  unsigned int arrayTop;
  struct item *prev;
};

typedef struct item tableItem;

void initializeStack();
void printAllItems();
void addItemToStack(char *name, enum kindOfItem kind, unsigned int arrayTop, unsigned int size);
void removeLocalVariable();
tableItem* searchItem(char *name);
void setFunctionAddress(tableItem* item);
