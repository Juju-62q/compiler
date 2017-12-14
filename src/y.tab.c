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

#line 19 "parser.y"
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#line 44 "y.tab.c"
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
    0,    1,    2,    2,    5,    5,    6,    3,    3,    8,
    8,    9,   10,   11,   12,   13,   13,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   14,   15,   25,   26,
   26,   27,   16,   17,   18,   28,   20,   21,   22,   19,
   24,   24,   24,   24,   24,   24,   23,   23,   23,   23,
   23,   29,   29,   29,   30,   30,   30,   31,   32,   32,
    7,    7,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    2,    0,    3,
    1,    1,    4,    1,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    7,    0,    2,
    0,    0,    4,    8,    1,    1,    3,    4,    4,    0,
    3,    3,    3,    3,    3,    3,    1,    2,    2,    3,
    3,    1,    3,    3,    1,    1,    3,    1,    1,    3,
    1,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   61,
    0,    1,    0,    0,    0,   11,   12,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    2,   18,
   19,   20,   21,   22,   23,   24,   25,   26,   35,    0,
    5,   62,    0,   17,    0,    0,    0,    0,    0,   56,
   58,    0,    0,    0,   52,   55,    0,    0,    0,    0,
   10,    0,   13,   37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   15,   16,    0,   57,    0,    0,
    0,    0,    0,    0,    0,    0,   29,   53,   54,   38,
   33,   39,    0,    0,    0,    0,   32,    0,   30,   28,
   34,
};
short yydgoto[] = {                                       2,
    6,    7,   14,   29,    8,    9,   11,   15,   16,   17,
   21,   63,   45,   30,   31,   32,   33,   34,   35,   36,
   37,   38,   52,   53,  104,  107,  110,   39,   54,   55,
   56,    0,
};
short yysindex[] = {                                   -263,
 -286,    0, -278, -223, -262, -242, -202, -214,    0,    0,
 -190,    0, -194, -156, -186,    0,    0, -223, -177,    0,
 -151, -156, -162, -160, -179, -160, -131, -147,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -202,
    0,    0, -223,    0, -258, -136, -274, -274, -160,    0,
    0,  -14, -109, -260,    0,    0, -134,  -94, -160, -160,
    0, -156,    0,    0, -156, -160, -260, -260, -175, -274,
 -274, -160, -160, -160, -160, -160, -160, -156, -274, -274,
 -105, -156, -119, -148,    0,    0,  -82,    0, -260, -260,
 -148, -148, -148, -148, -148, -148,    0,    0,    0,    0,
    0,    0, -160,  -78, -155, -156,    0, -156,    0,    0,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -213,    0,    0, -200,    0,    0,    0,
 -102,    0,    0, -108,    0,    0,    0, -226,    0,    0,
    0, -246,    0,    0,    0,    0,    0, -255,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -184,
    0,    0, -182,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -138,    0,    0,    0,    0,    0,    0,
    0, -186,    0,    0, -246,    0, -111,  -84,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -238,    0,    0,
    0, -238,    0, -164,    0,    0,    0,    0,  -57,  -30,
 -251, -245, -192, -107,  -86,  -80,    0,    0,    0,    0,
    0,    0,    0, -254,    0, -238,    0, -238,    0,    0,
    0,
};
short yygindex[] = {                                      0,
    0,  156,    0,  -22,    0,  187,    0,    0,  166,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -48,  182,    0,    0,    0,    0,   22,   49,
    0,    0,
};
#define YYTABLESIZE 268
short yytable[] = {                                      44,
   69,   64,    1,   36,   36,   31,   41,    3,   49,    4,
   83,   84,   42,   40,   79,   80,   41,   87,   50,   51,
   40,   40,   42,   91,   92,   93,   94,   95,   96,   65,
    4,   10,   36,   31,    4,   36,   31,    4,    4,   85,
    4,   40,   86,    3,    4,    4,    5,    3,   12,   40,
    3,    3,   40,    3,  105,   97,    9,    3,    3,  101,
    9,    4,   13,    9,    4,   44,    9,    4,   67,   68,
    9,    9,    8,   18,    3,   44,    8,    3,    3,    8,
    3,    3,    8,  109,    3,  111,    8,    8,    3,    3,
    9,   89,   90,    9,   27,   27,   19,   70,   71,   20,
   22,   40,  108,   57,   23,    3,    8,   24,   88,    8,
   25,    3,   47,   48,   26,   27,   42,   70,   71,   47,
   47,   47,   49,   27,   70,   71,   27,   98,   99,   47,
   47,   46,   50,   51,   47,   47,   43,   28,   47,   47,
   47,   47,   47,   47,   60,   47,   48,   48,   48,   47,
   43,   59,   47,   70,   71,   66,   48,   48,   78,   81,
   43,   48,   48,   82,  102,   48,   48,   48,   48,   48,
   48,   46,   48,   49,   49,   49,   48,   45,  100,   48,
  106,   46,   40,   49,   49,    7,  103,   45,   49,   49,
   70,   71,   49,   49,   49,   49,   49,   49,   62,   49,
   50,   50,   50,   49,   41,   61,   49,   58,    0,    0,
   50,   50,    0,    0,    0,   50,   50,    0,    0,   50,
   50,   50,   50,   50,   50,    0,   50,   51,   51,   51,
   50,    0,    0,   50,    0,    0,    0,   51,   51,    0,
    0,    0,   51,   51,    0,    0,   51,   51,   51,   51,
   51,   51,    0,   51,    0,    0,    0,   51,   70,   71,
   51,    0,   72,   73,   74,   75,   76,   77,
};
short yycheck[] = {                                      22,
   49,  260,  266,  259,  260,  260,  258,  294,  283,  288,
   59,   60,  258,  260,  275,  276,  268,   66,  293,  294,
  259,  260,  268,   72,   73,   74,   75,   76,   77,  288,
  257,  294,  288,  288,  261,  291,  291,  264,  265,   62,
  267,  288,   65,  257,  271,  272,  270,  261,  291,  288,
  264,  265,  291,  267,  103,   78,  257,  271,  272,   82,
  261,  288,  265,  264,  291,  258,  267,  294,   47,   48,
  271,  272,  257,  288,  257,  268,  261,  291,  261,  264,
  294,  264,  267,  106,  267,  108,  271,  272,  271,  272,
  291,   70,   71,  294,  259,  260,  287,  273,  274,  294,
  257,  288,  258,  283,  261,  288,  291,  264,  284,  294,
  267,  294,  273,  274,  271,  272,  294,  273,  274,  258,
  259,  260,  283,  288,  273,  274,  291,   79,   80,  268,
  269,  294,  293,  294,  273,  274,  288,  294,  277,  278,
  279,  280,  281,  282,  292,  284,  258,  259,  260,  288,
  258,  283,  291,  273,  274,  292,  268,  269,  268,  294,
  268,  273,  274,  258,  284,  277,  278,  279,  280,  281,
  282,  258,  284,  258,  259,  260,  288,  258,  284,  291,
  259,  268,  291,  268,  269,  288,  269,  268,  273,  274,
  273,  274,  277,  278,  279,  280,  281,  282,   43,  284,
  258,  259,  260,  288,   18,   40,  291,   26,   -1,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,  258,  259,  260,
  288,   -1,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,   -1,  288,  273,  274,
  291,   -1,  277,  278,  279,  280,  281,  282,
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
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
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
"while_statement : WHILE condition DO statement",
"for_statement : FOR IDENT ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
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
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
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
#line 305 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
  fprintf(stderr, "%d %s\n", yylineno, yytext);
}
#line 340 "y.tab.c"
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
#line 43 "parser.y"
{
          if(!procFlag) setUndefinedAddress(getStartPoint());
          printf("program end\n");
          printAllItems();
        }
