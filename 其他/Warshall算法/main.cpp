#include <iostream>
#include<stdio.h>
#include<stdlib.h>
//������ϵ���� ���䴫�ݱհ�
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
    //��д��  ����num+1���ڴ浥Ԫ ��ָ��ָ���ָ��
    int * *r = (int **)malloc(sizeof(int *)*(num+1));

    //ÿ��ָ����num+1���ڴ浥Ԫ���׵�ַ
    for(int i=0;i<num+1;i++)
        r[i] = (int*)malloc(sizeof(int)*(num+1));
    for(int i=1;i<=num;i++)
        for(int j=1;j<=num;j++)
            fscanf(p,"%d",&r[i][j]);
     Warshall(num,r);
    fclose(p);
    return 0;
}
