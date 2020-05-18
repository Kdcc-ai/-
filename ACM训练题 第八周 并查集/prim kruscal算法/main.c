#include <stdio.h>
#include <stdlib.h>
#define INF 32767
#define max 50
//可能有bug
typedef struct Mgraph{
   char V[100][100];//顶点编号
   char name[100][100];//城市名
   int edges[100][100];//两点间距离
   int n;//图中顶点个数
}graph;
typedef struct{
   int u;//边的起始顶点
   int v;//边的终止顶点
   int w;//边的权值
}edge;
edge edgeset[100];
int findbian(graph g){//统计总共有几条边
   int k=1;
   for(i=1;i<=g.n;i++)
        for(j=1;j<=g.n;j++)
          if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
          {
              edgeset[k].u=i;
              edgeset[k].v=j;
              edgeset[k].w=g.edges[i][j];//初始化操作
              k++;
          }
  return k-1;//总共有k-1条边
}
void sort(int n){
   int i,j;
   edge t;
   for(i=1;i<=n-1;i++)
     for(j=i+1;j<=n;j++)
   if(edgeset[i].w>edgeset[j].w){
    t=edgeset[j];
    edgeset[j]=edgeset[i];
    edgeset[i]=t;
   }
}
int find_set(int father[],int node){//寻找该节点的根节点节点
    int r=node;
    while(father[r]!=r){
        r=father[r];
    }
    int i=node,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;//压缩路径操作
    }
    return r;
}
void Kruskal(graph g){
    printf("克鲁斯卡尔输出通信网为：\n");
    int father[max],v1,v2;
    int n=findbian(graph g);//总共有n条边
    sort(n);//边权值进行排序
    for(i=1;i<=g.n;i++)
        father[i]=i;//并查集初始化操作
    i=1;
    while(i<g.n)    {//寻找n-1条边
        v1=find_set(father,edgeset[i].u);
        v2=find_set(father,edgeset[i].v);
        if(v1!=v2){
            printf("边(%d,%d)的权值为：%d\n",edgeset[i].u,edgeset[i].v,edgeset[i].w);
            i++;
            father[v1]=v2;//v1的根节点记成v2
                 }
                      }

}


void Prim(graph g,int v){//Prim算法
    int i,k,min;
    int lowcost[100];//标记数组
    int closeset[100];
    for(i=1;i<=g.n;i++){//给两个数组赋初值 lowcost数组为1->n各节点到所给的第一个节点的权值大小 closeset数组为1->各节点的前一个即诶对呐时所给的第一个节点
        lowcost[i]=g.edges[v][i];
        closeset[i]=v;//与i相连的顶点
        lowcost[v]=0;
    }
    for(i=1;i<g.n;i++){//输出n-1条边,在V-U中找出离U最近的顶点k
        min=INF;

        for(j=1;j<=g.n;j++)//二重for循环的第一个,从顶点1开始遍历
            if(lowcost[j]!=0&&lowcost[j]<min)//j没进U呢且j与U距离小于min
        {
            min=lowcost[j];
            k=j;//k记录最近编号顶点,刚加入U集合的顶点
        }

       printf("边(%s,%s)的权值为：%d\n",g.name[closeset[k]],g.name[k],lowcost[k]);
       lowcost[k]=0;//标记k进入U

    for(j=1;j<=g.n;j++){//二重for循环的第二个,从顶点1开始遍历
        if(lowcost[j]!=0&&`g.edges[k][j]<lowcost[j]){//j在V-U中且j与刚并入的节点距离小于lowcost数组中的距离,交换数值
            lowcost[j]=g.edges[k][j];//要注意lowcost数组是不断更新的,他始终代表的是V-U中某节点到V中节点的距离最小值
            closeset[j]=k;//此时与j节点想关联的最近节点变为j
        }
       }



    }

}



int main()
{
    int number=INF,i=1,count;
    graph g;
    while(number!=0){
    printf("城市信息输入请按1\n");
    printf("城市间距离编辑请按2\n");
    printf("采用Prim算法进行通信网的构建请按3\n");
    printf("采用Kruskal算法进行通信网的构建请按4\n");
    printf("退出请按0\n");
    scanf("%d",&number);
    if(number==1){
        printf("请输入你想输入的城市信息个数\n");
        scanf("%d",&g.n);
        count=g.n;
        while(count--){
            printf("请输入城市编号和城市名称：\n");
            scanf("%s %s",g.V[i],g.name[i]);
            i++;
         }
         printf("城市信息录入成功\n\n");
    }
    if(number==2)
        { int a,b,c,j;
        for(i=1;i<=g.n;i++)
        for(j=1;j<=g.n;j++)
         {g.edges[i][j]=INF;
         }
         for(i=1;i<=g.n;i++)
        for(j=1;j<=g.n;j++)
         {g.edges[i][j]=INF;
         }


       printf("请输入你想录入的信息个数\n");
       scanf("%d",&count);
        while(count--)
        { printf("请输入城市编号和它们之间的距离");
            scanf("%d %d %d",&a,&b,&c);
            g.edges[a][b]=g.edges[b][a]=c;
        }
    if(number==3)
        Prim(g,1);
    if(number==4)
        Kruskal(g);
   }

                     }
    return 0;
}
