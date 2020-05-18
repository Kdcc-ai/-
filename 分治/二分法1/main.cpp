#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//斐波那契数列 结果大于8位的话就输出前四位后四位
using namespace std;
long long Fib(long long first,long long second,int n)
{
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    if(n==3) return first+second;
    else
        return Fib(second,first+second,n-1);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long long num=Fib(1,1,n);
        printf("%d\n",num);
    }
    return 0;
}
