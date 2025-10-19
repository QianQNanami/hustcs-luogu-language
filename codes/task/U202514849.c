#include <stdio.h>
#include <stdlib.h>

struct task{
    int number;
    int prenum;
    struct task **precode;
};
void buildtree(struct task ***);
int calculate(struct task *);
void main(){
     int count;
     struct task **tree;
     buildtree(&tree);
     count=calculate(*tree);
     printf("%d",count);
}

void buildtree(struct task ***treep){
     int N,pre;
     struct task **thetree;
     scanf("%d",&N);
     *treep=(struct task **)malloc(sizeof(struct task *)*N);
     for(int i=0;i<=N-1;i++) (*treep)[i]=(struct task *)malloc(sizeof(struct task));
     thetree=*treep;
     for(int i=0;i<=N-1;i++){
        thetree[i]->number=i+1;
        scanf("%d",&(thetree[i]->prenum));
        thetree[i]->precode=(struct task **)malloc(sizeof(struct task *)*(thetree[i]->prenum));
        for(int j=0;j<=(thetree[i]->prenum-1);j++) {
            scanf("%d",&pre);
            (thetree[i]->precode)[j]=thetree[pre-1];
        }
    }
}

int calculate(struct task *head){
      int sum=1;
      if(head->prenum==0) return 1;
      else{
        for(int i=1;i<=(head->prenum);i++){
            sum+=calculate(head->precode[i-1]);
        }
      }
      return sum;
}
