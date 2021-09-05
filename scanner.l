%{
#include "scanner.h"
%}

tabulation [ \t]+
nexline [ \n]+
whitespace {tabulation}*{nexline}*
identifier [a-zA-Z][_a-zA-Z0-9]*
integer [1-9][0-9]*

%%


{nexline}  return NEXTLINE;
{whitespace} return WITHESPACE;


";" return SEMICOLON;
"=" return AFFECT;
"+" return PLUS;
"-" return MINUS;
"*" return TIMES;
"<" return INFERIOR;
"<=" return INFERIOR_EQUAL;
">" return SUPERIOR;
">=" return SUPERIOR_EQUAL;
"==" return EQUAL;
"&" return AND;
"/" return DIVIDE;
"!" return NOT;
"|" return OR;
"{"      return OPENBRACKET;
"}"      return CLOSEBRACKET;
"("      return OPENPARENTHESE;
")"      return CLOSEPARENTHESE;

"if" return IF;
"while" return WHILE;
"else" 	 return ELSE;
"do"    return DO;
"return"	 return RETURN;
"int" return INTEGER_TYPE;
"ecrire" return PRINT_FUNCTION;
"lire" return READ_FUNCTION;


{identifier} return IDENTIFIER;


{integer} return INTEGER;


.   printf("Unexpexted character\n");

%%

int yywrap(){
	printf("\t File Scanned\n");
	return -1;
}