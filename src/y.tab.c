#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "parser.y"
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

#line 21 "parser.y"
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#line 46 "y.tab.c"
#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    4,    5,    5,    8,    8,    9,    6,    6,   11,
   11,   12,   12,   13,   13,   14,   14,   17,   18,   18,
   15,   16,   19,   19,    7,    7,    7,    7,    7,    7,
    7,    7,    7,   20,   20,    3,   21,   30,   31,   31,
   32,   22,   33,   23,   34,   35,    2,    2,   36,    1,
   25,   26,   26,   27,   24,   29,   29,   29,   29,   29,
   29,   28,   28,   28,   28,   28,   38,   38,   38,   39,
   39,   39,   39,   39,   42,   40,   41,   37,   37,   10,
   10,   10,   10,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    2,    0,    3,
    1,    1,    1,    4,    7,    4,    7,    1,    1,    3,
    1,    2,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    3,    4,    7,    0,    2,    0,
    0,    5,    0,    3,    4,    3,    5,    1,    0,    1,
    3,    4,    7,    4,    0,    3,    3,    3,    3,    3,
    3,    1,    2,    2,    3,    3,    1,    3,    3,    1,
    1,    1,    3,    5,    0,    1,    4,    1,    3,    1,
    3,    6,    8,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,    1,    0,    0,    0,    0,   11,   12,   13,    0,
    0,    0,   21,    0,    0,    0,    0,    0,    0,   43,
    0,    0,    0,   29,    0,    2,   25,   26,   27,   28,
   30,   31,   32,   33,    0,    0,    5,    0,    0,    0,
    0,    0,    0,   24,    0,    0,    0,    0,    0,   72,
    0,   75,    0,    0,    0,   67,   70,   71,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   10,    0,    0,
   19,    0,    0,    0,   16,    0,   14,   51,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   44,    0,    0,    0,    0,   22,
    0,   23,    0,   73,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   38,   68,   69,   52,    0,    0,
   54,   36,    0,    0,   46,   82,    0,    0,   20,    0,
   77,    0,    0,    0,   42,   47,    0,    0,   17,   15,
   74,    0,   41,    0,    0,   83,   39,   37,   53,
};
short yydgoto[] = {                                       2,
   62,   34,   35,    6,   84,   15,   36,    8,    9,   11,
   16,   17,   18,   19,   24,   85,   82,   83,   55,   37,
   38,   39,   40,   41,   42,   43,   44,   63,   64,  153,
  163,  168,   70,   45,   77,   74,  144,   65,   66,   67,
   68,   95,
};
short yysindex[] = {                                   -254,
 -288,    0, -264, -240, -257, -200, -123, -216,    0, -185,
 -153,    0, -191, -191, -116, -142,    0,    0,    0, -240,
 -135, -121,    0, -107,  -76, -116, -119, -111, -131,    0,
  -87, -124,    0,    0,  -84,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -59, -123,    0,  -69,  -57,  -64,
 -240,  -64, -240,    0, -256,  -41, -129, -129, -111,    0,
  -31,    0,   97,  -24, -157,    0,    0,    0,  -39, -111,
 -111, -111, -111,  -19, -111, -111, -116,    0,  -18,  -17,
    0,  -22,   -9, -116,    0,  -16,    0,    0, -116, -111,
 -157, -157, -146, -111,   -4, -129, -129, -111, -111, -111,
 -111, -111, -111, -116, -129, -129, -219,   11,  -73, -260,
  -58, -111,  -58, -251,    0,   -6,   -7,   -3,  -10,    0,
    1,    0,  -58,    0, -213, -111, -157, -157,  -58,  -58,
  -58,  -58,  -58,  -58,    0,    0,    0,    0, -111, -116,
    0,    0,  -58, -110,    0,    0,   -5, -240,    0, -240,
    0,  -78,   37, -164,    0,    0, -111,   12,    0,    0,
    0, -116,    0,   18,  -58,    0,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -236,    0,    0, -159,    0,    0,  -53,
   15,    0,    0,    0,   17,    0,    0,    0,    0, -177,
    0,    0,    0,    0,    0, -255,    0,    0,    0,    0,
    0, -220, -206,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -141,    0,    0,  -46,    0,
 -128,    0, -128,    0,    0,    0,    0,    0,    0,    0,
  -89,    0,    0,    0,  -55,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -184,    0,    0,    0,
    0,    0,   25,   22,    0,    0,    0,    0, -255,    0,
  -21,   13,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -184,    0,    0,    0,    0,    0,    0,
 -167,    0,  -14,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   42,    0,    0,    0,   47,   81, -250, -217,
 -201, -162, -109, -101,    0,    0,    0,    0,    0, -184,
    0,    0,  -67,    0,    0,    0,    0, -128,    0, -128,
    0,    0, -210,    0,    0,    0,    0,    0,    0,    0,
    0, -184,    0,    0,  -44,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  -15,    0,    0,    0,  308,    0,  -25,    0,  293,    0,
    0,  268,    0,    0,  303,  -51,  266,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -56,  249,    0,
    0,    0,    0,    0,    0,    0,  196,  -48,  144,    0,
    0,    0,
};
#define YYTABLESIZE 379
short yytable[] = {                                      33,
   54,   87,   93,   88,   55,    3,  145,   56,   91,   92,
   33,    1,   96,   97,  109,  110,  111,   56,  113,  114,
    3,   96,   97,    4,    3,  142,    3,    3,    3,    5,
    3,   89,   55,  123,    3,    3,   10,  125,   50,   50,
   57,  129,  130,  131,  132,  133,  134,  127,  128,   40,
   57,  115,   48,   48,    3,  143,   59,    3,  120,   96,
   97,   33,   50,  122,  138,  139,   59,   50,   33,  143,
   50,   20,  151,   33,   55,   55,   49,   40,  135,    4,
   40,   48,  154,    4,   48,    4,    4,    4,   33,    4,
   12,   34,   34,    4,    4,   58,  159,    9,  160,   21,
  165,    9,   23,   55,    9,   58,   55,    9,   96,   97,
    4,    9,    9,    4,  155,    8,    4,  105,  106,    8,
   34,  164,    8,   34,   33,    8,   96,   97,    3,    8,
    8,    9,    3,   22,    9,    3,  167,  124,    3,   13,
   26,   14,    3,    3,   27,   46,   33,   28,   61,    8,
   29,   69,    8,   59,   30,   31,   60,   48,   61,    3,
   72,   57,   58,   60,   61,    3,   60,   73,   76,   76,
   76,   59,   49,  156,   56,   50,  157,   32,   76,   76,
   51,   60,   61,   76,   76,   76,   76,   76,   76,   76,
   76,   76,   76,   50,   76,   71,   76,   76,   76,   96,
   97,   76,   62,   62,   62,  161,   52,   75,  157,   76,
  141,   53,   62,   62,   96,   97,   78,   62,   62,   78,
   79,   62,   62,   62,   62,   62,   62,   80,   62,   81,
   62,   62,   62,   80,   80,   62,   63,   63,   63,   79,
   81,   81,   79,  104,   35,   35,   63,   63,  136,  137,
   90,   63,   63,   94,  107,   63,   63,   63,   63,   63,
   63,  118,   63,  112,   63,   63,   63,  121,  140,   63,
   64,   64,   64,   35,  116,  117,   35,  119,  126,  146,
   64,   64,  147,  149,  148,   64,   64,  158,  150,   64,
   64,   64,   64,   64,   64,  162,   64,  166,   64,   64,
   64,  169,    7,   64,   65,   65,   65,   55,   18,   55,
   45,    7,   47,   78,   65,   65,   25,   86,  108,   65,
   65,  152,    0,   65,   65,   65,   65,   65,   65,    0,
   65,    0,   65,   65,   65,    0,    0,   65,   66,   66,
   66,    0,    0,    0,    0,    0,    0,    0,   66,   66,
    0,    0,    0,   66,   66,    0,    0,   66,   66,   66,
   66,   66,   66,    0,   66,    0,   66,   66,   66,   96,
   97,   66,    0,   98,   99,  100,  101,  102,  103,
};
short yycheck[] = {                                      15,
   26,   53,   59,  260,  260,  294,  258,  258,   57,   58,
   26,  266,  273,  274,   71,   72,   73,  268,   75,   76,
  257,  273,  274,  288,  261,  286,  263,  264,  265,  270,
  267,  288,  288,   90,  271,  272,  294,   94,  259,  260,
  258,   98,   99,  100,  101,  102,  103,   96,   97,  260,
  268,   77,  259,  260,  291,  112,  258,  294,   84,  273,
  274,   77,  283,   89,  284,  285,  268,  288,   84,  126,
  291,  288,  286,   89,  259,  260,  283,  288,  104,  257,
  291,  288,  139,  261,  291,  263,  264,  265,  104,  267,
  291,  259,  260,  271,  272,  258,  148,  257,  150,  285,
  157,  261,  294,  288,  264,  268,  291,  267,  273,  274,
  288,  271,  272,  291,  140,  257,  294,  275,  276,  261,
  288,  286,  264,  291,  140,  267,  273,  274,  257,  271,
  272,  291,  261,  287,  294,  264,  162,  284,  267,  263,
  257,  265,  271,  272,  261,  288,  162,  264,  258,  291,
  267,  283,  294,  283,  271,  272,  258,  293,  268,  288,
  285,  273,  274,  293,  294,  294,  268,  292,  258,  259,
  260,  283,  294,  284,  294,  283,  287,  294,  268,  269,
  288,  293,  294,  273,  274,  275,  276,  277,  278,  279,
  280,  281,  282,  283,  284,  283,  286,  287,  288,  273,
  274,  291,  258,  259,  260,  284,  283,  292,  287,  269,
  284,  288,  268,  269,  273,  274,  284,  273,  274,  287,
  290,  277,  278,  279,  280,  281,  282,  285,  284,  294,
  286,  287,  288,  287,  288,  291,  258,  259,  260,  284,
  287,  288,  287,  268,  259,  260,  268,  269,  105,  106,
  292,  273,  274,  285,  294,  277,  278,  279,  280,  281,
  282,  284,  284,  283,  286,  287,  288,  284,  258,  291,
  258,  259,  260,  288,  293,  293,  291,  287,  283,  286,
  268,  269,  290,  294,  288,  273,  274,  293,  288,  277,
  278,  279,  280,  281,  282,  259,  284,  286,  286,  287,
  288,  284,  288,  291,  258,  259,  260,  291,  284,  288,
  269,    4,   20,   46,  268,  269,   14,   52,   70,  273,
  274,  126,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,   -1,  286,  287,  288,   -1,   -1,  291,  258,  259,
  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,
   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,   -1,  286,  287,  288,  273,
  274,  291,   -1,  277,  278,  279,  280,  281,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
char *yyrule[] = {
"$accept : program",
"program : PROGRAM IDENT SEMICOLON outblock PERIOD",
"outblock : var_decl_part subprog_decl_part statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"subprog_decl : function_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"proc_decl : PROCEDURE proc_name LPAREN proc_variables RPAREN SEMICOLON inblock",
"function_decl : FUNCTION proc_name SEMICOLON inblock",
"function_decl : FUNCTION proc_name LPAREN proc_variables RPAREN SEMICOLON inblock",
"proc_variables : proc_var_list",
"proc_var_list : IDENT",
"proc_var_list : proc_var_list COMMA IDENT",
"proc_name : IDENT",
"inblock : var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"assignment_statement : IDENT ASSIGN expression",
"assignment_statement : array_assign ASSIGN expression",
"array_assign : IDENT LBRACKET expression RBRACKET",
"if_statement : IF condition THEN statement set_address_if else_statement set_address_else",
"set_address_if :",
"else_statement : ELSE statement",
"else_statement :",
"set_address_else :",
"while_statement : WHILE set_while_loop condition DO statement",
"set_while_loop :",
"for_statement : for_initial for_loop statement",
"for_initial : FOR IDENT ASSIGN expression",
"for_loop : TO expression DO",
"proc_call_statement : proc_call_name add_stack_proc LPAREN arg_list RPAREN",
"proc_call_statement : proc_call_name",
"add_stack_proc :",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"read_statement : READ LPAREN IDENT LBRACKET expression RBRACKET RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_or_function",
"factor : var_array",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"factor : proc_call_name add_stack_func LPAREN arg_list RPAREN",
"add_stack_func :",
"var_or_function : IDENT",
"var_array : IDENT LBRACKET expression RBRACKET",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",
"id_list : IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",
"id_list : id_list COMMA IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 538 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
  fprintf(stderr, "%d %s\n", yylineno, yytext);
}
#line 406 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 48 "parser.y"
{
          if(!procFlag) setUndefinedAddress(getStartPoint());
          printf("program end\n");
          printAllItems();
        }
break;
case 14:
#line 90 "parser.y"
{
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
break;
case 15:
#line 98 "parser.y"
{
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(INT, 0, 0, - procVariableNum);
          generateOperation(RTN, 0, 0, 0);
          procVariableNum = 0;
        }
break;
case 16:
#line 111 "parser.y"
{
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
break;
case 17:
#line 119 "parser.y"
{
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(INT, 0, 0, - procVariableNum);
          generateOperation(RTN, 0, 0, 0);
          procVariableNum = 0;
        }
break;
case 18:
#line 132 "parser.y"
{
          generateOperation(INT, 0, 0, procVariableNum);
        }
break;
case 19:
#line 138 "parser.y"
{
          addItemToStack(yyvsp[0].ident, local , 0, 1);
          printf("variable declaration\n");
          printAllItems();
          ++procVariableNum;
        }
break;
case 20:
#line 145 "parser.y"
{
          addItemToStack(yyvsp[0].ident, local, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          ++procVariableNum;
        }
break;
case 21:
#line 155 "parser.y"
{
          kind = local;
          printf("procedure declaration\n");
          printAllItems();
          if(procFlag){
            procFlag = 0;
            generateOperation(JMP,0,0,0);
          }
          addItemToStack(yyvsp[0].ident, func, 0, 0);
        }
break;
case 34:
#line 190 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-2].ident);
          if (item -> kind == func){
            generateOperation(STO, 1, 0, -5);
          }else{
            REG base = item -> kind == local ? 1 : 0;
            generateOperation(STO, base, 0, item -> addr);
          }
        }
break;
case 35:
#line 201 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-2].ident);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(STO, base, 3, item -> addr);
        }
break;
case 36:
#line 211 "parser.y"
{
          strcpy(yyval.ident, yyvsp[-3].ident);
          tableItem *item;
          item = searchItem(yyvsp[-3].ident);
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 3, 0);
        }
break;
case 38:
#line 226 "parser.y"
{
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
        }
break;
case 41:
#line 239 "parser.y"
{
          setUndefinedAddress(getOpCount());
        }
break;
case 42:
#line 247 "parser.y"
{
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
          setUndefinedAddress(getLoopPoint());
        }
break;
case 43:
#line 256 "parser.y"
{
          setLoopPoint();
        }
break;
case 44:
#line 263 "parser.y"
{
          tableItem *item = searchItem(forLoopVar);
          REG base = item -> kind == local ? 1 : 0;

          /*increment*/
          generateOperation(LOD, base, 0, item -> addr);
          generateOperation(LIT, 0, 0, 1);
          generateOperation(OPR, 0, 0, 1);
          generateOperation(STO, base, 0, item -> addr);

          /* set up loop*/
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
          setUndefinedAddress(getLoopPoint());
          free(forLoopVar);
        }
break;
case 45:
#line 283 "parser.y"
{
          /*initiallize*/
          tableItem *item;
          item = searchItem(yyvsp[-2].ident);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(STO, base, 0, item -> addr);
          setLoopPoint();

          forLoopVar = (char*)malloc(strlen(yyvsp[-2].ident));
          sprintf(forLoopVar, "%s", yyvsp[-2].ident);
        }
break;
case 46:
#line 298 "parser.y"
{
          tableItem *item = searchItem(forLoopVar);
          REG base = item -> kind == local ? 1 : 0;

          /*check loop condition*/
          generateOperation(LOD, base, 0, item -> addr);
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 47:
#line 311 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-4].ident);
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }
break;
case 48:
#line 318 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[0].ident);
          generateOperation(CAL, 0, 0, item -> addr);
        }
