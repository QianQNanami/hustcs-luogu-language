#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dictionary{
         char p[150];
         int number;
};

void main(){
    int n,m;
    struct dictionary **p;
    char **input;
    scanf("%d%d",&n,&m);
    p=(struct dictionary **)malloc(sizeof(struct dictionary *)*n);
    for(int i=0;i<=n-1;i++) p[i]=(struct dictionary *)malloc(sizeof(struct dictionary));
    for(int i=0;i<=n-1;i++)  scanf("%s%d",p[i]->p,&p[i]->number);
    getchar();
    input=(char **)malloc(sizeof(char *)*m);
    for(int i=0;i<=m-1;i++) input[i]=(char *)malloc(sizeof(char)*150);
    for(int i=0;i<=m-1;i++) gets(input[i]);
    int state=1;
    char cmp[150];
    for(int i=0;i<=m-1;i++){
                 for(int j=0;input[i][j]!='\0';j++){
                       switch(state){
                           case 1:
                               if(input[i][j]!='{') {
                               printf("%c",input[i][j]);
                               break;
                               }
                              else {
                                  state=2;
                              break;
                              }
                         case 2:
                              int k=0;
                              while(input[i][j]!='}'){
                             cmp[k++]=input[i][j++];
                           }
                             cmp[k]='\0';
                             for(int h=0;h<=n-1;h++){
                             if(strcmp(cmp,p[h]->p)==0){
                                   printf("%d",p[h]->number);
                                   break;
                             }
                             }
                             state=1;
                             break;
                }
            }
                          printf("\n");
    }

}




