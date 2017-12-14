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
static REG loopPoint = 0;

static undefinedOp *undefinedOpList;

int initializeOutputFile(){
  if((outputFile = fopen(OUTPUT_FILE, "wb")) == NULL)
    return -1;
  op *sentinelOp = (op*)malloc(sizeof(op));
  sentinelOp -> next = NULL;
  opList = sentinelOp;
  opListTail = sentinelOp;

  undefinedOpList = NULL;
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

  opListTail -> next = newOp;
  opListTail = newOp;
}

void setUndefinedAddress(REG address){
  undefinedOp *tmp = undefinedOpList;
  undefinedOpList -> opFromList -> opCode.address = address;
  undefinedOpList = undefinedOpList -> prev;
  free(tmp);
}

REG getOpCount(){
  return opCount;
}

REG getStartPoint(){
  return startPoint;
}

void setLoopPoint(){
  loopPoint = opCount;
}

REG getLoopPoint(){
  return loopPoint;
}
