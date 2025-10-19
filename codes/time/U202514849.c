#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char sequence[],char reverse[],int x,int y);
int main(){
     char sequence[100],reversequence[100],minsequence[100];
     int length;
     scanf("%s",sequence);
     length=strlen(sequence);
     strcpy(minsequence,sequence);
     for(int i=0;i<=length-2;i++){
            for(int j=i+1;j<=length-1;j++){
                reverse(sequence,reversequence,i,j);
                if(strcmp(reversequence,minsequence)<0) strcpy(minsequence,reversequence);
            }
     }
     printf("%s",minsequence);
}
void reverse(char sequence[],char reverse[],int x,int y){
       char tmp;
       strcpy(reverse,sequence);
       for(int i=x,j=y;i<j;i++,j--) {
        tmp=reverse[i];
        reverse[i]=reverse[j];
        reverse[j]=tmp;
       }
}
