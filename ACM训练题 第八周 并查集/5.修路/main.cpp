#include <iostream>
//已通过
using namespace std;//标准库中内容
const int maxx=6000;
int visit[101];
class Kru{
  public:
      int bef;
      int aft;
      int data;
      int flag;
      Kru(){
           bef=-1;
           aft=-1;
           data=0;
           flag=0;
           }
};
int find_(int a){
  if(visit[a]==a)
    return a;
  else
    return visit[a]=find_(visit[a]);
}
void Union(int x,int y){
  int fx=find_(x),fy=find_(y);
   if(fx!=fy)
    {
        visit[fy]=fx;
    }
}
int main()
{
    int n;
    while(cin>>n){
        Kru kr[maxx+5];//存储边权值
        for(int i=1;i<=n;i++)
            visit[i]=i;

        int k=0;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++){
             int temp;
             cin>>temp;
             if(i<j){
                kr[k].bef=i;
                kr[k].aft=j;
                kr[k++].data=temp;
                     }
                              }//进行输入

        int h;
        cin>>h;
        int sumedge=0;
        while(h--){
            int sumedge=0;
            int a,b;
            cin>>a>>b;
            if(find_(a)!=find_(b))
            {
                Union(a,b);
                sumedge++;
            }
                  }
        Kru temp;//存储边类临时值

        for(int i=0;i<k-1;i++)
        for(int j=0;j<k-1-i;j++)
            if(kr[j].data>kr[j+1].data)
            {
                temp=kr[j];
                kr[j]=kr[j+1];
                kr[j+1]=temp;
            }//边按权值排序
        int sum=0;
       for(int i=0;i<k;i++)//k条边
         {
            int u=kr[i].bef;
            int v=kr[i].aft;
             if(find_(u)!=find_(v))
             {
                 sum+=kr[i].data;
                 sumedge++;
                 Union(u,v);
             }
             if(sumedge>=n-1)
                 break;
         }

   cout<<sum<<endl;
    }
    return 0;
}
