/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Substitute the variable and function names.  */
#define yyparse         cregparse
#define yylex           creglex
#define yyerror         cregerror
#define yylval          creglval
#define yychar          cregchar
#define yydebug         cregdebug
#define yynerrs         cregnerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 17 "../cwb/cl/registry.y"


#include <ctype.h>

#include "globals.h"

#include "corpus.h"
#include "macros.h"
#include "attributes.h"


extern int creglex();

Corpus *cregcorpus = NULL;
Attribute *cregattrib = NULL;

char cregestring[1024];

/* ====================================================================== */

DynArg *makearg(char *type_id);

#define cregSetAttrComponentPath(attr, cid, path) \
{ \
  if (!declare_component(attr, cid, path)) { \
    sprintf(cregestring, "Component %s with path %s declared twice" \
            " (or internal error)", cid_name(cid), path); \
    cl_free(path); \
    cregerror(cregestring); \
  } \
}

void cregerror_cleanup(char *message)
{
 Rprintf( "REGISTRY ERROR (%s/%s): %s\n", cregin_path, cregin_name, message);

  if (cregattrib != NULL)
    attr_drop_attribute(cregattrib);

  if (cregcorpus != NULL)
    drop_corpus(cregcorpus);

  cregcorpus = NULL;
  cregattrib = NULL;
}

#define cregerror(message) { cregerror_cleanup(message); YYERROR; }

/* ====================================================================== */



/* Line 268 of yacc.c  */
#line 132 "../cwb/cl/registry.tab.c"

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
     NAME_SYM = 258,
     ID_SYM = 259,
     INFO_SYM = 260,
     HOME_SYM = 261,
     ATTRIBUTE_SYM = 262,
     DIR_SYM = 263,
     CORPUS_SYM = 264,
     REVCORP_SYM = 265,
     REVCIDX_SYM = 266,
     FREQS_SYM = 267,
     LEXICON_SYM = 268,
     LEXIDX_SYM = 269,
     LEXSRT_SYM = 270,
     STRUCTURE_SYM = 271,
     ALIGNED_SYM = 272,
     DYNAMIC_SYM = 273,
     DOTS_SYM = 274,
     IGNORE_SYM = 275,
     ADMIN_SYM = 276,
     ACCESS_SYM = 277,
     USER_SYM = 278,
     GROUP_SYM = 279,
     ASSERT_SYM = 280,
     HOST_SYM = 281,
     PROPERTY_SYM = 282,
     IDENTIFIER = 283,
     STRING = 284,
     NUMBER = 285
   };
#endif
/* Tokens.  */
#define NAME_SYM 258
#define ID_SYM 259
#define INFO_SYM 260
#define HOME_SYM 261
#define ATTRIBUTE_SYM 262
#define DIR_SYM 263
#define CORPUS_SYM 264
#define REVCORP_SYM 265
#define REVCIDX_SYM 266
#define FREQS_SYM 267
#define LEXICON_SYM 268
#define LEXIDX_SYM 269
#define LEXSRT_SYM 270
#define STRUCTURE_SYM 271
#define ALIGNED_SYM 272
#define DYNAMIC_SYM 273
#define DOTS_SYM 274
#define IGNORE_SYM 275
#define ADMIN_SYM 276
#define ACCESS_SYM 277
#define USER_SYM 278
#define GROUP_SYM 279
#define ASSERT_SYM 280
#define HOST_SYM 281
#define PROPERTY_SYM 282
#define IDENTIFIER 283
#define STRING 284
#define NUMBER 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 69 "../cwb/cl/registry.y"

  char    *strval;
  int      ival;
  void    *args;
  void    *attr;

  IDList   idlist;

  struct {
    int status;
    char *path;
  } storage;



