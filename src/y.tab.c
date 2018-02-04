/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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
static int forwardingFlag = func;


#line 87 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SBEGIN = 258,
    DO = 259,
    ELSE = 260,
    SEND = 261,
    FOR = 262,
    FORWARD = 263,
    FUNCTION = 264,
    IF = 265,
    PROCEDURE = 266,
    PROGRAM = 267,
    READ = 268,
    THEN = 269,
    TO = 270,
    VAR = 271,
    WHILE = 272,
    WRITE = 273,
    PLUS = 274,
    MINUS = 275,
    MULT = 276,
    DIV = 277,
    EQ = 278,
    NEQ = 279,
    LE = 280,
    LT = 281,
    GE = 282,
    GT = 283,
    LPAREN = 284,
    RPAREN = 285,
    LBRACKET = 286,
    RBRACKET = 287,
    COMMA = 288,
    SEMICOLON = 289,
    COLON = 290,
    INTERVAL = 291,
    PERIOD = 292,
    ASSIGN = 293,
    NUMBER = 294,
    IDENT = 295
  };
#endif
/* Tokens.  */
#define SBEGIN 258
#define DO 259
#define ELSE 260
#define SEND 261
#define FOR 262
#define FORWARD 263
#define FUNCTION 264
#define IF 265
#define PROCEDURE 266
#define PROGRAM 267
#define READ 268
#define THEN 269
#define TO 270
#define VAR 271
#define WHILE 272
#define WRITE 273
#define PLUS 274
#define MINUS 275
#define MULT 276
#define DIV 277
#define EQ 278
#define NEQ 279
#define LE 280
#define LT 281
#define GE 282
#define GT 283
#define LPAREN 284
#define RPAREN 285
#define LBRACKET 286
#define RBRACKET 287
#define COMMA 288
#define SEMICOLON 289
#define COLON 290
#define INTERVAL 291
#define PERIOD 292
#define ASSIGN 293
#define NUMBER 294
#define IDENT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:355  */

    int num;
    char ident[MAXLENGTH+1];

