#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *str1,*str2;
	str1=(char*)malloc(sizeof(char)*100);
	str2=(char*)malloc(sizeof(char)*100);
	char *result=(char*)malloc(sizeof(char)*100);
	scanf("%s",str1);
	scanf("%s",str2);
	if(strlen(str1)!=strlen(str2))
	{
		printf("Invalid Input");
		return;
	}
	int i,value;
	for(i=0;i<strlen(str1);i++)
	{
		value=(str1[i]-96)+(str2[i]-96);
		if(value>26)
			value-=26;
		result[i]=value+96;
	}
	printf("%s",result);
}
