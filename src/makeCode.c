#include <stdio.h>
#include "optype.h"
#include "code.h"

#define OUTPUT_FILE "result.code"
static FILE *outputFile;

int initializeOutputFile(){
  if((outputFile = fopen(OUTPUT_FILE, "wb")) == NULL)
    return -1;
  return 0;
}

void closeOutputFile(){
  fclose(outputFile);
}

void generateOperation(int opCode, REG baseReg, REG indexReg, int address ){
  OPCODE OP;
  OP.opcode = opCode;
  OP.basereg = baseReg;
  OP.indexreg = indexReg;
  OP.address = address;

  fwrite(&OP, sizeof(OP), 1, outputFile);
}
