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
    0,    3,    4,    4,    7,    7,    8,    5,    5,   10,
   10,   11,   11,   12,   12,   13,   13,   16,   17,   17,
   14,   15,   18,   18,    6,    6,    6,    6,    6,    6,
    6,    6,    6,   19,   20,   29,   30,   30,   31,   21,
   32,   22,   33,   34,    2,    2,   35,    1,   24,   25,
   26,   23,   28,   28,   28,   28,   28,   28,   27,   27,
   27,   27,   27,   37,   37,   37,   38,   38,   38,   38,
   40,   39,   36,   36,    9,    9,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    2,    0,    3,
    1,    1,    1,    4,    7,    4,    7,    1,    1,    3,
    1,    2,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    3,    7,    0,    2,    0,    0,    5,
    0,    3,    4,    3,    5,    1,    0,    1,    3,    4,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    2,    3,    3,    1,    3,    3,    1,    1,    3,    5,
    0,    1,    1,    3,    1,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   75,
    0,    1,    0,    0,    0,    0,   11,   12,   13,    0,
    0,   21,    0,    0,    0,    0,    0,    0,   41,    0,
    0,    0,   29,    2,   25,   26,   27,   28,   30,   31,
   32,   33,    0,    0,    5,   76,    0,    0,    0,    0,
   24,    0,    0,    0,    0,    0,   68,    0,   71,    0,
    0,    0,   64,   67,    0,    0,    0,    0,    0,    0,
    0,   10,   19,    0,    0,    0,   16,    0,   14,   49,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   42,    0,    0,   22,    0,   23,    0,
   69,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,   65,   66,   50,    0,   51,    0,    0,   44,    0,
   20,    0,    0,    0,   40,   45,    0,   17,   15,   70,
    0,   39,    0,   37,   35,
};
short yydgoto[] = {                                       2,
   59,   33,    6,   76,   15,   34,    8,    9,   11,   16,
   17,   18,   19,   23,   77,   74,   75,   52,   35,   36,
   37,   38,   39,   40,   41,   42,   60,   61,  134,  142,
  145,   66,   43,   71,   69,  128,   62,   63,   64,   86,
};
short yysindex[] = {                                   -261,
 -280,    0, -266, -244, -230, -223, -117, -214,    0,    0,
 -211,    0, -187, -187, -128, -199,    0,    0,    0, -244,
 -179,    0, -143, -133, -128, -173,  -46, -190,    0, -134,
 -136,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -86, -117,    0,    0, -104, -244, -104, -244,
    0, -253, -101, -274, -274,  -46,    0,    0,    0,   80,
  -75, -111,    0,    0,  -96,  -46,  -46,  -46,  -84,  -46,
 -128,    0,    0,  -81,  -87, -128,    0,  -80,    0,    0,
 -128,  -46, -111, -111, -168,  -70, -274, -274,  -46,  -46,
  -46,  -46,  -46,  -46, -128, -274, -274,  -73,  -44, -161,
 -115,  -46, -245,    0,  -71,  -69,    0,  -64,    0, -115,
    0,  -46, -111, -111, -115, -115, -115, -115, -115, -115,
    0,    0,    0,    0, -128,    0, -115, -281,    0, -244,
    0, -244, -238,  -30,    0,    0,  -46,    0,    0,    0,
 -128,    0, -115,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -169,    0,    0, -194,    0,    0,    0,
  -56,    0,    0,    0,  -58,    0,    0,    0,    0, -240,
    0,    0,    0,    0, -252,    0,    0,    0,    0,    0,
  -99,  -65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -153,    0,    0,    0, -137,    0, -137,
    0,    0,    0,    0,    0,    0,    0, -106,    0,    0,
    0,  -72,    0,    0,    0,    0,    0,    0,    0,    0,
 -226,    0,    0,    0,  -50,  -37,    0,    0,    0,    0,
 -252,    0,  -38,   -4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -226,    0,    0,    0,    0,    0,
 -201,    0,    0,    0,    0,    0,    0,    0,    0,  -31,
    0,    0,   30,   64, -215, -189, -177, -159, -126, -121,
    0,    0,    0,    0, -226,    0, -212,    0,    0, -137,
    0, -137,    0, -205,    0,    0,    0,    0,    0,    0,
 -226,    0, -156,    0,    0,
};
short yygindex[] = {                                      0,
  -15,    0,    0,  241,    0,  -24,    0,  232,    0,    0,
  213,    0,    0,  244,  -48,  210,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -52,  194,    0,    0,
    0,    0,    0,    0,    0,  149,  -43,   83,    0,    0,
};
#define YYTABLESIZE 362
short yytable[] = {                                      32,
   51,   79,  136,   85,    1,  137,   80,   52,   56,   32,
   83,   84,  129,    3,  100,  101,    4,  103,   57,   58,
    4,    4,    4,    4,    4,    5,    4,   87,   88,  110,
    4,    4,   52,   52,   81,   52,  115,  116,  117,  118,
  119,  120,   53,  113,  114,  140,  104,    4,  137,  127,
    4,  107,   53,    4,   38,   32,  109,   34,   34,  127,
   32,   52,    9,   10,   52,   32,    9,   12,   54,    9,
  121,   73,    9,   20,   73,   21,    9,    9,   54,   32,
   56,  138,   38,  139,  143,   38,   34,    3,   44,   34,
   56,    3,   65,    3,    3,    3,    9,    3,   55,    9,
  135,    3,    3,    8,   87,   88,   22,    8,   55,   32,
    8,   87,   88,    8,   46,  111,  144,    8,    8,    3,
   53,    3,  126,    3,    3,   32,    3,   74,   25,    3,
   74,   58,   26,    3,    3,   27,   57,    8,   28,   47,
    8,   58,   29,   30,   48,   13,   57,   14,   67,   49,
    3,   72,   72,   72,   50,   68,    3,   87,   88,   48,
   48,   72,   72,   96,   97,   31,   72,   72,   72,   72,
   72,   72,   72,   72,   72,   72,   48,   72,  122,  123,
   72,   72,   70,   48,   72,   59,   59,   59,   48,   73,
   82,   48,   95,   46,   46,   59,   59,   98,  102,  106,
   59,   59,  105,  108,   59,   59,   59,   59,   59,   59,
  124,   59,  112,  125,   59,   59,  130,   47,   59,   60,
   60,   60,   46,  132,  131,   46,   54,   55,  141,   60,
   60,    7,   52,   18,   60,   60,   56,   43,   60,   60,
   60,   60,   60,   60,    7,   60,   57,   58,   60,   60,
   52,   45,   60,   61,   61,   61,   72,   24,   78,   99,
  133,    0,    0,   61,   61,    0,    0,    0,   61,   61,
    0,    0,   61,   61,   61,   61,   61,   61,    0,   61,
    0,    0,   61,   61,    0,    0,   61,   62,   62,   62,
    0,    0,    0,    0,    0,    0,    0,   62,   62,    0,
    0,    0,   62,   62,    0,    0,   62,   62,   62,   62,
   62,   62,    0,   62,    0,    0,   62,   62,    0,    0,
   62,   63,   63,   63,    0,    0,    0,    0,    0,    0,
    0,   63,   63,    0,    0,    0,   63,   63,    0,    0,
   63,   63,   63,   63,   63,   63,    0,   63,    0,    0,
   63,   63,   87,   88,   63,    0,   89,   90,   91,   92,
   93,   94,
};
short yycheck[] = {                                      15,
   25,   50,  284,   56,  266,  287,  260,  260,  283,   25,
   54,   55,  258,  294,   67,   68,  257,   70,  293,  294,
  261,  288,  263,  264,  265,  270,  267,  273,  274,   82,
  271,  272,  259,  260,  288,  288,   89,   90,   91,   92,
   93,   94,  258,   87,   88,  284,   71,  288,  287,  102,
  291,   76,  268,  294,  260,   71,   81,  259,  260,  112,
   76,  288,  257,  294,  291,   81,  261,  291,  258,  264,
   95,  284,  267,  288,  287,  287,  271,  272,  268,   95,
  258,  130,  288,  132,  137,  291,  288,  257,  288,  291,
  268,  261,  283,  263,  264,  265,  291,  267,  258,  294,
  125,  271,  272,  257,  273,  274,  294,  261,  268,  125,
  264,  273,  274,  267,  294,  284,  141,  271,  272,  257,
  294,  291,  284,  261,  294,  141,  264,  284,  257,  267,
  287,  258,  261,  271,  272,  264,  258,  291,  267,  283,
  294,  268,  271,  272,  288,  263,  268,  265,  283,  283,
  288,  258,  259,  260,  288,  292,  294,  273,  274,  259,
  260,  268,  269,  275,  276,  294,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  283,  284,   96,   97,
  287,  288,  269,  283,  291,  258,  259,  260,  288,  294,
  292,  291,  268,  259,  260,  268,  269,  294,  283,  287,
  273,  274,  284,  284,  277,  278,  279,  280,  281,  282,
  284,  284,  283,  258,  287,  288,  288,  283,  291,  258,
  259,  260,  288,  288,  294,  291,  273,  274,  259,  268,
  269,  288,  291,  284,  273,  274,  283,  269,  277,  278,
  279,  280,  281,  282,    4,  284,  293,  294,  287,  288,
  288,   20,  291,  258,  259,  260,   44,   14,   49,   66,
  112,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,   -1,  287,  288,   -1,   -1,  291,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,  287,  288,   -1,   -1,
  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,   -1,
  287,  288,  273,  274,  291,   -1,  277,  278,  279,  280,
  281,  282,
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
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"factor : proc_call_name add_stack_func LPAREN arg_list RPAREN",
"add_stack_func :",
"var_or_function : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",
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
#line 476 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
  fprintf(stderr, "%d %s\n", yylineno, yytext);
}
#line 387 "y.tab.c"
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
#line 47 "parser.y"
{
          if(!procFlag) setUndefinedAddress(getStartPoint());
          printf("program end\n");
          printAllItems();
        }
