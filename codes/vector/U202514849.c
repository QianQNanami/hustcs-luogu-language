#include <stdio.h>
#include <stdlib.h>
#define MAX_ARR 1000


int smallerthan(int *,int *,int);


int main(){
     int *vector[MAX_ARR];
     int minbig[MAX_ARR];
     int n,m;
     scanf("%d%d",&n,&m);
     for(int i=0;i<=n-1;i++){
          vector[i]=(int *)malloc(sizeof(int)*m);
          minbig[i]=0;
          for(int j=0;j<=m-1;j++) scanf("%d",&vector[i][j]);
    }
    for(int i=0;i<=n-1;i++)
             for(int j=0;j<=n-1;j++){
                    int t=smallerthan(vector[i],vector[j],m);
                    if(t==1&&minbig[i]==0) minbig[i]=j+1;
                    else if(t==1&&minbig[i]>j) minbig[i]=j+1;
    }
    for(int i=0;i<=n-1;i++)
           printf("%d\n",minbig[i]);
    return 0;
    }


int smallerthan(int *v1,int *v2,int m){
         for(int i=0;i<=m-1;i++){
            if (v1[i]>=v2[i]) return 0;
         }
         return 1;
}
