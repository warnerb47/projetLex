#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern char *yytext;
int isOperator(char *string);
int main(void)
{
    int currentToken, nextToken, countLine = 1, mainCreated = 0;
    int bracketCounter = 0, parentheseCounter = 0;
    currentToken = yylex();
    while (currentToken)
    {
        switch (currentToken)
        {
        case NEXTLINE:
            // printf("retourd à la ligne\n");
            countLine++;
            break;
        case INTEGER_TYPE:
            printf("type simple de valeur %s à la ligne %d\n", yytext, countLine);
            break;
        case IDENTIFIER:
            printf("identificateur de valeur %s à la ligne %d\n", yytext, countLine);
            break;
        case WITHESPACE:
            break;
        case MAINFUNCTION:
            if (mainCreated)
            {
                printf("Syntax error in line %d, Main function exist already \n", countLine);
            }
            else
            {
                mainCreated = 1;
                nextToken = yylex();
                if (
                    nextToken == SEMICOLON ||
                    isOperator(yytext) ||
                    nextToken == INTEGER_TYPE ||
                    nextToken == OPENBRACKET ||
                    nextToken == OPENPARENTHESE ||
                    nextToken == CLOSEBRACKET ||
                    nextToken == CLOSEPARENTHESE ||
                    nextToken == MAINFUNCTION)
                {
                    printf("Syntax error in line %d, Expected  identifier \n", countLine + 1);
                }
            }

            break;
        case INVALID_IF:
            printf("Syntax error in line %d, `%s`\n", countLine, yytext);
            break;
        case ELSE:
            printf("ELSE `%s` found at line %d\n", yytext, countLine);
            break;
        case WHILE:
            printf("WHILE `%s` found at line %d\n", yytext, countLine);
            break;
        case DO:
            printf("DO `%s` found at line %d\n", yytext, countLine);
            break;
        case RETURN:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` but found %s \n", countLine, yytext);
            }
            break;
        case INVALID_RETURN:
            printf("Syntax error in line %d\n", countLine);
            break;
        case OPERATOR:
            printf("OPERATOR `%s` found at line %d\n", yytext, countLine);
            break;
        case PRINT_FUNCTION:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` but found %s \n", countLine, yytext);
            }
            break;
        case READ_FUNCTION:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` but found %s \n", countLine, yytext);
            }
            // printf("READ_FUNCTION `%s` found at line %d\n", yytext, countLine);
            break;

        case FUNCTION_CALL:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` but found %s \n", countLine, yytext);
            }
            // printf("FUNCTION_CALL `%s` found at line %d\n", yytext, countLine);
            break;
        case FUNCTION_DEFINITION:
            printf("FUNCTION_DEFINITION found at line %d\n", countLine);
            break;
        case INTEGER_DECLARATION:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` but found %s \n", countLine, yytext);
            }
            break;
        case INVALID_INTEGER_DECLARATION:
            printf("Syntax error in line %d, invalid declaration \n", countLine);
            break;
        case TABLE_DECLARATION:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` but found %s \n", countLine, yytext);
            }
            break;
        case INVALID_TABLE_DECLARATION:
            printf("Syntax error in line %d, invalid declaration \n", countLine);
            break;
        case OPENPARENTHESE:
            printf("symbole de valeur %s à la ligne %d\n", yytext, countLine);
            parentheseCounter++;
            break;
        case CLOSEPARENTHESE:
            printf("symbole de valeur %s à la ligne %d\n", yytext, countLine);
            parentheseCounter--;
            break;
        case OPENBRACKET:
            printf("symbole de valeur %s à la ligne %d\n", yytext, countLine);
            bracketCounter++;
            break;
        case CLOSEBRACKET:
            printf("symbole de valeur %s à la ligne %d\n", yytext, countLine);
            bracketCounter--;
            break;
        case CONDITION:
            printf("CONDITION found at line %d\n", countLine);
            break;
            // default:
            //     printf("Syntax error in line %d\n",countLine);
            //     return 1;
        }
        currentToken = yylex();
    }
    if (parentheseCounter != 0)
    {
        printf("Unexpected end of file please close opened parentheses\n");
    }
    if (bracketCounter != 0)
    {
        printf("Unexpected end of file please close opened brackets\n");
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