#include<cstdio>
#include<cstring>
#include<queue>
 //HDOJ 1728 逃离迷宫 (BFS 较难)
//在一个M*N的迷宫里，gloria要从一个地方走到另一个地方，判断是否可以在K次转弯内到达目的地。
//思路：怎么满足拐弯最少是关键

//https://www.cnblogs.com/tonghao/p/4718298.html

//BFS在这题根据题意比如它在一个点那么横着左边一行 横着右边一行 竖着左边一行 竖着右边一行
//看做他的邻接点
using namespace std;

struct node
{
    int x,y;
}now,tmp;

queue<struct node>q;

int m,n;
char maze[111][111];
int vis[111][111];
int k,bx,by,ex,ey;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool bfs()
{
    while(!q.empty())
        q.pop();
    now.x=bx;now.y=by;
    q.push(now);
    //马上开始搜索 第一个点为起始点
    while(!q.empty())
    {
        now=q.front();//得到起始点
        q.pop();
        for(int i=0;i<4;i++)
        {
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            //以此向左 右 上 下搜到尽头
            while(tmp.x>0&&tmp.y>0&&tmp.x<=m&&tmp.y<=n&&maze[tmp.x][tmp.y]!='*')
            {   //如果以前没搜到
                if(vis[tmp.x][tmp.y]==-1)
                {
                    //进入队列
                    q.push(tmp);
                    //现在temp点的拐弯次数就是now点拐弯次数加一
                    vis[tmp.x][tmp.y]=vis[now.x][now.y]+1;
                    if(tmp.x==ex&&tmp.y==ey)
                        return true;
                }
                tmp.x+=dx[i];tmp.y+=dy[i];
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
        {
            memset(vis,-1,sizeof(vis));
            //首先赋值为-1次
            scanf("%d %d",&m,&n);
            int i;
            for(i=1;i<=m;i++)
                scanf("%s",maze[i]+1);
            scanf("%d %d %d %d %d",&k,&by,&bx,&ey,&ex);
            if(bx==ex&&by==ey)
            {
                printf("yes\n");
                continue;
            }
            if(bfs())
            {
                if(vis[ex][ey]<=k)
                    printf("yes\n");
                else
                    printf("no\n");
            }
            else
                printf("no\n");
        }
    }
    return 0;
}
