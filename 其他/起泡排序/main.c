#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    //n个数
    int bound,exchange=n-1;
    //exchange用于判断是否进行了交换
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int bound,exchange=n-1;
    while(exchange!=0)
    {   bound=exchange;
        exchange=0;
        int j=0;
        for(j=0;j<bound;j++)
        {
            if(a[j]>a[j+1])
            {
                //交换

                exchange=j;//记录最后那次交换的位置 下次交换到这儿
            }
        }
    }//理解这种思路 就是那种 变量名传递信息。。
    return 0;
}
