%{
    #define keyword                 101
    #define identifier              102
    #define string_literal          103
    #define floating_constant       104
    #define char_constant           105
    #define enumeration_constant    106
    #define integer_constant        107
    #define punctuator              108
    #define single_line_comment     109
    #define multiple_line_comment   110
    #define invalid_token           111
%}

%x   body_of_single_line_comment
%x   body_of_multiple_line_comment

keyword                "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"
escape_sequence        "\\\'"|"\\\""|"\\?"|"\\\\"|"\\a"|"\\b"|"\\f"|"\\n"|"\\r"|"\\t"|"\\v"
punctuator             "["|"++"|"/"|"?"|"="|","|"]"|"("|"{"|"}"|"."|"->"|"*"|"+"|"-"|"~"|"!"|"%"|"<<"|">>"|"<"|">"|"<="|">="|":"|";"|"..."|"*="|"/="|"%="|"+="|"-="|"<<="|"#"|"--"|")"|"&"|"=="|"^"|"|"|"&&"|">>="|"!="|"&="|"^="|"||"|"|"

identifier             [A-Za-z_][A-Za-z0-9_]*

digit                  [0-9]
digit_sequence         {digit}+
NON_ZERO_digit         [1-9]
integer_constant       {NON_ZERO_digit}{digit}*|"0"
sign                   [+-]?

exponent               [eE]{sign}{digit_sequence}
fraction_constant      {digit_sequence}?\.{digit_sequence}|{digit_sequence}\.
floating_constant      {fraction_constant}({exponent}?)|{digit_sequence}{exponent}

enumeration_constant   {identifier}

s_char                  [^\"\n\\]|{escape_sequence}
s_char_sequence         {s_char}+
string_literal          \"({s_char_sequence}?)\"

c_char                  [^\'\n\\]|{escape_sequence}
c_char_sequence         {c_char}+
char_constant           \'{c_char_sequence}\'

whitespace              [ \t\n]

%%

{keyword}                       { return keyword; }
{identifier}                    { return identifier; }
{integer_constant}              { return integer_constant; }
{floating_constant}             { return floating_constant; }
{char_constant}                 { return char_constant; }
{string_literal}                { return string_literal; }
{punctuator}                    { return punctuator; }


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