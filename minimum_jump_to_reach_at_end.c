

//minimum jump to reach at the end in an array

#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter size of array");
	scanf("%d",&n);
	int a[n];
	printf("enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int jump[n];
	for(i=0;i<n;i++)
	{
		jump[i]=99999;
	}
	int path[n];
	jump[0]=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(i<=(j+a[j]))
			{
				if(jump[i]>(jump[j]+1))
				{
					jump[i]=(jump[j]+1);
					path[i]=j;
				}	
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",jump[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",path[i]);
	}
	printf("\n");
	j=n-1;
	int arr[n];
	i=0;
	while(1)
	{
		arr[i]=a[j];
		if(j==0)
			break;
		j=path[j];
		i++;
	}
	for(j=i;j>=0;j--)
	{
		printf("%d",arr[j]);
	}
}
