#include<stdio.h>
int main()
{
	int row,col;
	printf("enter row and col lenght\n");
	scanf("%d %d",&row,&col);
	printf("enter values of matrix\n");
	int a[row][col];
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	int min;
	for(i=1;i<row;i++)
	{
		for(j=1;j<col;j++)
		{
			if(a[i][j]==1)
			{
				a[i][j]=(a[i][j-1]<(min=a[i-1][j]<a[i-1][j-1]?a[i-1][j]:a[i-1][j-1])?a[i][j-1]:min)+1;
			}
		}
	}
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
}
