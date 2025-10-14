#include <stdio.h>
#include <stdlib.h>


int main(){
      float average,sum=0,score=0,max=0,min=10;
      int num;
      scanf("%d",&num);
      if(num<3||num>1000) printf(" ÊäÈë´íÎó");
      for(int i=1;i<=num;i++){
        scanf("%f",&score);
        if(max<score) max=score;
        if(min>score) min=score;
        sum+=score;
      }
      average=(sum-max-min)/(num-2);
      printf("%.2f",average);
      return 0;
}
