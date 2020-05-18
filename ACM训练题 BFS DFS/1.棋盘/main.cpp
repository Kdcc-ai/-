#include <iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
#include<cstring>
//Knight Movwes HDOJ
//������ ������λ�ú�����a-h������1-8 �����С����
//BFS��ɢ�ٷ�ɢ ֱ���ҵ�Ϊֹ
//Knight Moves  HDOJ - 1372
using namespace std;
struct position{
int x;
int y;
};
//������� λ�����
position dir[8]={{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2}};
char c[6];//�ַ��������������ַ�
int a[6];


queue<int> que;//�������BFS���ö���
int vis[9][9];//����λ��
int ans;
int is_right(int a,int b)
{
    if(a>0&&a<=8&&b>0&&b<=8)
        return 1;
    return 0;
}
//BFS
//����һ������������ ȷʵ�����ƹ��������������α�����,˼������ͬ��
//ans=1Ҳ���ǵ�һ���ܹ�������һ���� �������Ĳ���Ϊ1
//ans=2�ӵ�һ����������һ�������水˳��Ѱ�ҵ��ڶ����� �������Ĳ���Ϊ2
//ֱ���ҵ�Ϊֹ ֱ��return�������Ĳ���
int BFS()
{
    int col,row,i;
    ans=0;
    que.push(a[0]);
    que.push(a[1]);
    que.push(ans);
    //ans���ڼ�¼���˼��� ��ֵΪ0��
    vis[a[0]][a[1]]=1;
    //���ȷ��������
    while(!que.empty())
    {
        col=que.front();que.pop();
        row=que.front();que.pop();
        ans=que.front();que.pop();
        //����� ����
        if(col==a[2]&&row==a[3])
            return ans;
            //ֱ��return����
        for(i=0;i<8;i++)
        {//�����߰˲�


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
    while(gets(c))//�������� ������5���ַ� ����һ���ո�
    {
        while(!que.empty())
            que.pop();//��ն���
        memset(vis,0,sizeof(vis));
        a[0]=c[0]-'a'+1;//�����������ֵ��ͬ��
        a[1]=c[1]-'0';
        a[2]=c[3]-'a'+1;
        a[3]=c[4]-'0';
        ans=BFS();

        printf("To get from %c%c to %c%c takes %d knight moves.\n",c[0],c[1],c[3],c[4],ans);
    }
    return 0;
}