break;
case 14:
#line 89 "parser.y"
{
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
break;
case 15:
#line 97 "parser.y"
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
#line 110 "parser.y"
{
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
break;
case 17:
#line 118 "parser.y"
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
#line 131 "parser.y"
{
          generateOperation(INT, 0, 0, procVariableNum);
        }
break;
case 19:
#line 137 "parser.y"
{
          addItemToStack(yyvsp[0].ident, local);
          printf("variable declaration\n");
          printAllItems();
          ++procVariableNum;
        }
break;
case 20:
#line 144 "parser.y"
{
          addItemToStack(yyvsp[0].ident, local);
          printf("variable declaration\n");
          printAllItems();
          ++procVariableNum;
        }
break;
case 21:
#line 154 "parser.y"
{
          kind = local;
          addItemToStack(yyvsp[0].ident,func);
          printf("procedure declaration\n");
          printAllItems();
          if(procFlag){
            procFlag = 0;
            generateOperation(JMP,0,0,0);
          }
        }
break;
case 34:
#line 189 "parser.y"
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
case 36:
#line 207 "parser.y"
{
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
        }
break;
case 39:
#line 220 "parser.y"
{
          setUndefinedAddress(getOpCount());
        }
break;
case 40:
#line 228 "parser.y"
{
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
          setUndefinedAddress(getLoopPoint());
        }
break;
case 41:
#line 237 "parser.y"
{
          setLoopPoint();
        }
break;
case 42:
#line 244 "parser.y"
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
case 43:
#line 264 "parser.y"
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
case 44:
#line 279 "parser.y"
{
          tableItem *item = searchItem(forLoopVar);
          REG base = item -> kind == local ? 1 : 0;

          /*check loop condition*/
          generateOperation(LOD, base, 0, item -> addr);
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 45:
#line 292 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-4].ident);
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }
break;
case 46:
#line 299 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[0].ident);
          generateOperation(CAL, 0, 0, item -> addr);
        }
break;
case 47:
#line 308 "parser.y"
{
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 4);
        }
