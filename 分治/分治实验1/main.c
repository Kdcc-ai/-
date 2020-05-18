#include <stdio.h>
#include <stdlib.h>
int a[200],b[200];
double FindOneMiddle(int a[],int left,int right)
//找到单数组中位数
{
    double mid;
    int n=right-left+1;
    //有n个元素
    if(n%2==0)//有偶数个元素
        mid=(a[n/2]+a[n/2-1])*1.0/2;
              //有奇数个元素
    else
        mid=a[n/2]*1.0;
    return mid;
}
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
int min(int a,int b)
{
    if(a>=b) return b;
    else return a;
}
double FindMiddle(int a[],int aleft,int aright,int b[],int bleft,int bright)
{
     double result,mida,midb;
     if(aright-aleft==0)
        return (a[aleft]+b[bleft])*1.0/2;//一个元素 直接返回
     //找到a b数组中位数
     mida=FindOneMiddle(a,aleft,aright);
     midb=FindOneMiddle(b,bleft,bright);
     //只有两个元素
     if((aright-aleft)==1&&(bright-bleft)==1)
     {
         return (max(a[aleft],b[bleft])+min(a[aright],b[bright]))*1.0/2;
     }
     if(mida==midb)
     {
         return mida*1.0;
     }// 两个数组中位数相同 那么这个中位数就是以前数组中位数
     //分析奇数 偶数都满足
     else if(mida>midb)//a左半部分  b右半部分
     {
        if((aright-aleft+1)%2==0)
        {
         result=FindMiddle(a,aleft,(aright-aleft)/2,b,(bleft+bright)/2+1,bright);
        }
        else
        {
         result=FindMiddle(a,aleft,(aright-aleft)/2-1,b,(bleft+bright)/2+1,bright);
        }
     }
     else if(mida<midb)//a右半部分 b左半部分
     {
         if((aright-aleft+1)%2==0)
         {
         result=FindMiddle(a,(aleft+aright)/2+1,aright,b,bleft,(bright-bleft)/2);
         }
         else
         {
             result=FindMiddle(a,(aleft+aright)/2+1,aright,b,bleft,(bright-bleft)/2-1);
         }
     }
     return result;
}
int main()
{
    FILE *In,*Ou;
    int n;
    if((In=fopen("D:\\input.txt","r"))!=NULL)
    {
        fscanf(In,"%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            fscanf(In,"%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            fscanf(In,"%d",&b[i]);
        }
        fclose(In);
    }
    else
        printf("输入文件打开失败！\n");
    double result=FindMiddle(a,0,n-1,b,0,n-1);
    if((Ou=fopen("D:\\output.txt","w"))!=NULL)
    {
        fprintf(Ou,"%.1lf",result);
        fclose(Ou);
    }
    else
        printf("输出文件打开失败！\n");
    return 0;
}
