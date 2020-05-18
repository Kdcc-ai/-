#include <stdio.h>
#include <stdlib.h>
typedef struct edge{
   int u;//边的起始顶点
   int v;//边的终止顶点
   int w;//边的权值
}edge;
edge E[4950]={0};
//结构体定义
int find_father(int father[],int n){
    int r=n;
    while(father[r]!=r)
        r=father[r];
    int i=n,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;
    }
    return r;
}

int main()
                         {
    int x,i,j,n;
    int a,b,c;
    while(1)
{
        scanf("%d",&n);//输入总共有n个城市
        if(n==0) break;
        else{
         int sum=0;//计数为0
         for(i=0;i<(n*(n-1))/2;i++)
             scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);//输入

          int a,b;
          edge e;
          for(i=0;i<(n*(n-1))/2-1;i++)
             for(j=0;j<(n*(n-1))/2-1-i;j++)
                if(E[j].w>E[j+1].w)      {
                    e=E[j];
                    E[j]=E[j+1];
                    E[j]=e;           }
                               //按边权值进行排序,结构体中为权值从小到大排序
for(i=0;i<(n*(n-1))/2;i++)
    printf("%d",E[i].w);
         int father[101]={0};//根节点数组,赋初值;每个城市的根节点都是自己
         for(j=1;j<n+1;j++)
            father[j]=j;
         j=1;
         while(j<n){//需要n-1条边
             int v1,v2;
             v1=find_father(father,E[j].u);
             v2=find_father(father,E[j].v);
             if(v1!=v2) {
                 sum+=E[j].w;
                 father[v1]=v2;
                        }
            j++;
                   }
        printf("%d\n",sum);
             }

}
    return 0;
                          }
