/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"


    #include <stdio.h>
    #include "scanner.h"
    #include "nodo.h"
    #include <string>
    #include <iostream>
    #include <vector>
    using namespace std;

    extern int yylineno;
    extern int columna;
    extern char *yytext;
    extern nodoSimple *raiz;

    int yyerror(const char* mens){
        cout<<mens<<endl;
        return 0;
    }


#line 92 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    mkdisk = 258,
    rmdisk = 259,
    fdisk = 260,
    mount = 261,
    unmount = 262,
    rep = 263,
    exec = 264,
    size = 265,
    unit = 266,
    path = 267,
    fit = 268,
    name = 269,
    type = 270,
    del = 271,
    add = 272,
    id = 273,
    bf = 274,
    ff = 275,
    wf = 276,
    k = 277,
    m = 278,
    b = 279,
    p = 280,
    e = 281,
    l = 282,
    fast = 283,
    full = 284,
    mbr = 285,
    disk = 286,
    igual = 287,
    entero = 288,
    cadena = 289,
    identificador = 290,
    ruta = 291,
    mkfs = 292,
    login = 293,
    logout = 294,
    mkgrp = 295,
    rmgrp = 296,
    mkusr = 297,
    rmusr = 298,
    chmod = 299,
    mkfile = 300,
    cat = 301,
    rem = 302,
    edit = 303,
    ren = 304,
    mkdir = 305,
    cp = 306,
    mv = 307,
    findp = 308,
    chownp = 309,
    chgrp = 310,
    pausep = 311,
    carpeta = 312,
    archivo = 313,
    usr = 314,
    pwd = 315,
    grp = 316,
    ugo = 317,
    r = 318,
    pp = 319,
    cont = 320,
    dest = 321,
    rutap = 322,
    inode = 323,
    block = 324,
    bm_inode = 325,
    bm_block = 326,
    tree = 327,
    sb = 328,
    file = 329,
    ls = 330,
    journaling = 331
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    char text[200];
    class nodoSimple *nodo;

#line 226 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  115
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  328

