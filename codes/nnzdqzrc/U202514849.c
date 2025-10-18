#include <stdio.h>
#include <stdlib.h>
#define MAX_TASK 20
int mintime(int s);
int max(int x,int y);
int min(int x,int y);
int halfchoose(int *,int ,int ,int );
int main(){
    int s[4],sum=0;
    for(int i=0;i<=3;i++) scanf("%d",&s[i]);
     for(int i=0;i<=3;i++) {sum+=mintime(s[i]);
     }
    printf("%d",sum);
    return 0;
}
int max(int x,int y){
     if (x>y) return x;
     return y;
}
int min(int x,int y){
      if(x>y) return y;
      return x;
}
int halfchoose(int *task,int n,int SUM,int sum){
      int min1,min2,min3,min4;
      if(n==0) return max(sum,SUM-sum);
      min3=halfchoose(task+1,n-1,SUM,sum+*task);
      min4=halfchoose(task+1,n-1,SUM,sum);
      return min(min3,min4);
}
int mintime(int s){
    int task[MAX_TASK],sum=0,min=9999;
    for(int i=0;i<=s-1;i++) {
            scanf("%d",&task[i]);
            sum+=task[i];
    }
    return halfchoose(task,s,sum,0);
}
