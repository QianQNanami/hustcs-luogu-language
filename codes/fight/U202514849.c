#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void main(){
     int n,m,p1,s1,s2,*c,spiritb=0,spirith=0,min,S1,S2,p2;
     scanf("%d%",&n);
     c=(int *)malloc(sizeof(int)*n);
     for(int i=0;i<=n-1;i++) scanf("%d",&c[i]);
     scanf("%d%d%d%d",&m,&p1,&s1,&s2);
     for(int i=0;i<=n-1;i++){
        if(i<m-1) spiritb+=(abs(m-1-i))*c[i];
        if(i>m-1)  spirith+=(abs(m-1-i))*c[i];
     }
        if(p1<m) spiritb+=(abs(m-p1))*s1;
        if(p1>m)  spirith+=(abs(m-p1))*s1;
       min=abs(spiritb-spirith);
       p2=m;
       for(int i=0;i<=n-1;i++){
        S1=spiritb;
        S2=spirith;
         if(i<m) S1+=(abs(m-1-i))*s2;
         if(i>m) S2+=(abs(m-1-i))*s2;
         if(min>abs(S1-S2)){
                min=abs(S1-S2);
                p2=i;
        }
    }
     printf("%d",p2+1);
}


