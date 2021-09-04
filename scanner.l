%{
#include "scanner.h"
%}

whitespace [ \t]+
identifier [a-zA-Z][_a-zA-Z0-9]*
arguments [{identifier}","]*
%%
"\n"  return NEXTLINE;
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
"("      return OPENPARENTHESE;
")"      return CLOSEPARENTHESE;
"print("{identifier}")" return PRINT_FUNCTION;
"read()" return READ_FUNCTION;
"int main()" return MAINFUNCTION;
{identifier}"()" return FUNCTION_CALL;
"int"{whitespace}{identifier}"()" return FUNCTION_DEFINITION;
"void"{whitespace}{identifier}"()" return FUNCTION_DEFINITION;
.   printf("Unexpexted character\n");

%%

int yywrap(){
	printf("\t File Scanned\n");
	return -1;
}