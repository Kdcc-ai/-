void Merge(int r[],int r1[],int s,int m,int t)
//�鲢������
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
        m=(s+t)/2;//����
        //1
        MergeSort(r,s,m); //���������1���鲢����ǰ���������
        //2
        MergeSort(r,m+1,t);//���������2���鲢�������������
        //3
        Merge(r,r1,s,m,t);//�ϲ������������У�������������r1��
        //4
        for(int i=s;i<=t;i++)
            r[i]=r1[i];//���������д�������r��
    }
}
