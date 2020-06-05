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
#line 1 "sem.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	int g_addr = 100;
	int i=1;
	int j=8;
	int stack[100];
	int index1=0;
	int end[100];
	int arr[10];
	int gl1,gl2,curr_type=0,c=0,b;
	int type=258;
	int fname[100];
	int nP;
	int fTypes[100];
	int fTypes2[100];
	int temptype;
	int it;
	int temp;

	struct sym
	{
		int sno;
		char token[100];
		int type[100];
		int tn;
		int addr;
		float fvalue;
		int scope;
		int arrFlag;
		int fType[100]; 
		int numParams; 
	}st[100];

	int n=0,arr[10];

	void storereturn( int curr_type, int returntype )
	{
		arr[curr_type] = returntype;
		return;
	}

	void insertscope(char *a,int s)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				st[i].scope=s;
				break;
			}
		}
	}

	int returntype_func(int ct)
	{
		return arr[ct-1];
	}

	int isArray(char* a)
	{
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				if(st[i].arrFlag==1)
					return st[i].fvalue;
						else
							return 0;
			 }
		}
		return 0;
	}

	int retNumParams(char* a)
	{
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				return st[i].numParams;
			}
		}
		return 0;
	}

	void getParams(char* a)
	{
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				for(int j=0; j<st[i].numParams; j++)
					fTypes[j] = st[i].fType[j]; 
			}
		}
		return 0;
	}
	int returnscope(char *a,int cs)
	{
		//printf("\nString is: %s", a);
		int i;
		int max = 0;
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token))
			{
				if(st[i].scope>=max)
					max = st[i].scope;
			}
		}
		return max;
	}

	int lookup(char *a)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if( !strcmp( a, st[i].token) )
				return 0;
		}
		return 1;
	}

	int returntype(char *a,int scope_curr)
	{
		int i;
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token) && st[i].scope==scope_curr)
				return st[i].type[0];
		}
	}

	void update_value(char *a,char *b,int sc)
	{
		int i,j,k;
		int max=0;
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token)   && sc>=st[i].scope)
			{
				if(st[i].scope>=max)
					max=st[i].scope;
			}
		}
		for(i=0;i<=n;i++)
		{
			if(!strcmp(a,st[i].token)   && max==st[i].scope)
			{
				float temp=atof(b);
				for(k=0;k<st[i].tn;k++)
				{
					if(st[i].type[k]==258||st[i].type[0]==269)
						st[i].fvalue=(int)temp;
					else
						st[i].fvalue=temp;
				}
			}
		}
	}

	void insert(char *name, int type, int addr, int arrFlag)
	{
		int i;
		if(lookup(name))
		{
			strcpy(st[n].token,name);
			st[n].tn=1;
			st[n].type[st[n].tn-1]=type;
			st[n].addr=addr;
			st[n].sno=n+1;
			st[n].arrFlag = arrFlag;
			n++;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(!strcmp(name,st[i].token))
				{
					st[i].tn++;
					st[i].type[st[i].tn-1]=type;
					break;
				}
			}
		}

		return;
	}
	void insertFunc(char *name, int type, int addr, int arrFlag, int params[100], int numParams)
	{
		int i;
		if(lookup(name))
		{
			strcpy(st[n].token,name);
			st[n].tn=1;
			st[n].type[st[n].tn-1]=type;
			st[n].addr=addr;
			st[n].sno=n+1;
			st[n].arrFlag = arrFlag;
			for(int j=0; j<numParams; j++)
				st[n].fType[j] = params[j];
			st[n].numParams = numParams;
			n++;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(!strcmp(name,st[i].token))
				{
					st[i].tn++;
					st[i].type[st[i].tn-1]=type;
					break;
				}
			}
		}

		return;
	}
	void insert_dup(char *name, int type, int addr,int s_c, int arrFlag)
	{
		strcpy(st[n].token,name);
		st[n].tn=1;
		st[n].type[st[n].tn-1]=type;
		st[n].addr=addr;
		st[n].sno=n+1;
		st[n].scope=s_c;
		st[n].arrFlag=arrFlag;
		n++;
		return;
	}

	void print()
	{
		int i,j;
		printf("\nSymbol Table\n\n");
		printf("\nSNo.\tToken\tAddress\tValue\tScope\tIsArray\tType\t                 Params\n");
		for(i=0;i<n;i++)
		{
			if(st[i].type[0]==258 || st[i].type[0]==261|| st[i].type[0]==262|| st[i].type[0]==263)
				printf("%d\t%s\t%d\t%d\t%d\t%d",st[i].sno,st[i].token,st[i].addr,(int)st[i].fvalue,st[i].scope, st[i].arrFlag);
			else
				printf("%d\t%s\t%d\t%.1f\t%d\t%d",st[i].sno,st[i].token,st[i].addr,st[i].fvalue,st[i].scope, st[i].arrFlag);
			for(j=0;j<st[i].tn;j++)
			{
				if(st[i].type[j]==258)
					printf("\tINT");
				else if(st[i].type[j]==259)
					printf("\tFLOAT");
				else if(st[i].type[j]==274)
					printf("\tFUNCTION");
				else if(st[i].type[j]==269)
					printf("\tARRAY");
				else if(st[i].type[j]==260)
					printf("\tVOID");
				else if(st[i].type[j]==261)
			  		printf("\tUNSIGNED INT");
				else if(st[i].type[j]==263)
			    		printf("\tLONG INT");
				else if(st[i].type[j]==262)
			      		printf("\tSHORT INT");
			}
			for(int j=0;j<st[i].numParams;j++)
			{
				if(st[i].fType[j]==258)
					printf("\tINT");
				else if(st[i].fType[j]==259)
					printf("\tFLOAT");
				else if(st[i].fType[j]==274)
					printf("\tFUNCTION");
				else if(st[i].fType[j]==269)
					printf("\tARRAY");
				else if(st[i].fType[j]==260)
					printf("\tVOID");
				else if(st[i].fType[j]==261)
			  		printf("\tUNSIGNED INT");
				else if(st[i].fType[j]==263)
			    		printf("\tLONG INT");
				else if(st[i].fType[j]==262)
			      		printf("\tSHORT INT");
			}
			printf("\n");
		}
		return;
	}

