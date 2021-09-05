%{
#include "scanner.h"
%}

tabulation [ \t]+
nexline [ \n]+
whitespace {tabulation}*{nexline}*
identifier [a-zA-Z][_a-zA-Z0-9]*
integer [1-9][0-9]*
arguments [{identifier}{whitespace},]*{whitespace}{identifier}{whitespace}
condition (!?)({identifier}(<|>|==|<=|>=|!=|\||&){identifier})
artihmeticExpression {identifier}(\+|\*|\/|-|=){identifier}
shortCondition (!?){identifier}
conditions (!?){condition}(\||&)*{condition}
functionCall {identifier}"("{arguments}*")"

return "return"{whitespace}({identifier}|{functionCall}|{conditions}|{condition}|{artihmeticExpression}|{integer}){whitespace}
inValidReturn "return"{whitespace}[^({identifier}|{functionCall}|{conditions}|{condition}|{artihmeticExpression}|{integer})]{whitespace}

validIfStatement "if"{whitespace}"("{whitespace}({identifier}|{functionCall}|{conditions}|{condition}|{integer}){whitespace}")"{whitespace}
invalidIfStatement "if"{whitespace}"("{whitespace}[^({identifier}|{functionCall}|{conditions}|{condition}|{integer})]{whitespace}")"{whitespace}

validWhileStatement "while"{whitespace}"("{whitespace}({identifier}|{functionCall}|{conditions}|{condition}|{integer}){whitespace}")"{whitespace}
invalidWhileStatement "while"{whitespace}"("{whitespace}[^({identifier}|{functionCall}|{conditions}|{condition}|{integer})]{whitespace}")"{whitespace}
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
{validIfStatement} return IF;
{invalidIfStatement} return INVALID_IF;
{validWhileStatement} return WHILE;
{invalidWhileStatement} return INVALID_WHILE;
"else" 	 return ELSE;
"do"    return DO;
{return}	 return RETURN;
{inValidReturn}	 return INVALID_RETURN;
"int" return TYPE;
{identifier} return IDENTIFIER;
{integer} return INTEGER;
"{"      return OPENBRACKET;
"}"      return CLOSEBRACKET;
"("      return OPENPARENTHESE;
")"      return CLOSEPARENTHESE;
"print("{identifier}")" return PRINT_FUNCTION;
"read()" return READ_FUNCTION;
"int main()" return MAINFUNCTION;
{conditions} return CONDITION;
{shortCondition} return CONDITION;
{functionCall} return FUNCTION_CALL;
"int"{whitespace}{identifier}"("{arguments}*")" return FUNCTION_DEFINITION;
"void"{whitespace}{identifier}"("{arguments}*")" return FUNCTION_DEFINITION;
.   printf("Unexpexted character\n");

%%

int yywrap(){
	printf("\t File Scanned\n");
	return -1;
}