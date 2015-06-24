/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pascal.y" /* yacc.c:339  */

	#include "globals.h"
	#include "utils.h"
	#include "scan.h"
	#include "parse.h"
	
	#define YYDEBUG 1
	#define YYSTYPE TreeNode *
	static TreeNode *savedTree;
	static int yylex();

#line 78 "y.tab.c" /* yacc.c:339  */

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
    DOT = 258,
    PROGRAM = 259,
    ID = 260,
    SEMI = 261,
    CONST = 262,
    EQUAL = 263,
    INTEGER = 264,
    REAL = 265,
    CHAR = 266,
    STRING = 267,
    FALSE = 268,
    MAXINT = 269,
    TRUE = 270,
    TYPE = 271,
    ARRAY = 272,
    LB = 273,
    RB = 274,
    OF = 275,
    RECORD = 276,
    END = 277,
    COLON = 278,
    COMMA = 279,
    SBOOLEAN = 280,
    SCHAR = 281,
    SINTEGER = 282,
    SREAL = 283,
    LP = 284,
    RP = 285,
    DOTDOT = 286,
    MINUS = 287,
    VAR = 288,
    FUNCTION = 289,
    PROCEDURE = 290,
    ASSIGN = 291,
    SBEGIN = 292,
    IF = 293,
    THEN = 294,
    ELSE = 295,
    REPEAT = 296,
    UNTIL = 297,
    WHILE = 298,
    DO = 299,
    FOR = 300,
    TO = 301,
    DOWNTO = 302,
    CASE = 303,
    GOTO = 304,
    GE = 305,
    GT = 306,
    LE = 307,
    LT = 308,
    UNEQUAL = 309,
    PLUS = 310,
    OR = 311,
    MUL = 312,
    DIV = 313,
    MOD = 314,
    AND = 315,
    NOT = 316
  };
#endif
/* Tokens.  */
#define DOT 258
#define PROGRAM 259
#define ID 260
#define SEMI 261
#define CONST 262
#define EQUAL 263
#define INTEGER 264
#define REAL 265
#define CHAR 266
#define STRING 267
#define FALSE 268
#define MAXINT 269
#define TRUE 270
#define TYPE 271
#define ARRAY 272
#define LB 273
#define RB 274
#define OF 275
#define RECORD 276
#define END 277
#define COLON 278
#define COMMA 279
#define SBOOLEAN 280
#define SCHAR 281
#define SINTEGER 282
#define SREAL 283
#define LP 284
#define RP 285
#define DOTDOT 286
#define MINUS 287
#define VAR 288
#define FUNCTION 289
#define PROCEDURE 290
#define ASSIGN 291
#define SBEGIN 292
#define IF 293
#define THEN 294
#define ELSE 295
#define REPEAT 296
#define UNTIL 297
#define WHILE 298
#define DO 299
#define FOR 300
#define TO 301
#define DOWNTO 302
#define CASE 303
#define GOTO 304
#define GE 305
#define GT 306
#define LE 307
#define LT 308
#define UNEQUAL 309
#define PLUS 310
#define OR 311
#define MUL 312
#define DIV 313
#define MOD 314
#define AND 315
#define NOT 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 248 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    17,    17,    23,    25,    35,    36,    38,    58,    65,
      70,    75,    80,    85,    90,    95,   101,   102,   104,   120,
     127,   132,   133,   136,   143,   149,   165,   172,   187,   193,
     197,   201,   205,   209,   214,   219,   225,   232,   240,   247,
     248,   250,   266,   273,   274,   276,   289,   291,   300,   309,
     310,   312,   325,   327,   333,   340,   353,   355,   360,   362,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   374,
     380,   387,   395,   400,   407,   413,   420,   427,   434,   441,
     451,   455,   460,   467,   480,   482,   488,   495,   501,   516,
     522,   528,   534,   540,   546,   552,   558,   563,   569,   575,
     581,   586,   592,   598,   604,   610,   615,   620,   626,   631,
     636,   641,   646,   652
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "PROGRAM", "ID", "SEMI", "CONST",
  "EQUAL", "INTEGER", "REAL", "CHAR", "STRING", "FALSE", "MAXINT", "TRUE",
  "TYPE", "ARRAY", "LB", "RB", "OF", "RECORD", "END", "COLON", "COMMA",
  "SBOOLEAN", "SCHAR", "SINTEGER", "SREAL", "LP", "RP", "DOTDOT", "MINUS",
  "VAR", "FUNCTION", "PROCEDURE", "ASSIGN", "SBEGIN", "IF", "THEN", "ELSE",
  "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", "CASE", "GOTO",
  "GE", "GT", "LE", "LT", "UNEQUAL", "PLUS", "OR", "MUL", "DIV", "MOD",
  "AND", "NOT", "$accept", "program", "id_tmp", "routine", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_decl", "array_type_decl", "record_type_decl", "field_decl_list",
  "name_list", "simple_type_decl", "var_part", "var_decl_list",
  "routine_part", "routine_part_list", "func_proc_decl", "parameters",
  "para_decl_list", "para_type_list", "stmt_list", "stmt", "stmt_label",
  "non_label_stmt", "assign_stmt", "proc_stmt", "compound_stmt", "if_stmt",
  "repeat_stmt", "while_stmt", "for_stmt", "direction", "case_stmt",
  "case_expr_list", "case_expr", "goto_stmt", "expression_list",
  "expression", "expr", "term", "factor", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -153

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-153)))

