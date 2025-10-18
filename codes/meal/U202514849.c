#include <stdio.h>
#include <stdlib.h>
#define MAX_MEAL 100

struct MEAL{
         int time;
         struct MEAL *next,*pre;
};
typedef struct MEAL*sequence[MAX_MEAL];
int main(){
      int n,m,t,senum=0;
      scanf("%d%d",&t,&n);
      int early[MAX_MEAL],late[MAX_MEAL];
      sequence meal;
      for(int i=0;i<n;i++) {
            meal[i]=(struct MEAL *)malloc(sizeof(struct MEAL));
            meal[i]->pre=meal[i]->next=NULL;
      }
      for(int i=0;i<n;i++){
           int depend;
           scanf("%d",&depend);
           if (depend!=0){
                meal[i]->pre=meal[depend-1];
                meal[depend-1]->next=meal[i];
           }
      }
     int cando=1;
     for(int i=0;i<n;i++) scanf("%d",&meal[i]->time);
     for(int i=0;i<n;i++){
          int before=0,after=0;
          struct MEAL *p;
          for(p=meal[i];p!=NULL;p=p->next) after+=p->time;
          for(p=meal[i]->pre;p!=NULL;p=p->pre) before+=p->time;
          if((before+after)>t) cando=0;
          early[i]=before;
          late[i]=t-after;
     }
     for(int i=0;i<n;i++) printf("%d ",early[i]+1);
     if(cando==1)  {
             printf("\n");
             for(int i=0;i<n;i++)  printf("%d ",late[i]+1);
     }
     return 1;
}