#line 212 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    57,    60,    62,    66,    67,    71,    75,
      76,    80,    81,    85,    86,   114,   122,   135,   143,   156,
     163,   172,   184,   199,   203,   204,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   220,   231,   241,   252,   257,
     264,   265,   270,   277,   287,   293,   313,   328,   341,   348,
     358,   365,   372,   376,   384,   398,   404,   409,   414,   419,
     424,   429,   434,   442,   443,   444,   448,   452,   459,   460,
     464,   471,   472,   473,   477,   478,   489,   496,   511,   524,
     528,   535,   542,   549,   558
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SBEGIN", "DO", "ELSE", "SEND", "FOR",
  "FORWARD", "FUNCTION", "IF", "PROCEDURE", "PROGRAM", "READ", "THEN",
  "TO", "VAR", "WHILE", "WRITE", "PLUS", "MINUS", "MULT", "DIV", "EQ",
  "NEQ", "LE", "LT", "GE", "GT", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "COMMA", "SEMICOLON", "COLON", "INTERVAL", "PERIOD",
  "ASSIGN", "NUMBER", "IDENT", "$accept", "program", "outblock",
  "var_decl_part", "var_decl_list", "var_decl", "subprog_decl_part",
  "subprog_decl_list", "subprog_decl", "proc_decl", "function_decl",
  "proc_variables", "proc_var_list", "proc_name", "inblock",
  "statement_list", "statement", "assignment_statement", "array_assign",
  "if_statement", "set_address_if", "else_statement", "set_address_else",
  "while_statement", "set_while_loop", "for_statement", "for_initial",
  "for_loop", "proc_call_statement", "add_stack_proc", "proc_call_name",
  "block_statement", "read_statement", "write_statement", "null_statement",
  "condition", "expression", "term", "factor", "add_stack_func",
  "var_or_function", "var_array", "arg_list", "id_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -52

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,   -25,    19,    26,   -55,    30,    38,    -3,    79,    33,
     -55,    39,    49,   -55,    58,    58,     0,    80,   -55,   -55,
     -55,    30,    57,    73,   -55,   -20,    51,     0,    76,    10,
      88,   -55,    89,    27,   -55,   -55,    82,   -55,   -55,   -55,
     104,   -55,    92,   -55,   -55,   -55,   -55,    79,   -55,    86,
      93,    87,    30,    87,    30,     2,   -55,    85,    37,    37,
      10,   -55,    62,   -55,   112,    81,    20,   -55,   -55,   -55,
      90,    10,    10,    10,    10,    10,    10,     0,    99,   -55,
      94,    95,   -55,   101,    96,     0,   -55,   102,   -55,   -55,
       0,    10,    20,    20,    18,    10,   106,     0,    37,    37,
      10,    10,    10,    10,    10,    10,    37,    37,    64,   132,
      53,     1,    83,    83,    12,   -55,    10,   107,   105,   108,
      98,   -55,   109,   -55,    83,   -55,     3,    10,   -55,    20,
      20,    83,    83,    83,    83,    83,    83,   -55,   -55,   -55,
      10,     0,   -55,   -55,   -55,    83,    54,   -55,   110,    30,
     -55,    30,   -55,    56,   135,    43,   -55,   -55,    10,   113,
     -55,   -55,   -55,     0,   -55,   114,    83,   -55,   -55,   -55,
     -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     0,    10,     0,
       7,    81,     8,     2,     0,     0,    56,     0,    12,    13,
      14,     5,     0,     0,    22,     0,     0,    56,     0,     0,
       0,    44,     0,    51,     3,    26,     0,    27,    28,    29,
       0,    30,    49,    32,    33,    34,    31,     9,     6,     0,
      82,     0,     4,     0,     4,     0,    25,     0,     0,     0,
       0,    73,    77,    76,     0,     0,    63,    68,    71,    72,
       0,     0,     0,     0,     0,     0,     0,    56,     0,    11,
       0,     0,    20,     0,    19,    56,    17,     0,    15,    52,
      56,     0,    64,    65,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36,     0,    45,     0,     0,     0,     0,
       0,    23,     0,    24,    46,    74,     0,     0,    39,    66,
      67,    57,    58,    60,    59,    62,    61,    69,    70,    53,
       0,    56,    55,    37,    47,    79,     0,    83,     0,     4,
      21,     4,    78,     0,    41,     0,    43,    48,     0,     0,
      18,    16,    75,    56,    42,     0,    80,    84,    40,    38,
      54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,   141,   -55,   127,   -55,   -55,   103,   -55,
     -55,   100,   -55,   136,   -52,   -55,   -26,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -16,   -55,   -55,   -55,   -55,    84,   -48,   -54,     5,   -55,
     -55,   -55,    25,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    85,     9,    10,    16,    17,    18,    19,
      20,    83,    84,    25,    86,    55,    34,    35,    36,    37,
     154,   164,   169,    38,    71,    39,    40,    77,    41,    78,
      63,    43,    44,    45,    46,    64,    65,    66,    67,    96,
      68,    69,   146,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    56,    88,    27,    92,    93,     1,    28,    89,    51,
      29,    42,    94,    30,    52,     3,   144,    31,    32,     4,
      98,    99,    98,    99,   110,   111,   112,   113,   114,    58,
      59,    98,    99,   143,    13,   152,    90,    98,    99,    60,
      33,   106,   107,   124,   129,   130,     6,   126,   125,    61,
      62,   115,   131,   132,   133,   134,   135,   136,    73,   121,
       5,    42,    98,    99,   123,    74,    60,    21,   145,    42,
      22,   128,    98,    99,    42,   165,    61,    62,    11,   145,
      53,    42,    23,   142,   157,    54,   162,   158,    14,   158,
      15,   -51,   155,    95,   139,   140,    49,   160,    24,   161,
      98,    99,    98,    99,   100,   101,   102,   103,   104,   105,
     166,   137,   138,    50,    47,   156,    57,    70,    72,    76,
      75,   -50,    80,    91,    81,    42,    97,    82,   116,   120,
     108,   119,   122,   117,   118,   127,   141,   168,   150,   147,
     163,   148,   149,   151,   170,   167,     8,    42,    48,   159,
      79,    26,   153,    87,     0,   109
};

