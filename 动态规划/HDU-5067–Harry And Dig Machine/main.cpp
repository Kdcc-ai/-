#include <iostream>
#include<cmath>
using namespace std;
const int maxn = 11;
const int INF = 0x3f3f3f3f;
int n,m,d[maxn][maxn],dp[1<<maxn][maxn],tot;
//״̬ѹ�� ��λ�� ���������
struct Point{
     int x,y;
     Point(int a=0,int b=0)
     {
         x = a;
         y = b;
     }
}p[maxn];
int calc(int a,int b)
{
    return abs(p[a].x-p[b].x) +abs(p[a].y-p[b].y);
}
int main()
{
    int tmp;
    while(~scanf("%d%d",&n,&m))
    {
        // 1.�ܹ���0~tot-1���
        tot = 1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<m;j++){
                scanf("%d",&tmp);
                if(tmp) p[tot++] = Point(i,j);
            }
        p[0] = Point(1,1);
        //2.�����i j֮�����
        for(int i = 0;i<tot;i++)
            for(int j=i;j<tot;j++)
                 d[i][j] = d[j][i] = calc(i,j);

        memset(dp,0x3f,sizeof dp);
        //3.��ʼ��dp��1�㾭���ռ��ϻص�1����Ϊ0
        dp[1][0]=0;
        //���δ���ÿһ���Ӽ�
        int s = (1<<tot);
        for(int i=1;i<s;i++)
            for(int j=0;j<tot;j++)
            {
               if(dp[i][j]==INF) continue;
               for(int k=0;k<tot;k++)
                  if(((i>>k)&1)==0 && dp[i|(i<<k)][k]>dp[i][j]+d[j][k])
                        dp[i|(i<<k)][k] = dp[i][j]+d[j][k];
            }
        int ret = INF;
        for(int i=0;i<tot;i++)
            ret = min(dp[s-1][i]+d[i][0],ret);
        cout<<ret<<endl;
    }
    return 0;
}
