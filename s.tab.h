
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 128 "s.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


