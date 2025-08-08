#include <stdio.h>
char input[10];
int i=0;
void E();
void EPRIME();
void T();
void TPRIME();
void F();
void E()
{
	T();
	EPRIME();
}
void EPRIME()
{
	if(input[i]=='+')
	{
		i++;
		T();
		EPRIME();
	}
}
void T()
{
	F();
	TPRIME();
}
void TPRIME()
{
	if(input[i]=='*')
	{
		i++;
		F();
		TPRIME();
	}
}
void F()
{
	if(input[i]=='(')
	{
		i++;
		E();
		if(input[i]==')') i++;
	}
	else if(input[i]>='a' && input[i]<='z') i++;
}
int main()
{
	printf("Enter the Expression:");
	scanf("%s",input);
	E();
	if(input[i]=='\0') printf("Parsing Succeed!!");
	else printf("Syntax Error!!");
}
