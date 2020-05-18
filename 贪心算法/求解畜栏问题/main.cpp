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
    { if(e==s.e) //����ʱ����ͬ
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
    for(int i=1;i<=N;i++) //1-N������б���
    {
        if(ans[i]==0) //��û�����Ź� �ӵ�һ����ʼ
        {  ans[i]=num; //�������ŵ����ӵı��
           int preend=Cow[i].e;//ǰһ�����ݻ�Ľ���ʵ��
           //���������ݻ�Ӽ�
           for(int j=i+1;j<=N;j++)
           { if(Cow[j].b>preend&&ans[j]==0)
              {
                 ans[j]=num;
                 preend=Cow[j].e;//����ط�Ҫ���ϸ���
              }
           }
           num++;
        }
    }
    //������num�Լ���˳�����ÿ����ŵ���
    cout<<num-1<<endl;
    for(int i=1;i<=N;i++)
        cout<<ans[i]<<endl;
    return 0;
}
