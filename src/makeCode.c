#include <stdio.h>
#include <stdlib.h>
#include "optype.h"
#include "code.h"

#define OUTPUT_FILE "result.code"
static FILE *outputFile;
static op *opList;
static op *opListTail;
static op *undefinedOpList;
static op *undefinedOpListTail;

int initializeOutputFile(){
  if((outputFile = fopen(OUTPUT_FILE, "wb")) == NULL)
    return -1;
  op *sentinelOp;
  sentinelOp = (op*)malloc(sizeof(op));
  sentinelOp -> next = NULL;
  opList = sentinelOp;
  opListTail = sentinelOp;
  undefinedOpList = sentinelOp;
  undefinedOpListTail = sentinelOp;
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
  op *newOp = (op*)malloc(sizeof(op));
  newOp -> opCode.opcode = opCode;
  newOp -> opCode.basereg = baseReg;
  newOp -> opCode.indexreg = indexReg;
  newOp -> opCode.address = address;
  newOp -> next = NULL;

  if(opCode == JMP || opCode == JPC){
    undefinedOpListTail -> next = newOp;
    newOp = undefinedOpListTail;
  }

  opListTail -> next = newOp;
  newOp = opListTail;
}
