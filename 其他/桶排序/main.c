#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[11],i,j,t;
    for(i=0;i<=10;i++)
        a[i]=0;
    for(i=1;i<=5;i++)
    {
        scanf("%d",&t);
        a[t]++;
    }
    for(i=0;i<=10;i++)  //依次判断a[0]~a[10]
            for(j=1;j<=a[i];j++)  //出现了几次就打印几次
                printf("%d ",i);
                getchar();
                getchar();
//从大到小 简单改进就行

 //真正的桶排序

    return 0;
}
