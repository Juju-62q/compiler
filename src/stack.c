#include "stack.h"
#include "optype.h"

static char* getKindString(enum kindOfItem kind);
static void removeItem();

/*declation of Stack Items*/
static tableItem *stackPointer;
static int globalNum = 0;
static int localNum = 0;
static int forwardNum = 0;

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

void addItemToStack(char *name, enum kindOfItem kind, unsigned int arrayTop, unsigned int size){

  /*set information about new item*/
  tableItem *newItem;
  newItem = (tableItem*)malloc(sizeof(tableItem));
  newItem -> name = (char*)malloc(strlen(name));
  sprintf(newItem -> name, "%s", name);
  if(kind == func){
    newItem -> addr = getOpCount();
    localNum = 0;
  }else if(kind == forward){
    newItem -> addr = --forwardNum;
    localNum = 0;
    kind = func;
  }else{
    if(kind == local){
      newItem -> addr = localNum;
      localNum += size;
    }else{
      newItem -> addr = globalNum;
      globalNum += size;
    }    
  }
  newItem -> kind = kind;
  newItem -> arrayTop = arrayTop;
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
    if(!strcmp(item -> name, name)){
      if(item -> kind == func) localNum = 0;
      printf("lookup (%s) -> addr : %d,type : %s\n", name, item->addr, getKindString(item->kind));
      return item;
    }
  }
  printf("lookup (%s) -> not found\n", name);
  return NULL;
}

void setFunctionAddress(tableItem* item){
  setForwardedCall(item -> addr, getOpCount());
  item -> addr = getOpCount();
  return;
}
