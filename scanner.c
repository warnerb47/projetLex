#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern char *yytext;

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
                    nextToken == OPERATOR ||
                    nextToken == INTEGER ||
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
        case IF:
            printf("if `%s` found at line %d\n", yytext, countLine);
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
            printf("RETURN `%s` found at line %d\n", yytext, countLine);
            break;
        case OPERATOR:
            printf("OPERATOR `%s` found at line %d\n", yytext, countLine);
            break;
        case PRINT_FUNCTION:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` \n", countLine);
            }
            break;
        case READ_FUNCTION:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` \n", countLine);
            }
            // printf("READ_FUNCTION `%s` found at line %d\n", yytext, countLine);
            break;

        case FUNCTION_CALL:
            nextToken = yylex();
            if (nextToken != SEMICOLON)
            {
                printf("Syntax error in line %d, Expected  `;` \n", countLine);
            }
            // printf("FUNCTION_CALL `%s` found at line %d\n", yytext, countLine);
            break;
        case OPENPARENTHESE:
            parentheseCounter++;
            break;
        case CLOSEPARENTHESE:
            parentheseCounter--;
            break;
        case OPENBRACKET:
            bracketCounter++;
            break;
        case CLOSEBRACKET:
            bracketCounter--;
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