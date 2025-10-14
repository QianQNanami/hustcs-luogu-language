#include <stdio.h>
#include <stdlib.h>

int main(){
     int problems;
     scanf("%d",&problems);
     if(problems<0||problems>100) printf("数据不合理");
     if(problems>=6) printf("Luogu");
     else printf("local");
     return 0;
}
