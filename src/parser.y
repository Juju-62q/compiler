%{
/* 
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include "stack.h"
#include "code.h"
#include "optype.h"

extern int yylineno;
extern char* yytext;
static enum kindOfItem kind = global;
static int procFlag = 1;
static char* forLoopVar;

%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS
%left MULT DIV

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER
%token <ident> IDENT

%%

program
        : PROGRAM IDENT SEMICOLON outblock PERIOD
        {
          if(!procFlag) setUndefinedAddress(getStartPoint());
          printf("program end\n");
          printAllItems();
        }
        ;

outblock
        : var_decl_part subprog_decl_part statement
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
        ;

var_decl_list
        : var_decl_list SEMICOLON var_decl
        | var_decl
        ;

var_decl
        : VAR id_list
        ;

subprog_decl_part
        : subprog_decl_list SEMICOLON
        | /* empty */
        ;

subprog_decl_list
        : subprog_decl_list SEMICOLON subprog_decl
        | subprog_decl
        ;

subprog_decl
        : proc_decl
        ;

proc_decl 
        : PROCEDURE proc_name SEMICOLON inblock
        {
          kind = global;
          removeLocalVariable();
          printf("removeing Items\n");
          printAllItems();
        }
        ;

proc_name 
        : IDENT
        {
          kind = local;
          addItemToStack($1,func);
          printf("procedure declaration\n");
          printAllItems();
          if(procFlag){
            procFlag = 0;
            generateOperation(JMP,0,0,0);
          }
        }
        ;

inblock
        : var_decl_part statement
        {
          generateOperation(RTN, 0, 0, 0);
        }
        ;

statement_list
        : statement_list SEMICOLON statement
        | statement
        ;

statement
        : assignment_statement
        | if_statement
        | while_statement
        | for_statement
        | proc_call_statement
        | null_statement
        | block_statement
        | read_statement
        | write_statement
        ;

assignment_statement
        : IDENT ASSIGN expression
        {
          tableItem *item;
          item = searchItem($1);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(STO, base, 0, item -> addr);
        }
        ;

if_statement
        : IF condition THEN statement set_address_if else_statement set_address_else
        ;

set_address_if
        : 
        {
          setUndefinedAddress(getOpCount());
          generateOperation(JMP, 0, 0, 0);
        }
          
else_statement
        : ELSE statement
        | /* empty */
        ;

set_address_else
        :
        {
          setUndefinedAddress(getOpCount());
        }


while_statement
        : WHILE set_while_loop condition DO statement
        {
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
          setUndefinedAddress(getLoopPoint());
        }
        ;

set_while_loop
        :
        {
          setLoopPoint();
        }

for_statement
        : for_initial for_loop statement
        {
          tableItem *item = searchItem(forLoopVar);
          REG base = item -> kind == local ? 1 : 0;

          //increment
          generateOperation(LOD, base, 0, item -> addr);
          generateOperation(LIT, 0, 0, 1);
          generateOperation(OPR, 0, 0, 1);
          generateOperation(STO, base, 0, item -> addr);

          // set up loop
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
          setUndefinedAddress(getLoopPoint());
          free(forLoopVar);
        }
        ;

for_initial
        : FOR IDENT ASSIGN expression
        {
          //initiallize
          tableItem *item;
          item = searchItem($2);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(STO, base, 0, item -> addr);
          setLoopPoint();

          forLoopVar = (char*)malloc(strlen($2));
          sprintf(forLoopVar, "%s", $2);
        }

for_loop
        : TO expression DO
        {
          tableItem *item = searchItem(forLoopVar);
          REG base = item -> kind == local ? 1 : 0;

          //check loop condition
          generateOperation(LOD, base, 0, item -> addr);
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
        {
          tableItem *item;
          item = searchItem($1);
          generateOperation(CAL, 0, 0, item -> addr);
        }
        ;

block_statement
        : SBEGIN statement_list SEND
        ;

read_statement
        : READ LPAREN IDENT RPAREN
        {
          tableItem *item;
          item = searchItem($3);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(GET, 0, 0, 0);
          generateOperation(STO, base, 0, item -> addr);
        }
        ;

write_statement
        : WRITE LPAREN expression RPAREN
        {
          generateOperation(PUT, 0, 0, 0);
        }
        ;

null_statement
        : /* empty */
        ;

condition
        : expression EQ expression
        {
          generateOperation(OPR, 0, 0, 5);
          generateOperation(JPC, 0, 0, 0);
        }
        | expression NEQ expression
        {
          generateOperation(OPR, 0, 0, 6);
          generateOperation(JPC, 0, 0, 0);
        }
        | expression LT expression
        {
          generateOperation(OPR, 0, 0, 7);
          generateOperation(JPC, 0, 0, 0);
        }
        | expression LE expression
        {
          generateOperation(OPR, 0, 0, 8);
          generateOperation(JPC, 0, 0, 0);
        }
        | expression GT expression
        {
          generateOperation(OPR, 0, 0, 9);
          generateOperation(JPC, 0, 0, 0);
        }
        | expression GE expression
        {
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
        ;

expression
        : term
        | PLUS term
        | MINUS term
        {
          generateOperation(OPR, 0, 0, 0);
        }
        | expression PLUS term
        {
          generateOperation(OPR, 0, 0, 1);
        }
        | expression MINUS term
        {
          generateOperation(OPR, 0, 0, 2);
        }
        ;

term
        : factor
        | term MULT factor
        {
          generateOperation(OPR, 0 ,0 ,3);
        }
        | term DIV factor
        {
          generateOperation(OPR, 0 ,0 ,4);
        }
        ;

factor
        : var_name
        | NUMBER
        {
          generateOperation(LIT,0,0,$1);
        }
        | LPAREN expression RPAREN
        ;

var_name
        : IDENT
        {
          tableItem *item;
          item = searchItem($1);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(LOD, base, 0, item -> addr);
        }
        ;

arg_list
        : expression
        | arg_list COMMA expression
        ;

id_list
        : IDENT
        {
          addItemToStack($1,kind);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
        | id_list COMMA IDENT
        {
          addItemToStack($3,kind);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
        ;

%% 
yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
  fprintf(stderr, "%d %s\n", yylineno, yytext);
}
