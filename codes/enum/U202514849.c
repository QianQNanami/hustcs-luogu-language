#include <stdio.h>
#include <stdlib.h>

void main(){
       int n,x,times=0,i,j;
       scanf("%d%d",&n,&x);
       for(i=1;i<=n;i++){
            for(j=i;j!=0;j=j/10){
                if(j%10==x) times++;
            }
        }
       printf("%d",times);
}
