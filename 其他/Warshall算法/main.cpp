#include <iostream>
#include<stdio.h>
#include<stdlib.h>
//给定关系矩阵 求其传递闭包
using namespace std;
void Warshall(int num,int **r)
{
    int * *temp = (int **)malloc(sizeof(int *)*(num+1));
    for(int i=0;i<num+1;i++)
       temp[i] = (int*)malloc(sizeof(int)*(num+1));
     for(int k=1;k<=num;k++)
        for(int i=1;i<=num;i++)
           for(int j=1;j<=num;j++)
               temp[i][j]=(r[i][j])||(r[i][k]&&r[k][j]);
     for(int i=1;i<=num;i++)
        for(int j=1;j<=num;j++)
        r[i][j]=temp[i][j];
}
int main()
{
    int num = 4;
    FILE *p;
    p=fopen("D:\\demo.txt","r");
    //新写法  分配num+1个内存单元 给指向指针的指针
    int * *r = (int **)malloc(sizeof(int *)*(num+1));

    //每个指针存放num+1个内存单元的首地址
    for(int i=0;i<num+1;i++)
        r[i] = (int*)malloc(sizeof(int)*(num+1));
    for(int i=1;i<=num;i++)
        for(int j=1;j<=num;j++)
            fscanf(p,"%d",&r[i][j]);
     Warshall(num,r);
    fclose(p);
    return 0;
}
