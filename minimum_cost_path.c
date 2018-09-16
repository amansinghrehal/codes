#include<stdio.h>
int main()
{
	int row;
	int col;
	printf("enter the row and col of matrix\n");
	scanf("%d %d",&row,&col);
	int i,j;
	int matrix[row][col];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&matrix[i][j]);		
		}
	}	
	int result[row][col];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==0)
			{
				if(j==0)
				{
					result[i][j]=matrix[i][j];
				}
				else
				{
					matrix[i][j]=matrix[i][j]+matrix[i][j-1];
				}
			}
			else if(j==0)
			{
				matrix[i][j]+=matrix[i-1][j];
			}
			else
			{
				matrix[i][j]+=matrix[i-1][j]<matrix[i][j-1]?matrix[i-1][j]:matrix[i][j-1];
			}
		}
	}
	printf("%d",matrix[i-1][j-1]);
}

