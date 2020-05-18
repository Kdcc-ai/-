#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char path[105][105];
struct node
{
    int x;
    int y;
}
now,temp;
int m,n;
int k;
int y1,x1,y2,x2;
int vis[105][105];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<struct node> q;
bool BFS()
{    while(!q.empty()) q.pop();
     now.x=x1;
     now.y=y1;
     q.push(now);

    while(!q.empty())
    {
        now=q.front();
        q.pop();
        //得到队头元素
        //队头元素四个方向进行行走
        for(int i=0;i<4;i++)
        {   temp.x= now.x+dx[i];
            temp.y= now.y+dy[i];
            //从队列头元素开始 遍历四个方向
            while(temp.x>0&&temp.x<=m&&temp.y>0&&temp.y<=n&&path[temp.x][temp.y]!='*'){
               if(vis[temp.x][temp.y]==-1)
               {
                 q.push(temp);
                 vis[temp.x][temp.y]=vis[now.x][now.y]+1;
                 if(temp.x==x2&&temp.y==y2) return true;
               }
               temp.x+=dx[i];temp.y+=dy[i];
                                                                                       }
        }
    }
    return false;
}
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {   memset(vis,-1,sizeof(vis));
            scanf("%d %d",&m,&n);
            for(int i=1;i<=m;i++)
            {
                scanf("%s",path[i]+1);

            }
            scanf("%d %d %d %d %d",&k,&y1,&x1,&y2,&x1);
            if(x1==x2&&y1==y2)
            {
                printf("yes\n");
                continue;
            }
            if(BFS())
            {
                if(vis[x2][y2]<=k) printf("yes\n");
                else printf("no\n");
            }
            else printf("no\n");
        }
    }
    return 0;
}
