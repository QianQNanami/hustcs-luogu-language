#include <stdio.h>
#include <stdlib.h>

void  split(int n);

void main(){
       int n;
       scanf("%d",&n);
       split(n);
}

void split(int n){
      if(n==2) {
            printf("2");
            return;
     }
       if(n==0) {
            printf("0");
            return;
}
     int valid[16],bit;
     for(bit=0;n!=0;bit++) {
        valid[bit]=n%2;
        n/=2;
     }
     for(int k=bit-1;k>=0;k--){
        if(valid[k]==1) {
          if(k==1) printf("2+");
          else{
                printf("2(");
                split(k);
                printf(")+");
        }
        }
     }
     printf("\b \b");
}

