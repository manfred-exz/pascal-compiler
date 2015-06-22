/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
