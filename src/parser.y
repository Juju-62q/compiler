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
static int procVariableNum = 0;

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

%type <ident> proc_call_name
%type <num> proc_call_statement
%type <ident> array_assign
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
        | function_decl
        ;

proc_decl 
        : PROCEDURE proc_name SEMICOLON inblock
        {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
        | PROCEDURE proc_name LPAREN proc_variables RPAREN SEMICOLON inblock
        {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(INT, 0, 0, - procVariableNum);
          generateOperation(RTN, 0, 0, 0);
          procVariableNum = 0;
        }
        ;

function_decl 
        : FUNCTION proc_name SEMICOLON inblock
        {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
        | FUNCTION proc_name LPAREN proc_variables RPAREN SEMICOLON inblock
        {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(INT, 0, 0, - procVariableNum);
          generateOperation(RTN, 0, 0, 0);
          procVariableNum = 0;
        }
        ;

proc_variables
        : proc_var_list
        {
          generateOperation(INT, 0, 0, procVariableNum);
        }

proc_var_list
        : IDENT
        {
          addItemToStack($1, local , 0, 1);
          printf("variable declaration\n");
          printAllItems();
          ++procVariableNum;
        }
        | proc_var_list COMMA IDENT
        {
          addItemToStack($3, local, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          ++procVariableNum;
        }
        ;

proc_name 
        : IDENT
        {
          kind = local;
          printf("procedure declaration\n");
          printAllItems();
          if(procFlag){
            procFlag = 0;
            generateOperation(JMP,0,0,0);
          }
          addItemToStack($1, func, 0, 0);
        }
        ;

inblock
        : var_decl_part statement
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
          if (item -> kind == func){
            generateOperation(STO, 1, 0, -5);
          }else{
            REG base = item -> kind == local ? 1 : 0;
            generateOperation(STO, base, 0, item -> addr);
          }
        }
        | array_assign ASSIGN expression
        {
          tableItem *item;
          item = searchItem($1);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(STO, base, 3, item -> addr);
        }
        ;

array_assign
        : IDENT LBRACKET expression RBRACKET
        {
          strcpy($$, $1);
          tableItem *item;
          item = searchItem($1);
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 3, 0);
        }

if_statement
        : IF condition THEN statement set_address_if else_statement set_address_else
        ;

set_address_if
        : 
        {
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
        }
        ;
          
else_statement
        : ELSE statement
        | /* empty */
        ;

set_address_else
        :
        {
          setUndefinedAddress(getOpCount());
        }
        ;


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
        ;

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
        ;

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
        ;

proc_call_statement
        : proc_call_name add_stack_proc LPAREN arg_list RPAREN
        {
          tableItem *item;
          item = searchItem($1);
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }
        | proc_call_name
        {
          tableItem *item;
          item = searchItem($1);
          generateOperation(CAL, 0, 0, item -> addr);
        }
        ;

add_stack_proc
        :
        {
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 4);
        }
        ;

proc_call_name
        : IDENT
        {
          strcpy($$, $1);
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
        | READ LPAREN IDENT LBRACKET expression RBRACKET RPAREN
        {
          tableItem *item;
          item = searchItem($3);
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 3, 0);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(GET, 0, 0, 0);
          generateOperation(STO, base, 3, item -> addr);
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
        : var_or_function
        | var_array
        | NUMBER
        {
          generateOperation(LIT,0,0,$1);
        }
        | LPAREN expression RPAREN
         | proc_call_name add_stack_func LPAREN arg_list RPAREN
        {
          tableItem *item;
          item = searchItem($1);
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }        
        ;

add_stack_func
        :
        {
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 5);
        }
        ;

var_or_function
        : IDENT
        {
          tableItem *item;
          item = searchItem($1);
          if(item -> kind == func){
            generateOperation(INT, 0, 0, 1);
            generateOperation(CAL, 0, 0, item -> addr);
          }else{
            REG base = item -> kind == local ? 1 : 0;
            generateOperation(LOD, base, 0, item -> addr);
          }
        }
        ;

var_array
        : IDENT LBRACKET expression RBRACKET
        {
          tableItem *item;
          item = searchItem($1);
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 4, 0);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(LOD, base, 4, item -> addr); 
        }
        ;

arg_list
        : expression
        {
          ++procVariableNum;
        }
        | arg_list COMMA expression
        {
          ++procVariableNum;
        }
        ;

id_list
        : IDENT
        {
          addItemToStack($1, kind, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
        | id_list COMMA IDENT
        {
          addItemToStack($3, kind, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
        | IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET
        {
          addItemToStack($1, kind, $3, $5 - $3);
          printf("variable declaration\n");
          printAllItems();
          int i;
          for( i = $3; i < $5; ++i)
            generateOperation(LIT,0,0,0);
        }
        | id_list COMMA IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET
        {
          addItemToStack($3, kind, $5, $7 - $5);
          printf("variable declaration\n");
          printAllItems();
          int i;
          for( i = $5; i < $7; ++i)
            generateOperation(LIT,0,0,0);
        }
        ;

%% 
yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
  fprintf(stderr, "%d %s\n", yylineno, yytext);
}