/* Line 293 of yacc.c  */
#line 244 "../cwb/cl/registry.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 256 "../cwb/cl/registry.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,     2,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     8,    10,    12,    13,    24,    27,
      28,    31,    32,    35,    36,    41,    42,    47,    48,    53,
      54,    57,    60,    61,    62,    66,    67,    74,    75,    76,
      81,    85,    89,    98,   100,   101,   103,   105,   107,   111,
     113,   115,   119,   120,   123,   124,   127,   130,   133,   136,
     139,   142,   145,   148,   150,   152,   154,   156,   159,   160,
     162,   165,   166,   171
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    -1,    40,    42,    41,    -1,     1,    -1,
      52,    -1,    -1,    50,    51,    45,    44,    43,    46,    49,
      47,    48,    68,    -1,     5,    64,    -1,    -1,     6,    64,
      -1,    -1,    21,    65,    -1,    -1,    23,    31,    66,    32,
      -1,    -1,    24,    31,    66,    32,    -1,    -1,    26,    31,
      66,    32,    -1,    -1,     3,    67,    -1,     4,    65,    -1,
      -1,    -1,    55,    53,    52,    -1,    -1,    20,    65,    65,
      57,    54,    52,    -1,    -1,    -1,     7,    65,    56,    58,
      -1,    17,    65,    57,    -1,    16,    65,    57,    -1,    18,
      65,    33,    59,    34,    35,    60,    67,    -1,    64,    -1,
      -1,    61,    -1,    64,    -1,    60,    -1,    59,    36,    60,
      -1,    65,    -1,    19,    -1,    31,    62,    32,    -1,    -1,
      63,    62,    -1,    -1,     8,    64,    -1,     9,    64,    -1,
      10,    64,    -1,    11,    64,    -1,    12,    64,    -1,    13,
      64,    -1,    14,    64,    -1,    15,    64,    -1,    65,    -1,
      67,    -1,    28,    -1,    30,    -1,    66,    65,    -1,    -1,
      29,    -1,    68,    69,    -1,    -1,    27,    28,    37,    29,
      -1,    27,    28,    37,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   140,   162,   165,   171,   168,   183,   184,
     187,   188,   191,   192,   195,   197,   200,   202,   205,   207,
     210,   213,   214,   217,   217,   225,   225,   228,   232,   231,
     243,   254,   265,   296,   298,   302,   307,   312,   313,   325,
     332,   339,   340,   343,   344,   347,   348,   349,   350,   351,
     352,   353,   354,   357,   358,   361,   362,   369,   375,   378,
     381,   382,   385,   389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME_SYM", "ID_SYM", "INFO_SYM",
  "HOME_SYM", "ATTRIBUTE_SYM", "DIR_SYM", "CORPUS_SYM", "REVCORP_SYM",
  "REVCIDX_SYM", "FREQS_SYM", "LEXICON_SYM", "LEXIDX_SYM", "LEXSRT_SYM",
  "STRUCTURE_SYM", "ALIGNED_SYM", "DYNAMIC_SYM", "DOTS_SYM", "IGNORE_SYM",
  "ADMIN_SYM", "ACCESS_SYM", "USER_SYM", "GROUP_SYM", "ASSERT_SYM",
  "HOST_SYM", "PROPERTY_SYM", "IDENTIFIER", "STRING", "NUMBER", "'{'",
  "'}'", "'('", "')'", "':'", "','", "'='", "$accept", "Registry", "$@1",
  "Declaration", "Header", "$@2", "OptInfo", "OptHome", "OptAdmin",
  "OptUserAccessClause", "OptGroupAccessClause", "OptHostAccessClause",
  "NameDecl", "IDDecl", "Attributes", "$@3", "$@4", "Attribute", "$@5",
  "StorageSpec", "AttrBody", "ArgList", "SingleArg", "OptFieldDefs",
  "FieldDefs", "FieldDef", "path", "id", "IDList", "string",
  "OptProperties", "Property", 0
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
     285,   123,   125,    40,    41,    58,    44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    40,    39,    39,    41,    43,    42,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      50,    51,    51,    53,    52,    54,    52,    52,    56,    55,
      55,    55,    55,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     1,     1,     0,    10,     2,     0,
       2,     0,     2,     0,     4,     0,     4,     0,     4,     0,
       2,     2,     0,     0,     3,     0,     6,     0,     0,     4,
       3,     3,     8,     1,     0,     1,     1,     1,     3,     1,
       1,     3,     0,     2,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     2,     0,     1,
       2,     0,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     1,     0,    27,    22,    59,    20,
       0,     0,     0,     0,     0,     3,     5,    23,     0,    11,
      55,    56,    28,    34,    34,     0,     0,    27,    21,     0,
       9,    42,    31,    33,    53,    54,    30,     0,    34,    24,
      10,     0,     6,    44,    29,    35,    36,    40,     0,    37,
      39,    25,     8,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,    27,     0,    19,    45,
      46,    47,    48,    49,    50,    51,    52,    41,    43,     0,
      38,    26,    12,     0,    15,     0,    58,     0,    17,    32,
       0,    58,     0,    61,    18,    57,     0,    58,     7,    14,
       0,     0,    60,    16,     0,     0,    62,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    15,     6,    53,    42,    30,    68,    88,
      93,    84,     7,    19,    16,    27,    66,    17,    31,    32,
      44,    48,    49,    45,    62,    63,    33,    34,    90,    35,
      98,   102
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int8 yypact[] =
{
      65,   -78,    18,    19,   -78,    14,    24,    25,   -78,   -78,
      45,    45,    45,    45,    45,   -78,   -78,   -78,    45,    61,
     -78,   -78,   -78,    35,    35,    44,    45,    24,   -78,    35,
      73,    31,   -78,   -78,   -78,   -78,   -78,    -7,    35,   -78,
     -78,    35,   -78,    38,   -78,   -78,   -78,   -78,    40,   -78,
     -78,   -78,   -78,    58,    35,    35,    35,    35,    35,    35,
      35,    35,    49,    38,    47,    -7,    24,    45,    57,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,    -7,
     -78,   -78,   -78,    53,    64,    14,   -78,    60,    68,   -78,
     -15,   -78,    62,   -78,   -78,   -78,    -2,   -78,    67,   -78,
      26,    69,   -78,   -78,    51,    42,   -78,   -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -21,   -78,   -78,   -78,   -78,   -14,
     -78,   -78,   -54,   -78,    33,   -78,   -22,   -10,   -77,     0,
     -78,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int8 yytable[] =
{
      22,    23,    24,    25,    26,     9,    39,    40,    28,    46,
      36,    80,    47,    20,    96,    21,    38,    94,     4,    52,
     100,    20,     5,    21,    51,    85,    20,    50,    21,    18,
      99,    10,    69,    70,    71,    72,    73,    74,    75,    76,
      11,    12,    13,     8,    14,    81,    54,    55,    56,    57,
      58,    59,    60,    61,    20,    50,    21,    82,   103,    20,
       8,    21,    43,    20,     8,    21,     1,    29,    -2,    50,
      20,   106,    21,    20,    64,    21,    65,    37,    41,    67,
      95,    77,    79,    83,    86,    89,    95,    87,   105,     0,
      95,    91,    92,    97,   101,   107,    78,   104
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-78))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      10,    11,    12,    13,    14,     5,    27,    29,    18,    31,
      24,    65,    19,    28,    91,    30,    26,    32,     0,    41,
      97,    28,     3,    30,    38,    79,    28,    37,    30,     4,
      32,     7,    54,    55,    56,    57,    58,    59,    60,    61,
      16,    17,    18,    29,    20,    66,     8,     9,    10,    11,
      12,    13,    14,    15,    28,    65,    30,    67,    32,    28,
      29,    30,    31,    28,    29,    30,     1,     6,     3,    79,
      28,    29,    30,    28,    34,    30,    36,    33,     5,    21,
      90,    32,    35,    26,    31,    85,    96,    23,    37,    -1,
     100,    31,    24,    31,    27,   105,    63,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    39,    40,     0,     3,    42,    50,    29,    67,
       7,    16,    17,    18,    20,    41,    52,    55,     4,    51,
      28,    30,    65,    65,    65,    65,    65,    53,    65,     6,
      45,    56,    57,    64,    65,    67,    57,    33,    65,    52,
      64,     5,    44,    31,    58,    61,    64,    19,    59,    60,
      65,    57,    64,    43,     8,     9,    10,    11,    12,    13,
      14,    15,    62,    63,    34,    36,    54,    21,    46,    64,
      64,    64,    64,    64,    64,    64,    64,    32,    62,    35,
      60,    52,    65,    26,    49,    60,    31,    23,    47,    67,
      66,    31,    24,    48,    32,    65,    66,    31,    68,    32,
      66,    27,    69,    32,    28,    37,    29,    65
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

