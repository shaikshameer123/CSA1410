#include <stdio.h>
#include <string.h>
void code_gen(char op,char *arg1,char *arg2)
{
	if(!(op=='-')) printf("MOV %s,R0\n",arg1);
	if(op=='+')
	{
		printf("ADD %s,R0",arg2);
	}
	else if(op=='-')
	{
		printf("MOV %s,R0\n",arg2);
		printf("SUB %s,R0",arg1);
	}
	else if(op=='*')
	{
		printf("MUL %s,R0",arg1);
	}
	else if(op=='/')
	{
		printf("DIV %s,R0",arg1);
	}
	else
	{
		printf("Invalid Operation\n");
	}
}
int main()
{
	char op,arg1[5],arg2[5];
	printf("Enter the Expression:");
	scanf("%s %c %s",&arg1,&op,&arg2);
	printf("ASSEMBLY CODE\n");
	code_gen(op,arg1,arg2);
}
