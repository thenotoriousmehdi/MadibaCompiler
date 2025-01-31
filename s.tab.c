
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "s.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h" 
#include "pile.h"
#ifndef strdup
#define strdup _strdup
#endif

// Prototype de la fonction principale d'analyse lexicale
int yylex();
void yyerror(const char *s);
extern int yylex(void);  // Déclare la fonction yylex générée par Flex

extern int lineNumber;
extern int columnNumber;
extern table_symbol symbolTable;



typedef struct quadruplet quadruplet;
struct quadruplet
{   
    char oprt[30];
	char op1[30];
	char op2[30];   
	char result[30]; 
};

quadruplet tab_quad[1000]; 

pile  stack;

int qc = 1 ; 
int ti = 0 ; 


// pour print 
char* print_expressions[30];  
int num_print_expressions = 0;

char current_loop_var[256];  
char increment_val[256];
int condition_addr;





/* Line 189 of yacc.c  */
#line 124 "s.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IMPORT = 258,
     PROGRAM = 259,
     CONST = 260,
     VAR = 261,
     TYPES = 262,
     FUNCTIONS = 263,
     MAIN = 264,
     INT = 265,
     FLOAT = 266,
     CHAR = 267,
     BOOL = 268,
     STRING = 269,
     CST = 270,
     OBJECT = 271,
     ENUM = 272,
     FUNCTION = 273,
     FOR = 274,
     WHILE = 275,
     IF = 276,
     ELSE = 277,
     SCAN = 278,
     PRINT = 279,
     VOID = 280,
     TRUE = 281,
     FALSE = 282,
     INTEGER_LITERAL = 283,
     FLOAT_LITERAL = 284,
     CHAR_LITERAL = 285,
     STRING_LITERAL = 286,
     IDENTIFIER = 287,
     ARRAY = 288,
     OBJECT_FIELD = 289,
     DOT = 290,
     AND = 291,
     OR = 292,
     NOT = 293,
     EQUAL = 294,
     NOT_EQUAL = 295,
     LESS_THAN = 296,
     GREATER_THAN = 297,
     LESS_EQUAL = 298,
     GREATER_EQUAL = 299,
     PLUS = 300,
     MINUS = 301,
     MULTIPLY = 302,
     DIVIDE = 303,
     MODULO = 304,
     COMMA = 305,
     OPEN_PAREN = 306,
     CLOSE_PAREN = 307,
     OPEN_BRACKET = 308,
     CLOSE_BRACKET = 309,
     OPEN_BRACE = 310,
     CLOSE_BRACE = 311,
     SEMICOLON = 312,
     QUOTE = 313,
     ASSIGN = 314,
     TWO_POINT = 315,
     RETURN = 316
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 51 "s.y"

    int intval;         // Pour INTEGER_LITERAL
    float floatval;     // Pour FLOAT_LITERAL
    char charval;       // Pour CHAR_LITERAL
    char* strval;       // Pour STRING_LITERAL et IDENTIFIER
    int type;           // Pour les types (INT, FLOAT, etc.)
   
    struct expressionTYPE {
    int type ;
    char val[256];
    } expressionTYPE;



