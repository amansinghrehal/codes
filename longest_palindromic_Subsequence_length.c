#include<stdio.h>
#include<string.h>
int main()
{
	char str[1001];
	int i,j;
	scanf("%s",str);
	int len=strlen(str);
	int matrix[len][len];
	if(len>1000)
	{
		printf("Invalid Input");
		return;
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(i==j)
				matrix[i][j]=1;
			else
				matrix[i][j]=0;
		}
	}
	int a,b,k;
	for(k=1;k<len;k++)
	{
		for(j=k;j<len;j++)
		{
			if(str[j]==str[j-k])		
			{
				matrix[j-k][j]=matrix[j-k+1][j-1]+2;
			}
			else
			{
				a=matrix[j-k][j-1];
				b=matrix[j-k+1][j];
				matrix[j-k][j]=a>b?a:b;
			}
		}
	}
	printf("%d",(len-matrix[0][len-1]));

}
