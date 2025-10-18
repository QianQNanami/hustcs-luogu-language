#include <stdio.h>
#include <stdlib.h>


int min(int *pn,int x);
void main(){
    int *gcod,n,q,*buyer,*needs,*length,k,x;
    scanf("%d%d",&n,&q);
    gcod=(int  *)malloc(sizeof(int)*n);
    buyer=(int *)malloc(sizeof(int)*q);
    length=(int *)malloc(sizeof(int)*q);
    needs=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<=n-1;i++) scanf("%d",&gcod[i]);
    for(int i=0;i<=q-1;i++) scanf("%d%d",&length[i],&buyer[i]);
    for(int i=0;i<=q-1;i++){
        k=1;
        for(int j=0;j<=n-1;j++) needs[j]=-1;
        for(int j=1;j<=length[i];j++) k*=10;
        x=0;
        for(int j=0;j<=n-1;j++){
            if(gcod[j]%k==buyer[i]){
                needs[x]=gcod[j];
                x++;
            }
        }
        printf("%d\n",min(needs,x));
        }
}


int min(int *pn,int x){
        int tmp;
        if (x==0) return -1;
        for(int i=0;i<=x-2;i++){
        for(int j=i+1;j<=x-1;j++){
            if(pn[i]>pn[j]){
                tmp=pn[i];
                pn[i]=pn[j];
                pn[j]=tmp;
            }
        }
        return *pn;
     }




}
