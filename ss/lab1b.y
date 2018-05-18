%{
#include<stdio.h>
int result;
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
S:E {result=$1;}
E:E'+'E {$$=$1+$3;}
 |E'*'E {$$=$1*$3;}
 |E'-'E {$$=$1-$3;}
 |E'/'E {if($3==0)
	{
		printf("No cannot divide by zero\n");
		exit(0);
	}
	else
	{
		$$=$1/$3;
	}
	}
 |'('E')' {$$=$2;}
 |NUM {$$=$1;}
%%
int main()
{
	printf("Enter the expression\n");
	yyparse();
	printf("Valid expression\n");
	printf("Result of an expression is %d\n",result);
}
yyerror()
{
	printf("Invalid expression\n");
	exit(0);
}
