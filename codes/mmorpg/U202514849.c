#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
      char *name;
      int status;
      struct Node *next;
};

void sortnode(struct Node **);
void main(){
      struct Node *p,*head,*last;
      char explored[100],(*output)[100];
      int n,m,k;
      scanf("%d%d%d",&n,&m,&k);
      p=(struct Node *)malloc(sizeof(struct Node));
      head=p;
      for(int i=0;i<=n-1;i++) {
        p->name=(char *)malloc(sizeof(char)*100);
        scanf("%s",p->name);
        p->status=0;
        last=p;
        p=(struct Node *)malloc(sizeof(struct Node));
        last->next=p;
        }
        last->next=NULL;
        free(p);
        for(int i=0;i<=m-1;i++){
            scanf("%s",explored);
            for(p=head;p!=NULL;p=p->next){
                if(strcmp(explored,p->name)==0){
                    p->status=1;
                    break;
                }
            }
        }
        for(int i=0;i<=k-1;i++){
            p=(struct Node *)malloc(sizeof(struct Node));
            p->name=(char *)malloc(sizeof(char)*100);
            scanf("%s",p->name);
            p->status=0;
            last->next=p;
            last=p;
    }
            last->next=NULL;
            sortnode(&head);
            for(p=head;p!=NULL;p=p->next){
                if(p->status==0) printf("%s\n",p->name);
            }


}

void sortnode(struct Node **headp){
        struct Node *head=*headp;
        char *tname;
        int tstatus;
        for(struct Node *p=head;p->next!=NULL;p=p->next){
            for(struct Node *p1=p->next;p1!=NULL;p1=p1->next){
                   if(strcmp(p->name,p1->name)>0){
                      tname=p->name;
                      p->name=p1->name;
                      p1->name=tname;
                      tstatus=p->status;
                      p->status=p1->status;
                      p1->status=tstatus;

                   }
            }
        }
}


