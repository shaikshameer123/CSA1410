#include <stdio.h>
#include <string.h>
struct symbol
{
	char name[10];
	char val[10];
	char address[10];
};
struct table
{
	symbol s[20];
	int count;
};
table t;
void insert(char *n,char *v,char *a)
{
	strcpy(t.s[t.count].name,n);
	strcpy(t.s[t.count].val,v);
	strcpy(t.s[t.count].address,a);
	t.count++;
	printf("\nInsertion Succeed\n\n");
}
void search(char *n)
{
	for(int i=0;i<t.count;i++)
	{
		if(strcmp(t.s[i].name,n)==0)
		{
			printf("\nSymbol Found!!\n");
			printf("Symbol Value=%s\n",t.s[i].val);
			printf("Symbol Address=%s\n\n",t.s[i].address);
			return;
		}
	}
	printf("Symbol Not Found!!!\n\n");
}
void display()
{
	printf("\nSYMBOL NAME\t\tVALUE\t\tADDRESS\n");
	for(int i=0;i<t.count;i++)
	{
		printf("%s\t\t\t%s\t\t\t%s\n",t.s[i].name,t.s[i].val,t.s[i].address);
	}
	printf("\n");
}
int main()
{
	t.count=0;
	int c;
	char n[20],v[20],a[20];
	while(1)
	{
		printf("1.INSERT INTO SYMBOL TABLE\n2.SEARCH SYMBOL\n3.DISPLAT SYMBOL TABLE\nENTER CHOICE=");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the Name of the Symbol:");
				scanf("%s",n);
				printf("Enter the Value of the Symbol:");
				scanf("%s",v);
				printf("Enter the Address of the Symbol:");
				scanf("%s",a);
				insert(n,v,a);
				break;
			case 2:
				printf("Enter the Symbol to Search:");
				scanf("%s",n);
				search(n);
				break;
			case 3:
				display();
				break;
			default:
				printf("Invalid Operation!!\n\n");
		}
	}
}
