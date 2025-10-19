#include <stdio.h>
#include <stdlib.h>
#define MAP_SIZE_MAX 100

enum COLOR{RED=0,YEL=1,NON=2};

struct Queue{
         int size;
         int thep[MAP_SIZE_MAX*2][6];    /**队列中的排队的对象的五个元素记录x，y,color，magic,cost**/
};

void enqueue(struct Queue *pq,int x,int y,int magic,int color,int cost);
void dequeue(int cur[6],struct Queue *pq);
void swim(struct Queue *);
void pop(struct Queue *);
void swap(int obj1[6],int obj2[6]);

void main(){
         int map[MAP_SIZE_MAX][MAP_SIZE_MAX],mincost[MAP_SIZE_MAX][MAP_SIZE_MAX][2][2];
          /*用数组存储格子属性，map:color,mincost[x][y][magic][color]*/
         int movetocolor[5][3]={{},
         {0,1,0},{0,-1,0},{0,0,1},{0,0,-1}    /**四个方向，移到有色格子，两个元素代表dx,dy**/
         };
         int movetounc[9][4]={{} ,
         {0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1},
         {0,1,1,0},{0,1,-1,0},{0,1,0,1},{0,1,0,-1}    /**八个方向，移到魔法格子，三个元素代表颜色，dx，dy**/
         };
         int m,n;
         scanf("%d%d",&m,&n);
         for(int i=1;i<=m;i++)
               for(int j=1;j<=m;j++){
                    map[i][j]=NON;
                    mincost[i][j][1][0]=mincost[i][j][1][1]=mincost[i][j][0][0]=mincost[i][j][0][1]=9999;
               }
         for(int i=1;i<=n;i++){
                    int x,y,color;
                    scanf("%d%d%d",&x,&y,&color);
                    map[x][y]=color;
            }
        /**完成初始化,而后创建优先队列**/
         struct  Queue PQ;
         struct Queue *pq=&PQ;
         pq->size=0;
         mincost[1][1][0][map[1][1]]=1;
         enqueue(pq,1,1,0,map[1][1],1);/**enqueue参数：queue，x,y,magic,color,cost**/

         int cur[6];
         while(pq->size!=0){

            dequeue(cur,pq);
            int x,y,color,magic,cost,nx,ny,ncolor,nmagic,ncost;
            x=cur[1];
            y=cur[2];
            magic=cur[3];
            color=cur[4];
            cost=cur[5];
            if(x==m&&y==m) {
			    printf("%d",mincost[x][y][magic][color]);
			    return ;
		    }
        /**剪枝，队列里可能有落后的对象**/
            if(mincost[x][y][magic][color]<cost) continue;
        /**移动到有色格子**/
            for(int i=1;i<=4;i++){
               nx=movetocolor[i][1]+x;
               ny=movetocolor[i][2]+y;
               if(nx>m||nx<1||ny>m||ny<1) continue;
               ncolor=map[nx][ny];
               if(ncolor==NON) continue;
               if(color!=ncolor) ncost=cost+1;
               else ncost=cost;
               if(ncost<mincost[nx][ny][0][ncolor]) {
                    enqueue(pq,nx,ny,0,ncolor,ncost);
                    mincost[nx][ny][0][ncolor]=ncost;
               }
           }
       /**移动到无色格子**/
            for(int i=1;i<=8;i++){
               nx=movetounc[i][2]+x;
               ny=movetounc[i][3]+y;
                 if (nx>m||nx<1||ny>m||ny<1) continue;
                 ncolor=map[nx][ny];
                 if(ncolor!=NON||magic==1) continue;
                 ncost=cost+2;
                 ncolor=movetounc[i][1];
                 if(ncost<mincost[nx][ny][1][ncolor]) {
                    enqueue(pq,nx,ny,1,ncolor,ncost);
                    mincost[nx][ny][1][ncolor]=ncost;
                 }
            }
        }
        printf("-1");
}

void swap(int obj1[6],int obj2[6]){
          int tmp[6];
          for(int i=1;i<=5;i++){
            tmp[i]=obj1[i];
            obj1[i]=obj2[i];
            obj2[i]=tmp[i];
          }
}

void swim(struct Queue *pq){
    int size=pq->size;
    int npos=size;
    int parent;
    while(npos>1){
        parent=size/2;
        if(pq->thep[parent][5]>pq->thep[size][5]){
        swap(pq->thep[npos],pq->thep[parent]);
        npos=parent;
    }else break;
    }
}
void sink(struct Queue *pq){
    int npos,minindex=npos=1;
    int leftchild,rightchild;
    while(npos*2<=pq->size){
        leftchild=npos*2;
        rightchild=npos*2+1;
        if(pq->thep[npos][5]>pq->thep[leftchild][5])
        minindex=leftchild;
        if(pq->thep[npos][5]>pq->thep[rightchild][5])
        minindex=rightchild;
        if(minindex!=npos){
               swap(pq->thep[npos],pq->thep[minindex]);
               npos=minindex;
        }
        else break;
        }
}


void enqueue(struct Queue *pq,int x,int y,int magic,int color,int cost){
            int size=(++pq->size);
            pq->thep[size][1]=x;
            pq->thep[size][2]=y;
            pq->thep[size][3]=magic;
            pq->thep[size][4]=color;
            pq->thep[size][5]=cost;
            swim(pq);
}
void dequeue(int cur[6],struct Queue *pq){
           for(int i=1;i<=5;i++){
            cur[i]=pq->thep[1][i];
            pq->thep[1][i]=pq->thep[pq->size][i];
           }
           pq->size--;
           sink(pq);
}









