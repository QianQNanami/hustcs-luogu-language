#include <stdio.h>
#include <stdlib.h>
#define MAX_BOOKS 100
void sort(int*,int );
int main(){
       int N,B;
       int height[MAX_BOOKS];
       scanf("%d%d",&N,&B);
       for(int i=0;i<=N-1;i++) scanf("%d",&height[i]);
       sort(height,N);
       int num=0,H=0;
       while(num<=N){
        H+=height[num];
        num++;
        if(H>B){
            printf("%d",num);
            return 1;
        }
       }
}
void sort(int *height,int N){
       for(int i=0;i<=N-2;i++)
           for(int j=i+1;j<=N-1;j++){
               if(height[i]<height[j]){
                      int tmp=height[i];
                      height[i]=height[j];
                      height[j]=tmp;
            }
        }
}
