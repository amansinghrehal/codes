#include<stdio.h>
int max(int a,int b);
int main()
{
	int i,j,n,len;
	printf("enter the number of pieces\n");
	scanf("%d",&n);
	printf("enter the length of the rod");
	scanf("%d",&len);
	int a[n+1][n+1];
	a[0][0]=0;
	a[0][1]=0;
	printf("enter length of piece and its corosponding profit in one row\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);
	}
	int pieces[n+1][len+1];
	int mat[n+1][len+1];
	int div,mod,val;
	int k=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=len;j++)
		{
			if(i==0||j==0)
			{
					mat[i][j]=0;
					pieces[i][j]=0;
			}	
			else if(a[i][1]>j)
			{
				mat[i][j]=mat[i-1][j];
				pieces[i][j]=0;
			}
			else
			{
				div=j/a[i][1];
				mod=j%a[i][1];
				val=(div*a[i][0])+mat[i-1][mod];
				if(val>mat[i-1][j])//?val:mat[i-1][j];
				{
					pieces[i][j]=1;
					mat[i][j]=val;
				}
				else
				{
					pieces[i][j]=0;
					mat[i][j]=mat[i-1][j];
				}
			}
		}	
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=len;j++)
		{
			printf("%d\t",mat[i][j]);		
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=len;j++)
		{
			printf("%d\t",pieces[i][j]);		
		}
		printf("\n");
	}
	printf("\n\n");
	i=i-1;
	j=j-1;
	while(1)
	{
		if(pieces[i][j]==1)
		{
			printf("%d\t",a[i][1]);
			i--;
			j=len-a[i][1];
			len=j;
		}
		else
		{
			i--;
		}
		if(mat[i][j]==0)
			break;
	} 	
}

int max(int a,int b)
{
	if(a>b)
		return b;
	else
		return b;
}