#line 357 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    UNSIGNED_INT = 261,
    S_INT = 262,
    L_INT = 263,
    ID = 264,
    INT_CONST = 265,
    FLOAT_CONST = 266,
    WHILE = 267,
    IF = 268,
    RETURN = 269,
    PREPROC = 270,
    LE = 271,
    STRING = 272,
    PRINT = 273,
    FUNCTION = 274,
    ARRAY = 275,
    ELSE = 276
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define UNSIGNED_INT 261
#define S_INT 262
#define L_INT 263
#define ID 264
#define INT_CONST 265
#define FLOAT_CONST 266
#define WHILE 267
#define IF 268
#define RETURN 269
#define PREPROC 270
#define LE 271
#define STRING 272
#define PRINT 273
#define FUNCTION 274
#define ARRAY 275
#define ELSE 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 300 "sem.y" /* yacc.c:355  */

		int ival;
		char *str;
	

#line 442 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 459 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   276

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
      23,    24,    33,    31,    25,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   307,   307,   308,   309,   310,   314,   330,   348,   349,
     352,   353,   354,   355,   356,   357,   361,   365,   366,   367,
     371,   372,   373,   374,   375,   381,   382,   383,   384,   387,
     404,   414,   415,   416,   417,   421,   422,   426,   430,   431,
     434,   454,   462,   463,   464,   472,   473,   476,   491,   519,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     565,   566,   570,   597,   618,   632,   642
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "UNSIGNED_INT",
  "S_INT", "L_INT", "ID", "INT_CONST", "FLOAT_CONST", "WHILE", "IF",
  "RETURN", "PREPROC", "LE", "STRING", "PRINT", "FUNCTION", "ARRAY",
  "ELSE", "'='", "'('", "')'", "','", "'{'", "'}'", "';'", "'['", "']'",
  "'+'", "'-'", "'*'", "'/'", "$accept", "start", "Function", "param_list",
  "Type", "compound_stmt", "statement_list", "stmt", "function_call",
  "call_list", "if_stmt", "while_stmt", "expr1", "secondary_assignment",
  "assignment_exp", "exp", "consttype", "Declaration", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    61,    40,    41,    44,   123,   125,    59,    91,
      93,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -97

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    81,   -97,
     -97,    63,    39,     3,    63,    35,    25,   -97,   102,    60,
      63,   120,   120,    65,   -97,    58,   115,   -97,   -97,   -97,
     -14,   -97,    39,    39,    39,    39,   120,   -97,   -97,   -97,
      71,    80,   -97,    39,    39,    39,    39,     7,    88,   -97,
      92,   102,   102,   102,   102,   -97,    82,    78,   121,   126,
     132,   137,    85,   112,    34,   105,   142,    39,   -97,   -97,
     -97,   -97,   -97,   -97,   112,   -97,   112,   185,   -97,   116,
     102,   -97,   114,   -97,   153,   -97,   156,   128,   150,    19,
     159,   -97,   -97,   174,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,    32,   120,   120,   -97,   166,   178,   158,   -97,   168,
      74,   -97,    30,   -97,    41,   -97,   172,   -97,   170,    70,
     120,   112,   112,    39,   -97,   -97,   -97,   183,   -97,   179,
     143,   112,   173,   -97,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    66,    10,    11,    12,    13,    14,    15,    48,    60,
      61,     0,     0,     0,     0,     0,     0,    42,    45,    58,
       0,     0,     0,     0,     3,    48,     0,    58,     1,     2,
       0,    64,     0,     0,     0,     0,     0,     4,    40,    41,
       0,     0,    59,     0,     0,     0,     0,     0,     0,    63,
       0,    50,    51,    52,    53,    43,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    54,
      55,    56,    57,    62,    19,     6,     0,     0,     8,     0,
      47,    18,     0,     7,     0,    65,    48,     0,     0,     0,
       0,    16,    26,     0,    28,    17,    23,    21,    22,    20,
       9,     0,     0,     0,    25,     0,     0,     0,    31,     0,
       0,    32,     0,    39,     0,    24,     0,    30,     0,     0,
       0,     0,     0,     0,    29,    33,    34,    38,    37,    35,
       0,     0,     0,    36,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,    -1,   -97,   -97,   -37,   -70,   -97,   -97,   -97,   -97,
     -97,   -97,   -96,   -20,   -97,    -7,   -12,   122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    64,    15,    75,    82,    95,    96,   110,
      97,    98,   112,    16,    17,    18,    19,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    38,    39,    28,    81,    26,    83,   114,    47,    48,
      24,    65,    94,    29,    49,    50,    55,     9,    10,    37,
      27,    27,    27,    27,   127,    51,    52,    53,    54,     9,
      10,    27,    27,    27,    27,    62,    58,    59,    60,    61,
      84,   108,     9,    10,    30,    93,   120,   104,    25,     9,
      10,   128,   129,    31,   121,    27,   109,   120,    76,    77,
      80,   133,    12,    -5,     1,   122,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    40,   -46,   105,    11,   125,
       9,    10,   113,   113,   -46,    36,    12,    41,   -46,   111,
      57,     2,     3,     4,     5,     6,     7,   -44,   118,   119,
     113,    56,    66,    21,    67,   -44,    22,   126,    68,   -44,
      23,    27,    63,    73,    78,     1,   130,     2,     3,     4,
       5,     6,     7,    86,     9,    10,    87,    88,    89,     8,
       9,    10,    90,    32,    33,    34,    35,    12,    74,    42,
      74,    91,    92,    12,    85,    69,    43,    44,    45,    46,
      70,   102,    32,    33,    34,    35,    71,    32,    33,    34,
      35,    72,   100,    32,    33,    34,    35,   132,    32,    33,
      34,    35,    79,   103,    32,    33,    34,    35,    21,   101,
      47,    22,   106,   107,   -44,    23,    49,    50,     2,     3,
       4,     5,     6,     7,   115,   116,   117,   123,   124,   120,
     131,   134,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      12,    21,    22,     0,    74,    12,    76,   103,    22,    23,
      11,    48,    82,    14,    28,    29,    36,    10,    11,    20,
      32,    33,    34,    35,   120,    32,    33,    34,    35,    10,
      11,    43,    44,    45,    46,    47,    43,    44,    45,    46,
      77,     9,    10,    11,     9,    82,    16,    28,     9,    10,
      11,   121,   122,    28,    24,    67,    24,    16,    24,    25,
      67,   131,    23,     0,     1,    24,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    10,    16,    89,    15,     9,
      10,    11,   102,   103,    24,    25,    23,    29,    28,   101,
      10,     3,     4,     5,     6,     7,     8,    16,    24,    25,
     120,    30,    10,    22,    22,    24,    25,   119,    30,    28,
      29,   123,    24,    28,     9,     1,   123,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     9,
      10,    11,    18,    31,    32,    33,    34,    23,    26,    24,
      26,    27,    28,    23,    28,    24,    31,    32,    33,    34,
      24,    23,    31,    32,    33,    34,    24,    31,    32,    33,
      34,    24,     9,    31,    32,    33,    34,    24,    31,    32,
      33,    34,    30,    23,    31,    32,    33,    34,    22,    23,
      22,    25,    23,     9,    28,    29,    28,    29,     3,     4,
       5,     6,     7,     8,    28,    17,    28,    25,    28,    16,
      21,    28,    -1,    -1,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    15,    23,    36,    37,    39,    48,    49,    50,    51,
      52,    22,    25,    29,    36,     9,    50,    51,     0,    36,
       9,    28,    31,    32,    33,    34,    25,    36,    48,    48,
      10,    29,    24,    31,    32,    33,    34,    22,    23,    28,
      29,    50,    50,    50,    50,    48,    30,    10,    50,    50,
      50,    50,    51,    24,    38,    39,    10,    22,    30,    24,
      24,    24,    24,    28,    26,    40,    24,    25,     9,    30,
      50,    40,    41,    40,    39,    28,     9,    12,    13,    14,
      18,    27,    28,    39,    40,    42,    43,    45,    46,    52,
       9,    23,    23,    23,    28,    51,    23,     9,     9,    24,
      44,    51,    47,    48,    47,    28,    17,    28,    24,    25,
      16,    24,    24,    25,    28,     9,    51,    47,    40,    40,
      50,    21,    24,    40,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    36,    36,    37,    37,    38,    38,
      39,    39,    39,    39,    39,    39,    40,    41,    41,    41,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    43,
      43,    44,    44,    44,    44,    45,    45,    46,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    52,    52,    52,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     5,     6,     2,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     0,
       1,     1,     1,     1,     3,     2,     1,     7,     1,     5,
       4,     1,     1,     3,     3,     5,     7,     5,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     6,     1,     4,
       3,     3,     3,     3,     5,     5,     5,     5,     1,     3,
       1,     1,     5,     3,     2,     6,     1
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
        case 6:
