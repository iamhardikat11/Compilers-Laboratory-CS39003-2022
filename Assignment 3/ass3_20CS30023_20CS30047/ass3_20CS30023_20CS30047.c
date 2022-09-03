#include <stdio.h>

#ifndef _DEFI
#define _DEFI
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
#endif

int main()
{
    int token;
    while (token = yylex())
    {
        if(token == keyword)
            printf("<Line: %d, KEYWORD, Token : %d, %s>", yyline, token, yytext);
        else if(token == identifier)
            printf("<Line: %d, IDENTIFIER, Token : %d, %s>", yyline, token, yytext);
        else if(token == string_literal)
            printf("<Line: %d, STRING, Token : %d, %s>", yyline, token, yytext);
        else if(token == floating_constant)
            printf("<Line: %d, FLOAT, Token : %d, %s>", yyline, token, yytext);
        else if(token == character_constant)
            printf("<Line: %d, CHARACTER, Token : %d, %s>", yyline, token, yytext);
        else if(token == enumeration_constant)
            printf("<Line: %d, ENUM, Token : %d, %s>", yyline, token, yytext);
        else if(token == integer_constant)
            printf("<Line: %d, INTEGER, Token : %d, %s>", yyline, token, yytext);
        else if(token == punctuator)
            printf("<Line: %d, PUNCTUATOR, Token : %d, %s>", yyline, token, yytext);
        else if(token == single_line_comment)
            printf("<Line: %d, SINGLE LINE COMMENT, Token : %d, %s>", yyline, token, yytext);
        else if(token == multi_line_comment)
            printf("<Line: %d, MULT-LINE COMMENT, Token : %d, %s>", yyline, token, yytext);
        else if(token == invalid_token)
            printf("<Line: %d, INVALID TOKEN, Token : %d, %s>", yyline, token, yytext);;    
    }
    return 0;
}
