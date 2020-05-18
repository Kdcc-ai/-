#include<cstdio>
#include<cstring>
#include<queue>
 //HDOJ 1728 �����Թ� (BFS ����)
//��һ��M*N���Թ��gloriaҪ��һ���ط��ߵ���һ���ط����ж��Ƿ������K��ת���ڵ���Ŀ�ĵء�
//˼·����ô������������ǹؼ�

//https://www.cnblogs.com/tonghao/p/4718298.html

//BFS��������������������һ������ô�������һ�� �����ұ�һ�� �������һ�� �����ұ�һ��
//���������ڽӵ�
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
    //���Ͽ�ʼ���� ��һ����Ϊ��ʼ��
    while(!q.empty())
    {
        now=q.front();//�õ���ʼ��
        q.pop();
        for(int i=0;i<4;i++)
        {
            tmp.x=now.x+dx[i];
            tmp.y=now.y+dy[i];
            //�Դ����� �� �� ���ѵ���ͷ
            while(tmp.x>0&&tmp.y>0&&tmp.x<=m&&tmp.y<=n&&maze[tmp.x][tmp.y]!='*')
            {   //�����ǰû�ѵ�
                if(vis[tmp.x][tmp.y]==-1)
                {
                    //�������
                    q.push(tmp);
                    //����temp��Ĺ����������now����������һ
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
            //���ȸ�ֵΪ-1��
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
