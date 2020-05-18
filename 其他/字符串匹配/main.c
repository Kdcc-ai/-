#include <stdio.h>
#include <stdlib.h>
//字符串匹配BF算法
//主串n 子串m
//假设匹配成功发生在Si处
//则在i-1趟不成功的匹配共比较了(i-1)*m次
//第i次比较了m次 所以总共比较了i*m次

//平均比较次数是i从1到n-m+1：1/(n-m-1) * (i*m)==m*(n-m+2)/2
//一般情况下m<<n 最坏情况下的时间复杂度为O(n*m)
int main()
{
    char S[11]={'a','b','c','b','c','b','c','b','c','d','\0'};
    char T[4]={'b','c','b','\0'};
    int index=0;
    int i=0,j=0;
    while((S[i]!='\0')&&(T[j]!='\0'))
    {
        if(S[i++]==T[j++])
            {
                ;
            }
        else
        {
            index++;
            i=index;
            j=0;
        }
    }
   //if(T[j]=='\0')
      //  printf("%d",index+1);
    return 0;
}
