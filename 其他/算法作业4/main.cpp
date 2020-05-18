#include <iostream>
#include <iostream>
#include<algorithm>
#include<map>
using namespace std;
int Reverse(int A[],int n)
{
    int num=0;
   // map<int,int> M;
    for(int i=0;i<n;i++)
       for(int j=i+1;j<n;j++)
       {
           if(A[i]>A[j])
               num++;
       }
       return num;
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int num=Reverse(A,n);
    cout<<num;
    return 0;
}
