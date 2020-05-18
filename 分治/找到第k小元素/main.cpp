#include <iostream>
using namespace std;
int QuickSelect(int a[],int left,int right,int k)
{
    if(left>right)
        return -1;
    int i,j,t,temp;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
        //理解为i与j相碰时的空就是temp所在位置
    {
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;
    if(i==k-1) return a[i];
    else if(i<k-1) return QuickSelect(a,i+1,right,k);
    else return QuickSelect(a,left,i-1,k);
}
int main()
{
    int a[10]={1,3,2,5,9,7,3,6,10,8};
    int k;
    cin>>k;
    cout<<QuickSelect(a,0,9,k)<<endl;
    return 0;
}
