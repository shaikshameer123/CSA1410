#include <stdio.h>
#include <string.h>
int opcount(char *s)
{
	int oc=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') oc++;
	}
	return oc;
}
int check(char s)
{
	if(s>='0' && s<='9') return 1;
	return 0;
}
char* postfix(char *s)
{
	char stack[20],a[20];
	int j=0,top=-1;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			a[j++]=s[i];
		}
		else if(s[i]=='+' || s[i]=='-')
		{
			if(top==-1)
			{
				stack[++top]=s[i];
			}
			else if(stack[top]=='+' || stack[top]=='-' || stack[top]=='*' || stack[top]=='/')
			{
				while(top!=-1)
				{
					a[j++]=stack[top--];
				}
				stack[++top]=s[i];
			}
			else stack[++top]=s[i];
		}
		else if(s[i]=='*' || s[i]=='/')
		{
			if(top==-1) stack[++top]=s[i];
			else if(stack[top]=='*' || stack[top]=='/')
			{
				while(stack[top]=='*' || stack[top]=='/')
				{
					a[j++]=stack[top--];
				}
				stack[++top]=s[i];
			}
			else stack[++top]=s[i];
		}
	}
	while(top!=-1) a[j++]=stack[top--];
	return a;
}
int main()
{
	char exp[10],stack[20],c='0';
	printf("Enter The Expression:");
	scanf("%s",exp);
	printf("...The Three Address Code...\n");
	int top=-1,j=0;
	strcpy(exp,postfix(exp));
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]>='a' && exp[i]<='z') stack[++top]=exp[i];
		else
		{
			printf("t%c=",c);
			if(check(stack[top-1])) printf("t%c",stack[top-1]);
			else printf("%c",stack[top-1]);
			printf("%c",exp[i]);
			if(check(stack[top])) printf("t%c\n",stack[top]);
			else printf("%c\n",stack[top]);
			top-=2;
			stack[++top]=c;
			c++;
		}
		if((c-'0')==opcount(exp)) break;
	}
}
