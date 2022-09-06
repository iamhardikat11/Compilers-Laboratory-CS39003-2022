/*
 *   Compilers Labortary
 *   Compilers Assignment 3
 *   Hardik Pravin Soni - 20CS30023
 *   Saurabh Jaiswal - 20CS30047
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _DEFI
#define _DEFI
    int yylex();
    #define keyword                 101
    #define identifier              102
    #define string_literal          103
    #define floating_constant       104
    #define character_constant      105
    #define enumeration_constant    106
    #define integer_constant        107
    #define punctuator              108
    #define single_line_comment     109
    #define multi_line_comment      110
    #define invalid_token           111
    int yylineno;
    char *yytext;
#endif


int main()
{
    int token;
    while (token = yylex())
    {
        if(token == keyword)
            printf("<Line : %d, C-KEYWORD          , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == identifier)
            printf("<Line : %d, Valid IDENTIFIER   , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == string_literal)
            printf("<Line : %d, STRING  Literal    , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == floating_constant)
            printf("<Line : %d,   FLOAT            , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == character_constant)
            printf("<Line : %d, CHARACTER          , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == enumeration_constant)
            printf("<Line : %d, ENUM               , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == integer_constant)
            printf("<Line : %d, INTEGER            , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == punctuator)
            printf("<Line : %d, PUNCTUATOR         , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == single_line_comment)
            printf("<Line : %d, Single Comment     , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == multi_line_comment)
            printf("<Line : %d, MULTI-LINE COMMENT , Token : %d, %s>\n", yylineno, token, yytext);
        else if(token == invalid_token)
            printf("<Line : %d, INVALID TOKEN      , Token : %d, %s>\n", yylineno, token, yytext);;    
    }
    return 0;
}

