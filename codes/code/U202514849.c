#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 100
int main(){
   int n,m;
   int a,b[MAX_NUM];
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;i++){
        scanf("%d",&a);
        b[i]=m%a;
        m/=a;
   }
   for(int i=0;i<n;i++) printf("%d ",b[i]);
}