#line 314 "sem.y" /* yacc.c:1646  */
    {
	 
	if ((yyvsp[-4].ival)!=returntype_func(curr_type))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-3].str),"printf") && strcmp((yyvsp[-3].str),"scanf") && strcmp((yyvsp[-3].str),"getc") && strcmp((yyvsp[-3].str),"gets") && strcmp((yyvsp[-3].str),"getchar") && strcmp	((yyvsp[-3].str),"puts") && strcmp((yyvsp[-3].str),"putchar") && strcmp((yyvsp[-3].str),"clearerr") && strcmp((yyvsp[-3].str),"getw") && strcmp((yyvsp[-3].str),"putw") && strcmp((yyvsp[-3].str),"putc") && strcmp((yyvsp[-3].str),"rewind") && strcmp((yyvsp[-3].str),"sprint") && strcmp((yyvsp[-3].str),"sscanf") && strcmp((yyvsp[-3].str),"remove") && strcmp((yyvsp[-3].str),"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
	else
	{
		insert((yyvsp[-3].str),FUNCTION,g_addr, 0);
		insert((yyvsp[-3].str),(yyvsp[-4].ival),g_addr, 0);
		g_addr+=4;
	}
	}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 330 "sem.y" /* yacc.c:1646  */
    {
	

	if ((yyvsp[-5].ival)!=returntype_func(curr_type))
	{
		printf("\nError : Type mismatch : Line %d\n",printline());
	}

	if (!(strcmp((yyvsp[-4].str),"printf") && strcmp((yyvsp[-4].str),"scanf") && strcmp((yyvsp[-4].str),"getc") && strcmp((yyvsp[-4].str),"gets") && strcmp((yyvsp[-4].str),"getchar") && strcmp	((yyvsp[-4].str),"puts") && strcmp((yyvsp[-4].str),"putchar") && strcmp((yyvsp[-4].str),"clearerr") && strcmp((yyvsp[-4].str),"getw") && strcmp((yyvsp[-4].str),"putw") && strcmp((yyvsp[-4].str),"putc") && strcmp((yyvsp[-4].str),"rewind") && strcmp((yyvsp[-4].str),"sprint") && strcmp((yyvsp[-4].str),"sscanf") && strcmp((yyvsp[-4].str),"remove") && strcmp((yyvsp[-4].str),"fflush")))
		printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-4].str),printline());
	else
	{
		insertFunc((yyvsp[-4].str),FUNCTION,g_addr, 0, fname, nP);
		insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr, 0);
		g_addr+=4;
	}
	}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 348 "sem.y" /* yacc.c:1646  */
    { nP = 1; fname[nP-1] = (yyvsp[-1].ival); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 349 "sem.y" /* yacc.c:1646  */
    { nP++; fname[nP-1] = (yyvsp[-1].ival); }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 375 "sem.y" /* yacc.c:1646  */
    {
					if(!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str))))
						storereturn(curr_type,FLOAT);
					else
						storereturn(curr_type,INT); curr_type++;
				}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 381 "sem.y" /* yacc.c:1646  */
    {storereturn(curr_type,VOID); curr_type++;}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 387 "sem.y" /* yacc.c:1646  */
    {
	if(lookup((yyvsp[-4].str)))
		printf("\nError: Undeclared function %s : Line %d\n", (yyvsp[-4].str), printline());
	else
	{
		if(retNumParams((yyvsp[-4].str)) == 0)
			printf("\nError : Parameter list does not match signature : Line %d\n", printline()); 
		getParams((yyvsp[-4].str));				
	}

	for(int j=0; j<retNumParams((yyvsp[-4].str)); j++)
	{
		if(fTypes[j] != fTypes2[j])
			printf("\nError : Parameter list does not match signature : Line %d\n", printline());
	}
	
}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 404 "sem.y" /* yacc.c:1646  */
    {
	if(lookup((yyvsp[-3].str)))
		printf("\nError: Undeclared function %s : Line %d\n", (yyvsp[-3].str), printline());
	else
	{
		if(retNumParams((yyvsp[-3].str)) != 0)
			printf("\nError : Parameter list does not match signature : Line %d\n", printline()); 
	}
}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "sem.y" /* yacc.c:1646  */
    { temptype = returntype((yyvsp[0].str), stack[index1-1]); it = 0; fTypes2[it] = temptype; }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "sem.y" /* yacc.c:1646  */
    { temptype = temp; it = 0; fTypes2[it] = temptype; }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "sem.y" /* yacc.c:1646  */
    { it++; temptype = returntype((yyvsp[0].str), stack[index1-1]); fTypes2[it] = temptype;}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "sem.y" /* yacc.c:1646  */
    { temptype = temp; it++; fTypes2[it] = temptype;}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 435 "sem.y" /* yacc.c:1646  */
    {
	  c=0;
		int scope_curr=returnscope((yyvsp[-2].str),stack[index1-1]);
		//printf("Scope: %d",scope_curr);
		int type=returntype((yyvsp[-2].str),scope_curr);
		if((!(strspn((yyvsp[0].str),"0123456789")==strlen((yyvsp[0].str)))) && type==258)
			printf("\nError : Type Mismatch : Line %d\n",printline());
		if(!lookup((yyvsp[-2].str)))
		{
			int currscope=stack[index1-1];
			int scope=returnscope((yyvsp[-2].str),currscope);
			if((scope<=currscope && end[scope]==0) && !(scope==0))
				update_value((yyvsp[-2].str),(yyvsp[0].str),currscope);
		}
		if(isArray((yyvsp[-2].str)))
				printf("\nError: Array Identfier has no subscript: Line %d\n", printline());

		}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 454 "sem.y" /* yacc.c:1646  */
    {
					if(lookup((yyvsp[-2].str)))
						printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());

						if(isArray((yyvsp[-2].str)))
								printf("\nError: Array identfier has no subscript: Line %d\n", printline());

				}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 464 "sem.y" /* yacc.c:1646  */
    {
		if(lookup((yyvsp[0].str)))
			printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());

			if(isArray((yyvsp[0].str)))
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 476 "sem.y" /* yacc.c:1646  */
    {
			if(lookup((yyvsp[-5].str)))
				printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-5].str),printline());

			if(isArray((yyvsp[-5].str))==0)
				printf("\nError: Non-array variable used as an array: Line %d\n", printline());

				float bound = isArray((yyvsp[-5].str));

				if(isArray((yyvsp[-5].str)) && (atoi((yyvsp[-3].str)) >= bound || atoi((yyvsp[-3].str)) < 0))
					printf("\nError: Array subscript out of bounds : Line %d\n", printline());

		}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 491 "sem.y" /* yacc.c:1646  */
    {
	if(isArray((yyvsp[0].str)))
	 printf("\nError: Array identifier has no subscript: Line %d\n", printline());

	if(c==0)
	{
		c=1;
		int scope_curr=returnscope((yyvsp[0].str),stack[index1-1]);
		b=returntype((yyvsp[0].str),scope_curr);
	}
	else
	{
		int scope_curr1=returnscope((yyvsp[0].str),stack[index1-1]);
		if(b!=returntype((yyvsp[0].str),scope_curr1))
			printf("\nError : Type Mismatch : Line %d\n",printline());
	}
	if(!lookup((yyvsp[0].str)))
	{
		int currscope=stack[index1-1];
		//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
		int scope=returnscope((yyvsp[0].str),currscope);
		//printf("Curr scope: %d %d\n", currscope,scope);
		if(!(scope<=currscope && end[scope]==0))
			printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[0].str),printline());
	}
  else
    printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
	}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 519 "sem.y" /* yacc.c:1646  */
    {
		if(c==0)
		{
			c=1;
			int scope_curr=returnscope((yyvsp[-3].str),stack[index1-1]);
			b=returntype((yyvsp[-3].str),scope_curr);
		}
		else
		{
			int scope_curr1=returnscope((yyvsp[-3].str),stack[index1-1]);
			if(b!=returntype((yyvsp[-3].str),scope_curr1))
				printf("\nError : Type Mismatch : Line %d\n",printline());
		}
		if(!lookup((yyvsp[-3].str)))
		{
			int currscope=stack[index1-1];
			//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
			int scope=returnscope((yyvsp[-3].str),currscope);
			//printf("Curr scope: %d %d\n", currscope,scope);
			if(!(scope<=currscope && end[scope]==0))
				printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-3].str),printline());
		}
	  else
	    printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-3].str),printline());

		if(isArray((yyvsp[-3].str))==0)
			printf("\nError: Non-array variable used as an array: Line %d\n", printline());

		float bound = isArray((yyvsp[-3].str));

		if(isArray((yyvsp[-3].str)) && (atoi((yyvsp[-1].str)) >= bound || atoi((yyvsp[-1].str)) < 0) )
			printf("\nError: Array subscript out of bounds : Line %d\n", printline());

		}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 565 "sem.y" /* yacc.c:1646  */
    { temp = 258;}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 566 "sem.y" /* yacc.c:1646  */
    { temp = 259;}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 571 "sem.y" /* yacc.c:1646  */
    {
			if( (!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && (yyvsp[-4].ival)==258)
				printf("\nError : Type Mismatch : Line %d\n",printline());

			if(!lookup((yyvsp[-3].str)))
			{
				int currscope=stack[index1-1];
				int previous_scope=returnscope((yyvsp[-3].str),currscope);
				if(currscope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
				else
				{
					insert_dup((yyvsp[-3].str),(yyvsp[-4].ival),g_addr,currscope, 0);
					update_value((yyvsp[-3].str),(yyvsp[-1].str),stack[index1-1]);
					g_addr+=4;
				}
			}
			else
			{
				int scope=stack[index1-1];
				insert((yyvsp[-3].str),(yyvsp[-4].ival),g_addr, 0);
				insertscope((yyvsp[-3].str),scope);
				update_value((yyvsp[-3].str),(yyvsp[-1].str),stack[index1-1]);
				g_addr+=4;
			}
		}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 597 "sem.y" /* yacc.c:1646  */
    {
		if(!lookup((yyvsp[-1].str)))
		{
			int currscope=stack[index1-1];
			int previous_scope=returnscope((yyvsp[-1].str),currscope);
			if(currscope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-1].str),printline());
			else
			{
				insert_dup((yyvsp[-1].str),(yyvsp[-2].ival),g_addr,currscope, 0);
				g_addr+=4;
			}
		}
		else
		{
			int scope=stack[index1-1];
			insert((yyvsp[-1].str),(yyvsp[-2].ival),g_addr, 0);
			insertscope((yyvsp[-1].str),scope);
			g_addr+=4;
		}
	}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 618 "sem.y" /* yacc.c:1646  */
    {
				if(!lookup((yyvsp[-1].str)))
				{
					int currscope=stack[index1-1];
					//printf("\ncurrscope%d Current Scope: %d\n", currscope, stack[index1-1]);
					int scope=returnscope((yyvsp[-1].str),currscope);
					//printf("Curr scope: %d %d\n", currscope,scope);
					if(!(scope<=currscope && end[scope]==0))
						printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				}
				else
					printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
				}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 632 "sem.y" /* yacc.c:1646  */
    {
						insert((yyvsp[-4].str),ARRAY,g_addr,1);
						insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr,1);
						update_value((yyvsp[-4].str),(yyvsp[-2].str),stack[index1-1]);
						g_addr+=4;
						if(atoi((yyvsp[-2].str))<=0)
						{
							printf("\nError: Illegal array subscript %d : Line %d\n", atoi((yyvsp[-2].str)), printline());
						}
					}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2005 "y.tab.c" /* yacc.c:1646  */
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
#line 645 "sem.y" /* yacc.c:1906  */


#include "lex.yy.c"
#include<ctype.h>
int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	if(!yyparse())
	{
		printf("Parsing done\n");
		print();
	}
	else
	{
		printf("Error\n");
	}
	fclose(yyin);
	return 0;
}

yyerror(char *s)
{
	printf("\nLine %d : %s %s\n",yylineno,s,yytext);
}

int printline()
{
	return yylineno;
}

void block_start()
{
	stack[index1]=i;
	i++;
	index1++;
	//printf("\n\nTop of stack changed to: %d at line %d", stack[index1-1], yylineno);
	return;
}

void block_end()
{
	index1--;
	//printf("\n\nTop of stack changed to: %d at line %d", stack[index1-1], yylineno);
	end[stack[index1]]=1;
	stack[index1]=0;
	return;
}