#define YYTABLE_NINF -73

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    27,    46,  -153,    52,  -153,    53,    27,    70,    54,
      88,    27,  -153,    27,    65,   334,    99,   121,    27,   144,
      20,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   151,   334,
     302,   158,  -153,     1,   144,    27,    27,    96,  -153,  -153,
    -153,   163,   140,   167,   144,  -153,  -153,  -153,  -153,   144,
     334,   156,   174,   200,  -153,  -153,  -153,   302,   302,   203,
      17,   181,   181,  -153,  -153,  -153,  -153,   327,     4,   116,
     -10,   182,   207,   334,  -153,   211,   213,  -153,   302,     6,
     195,   224,   222,   209,  -153,   123,   302,  -153,   273,  -153,
    -153,  -153,  -153,   226,   144,   128,    12,  -153,   327,    53,
       7,  -153,  -153,   150,  -153,   150,    27,   150,   228,   185,
     229,   215,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,   219,   302,   235,   334,  -153,  -153,   166,   327,
       6,  -153,   236,   237,    77,   150,   150,   150,    98,  -153,
      37,    47,   332,  -153,   231,   124,   220,    84,  -153,    27,
     150,   150,   150,  -153,   261,   302,   256,  -153,  -153,   327,
    -153,  -153,    53,  -153,   142,  -153,  -153,   253,   150,   150,
     150,   252,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   252,   150,   366,   239,   148,
      -3,   201,   201,  -153,  -153,  -153,  -153,   258,  -153,  -153,
     196,    -2,    47,   238,    47,    47,    47,    47,    47,   332,
     332,   332,  -153,  -153,  -153,  -153,   201,  -153,    67,   254,
     268,   352,  -153,   150,   245,   150,  -153,  -153,  -153,  -153,
     252,  -153,  -153,   150,   252,   252,  -153,  -153,   201,   150,
     201,  -153,   172,   286,   288,   201,   252,  -153,  -153,  -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     6,     0,     0,    17,
       0,     5,     2,     0,    40,     0,     0,     0,    16,     0,
      44,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    28,     0,    39,     0,     0,     0,    43,    46,
       8,     0,    33,     0,     0,    29,    30,    31,    32,     0,
       0,     0,     0,     0,    21,    22,    20,     0,     0,     0,
       0,    50,    50,    56,    45,     4,     7,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,    27,     0,     0,
       0,     0,     0,     0,    24,     0,     0,    34,     0,    38,
      35,    18,    42,     0,     0,     0,     0,    52,     0,     6,
       3,    59,    74,     0,    56,     0,     0,     0,     0,     0,
       0,     0,    58,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,     0,     0,     0,    36,    41,     0,     0,
       0,    49,     0,     0,   106,     0,     0,     0,     0,   108,
       0,    96,   100,   105,     0,     0,     0,     0,    87,     0,
       0,     0,     0,    55,     0,     0,     0,    26,    37,     0,
      54,    51,     6,    48,     0,   111,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    69,    57,    23,    25,    53,     0,   109,   113,
       0,     0,    94,    76,    90,    91,    92,    93,    95,    98,
      97,    99,   101,   102,   103,   104,    77,    78,     0,     0,
       0,     0,    84,     0,     0,     0,    73,    47,   112,   107,
       0,    80,    81,     0,     0,     0,    82,    83,    71,     0,
      88,    75,     0,     0,     0,    70,     0,    86,    85,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,    -1,   -91,  -153,  -153,   -14,  -153,  -153,   -55,
    -153,  -153,  -153,    18,   -60,  -153,  -153,  -153,  -153,   259,
     241,  -153,   178,   214,  -152,  -153,   168,  -153,  -153,   283,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,   100,  -153,   155,
     -42,   212,   -54,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   138,     8,     9,    11,   139,    14,    18,    53,
      54,    55,    68,    95,    56,    20,    34,    37,    38,    39,
      80,    96,    97,    82,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   233,   120,   221,   222,   121,   190,
     191,   141,   142,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    28,    75,    76,   165,   166,    10,    83,   133,    32,
      16,    32,    17,   -72,    59,    41,    52,    31,   130,   203,
      87,   225,   225,    93,    58,    59,    84,   226,   229,    51,
       1,   124,     3,   217,    61,    62,    71,    33,   132,    94,
      78,    59,   131,    52,    52,   170,     5,   -72,   212,   213,
     214,   215,    60,    52,    35,    36,    51,    51,     6,    90,
       7,   140,    69,   145,    52,   147,    51,    70,   156,   160,
      13,   197,    52,    12,   126,   170,   171,    51,   241,   177,
      -3,   109,   243,   244,    52,    51,    85,   172,   173,   174,
     175,   176,   170,   164,   249,    -3,    15,    51,    19,   196,
     194,   167,   178,   179,   187,   146,    -3,    29,   189,    52,
     192,   158,   128,   231,   232,    52,   168,   172,   173,   174,
     175,   176,    51,   209,   210,   211,   200,   169,    51,    30,
      35,    36,   170,    63,   172,   173,   174,   175,   176,    86,
      59,    52,   216,   109,   218,    52,   123,    59,   188,    32,
     170,   129,    59,   109,    51,   134,   170,    40,    51,    21,
      22,    23,    24,    25,    26,    27,    57,   224,   185,    66,
     109,    -3,   198,   220,   172,   173,   174,   175,   176,   135,
     170,   238,   136,   240,   109,    67,   219,    72,   149,   159,
      59,   242,   172,   173,   174,   175,   176,   245,   172,   173,
     174,   175,   176,   150,   170,    73,    74,   220,    77,   170,
      79,   137,    89,    88,   151,   228,   246,    91,    98,    92,
     219,   152,   172,   173,   174,   175,   176,   100,   122,   109,
      99,   101,   127,   109,   109,   153,   100,   148,   154,   155,
     101,   157,   162,   163,   102,   109,   172,   173,   174,   175,
     176,   172,   173,   174,   175,   176,   186,   100,   199,    63,
     103,   101,   195,   104,   227,   105,   100,   106,    63,   103,
     107,   108,   104,   184,   105,   223,   106,   234,   230,   107,
     108,   239,    21,    22,    23,    24,    25,    26,    27,    63,
     103,   235,   247,   104,   248,   105,    64,   106,    63,   103,
     107,   108,   104,    81,   105,   125,   106,    42,   161,   107,
     108,    21,    22,    23,    24,    25,    26,    27,   144,    43,
      65,   237,   193,    44,   201,     0,     0,    45,    46,    47,
      48,    49,    42,     0,    50,     0,    21,    22,    23,    24,
      25,    26,    27,    21,    22,    23,    24,    25,    26,    27,
       0,     0,    45,    46,    47,    48,    49,     3,     0,    50,
       0,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     3,     0,     0,   236,    21,    22,    23,    24,    25,
      26,    27,   202,     0,   204,   205,   206,   207,   208,   180,
     181,   182,   183
};