break;
case 48:
#line 316 "parser.y"
{
          strcpy(yyval.ident, yyvsp[0].ident);
        }
break;
case 50:
#line 327 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-1].ident);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(GET, 0, 0, 0);
          generateOperation(STO, base, 0, item -> addr);
        }
break;
case 51:
#line 338 "parser.y"
{
          generateOperation(PUT, 0, 0, 0);
        }
break;
case 53:
#line 349 "parser.y"
{
          generateOperation(OPR, 0, 0, 5);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 54:
#line 354 "parser.y"
{
          generateOperation(OPR, 0, 0, 6);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 55:
#line 359 "parser.y"
{
          generateOperation(OPR, 0, 0, 7);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 56:
#line 364 "parser.y"
{
          generateOperation(OPR, 0, 0, 8);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 57:
#line 369 "parser.y"
{
          generateOperation(OPR, 0, 0, 9);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 58:
#line 374 "parser.y"
{
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 61:
#line 384 "parser.y"
{
          generateOperation(OPR, 0, 0, 0);
        }
break;
case 62:
#line 388 "parser.y"
{
          generateOperation(OPR, 0, 0, 1);
        }
break;
case 63:
#line 392 "parser.y"
{
          generateOperation(OPR, 0, 0, 2);
        }
break;
case 65:
#line 400 "parser.y"
{
          generateOperation(OPR, 0 ,0 ,3);
        }
break;
case 66:
#line 404 "parser.y"
{
          generateOperation(OPR, 0 ,0 ,4);
        }
break;
case 68:
#line 412 "parser.y"
{
          generateOperation(LIT,0,0,yyvsp[0].num);
        }
break;
case 70:
#line 417 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-4].ident);
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }
break;
case 71:
#line 427 "parser.y"
{
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 5);
        }
break;
case 72:
#line 435 "parser.y"
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
case 73:
#line 450 "parser.y"
{
          ++procVariableNum;
        }
break;
case 74:
#line 454 "parser.y"
{
          ++procVariableNum;
        }
break;
case 75:
#line 461 "parser.y"
{
          addItemToStack(yyvsp[0].ident,kind);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
break;
case 76:
#line 468 "parser.y"
{
          addItemToStack(yyvsp[0].ident,kind);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
break;
#line 926 "y.tab.c"
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
