%option noyywrap yylineno case-insensitive

%{
#include "globals.h"
#include "y.tab.h"
#include "scan.h"

char tokenString[256];
%}

NQUOTE [^']

%%

"array"     return ARRAY; 
"and"       return AND; 
"begin"     return SBEGIN; 
"boolean"   return SBOOLEAN; 
"case"      return CASE; 
"char"      return SCHAR; 
"const"     return CONST; 
"do"        return DO; 
"downto"    return DOWNTO; 
"else"      return ELSE; 
"end"       return END; 
"false"     return FALSE; 
"for"       return FOR; 
"function"  return FUNCTION; 
"goto"      return GOTO; 
"if"        return IF; 
"integer"   return SINTEGER; 
"maxint"    return MAXINT; 
"mod"       return MOD; 
"not"       return NOT;
"of"        return OF; 
"or"        return OR; 
"procedure" return PROCEDURE; 
"program"   return PROGRAM; 
"real"      return SREAL; 
"record"    return RECORD; 
"repeat"    return REPEAT; 
"then"      return THEN; 
"to"        return TO; 
"true"      return TRUE; 
"type"      return TYPE; 
"until"     return UNTIL; 
"var"       return VAR; 
"while"     return WHILE; 

[a-zA-Z_]([a-zA-Z0-9_])*    return ID; 

":="        return ASSIGN; 
":"         return COLON; 
","         return COMMA; 
'({NQUOTE}|'')'     return CHAR; 
"/"         return DIV; 
"."         return DOT; 
".."        return DOTDOT; 
"="         return EQUAL; 
">="        return GE; 
">"         return GT; 
[0-9]+      return INTEGER; 
"["         return LB; 
"<="        return LE; 
"("         return LP; 
"<"         return LT; 
"-"         return MINUS; 
"*"         return MUL; 
"+"         return PLUS; 
"]"         return RB; 
[0-9]+"."[0-9]+     return REAL; 
")"         return RP; 
";"         return SEMI; 
'({NQUOTE}|'')+' return STRING; 
"<>"        return UNEQUAL; 

"(*"   |
"{"    { register int c;
     while ((c = input()))
     {
      if (c == '}')
       break;
      else if (c == '*')
      {
       if ((c = input()) == ')')
        break;
       else
        unput (c);
      }
      else if (c == '\n')
       lineno++;
     }
    }

[ \t\f]    ;

\n    lineno++;

%%

int getToken()
{
	static int firstTime = 1;
	int currentToken, i;

	if (firstTime){
		firstTime = 0;
		lineno++;
		yyin = source;
//		yyout = listing;
	}

	currentToken = yylex();

    switch(currentToken){
    case ID:
    case CHAR:
    case INTEGER:
    case REAL:
    case STRING:
		memset(tokenString, 0, sizeof(tokenString));
		strcpy(tokenString, yytext);
        break;
    }   
/*
	if (currentToken == ID || currentToken == CHAR || currentToken == INTEGER || currentToken == REAL || currentToken == STRING)
	{
		memset(tokenString, 0, sizeof(tokenString));
		strcpy(tokenString, yytext);
	}
*/

    // convert to lower-case tokens
	for (i = 0; tokenString[i]; i++)
		tokenString[i] = tolower(tokenString[i]);

	return currentToken;
}
