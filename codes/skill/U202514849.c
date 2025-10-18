#include <stdio.h>
#include <stdlib.h>
#define MAX_SKILL 10000
struct SKILL{
      int time,cost;
};
typedef struct SKILL skill[MAX_SKILL];
void skillsort(skill,int);
void sink(skill,int);
int main(){
       skill skills;
       int n,m,k;
       scanf("%d%d%d",&n,&m,&k);
       for(int i=0;i<n;i++) scanf("%d%d",&skills[i].time,&skills[i].cost);
       skillsort(skills,n);
       while(m>=skills[n-1].cost&&skills[n-1].time>k){
           m-=skills[n-1].cost;
           skills[n-1].time--;
           sink(skills,n);
        }
          printf("%d",skills[n-1].time);
      return 0;
}

void skillsort(skill skills,int n){
          for(int i=0;i<n-1;i++)
               for(int j=i+1;j<n;j++)
                   if(skills[i].time>skills[j].time){
                         struct SKILL tmp;
                         tmp=skills[i];
                         skills[i]=skills[j];
                         skills[j]=tmp;
                   }
}

void sink(skill skills,int n){
       int i=n-1;
       int j=n-2;
       while(skills[j].time>skills[i].time&&j>=0){
                    struct SKILL tmp;
                    tmp=skills[i];
                    skills[i]=skills[j];
                    skills[j]=tmp;
                    i--;
                    j--;
       }
}
