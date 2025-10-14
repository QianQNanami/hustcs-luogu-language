#include <stdio.h>
#include <stdlib.h>

int main(void){
      int A,B,C,score;
        printf("三项成绩");
input:
        scanf("%d%d%d",&A,&B,&C);
        if(A==100||B==100||C==100||A%10!=0||B%10!=0||C%10!=0) {
            printf("重新输入");
            goto input;
        }
        score=0.2*A+0.3*B+0.5*C;
        printf("%d",score);
        return 0;
        }
