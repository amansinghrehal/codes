#include<stdio.h>
int top=-1;
int isEmpty();
int pop(int []);
void push(int [],int);
int main()
{
	int row,col,i,j,max=0,currMax,area;
	printf("enter row length\n");
	scanf("%d",&row);
	printf("enter col length\n");
	scanf("%d",&col);
	int hist[col];
	for(i=0;i<col;i++)
	{
		hist[i]=0;
	}
	int matrix[row][col];
	printf("enter matrix elemnt\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}

	//	for(i=0;i<n;i++)
	//	    printf("%d",hist[i]);
//	int len=sizeof(hist)/sizeof(hist[0]);
	//printf("%d",len);
	int stack[col]; 
	int final_max=0;
	int k;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(matrix[i][j]==0)
			{
				hist[j]=0;
			}
			else
			{
				hist[j]=hist[j]+matrix[i][j];
			}
		}
		k=0;
		top=-1;
		while(k<col)
		{
			if(isEmpty()||hist[stack[top]]<=hist[k])
			{
				push(stack,k);
				k++;
			}
			else
			{
				currMax=pop(stack);
				area=hist[currMax]*(isEmpty()?(k-1):(k-1-stack[top]));
			//	printf("area is %d\n",area);
				if(area>max)
					max=area;
			}
		}
		while(!isEmpty())
		{
			currMax=pop(stack);
			area=hist[currMax]*(isEmpty()?(k-1):(k-1-stack[top]));
		//	printf("area is %d\n",area);
			if(area>max)
				max=area;
		}
		if(max>final_max)
			final_max=max;
		printf("\n%d",final_max);
	}
	//printf("\n%d",final_max);
}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
	return 0;
}
void push(int *stack,int i)
{
	top=top+1;
	stack[top]=i;
	printf("%dpushed\n",stack[top]);
}
int pop(int *stack)
{
	int data;
	data=stack[top];
	top=top-1;
	printf("%dpoped\n",data);
	return data;
}

