#include <stdio.h>
#include <stdlib.h>
int m[101][101];//前i个数字 分成j段
int a[101];//存放数字
int cal(int a[],int i,int j)
{
    int value=0;
    while(j>=i)
    {
        value=value*10+a[i];
        i++;
    }
    return value;
}
int main()
{
    FILE *In,*Ou;
    int n,k,i,j;
    int num;
    int max,value;
    if((In=fopen("D:\\input.txt","r"))!=NULL)
    {
        fscanf(In,"%d %d",&n,&k);
        fscanf(In,"%d",&num);
        int i=n;
        while(num)
        {
            a[i]=num%10;i--;
            num/=10;
        }
        fclose(In);
    }
    else
    {
        printf("输入文件打开失败！\n");
    }
    if(k>=n)
    {
        printf("划分位数大于等于数字位数 输入不合法\n");
        return 0;
    }
    /*
    m[i][j]表示前i个数分成j段的最大乘积
    满足最优性原理 重叠子问题
    动态规划方程
    */
    m[1][1]=a[1];
    for(i=2;i<=n;i++)
        m[i][1]=m[i-1][1]*10+a[i];
    for(i=2;i<=k;i++){//分成多少段 统计到k段即可
        max=-1;
        for(j=i;j<=n;j++){//统计前j个元素分成i段的最大乘积
            int d;
            for(d=1;d<=j-1;d++){
                value=m[d][i-1]*cal(a,d+1,j);//把前d个数分成i-1段再乘上从d+1~j
                if(value>max)
                    max=value;
            }
            m[j][i]=max;
        }
    }
    if((Ou=fopen("D:\\output.txt","w"))!=NULL)
    {
        fprintf(Ou,"%d",max);
        fclose(Ou);
    }
    else
    {
        printf("输出文件打开失败\n");
    }
    return 0;
}
