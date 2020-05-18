#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Out[5000][5000]={0};
void Output(int n,int num)
//n是几位 num是pow(2,n)
{
    if(n==1) //num=2
    {
        Out[0][0]=0;
        Out[1][0]=1;
        return;
    }
    int i=0,j=0;
    for(i=0;i<num/2;i++)
    {
        Out[i][n-1]=0;
        Out[num-i-1][n-1]=1;
    }//根据规则 末位填0 1
    Output(n-1,num/2);
    for(i=num/2;i<num;i++)
        for(j=0;j<n-1;j++)//前一次那趟
             Out[i][j]=Out[num-i-1][j];
}
int main()
{
    FILE *In,*Ou;
    int n;
    if((In=fopen("D:\\input.txt","r"))!=NULL)
    {
        fscanf(In,"%d",&n);
        fclose(In);
        int i=1;
        Output(n,pow(2,n));//调用输出函数
    }
    else
    {
        printf("输入文件打开失败！\n");
    }
    if((Ou=fopen("D:\\output.txt","w"))!=NULL)
    {
        int i=0,j=0;
        for(i=0;i<pow(2,n);i++)
        {
            for(j=0;j<n;j++)
              fprintf(Ou,"%d",Out[i][j]);
              fprintf(Ou,"\n");
        }
        fclose(Ou);
    }
    else
    {
        printf("输出文件打开失败\n");
    }
    return 0;
}
