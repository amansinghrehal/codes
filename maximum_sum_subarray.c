#include<stdio.h>
int main()
{
	int n;
	printf("enter nubmer of elementas\n");
	scanf("%d",&n);
	printf("enter elemmtns\n");
	int i;
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	int max_so_far=a[0];
	int max_ending_here=0;
	int start=0,end=0,s=0;
	for(i=0;i<n;i++)
	{
		max_ending_here=max_ending_here+a[i];
		if(max_ending_here>max_so_far)
		{
			max_so_far=max_ending_here;
			start=s;
			end=i;
		}
		if(max_ending_here<0)
		{
			max_ending_here=0;
			s=i+1;
		}
	} 
	printf("%d\n",max_so_far);
	for(i=start;i<=end;i++)
	{
		printf("%d\t",a[i]);
	}
	
}