break;
case 49:
#line 327 "parser.y"
{
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 4);
        }
break;
case 50:
#line 335 "parser.y"
{
          strcpy(yyval.ident, yyvsp[0].ident);
        }
break;
case 52:
#line 346 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-1].ident);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(GET, 0, 0, 0);
          generateOperation(STO, base, 0, item -> addr);
        }
break;
case 53:
#line 354 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-4].ident);
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 3, 0);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(GET, 0, 0, 0);
          generateOperation(STO, base, 3, item -> addr);
        }
break;
case 54:
#line 368 "parser.y"
{
          generateOperation(PUT, 0, 0, 0);
        }
break;
case 56:
#line 379 "parser.y"
{
          generateOperation(OPR, 0, 0, 5);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 57:
#line 384 "parser.y"
{
          generateOperation(OPR, 0, 0, 6);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 58:
#line 389 "parser.y"
{
          generateOperation(OPR, 0, 0, 7);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 59:
#line 394 "parser.y"
{
          generateOperation(OPR, 0, 0, 8);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 60:
#line 399 "parser.y"
{
          generateOperation(OPR, 0, 0, 9);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 61:
#line 404 "parser.y"
{
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 64:
#line 414 "parser.y"
{
          generateOperation(OPR, 0, 0, 0);
        }
break;
case 65:
#line 418 "parser.y"
{
          generateOperation(OPR, 0, 0, 1);
        }
break;
case 66:
#line 422 "parser.y"
{
          generateOperation(OPR, 0, 0, 2);
        }
break;
case 68:
#line 430 "parser.y"
{
          generateOperation(OPR, 0 ,0 ,3);
        }
break;
case 69:
#line 434 "parser.y"
{
          generateOperation(OPR, 0 ,0 ,4);
        }
break;
case 72:
#line 443 "parser.y"
{
          generateOperation(LIT,0,0,yyvsp[0].num);
        }
break;
case 74:
#line 448 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-4].ident);
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }
break;
case 75:
#line 458 "parser.y"
{
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 5);
        }
break;
case 76:
#line 466 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[0].ident);
          if(item -> kind == func){
            generateOperation(INT, 0, 0, 1);
            generateOperation(CAL, 0, 0, item -> addr);
          }else{
            REG base = item -> kind == local ? 1 : 0;
            generateOperation(LOD, base, 0, item -> addr);
          }
        }
break;
case 77:
#line 481 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-3].ident);
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 4, 0);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(LOD, base, 4, item -> addr); 
        }
break;
case 78:
#line 494 "parser.y"
{
          ++procVariableNum;
        }
break;
case 79:
#line 498 "parser.y"
{
          ++procVariableNum;
        }
break;
case 80:
#line 505 "parser.y"
{
          addItemToStack(yyvsp[0].ident, kind, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
break;
case 81:
#line 512 "parser.y"
{
          addItemToStack(yyvsp[0].ident, kind, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
break;
case 82:
#line 519 "parser.y"
{
          addItemToStack(yyvsp[-5].ident, kind, yyvsp[-3].num, yyvsp[-1].num - yyvsp[-3].num);
          printf("variable declaration\n");
          printAllItems();
          int i;
          for( i = yyvsp[-3].num; i < yyvsp[-1].num; ++i)
            generateOperation(LIT,0,0,0);
        }
break;
case 83:
#line 528 "parser.y"
{
          addItemToStack(yyvsp[-5].ident, kind, yyvsp[-3].num, yyvsp[-1].num - yyvsp[-3].num);
          printf("variable declaration\n");
          printAllItems();
          int i;
          for( i = yyvsp[-3].num; i < yyvsp[-1].num; ++i)
            generateOperation(LIT,0,0,0);
        }
break;
#line 1012 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
