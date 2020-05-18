#include <iostream>

using namespace std;
//KMP算法
//在一次过程中 已经get到了主串的部分内容(通过子串)
//利用get到的这些主串内容以及子串的某些特性(next[]数组里面存储)
//把子串多往后移几位

//用next[j]表示下一轮j定位的地方
//其实next[j]就是第j个元素前j-1个元素首尾重合的部分个数加1(这块首尾重合部分的个数应该取到最多 即next[j]应取尽量大的值)
//求解next数组
void Getnext(char ch[],int clen,int next[])
{
   next[1]=0;
   int i=1,j=0;
   while(i<=clen)
   {
       if(i<=clen)
       {
           if(j==0||ch[i]==ch[j] next[++i]=++j;
           else j=next[j];
       }
   }
}
