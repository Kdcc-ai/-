#include <stdio.h>
#include <stdlib.h>
/**
找出未出现的最小正整数。
时间高效
给出n个数
找出未出现的最小正整数共三种情况：
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
      max=a[i];//首先将a[n]的最大值找出来 为max
    }
    int arr[max+1];//那么这个数组下标为0->max  因为数组中最大值是max
    for(i=0;i<max+1;i++)
    {
        arr[i]=0;
    }
    for(i=0;i<n;i++)
    {//遍历这个数组
        if(a[i]>0) arr[a[i]]++;//如果说a[i]大于0 那么arr[i]对应位置元素值+1(代表出现过)
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
