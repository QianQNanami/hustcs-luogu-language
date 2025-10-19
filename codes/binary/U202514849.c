#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int biggerthan(int *,int ,int);
int smallerthan(int *,int ,int);
int equalto(int *,int ,int );
int main(){
    int n,m,a[MAX_SIZE],ques,x,y;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n-1;i++) scanf("%d",&a[i]);
    for(int i=0;i<=m-1;i++){
        scanf("%d",&ques);
        switch (ques){
         case 1:
            scanf("%d",&x);
            printf("%d",equalto(a,n,x));
            break;
         case 2:
            scanf("%d%d",&x,&y);
            if(x>y) {
                    printf("0");
                    break;
                        }
            printf("%d",n-biggerthan(a,n,y)-smallerthan(a,n,x));
            break;
         case 3:
            scanf("%d%d",&x,&y);
            if(x>=y) {
                    printf("0");
                    break;
                        }
            printf("%d",n-biggerthan(a,n,y)-smallerthan(a,n,x)-equalto(a,n,y));
            break;
        case 4:
            scanf("%d%d",&x,&y);
            if(x>=y) {
                    printf("0");
                    break;
                        }
            printf("%d",n-biggerthan(a,n,y)-smallerthan(a,n,x)-equalto(a,n,x));
            break;
        case 5:
            scanf("%d%d",&x,&y);
            if(x>=y) {
                    printf("0");
                    break;
                        }
            printf("%d",n-biggerthan(a,n,y)-smallerthan(a,n,x)-equalto(a,n,y)-equalto(a,n,x));
            break;
        }
    }
    return 0;
}
int biggerthan(int *a,int n,int x){
            int num=0;
            for(int i=0;i<=n-1;i++){
                if(a[i]>x) num++;
            }
           return num;
           }
int smallerthan(int *a,int n,int x){
            int num=0;
            for(int i=0;i<=n-1;i++){
                if(a[i]<x) num++;
            }
           return num;
           }
int equalto(int *a,int n,int x){
            int num=0;
            for(int i=0;i<=n-1;i++){
                if(a[i]==x) num++;
            }
           return num;
           }
