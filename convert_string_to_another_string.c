#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int,int,int);
int main()
{
	char *c=(char*)malloc(10*sizeof(char));
	char *c1=(char*)malloc(10*sizeof(char));
	printf("enter first string\n");
	int i=0,j;
	char ch;
	while((ch=getchar())!='\n')
	{
		c[i]=ch;
		i++;
		if(i>strlen(c)-1)
			c=(char*)realloc(c,sizeof(c)+10);
	}
	c[i]='\0';
	i=0;
	printf("enter secound string\n");
	while((ch=getchar())!='\n')
	{
		c1[i]=ch;
		i++;
		if(i>strlen(c1)-1)
			c1=(char*)realloc(c1,sizeof(c1)+10);
	}
	c1[i]='\0';
	int matrix[strlen(c)+1][strlen(c1)+1];
	int value;
	for(i=0;i<=strlen(c);i++)
	{
		for(j=0;j<=strlen(c1);j++)
		{
			if(i==0)
			{
				matrix[i][j]=j;
			}
			else if(j==0)
			{
				matrix[i][j]=i;
			}
			else
			{
				if(c[i-1]!=c1[j-1]||i!=j)
				{
					value=min(matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1])+1;
				}	
				else
				{
					value=matrix[i-1][j-1];
				}
				matrix[i][j]=value;
			}		
		}
	}
	for(i=0;i<=strlen(c);i++)// A Naive recursive C++ program to find minimum number

	{
		for(j=0;j<=strlen(c1);j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	
}
int min(int a,int b,int c)
{
	if(a<b)
	{
		if(a<c)
			return a;
	}
	else if(b<c)
		return b;
	else
		return c;
}