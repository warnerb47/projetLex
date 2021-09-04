%{
#include "scanner.h"
%}

whitespace [ \t\n]+
identifier [a-zA-Z][_a-zA-Z0-9]*
manFunction "int"{whitespace}"main()"{whitespace}*"{"
arguments [{identifier}","]*
%%
\n { yylineno++; }
{whitespace} return WITHESPACE;
";" return SEMICOLON;
"=" return OPERATOR;
"+" return OPERATOR;
"-" return OPERATOR;
"*" return OPERATOR;
"<" return OPERATOR;
"<=" return OPERATOR;
">" return OPERATOR;
">=" return OPERATOR;
"==" return OPERATOR;
"&" return OPERATOR;
"/" return OPERATOR;
"!" return OPERATOR;
"if"       return IF;
"else" 	 return ELSE;
"while"    return WHILE;
"do"    return DO;
"return"	 return RETURN;
"int" return TYPE;
{identifier} return IDENTIFIER;
[1-9][0-9]* return INTEGER;
"{"      return OPENBRACKET;
"}"      return CLOSEBRACKET;
"("      return OPENPATENTHESE;
")"      return CLOSEPATENTHESE;
"print("{identifier}")" return PRINT_FUNCTION;
"read()" return READ_FUNCTION;
{identifier}"()" return FUNCTION_CALL;
.   printf("Unexpexted character\n");

%%

int yywrap(){
	printf("\t Fin de fichier detecte !\n");
	return -1;
}