#define YYUNDEFTOK  2
#define YYMAXUTOK   331


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   168,   168,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   183,   184,   185,   186,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   211,   212,   213,   214,   215,   220,   221,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   237,   238,   239,
     243,   244,   248,   249,   250,   251,   252,   256,   257,   261,
     262,   263,   267,   268,   269,   270,   274,   278,   279,   283,
     284,   288,   289,   290,   291,   295,   296,   300,   301,   302,
     303,   307,   308,   309,   310,   311,   315,   316,   320,   321,
     325,   326,   327,   331,   332,   333,   337,   338,   339,   343,
     344,   345,   349,   350,   351,   356,   357,   358,   362,   363,
     364,   365,   369,   370,   371,   375,   382,   386,   387,   388,
     392,   393,   397,   398,   402,   403,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   422,   427,   431,
     432,   433,   437,   438,   439,   443,   444,   448,   449,   450,
     454,   455,   456,   460,   461,   465,   469,   470,   474,   475,
     476,   481,   482,   486,   487,   491,   492,   493,   497,   498,
     502,   503,   507,   508
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mkdisk", "rmdisk", "fdisk", "mount",
  "unmount", "rep", "exec", "size", "unit", "path", "fit", "name", "type",
  "del", "add", "id", "bf", "ff", "wf", "k", "m", "b", "p", "e", "l",
  "fast", "full", "mbr", "disk", "igual", "entero", "cadena",
  "identificador", "ruta", "mkfs", "login", "logout", "mkgrp", "rmgrp",
  "mkusr", "rmusr", "chmod", "mkfile", "cat", "rem", "edit", "ren",
  "mkdir", "cp", "mv", "findp", "chownp", "chgrp", "pausep", "carpeta",
  "archivo", "usr", "pwd", "grp", "ugo", "r", "pp", "cont", "dest",
  "rutap", "inode", "block", "bm_inode", "bm_block", "tree", "sb", "file",
  "ls", "journaling", "$accept", "INICIO", "COMANDO", "MKDISK", "RMDISK",
  "FDISK", "MOUNT", "UNMOUNT", "REP", "EXEC", "MKFS", "LOGIN", "LOGOUT",
  "MKGRP", "RMGRP", "MKUSR", "RMUSR", "CHMOD", "MKFILE", "CAT", "REM",
  "EDIT", "REN", "MKDIR", "CP", "MV", "FINDP", "CHOWNP", "CHGRP", "PAUSEP",
  "ID", "TYPE", "TYPEMKFS", "DEL", "NAME", "NAMEREP", "ADD", "SIZE", "FIT",
  "UNIT", "PATH", "PWD", "USR", "GRP", "UGO", "CARPETA", "RUTA", "DEST",
  "CONT", "PATHREM", "CONTEDIT", "ARCHIVO", "FILE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   184,    16,   165,   145,    32,    -6,    72,   100,    17,
    -149,    60,    80,   139,    52,    18,     3,   -18,   141,     6,
     156,    -5,    -8,    -1,   172,    34,   157,  -149,   173,  -149,
     124,   160,   207,   210,    83,   207,    83,   124,   160,   207,
     210,   211,   214,   217,   218,    83,   207,   211,    83,   219,
      83,   207,   220,   219,   221,    83,   207,    83,   222,   219,
      83,   219,   223,   224,    83,    83,   211,    83,   211,    83,
     223,   224,   225,    83,   223,    83,   226,   227,    18,    83,
     124,   207,     3,   228,    83,   229,    83,   230,    83,   207,
     231,    83,   207,   232,    83,   226,    -5,    83,   226,   233,
      83,   226,   233,    83,   207,   232,    83,   226,   223,    34,
      83,   223,   225,    83,    83,  -149,   196,   184,   179,   184,
     183,   184,   185,   184,  -149,  -149,  -149,   165,   165,   165,
     165,     5,   165,   182,   165,    71,   165,   234,   165,  -149,
     145,   145,  -149,   235,  -149,  -149,    -6,    74,    -6,    -6,
       7,    -6,  -149,  -149,  -149,   112,   100,   100,  -149,    17,
     177,    17,   180,    17,  -149,  -149,  -149,  -149,  -149,  -149,
     139,   139,   197,   139,  -149,  -149,  -149,    -3,    18,   236,
      18,  -149,  -149,     3,     3,  -149,   186,     3,  -149,   187,
    -149,  -149,    62,  -149,  -149,     6,   199,     6,  -149,   156,
     -13,   156,  -149,    -5,  -149,  -149,    -8,    44,    -8,  -149,
      -1,    -1,  -149,   172,   172,  -149,    34,    34,  -149,  -149,
     157,   157,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      30,    35,    37,    46,    49,    51,    56,    58,    61,    65,
      66,    68,    70,    74,    76,    80,    85,    87,    89,    92,
      95,    98,   101,   104,   107,   111,   114,   115,     0,     2,
       0,     0,     0,     0,    30,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,    30,     0,
      30,     0,     0,     0,     0,    30,     0,    30,     0,     0,
      30,     0,     0,     0,    30,    30,     0,    30,     0,    30,
       0,     0,     0,    30,     0,    30,     0,     0,    80,    30,
       0,     0,    85,     0,    30,     0,    30,     0,    30,     0,
       0,    30,     0,     0,    30,     0,    98,    30,     0,     0,
      30,     0,     0,    30,     0,     0,    30,     0,     0,   111,
      30,     0,     0,    30,    30,     1,     0,    35,     0,    35,
       0,    35,     0,    35,     3,    36,     4,    46,    46,    46,
      46,     0,    46,     0,    46,     0,    46,     0,    46,     5,
      49,    49,     6,     0,    50,     7,    56,     0,    56,    56,
       0,    56,     8,    57,     9,     0,    61,    61,    10,    65,
       0,    65,     0,    65,    11,    12,    67,    13,    69,    14,
      74,    74,     0,    74,    15,    75,    16,     0,    80,     0,
      80,    79,    17,    85,    85,    82,     0,    85,    18,     0,
      86,    19,     0,    88,    20,    92,     0,    92,    21,    95,
       0,    95,    22,    98,    97,    23,   101,     0,   101,    24,
     104,   104,    25,   107,   107,    26,   111,   111,   109,    27,
     114,   114,    28,    29,   138,    31,   142,   143,   144,    33,
     145,   146,    34,   139,   140,   141,    32,    38,    39,    40,
      42,   125,   124,    44,   117,   118,   119,    41,   122,   123,
      43,   137,    45,    48,    47,   116,    53,   126,   127,   128,
     130,   131,   132,   133,   134,   135,   136,   129,    52,    54,
     159,   160,   158,    55,   121,   120,    60,    59,    64,   152,
     150,   151,    62,   149,   147,   148,    63,    71,    72,   153,
     154,    73,   157,   156,    77,   155,    78,    83,    81,   163,
     164,    84,   172,   173,   165,   166,   167,    90,   168,   169,
      91,    93,   170,   171,    94,    96,    99,   162,   161,   100,
     102,   103,   105,   106,   108,   110,   112,   113
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,   -31,    66,  -149,    33,    95,  -149,    42,  -149,
      81,  -112,  -149,  -149,  -149,  -148,  -149,   -68,   -81,  -149,
    -149,    29,    26,   -94,    22,    30,    31,  -109,    27,  -149,
     113,  -149,  -149,  -149,    48,  -149,  -149,   -28,   237,   238,
     -19,   195,    43,   159,  -149,    57,  -149,   166,  -149,  -149,
    -149,   167,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    34,    36,    45,    48,    50,    55,    57,
      60,    64,    65,    67,    69,    73,    75,    79,    84,    86,
      88,    91,    94,    97,   100,   103,   106,   110,   113,   114,
     144,   134,   156,   136,   132,   148,   138,   117,   123,   119,
     121,   163,   161,   173,   180,   178,   151,   208,   187,   193,
     197,   201,   190
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     218,   185,   204,   124,    98,   126,    51,    95,    52,   127,
     181,   101,    53,    80,   139,    81,   125,   142,    89,   145,
     129,   312,   287,   288,   152,   291,   154,   140,    35,   158,
      76,   292,   146,   164,   165,    61,   167,   153,   169,   241,
     242,   270,   174,   271,   176,   313,   107,   278,   182,   282,
      49,   286,   183,   188,   293,   191,    85,   194,    99,    96,
     198,    54,   184,   202,   272,   102,   205,    82,    83,   209,
     195,    90,   212,   199,    66,   215,    62,    63,   317,   219,
      77,    78,   222,   223,    56,   213,     1,     2,     3,     4,
       5,     6,     7,   108,    68,   141,   304,   109,   305,   248,
     249,   318,   297,   298,   257,   258,   301,   324,   325,   315,
     294,    74,   296,   170,   166,    58,   168,   175,    59,   306,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     274,   275,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   217,   203,    87,   220,   206,   116,    46,   210,    47,
     237,   238,   239,   240,   216,   243,   149,   247,    92,   250,
      93,   252,   157,   115,   159,    37,    38,    39,    40,    41,
      42,    43,    44,   225,   104,   229,   105,   232,   256,   236,
     268,   269,   118,   273,    30,    31,    32,    33,    70,    71,
      72,   226,   227,   228,   233,   234,   235,   244,   245,   246,
     279,   280,   281,   283,   284,   285,   111,   230,   112,   231,
     299,   302,   300,   303,   307,   311,   310,   314,   316,   224,
     319,   289,   290,   308,   309,   253,   254,   276,   277,   120,
     320,   321,   122,   131,   322,   323,   133,   326,   327,   135,
     137,   143,   147,   150,   155,   160,   162,   172,   177,   179,
     186,   189,   192,   196,   200,   207,   171,   251,   211,   295,
     255,   221,   214,     0,     0,     0,   128,   130
};

