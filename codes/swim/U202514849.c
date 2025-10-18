#include <stdio.h>
#include <stdlib.h>

int   main(void){
        const float s=2;
        float distance,sum,d;
        int times;
input:
       scanf("%f",&distance);
        if(distance<0||distance>100) {
            printf("ÖØÐÂÊäÈë");
            goto input;
        }
        for(times=0,d=s,sum=0;sum<distance;times++){
            sum+=d;
            d*=0.98;
            }
         printf("%d",times);
         return 0;
}

