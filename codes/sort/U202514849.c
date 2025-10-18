#include<stdio.h>
#include<stdlib.h>

int main(void){
     int num[3],tmp;
     scanf("%d%d%d",num,num+1,num+2);
     for(int i=0;i<2;i++){
        for(int j=i+1;j<=2;j++){
            if(num[i]>num[j]){
                tmp=num[i];
                num[i]=num[j];
                num[j]=tmp;
            }
        }
     }
     printf("%d %d %d",num[0],num[1],num[2]);
     return 0;
}
