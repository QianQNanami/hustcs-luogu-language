#include <stdio.h>
#include <stdlib.h>

void main(){
         int n,k,*number,tmp,K=1,h;
         scanf("%d%d",&n,&k);
         number=(int *)malloc(sizeof(int)*n);
         for(int i=0;i<=n-1;i++) scanf("%d",number+i);
         for(int i=0;i<=n-2;i++){
                for(int j=i+1;j<=n-1;j++){
                    if(number[j]<number[i]){
                        tmp=number[i];
                        number[i]=number[j];
                        number[j]=tmp;
                    }
                }
        }
        tmp=number[0];
      for(h=0;K<k;h++){
           if(number[h]>tmp){
                 tmp=number[h];
                 K++;
           }
      }
        printf("%d",number[h-1]);
      }



