#include <stdio.h>
#include <stdlib.h>
#define NUM 100000

long long overlap(long long *L1,long long *L2);

int main(){
    FILE *fp;
    char *filename1="constr.in",*filename2="constr.out";
    fp=fopen(filename1,"r");
    long long N,a,b;
    fscanf(fp,"%lld%lld%lld",&N,&a,&b);
    long long area[2][2],constr[2][2]={{0,a},{0,b}};  /**横纵两个维度各自两个坐标**/
    long long overLAP=0;
    for(int i=0;i<N;i++){
        fscanf(fp,"%lld%lld%lld%lld",&area[0][0],&area[1][0],&area[0][1],&area[1][1]);
        overLAP+=overlap(constr[1],area[1])*overlap(constr[0],area[0]);
    }
    fclose(fp);
    fp=fopen(filename2,"w");
    fprintf(fp,"%d",overLAP);
    fclose(fp);
    return 0;
}

long long overlap(long long *L1,long long *L2){
     if(L1[1]<=L2[0]||L2[1]<=L1[0]) return 0;
     if(L1[0]<=L2[0]&&L2[0]<=L1[1]&&L1[1]<=L2[1]) return L1[1]-L2[0];
     if(L2[0]<=L1[0]&&L1[0]<=L2[1]&&L2[1]<=L1[1]) return L2[1]-L1[0];
     if(L2[0]<=L1[0]&&L1[1]<=L2[1]) return L1[1]-L1[0];
     if(L1[0]<=L2[0]&&L2[1]<=L1[1]) return L2[1]-L2[0];
}
