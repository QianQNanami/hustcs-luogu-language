#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MAR 200
#define P 131
#define M   1000000007
/**ÀûÓÃ×Ö·û´®¹þÏ£Öµ´æ´¢¾ØÕó**/
typedef long long matrix[8];
long long hashcal(char *);
int enmatrix(int *pretimes,matrix *m,matrix tmp, int sorts,int *cur);
int hashcmp(matrix m1,matrix m2);
int main(){
      int pretimes[MAX_MAR],n,sorts=0;
      int PRETIMES[MAX_MAR];
      scanf("%d",&n);
      getchar();
      matrix *m=(matrix *)malloc(sizeof(matrix)*MAX_MAR);
      for(int i=0;i<=n-1;i++){
        char *p=(char *)malloc(sizeof(char)*10);
        matrix tmp;
        for(int j=0;j<=7;j++){
                  fgets(p,10,stdin);
                  tmp[j]=hashcal(p);
                  }
         free(p);
         sorts+=enmatrix(pretimes,m,tmp,sorts,&PRETIMES[i]);
         }
         for(int i=0;i<n;i++) printf("%d\n",PRETIMES[i]);
         return 1;
}
long long hashcal(char *p){
        long long hash;
        for(int i=0;p[i]!='\0';i++)
                 hash=(i==0) ? (long long) p[i]: (hash*P+(long long)p[i])%M;
        return hash;
}

int hashcmp(matrix m1,matrix m2){
         for(int i=0;i<8;i++)
            if(m1[i]!=m2[i]) return 1;
          return 0;
}

int enmatrix(int *pretimes,matrix *m, matrix tmp, int sorts,int *cur){
         if(sorts==0){
             for(int i=0;i<8;i++) m[sorts][i]=tmp[i];
             pretimes[sorts]=1;
             *cur=1;
             return 1;
        }
         for(int i=0;i<sorts;i++)
              if(hashcmp(m[i], tmp)==0){
                    *cur=++pretimes[i];
                    return 0;
              }
         *cur=pretimes[sorts]=1;
         for(int i=0;i<8;i++) m[sorts][i]=tmp[i];
         return 1;
         }