/* Line 214 of yacc.c  */
#line 236 "s.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 248 "s.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  242

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    16,    17,    22,    23,    26,    32,
      37,    38,    41,    47,    51,    53,    55,    57,    59,    61,
      63,    65,    67,    69,    71,    73,    74,    79,    80,    83,
      89,    96,    97,   102,   109,   110,   115,   116,   119,   129,
     139,   140,   142,   146,   152,   153,   155,   157,   160,   166,
     170,   172,   174,   176,   178,   180,   182,   185,   190,   191,
     195,   197,   202,   203,   205,   207,   210,   212,   214,   216,
     218,   220,   222,   225,   230,   238,   245,   251,   253,   257,
     263,   264,   274,   275,   276,   282,   290,   295,   300,   305,
     308,   312,   316,   320,   324,   328,   332,   336,   340,   344,
     348,   352,   356,   360,   364,   367,   369,   373,   378,   382,
     384
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,     4,    32,    65,    68,    73,    77,
      87,    -1,     3,    31,    57,    -1,    -1,     5,    55,    66,
      56,    -1,    -1,    66,    67,    -1,    71,    32,    59,    72,
      57,    -1,     6,    55,    69,    56,    -1,    -1,    69,    70,
      -1,    71,    32,    59,    72,    57,    -1,    71,    32,    57,
      -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    26,
      -1,    27,    -1,    -1,     7,    55,    74,    56,    -1,    -1,
      74,    75,    -1,    16,    32,    55,    76,    56,    -1,    71,
      32,    53,    28,    54,    57,    -1,    -1,    76,    71,    32,
      57,    -1,    76,    71,    32,    59,    72,    57,    -1,    -1,
       8,    55,    78,    56,    -1,    -1,    78,    79,    -1,    71,
      18,    32,    51,    80,    52,    55,    82,    56,    -1,    25,
      18,    32,    51,    80,    52,    55,    82,    56,    -1,    -1,
      81,    -1,    71,    60,    32,    -1,    81,    50,    71,    60,
      32,    -1,    -1,    83,    -1,    84,    -1,    83,    84,    -1,
      71,    32,    59,   105,    57,    -1,    71,    32,    57,    -1,
      91,    -1,    92,    -1,    94,    -1,    95,    -1,    99,    -1,
     102,    -1,    85,    57,    -1,    32,    51,    86,    52,    -1,
      -1,    86,    50,   105,    -1,   105,    -1,     9,    55,    88,
      56,    -1,    -1,    89,    -1,    90,    -1,    89,    90,    -1,
      91,    -1,    92,    -1,    94,    -1,    95,    -1,    99,    -1,
     102,    -1,    85,    57,    -1,    32,    59,   105,    57,    -1,
      32,    53,   105,    54,    59,   105,    57,    -1,    32,    35,
      32,    59,   105,    57,    -1,    24,    51,    93,    52,    57,
      -1,   105,    -1,    93,    50,   105,    -1,    23,    51,    32,
      52,    57,    -1,    -1,    21,    51,   105,    52,    96,    55,
      89,    56,    97,    -1,    -1,    -1,    22,    98,    55,    89,
      56,    -1,    19,    51,   100,   101,    55,    89,    56,    -1,
      32,    59,   105,    50,    -1,    72,    50,    72,    52,    -1,
     103,   104,    89,    56,    -1,    20,    51,    -1,   105,    52,
      55,    -1,   105,    37,   105,    -1,   105,    36,   105,    -1,
     105,    39,   105,    -1,   105,    40,   105,    -1,   105,    41,
     105,    -1,   105,    42,   105,    -1,   105,    43,   105,    -1,
     105,    44,   105,    -1,   105,    45,   105,    -1,   105,    46,
     105,    -1,   105,    47,   105,    -1,   105,    48,   105,    -1,
     105,    49,   105,    -1,    38,   105,    -1,    85,    -1,    51,
     105,    52,    -1,    32,    53,   105,    54,    -1,    32,    35,
      32,    -1,    32,    -1,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    99,   102,   104,   107,   109,   113,   140,
     143,   145,   149,   165,   176,   177,   178,   179,   180,   184,
     190,   196,   202,   208,   209,   214,   216,   222,   224,   228,
     235,   244,   246,   253,   262,   264,   267,   269,   273,   281,
     290,   292,   296,   306,   316,   318,   322,   323,   328,   334,
     340,   341,   342,   343,   344,   345,   346,   351,   354,   356,
     357,   362,   365,   367,   371,   372,   376,   377,   378,   379,
     380,   381,   382,   386,   404,   405,   409,   426,   429,   435,
     452,   452,   470,   471,   471,   492,   513,   527,   562,   578,
     582,   592,   608,   624,   641,   654,   667,   680,   693,   706,
     722,   738,   754,   778,   798,   799,   800,   804,   805,   806,
     817
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT", "PROGRAM", "CONST", "VAR",
  "TYPES", "FUNCTIONS", "MAIN", "INT", "FLOAT", "CHAR", "BOOL", "STRING",
  "CST", "OBJECT", "ENUM", "FUNCTION", "FOR", "WHILE", "IF", "ELSE",
  "SCAN", "PRINT", "VOID", "TRUE", "FALSE", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "CHAR_LITERAL", "STRING_LITERAL", "IDENTIFIER", "ARRAY",
  "OBJECT_FIELD", "DOT", "AND", "OR", "NOT", "EQUAL", "NOT_EQUAL",
  "LESS_THAN", "GREATER_THAN", "LESS_EQUAL", "GREATER_EQUAL", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "MODULO", "COMMA", "OPEN_PAREN",
  "CLOSE_PAREN", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_BRACE",
  "CLOSE_BRACE", "SEMICOLON", "QUOTE", "ASSIGN", "TWO_POINT", "RETURN",
  "$accept", "program", "import_section", "const_section",
  "const_declarations", "const_declaration", "var_section",
  "var_declarations", "var_declaration", "type", "value", "types_section",
  "types_declarations", "type_declaration", "object_fields",
  "functions_section", "function_declarations", "function_declaration",
  "parameters", "parameter_list", "fonction_body",
  "instructions_fonction_list", "instruction_fonction", "function_call",
  "argument_list", "main_section", "main_body", "instruction_list",
  "instruction", "affectation", "print_stmt", "print_expression_list",
  "scan_stmt", "if_stmt", "$@1", "else_part", "$@2", "for_stmt",
  "init_for", "corp_for", "while_stmt", "debut_while", "corp_while",
  "expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    67,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    86,    86,
      86,    87,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    92,    93,    93,    94,
      96,    95,    97,    98,    97,    99,   100,   101,   102,   103,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     3,     0,     4,     0,     2,     5,     4,
       0,     2,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     2,     5,
       6,     0,     4,     6,     0,     4,     0,     2,     9,     9,
       0,     1,     3,     5,     0,     1,     1,     2,     5,     3,
       1,     1,     1,     1,     1,     1,     2,     4,     0,     3,
       1,     4,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     4,     7,     6,     5,     1,     3,     5,
       0,     9,     0,     0,     5,     7,     4,     4,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     3,     4,     3,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     3,     4,     0,
       0,     6,     0,    25,     0,    10,     0,    34,    14,    15,
      16,    17,    18,     5,     7,     0,     0,    27,     0,     0,
       0,     9,    11,     0,     0,    36,     0,     2,     0,     0,
       0,    26,     0,    28,     0,    62,    23,    24,    19,    20,
      21,    22,     0,    13,     0,     0,     0,     0,    35,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    66,    67,    68,    69,    70,    71,     0,     8,     0,
      31,     0,     0,     0,     0,    89,     0,     0,     0,     0,
      58,     0,     0,    72,    61,    65,   109,     0,     0,   110,
     105,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,    60,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    40,    40,     0,     0,     0,    80,     0,     0,     0,
       0,     0,    57,     0,    73,   108,     0,   106,    88,    92,
      91,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    90,     0,    30,     0,     0,    41,     0,     0,
       0,     0,     0,    79,    78,    76,     0,    59,     0,   107,
      32,     0,     0,     0,     0,     0,    86,     0,     0,     0,
      75,     0,     0,    42,    44,     0,    44,    87,    85,     0,
      74,    33,     0,     0,    45,    46,     0,    50,    51,    52,
      53,    54,    55,     0,     0,    82,     0,    39,    47,    56,
      43,    38,    83,    81,    49,     0,     0,     0,     0,    48,
       0,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    10,    14,    24,    13,    26,    32,   212,
      99,    17,    34,    43,   104,    29,    44,    60,   176,   177,
     213,   214,   215,   100,   115,    37,    68,    69,    70,    71,
      72,   112,    73,    74,   182,   233,   236,    75,   109,   145,
      76,    77,   101,   102
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
       9,    -8,    32,    34,   -18,  -196,    20,  -196,    42,     0,
      53,  -196,    35,    86,    23,  -196,    40,    81,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,    78,    31,  -196,    58,   108,
      59,  -196,  -196,    89,    -6,  -196,    75,  -196,   395,   -37,
      99,  -196,   110,  -196,    15,   396,  -196,  -196,  -196,  -196,
    -196,  -196,    83,  -196,   395,    90,    94,   130,  -196,   131,
    -196,   101,   105,   106,   107,   111,    -5,    93,   109,   396,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   173,  -196,   120,
    -196,   135,   134,   136,   156,  -196,   173,   160,   173,   162,
     173,   173,   173,  -196,  -196,  -196,    14,   173,   173,  -196,
    -196,   396,   308,  -196,    70,   113,   145,   146,   147,   395,
     322,   157,    22,   365,   151,    36,   365,   276,   200,   180,
     173,  -196,   336,   114,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   158,  -196,   182,
     164,   221,   221,   173,   178,   168,  -196,   212,   173,   213,
     173,   173,  -196,   214,  -196,  -196,   292,  -196,  -196,   390,
     390,   205,   205,   205,   205,   205,   205,   -32,   -32,  -196,
    -196,  -196,  -196,    68,  -196,   211,   220,   239,   236,   350,
     395,   396,   235,  -196,   365,  -196,   219,   365,   173,  -196,
    -196,   395,   259,   237,   221,   252,  -196,   256,   152,   396,
    -196,   238,   253,  -196,   206,   249,   206,  -196,  -196,   159,
    -196,  -196,   279,   270,   206,  -196,   285,  -196,  -196,  -196,
    -196,  -196,  -196,   295,   287,   381,    82,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,   173,   363,   257,   396,  -196,
     166,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   -13,
     -36,  -196,  -196,  -196,  -196,  -196,  -196,  -196,   298,  -196,
     240,  -196,   227,   -45,  -196,  -196,  -196,   -87,   -66,  -195,
    -153,  -196,  -138,  -129,  -196,  -196,  -196,   -95,  -196,  -196,
     -90,  -196,  -196,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      67,    25,    52,    95,    18,    19,    20,    21,    22,   217,
      40,   217,     1,    33,   123,   134,   135,   136,    79,   217,
      53,    42,    54,     4,    67,    18,    19,    20,    21,    22,
      89,    59,     5,    18,    19,    20,    21,    22,     6,     7,
      57,    18,    19,    20,    21,    22,    90,     9,    91,   119,
      41,   218,     8,   218,    92,    11,    67,    95,   110,    12,
     113,   218,   116,   117,   118,    90,   219,   120,   219,   121,
     122,    58,   148,   144,   149,   220,   219,   220,    67,    23,
      18,    19,    20,    21,    22,   220,   151,    31,   152,    28,
      15,   139,   156,    16,   198,    27,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   221,
      30,   221,   209,    35,   222,   179,   222,    36,    38,   221,
     184,    39,   186,   187,   222,   190,   138,   191,   175,   175,
      45,    55,    95,    61,    62,    63,    67,    64,    65,   234,
      78,   235,    56,    95,   197,    80,    66,    81,    82,    83,
      93,   240,    84,    67,    67,   202,    85,    86,    87,   216,
     201,   216,    88,   105,    67,    94,   106,   140,   107,   216,
     158,    61,    62,    63,    95,    64,    65,   103,    61,    62,
      63,   205,    64,    65,    66,    61,    62,    63,   108,    64,
      65,    66,   111,    67,   114,    67,   141,   142,    66,    46,
      47,    48,    49,    50,    51,    96,   143,   237,   208,   147,
     150,    97,   155,   172,   173,   225,    18,    19,    20,    21,
      22,   174,   241,   181,    98,    61,    62,    63,   180,    64,
      65,    18,    19,    20,    21,    22,   124,   125,    66,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     132,   133,   134,   135,   136,   124,   125,   154,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   183,
     185,   192,   193,   188,   124,   125,   200,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   195,   194,
     199,   203,   204,   124,   125,   210,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   206,   207,   223,
     211,   226,   124,   125,   239,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   227,   230,   124,   125,
     153,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   229,   231,   124,   125,   189,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   124,   125,
     137,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   124,   125,   146,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   124,   125,   157,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     196,   124,   125,   232,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    61,    62,    63,   238,    64,
      65,    46,    47,    48,    49,    50,    51,     0,    66,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     178,   228,     0,     0,     0,     0,   224
};

