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
    char *yytext;
#endif

int main()
{
    // char yytext[1000];
    int token;
    int lineno = 1;
    while (token = yylex())
    {
        if(token == keyword)
            printf("<Line : %d, KEYWORD, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == identifier)
            printf("<Line : %d, IDENTIFIER, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == string_literal)
            printf("<Line : %d, STRING, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == floating_constant)
            printf("<Line : %d, FLOAT, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == character_constant)
            printf("<Line : %d, CHARACTER, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == enumeration_constant)
            printf("<Line : %d, ENUM, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == integer_constant)
            printf("<Line : %d, INTEGER, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == punctuator)
            printf("<Line : %d, PUNCTUATOR, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == single_line_comment)
            printf("<Line : %d, SINGLE LINE COMMENT, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == multi_line_comment)
            printf("<Line : %d, MULT-LINE COMMENT, Token : %d, %s>\n", lineno++, token, yytext);
        else if(token == invalid_token)
            printf("<Line : %d, INVALID TOKEN, Token : %d, %s>\n", lineno++, token, yytext);;    
    }
    return 0;
}
