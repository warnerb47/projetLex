    #include<stdio.h>
    #include "scanner.h"

    extern int yylex();
    extern int yylineno;
    extern char* yytext;

    int main(void) {
        int currentToken, nextToken;
        currentToken = yylex();
        while (currentToken)
        {
            // printf("currentToken = %d \n", currentToken);
            switch (currentToken) {
                case WITHESPACE:
                    break;
                case MAINFUNCTION:
                    nextToken = yylex();
                    if (
                        nextToken == SEMICOLON ||
                        nextToken == OPERATOR ||
                        nextToken == INTEGER ||
                        nextToken == OPENBRACKET ||
                        nextToken == OPENPATENTHESE ||
                        nextToken == MAINFUNCTION
                    )
                    {
                        printf("Syntax error in line %d, Expected  identifier \n", yylineno);
                        return 1;
                    }
                    // printf("main function `%s` found at line %d\n", yytext, yylineno);
                    break;
                case TYPE:
                    if(nextToken != IDENTIFIER) {
                        printf("Syntax error in line %d, Expected an identifier but found %s\n", yylineno+1, yytext);
                        return 1;
                    }
                    printf("TYPE `%s` found at line %d\n", yytext, yylineno);
                    break;
                case IF:
                    printf("if `%s` found at line %d\n", yytext, yylineno);
                    break;
                case ELSE:
                    printf("ELSE `%s` found at line %d\n", yytext, yylineno);
                    break;
                case WHILE:
                    printf("WHILE `%s` found at line %d\n", yytext, yylineno);
                    break;
                case DO:
                    printf("DO `%s` found at line %d\n", yytext, yylineno);
                    break;
                case RETURN:
                    printf("RETURN `%s` found at line %d\n", yytext, yylineno);
                    break;
                case OPERATOR:
                    printf("OPERATOR `%s` found at line %d\n", yytext, yylineno);
                    break;
                case PRINT_FUNCTION:
                    printf("PRINT_FUNCTION `%s` found at line %d\n", yytext, yylineno);
                    break;
                case READ_FUNCTION:
                    printf("READ_FUNCTION `%s` found at line %d\n", yytext, yylineno);
                    break;
                
                case FUNCTION_CALL:
                    printf("FUNCTION_CALL `%s` found at line %d\n", yytext, yylineno);
                    break;
                // default:
                //     printf("Syntax error in line %d\n",yylineno);
                //     return 1;
            }
            currentToken = yylex();
        }
        return 0;
    }