static const yytype_int16 yycheck[] =
{
      45,    14,    38,    69,    10,    11,    12,    13,    14,   204,
      16,   206,     3,    26,   101,    47,    48,    49,    54,   214,
      57,    34,    59,    31,    69,    10,    11,    12,    13,    14,
      35,    44,     0,    10,    11,    12,    13,    14,     4,    57,
      25,    10,    11,    12,    13,    14,    51,     5,    53,    35,
      56,   204,    32,   206,    59,    55,   101,   123,    86,     6,
      88,   214,    90,    91,    92,    51,   204,    53,   206,    97,
      98,    56,    50,   109,    52,   204,   214,   206,   123,    56,
      10,    11,    12,    13,    14,   214,    50,    56,    52,     8,
      55,   104,   120,     7,   181,    55,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   204,
      32,   206,   199,    55,   204,   143,   206,     9,    59,   214,
     148,    32,   150,   151,   214,    57,    56,    59,   141,   142,
      55,    32,   198,    19,    20,    21,   181,    23,    24,    57,
      57,    59,    32,   209,   180,    55,    32,    53,    18,    18,
      57,   238,    51,   198,   199,   191,    51,    51,    51,   204,
     188,   206,    51,    28,   209,    56,    32,    54,    32,   214,
      56,    19,    20,    21,   240,    23,    24,    57,    19,    20,
      21,   194,    23,    24,    32,    19,    20,    21,    32,    23,
      24,    32,    32,   238,    32,   240,    51,    51,    32,    26,
      27,    28,    29,    30,    31,    32,    59,   235,    56,    52,
      59,    38,    32,    55,    32,    56,    10,    11,    12,    13,
      14,    57,    56,    55,    51,    19,    20,    21,    50,    23,
      24,    10,    11,    12,    13,    14,    36,    37,    32,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      45,    46,    47,    48,    49,    36,    37,    57,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    57,
      57,    60,    52,    59,    36,    37,    57,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    52,    50,
      55,    32,    55,    36,    37,    57,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    55,    52,    60,
      57,    32,    36,    37,    57,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    56,    32,    36,    37,
      54,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    57,    56,    36,    37,    54,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    36,    37,
      52,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    36,    37,    52,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    36,    37,    52,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    36,    37,    22,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    19,    20,    21,    55,    23,
      24,    26,    27,    28,    29,    30,    31,    -1,    32,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
     142,   214,    -1,    -1,    -1,    -1,   206
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    64,    31,     0,     4,    57,    32,     5,
      65,    55,     6,    68,    66,    55,     7,    73,    10,    11,
      12,    13,    14,    56,    67,    71,    69,    55,     8,    77,
      32,    56,    70,    71,    74,    55,     9,    87,    59,    32,
      16,    56,    71,    75,    78,    55,    26,    27,    28,    29,
      30,    31,    72,    57,    59,    32,    32,    25,    56,    71,
      79,    19,    20,    21,    23,    24,    32,    85,    88,    89,
      90,    91,    92,    94,    95,    99,   102,   103,    57,    72,
      55,    53,    18,    18,    51,    51,    51,    51,    51,    35,
      51,    53,    59,    57,    56,    90,    32,    38,    51,    72,
      85,   104,   105,    57,    76,    28,    32,    32,    32,   100,
     105,    32,    93,   105,    32,    86,   105,   105,   105,    35,
      53,   105,   105,    89,    36,    37,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    52,    56,    71,
      54,    51,    51,    59,    72,   101,    52,    52,    50,    52,
      59,    50,    52,    54,    57,    32,   105,    52,    56,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,    55,    32,    57,    71,    80,    81,    80,   105,
      50,    55,    96,    57,   105,    57,   105,   105,    59,    54,
      57,    59,    60,    52,    50,    52,    50,    72,    89,    55,
      57,   105,    72,    32,    55,    71,    55,    52,    56,    89,
      57,    57,    71,    82,    83,    84,    85,    91,    92,    94,
      95,    99,   102,    60,    82,    56,    32,    56,    84,    57,
      32,    56,    22,    97,    57,    59,    98,   105,    55,    57,
      89,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 91 "s.y"
    {
        printf("Analyse syntaxique correcte.\n");
        displayTable(); // Affiche la table des symboles après l'analyse
        YYACCEPT;
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 114 "s.y"
    {   
         
        if (insertSymbol((yyvsp[(2) - (5)].strval), C_CONST, (yyvsp[(1) - (5)].type), 0) == -1) {
             char temp[100] ; 
            sprintf(temp,"Constante %s déjà déclarée.\n", (yyvsp[(2) - (5)].strval));
            yyerrorS(temp);
        }
       
        if ((yyvsp[(4) - (5)].expressionTYPE).type != (yyvsp[(1) - (5)].type)) {
            char temp[100] ; 
            sprintf(temp,"Type de la constante %s incorrect.\n", (yyvsp[(2) - (5)].strval));

            yyerrorS(temp);
        }else{
              strcpy(tab_quad[qc].oprt,"=");
              strcpy(tab_quad[qc].op1,(yyvsp[(4) - (5)].expressionTYPE).val);
              strcpy(tab_quad[qc].op2,"");
              strcpy(tab_quad[qc].result,(yyvsp[(2) - (5)].strval));
                qc++;
        }
        
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 150 "s.y"
    {
        if (insertSymbol((yyvsp[(2) - (5)].strval), C_VAR, (yyvsp[(1) - (5)].type), 0) == -1) {
            printf("Erreur : Variable %s déjà déclarée.\n", (yyvsp[(2) - (5)].strval));
        }
         if ((yyvsp[(4) - (5)].expressionTYPE).type != (yyvsp[(1) - (5)].type)) {
            printf("Erreur : Type de la Variable %s incorrect.\n", (yyvsp[(2) - (5)].strval));
        }else{
             
              strcpy(tab_quad[qc].oprt,"=");
              strcpy(tab_quad[qc].op1,(yyvsp[(4) - (5)].expressionTYPE).val);
              strcpy(tab_quad[qc].op2,"");
              strcpy(tab_quad[qc].result,(yyvsp[(2) - (5)].strval));
                qc++;
        }
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 166 "s.y"
    {
        if (insertSymbol((yyvsp[(2) - (3)].strval), C_VAR, (yyvsp[(1) - (3)].type), 0) == -1) {
            printf("Erreur : Variable %s déjà déclarée.\n", (yyvsp[(2) - (3)].strval));
        }
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 176 "s.y"
    { (yyval.type) = T_INT; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 177 "s.y"
    { (yyval.type) = T_FLOAT; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 178 "s.y"
    { (yyval.type) = T_CHAR; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 179 "s.y"
    { (yyval.type) = T_BOOL; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 180 "s.y"
    { (yyval.type) = T_STRING; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 184 "s.y"
    { 
     (yyval.expressionTYPE).type = T_INT ; 
    char buffer[20]; 
    sprintf(buffer, "%d", (yyvsp[(1) - (1)].intval)); 
    strcpy((yyval.expressionTYPE).val,strdup(buffer)); 
     ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 190 "s.y"
    { 
    (yyval.expressionTYPE).type = T_FLOAT ; 
    char buffer[20]; 
    sprintf(buffer, "%f", (yyvsp[(1) - (1)].floatval)); 
    strcpy((yyval.expressionTYPE).val,strdup(buffer));  
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 196 "s.y"
    { 
   (yyval.expressionTYPE).type = T_CHAR ;    
    char buffer[20] ;
    sprintf(buffer, "%c", (yyvsp[(1) - (1)].charval));
   strcpy((yyval.expressionTYPE).val,strdup(buffer)); 
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 202 "s.y"
    {  (yyval.expressionTYPE).type =  T_STRING ;   
                      char buffer[20] ;
                     sprintf(buffer, "%s", (yyvsp[(1) - (1)].strval));
                     strcpy((yyval.expressionTYPE).val,strdup(buffer));  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 208 "s.y"
    {  (yyval.expressionTYPE).type = T_BOOL;  strcpy((yyval.expressionTYPE).val,strdup("true"));  ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 209 "s.y"
    {  (yyval.expressionTYPE).type =  T_BOOL; strcpy((yyval.expressionTYPE).val,strdup("false"));  ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 217 "s.y"
    {
        symbolTable.base = 0;
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 229 "s.y"
    {
        if (insertSymbol((yyvsp[(2) - (5)].strval), C_TYPE, T_STRING, symbolTable.base) == -1) {
            printf("Erreur : Type objet %s déjà déclaré.\n", (yyvsp[(2) - (5)].strval));
        }
        symbolTable.base = 0 ;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 235 "s.y"
    {
        printf("Tableau %s de type %d avec taille %d\n", (yyvsp[(2) - (6)].strval), (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].intval)); 
        if (insertSymbol((yyvsp[(2) - (6)].strval), C_ARRAY, (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].intval)) == -1) {
            printf("Erreur : Type enum %s déjà déclaré.\n", (yyvsp[(2) - (6)].strval));
        }
    
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 247 "s.y"
    {
        if(insertSymbol((yyvsp[(3) - (4)].strval),C_CHAMP , (yyvsp[(2) - (4)].type), 0) == -1) {
            printf("Erreur : Type enum %d déjà déclaré.\n", (yyvsp[(2) - (4)].type));
        }
        symbolTable.base ++;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 254 "s.y"
    {
        if(insertSymbol((yyvsp[(3) - (6)].strval),C_CHAMP , (yyvsp[(2) - (6)].type), 0) == -1) {
            printf("Erreur : Type enum %d déjà déclaré.\n", (yyvsp[(2) - (6)].type));
        }
        symbolTable.base ++;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 274 "s.y"
    {
        if (insertSymbol((yyvsp[(3) - (9)].strval), C_VAR, T_FUNCTION, symbolTable.base) == -1) {
            printf("Erreur : Fonction %s déjà déclarée.\n", (yyvsp[(3) - (9)].strval));
        }
        symbolTable.base = 0 ;
    
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 282 "s.y"
    {
        if (insertSymbol((yyvsp[(3) - (9)].strval), C_VAR, T_FUNCTION,symbolTable.base) == -1) {
            printf("Erreur : Fonction %s déjà déclarée.\n", (yyvsp[(3) - (9)].strval));
        }
        symbolTable.base = 0 ;
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 297 "s.y"
    {
        if (insertSymbol((yyvsp[(3) - (3)].strval), C_ARGUMENT, (yyvsp[(1) - (3)].type), 0) == -1) {
            printf("Erreur : Argument %s déjà déclaré.\n", (yyvsp[(3) - (3)].strval));
        }
        {
        symbolTable.base ++;
    
    }
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 307 "s.y"
    {
        if (insertSymbol((yyvsp[(5) - (5)].strval), C_ARGUMENT, (yyvsp[(3) - (5)].type), 0) == -1) {
            printf("Erreur : Argument %s déjà déclaré.\n", (yyvsp[(5) - (5)].strval));
        }
        symbolTable.base ++;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 329 "s.y"
    {
        if (insertSymbol((yyvsp[(2) - (5)].strval), C_LOCAL, (yyvsp[(1) - (5)].type), 0) == -1) {
            printf("Erreur : Argument %d déjà déclaré.\n", (yyvsp[(1) - (5)].type));
        }
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 335 "s.y"
    {
        if (insertSymbol((yyvsp[(2) - (3)].strval), C_LOCAL, (yyvsp[(1) - (3)].type), 0) == -1) {
            printf("Erreur : Argument %d déjà déclaré.\n", (yyvsp[(1) - (3)].type));
        }
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 386 "s.y"
    {
        desc_identif* symbol = lookupSymbol((yyvsp[(1) - (4)].strval));
        if (symbol == NULL) {
         char error_message[256];
         sprintf(error_message, "Variable %s non declaree.", (yyvsp[(1) - (4)].strval));          
         yyerrorS(error_message);
        }else {
         if ((yyvsp[(3) - (4)].expressionTYPE).type != symbol->type) {
            printf("Erreur Sémantique : Type de la variable %s incorrect.\n", (yyvsp[(1) - (4)].strval));
        }else{
              strcpy(tab_quad[qc].oprt,"=");
              strcpy(tab_quad[qc].op1,(yyvsp[(3) - (4)].expressionTYPE).val);
              strcpy(tab_quad[qc].op2,"");
              strcpy(tab_quad[qc].result,(yyvsp[(1) - (4)].strval));
                qc++;
        }
    }
 ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 409 "s.y"
    {
      
        for (int i = 0; i < num_print_expressions; i++) {
            strcpy(tab_quad[qc].oprt, "PRINT");
            strcpy(tab_quad[qc].op1, print_expressions[i]); 
            strcpy(tab_quad[qc].op2, "");
            strcpy(tab_quad[qc].result, "");
            qc++; 

            free(print_expressions[i]);
        }

       
        num_print_expressions = 0;
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 426 "s.y"
    {
        print_expressions[num_print_expressions++] = strdup((yyvsp[(1) - (1)].expressionTYPE).val); 
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 429 "s.y"
    {
        print_expressions[num_print_expressions++] = strdup((yyvsp[(3) - (3)].expressionTYPE).val);  
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 435 "s.y"
    {

        desc_identif* symbol = lookupSymbol((yyvsp[(3) - (5)].strval));
        if (symbol != NULL) {
            strcpy(tab_quad[qc].oprt, "SCAN");
            strcpy(tab_quad[qc].op1, (yyvsp[(3) - (5)].strval));  
            strcpy(tab_quad[qc].op2, "");
            strcpy(tab_quad[qc].result, "");
            qc++;  
        } else {
            yyerrorS("Invalid variable for SCAN");
        }
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 452 "s.y"
    {
        if ((yyvsp[(3) - (4)].expressionTYPE).type == T_BOOL) {
            empiler(&stack, qc-1); 
        } else {
            yyerrorS("Condition must evaluate to a boolean value");
        }
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 459 "s.y"
    {
        if (!estVide(&stack)) {  
            char addrEndIf[10];
            int addrFalseJump = depiler(&stack);

            sprintf(addrEndIf, "%d", qc);
            strcpy(tab_quad[addrFalseJump].op1, addrEndIf);
        } else {
            printf("Erreur : La pile est vide.\n");
        }
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 471 "s.y"
    {
        strcpy(tab_quad[qc].oprt, "BR");
        strcpy(tab_quad[qc].op1, "");
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, "");

        if (!estVide(&stack)) {
            char addrEndIf[10];
            int addrFalseJump = depiler(&stack);
            empiler(&stack, qc); 
            qc++;
            sprintf(addrEndIf, "%d", qc);
            strcpy(tab_quad[addrFalseJump].op1, addrEndIf);
        } else {
            printf("Erreur : La pile est vide.\n");
        }
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 492 "s.y"
    {
              
        int expFor = depiler(&stack);  // on depile l'addrese de la condition 
        char temp [30]; 

        strcpy(tab_quad[qc].oprt, "BR");
        sprintf(temp, "%d", expFor);  // Jump to comparison
        strcpy(tab_quad[qc].op1, temp);
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, "");

        

        qc++;
         sprintf(temp,"%d",qc);

        strcpy(tab_quad[expFor].op1,temp); // mise a jour de l'adresse de la condition pour le branchement 
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 513 "s.y"
    {
        strcpy(current_loop_var, (yyvsp[(1) - (4)].strval));  
       
        strcpy(tab_quad[qc].oprt, "=");
        strcpy(tab_quad[qc].op1, (yyvsp[(3) - (4)].expressionTYPE).val); 
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, (yyvsp[(1) - (4)].strval));   
        qc++;
       
        condition_addr = qc;  
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 527 "s.y"
    {
        
        strcpy(tab_quad[qc].oprt, "BG");
        strcpy(tab_quad[qc].op1, "temp");  // on va changer sa valeur dans la fin de for 
        strcpy(tab_quad[qc].op2,current_loop_var );      // 10
        strcpy(tab_quad[qc].result, (yyvsp[(1) - (4)].expressionTYPE).val);
        empiler(&stack,qc); // empiler pour pouvoir retourner 
        qc++;

        // incrementation 
        strcpy(tab_quad[qc].oprt, "+");
        strcpy(tab_quad[qc].op1, current_loop_var);
        strcpy(tab_quad[qc].op2, (yyvsp[(3) - (4)].expressionTYPE).val);
        char temp[20];
        sprintf(temp, "T%d", ti++);
        strcpy(tab_quad[qc].result, temp);
        qc++;
       
        strcpy(tab_quad[qc].oprt, "=");
        strcpy(tab_quad[qc].op1, temp);
        strcpy(tab_quad[qc].op2, "");
        strcpy(tab_quad[qc].result, current_loop_var);
        qc++;
       
   
       
       
        // Save increment value for later
        strcpy(increment_val, (yyvsp[(3) - (4)].expressionTYPE).val);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 562 "s.y"
    {
    char adresse[10];
    char adresseCondWhile [10];

     int addrDebutWhile = depiler(&stack);  // apres verif cond nchofo win nro7o ida fin wela debut fin while 
    int addrCondWhile = depiler(&stack);  
    sprintf(adresseCondWhile,"%d",addrCondWhile);
    strcpy(tab_quad[qc].oprt,"BR");
    strcpy(tab_quad[qc].op1,adresseCondWhile); // branchement direct au debut de l'expression de la condition 
    strcpy(tab_quad[qc].op2,"");
    strcpy(tab_quad[qc].result,"");
    qc++;
    sprintf(adresse,"%d",qc);
    strcpy(tab_quad[addrDebutWhile].op1,adresse); // mise ajour  de laaddrese de expression 
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 578 "s.y"
    {
    empiler(&stack,qc);  // empiler l'adresse de la condition  pour retourner a la condition  
  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 582 "s.y"
    { 
    if((yyvsp[(1) - (3)].expressionTYPE).type == T_BOOL){
        empiler(&stack,qc-1);  // empiler @ de quadriplet de l'expression  pour update 
    }else{
        printf("Semantic error : cannot evaluate non boolean expression as condition");
    }
;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 592 "s.y"
    {  // pas sur 
             if((yyvsp[(1) - (3)].expressionTYPE).type == T_BOOL &&  (yyvsp[(3) - (3)].expressionTYPE).type == T_BOOL  )
                    {  (yyval.expressionTYPE).type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"|");
                        strcpy(tab_quad[qc].op1,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[(3) - (3)].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 608 "s.y"
    { //revoir 
             if((yyvsp[(1) - (3)].expressionTYPE).type == T_BOOL &&  (yyvsp[(3) - (3)].expressionTYPE).type == T_BOOL  )
                    {  (yyval.expressionTYPE).type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"&");
                        strcpy(tab_quad[qc].op1,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[(3) - (3)].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 624 "s.y"
    { 
         
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type  )
                    { (yyval.expressionTYPE).type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BNE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].result,(yyvsp[(3) - (3)].expressionTYPE).val);
                         char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                           }   
                     ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 641 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type  )
                    { (yyval.expressionTYPE).type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].result,(yyvsp[(3) - (3)].expressionTYPE).val);
                        strcpy((yyval.expressionTYPE).val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 654 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type  )
                    { (yyval.expressionTYPE).type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BGE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].result,(yyvsp[(3) - (3)].expressionTYPE).val);
                        strcpy((yyval.expressionTYPE).val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 667 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type  )
                    {  (yyval.expressionTYPE).type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BLE");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].result,(yyvsp[(3) - (3)].expressionTYPE).val);
                        strcpy((yyval.expressionTYPE).val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 680 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type  )
                    { (yyval.expressionTYPE).type = T_BOOL ; 
                        strcpy(tab_quad[qc].oprt,"BG");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].result,(yyvsp[(3) - (3)].expressionTYPE).val);
                        strcpy((yyval.expressionTYPE).val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 693 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type  )
                    { (yyval.expressionTYPE).type = T_BOOL ;  ; 
                        strcpy(tab_quad[qc].oprt,"BL");
                        strcpy(tab_quad[qc].op1,"");
                        strcpy(tab_quad[qc].op2,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].result,(yyvsp[(3) - (3)].expressionTYPE).val);
                        strcpy((yyval.expressionTYPE).val,"");
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 706 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type &&  ( (yyvsp[(1) - (3)].expressionTYPE).type == T_INT  | (yyvsp[(1) - (3)].expressionTYPE).type == T_FLOAT ))
                    {  (yyval.expressionTYPE).type = (yyvsp[(1) - (3)].expressionTYPE).type ; 
                        strcpy(tab_quad[qc].oprt,"+");
                        strcpy(tab_quad[qc].op1,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[(3) - (3)].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 722 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type &&  ( (yyvsp[(1) - (3)].expressionTYPE).type == T_INT  | (yyvsp[(1) - (3)].expressionTYPE).type == T_FLOAT ))
                    {  (yyval.expressionTYPE).type = (yyvsp[(1) - (3)].expressionTYPE).type ; 
                        strcpy(tab_quad[qc].oprt,"-");
                        strcpy(tab_quad[qc].op1,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[(3) - (3)].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 738 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type &&  ( (yyvsp[(1) - (3)].expressionTYPE).type == T_INT  | (yyvsp[(1) - (3)].expressionTYPE).type == T_FLOAT ))
                    {  (yyval.expressionTYPE).type = (yyvsp[(1) - (3)].expressionTYPE).type ; 
                        strcpy(tab_quad[qc].oprt,"*");
                        strcpy(tab_quad[qc].op1,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[(3) - (3)].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                             yyerrorS("Type expression incompatible");
                                   }   
                     ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 754 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type &&  ( (yyvsp[(1) - (3)].expressionTYPE).type == T_INT  | (yyvsp[(1) - (3)].expressionTYPE).type == T_FLOAT ))
                    {   if( strcmp((yyvsp[(3) - (3)].expressionTYPE).val,"0") != 0   ){
                        if( atoi((yyvsp[(1) - (3)].expressionTYPE).val) % atoi((yyvsp[(3) - (3)].expressionTYPE).val) == 0){
                           (yyval.expressionTYPE).type = T_INT ; 
                        } else {
                            (yyval.expressionTYPE).type = T_FLOAT; 
                        }
                        strcpy(tab_quad[qc].oprt,"/");
                        strcpy(tab_quad[qc].op1,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[(3) - (3)].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {
                    yyerrorS("Devision par 0 impossible !");  
                                   }  
                    }else{
                         yyerrorS("Type expression incompatible");
                    } 
                    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 778 "s.y"
    { 
             if((yyvsp[(1) - (3)].expressionTYPE).type == (yyvsp[(3) - (3)].expressionTYPE).type &&  ( (yyvsp[(1) - (3)].expressionTYPE).type == T_INT  | (yyvsp[(1) - (3)].expressionTYPE).type == T_FLOAT ))
                    {   if( strcmp((yyvsp[(3) - (3)].expressionTYPE).val,"0") != 0   ){
                           (yyval.expressionTYPE).type = T_INT ; 
                        strcpy(tab_quad[qc].oprt,"%");
                        strcpy(tab_quad[qc].op1,(yyvsp[(1) - (3)].expressionTYPE).val);
                        strcpy(tab_quad[qc].op2,(yyvsp[(3) - (3)].expressionTYPE).val);
                        char  res [10]; 
                        sprintf(res,"T%d",ti);
                        strcpy(tab_quad[qc].result,res);
                        strcpy((yyval.expressionTYPE).val,res);
                         ti++; 
                         qc++;  
                           } else {                        
                             yyerrorS("Devision par 0 impossible !");
                                   }  
                    }else{
                          yyerrorS("Type expression incompatible");
                    } 
                    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 800 "s.y"
    {
        (yyval.expressionTYPE).type = (yyvsp[(2) - (3)].expressionTYPE).type ; 
        strcpy((yyval.expressionTYPE).val,(yyvsp[(2) - (3)].expressionTYPE).val); 
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 806 "s.y"
    {
          desc_identif* symbol = lookupSymbol((yyvsp[(1) - (1)].strval));
        if (symbol == NULL) {
         char error_message[256];
         sprintf(error_message, "Variable %s non declaree.", (yyvsp[(1) - (1)].strval));          
         yyerrorS(error_message);
        }else {
            (yyval.expressionTYPE).type = symbol->type; 
            strcpy((yyval.expressionTYPE).val,(yyvsp[(1) - (1)].strval)) ; 
        }
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2571 "s.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 819 "s.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erreur syntaxique ligne %d, colonne %d : %s\n", lineNumber, columnNumber, s);
}
void yyerrorS(const char *s) {
    fprintf(stderr, "Erreur Semantique ligne %d, colonne %d : %s\n", lineNumber, columnNumber, s);
}

int main() {
    initTable(); 
    
    initPile(&stack); 
    printf("\nAnalyse syntaxique en cours...\n");
     yyparse();


      printf("Analyse syntaxique TERMINER...\n");
   for (int i = 1; i < qc; i++) {
    printf("[%d] - ( %s , %s , %s , %s )\n",  i, tab_quad[i].oprt, tab_quad[i].op1, tab_quad[i].op2, tab_quad[i].result);
   }
    return 0;

}

