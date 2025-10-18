#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void compare(char [],char [],int ls,int rs,int lt,int rt);
 void main(){
          char s[100],t[100];
          int q,ls,rs,lt,rt;
          scanf("%s%s%d",s,t,&q);
          for(int i=0;i<=q-1;i++){
            scanf("%d%d%d%d",&ls,&rs,&lt,&rt);
            compare(s,t,ls,rs,lt,rt);
            }
 }

void compare(char s[],char t[],int ls,int rs,int lt,int rt){
        char scut[100],tcut[100];
        int j=0;
        for(int i=ls-1;i<=rs-1;i++){
            scut[j++]=s[i];
        }
        scut[j]='\0';
        j=0;
        for(int i=lt-1;i<=rt-1;i++){
            tcut[j++]=t[i];
        }
        tcut[j]='\0';
        if(strcmp(scut,tcut)<0) printf("yifusuyi\n");
        else if(strcmp(scut,tcut)>0) printf("erfusuer\n");
        else printf("ovo\n");
}
