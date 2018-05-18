%{
#include<stdio.h>
#include<string.h>
int id=0;
char ident[10][10];
char opc[10];
int op=0;
int c=0;
%}
%%
[0-9]+ {strcpy(ident[id],yytext); id++;}
[+ *]  {opc[op]=yytext[0]; op++;}
[(] c++;
[)] c--;
.   ;
%%

void main()
{
	int i=0;
	printf("Enter exprssion\n");
	yylex();
	{
	if(c==0&&id==op+1){
	printf("Valid\n");
	printf("Number of identifiers%d\n",id);
	printf("Number of operators%d\n",op);
	printf("Identifiers are:\n");
	for(i=0;i<id;i++)
	{
	printf("%s\t",ident[i]);
	}
	printf("\nOperators are:\n");
	for(i=0;i<op;i++)
	{
		printf("%c\t",opc[i]);
	}
	printf("\n");
	}
	else{
		printf("Invalid\n");
	}
	}
}


