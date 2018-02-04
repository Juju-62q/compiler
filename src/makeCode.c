#include <stdio.h>
#include <stdlib.h>
#include "optype.h"
#include "code.h"

#define OUTPUT_FILE "result.code"
static FILE *outputFile;

static op *opList;
static op *opListTail;
static REG opCount = 0;
static REG startPoint = 0;

static loopPoint *loopPointList = NULL;

static undefinedOp *undefinedOpList = NULL;

static forwardedCall *forwardedCallList;
static forwardedCall *forwardedCallListTail;

int initializeOutputFile(){
  if((outputFile = fopen(OUTPUT_FILE, "wb")) == NULL)
    return -1;
  op *sentinelOp = (op*)malloc(sizeof(op));
  sentinelOp -> next = NULL;
  opList = sentinelOp;
  opListTail = sentinelOp;

  undefinedOpList = NULL;

  forwardedCall *sentinentCall = (forwardedCall*)malloc(sizeof(forwardedCall));
  sentinentCall -> next = NULL;
  forwardedCallList = sentinentCall;
  forwardedCallListTail = sentinentCall;
  return 0;
}

void writeExecuteFile(){
  op *tmpOp;
  for(tmpOp = opList -> next; tmpOp != NULL; tmpOp = tmpOp -> next){
    fwrite(&(tmpOp -> opCode), sizeof(OPCODE), 1, outputFile);
    free(tmpOp);
  }
  fclose(outputFile);
}

void generateOperation(int opCode, REG baseReg, REG indexReg, int address ){
  ++opCount;
  op *newOp = (op*)malloc(sizeof(op));
  newOp -> opCode.opcode = opCode;
  newOp -> opCode.basereg = baseReg;
  newOp -> opCode.indexreg = indexReg;
  newOp -> opCode.address = address;
  newOp -> next = NULL;

  if(opCode == JMP || opCode == JPC){
    undefinedOp *newUndefinedOp = (undefinedOp*)malloc(sizeof(undefinedOp));
    newUndefinedOp -> prev = undefinedOpList;
    newUndefinedOp -> opFromList = newOp;
    undefinedOpList = newUndefinedOp;
  }

  if(opCode == RTN){
    startPoint = opCount;
  }

  if(opCode == CAL && address < 0){
    forwardedCall *newForwardedCall = (forwardedCall*)malloc(sizeof(forwardedCall));
    newForwardedCall -> next = NULL;
    newForwardedCall -> callFromList = newOp;
    forwardedCallListTail -> next = newForwardedCall;
    forwardedCallListTail = newForwardedCall;
  }

  opListTail -> next = newOp;
  opListTail = newOp;
}

void setUndefinedAddress(REG address){
  undefinedOp *tmp = undefinedOpList;
  for(tmp = undefinedOpList; tmp != NULL; tmp = tmp -> prev)
    printf("%d ", tmp -> opFromList -> opCode.address);
  printf("\n");
  tmp = undefinedOpList;
  undefinedOpList -> opFromList -> opCode.address = address;
  undefinedOpList = undefinedOpList -> prev;
  //free(tmp);
}

REG getOpCount(){
  return opCount;
}

REG getStartPoint(){
  return startPoint;
}

void setLoopPoint(){
  loopPoint *newLoopPoint = (loopPoint*)malloc(sizeof(loopPoint));
  newLoopPoint -> prev = loopPointList;
  newLoopPoint -> loopPoint = (REG)opCount;
  loopPointList = newLoopPoint;
}

REG getLoopPoint(){
  loopPoint* i;
  for(i = loopPointList; i != NULL; i = i -> prev) printf("%d ",i -> loopPoint);
  printf("\n");
  REG retLoopPoint = loopPointList -> loopPoint;
  loopPoint *deleteLoopPoint = loopPointList;
  loopPointList = loopPointList -> prev;
  free(deleteLoopPoint);
  return retLoopPoint;
}

void setForwardedCall(int forwardedNum, unsigned int addr){
  forwardedCall *iterate;
  for(iterate = forwardedCallList -> next; iterate != NULL; iterate = iterate -> next){
    if(iterate -> callFromList -> opCode.address == forwardedNum){
      iterate -> callFromList -> opCode.address = addr;
    }
  }
  return;
}