break;
case 13:
#line 84 "parser.y"
{
          kind = global;
          removeLocalVariable();
          printf("removeing Items\n");
          printAllItems();
        }
break;
case 14:
#line 94 "parser.y"
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
case 15:
#line 108 "parser.y"
{
          generateOperation(RTN, 0, 0, 0);
        }
break;
case 27:
#line 132 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-2].ident);
          generateOperation(STO, 0, 0, item -> addr);
        }
break;
case 29:
#line 145 "parser.y"
{
          setUndefinedAddress(getOpCount());
          generateOperation(JMP, 0, 0, 0);
        }
break;
case 32:
#line 157 "parser.y"
{
          setUndefinedAddress(getOpCount());
        }
break;
case 33:
#line 163 "parser.y"
{
          setUndefinedAddress(getOpCount());
        }
break;
case 34:
#line 170 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-6].ident);
        }
break;
case 36:
#line 182 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[0].ident);
          generateOperation(CAL, 0, 0, item -> addr);
        }
break;
case 38:
#line 195 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[-1].ident);
        }
break;
case 41:
#line 211 "parser.y"
{
          generateOperation(OPR, 0, 0, 6);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 42:
#line 216 "parser.y"
{
          generateOperation(OPR, 0, 0, 5);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 43:
#line 221 "parser.y"
{
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 44:
#line 226 "parser.y"
{
          generateOperation(OPR, 0, 0, 9);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 45:
#line 231 "parser.y"
{
          generateOperation(OPR, 0, 0, 8);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 46:
#line 236 "parser.y"
{
          generateOperation(OPR, 0, 0, 7);
          generateOperation(JPC, 0, 0, 0);
        }
break;
case 49:
#line 246 "parser.y"
{
          generateOperation(OPR, 0, 0, 0);
        }
break;
case 50:
#line 250 "parser.y"
{
          generateOperation(OPR, 0, 0, 1);
        }
break;
case 51:
#line 254 "parser.y"
{
          generateOperation(OPR, 0, 0, 2);
        }
break;
case 56:
#line 268 "parser.y"
{
          generateOperation(LIT,0,0,yyvsp[0].num);
        }
break;
case 58:
#line 276 "parser.y"
{
          tableItem *item;
          item = searchItem(yyvsp[0].ident);
          generateOperation(LOD, 0, 0, item -> addr);
        }
break;
case 61:
#line 290 "parser.y"
{
          addItemToStack(yyvsp[0].ident,kind);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
break;
case 62:
#line 297 "parser.y"
{
          addItemToStack(yyvsp[0].ident,kind);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
break;
#line 698 "y.tab.c"
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
