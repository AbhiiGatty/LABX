%{
#include<stdio.h>
%}
%token A B
%%
E:A E
 |B
%%
int main()
{
	printf("Enter the string\n");
	yyparse();
	printf("Valid String\n");
}
yyerror()
{
	printf("Invalid String\n");
	exit(0);
}