#include "cl.h"

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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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

/* Line 1806 of yacc.c  */
#line 140 "../cwb/cl/registry.y"
    { cregcorpus = new(Corpus); 
                                      cregcorpus->attributes = NULL;
                                      cregcorpus->name = NULL;
                                      cregcorpus->id = NULL;
                                      cregcorpus->path = NULL;
                                      cregcorpus->charset = latin1;  /* default charset is latin1 */
                                      cregcorpus->properties = NULL;
                                      cregcorpus->info_file = NULL;
                                      cregcorpus->admin = NULL;
                                      cregcorpus->groupAccessList = NULL;
                                      cregcorpus->hostAccessList = NULL;
                                      cregcorpus->userAccessList = NULL;
                                      cregcorpus->registry_dir = NULL;
                                      cregcorpus->registry_name = NULL;
                                      cregcorpus->nr_of_loads = 1;
                                      cregcorpus->next = NULL;
                                    }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 158 "../cwb/cl/registry.y"
    { if (cregcorpus->attributes == NULL) {
                                        cregerror("Illegal corpus declaration -- no attributes defined"); 
                                      }
                                    }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 162 "../cwb/cl/registry.y"
    { cregerror_cleanup("Parse Error."); YYABORT; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 165 "../cwb/cl/registry.y"
    { /* nop */ }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 171 "../cwb/cl/registry.y"
    { cregcorpus->name      = (yyvsp[(1) - (4)].strval);
                                      cregcorpus->id        = (yyvsp[(2) - (4)].strval);
                                      cregcorpus->path      = (yyvsp[(3) - (4)].strval);
                                      cregcorpus->info_file = (yyvsp[(4) - (4)].strval);
                                    }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 183 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(2) - (2)].strval); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 184 "../cwb/cl/registry.y"
    { (yyval.strval) = NULL; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 187 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(2) - (2)].strval); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 188 "../cwb/cl/registry.y"
    { (yyval.strval) = NULL; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 191 "../cwb/cl/registry.y"
    { cregcorpus->admin = (yyvsp[(2) - (2)].strval); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 192 "../cwb/cl/registry.y"
    { cregcorpus->admin = NULL; }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 196 "../cwb/cl/registry.y"
    { cregcorpus->userAccessList = (yyvsp[(3) - (4)].idlist); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 197 "../cwb/cl/registry.y"
    { cregcorpus->userAccessList = NULL; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 201 "../cwb/cl/registry.y"
    { cregcorpus->groupAccessList = (yyvsp[(3) - (4)].idlist); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 202 "../cwb/cl/registry.y"
    { cregcorpus->groupAccessList = NULL; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 206 "../cwb/cl/registry.y"
    { cregcorpus->hostAccessList = (yyvsp[(3) - (4)].idlist); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 207 "../cwb/cl/registry.y"
    { cregcorpus->hostAccessList = NULL; }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 210 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(2) - (2)].strval); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 213 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(2) - (2)].strval); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 214 "../cwb/cl/registry.y"
    { (yyval.strval) = NULL; }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 217 "../cwb/cl/registry.y"
    { 
                                      /* declare components which are not yet declared for local attrs. */
                                      if ((((Attribute *)(yyvsp[(1) - (1)].attr))->any.path == NULL) &&
                                          (cregcorpus->path != NULL))
                                        ((Attribute *)(yyvsp[(1) - (1)].attr))->any.path = cl_strdup(cregcorpus->path);
                                      declare_default_components((Attribute *)(yyvsp[(1) - (1)].attr));
                                    }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 225 "../cwb/cl/registry.y"
    {}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 232 "../cwb/cl/registry.y"
    { 
                                      if ((cregattrib = setup_attribute(cregcorpus, (yyvsp[(2) - (2)].strval), ATT_POS, NULL)) == NULL) {
                                        sprintf(cregestring, 
                                                "Positional attribute %s declared twice -- "
                                                "semantic error", (yyvsp[(2) - (2)].strval));
                                        cl_free((yyvsp[(2) - (2)].strval));
                                        cregerror(cregestring);
                                      }
                                    }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 241 "../cwb/cl/registry.y"
    { (yyval.attr) = cregattrib; cregattrib = NULL; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 244 "../cwb/cl/registry.y"
    { if (((yyval.attr) = setup_attribute(cregcorpus, (yyvsp[(2) - (3)].strval), ATT_ALIGN, NULL)) == NULL) {
                                        sprintf(cregestring, "Alignment attribute %s declared twice -- "
                                                "semantic error", (yyvsp[(2) - (3)].strval));
                                        cl_free((yyvsp[(2) - (3)].strval));
                                        cl_free((yyvsp[(3) - (3)].storage).path);
                                        cregerror(cregestring);
                                      }

                                      ((Attribute *)(yyval.attr))->align.path = (yyvsp[(3) - (3)].storage).path;
                                    }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 255 "../cwb/cl/registry.y"
    { if (((yyval.attr) = setup_attribute(cregcorpus, (yyvsp[(2) - (3)].strval), ATT_STRUC, NULL)) == NULL) {
                                        sprintf(cregestring, "Structure attribute %s declared twice -- "
                                                "semantic error", (yyvsp[(2) - (3)].strval));
                                        cl_free((yyvsp[(2) - (3)].strval));
                                        cl_free((yyvsp[(3) - (3)].storage).path);
                                        cregerror(cregestring);
                                      }

                                      ((Attribute *)(yyval.attr))->struc.path = (yyvsp[(3) - (3)].storage).path;
                                    }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 268 "../cwb/cl/registry.y"
    { if (((yyval.attr) = setup_attribute(cregcorpus, (yyvsp[(2) - (8)].strval), ATT_DYN, NULL)) == NULL) {

                                        DynArg *a;

                                        sprintf(cregestring, "Dynamic attribute %s declared twice -- "
                                                "semantic error", (yyvsp[(2) - (8)].strval));
                                        cl_free((yyvsp[(2) - (8)].strval));
                                        cl_free((yyvsp[(7) - (8)].args));
                                        cl_free((yyvsp[(8) - (8)].strval));

                                        while ((yyvsp[(4) - (8)].args) != NULL) {
                                          a = (DynArg *)(yyvsp[(4) - (8)].args);
                                          (yyvsp[(4) - (8)].args) = ((DynArg *)a)->next;
                                          cl_free(a);
                                        }

                                        cregerror(cregestring);
                                      }

                                      ((Attribute *)(yyval.attr))->dyn.arglist = (yyvsp[(4) - (8)].args);
                                      ((Attribute *)(yyval.attr))->dyn.res_type = ((DynArg *)(yyvsp[(7) - (8)].args))->type;
                                      free((yyvsp[(7) - (8)].args));
                                      ((Attribute *)(yyval.attr))->dyn.call = (yyvsp[(8) - (8)].strval);

                                      ((Attribute *)(yyval.attr))->dyn.path = NULL;
                                    }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 296 "../cwb/cl/registry.y"
    { (yyval.storage).path = (yyvsp[(1) - (1)].strval); 
                                    }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 298 "../cwb/cl/registry.y"
    { (yyval.storage).path = NULL;
                                    }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 302 "../cwb/cl/registry.y"
    { assert(cregattrib != NULL);
                                      if ((cregattrib->any.path == NULL) &&
                                          (cregcorpus->path != NULL))
                                        cregattrib->any.path = cl_strdup(cregcorpus->path);
                                    }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 307 "../cwb/cl/registry.y"
    { assert(cregattrib != NULL);
                                      cregattrib->any.path = (yyvsp[(1) - (1)].strval); 
                                    }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 312 "../cwb/cl/registry.y"
    { (yyval.args) = (yyvsp[(1) - (1)].args); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 314 "../cwb/cl/registry.y"
    { 
                                      DynArg *last;
                                      assert((yyvsp[(1) - (3)].args) != NULL);
                                      last = (yyvsp[(1) - (3)].args); 
                                      while (last->next != NULL) last = (DynArg *)last->next;
                                      
                                      last->next = (yyvsp[(3) - (3)].args); 
                                      (yyval.args) = (yyvsp[(1) - (3)].args); 
                                    }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 325 "../cwb/cl/registry.y"
    { (yyval.args) = (DynArg *)makearg((yyvsp[(1) - (1)].strval)); 
                                      if ((yyval.args) == NULL) {
                                        sprintf(cregestring, "Illegal argument type %s or "
                                                "not enough memory -- FATAL ERROR", (yyvsp[(1) - (1)].strval));
                                        cregerror(cregestring);
                                      }
                                    }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 332 "../cwb/cl/registry.y"
    { (yyval.args) = (DynArg *)makearg("VARARG"); 
                                      if ((yyval.args) == NULL)
                                        cregerror("Internal error while parsing variable "
                                                  "argument list -- FATAL ERROR");
                                    }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 347 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompDirectory,    (yyvsp[(2) - (2)].strval)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 348 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompCorpus,       (yyvsp[(2) - (2)].strval)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 349 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompRevCorpus,    (yyvsp[(2) - (2)].strval)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 350 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompRevCorpusIdx, (yyvsp[(2) - (2)].strval)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 351 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompCorpusFreqs,  (yyvsp[(2) - (2)].strval)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 352 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompLexicon,      (yyvsp[(2) - (2)].strval)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 353 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompLexiconIdx,   (yyvsp[(2) - (2)].strval)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 354 "../cwb/cl/registry.y"
    { cregSetAttrComponentPath(cregattrib, CompLexiconSrt,   (yyvsp[(2) - (2)].strval)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 357 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(1) - (1)].strval); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 358 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(1) - (1)].strval); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 361 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(1) - (1)].strval); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 362 "../cwb/cl/registry.y"
    { char *nr;
                                      nr = (char *)cl_malloc(16);
                                      sprintf(nr, "%d", (yyvsp[(1) - (1)].ival));
                                      (yyval.strval) = nr;
                                    }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 369 "../cwb/cl/registry.y"
    { IDList n;
                                      n = (IDList)cl_malloc(sizeof(IDBuf));
                                      n->next = (yyvsp[(1) - (2)].idlist);
                                      n->string = (yyvsp[(2) - (2)].strval);
                                      (yyval.idlist) = n;
                                    }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 375 "../cwb/cl/registry.y"
    { (yyval.idlist) = NULL; }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 378 "../cwb/cl/registry.y"
    { (yyval.strval) = (yyvsp[(1) - (1)].strval); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 386 "../cwb/cl/registry.y"
    {
                                          add_corpus_property(cregcorpus, (yyvsp[(2) - (4)].strval), (yyvsp[(4) - (4)].strval));
                                        }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 390 "../cwb/cl/registry.y"
    { /* allow IDs and numbers without quotes */
                                          add_corpus_property(cregcorpus, (yyvsp[(2) - (4)].strval), (yyvsp[(4) - (4)].strval));
                                        }
    break;



/* Line 1806 of yacc.c  */
#line 2060 "../cwb/cl/registry.tab.c"
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 397 "../cwb/cl/registry.y"











