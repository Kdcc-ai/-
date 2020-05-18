#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/**
入度为0的点只有一个
除根以外的点入度都为1
空的图也是空树
*/
//学会调试程序
int father[10010];
int vis[10010];
int in[10010];//记录并入点的入度

int find_t(int m)  {
     int r=m;
     while(father[r]!=r)
        r=father[r];
    int i=m,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;
                }
    return r;  }

void merge(int m,int n){
  int A,B;
  A=find_t(m);
  B=find_t(n);
  if(A!=B)
    father[B]=A;
                      }


int main()
{
    int m,n,i;
    int k=1;
    while(~scanf("%d%d",&m,&n)){
        if(m==0&&n==0)   {//直接输入了空树
            printf("Case %d is a tree.\n",k);
            k++;
            continue;//进入下一次循环
                          }

        for(i=0;i<10010;i++)
        {
            father[i]=i;
            vis[i]=0;
            in[i]=0;//各数组赋初值
        }

        if(m==-1&&n==-1) break;//第一次就输入了结束标志
        in[n]++;//入度加1,指向那个点的入度加1
        merge(m,n);//进行点的合并
        vis[m]=1;
        vis[n]=1;//证明该点已进入
        scanf("%d %d",&m,&n);
        while(m!=0&&n!=0) {//继续输入
            in[n]++;
            merge(m,n);
            vis[m]=1;
            vis[n]=1;
        scanf("%d %d",&m,&n);
                                           }

        int res=0;
        int res2=0;
        for(i=1;i<10010;i++){
            if(vis[i]==1&&in[i]==0) res++;//用于判断根节点
            if(vis[i]==1&&in[i]>=2) res2++;//用于判断是否存在入度为2的点
        }
        if(res==1&&res2==0) {
                printf("Case %d is a tree.\n",k);
                k++;
                continue;
             }
        else{
              printf("Case %d is not a tree.\n",k);
              k++;
              continue;
             }
                              }
    return 0;
}
