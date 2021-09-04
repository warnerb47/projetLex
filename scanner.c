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
            switch (currentToken) {
                case NEXTLINE:
                    // printf("retourd à la ligne\n");
                    yylineno++;
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
                        nextToken == CLOSEBRACKET ||
                        nextToken == CLOSEPATENTHESE ||
                        nextToken == MAINFUNCTION
                    )
                    {
                        printf("Syntax error in line %d, Expected  identifier \n", yylineno+1);
                    }
                    // printf("main function  found at line %d\n", yylineno);
                    break;
                // case TYPE:
                //     if(nextToken != IDENTIFIER) {
                //         printf("Syntax error in line %d, Expected an identifier but found %s\n", yylineno+1, yytext);
                //         return 1;
                //     }
                //     printf("TYPE `%s` found at line %d\n", yytext, yylineno);
                //     break;
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
                    nextToken = yylex();
                    if (nextToken != SEMICOLON)
                    {
                        printf("Syntax error in line %d, Expected  `;` \n", yylineno);
                    }
                    // printf("PRINT_FUNCTION `%s` found at line %d\n", yytext, yylineno);
                    break;
                case READ_FUNCTION:
                    nextToken = yylex();
                    if (nextToken != SEMICOLON)
                    {
                        printf("Syntax error in line %d, Expected  `;` \n", yylineno);
                    }
                    // printf("READ_FUNCTION `%s` found at line %d\n", yytext, yylineno);
                    break;
                
                case FUNCTION_CALL:
                    nextToken = yylex();
                    if (nextToken != SEMICOLON)
                    {
                        printf("Syntax error in line %d, Expected  `;` \n", yylineno);
                    }
                    // printf("FUNCTION_CALL `%s` found at line %d\n", yytext, yylineno);
                    break;
                // default:
                //     printf("Syntax error in line %d\n",yylineno);
                //     return 1;
            }
            currentToken = yylex();
        }
        return 0;
    }