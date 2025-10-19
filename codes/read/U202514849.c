#include <stdio.h>
#include <stdlib.h>


void main(){
    int M,N,*p,theory,times=0,j;
    scanf("%d%d",&M,&N);
    p=(int *)malloc(sizeof(int)*(M+1));
    for(int i=0;i<=M-1;i++) p[i]=-1;
    p[M]=1001;
    for(int i=0;i<=N-1;i++){
        scanf("%d",&theory);
        for(j=0;p[j]!=1001&&p[j]!=-1&&p[j]!=theory;j++);
        if(p[j]==theory) continue;
        if(p[j]==1001){
            *p=theory;
            times++;
        }
        if(p[j]==-1){
            p[j]=theory;
            times++;
        }
     }
           printf("%d",times);
}
