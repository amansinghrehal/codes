#include<stdio.h>
int main()
{
	long int n,a,b,i;
	scanf("%ld %ld %ld",&n,&a,&b); 
	if(n%2!=0)
	{
		printf("NO");
		return;
	}
	if(n<=0)
	{
		printf("Invalid Input");
		return;
	}
	n=n/2;
	int count[n+1];
	int index[n+1];
	int values[2];
	values[0]=a;
	values[1]=b;
	for(i=0;i<=n;i++)
	{
		if(i==0)
			count[i]=0;
		else
		{
			count[i]=999999;
			index[i]=-1;
		}
	}
	int cal,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(j>=values[i])
			{
				cal=count[j-values[i]]+1;
				count[j]=count[j]<cal?count[j]:cal;
			}
		}
	}
	if(count[j-1]==999999)
		printf("NO");
	else
		printf("YES");
}
