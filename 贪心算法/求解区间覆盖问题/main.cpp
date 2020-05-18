#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N,k;
    cin>>N>>k;
    int a[100];
    for(int i=0;i<N;i++)
        cin>>a[i];
    sort(a,a+N);
    int judge[100]={0};
    int cnt = 0;
    for(int i=0;i<N;i++)
        if(judge[i]==0)
        {
           cnt++;
           for(int j=i;j<N;j++){
               if(a[j]<=a[i]+k)
                   judge[j]=1;
           }
        }
    cout<<cnt<<endl;
    return 0;
}
