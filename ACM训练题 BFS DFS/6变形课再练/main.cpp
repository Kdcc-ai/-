#include<stdio.h>
#include<string.h>
bool ans=false;
bool visit2[1000];
char alph[1000][1000];
int i=0;
void dfs(char cl)
{     if(cl=='m')
      {
          ans=true;
      }
else{
      for(int j=0;j<i;j++)
       {
          if(visit2[j]==0&&alph[j][0]==cl)//已经访问到了再放文件就没意义了 所以要visit数组标志
          {
              visit2[j]=1;
              int t=strlen(alph[j]);
              dfs(alph[j][t-1]);//深度优先搜索
          }
       }
     }
}

int main()
{
    while(scanf("%s",alph[i++])!=EOF)//输入不为结束符那就一直输入 每组以0结束
    {   memset(visit2,0,sizeof(visit2));
        if(alph[i-1][0]=='0')
        {
            dfs('b');
            printf("%s\n",ans?"Yes.":"No.");
            ans=false;
            i=0;
        }
    }
    return 0;
}
