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
          generateOperation(STO, 0, 0, item -> addr);
        }
        ;

if_statement
        : IF condition THEN statement else_statement
        ;

else_statement
        : ELSE statement
        | /* empty */
        ;

while_statement
        : WHILE condition DO statement
        ;

for_statement
        : FOR IDENT ASSIGN expression TO expression DO statement
        {
          tableItem *item;
          item = searchItem($2);
        }
        ;

proc_call_statement
        : proc_call_name
        ;

proc_call_name
        : IDENT
        {
          tableItem *item;
          item = searchItem($1);
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
        }
        ;

write_statement
        : WRITE LPAREN expression RPAREN
        ;

null_statement
        : /* empty */
        ;

condition
        : expression EQ expression
        | expression NEQ expression
        | expression LT expression
        | expression LE expression
        | expression GT expression
        | expression GE expression
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
        | term DIV factor
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
          generateOperation(LOD, 0, 0, item -> addr);
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
