#include <iostream>

using namespace std;
//�鲢����
//�����㷨�㷨ʵ��
//�Ȼ��� Ȼ�����ι鲢��
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
    if(s==t) return;//�ݹ�ı߽����� ֻ��һ����¼ �Ѿ�����
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
    cout<<"������N"<<endl;
    int N;
    cin>>N;
    int r[N];
    for(int i=0;i<N;i++)
        cin>>r[i]>>" ";
    int s=2,t=n-1;
    MergeSort(r,s,t);
    return 0;

}
