#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Change{
       int mode;
       double parameter;
};
typedef struct Change *changer;
void change (changer ,double *);
int main(){
       int n,m,i,j;
       double (*coord)[2];
       changer p;
       scanf("%d%d",&n,&m);
       p=(struct Change*)malloc(sizeof(struct Change)*n);
       coord=(double (*)[2])malloc(sizeof(double)*2*m);
       for(int i=0;i<=n-1;i++) scanf("%d%lf",&p[i].mode,&p[i].parameter);
       for(int z=0;z<=m-1;z++){
           scanf("%d%d%lf%lf",&i,&j,&coord[z][0],&coord[z][1]);
           for(int u=i-1;u<=j-1;u++) change(p+u,coord[z]);
        }
        for(int z=0;z<=m-1;z++) printf("%lf %lf\n",coord[z][0],coord[z][1]);
}

void change (changer p,double *cor){
            int mode=p->mode;
            double para=p->parameter;
         switch (mode){
              case 1:
                      cor[0]*=para;
                      cor[1]*=para;
                      break;
              case 2:
                      double x=cor[0];
                      double y=cor[1];
                      cor[0]=x*cos(para)-y*sin(para);
                      cor[1]=x*sin(para)+y*cos(para);
         }
}
