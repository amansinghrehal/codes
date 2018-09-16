#include<stdio.h>
int top=-1;
int isEmpty();
int pop(int []);
void push(int [],int);
int main()
{
	int n,i,j,max=0,currMax,area;
	printf("enter length of histogram\n");
	scanf("%d",&n);
	printf("enter height of hostogram\n");
	int hist[n];
	for(i=0;i<n;i++)
		scanf("%d",&hist[i]);
	//	for(i=0;i<n;i++)
	//	    printf("%d",hist[i]);
	int len=sizeof(hist)/sizeof(hist[0]);
	//printf("%d",len);
	int stack[n]; 
	i=0;
	while(i<len)
	{
		if(isEmpty()||hist[stack[top]]<=hist[i])
		{
			push(stack,i);
			i++;
		}
		else
		{
			currMax=pop(stack);
			area=hist[currMax]*(isEmpty()?(i-1):(i-1-stack[top]));
		//	printf("area is %d\n",area);
			if(area>max)
				max=area;
		}
	}
	while(!isEmpty())
	{
		currMax=pop(stack);
		area=hist[currMax]*(isEmpty()?(i-1):(i-1-stack[top]));
	//	printf("area is %d\n",area);
		if(area>max)
			max=area;
	}
	printf("%d",max);
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

