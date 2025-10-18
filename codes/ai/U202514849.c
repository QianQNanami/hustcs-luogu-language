#include <stdio.h>
#include <stdlib.h>

typedef int **matrix;
matrix buildmatrix(int m,int n,int mode);
matrix matrixmultiply(matrix m1,matrix m2,int m,int n,int p);
matrix transmatrix(matrix,int,int);
void matrixprintf(matrix,int,int);
void freematrix(matrix,int);
int main(){
    int n,d;
    matrix Q,K,V,W,product;
    scanf("%d%d",&n,&d);
    Q=buildmatrix(n,d,0);
    K=buildmatrix(n,d,0);
    K=transmatrix(K,n,d);
    V=buildmatrix(n,d,0);
    W=buildmatrix(1,n,0);
    product =matrixmultiply(Q,K,n,d,n);
    product=matrixmultiply(W,product,1,n,n);
    product=matrixmultiply(product,V,1,n,d);
    matrixprintf(product,1,d);
    return 0;
}
matrix buildmatrix(int m,int n,int mode){
   matrix p;
   p=(matrix)malloc(sizeof(int *)*m);
   for(int i=0;i<m;i++) p[i]=(int *)malloc(sizeof(int)*n);
   for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
       switch(mode){
           case 0:
              scanf("%d",&p[i][j]);
              break;
           case 1:
              p[i][j]=0;
              break;
       }
   return p;
}

void freematrix(matrix M,int m){
      for(int i=0;i<m;i++) free(M[i]);
      free(M);
}

matrix matrixmultiply(matrix m1,matrix m2,int m,int n,int p){
    matrix M=buildmatrix(m,p,1);
    for(int i=0;i<m;i++)
           for(int j=0;j<p;j++){
              M[i][j]=0;
              for(int q=0;q<n;q++) M[i][j]+=m1[i][q]*m2[q][j];
           }
    freematrix(m1,m);
    freematrix(m2,n);
    return M;
}

matrix transmatrix(matrix m1,int m,int n){
     matrix p=buildmatrix(n,m,1);
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) p[i][j]=m1[j][i];
     freematrix(m1,m);
     return p;
}

void matrixprintf(matrix M,int m,int n){
          for(int i=0;i<m;i++){
             for(int j=0;j<n;j++) printf("%d  ",M[i][j]);
            printf("\n");
}
}
