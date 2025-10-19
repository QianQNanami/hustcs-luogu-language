#include <stdio.h>
#include <stdlib.h>
#define MAX_CAPACITY 100
#define MAX_GOODS 100

int enter(int [][MAX_CAPACITY],int ,int ,int);
void sort(int *,int);
void main(){
     int n,m,k;
     scanf("%d%d%d",&n,&m,&k);
     int  vem[MAX_CAPACITY][MAX_CAPACITY],goods[MAX_GOODS];
     for(int i=0;i<=n-1;i++)
        for(int j=0;j<=m-1;j++) vem[i][j]=0;
     for(int i=0;i<=k-1;i++) scanf("%d",&goods[i]);
     sort(goods,k);
     for(int i=0;i<=k-1;i++){
        if(enter(vem,n,m,goods[i])==0){
               printf("NO");
               return ;
        }
     }
     printf("YES");
     return ;
}

void sort(int height[MAX_CAPACITY],int N){
       for(int i=0;i<=N-2;i++)
           for(int j=i+1;j<=N-1;j++){
               if(height[i]<height[j]){
                      int tmp=height[i];
                      height[i]=height[j];
                      height[j]=tmp;
            }
        }
}

int enter(int vem[MAX_CAPACITY][MAX_CAPACITY],int m,int n,int height){
      for(int i=height-1;i>=0;i--)
            for(int j=0;j<=m-1;j++)
               if(vem[i][j]==0){
                   vem[i][j]=1;
                   return 1;
        }
      return 0;
}
