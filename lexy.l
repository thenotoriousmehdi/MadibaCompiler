%{
#include "s.tab.h"
#include <stdlib.h>



// Initialisation des variables globales
int lineNumber = 1;     // Ligne initiale
int columnNumber = 1;   // Colonne initiale



%}
%option noyywrap


%%

"import"            {  return IMPORT; }
"program"           { return PROGRAM; }
"const"             { return CONST; }
"var"               { return VAR; }
"types"             { return TYPES; }
"functions"         { return FUNCTIONS; }
"main"              { return MAIN; }
"int"               { return INT; }
"float"             { return FLOAT; }
"char"              { return CHAR; }
"bool"              { return BOOL; }
"string"            { return STRING; }
"cst"               { return CST; }
"Object"            { return OBJECT; }
"enum"              { return ENUM; }
"function"          { return FUNCTION; }
"for"               { return FOR; }
"while"             { return WHILE; }
"if"                { return IF; }
"else"              { return ELSE; }
"scan"              { return SCAN; }
"print"             { return PRINT; }
"return"            { return RETURN; }



"void"         {return VOID;}   
"true"          {yylval.strval = strdup(yytext); return TRUE;}
"false"        {yylval.strval = strdup(yytext); return FALSE;}




"--".*              { /* igonre les commentaires */ }
\*\*([^*]|\*+[^*/])*\*\*  { /* igonre les commentaires */ }
"AND"              { return AND; }
"OR"               { return OR; }
"NOT"              { return NOT; }

[a-zA-Z_][a-zA-Z0-9_]*\\.[a-zA-Z_][a-zA-Z0-9_]* { return OBJECT_FIELD; }
[a-zA-Z_][a-zA-Z0-9_]*  {     yylval.strval = strdup(yytext); 
                              return IDENTIFIER; }

[0-9]+                { yylval.intval = atoi(yytext); return INTEGER_LITERAL; }
[0-9]+\.[0-9]+        { yylval.floatval = atof(yytext); return FLOAT_LITERAL; }
\"([^\"]|\\.)\"         { yylval.charval = yytext[1]; return CHAR_LITERAL; }
\"([^\"]|\\.)*\"      { yylval.strval = strdup(yytext); return STRING_LITERAL; }


"=="                  { return EQUAL; }
"!="                  { return NOT_EQUAL; }
"<"                   { return LESS_THAN; }
">"                   { return GREATER_THAN; }
"<="                  { return LESS_EQUAL; }
">="                  { return GREATER_EQUAL; }
"+"                   { return PLUS; }
"-"                   { return MINUS; }
"*"                   { return MULTIPLY; }
"/"                   { return DIVIDE; }
"%"                   { return MODULO; }

","                   { return COMMA; }
"("                   { return OPEN_PAREN; }
")"                   { return CLOSE_PAREN; }
"["                   { return OPEN_BRACKET; }
"]"                   { return CLOSE_BRACKET; }
"{"                   { return OPEN_BRACE; }
"}"                   { return CLOSE_BRACE; }
";"                  { return SEMICOLON; }
"'"                  { return QUOTE; }
"="                   { return ASSIGN; }
[.]                            { return DOT; } 

":"            {return TWO_POINT ;}    


[\n] {
    lineNumber++;
    columnNumber = 1;
}


[ \t] {
    columnNumber += yyleng;
}

\r?\n {
    lineNumber++;
    columnNumber = 1;
}

. {
    printf(" Erreur lexicale concernant l'entite  %s ligne %d colonne %d \n",yytext , lineNumber , columnNumber);
    exit(1);
}


