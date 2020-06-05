/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 300 "sem.y" /* yacc.c:1909  */

		int ival;
		char *str;
	

#line 102 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
