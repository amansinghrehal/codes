/* program to find how many combinations of numbers can make the total sum
the sum is given and unlimited access of the coins is avaliable*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j;
	printf("enter number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	int sum;
	printf("enter the sum to find\n");
	scanf("%d",&sum);
	int mat[n+1][sum+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
		{
			if(i==0&&j==0)
			{
				mat[i][j]=1;
			}
			else if(i==0)
			{
				mat[i][j]=0;
			}
			else if(a[i-1]>j)
			{
				mat[i][j]=mat[i-1][j];	
			}
			else
			{
				mat[i][j]=mat[i-1][j]+mat[i][j-i];
			}
		}
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("possible combinations are %d\t",mat[i-1][j-1]);
}
