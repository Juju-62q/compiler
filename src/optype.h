/*
	Virtual machine word definition 
		Sccs(@(#)optype.h	1.1  1/24/91)
*/

/*
    Register is equivalent to int
*/
typedef int REG;

/*
    One word is composed of instruction code, base register,
    index register, address field
*/
typedef struct {
    int	opcode;
    REG	basereg;
    REG	indexreg;
    REG address;
} OPCODE;

struct op{
  OPCODE opCode;
  struct op *next;
};

typedef struct op op;

struct undefinedOp{
  op *opFromList;
  struct undefinedOp *prev;
};

typedef struct undefinedOp undefinedOp;

int initializeOutputFile();
void writeExecuteFile();
void generateOperation(int opCode, REG baseReg, REG indexReg, int address);
void setUndefinedAddress();
