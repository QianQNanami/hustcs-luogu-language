#include <stdio.h>
#include <stdlib.h>

int main(){
     long n;
     long i,j;
     scanf("%ld",&n);
     if(n<0||n>1000000000) printf(" ‰»Î¥ÌŒÛ");
     for(i=0,j=1;j<=n;i++,j*=2);
     printf("%ld",i);
     return 0;
}
