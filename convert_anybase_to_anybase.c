#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
    char *n,*an;
    int gb,l,i,dg,cb;
    long int d=0;
    n=malloc(256);
    an=malloc(1000);
    scanf("%s",n);
    scanf("%d",&gb);
    scanf("%d",&cb);
    l=strlen(n);
    for(i=0;n[i]!='\0';i++){
        if(n[i]>=48&&n[i]<=57) 
            dg=n[i]-48;
        else if(n[i]>=65&&n[i]<=91)
            dg=n[i]-55;
        else dg=n[i]-87;
        d=d+(dg*pow(gb,(l-1)));
        l--;
    }
   // printf("%d\n",d);             //any base to decimal
    an=an+999;
    *an='\0';
   // printf("%s\n%ld\n",n,d);
    while(d){                                                         //decimal to any base
        *--an="0123456789abcdefghijklmnopqrstuvwxyz"[d%cb];
        d=d/cb;
    }
    printf("%s",an);
}
