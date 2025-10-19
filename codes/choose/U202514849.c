#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime(int);
int primesort(int*,int n,int k,int sum);
int main(){
  int n,k,*p,sorts;
  scanf("%d%d",&n,&k);
  p=(int *)malloc(sizeof(int)*n);
  for(int i=0;i<=n-1;i++) scanf("%d",&p[i]);
  sorts=primesort(p,n,k,0);
  printf("%d",sorts);
  free(p);
  return 0;
}

int isprime(int x){
    int i;
    for( i=2;i<=sqrt(x)&&x%i!=0;i++);
    if(i<=sqrt(x)) return 0;
    else return 1;
}

int primesort(int *p,int n,int k,int sum){
         if(n<k) return 0;
         if(k==0) return isprime(sum);
         if(n==k){
                for(int i=0;i<=n-1;i++) sum+=p[i];
                return isprime(sum);
         }
         int s1,s2;
         s1=primesort(&p[1],n-1,k,sum);
         s2=primesort(&p[1],n-1,k-1,sum+*p);
         return  (s1+s2);
}
