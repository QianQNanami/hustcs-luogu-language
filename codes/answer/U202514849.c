#include <stdio.h>
#include <stdlib.h>
#define MAX_EUQUATION  100
int issolu(long *,int n,long L,long R);

int main(){
     long a,b,c,solu[MAX_EUQUATION];
     long L,R,Q,n;
     scanf("%d%d",&n,&Q);
     for(int i=0;i<=n-1;i++){
        scanf("%dx %d=%d",&a,&b,&c);
        }
     for(int i=0;i<=Q-1;i++){
         scanf("%d%d",&L,&R);
         printf("%d",issolu(solu,n,L,R));
         }
     return 0;
}

int issolu(long *solu,int n,long L,long R){
      int solus=0;
      for(int i=0;i<=n-1;i++)
        if(solu[i]>=L&&solu[i]<=R) solus++;
     return solus;
}
