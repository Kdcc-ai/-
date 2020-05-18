#include <iostream>
//Ignatius and the Princess IV
//hdu1029
//N个数（N为奇数） 找出其中某数出现次数大于（N+1）/2的
//1.直接数组排序 模拟
//2.便利方法
//不错的思路
//根本是在一个序列中如果去掉两个不同的元素
//那么原序列中的多元素，在新的序列中还是多元素
#include<stdio.h>
using namespace std;
int main()
{
    int n,tmp,ret=0;
    while(~scanf("%d",&n))
    {
        int cnt=0;
        while(n--)
        {
            scanf("%d",&tmp);
            //输入temp值
            if(cnt<=0) ret=tmp;
            //可以理解为进行了吞并
            if(tmp==ret) ++cnt;
            //次数＋1
            else --cnt;
        }
        printf("%d\n",ret);
    }
    return 0;
}