static const yytype_int16 yycheck[] =
{
      16,    27,    54,     3,    58,    59,    12,     7,     6,    29,
      10,    27,    60,    13,    34,    40,     4,    17,    18,     0,
      19,    20,    19,    20,    72,    73,    74,    75,    76,    19,
      20,    19,    20,    32,    37,    32,    34,    19,    20,    29,
      40,    21,    22,    91,    98,    99,    16,    95,    30,    39,
      40,    77,   100,   101,   102,   103,   104,   105,    31,    85,
      34,    77,    19,    20,    90,    38,    29,    34,   116,    85,
      31,    97,    19,    20,    90,    32,    39,    40,    40,   127,
      29,    97,    33,    30,    30,    34,    30,    33,     9,    33,
      11,    29,   140,    31,    30,    31,    39,   149,    40,   151,
      19,    20,    19,    20,    23,    24,    25,    26,    27,    28,
     158,   106,   107,    40,    34,   141,    40,    29,    29,    15,
      38,    29,    36,    38,    31,   141,    14,    40,    29,    33,
      40,    30,    30,    39,    39,    29,     4,   163,    40,    32,
       5,    36,    34,    34,    30,    32,     5,   163,    21,    39,
      47,    15,   127,    53,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    42,    40,     0,    34,    16,    43,    44,    45,
      46,    40,    84,    37,     9,    11,    47,    48,    49,    50,
      51,    34,    31,    33,    40,    54,    54,     3,     7,    10,
      13,    17,    18,    40,    57,    58,    59,    60,    64,    66,
      67,    69,    71,    72,    73,    74,    75,    34,    46,    39,
      40,    29,    34,    29,    34,    56,    57,    40,    19,    20,
      29,    39,    40,    71,    76,    77,    78,    79,    81,    82,
      29,    65,    29,    31,    38,    38,    15,    68,    70,    49,
      36,    31,    40,    52,    53,    44,    55,    52,    55,     6,
      34,    38,    78,    78,    77,    31,    80,    14,    19,    20,
      23,    24,    25,    26,    27,    28,    21,    22,    40,    76,
      77,    77,    77,    77,    77,    57,    29,    39,    39,    30,
      33,    57,    30,    57,    77,    30,    77,    29,    57,    78,
      78,    77,    77,    77,    77,    77,    77,    79,    79,    30,
      31,     4,    30,    32,     4,    77,    83,    32,    36,    34,
      40,    34,    32,    83,    61,    77,    57,    30,    33,    39,
      55,    55,    30,     5,    62,    32,    77,    32,    57,    63,
      30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    59,    60,    61,
      62,    62,    63,    64,    65,    66,    67,    68,    69,    69,
      70,    71,    72,    73,    73,    74,    75,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    80,    81,    82,    83,
      83,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     3,     1,     2,     2,
       0,     3,     1,     1,     1,     4,     7,     4,     7,     1,
       1,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     7,     0,
       2,     0,     0,     5,     0,     3,     4,     3,     5,     1,
       0,     1,     3,     4,     7,     4,     0,     3,     3,     3,
       3,     3,     3,     1,     2,     2,     3,     3,     1,     3,
       3,     1,     1,     1,     3,     5,     0,     1,     4,     1,
       3,     1,     3,     6,     8
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 49 "parser.y" /* yacc.c:1646  */
    {
          if(!procFlag) setUndefinedAddress(getStartPoint());
          printf("program end\n");
          printAllItems();
        }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "parser.y" /* yacc.c:1646  */
    {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 123 "parser.y" /* yacc.c:1646  */
    {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(INT, 0, 0, - procVariableNum);
          generateOperation(RTN, 0, 0, 0);
          procVariableNum = 0;
        }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 136 "parser.y" /* yacc.c:1646  */
    {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(RTN, 0, 0, 0);
        }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 144 "parser.y" /* yacc.c:1646  */
    {
          kind = global;
          removeLocalVariable();
          printf("removing Items\n");
          printAllItems();
          generateOperation(INT, 0, 0, - procVariableNum);
          generateOperation(RTN, 0, 0, 0);
          procVariableNum = 0;
        }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 157 "parser.y" /* yacc.c:1646  */
    { 
          if(forwardingFlag != forward)
            generateOperation(INT, 0, 0, procVariableNum);
        }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "parser.y" /* yacc.c:1646  */
    {
          if(forwardingFlag != forward){
            addItemToStack((yyvsp[0].ident), local , 0, 1);
            printf("variable declaration\n");
            printAllItems();
            ++procVariableNum;
          }
        }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 173 "parser.y" /* yacc.c:1646  */
    {
          if(forwardingFlag != forward){
            addItemToStack((yyvsp[0].ident), local, 0, 1);
            printf("variable declaration\n");
            printAllItems();
            ++procVariableNum;
          }
        }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "parser.y" /* yacc.c:1646  */
    {
          kind = local;
          printf("procedure declaration\n");
          printAllItems();
          if(procFlag){
            procFlag = 0;
            generateOperation(JMP,0,0,0);
          }
          addItemToStack((yyvsp[0].ident), func, forwardingFlag , 0);
          forwardingFlag = func;
        }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 221 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[-2].ident));
          if (item -> kind == func){
            generateOperation(STO, 1, 0, -5);
          }else{
            REG base = item -> kind == local ? 1 : 0;
            generateOperation(STO, base, 0, item -> addr);
          }
        }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[-2].ident));
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(STO, base, 3, item -> addr);
        }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 242 "parser.y" /* yacc.c:1646  */
    {
          strcpy((yyval.ident), (yyvsp[-3].ident));
          tableItem *item;
          item = searchItem((yyvsp[-3].ident));
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 3, 0);
        }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 257 "parser.y" /* yacc.c:1646  */
    {
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
        }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 270 "parser.y" /* yacc.c:1646  */
    {
          setUndefinedAddress(getOpCount());
        }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 278 "parser.y" /* yacc.c:1646  */
    {
          setUndefinedAddress(getOpCount() + 1);
          generateOperation(JMP, 0, 0, 0);
          setUndefinedAddress(getLoopPoint());
        }
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 287 "parser.y" /* yacc.c:1646  */
    {
          setLoopPoint();
        }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 294 "parser.y" /* yacc.c:1646  */
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
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 314 "parser.y" /* yacc.c:1646  */
    {
          //initiallize
          tableItem *item;
          item = searchItem((yyvsp[-2].ident));
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(STO, base, 0, item -> addr);
          setLoopPoint();

          forLoopVar = (char*)malloc(strlen((yyvsp[-2].ident)));
          sprintf(forLoopVar, "%s", (yyvsp[-2].ident));
        }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 329 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item = searchItem(forLoopVar);
          REG base = item -> kind == local ? 1 : 0;

          //check loop condition
          generateOperation(LOD, base, 0, item -> addr);
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 342 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[-4].ident));
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 349 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[0].ident));
          generateOperation(CAL, 0, 0, item -> addr);
        }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 358 "parser.y" /* yacc.c:1646  */
    {
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 4);
        }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 366 "parser.y" /* yacc.c:1646  */
    {
          strcpy((yyval.ident), (yyvsp[0].ident));
        }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 377 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[-1].ident));
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(GET, 0, 0, 0);
          generateOperation(STO, base, 0, item -> addr);
        }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 385 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[-4].ident));
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 3, 0);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(GET, 0, 0, 0);
          generateOperation(STO, base, 3, item -> addr);
        }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 399 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(PUT, 0, 0, 0);
        }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 410 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 5);
          generateOperation(JPC, 0, 0, 0);
        }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 415 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 6);
          generateOperation(JPC, 0, 0, 0);
        }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 420 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 7);
          generateOperation(JPC, 0, 0, 0);
        }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 425 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 8);
          generateOperation(JPC, 0, 0, 0);
        }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 430 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 9);
          generateOperation(JPC, 0, 0, 0);
        }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 435 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 10);
          generateOperation(JPC, 0, 0, 0);
        }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 445 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 0);
        }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 449 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 1);
        }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 453 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0, 0, 2);
        }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 461 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0 ,0 ,3);
        }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 465 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(OPR, 0 ,0 ,4);
        }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 474 "parser.y" /* yacc.c:1646  */
    {
          generateOperation(LIT,0,0,(yyvsp[0].num));
        }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 479 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[-4].ident));
          generateOperation(INT, 0, 0, -4 - procVariableNum);
          generateOperation(CAL, 0, 0, item -> addr);
        }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 489 "parser.y" /* yacc.c:1646  */
    {
          procVariableNum = 0;
          generateOperation(INT, 0, 0, 5);
        }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 497 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[0].ident));
          if(item -> kind == func){
            generateOperation(INT, 0, 0, 1);
            generateOperation(CAL, 0, 0, item -> addr);
          }else{
            REG base = item -> kind == local ? 1 : 0;
            generateOperation(LOD, base, 0, item -> addr);
          }
        }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 512 "parser.y" /* yacc.c:1646  */
    {
          tableItem *item;
          item = searchItem((yyvsp[-3].ident));
          generateOperation(LIT, 0, 0, item -> arrayTop);
          generateOperation(OPR, 0, 0, 2);
          generateOperation(MVX, 0, 4, 0);
          REG base = item -> kind == local ? 1 : 0;
          generateOperation(LOD, base, 4, item -> addr); 
        }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 525 "parser.y" /* yacc.c:1646  */
    {
          ++procVariableNum;
        }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 529 "parser.y" /* yacc.c:1646  */
    {
          ++procVariableNum;
        }
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 536 "parser.y" /* yacc.c:1646  */
    {
          addItemToStack((yyvsp[0].ident), kind, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 543 "parser.y" /* yacc.c:1646  */
    {
          addItemToStack((yyvsp[0].ident), kind, 0, 1);
          printf("variable declaration\n");
          printAllItems();
          generateOperation(LIT,0,0,0);
        }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 550 "parser.y" /* yacc.c:1646  */
    {
          addItemToStack((yyvsp[-5].ident), kind, (yyvsp[-3].num), (yyvsp[-1].num) - (yyvsp[-3].num));
          printf("variable declaration\n");
          printAllItems();
          int i;
          for( i = (yyvsp[-3].num); i < (yyvsp[-1].num); ++i)
            generateOperation(LIT,0,0,0);
        }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 559 "parser.y" /* yacc.c:1646  */
    {
          addItemToStack((yyvsp[-5].ident), kind, (yyvsp[-3].num), (yyvsp[-1].num) - (yyvsp[-3].num));
          printf("variable declaration\n");
          printAllItems();
          int i;
          for( i = (yyvsp[-3].num); i < (yyvsp[-1].num); ++i)
            generateOperation(LIT,0,0,0);
        }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1954 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 569 "parser.y" /* yacc.c:1906  */
 
yyerror(char *s)
{
  fprintf(stderr, "%s\n", s);
  fprintf(stderr, "%d %s\n", yylineno, yytext);
}
