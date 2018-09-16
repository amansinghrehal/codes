#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *str1=(char*)malloc(sizeof(char)*10);
	char *str2=(char*)malloc(sizeof(char)*10);
	int i=0,j;
	char ch;
	while((ch=getchar())!='\n')
	{
		if(i>=sizeof(str1))
		{
			str1=(char*)realloc(str1,sizeof(str1)+10);
		}
		str1[i]=ch;
		i++;
	}
	str1[i]='\0';
	i=0;
	while((ch=getchar())!='\n')
	{
		if(i>=sizeof(str2))
		{
			str2=(char*)realloc(str2,sizeof(str2)+10);
		}
		str2[i]=ch;
		i++;
	}
	int max=0;
	int k,l;
	str2[i]='\0';
	int mat[strlen(str1)+1][strlen(str2)+1];
	for(i=0;i<=strlen(str1);i++)
	{
		for(j=0;j<=strlen(str2);j++)
		{
			if(i==0||j==0)
			{
				mat[i][j]=0;
			}
			else
			{
				if(str1[i-1]==str2[j-1])
				{
					mat[i][j]=mat[i-1][j-1]+1;
					if(mat[i][j]>max)
					{
						max=mat[i][j];
						k=i;
						l=j;
					}
				}
				else
				{
					mat[i][j]=mat[i-1][j];
				}
			}
			//	printf("%d\t",mat[i][j]);
		}
			//printf("\n");
	}
	
	printf("length of longest common substring is %d\n",mat[i-1][j-1]);
 /*
	
	for(i=0;i<=strlen(str1);i++)
	{
		for(j=0;j<=strlen(str2);j++)
		{
			printf("%d\t",mat[i][j]);
		}
			printf("\n");
	}

	char result[strlen(str1)];
	i=0;
	while(mat[k][l]!=0)
	{
		result[i]=str1[l-1];
		k--;
		l--;
		i++;
	}
	for(k=0;k<i-1;k++)
	{
		printf("%c",result[k]);
	}*/
}
