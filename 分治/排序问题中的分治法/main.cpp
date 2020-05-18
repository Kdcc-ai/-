#include <iostream>

using namespace std;
//归并排序
//分治算法算法实现
//先划分 然后依次归并！
void Merge(int r[],int r1[],int s,int m,int t)
{
    int i=s,j=m+1;
    int k=s;
    while(i<=m&&j<=t)
    {
        if(r[i]<=r[j]) r1[k++]=r[i++];
        else r1[k++]=r[j++];
    }
    while(i<=m) r1[k++]=r[i++];
    while(j<=t) r1[k++]=r[j++];
}
void MergeSort(int r[],int s,int t)
{
    int m,r1[1000];
    if(s==t) return;//递归的边界条件 只有一个记录 已经有序
    else
    {
        m=(s+t)/2;
        MergeSort(r,s,m);
        MergeSort(r,m+1,t);
        Merge(r,r1,s,m,t);
        for(int i=s;i<=t;i++)
            r[i]=r1[i];
    }
}
int main()
{
    cout<<"请输入N"<<endl;
    int N;
    cin>>N;
    int r[N];
    for(int i=0;i<N;i++)
        cin>>r[i]>>" ";
    int s=2,t=n-1;
    MergeSort(r,s,t);
    return 0;

}
