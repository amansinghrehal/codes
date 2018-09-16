// matrix should have at least one positive number to work

#include<stdio.h>
int main()
{
	int row,col,i,j;
	printf("enter row and column 0f matrix\n");
	scanf("%d %d",&row,&col);
	printf("enter row and column values as matrix \n");
	int a[row][col];
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	int kad[row];
	int right=0,left=0;
	int maxSum=-1,maxLeft,maxRight,maxUp,maxDown;
	int max_so_far;
	int max_here;
	int k;
	int up,down;
	for(i=0;i<col;i++)
	{	
	left=i;
		for(j=i;j<col;j++)
		{
			right=j;
			if(right==left)
			{
				for(k=0;k<row;k++)
				{
					kad[k]=a[k][j];
				}	
			}
			else
			{
				for(k=0;k<row;k++)
				{
					kad[k]=kad[k]+a[k][j];
				}
			}
			int l;
			for(l=0;l<row;l++)
				printf("%d\t",kad[l]);
			printf("\n");
			max_so_far=kad[0];
			max_here=0;
			int s=0;
			for(k=0;k<row;k++)
			{
				max_here=max_here+kad[k];
				if(max_here>max_so_far)
				{
					max_so_far=max_here;
					up=s;
					down=k;
				}
				if(max_here<0)
				{
					max_here=0;
					s=k+1;
				}
			}
			printf("%d\t%d\t%d\n",up,down,max_so_far);
			if(max_so_far>maxSum)
			{
				maxSum=max_so_far;
				maxLeft=left;
				maxRight=right;
				maxUp=up;
				maxDown=down;
			}
		}
	}
	printf("%d\t%d\t%d\t%d",maxLeft,maxRight,maxUp,maxDown);
}

