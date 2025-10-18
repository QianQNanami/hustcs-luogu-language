#include <stdio.h>
#include <stdlib.h>

int main(){
    int (*coord)[2],det[2]={0,0};
    int m,n,dx,dy;
    scanf("%d%d",&n,&m);
    coord=(int (*)[2])malloc(sizeof(int [2])*m);
    for(int i=0;i<=n-1;i++){
        scanf("%d %d",&dx,&dy);
        det[0]+=dx;
        det[1]+=dy;
    }
    for(int i=0;i<=m-1;i++){
           scanf("%d%d",&coord[i][0],&coord[i][1]);
          coord[i][0]+=det[0];
          coord[i][1]+=det[1];
    }
    for(int i=0;i<=m-1;i++) printf("%d %d\n",coord[i][0],coord[i][1]);
    return 0;
}
