#include <stdio.h>
#include <stdlib.h>
int n,a[101];
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right) return;
    temp=a[left];//temp�д�ľ��ǻ�׼��
    i=left;
    j=right;
    while(i!=j)
        //���ѭ������ֹ�������Ǳ�֤i==j
        //��ôi�����������ȫ��С�ڵ���a[left];
        //i�Ҳ���������ȫ������a[left]
    {
        //˳�����Ҫ,���ұ߿�ʼ��
        //Ϊʲôһ��Ҫ�ȴ��ұ������Ѱ���أ�
        //��ô�� ���˵�ȴ���߿�ʼѰ�ҵĻ�
        //��ôi��ͣ����λ��һ���Ǵ���a[left]ֵ���ݵ�λ�û�����jλ��(����5 4 3 2 1����)
        //�� ���˵�ߵ���jλ�� ��ôi==j����ѭ�� a[left]=a[i]=1 a[i]=temp=5 ��Ȼ����ȷ
        //�� ���˵ͣ����λ���Ǵ���a[left]ֵ���ݵ�λ��(����6 1 2 7 9����6 1 7 2 9)
        //�����6 1 2 7 9�Ļ�����ô֮��j��������ͣ����λ��һ��Ҳ��7λ��(����i==j����ѭ��),���ջ�����λa[left]=a[i]=7 a[i]=temp=6 ��Ȼ����ȷ
        //�����6 1 7 2 9�Ļ������Ƿ������ս������ȷ��
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        //���i==j ˵��j�������������ȫ��С�ڵ���a[left]
        //��ôi,j��ͣ��λ�þ���a[left]Ҫ�����λ��
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[i]=t;
        }
    }
    //������λ
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);//����������ߵ�
    quicksort(i+1,right);//���������ұߵ�
}
int main()
{
    int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(1,n);//���ÿ�������
    //����������
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    getchar();getchar();
    return 0;
}
