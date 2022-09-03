%{
    #define KEYWORD                 101
    #define IDENTIFIER              102
    #define STRING_LITERAL          103
    #define FLOATING_CONSTANT       104
    #define CHARACTER_CONSTANT      105
    #define ENUMERATION_CONSTANT    106
    #define INTEGER_CONSTANT        107
    #define PUNCTUATOR              108
    #define single_line_comment     109
    #define multiple_line_comment   110
    #define invalid_token           111
%}

%x   body_of_single_line_comment
%x   body_of_multiple_line_comment

KEYWORD                 "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"
escape_SEQUENCE         "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"
PUNCTUATOR              "["|"++"|"/"|"?"|"="|","|"]"|"("|"{"|"}"|"."|"->"|"*"|"+"|"-"|"~"|"!"|"%"|"<<"|">>"|"<"|">"|"<="|">="|":"|";"|"..."|"*="|"/="|"%="|"+="|"-="|"<<="|"#"|"--"|")"|"&"|"=="|"^"|"|"|"&&"|">>="|"!="|"&="|"^="|"||"|"|"

IDENTIFIER              [A-Za-z_][A-Za-z0-9_]*

DIGIT                   [0-9]
DIGIT_SEQUENCE          {DIGIT}+
NON_ZERO_DIGIT          [1-9]
INTEGER_CONSTANT        {NON_ZERO_DIGIT}{DIGIT}*|"0"

exponent                [eE]([-+]?){DIGIT_SEQUENCE}
fraction_constant       {DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}\.
FLOATING_CONSTANT       {fraction_constant}({exponent}?)|{DIGIT_SEQUENCE}{exponent}

ENUMERATION_CONSTANT    {IDENTIFIER}

s_char                  [^\"\n\\]|{escape_SEQUENCE}
s_char_SEQUENCE         {s_char}+
STRING_LITERAL          \"({s_char_SEQUENCE}?)\"

c_char                  [^\'\n\\]|{escape_SEQUENCE}
c_char_SEQUENCE         {c_char}+
CHARACTER_CONSTANT      \'{c_char_SEQUENCE}\'


whitespace              [ \t\n]

%%

{KEYWORD}                       { return KEYWORD; }
{IDENTIFIER}                    { return IDENTIFIER; }
{INTEGER_CONSTANT}              { return INTEGER_CONSTANT; }
{FLOATING_CONSTANT}             { return FLOATING_CONSTANT; }
{CHARACTER_CONSTANT}            { return CHARACTER_CONSTANT; }
{STRING_LITERAL}                { return STRING_LITERAL; }
{PUNCTUATOR}                    { return PUNCTUATOR; }


"/*"                                    { BEGIN(body_of_multiple_line_comment); }
<body_of_multiple_line_comment>"*/"     { BEGIN(INITIAL); return multiple_line_comment; }
<body_of_multiple_line_comment>.        { }
<body_of_multiple_line_comment>"\n"     { }

"//"                                    { BEGIN(body_of_single_line_comment); }
<body_of_single_line_comment>"\n"       { BEGIN(INITIAL); return single_line_comment; }
<body_of_single_line_comment>.          { }

{whitespace}          { }
.                     { return invalid_token; }

%%