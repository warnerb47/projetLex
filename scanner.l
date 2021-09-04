%{
#include "scanner.h"
%}

whitespace [ \t]+
identifier [a-zA-Z][_a-zA-Z0-9]*
arguments [{identifier}","]*
%%
\n  return NEXTLINE;
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
"int main()" return MAINFUNCTION;
{identifier}"()" return FUNCTION_CALL;
.   printf("Unexpexted character at line %d\n", yylineno);

%%

int yywrap(){
	printf("\t File Scanned\n");
	return -1;
}