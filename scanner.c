#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern char *yytext;
int isOperator(char *string);
int main(void)
{
    int currentToken, countLine = 1;
    currentToken = yylex();
    while (currentToken)
    {
        switch (currentToken)
        {
            case NEXTLINE:
                countLine++;
                break;
            case WITHESPACE:
                break;
            case SEMICOLON:
            case AFFECT:
            case PLUS:
            case MINUS:
            case TIMES:
            case INFERIOR:
            case INFERIOR_EQUAL:
            case SUPERIOR:
            case SUPERIOR_EQUAL:
            case EQUAL:
            case AND:
            case DIVIDE:
            case NOT:
            case OR:
            case OPENBRACKET:
            case CLOSEBRACKET:
            case OPENPARENTHESE:
            case CLOSEPARENTHESE:
                printf("symboles `%s` found at ligne %d\n", yytext, countLine);
                break;
            case IF:
            case WHILE:
            case ELSE:
            case DO:
            case RETURN:
            case INTEGER_TYPE:
            case PRINT_FUNCTION:
            case READ_FUNCTION:
                printf("Keyword `%s` found at ligne %d\n", yytext, countLine);
                break;
            case IDENTIFIER:
                printf("Identifier `%s` found at ligne %d\n", yytext, countLine);
                break;
            case INTEGER:
                printf("litteral integer `%s` found at ligne %d\n", yytext, countLine);
                break;
            default:
                printf("Syntax error in line %d\n", countLine);
                return 1;
        }
        currentToken = yylex();
    }
    return 0;
}

int isOperator(char *string)
{
    return string == "=" |
           string == "==" |
           string == "+" |
           string == "-" |
           string == "*" |
           string == "<" |
           string == ">" |
           string == "<=" |
           string == ">=" |
           string == "&" |
           string == "/" |
           string == "!" |
           string == "<>" |
           string == "|" |
           string == "/";
}