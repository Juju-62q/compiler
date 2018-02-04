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

struct forwardedCall{
  op *callFromList;
  struct forwardedCall *next;
};

typedef struct forwardedCall forwardedCall;

struct loopPoint{
  REG loopPoint;
  struct loopPoint *prev;
};

typedef struct loopPoint loopPoint;

int initializeOutputFile();
void writeExecuteFile();
void generateOperation(int opCode, REG baseReg, REG indexReg, REG address);
void setUndefinedAddress(REG address);
REG getOpCount();
REG getStartPoint();
void setLoopPoint();
REG getLoopPoint();
void setForwardedCall(int forwardedNum, unsigned int addr);