static const yytype_int16 yycheck[] =
{
       1,    15,    57,    58,   136,   137,     7,    67,    99,     5,
      11,     5,    13,     6,    24,    29,    30,    18,     6,   171,
      30,    24,    24,    78,    23,    24,    22,    30,    30,    30,
       4,    86,     5,   185,    35,    36,    50,    19,    98,    33,
      23,    24,    30,    57,    58,     8,     0,    40,   180,   181,
     182,   183,    34,    67,    34,    35,    57,    58,     6,    73,
       7,   103,    44,   105,    78,   107,    67,    49,   123,   129,
      16,   162,    86,     3,    88,     8,    39,    78,   230,    32,
       3,    82,   234,   235,    98,    86,    68,    50,    51,    52,
      53,    54,     8,   135,   246,    18,     8,    98,    33,   159,
     155,     3,    55,    56,    20,   106,    29,     8,   150,   123,
     152,   125,    94,    46,    47,   129,    18,    50,    51,    52,
      53,    54,   123,   177,   178,   179,   168,    29,   129,     8,
      34,    35,     8,    37,    50,    51,    52,    53,    54,    23,
      24,   155,   184,   144,   186,   159,    23,    24,   149,     5,
       8,    23,    24,   154,   155,     5,     8,     6,   159,     9,
      10,    11,    12,    13,    14,    15,     8,    19,    44,     6,
     171,    31,    30,   187,    50,    51,    52,    53,    54,    29,
       8,   223,    32,   225,   185,    18,   187,    31,     3,    23,
      24,   233,    50,    51,    52,    53,    54,   239,    50,    51,
      52,    53,    54,    18,     8,    31,     6,   221,     5,     8,
      29,    61,     5,    31,    29,    19,    44,     6,    23,     6,
     221,    36,    50,    51,    52,    53,    54,     5,    19,   230,
       6,     9,     6,   234,   235,     6,     5,     9,    23,    20,
       9,     6,     6,     6,    22,   246,    50,    51,    52,    53,
      54,    50,    51,    52,    53,    54,    36,     5,     5,    37,
      38,     9,     6,    41,     6,    43,     5,    45,    37,    38,
      48,    49,    41,    42,    43,    36,    45,    23,    40,    48,
      49,    36,     9,    10,    11,    12,    13,    14,    15,    37,
      38,    23,     6,    41,     6,    43,    37,    45,    37,    38,
      48,    49,    41,    62,    43,    32,    45,     5,   130,    48,
      49,     9,    10,    11,    12,    13,    14,    15,   104,    17,
      37,   221,   154,    21,   169,    -1,    -1,    25,    26,    27,
      28,    29,     5,    -1,    32,    -1,     9,    10,    11,    12,
      13,    14,    15,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    25,    26,    27,    28,    29,     5,    -1,    32,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,     5,    -1,    -1,    22,     9,    10,    11,    12,    13,
      14,    15,   170,    -1,   172,   173,   174,   175,   176,    57,
      58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    63,     5,    64,     0,     6,     7,    65,    66,
      64,    67,     3,    16,    69,     8,    64,    64,    70,    33,
      77,     9,    10,    11,    12,    13,    14,    15,    68,     8,
       8,    64,     5,    75,    78,    34,    35,    79,    80,    81,
       6,    68,     5,    17,    21,    25,    26,    27,    28,    29,
      32,    64,    68,    71,    72,    73,    76,     8,    23,    24,
      75,    64,    64,    37,    81,    91,     6,    18,    74,    75,
      75,    68,    31,    31,     6,    71,    71,     5,    23,    29,
      82,    82,    85,    76,    22,    75,    23,    30,    31,     5,
      68,     6,     6,    71,    33,    75,    83,    84,    23,     6,
       5,     9,    22,    38,    41,    43,    45,    48,    49,    64,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      97,   100,    19,    23,    71,    32,    68,     6,    75,    23,
       6,    30,    76,    65,     5,    29,    32,    61,    64,    68,
     102,   103,   104,   105,    85,   102,    64,   102,     9,     3,
      18,    29,    36,     6,    23,    20,    71,     6,    68,    23,
      76,    84,     6,     6,   102,   105,   105,     3,    18,    29,
       8,    39,    50,    51,    52,    53,    54,    32,    55,    56,
      57,    58,    59,    60,    42,    44,    36,    20,    64,   102,
     101,   102,   102,    88,    71,     6,    76,    65,    30,     5,
     102,   101,   103,    86,   103,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   105,   105,   102,    86,   102,    64,
      68,    98,    99,    36,    19,    24,    30,     6,    19,    30,
      40,    46,    47,    96,    23,    23,    22,    99,   102,    36,
     102,    86,   102,    86,    86,   102,    44,     6,     6,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    72,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    89,    90,    90,    91,    92,    92,    93,    94,    95,
      96,    96,    97,    98,    98,    99,    99,   100,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     5,     2,     0,     5,     4,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     5,     4,
       1,     1,     1,     6,     3,     5,     4,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     5,     3,     2,
       0,     5,     4,     1,     0,     2,     1,     8,     6,     3,
       0,     3,     1,     4,     3,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       6,     5,     1,     4,     3,     6,     4,     4,     4,     8,
       1,     1,     5,     2,     1,     4,     4,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     4,     1,     3,
       2,     2,     4,     3
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
#line 18 "pascal.y" /* yacc.c:1646  */
    {
			(yyvsp[-1])->id = (yyvsp[-3])->id;
			savedTree = (yyvsp[-1]);
		 }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 23 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newIdNode(); (yyval)->id = copyString(tokenString);}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 26 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newRoutineNode();
			(yyval)->child[0] = (yyvsp[-4]);
			(yyval)->child[1] = (yyvsp[-3]);
			(yyval)->child[2] = (yyvsp[-2]);
			(yyval)->child[3] = (yyvsp[-1]);
			(yyval)->child[4] = (yyvsp[0]);
		 }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 35 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 36 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 39 "pascal.y" /* yacc.c:1646  */
    {
					TreeNode *t = (yyvsp[-4]);

					TreeNode *newNode = newConstDeclNode();
					newNode->id = (yyvsp[-3])->id;
					newNode->child[0] = (yyvsp[-1]);

                    /* add new expr to the end of expr list */
					if (t != NULL)
					{
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = newNode;
						(yyval) = (yyvsp[-4]);
					}
					else
						(yyval) = newNode;
				 }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 59 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstDeclNode();
				(yyval)->id = (yyvsp[-3])->id;
				(yyval)->child[0] = (yyvsp[-1]);
			   }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 66 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstNode(IntegerK);
				(yyval)->value.int_value = atoi(tokenString);
			 }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstNode(RealK);
				(yyval)->value.real_value = atof(tokenString);
		     }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 76 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstNode(CharK);
				(yyval)->value.int_value = tokenString[1];
		     }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstNode(StringK);
				(yyval)->value.str_value = copyString(tokenString);
		     }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstNode(BooleanK);
				(yyval)->value.int_value = 0;
		     }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 91 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstNode(IntegerK);
				(yyval)->value.int_value = INT_MAX;
		     }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 96 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newConstNode(BooleanK);
				(yyval)->value.int_value = 1;
		     }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 101 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 102 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 105 "pascal.y" /* yacc.c:1646  */
    {
					TreeNode *t = (yyvsp[-4]);
					TreeNode *newNode = newTypeDeclNode();
					newNode->id = (yyvsp[-3])->id;
					newNode->child[0] = (yyvsp[-1]);
					if (t != NULL)
					{
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = newNode;
						(yyval) = (yyvsp[-4]);
					}
					else
						(yyval) = newNode;
				}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newTypeDeclNode();
					(yyval)->id = (yyvsp[-3])->id;
					(yyval)->child[0] = (yyvsp[-1]);
			    }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 128 "pascal.y" /* yacc.c:1646  */
    {
		    (yyval) = newTypeNode(TypeSimpleK);
		    (yyval)->child[0] = (yyvsp[0]);
		   }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 132 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 137 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newTypeNode(TypeArrayK);
					(yyval)->child[0] = (yyvsp[-3]);
					(yyval)->child[1] = (yyvsp[0]);
				 }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newTypeNode(TypeRecordK);
					(yyval)->child[0] = (yyvsp[-1]);
				  }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "pascal.y" /* yacc.c:1646  */
    {
					TreeNode *t = (yyvsp[-4]);
					TreeNode *newNode = newRecordNode();
					newNode->child[0] = (yyvsp[-3]);
					newNode->child[1] = (yyvsp[-1]);
					if (t != NULL)
					{
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = newNode;
						(yyval) = (yyvsp[-4]);
					}
					else
						(yyval) = newNode;
				 }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 166 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newRecordNode();
					(yyval)->child[0] = (yyvsp[-3]);
					(yyval)->child[1] = (yyvsp[-1]);
			     }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 173 "pascal.y" /* yacc.c:1646  */
    {
			TreeNode *t = (yyvsp[-2]);
			TreeNode *newNode = newNameListNode();
			newNode->id = copyString(tokenString);
			if (t != NULL)
			{
				while (t->sibling != NULL)
					t = t->sibling;
				t->sibling = newNode;
				(yyval) = (yyvsp[-2]);
			}
			else
				(yyval) = newNode;
		   }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 188 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newNameListNode();
			(yyval)->id = copyString(tokenString);
		   }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 194 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(BooleanK);
				  }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 198 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(CharK);
				  }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 202 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(IntegerK);
				  }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 206 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(RealK);
			      }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 210 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(IdK);
					(yyval)->id = copyString(tokenString);
			      }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 215 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(SNameListK);
					(yyval)->child[0] = (yyvsp[-1]);
			      }
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 220 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(DotDotK);
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
			      }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 226 "pascal.y" /* yacc.c:1646  */
    {
			      	(yyval) = newSimpleNode(DotDotK);
			      	(yyvsp[-2])->is_minus = 1;
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
			      }
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 233 "pascal.y" /* yacc.c:1646  */
    {
			      	(yyval) = newSimpleNode(DotDotK);
			      	(yyvsp[-3])->is_minus = 1;
					(yyval)->child[0] = (yyvsp[-3]);
					(yyvsp[0])->is_minus = 1;
					(yyval)->child[1] = (yyvsp[0]);
			      }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 241 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newSimpleNode(DotDotK);
					(yyval)->id = (yyvsp[-2])->id;
					(yyval)->id2 = copyString(tokenString);
			      }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 247 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 248 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 251 "pascal.y" /* yacc.c:1646  */
    {
				TreeNode *t = (yyvsp[-4]);
				TreeNode *newNode = newVarDeclNode();
				newNode->child[0] = (yyvsp[-3]);
				newNode->child[1] = (yyvsp[-1]);
				if (t != NULL)
				{
					while (t->sibling != NULL)
						t = t->sibling;
					t->sibling = newNode;
					(yyval) = (yyvsp[-4]);
				}
				else
					(yyval) = newNode;
			   }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 267 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newVarDeclNode();
				(yyval)->child[0] = (yyvsp[-3]);
				(yyval)->child[1] = (yyvsp[-1]);
			   }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 273 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 274 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 277 "pascal.y" /* yacc.c:1646  */
    {
					TreeNode *t = (yyvsp[-1]);
					if (t != NULL)
					{
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = (yyvsp[0]);
						(yyval) = (yyvsp[-1]);
					}
					else
						(yyval) = (yyvsp[0]);
				   }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 289 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 292 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newFuncProcNode(FuncK);
					(yyval)->id = (yyvsp[-6])->id;
					(yyvsp[-1])->id = (yyvsp[-6])->id;
					(yyval)->child[0] = (yyvsp[-5]);
					(yyval)->child[1] = (yyvsp[-3]);
					(yyval)->child[2] = (yyvsp[-1]);
			    }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 301 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newFuncProcNode(ProcK);
					(yyval)->id = (yyvsp[-4])->id;
					(yyvsp[-1])->id = (yyvsp[-4])->id;
					(yyval)->child[0] = (yyvsp[-3]);
					(yyval)->child[1] = (yyvsp[-1]);
			    }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 309 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 310 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 313 "pascal.y" /* yacc.c:1646  */
    {
					TreeNode *t = (yyvsp[-2]);
					if (t != NULL)
					{
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = (yyvsp[0]);
						(yyval) = (yyvsp[-2]);
					}
					else
						(yyval) = (yyvsp[0]);
				}
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 325 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 328 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newParaNode(VarK);
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
				}
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 334 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newParaNode(ValK);
					(yyval)->child[0] = (yyvsp[-2]);
					(yyval)->child[1] = (yyvsp[0]);
				}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 341 "pascal.y" /* yacc.c:1646  */
    {
			TreeNode *t = (yyvsp[-2]);
			if (t != NULL)
			{
				while (t->sibling != NULL)
					t = t->sibling;
				t->sibling = (yyvsp[-1]);
				(yyval) = (yyvsp[-2]);
			}
			else
				(yyval) = (yyvsp[-1]);
		   }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 353 "pascal.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 356 "pascal.y" /* yacc.c:1646  */
    {
		(yyvsp[0])->label = atoi((yyvsp[-2])->id);
		(yyval) = (yyvsp[0]);
	  }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 360 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 362 "pascal.y" /* yacc.c:1646  */
    {(yyval) = newIdNode(); (yyval)->id = copyString(tokenString);}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 364 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 365 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 366 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 367 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 368 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 369 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 370 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 371 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 372 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 375 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newStmtNode(AssignK);
				(yyval)->id = (yyvsp[-2])->id;
				(yyval)->child[0] = (yyvsp[0]);
			 }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 381 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newStmtNode(AssignK);
				(yyval)->id = (yyvsp[-5])->id;
				(yyval)->child[0] = (yyvsp[-3]);
				(yyval)->child[1] = (yyvsp[0]);
		     }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 388 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newStmtNode(AssignK);
				(yyval)->id = (yyvsp[-4])->id;
				(yyval)->id2 = (yyvsp[-2])->id;
				(yyval)->child[0] = (yyvsp[0]);
		     }
