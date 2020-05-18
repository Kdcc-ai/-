#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=1e+7;
int ans[INF];
typedef struct Cow
{
    int no;
    int b;
    int e;
    bool operator<(const Cow &s) const
    { if(e==s.e) //结束时间相同
         return b<=s.b;
      else
         return e<=s.e;
    }
};
int main()
{
    int N;
    cin>>N;
    Cow Cow[1000];
    for(int i=1;i<=N;i++)
        {
            cin>>Cow[i].b>>Cow[i].e;
            Cow[i].no=i;
        }
    sort(Cow+1,Cow+N+1);
    int num=1;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=N;i++) //1-N个羊进行遍历
    {
        if(ans[i]==0) //还没被安排过 从第一个开始
        {  ans[i]=num; //给他安排的笼子的编号
           int preend=Cow[i].e;//前一个兼容活动的结束实现
           //查找最大兼容活动子集
           for(int j=i+1;j<=N;j++)
           { if(Cow[j].b>preend&&ans[j]==0)
              {
                 ans[j]=num;
                 preend=Cow[j].e;//这个地方要不断更新
              }
           }
           num++;
        }
    }
    //输出最大num以及按顺序输出每个编号的羊
    cout<<num-1<<endl;
    for(int i=1;i<=N;i++)
        cout<<ans[i]<<endl;
    return 0;
}
