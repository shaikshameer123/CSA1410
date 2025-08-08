#include <stdio.h>
#include <string.h>
int main()
{
	char a[20];
	int index[10],n=0,flag=0;
	printf("Enter the Production:");
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='>' || a[i]=='|')
		{
			index[n++]=i+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[0]==a[index[i]])
		{
			printf("Left Recursion Present!!\n");
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Left Recursion Not Present!!");
		return 0;
	}
	printf("%c->");
	for(int i=index[n-1];i<strlen(a);i++) printf("%c",a[i]);
	printf("%c'\n%c'->",a[0],a[0]);
	for(int i=index[n-2]+1;i<strlen(a);i++)
	{
		if(a[i]=='|') break;
		printf("%c",a[i]);
	}
	printf("%c'|eps",a[0]);
}
