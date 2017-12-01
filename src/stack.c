#include "stack.h"

static char* getKindString(enum kindOfItem kind);
static void removeItem();

/*declation of Stack Items*/
static tableItem *stackPointer;
static int globalNum = 0;
static int localNum = 0;

/*int main(){
  initializeStack();
  addItemToStack("test1",local);
  addItemToStack("test2",global);
  addItemToStack("test3",func);
  addItemToStack("local1",local);
  addItemToStack("local2",local);
  printAllItems();
  //tableItem *item = searchItem("test1");
  printf("-----------------------------------\n");
  removeLocalVariable();
  printAllItems();
}*/

void initializeStack(){

  /*setting sentinel*/
  tableItem *sentinelItem;
  sentinelItem = (tableItem*)malloc(sizeof(tableItem));
  sentinelItem -> name = "\0";
  sentinelItem -> addr = 0;
  sentinelItem -> kind = sentinel;
  sentinelItem -> prev = NULL;

  /*setup stack pointer*/
  stackPointer = sentinelItem;
}

void printAllItems(){
  tableItem *item;
  for(item = stackPointer ; item -> kind != sentinel ; item = item -> prev){
    printf("%s\t%d\t%s\n",item -> name, item -> addr, getKindString(item -> kind));
  }
}

static char* getKindString(enum kindOfItem kind){
  switch (kind){
    case local:
      return "local";
    case global:
      return "global";
    case func:
      return "func";
    default:
      return "input error";
  }
}

void addItemToStack(char *name, enum kindOfItem kind){

  /*set information about new item*/
  tableItem *newItem;
  newItem = (tableItem*)malloc(sizeof(tableItem));
  newItem -> name = (char*)malloc(strlen(name));
  sprintf(newItem -> name, "%s", name);
  newItem -> addr = (kind == local)? localNum++ : globalNum++;
  newItem -> kind = kind;
  newItem -> prev = stackPointer;
  
  /*set stackPointer*/
  stackPointer = newItem;
}

void removeLocalVariable(){
  tableItem *item;
  for(item = stackPointer ; item -> kind != sentinel ; item = item -> prev){
    if(item -> kind == func) return;
    if(item -> kind == local) removeItem(item);
  }
}

static void removeItem(){
  tableItem *item;
  tableItem *prev = stackPointer -> prev;
  free(stackPointer -> name);
  free(stackPointer);
  stackPointer = prev;
}

tableItem* searchItem(char *name){
  tableItem *item;
  for(item = stackPointer ; item -> kind != sentinel ; item = item -> prev){
     if(!(strcmp(item -> name, name))) return item;
  }
  return NULL;
}
