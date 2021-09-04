%{
#include "scanner.h"
%}

whitespace [ \t]+
identifier [a-zA-Z][_a-zA-Z0-9]*
arguments [{identifier}{whitespace}*,]*{whitespace}*{identifier}{whitespace}*
condition (!?)({identifier}(<|>|==|<=|>=|!=|\||&){identifier})
shortCondition (!?){identifier}
conditions (!?){condition}(\||&)*{condition}
%%
"\n"  return NEXTLINE;
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
"if("{condition}")" return IF;
"if("{conditions}")" return IF;
"if("{identifier}")" return IF;
"if(!"{identifier}")" return IF;
"else" 	 return ELSE;
"while("{condition}")" return WHILE;
"while("{conditions}")" return WHILE;
"while("{identifier}")" return WHILE;
"while(!"{identifier}")" return WHILE;
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
{conditions} return CONDITION;
{shortCondition} return CONDITION;
{identifier}"("{arguments}*")" return FUNCTION_CALL;
"int"{whitespace}{identifier}"("{arguments}*")" return FUNCTION_DEFINITION;
"void"{whitespace}{identifier}"("{arguments}*")" return FUNCTION_DEFINITION;
.   printf("Unexpexted character\n");

%%

int yywrap(){
	printf("\t File Scanned\n");
	return -1;
}