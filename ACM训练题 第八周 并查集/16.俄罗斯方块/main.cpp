#include <stdio.h>
#include <stdlib.h>
#include<queue>
#include<vector>
//等级比较3 3
/**0 > 1
1 < 2
0 > 2
4 4
1 = 2
1 > 3
2 > 0
0 > 1
3 3
1 > 0
1 > 2
2 < 1：
*/
//输出
/**
OK
CONFLICT
UNCERTAIN
*/
using namespace std;
int N,M;
int sum;
//三个数组用于输入
int A[10010],B[10010];
char oper[10010];

int father[10001];
vector<int> next[10010];//用来模拟邻接表,因为拓扑排序中图的存储要是邻接表为存储结构，理解
int pre[10010];//存储入度

//并查集操作
int find_(int a){
    int r=a;
    while(a!=father[a]){
        a=father[a];
    }
    father[r]=a;
    return a;
}
int Union(int a,int b){
   int v1=find_(a);
   int v2=find_(b);
   if(v1!=v2){
      father[v2]=v1;
      return 1;
              }
    else return 0;
}
//初始化操作
void init()
{
    int i=0;
    for(i=0;i<N;i++)
    {
        father[i]=i;
        next[i].clear();
        pre[i]=0;
    }
}

void top_order()
{
  bool uncertain=false;
  queue<int> q;
  //进行队列的初始化
  int i=0;
  for(i=0;i<N;i++)
    if(pre[i]==0&&find_(i)==i) q.push(i);//i节点入度为0并且它是根节点,两个节点合并了就证明这两个节点可以看作相等
  while(!q.empty()){
     if(q.size()>1) uncertain=true;
     int cur=q.front();
     q.pop();
     sum--;
     for(i=0;i<next[cur].size();i++)
     {
         if(--pre[next[cur][i]]==0)
            q.push(next[cur][i]);
     }
                   }
    if(sum>0)printf("CONFLICT\n");
    else if(uncertain)printf("UNCERTAIN\n");
    else printf("OK\n");
}
int main()
{
    while(~scanf("%d %d",&N,&M)){
        int i;
        init();
        sum=N;
        for(i=0;i<M;i++)
        {
            scanf("%d %c %d",&A[i],&oper[i],&B[i]);
             if(oper[i]=='='){
                if(Union(A[i],B[i]))
                    sum--;//合并两个元素了 总数减一 这个语句也就导致了第73行语句
             }

        }
        for(i=0;i<M;i++)
     {
        if(oper[i]=='=') continue;
       int     a=find_(A[i]);
       int     b=find_(B[i]);//找到顶层根节点
        if(oper[i]=='>')
        {
            next[a].push_back(b);
            pre[b]++;
        }else{
           next[b].push_back(a);
           pre[a]++;
        }

     }

     top_order();//进行拓扑排序

    }
    return 0;
}
