#include <stdio.h>
#include <stdlib.h>
void main(){
   int N,code,sgn=0;
   scanf("%d",&N);
   for(int i=0;i<=N*N;){
            scanf("%d",&code);
            for(int j=1;j<=code;j++){
                i++;
                printf("%d",sgn);
                if(i%N==0) printf("\n");
            }
            sgn=(sgn==0)?1:0;
                }

}
