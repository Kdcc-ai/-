#include <iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
//在n个元素的数组中 找到差值为k的数字对去重后的个数
using namespace std;
int Find(vector<int> &vec,int k)
{
    map<int,int> map1;
    //map映射
    sort(vec.begin(),vec.end());

    int len=vec.size();
    for(int i=0;i<len-1;i++)
        for(int j=i+1;j<len;j++)
          if(abs(k)==vec[j]-vec[i])
         {
           map1[vec[i]]=vec[j];
         }
    int count=0;
    map<int,int>::iterator it=map1.begin();
    for(;it!=map.end();it++)
        count++:
            return count;
}
int main()
{
   int n,k;
   vector<int> vec;
   cin>>n>>k;

   for(int i=0;i<n;i++)
   {
       int a;
       scanf("%d",&a);
       vec.push_back(a);
   }
    cout<<Find(vec,k)<<endl;
    return 0;
}
