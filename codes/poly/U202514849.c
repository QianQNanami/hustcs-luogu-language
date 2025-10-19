#include <stdio.h>
#include <stdlib.h>


int main(){
/**筛法选出50000以内的素数并存到数组prime中**/
      static int prime[5001];
      int num[10001],k=0;
      for(int i=0;i<=10000;i++) num[i]=1;
      for(int i=0;i<=5000;i++) prime[i]=0;
      num[1]=0;
      num[0]=0;
      for(int j=2;j<=10000;j++){
            if (num[j]==1){
                         for(int p=2*j;p<=10000;p+=j) num[p]=0;
                         k++;
                         prime[k]=j;
      }
      }
      int s,sum=0,number=0;
      scanf("%d",&s);
      if(s<1||s>10000) printf("输入错误");
      while( (sum+prime[number++]) <s){
               sum+=prime[number];
               printf("%d\n",prime[number]);
      }
      printf("%d",number-1);
      return 0;
}