static const yytype_int16 yycheck[] =
{
     109,    82,    96,    34,    12,    36,    12,    12,    14,    37,
      78,    12,    18,    10,    45,    12,    35,    48,    12,    50,
      39,    34,   170,   171,    55,   173,    57,    46,    12,    60,
      12,    34,    51,    64,    65,    18,    67,    56,    69,    34,
      35,    34,    73,    36,    75,    58,    12,   159,    79,   161,
      18,   163,    80,    84,    57,    86,    74,    88,    66,    64,
      91,    67,    81,    94,    57,    66,    97,    64,    65,   100,
      89,    65,   103,    92,    14,   106,    59,    60,    34,   110,
      62,    63,   113,   114,    12,   104,     3,     4,     5,     6,
       7,     8,     9,    59,    14,    47,    34,    63,    36,    28,
      29,    57,   183,   184,    30,    31,   187,   216,   217,   203,
     178,    59,   180,    70,    66,    15,    68,    74,    18,    57,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      28,    29,    68,    69,    70,    71,    72,    73,    74,    75,
      76,   108,    95,    12,   111,    98,    32,    12,   101,    14,
     127,   128,   129,   130,   107,   132,    53,   134,    12,   136,
      14,   138,    59,     0,    61,    10,    11,    12,    13,    14,
      15,    16,    17,   117,    12,   119,    14,   121,   146,   123,
     148,   149,    32,   151,    10,    11,    12,    13,    59,    60,
      61,    22,    23,    24,    19,    20,    21,    25,    26,    27,
      33,    34,    35,    33,    34,    35,    59,    34,    61,    36,
      34,    34,    36,    36,   195,   199,   197,   201,   206,    33,
     208,    34,    35,    34,    35,   140,   141,   156,   157,    32,
     210,   211,    32,    32,   213,   214,    32,   220,   221,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    71,    33,   102,    33,
      35,   112,   105,    -1,    -1,    -1,    38,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    78,    79,
      10,    11,    12,    13,    80,    12,    81,    10,    11,    12,
      13,    14,    15,    16,    17,    82,    12,    14,    83,    18,
      84,    12,    14,    18,    67,    85,    12,    86,    15,    18,
      87,    18,    59,    60,    88,    89,    14,    90,    14,    91,
      59,    60,    61,    92,    59,    93,    12,    62,    63,    94,
      10,    12,    64,    65,    95,    74,    96,    12,    97,    12,
      65,    98,    12,    14,    99,    12,    64,   100,    12,    66,
     101,    12,    66,   102,    12,    14,   103,    12,    59,    63,
     104,    59,    61,   105,   106,     0,    32,   114,    32,   116,
      32,   117,    32,   115,    79,   117,    79,   114,   116,   117,
     115,    32,   111,    32,   108,    32,   110,    32,   113,    79,
     117,   111,    79,    32,   107,    79,   117,    32,   112,   107,
      32,   123,    79,   117,    79,    32,   109,   107,    79,   107,
      32,   119,    32,   118,    79,    79,   111,    79,   111,    79,
     119,   118,    32,   120,    79,   119,    79,    32,   122,    32,
     121,    94,    79,   114,   117,    95,    32,   125,    79,    32,
     129,    79,    32,   126,    79,   117,    32,   127,    79,   117,
      32,   128,    79,   122,   100,    79,   122,    32,   124,    79,
     122,   124,    79,   117,   128,    79,   122,   119,   104,    79,
     119,   120,    79,    79,    33,    80,    22,    23,    24,    80,
      34,    36,    80,    19,    20,    21,    80,    82,    82,    82,
      82,    34,    35,    82,    25,    26,    27,    82,    28,    29,
      82,    33,    82,    83,    83,    35,    85,    30,    31,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    85,    85,
      34,    36,    57,    85,    28,    29,    87,    87,    88,    33,
      34,    35,    88,    33,    34,    35,    88,    92,    92,    34,
      35,    92,    34,    57,    94,    33,    94,    95,    95,    34,
      36,    95,    34,    36,    34,    36,    57,    98,    34,    35,
      98,    99,    34,    58,    99,   100,   101,    34,    57,   101,
     102,   102,   103,   103,   104,   104,   105,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      84,    84,    85,    85,    85,    85,    85,    86,    86,    87,
      87,    87,    88,    88,    88,    88,    89,    90,    90,    91,
      91,    92,    92,    92,    92,    93,    93,    94,    94,    94,
      94,    95,    95,    95,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   101,
     101,   101,   102,   102,   102,   103,   103,   103,   104,   104,
     104,   104,   105,   105,   105,   106,   107,   108,   108,   108,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   113,   114,   115,
     115,   115,   116,   116,   116,   117,   117,   118,   118,   118,
     119,   119,   119,   120,   120,   121,   122,   122,   123,   123,
     123,   124,   124,   125,   125,   126,   126,   126,   127,   127,
     128,   128,   129,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     3,     3,     3,     3,     0,     2,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     3,     3,     0,
       2,     0,     3,     3,     3,     3,     0,     2,     0,     3,
       3,     0,     3,     3,     3,     0,     0,     2,     0,     2,
       0,     3,     3,     3,     0,     2,     0,     3,     3,     2,
       0,     3,     2,     3,     3,     0,     2,     0,     2,     0,
       3,     3,     0,     3,     3,     0,     3,     2,     0,     3,
       3,     0,     3,     3,     0,     3,     3,     0,     3,     2,
       3,     0,     3,     3,     0,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3:
#line 172 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mkdisk"); (yyval.nodo)->agregar((yyvsp[-1].nodo)); raiz->agregar((yyval.nodo));}
#line 1628 "parser.cpp"
    break;

  case 4:
#line 173 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","rmdisk"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1634 "parser.cpp"
    break;

  case 5:
#line 174 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","fdisk"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1640 "parser.cpp"
    break;

  case 6:
#line 175 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mount"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1646 "parser.cpp"
    break;

  case 7:
#line 176 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","unmount"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1652 "parser.cpp"
    break;

  case 8:
#line 177 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","rep"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1658 "parser.cpp"
    break;

  case 9:
#line 178 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","exec"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1664 "parser.cpp"
    break;

  case 10:
#line 179 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mkfs"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1670 "parser.cpp"
    break;

  case 11:
#line 180 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","login"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1676 "parser.cpp"
    break;

  case 12:
#line 181 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","logout"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1682 "parser.cpp"
    break;

  case 13:
#line 183 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mkgrp"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1688 "parser.cpp"
    break;

  case 14:
#line 184 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","rmgrp"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1694 "parser.cpp"
    break;

  case 15:
#line 185 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mkusr"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1700 "parser.cpp"
    break;

  case 16:
#line 186 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","rmusr"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1706 "parser.cpp"
    break;

  case 17:
#line 188 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","chmod"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1712 "parser.cpp"
    break;

  case 18:
#line 189 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mkfile"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1718 "parser.cpp"
    break;

  case 19:
#line 190 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","cat"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1724 "parser.cpp"
    break;

  case 20:
#line 191 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","rem"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1730 "parser.cpp"
    break;

  case 21:
#line 192 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","edit"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1736 "parser.cpp"
    break;

  case 22:
#line 193 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","ren"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1742 "parser.cpp"
    break;

  case 23:
#line 194 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mkdir"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1748 "parser.cpp"
    break;

  case 24:
#line 195 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","cp"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1754 "parser.cpp"
    break;

  case 25:
#line 196 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","mv"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1760 "parser.cpp"
    break;

  case 26:
#line 197 "parser.y"
                                {(yyval.nodo)=new nodoSimple("---","find"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1766 "parser.cpp"
    break;

  case 27:
#line 198 "parser.y"
                                {(yyval.nodo)=new nodoSimple("---","chown"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1772 "parser.cpp"
    break;

  case 28:
#line 199 "parser.y"
                              {(yyval.nodo)=new nodoSimple("---","chgrp"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1778 "parser.cpp"
    break;

  case 29:
#line 200 "parser.y"
                                {(yyval.nodo)=new nodoSimple("---","pause"); (yyval.nodo)->agregar((yyvsp[-1].nodo));raiz->agregar((yyval.nodo));}
#line 1784 "parser.cpp"
    break;

  case 30:
#line 201 "parser.y"
                              {(yyval.nodo)=new nodoSimple("FIN","---");}
#line 1790 "parser.cpp"
    break;

  case 31:
#line 211 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1796 "parser.cpp"
    break;

  case 32:
#line 212 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1802 "parser.cpp"
    break;

  case 33:
#line 213 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1808 "parser.cpp"
    break;

  case 34:
#line 214 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1814 "parser.cpp"
    break;

  case 35:
#line 215 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1820 "parser.cpp"
    break;

  case 36:
#line 220 "parser.y"
                 {(yyval.nodo)=(yyvsp[0].nodo);}
#line 1826 "parser.cpp"
    break;

  case 37:
#line 221 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1832 "parser.cpp"
    break;

  case 38:
#line 225 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1838 "parser.cpp"
    break;

  case 39:
#line 226 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1844 "parser.cpp"
    break;

  case 40:
#line 227 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1850 "parser.cpp"
    break;

  case 41:
#line 228 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1856 "parser.cpp"
    break;

  case 42:
#line 229 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1862 "parser.cpp"
    break;

  case 43:
#line 230 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1868 "parser.cpp"
    break;

  case 44:
#line 231 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1874 "parser.cpp"
    break;

  case 45:
#line 232 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1880 "parser.cpp"
    break;

  case 46:
#line 233 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1886 "parser.cpp"
    break;

  case 47:
#line 237 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1892 "parser.cpp"
    break;

  case 48:
#line 238 "parser.y"
                      {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1898 "parser.cpp"
    break;

  case 49:
#line 239 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1904 "parser.cpp"
    break;

  case 50:
#line 243 "parser.y"
            {(yyval.nodo)=(yyvsp[0].nodo);}
#line 1910 "parser.cpp"
    break;

  case 51:
#line 244 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1916 "parser.cpp"
    break;

  case 52:
#line 248 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1922 "parser.cpp"
    break;

  case 53:
#line 249 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1928 "parser.cpp"
    break;

  case 54:
#line 250 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1934 "parser.cpp"
    break;

  case 55:
#line 251 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1940 "parser.cpp"
    break;

  case 56:
#line 252 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1946 "parser.cpp"
    break;

  case 57:
#line 256 "parser.y"
                {(yyval.nodo)=(yyvsp[0].nodo);}
#line 1952 "parser.cpp"
    break;

  case 58:
#line 257 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1958 "parser.cpp"
    break;

  case 59:
#line 261 "parser.y"
                          {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1964 "parser.cpp"
    break;

  case 60:
#line 262 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1970 "parser.cpp"
    break;

  case 61:
#line 263 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 1976 "parser.cpp"
    break;

  case 62:
#line 267 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1982 "parser.cpp"
    break;

  case 63:
#line 268 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1988 "parser.cpp"
    break;

  case 64:
#line 269 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 1994 "parser.cpp"
    break;

  case 65:
#line 270 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2000 "parser.cpp"
    break;

  case 66:
#line 274 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2006 "parser.cpp"
    break;

  case 67:
#line 278 "parser.y"
                {(yyval.nodo)=(yyvsp[0].nodo);}
#line 2012 "parser.cpp"
    break;

  case 68:
#line 279 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2018 "parser.cpp"
    break;

  case 69:
#line 283 "parser.y"
                {(yyval.nodo)=(yyvsp[0].nodo);}
#line 2024 "parser.cpp"
    break;

  case 70:
#line 284 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2030 "parser.cpp"
    break;

  case 71:
#line 288 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2036 "parser.cpp"
    break;

  case 72:
#line 289 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2042 "parser.cpp"
    break;

  case 73:
#line 290 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2048 "parser.cpp"
    break;

  case 74:
#line 291 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2054 "parser.cpp"
    break;

  case 75:
#line 295 "parser.y"
                {(yyval.nodo)=(yyvsp[0].nodo);}
#line 2060 "parser.cpp"
    break;

  case 76:
#line 296 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2066 "parser.cpp"
    break;

  case 77:
#line 300 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2072 "parser.cpp"
    break;

  case 78:
#line 301 "parser.y"
                            {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2078 "parser.cpp"
    break;

  case 79:
#line 302 "parser.y"
                            {(yyval.nodo)=new nodoSimple("r","r");(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo)); }
#line 2084 "parser.cpp"
    break;

  case 80:
#line 303 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2090 "parser.cpp"
    break;

  case 81:
#line 307 "parser.y"
                       {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2096 "parser.cpp"
    break;

  case 82:
#line 308 "parser.y"
                       {(yyval.nodo)=new nodoSimple("p","p");(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo)); }
#line 2102 "parser.cpp"
    break;

  case 83:
#line 309 "parser.y"
                       {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2108 "parser.cpp"
    break;

  case 84:
#line 310 "parser.y"
                       {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2114 "parser.cpp"
    break;

  case 85:
#line 311 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2120 "parser.cpp"
    break;

  case 86:
#line 315 "parser.y"
                {(yyval.nodo)=(yyvsp[0].nodo);}
#line 2126 "parser.cpp"
    break;

  case 87:
#line 316 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2132 "parser.cpp"
    break;

  case 88:
#line 320 "parser.y"
                    {(yyval.nodo)=(yyvsp[0].nodo);}
#line 2138 "parser.cpp"
    break;

  case 89:
#line 321 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2144 "parser.cpp"
    break;

  case 90:
#line 325 "parser.y"
                            {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2150 "parser.cpp"
    break;

  case 91:
#line 326 "parser.y"
                            {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2156 "parser.cpp"
    break;

  case 92:
#line 327 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2162 "parser.cpp"
    break;

  case 93:
#line 331 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2168 "parser.cpp"
    break;

  case 94:
#line 332 "parser.y"
                        {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2174 "parser.cpp"
    break;

  case 95:
#line 333 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2180 "parser.cpp"
    break;

  case 96:
#line 337 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2186 "parser.cpp"
    break;

  case 97:
#line 338 "parser.y"
                            {(yyval.nodo)=new nodoSimple("p","p");(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo)); }
#line 2192 "parser.cpp"
    break;

  case 98:
#line 339 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2198 "parser.cpp"
    break;

  case 99:
#line 343 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2204 "parser.cpp"
    break;

  case 100:
#line 344 "parser.y"
                            {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2210 "parser.cpp"
    break;

  case 101:
#line 345 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2216 "parser.cpp"
    break;

  case 102:
#line 349 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2222 "parser.cpp"
    break;

  case 103:
#line 350 "parser.y"
                            {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2228 "parser.cpp"
    break;

  case 104:
#line 351 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2234 "parser.cpp"
    break;

  case 105:
#line 356 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2240 "parser.cpp"
    break;

  case 106:
#line 357 "parser.y"
                         {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2246 "parser.cpp"
    break;

  case 107:
#line 358 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2252 "parser.cpp"
    break;

  case 108:
#line 362 "parser.y"
                          {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2258 "parser.cpp"
    break;

  case 109:
#line 363 "parser.y"
                             {(yyval.nodo)=new nodoSimple("r","r");(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo)); }
#line 2264 "parser.cpp"
    break;

  case 110:
#line 364 "parser.y"
                             {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2270 "parser.cpp"
    break;

  case 111:
#line 365 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2276 "parser.cpp"
    break;

  case 112:
#line 369 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2282 "parser.cpp"
    break;

  case 113:
#line 370 "parser.y"
                    {(yyval.nodo)=(yyvsp[-1].nodo);(yyval.nodo)->agregarSiguiente((yyvsp[0].nodo));}
#line 2288 "parser.cpp"
    break;

  case 114:
#line 371 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2294 "parser.cpp"
    break;

  case 115:
#line 375 "parser.y"
      {(yyval.nodo)=new nodoSimple("VACIO","---");}
#line 2300 "parser.cpp"
    break;

  case 116:
#line 382 "parser.y"
                          {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"id"); }
#line 2306 "parser.cpp"
    break;

  case 117:
#line 386 "parser.y"
              {(yyval.nodo)=new nodoSimple("p","type"); }
#line 2312 "parser.cpp"
    break;

  case 118:
#line 387 "parser.y"
              {(yyval.nodo)=new nodoSimple("e","type"); }
#line 2318 "parser.cpp"
    break;

  case 119:
#line 388 "parser.y"
              {(yyval.nodo)=new nodoSimple("l","type"); }
#line 2324 "parser.cpp"
    break;

  case 120:
#line 392 "parser.y"
                 {(yyval.nodo)=new nodoSimple("full","type"); }
#line 2330 "parser.cpp"
    break;

  case 121:
#line 393 "parser.y"
                 {(yyval.nodo)=new nodoSimple("fast","type"); }
#line 2336 "parser.cpp"
    break;

  case 122:
#line 397 "parser.y"
                 {(yyval.nodo)=new nodoSimple("fast","del"); }
#line 2342 "parser.cpp"
    break;

  case 123:
#line 398 "parser.y"
                 {(yyval.nodo)=new nodoSimple("full","del"); }
#line 2348 "parser.cpp"
    break;

  case 124:
#line 402 "parser.y"
                          {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"name"); }
#line 2354 "parser.cpp"
    break;

  case 125:
#line 403 "parser.y"
                          {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"name"); }
#line 2360 "parser.cpp"
    break;

  case 126:
#line 408 "parser.y"
                        {(yyval.nodo)=new nodoSimple("mbr","name"); }
#line 2366 "parser.cpp"
    break;

  case 127:
#line 409 "parser.y"
                        {(yyval.nodo)=new nodoSimple("disk","name"); }
#line 2372 "parser.cpp"
    break;

  case 128:
#line 410 "parser.y"
                        {(yyval.nodo)=new nodoSimple("inode","name"); }
#line 2378 "parser.cpp"
    break;

  case 129:
#line 411 "parser.y"
                        {(yyval.nodo)=new nodoSimple("journaling","name"); }
#line 2384 "parser.cpp"
    break;

  case 130:
#line 412 "parser.y"
                        {(yyval.nodo)=new nodoSimple("block","name"); }
#line 2390 "parser.cpp"
    break;

  case 131:
#line 413 "parser.y"
                        {(yyval.nodo)=new nodoSimple("bm_inode","name"); }
#line 2396 "parser.cpp"
    break;

  case 132:
#line 414 "parser.y"
                        {(yyval.nodo)=new nodoSimple("bm_block","name"); }
#line 2402 "parser.cpp"
    break;

  case 133:
#line 415 "parser.y"
                        {(yyval.nodo)=new nodoSimple("tree","name"); }
#line 2408 "parser.cpp"
    break;

  case 134:
#line 416 "parser.y"
                        {(yyval.nodo)=new nodoSimple("sb","name"); }
#line 2414 "parser.cpp"
    break;

  case 135:
#line 417 "parser.y"
                        {(yyval.nodo)=new nodoSimple("file","name"); }
#line 2420 "parser.cpp"
    break;

  case 136:
#line 418 "parser.y"
                        {(yyval.nodo)=new nodoSimple("ls","name"); }
#line 2426 "parser.cpp"
    break;

  case 137:
#line 422 "parser.y"
                   {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"add"); }
#line 2432 "parser.cpp"
    break;

  case 138:
#line 427 "parser.y"
                   {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"size"); }
#line 2438 "parser.cpp"
    break;

  case 139:
#line 431 "parser.y"
               {(yyval.nodo)=new nodoSimple("bf","fit"); }
#line 2444 "parser.cpp"
    break;

  case 140:
#line 432 "parser.y"
               {(yyval.nodo)=new nodoSimple("ff","fit"); }
#line 2450 "parser.cpp"
    break;

  case 141:
#line 433 "parser.y"
               {(yyval.nodo)=new nodoSimple("wf","fit"); }
#line 2456 "parser.cpp"
    break;

  case 142:
#line 437 "parser.y"
              {(yyval.nodo)=new nodoSimple("k","unit"); }
#line 2462 "parser.cpp"
    break;

  case 143:
#line 438 "parser.y"
              {(yyval.nodo)=new nodoSimple("m","unit"); }
#line 2468 "parser.cpp"
    break;

  case 144:
#line 439 "parser.y"
              {(yyval.nodo)=new nodoSimple("b","unit"); }
#line 2474 "parser.cpp"
    break;

  case 145:
#line 443 "parser.y"
                   {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"path"); }
#line 2480 "parser.cpp"
    break;

  case 146:
#line 444 "parser.y"
                   {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"path"); }
#line 2486 "parser.cpp"
    break;

  case 147:
#line 448 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"pwd"); }
#line 2492 "parser.cpp"
    break;

  case 148:
#line 449 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"pwd"); }
#line 2498 "parser.cpp"
    break;

  case 149:
#line 450 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"pwd"); }
#line 2504 "parser.cpp"
    break;

  case 150:
#line 454 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"usr"); }
#line 2510 "parser.cpp"
    break;

  case 151:
#line 455 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"usr"); }
#line 2516 "parser.cpp"
    break;

  case 152:
#line 456 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"usr"); }
#line 2522 "parser.cpp"
    break;

  case 153:
#line 460 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"grp"); }
#line 2528 "parser.cpp"
    break;

  case 154:
#line 461 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"grp"); }
#line 2534 "parser.cpp"
    break;

  case 155:
#line 465 "parser.y"
                    {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"ugo"); }
#line 2540 "parser.cpp"
    break;

  case 156:
#line 469 "parser.y"
                     {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"path"); }
#line 2546 "parser.cpp"
    break;

  case 157:
#line 470 "parser.y"
                        {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"path"); }
#line 2552 "parser.cpp"
    break;

  case 158:
#line 474 "parser.y"
                     {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"ruta"); }
#line 2558 "parser.cpp"
    break;

  case 159:
#line 475 "parser.y"
                     {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"ruta"); }
#line 2564 "parser.cpp"
    break;

  case 160:
#line 476 "parser.y"
                     {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"ruta"); }
#line 2570 "parser.cpp"
    break;

  case 161:
#line 481 "parser.y"
                      {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"dest"); }
#line 2576 "parser.cpp"
    break;

  case 162:
#line 482 "parser.y"
                         {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"dest"); }
#line 2582 "parser.cpp"
    break;

  case 163:
#line 486 "parser.y"
                    {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"cont"); }
#line 2588 "parser.cpp"
    break;

  case 164:
#line 487 "parser.y"
                    {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"cont"); }
#line 2594 "parser.cpp"
    break;

  case 165:
#line 491 "parser.y"
                        {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"path"); }
#line 2600 "parser.cpp"
    break;

  case 166:
#line 492 "parser.y"
                        {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"path"); }
#line 2606 "parser.cpp"
    break;

  case 167:
#line 493 "parser.y"
                     {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"path"); }
#line 2612 "parser.cpp"
    break;

  case 168:
#line 497 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"cont"); }
#line 2618 "parser.cpp"
    break;

  case 169:
#line 498 "parser.y"
                            {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"cont"); }
#line 2624 "parser.cpp"
    break;

  case 170:
#line 502 "parser.y"
                        {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"name"); }
#line 2630 "parser.cpp"
    break;

  case 171:
#line 503 "parser.y"
                        {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"name"); }
#line 2636 "parser.cpp"
    break;

  case 172:
#line 507 "parser.y"
                    {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"file"); }
#line 2642 "parser.cpp"
    break;

  case 173:
#line 508 "parser.y"
                    {(yyval.nodo)=new nodoSimple((yyvsp[0].text),"file"); }
#line 2648 "parser.cpp"
    break;


#line 2652 "parser.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
