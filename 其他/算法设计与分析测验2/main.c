#include <stdio.h>
#include <stdlib.h>
//最接近数问题
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);//进行输入
    }
    int min;
    if(a[0]<a[1]) min=a[1]-a[0];
    else min=a[0]-a[1];
    int j=0;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
    {
        if(a[i]<a[j])
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;//交换
        }
        if(a[i]-a[j]<min) min=a[i]-a[j];
    }
    printf("%d\n",min);
    return 0;
}
