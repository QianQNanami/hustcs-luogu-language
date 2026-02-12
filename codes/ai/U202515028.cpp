#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int a,b,c,d;
    scanf("%d%d",&a,&b);
    if((a>=0&&a<=10000)&&(b>=0&&b<=9))
    {
    c=a*10+b;
    d=c/19;
    printf("%d",d);}
    else exit -1;
    return 0;
}