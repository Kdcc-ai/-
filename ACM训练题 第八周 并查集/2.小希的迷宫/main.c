#include <stdio.h>
#include <stdlib.h>
//
int father[100010];
int vis[100010];//用于标记他是否已经统计了
int ok;
void merge(int a,int b){//合并加判断操作
  int A,B;
  A=find(a);
  B=find(b);
  if(A!=B){
    father[B]=A;
  }
  else{
    ok=0;
      }
}


int find(int a)  {
     int r=a;
     while(father[r]!=r)
        r=father[r];
     int i=a;
     int j;
     while(i!=r)
        {
        j=father[i];
        father[i]=r;
        i=j;
        }
    return r;  }

int main()
{
    int m,n,i;
    while(~scanf("%d%d",&m,&n)){
        if(m==0&&n==0)   {
            printf("Yes\n");
            continue;//本次结束 开始下一次输入
                          }

        for(i=0;i<100010;i++)
        {
            father[i]=i;
            vis[i]=0;//先进行标记,等于0证明没输入这个点,这个点连边都没有
        }

        if(m==-1&&n==-1) break;
        merge(m,n);//对第一次输入的m,n进行合并
        ok=1;
        vis[m]=1;
        vis[n]=1;//表示m与n已经访问到了
        scanf("%d %d",&m,&n);
        while(m!=0&&n!=0) {
            merge(m,n);
            vis[m]=1;
            vis[n]=1;
            scanf("%d %d",&m,&n);
                          }

        if(ok==0){
            printf("No\n");
            continue;
                 }

        else{
            int count=0;
        for(i=0;i<=100010;i++)  {
             if(vis[i]&&father[i]==i)
               count++;
                                }

             if(count==1)
               printf("Yes\n");
             else
               printf("No\n");
        }
             }
    return 0;
}
