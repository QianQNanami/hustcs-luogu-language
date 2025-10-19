#include <stdio.h>
#include <stdlib.h>

 int main(void){
       int a,b;
input:
       scanf("%d%d",&a,&b);
       if(a>10000||a<0||b<0||b>9){
        printf("数据不合要求，重新输入");
        goto input;
       }
       printf("%d",(10*a+b)/19);
       return 1;
}
