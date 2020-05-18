#include <iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<cstring>
//Knight Movwes HDOJ
//马走日 给棋盘位置横坐标a-h纵坐标1-8 求出最小步数
//BFS发散再发散 直到找到为止
//Knight Moves  HDOJ - 1372
using namespace std;
struct position{
int x;
int y;
};
//八种情况 位移情况
position dir[8]={{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2}};
char c[6];//字符数组用于输入字符
int a[6];


queue<int> que;//宽度优先BFS就用队列
int vis[9][9];//棋盘位置
int ans;
int is_right(int a,int b)
{
    if(a>0&&a<=8&&b>0&&b<=8)
        return 1;
    return 0;
}
//BFS
//想了一会终于明白了 确实是类似广度优先搜索（层次遍历）,思想是相同的
//ans=1也就是第一步能够跳到的一批点 跟随他的步数为1
//ans=2从第一步跳到的那一批点里面按顺序寻找到第二批点 跟随他的步数为2
//直到找到为止 直接return跟随他的步数
int BFS()
{
    int col,row,i;
    ans=0;
    que.push(a[0]);
    que.push(a[1]);
    que.push(ans);
    //ans用于记录用了几步 初值为0步
    vis[a[0]][a[1]]=1;
    //首先访问这个点
    while(!que.empty())
    {
        col=que.front();que.pop();
        row=que.front();que.pop();
        ans=que.front();que.pop();
        //输出点 次数
        if(col==a[2]&&row==a[3])
            return ans;
            //直接return次数
        for(i=0;i<8;i++)
        {//可以走八步


            if(is_right(col+dir[i].x,row+dir[i].y)
               &&!vis[col+dir[i].x][row+dir[i].y])
            {
                vis[col+dir[i].x][row+dir[i].y]=1;
                que.push(col+dir[i].x);
                que.push(row+dir[i].y);
                que.push(ans+1);
            }
        }
    }
}
int main()
{
    while(gets(c))//进行输入 会输入5个字符 包括一个空格
    {
        while(!que.empty())
            que.pop();//清空队列
        memset(vis,0,sizeof(vis));
        a[0]=c[0]-'a'+1;//横纵坐标代表值相同了
        a[1]=c[1]-'0';
        a[2]=c[3]-'a'+1;
        a[3]=c[4]-'0';
        ans=BFS();

        printf("To get from %c%c to %c%c takes %d knight moves.\n",c[0],c[1],c[3],c[4],ans);
    }
    return 0;
}
