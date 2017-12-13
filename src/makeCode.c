#include <stdio.h>
#include <stdlib.h>
#include "optype.h"
#include "code.h"

#define OUTPUT_FILE "result.code"
static FILE *outputFile;

static op *opList;
static op *opListTail;
static unsigned int opCount = 0;
static unsigned int startPoint = 0;

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
     printf("startPoint = %d\n",startPoint);
  }

  opListTail -> next = newOp;
  opListTail = newOp;
}

void setUndefinedAddress(unsigned int address){
  undefinedOp *tmp = undefinedOpList;
  undefinedOpList -> opFromList -> opCode.address = address;
  undefinedOpList = undefinedOpList -> prev;
  free(tmp);
}

unsigned int getOpCount(){
  return opCount;
}

unsigned int getStartPoint(){
  return startPoint;
}
