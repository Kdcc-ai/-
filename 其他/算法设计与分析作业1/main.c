#include <stdio.h>
#include <stdlib.h>
/**
�ҳ�δ���ֵ���С��������
ʱ���Ч
����n����
�ҳ�δ���ֵ���С�����������������
-1-2-3 123 157 357
*/
int main()
{
    int n,i=0;
    scanf("%d",&n);
    int a[n],max=0;
    for(i=0;i<n;i++)
    {
     scanf("%d",&a[i]);
     if(a[i]>max)
      max=a[i];//���Ƚ�a[n]�����ֵ�ҳ��� Ϊmax
    }
    int arr[max+1];//��ô��������±�Ϊ0->max  ��Ϊ���������ֵ��max
    for(i=0;i<max+1;i++)
    {
        arr[i]=0;
    }
    for(i=0;i<n;i++)
    {//�����������
        if(a[i]>0) arr[a[i]]++;//���˵a[i]����0 ��ôarr[i]��Ӧλ��Ԫ��ֵ+1(������ֹ�)
    }
    for(i=1;i<=max;i++)
        if(arr[i]==0)
        {
            printf("%d",i);
            return 0;
        }
   printf("%d",max+1);
   return 0;
}
