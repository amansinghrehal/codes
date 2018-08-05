#include<stdio.h>
#include<string.h>
void deleteDigit(int*,int*,int,int,int);
int main()
{
	char str[20];
	int k;
	int i=0;
	printf("enter the number\n");
	scanf("%s",str);
	int len=strlen(str);
	printf("enter the number of digits to delete\n");
	scanf("%d",&k);
	if(k>len)
	{
		printf("Invald Input");
		return;
	}
	int input[len];
	for(i=0;i<len;i++)
	{
		if(isalpha(str[i]))
		{
			printf("Invald Input");
			return;
		}
		input[i]=str[i]-48;
	}
	int result[len];
	deleteDigit(input,result,0,k+1,len);
	for(i=0;i<len-k;i++)
	{
		printf("%d",result[i]);
	}
}
void deleteDigit(int *input,int *result,int big,int end,int len)
{
	int min=big;
	int i;
	static int c=0;
	for(i=big;i<end;i++)
	{
		if(c==0&&input[i]==0);
		
		else if(input[min]>input[i])
			min=i;
	}
	result[c++]=input[min];
	if(end<len)
		deleteDigit(input,result,min+1,end+1,len);
}
