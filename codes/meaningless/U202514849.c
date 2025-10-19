#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long Quickmul(long long base,int power);
int isprime(long long);
long long root(long long,int);
int main(){
     int q,k;
     long long a,out[10];
     scanf("%d",&q);
     for(int i=0;i<=(q-1);i++){
        scanf("%lld%d",&a,&k);
        long long rootk=root(a,k);
        out[i]=1;
        for(long long j=2;j<=rootk;j++)
            if(isprime(j)==1){
                int times=0;
                long long tmp=1;
               while(a%j==0){
                     a/=j;
                     tmp*=j;
                     times++;
                    }
                if (times>=k) out[i]*=tmp;
            }
     }
     for(int i=0;i<=q-1;i++) printf("%lld\n",out[i]);
     return 0;
}

long long Quickmul(long long base,int power){
          long long result=1;
          while(power>0){
            if(power&1==1) result*=base;
            power>>=1;
            base=base*base;
          }
          return result;
}


int isprime(long long x){
       for(int i=2;i<=(long long)root(x,2);i++)
             if(x%i==0) return 0;
        return 1;
}


long long root(long long x,int n){
        long long i;
        for(i=2;Quickmul(i,n)<=x;i++);
        return i-1;
}
