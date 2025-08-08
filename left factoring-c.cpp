#include <stdio.h>
#include <string.h>
int main()
{
	char a[20],s;
	int index[20],n=0,flag=0;
	printf("Enter the Production:");
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='>' || a[i]=='|')
		{
			index[n++]=i+1;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[index[i]]==a[index[i+1]])
		{
			printf("Left Factoring Present!!\n");
			s=a[index[i]];
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("No Left Factoring Present!!");
		return 0;
	}
	printf("%c->",a[0]);
	for(int i=0;i<n;i++)
	{
		if(a[index[i]]==s) continue;
		for(int j=index[i];j<strlen(a);j++)
		{
			if(a[j]==s) continue;
			if(a[j]=='|')
			{
				printf("|");
				break;
			}
			printf("%c",a[j]);
			if(a[j+1]=='\0') printf("|");
		}
	}
	printf("%c%c'",s,a[0]);
	printf("\n%c'->",a[0]);
	for(int i=3;i<strlen(a);i++)
	{
		if(a[i]==s)
		{
			flag=0;
			continue;
		}
		if(a[i]=='|')
		{
			if(a[i+1]==s) printf("|");
			flag=1;
			continue;
		}
		if(flag==0) printf("%c",a[i]);
	}
}
