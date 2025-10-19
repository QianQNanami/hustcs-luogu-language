#include <stdio.h>
#include <stdlib.h>
#define matrix long
 const long long MOD=998244353;

 /**矩阵乘法，运用快速幂的思想**/
 void matrixmul(matrix **A,matrix **B,int m,int n,int p){
        matrix tmp1[m][n],tmp2[n][p];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) tmp1[i][j]=A[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<p;j++) tmp2[i][j]=B[i][j];
        for(int i=0;i<m;i++)
            for(int j=0;j<p;j++){
                int k;
               for(k=0,A[i][j]=0;k<n;k++) A[i][j]+=(tmp1[i][k]*tmp2[k][j])%MOD;
 }

 }
 void Quickmul(matrix **result,matrix **base,int power,int m){
        while(power>0){
           if(power&1==1) matrixmul(result,base,m,m,m);
           power>>=1;
           matrixmul(base,base,m,m,m);
        }
 }

 int main(){
    long n;
    long f1,f2,a,b,c;
    scanf("%ld%ld%ld%ld%ld%ld",&n,&f1,&f2,&a,&b,&c);
    matrix **result,**A,**farr;
    result=(matrix **)malloc(sizeof(matrix *)*3);
    A=(matrix **)malloc(sizeof(matrix *)*3);
    farr=(matrix **)malloc(sizeof(matrix *)*3);
    for(int i=0;i<=2;i++){
        result[i]=(matrix *)malloc(sizeof(matrix)*3);
        A[i]=(matrix *)malloc(sizeof(matrix)*3);
        farr[i]=(matrix *)malloc(sizeof(matrix)*1);
    }
    result[0][0]=result[1][1]=result[2][2]=1;
    result[0][1]=result[0][2]=result[1][0]=result[1][2]=result[2][1]=result[2][0]=0;
    A[1][1]=A[1][2]=A[2][0]=A[2][1]=0;
    A[0][0]=a;
    A[0][1]=b;
    A[0][2]=A[1][0]=A[2][2]=1;
    farr[0][0]=f2;
    farr[1][0]=f1;
    farr[2][0]=c;
    Quickmul(result,A,n-2,3);
    matrixmul(result,farr,3,3,1);
    printf("%d",result[0][0]);
}


