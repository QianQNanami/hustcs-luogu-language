#include<stdio.h>
#include<stdlib.h>


int main(void){
      int d,isgum1,isgum2;
      scanf("%d",&d);
      isgum1=d%2==0?1:0;
      isgum2=(d>4&&d<=12)?1:0;
      if(isgum1==1&&isgum2==1) printf("1 1 0 0");
      if((isgum1==1&&isgum2==0)||(isgum1==0&&isgum2==1)) printf("1 1 1 0");
      if(isgum1==0&&isgum2==0) printf("0 0 0 1");
      return 0;
}