#line 2181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 396 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newStmtNode(SProcK);
			(yyval)->id = copyString(tokenString);
           }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 401 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newStmtNode(SProcK);
			(yyval)->id = (yyvsp[-3])->id;
			(yyval)->child[0] = (yyvsp[-1]);
		   }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 408 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newStmtNode(CompoundK);
				(yyval)->child[0] = (yyvsp[-1]);
			   }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 414 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newStmtNode(IfK);
			(yyval)->child[0] = (yyvsp[-4]);
			(yyval)->child[1] = (yyvsp[-2]);
			(yyval)->child[2] = (yyvsp[0]);
		 }
#line 2220 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 421 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newStmtNode(IfK);
			(yyval)->child[0] = (yyvsp[-2]);
			(yyval)->child[1] = (yyvsp[0]);
		 }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 428 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newStmtNode(RepeatK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			 }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 435 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newStmtNode(WhileK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 442 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newStmtNode(ForK);
			(yyval)->id = (yyvsp[-6])->id;
			(yyval)->child[0] = (yyvsp[-4]);
			(yyval)->child[1] = (yyvsp[-3]);
			(yyval)->child[2] = (yyvsp[-2]);
			(yyval)->child[3] = (yyvsp[0]);
		  }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 452 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newDirectionNode(ToK);
		   }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 456 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newDirectionNode(DowntoK);
		   }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 461 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newStmtNode(SCaseK);
			(yyval)->child[0] = (yyvsp[-3]);
			(yyval)->child[1] = (yyvsp[-1]);
		   }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 468 "pascal.y" /* yacc.c:1646  */
    {
					TreeNode *t = (yyvsp[-1]);
					if (t != NULL)
					{
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = (yyvsp[0]);
						(yyval) = (yyvsp[-1]);
					}
					else
						(yyval) = (yyvsp[0]);
			    }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 480 "pascal.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 483 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newCaseNode();
			(yyval)->child[0] = (yyvsp[-3]);
			(yyval)->child[1] = (yyvsp[-1]);
		   }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 489 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newCaseNode();
			(yyval)->id = (yyvsp[-3])->id;
			(yyval)->child[0] = (yyvsp[-1]);
		   }
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 496 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newStmtNode(GotoK);
			(yyval)->dest = atoi(tokenString);
		   }
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 502 "pascal.y" /* yacc.c:1646  */
    {
					TreeNode *t = (yyvsp[-2]);
					TreeNode *newNode = newExpressionListNode();
					newNode->child[0] = (yyvsp[0]);
					if (t != NULL)
					{
						while (t->sibling != NULL)
							t = t->sibling;
						t->sibling = newNode;
						(yyval) = (yyvsp[-2]);
					}
					else
						(yyval) = newNode;
				 }
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 517 "pascal.y" /* yacc.c:1646  */
    {
					(yyval) = newExpressionListNode();
					(yyval)->child[0] = (yyvsp[0]);
				 }
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 523 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newExpressionNode(GeK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 529 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newExpressionNode(GtK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			}
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 535 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newExpressionNode(LeK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 541 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newExpressionNode(LtK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 547 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newExpressionNode(EqualK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			}
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 553 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = newExpressionNode(UnequalK);
				(yyval)->child[0] = (yyvsp[-2]);
				(yyval)->child[1] = (yyvsp[0]);
			}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 559 "pascal.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 2437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 564 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = newExprNode(PlusK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	  }
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 570 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = newExprNode(MinusK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	  }
#line 2457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 576 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = newExprNode(OrK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	  }
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 582 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = (yyvsp[0]);
	  }
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 587 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = newTermNode(MulK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	  }
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 593 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = newTermNode(DivK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	  }
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 599 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = newTermNode(ModK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	  }
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 605 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = newTermNode(AndK);
		(yyval)->child[0] = (yyvsp[-2]);
		(yyval)->child[1] = (yyvsp[0]);
	  }
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 611 "pascal.y" /* yacc.c:1646  */
    {
		(yyval) = (yyvsp[0]);
	  }
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 616 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newFactorNode();
			(yyval)->id = copyString(tokenString);
		}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 621 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newFactorNode();
			(yyval)->id = (yyvsp[-3])->id;
			(yyval)->child[0] = (yyvsp[-1]);
	    }
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 627 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newFactorNode();
			(yyval)->child[0] = (yyvsp[0]);
	    }
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 632 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newFactorNode();
			(yyval)->child[0] = (yyvsp[-1]);
	    }
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 637 "pascal.y" /* yacc.c:1646  */
    {
			(yyvsp[0])->is_not = 1;
			(yyval) = (yyvsp[0]);
	    }
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 642 "pascal.y" /* yacc.c:1646  */
    {
			(yyvsp[0])->is_minus = 1;
			(yyval) = (yyvsp[0]);
	    }
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 647 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newFactorNode();
			(yyval)->id = (yyvsp[-3])->id;
			(yyval)->child[1] = (yyvsp[-1]);
	    }
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 653 "pascal.y" /* yacc.c:1646  */
    {
			(yyval) = newFactorNode();
			(yyval)->id = (yyvsp[-2])->id;
			(yyval)->id2 = copyString(tokenString);
	    }
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2602 "y.tab.c" /* yacc.c:1646  */
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
#line 659 "pascal.y" /* yacc.c:1906  */


int yyerror(char *message)
{
	printf("Syntax Error at Line %d: %s\n", lineno, message);
	return 0;
}

static int yylex()
{
	return getToken();
}

TreeNode *parse()
{
	yydebug = 0;
	yyparse();
	return savedTree;
}
