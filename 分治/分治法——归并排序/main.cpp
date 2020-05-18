void Merge(int r[],int r1[],int s,int m,int t)
//归并子序列
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
        m=(s+t)/2;//划分
        //1
        MergeSort(r,s,m); //求解子问题1，归并排序前半个子序列
        //2
        MergeSort(r,m+1,t);//求解子问题2，归并排序后半个子序列
        //3
        Merge(r,r1,s,m,t);//合并两个有子序列，结果存放在数组r1中
        //4
        for(int i=s;i<=t;i++)
            r[i]=r1[i];//将有序序列传回数组r中
    }
}
