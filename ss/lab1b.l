%{
#include"y.tab.h"
extern int yylval;
%}
num [0-9]+
%%
{num} {yylval=atoi(yytext);return NUM;}
. {return yytext[0];}
\n {return 0;}
%%
